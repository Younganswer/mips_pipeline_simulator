SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= mips_pipeline_simulator

RAYLIB_PATH		= ./raylib
INCLUDE_PATH	= -I. -I${LIBS_DIR}/${RAYLIB_PATH}/src -I${LIBS_DIR}/${RAYLIB_PATH}/src/external -I${LIBS_DIR}/${RAYLIB_PATH}/src/extras
LDLIBS			= -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo

ASSEMBLER_PATH	= ./assembler

SIZE_FACTOR = 0
ifneq (, ${filter ${SIZE_FACTOR}, 6 7 8 9 10})
	SIZE_FACTOR := 8
endif

CC			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -O2 -std=c++17 -D SIZE_FACTOR=${SIZE_FACTOR}
LDFLAGS		= -fsanitize=address -g3 -L. -L${LIBS_DIR}/${RAYLIB_PATH}/src
RM			= rm -f

LIBRAYLIB	= ./raylib/src/libraylib.a

LIBS_DIR	= ./libs
INCS_DIR	= ./incs
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs

SRCS =	main.cpp \
		button/button.cpp \
		camera/camera.cpp \
		draw/draw_contents.cpp \
		draw/draw_hazard_unit.cpp \
		draw/draw_forwarding_unit.cpp \
		draw/draw_operations.cpp \
		draw/draw_pipelines.cpp \
		forward/forward.cpp \
		hazard/hazard.cpp \
		info/info.cpp \
		instruction/instruction.cpp \
		shape/draw_arrow.cpp \
		shape/draw_dot.cpp \
		shape/draw_mux.cpp \
		shape/draw_trapezoid.cpp \
		render/draw_camera_sight.cpp \
		render/draw_window.cpp \
		render/render.cpp
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.cpp=${OBJS_DIR}/%.o}
DEPS = ${OBJS:.o=.d}


all: ${NAME}
	

INPUT_FILE = test.s
run: ${NAME}
	@${LIBS_DIR}/${ASSEMBLER_PATH}/spim/spim -file ${INPUT_FILE} -dump
	@./${NAME} text.asm data.asm


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p objs
	@mkdir -p objs/button
	@mkdir -p objs/camera
	@mkdir -p objs/draw
	@mkdir -p objs/forward
	@mkdir -p objs/hazard
	@mkdir -p objs/info
	@mkdir -p objs/instruction
	@mkdir -p objs/shape
	@mkdir -p objs/render


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@make -C ${LIBS_DIR}/${RAYLIB_PATH}/src
	@make -C ${LIBS_DIR}/${ASSEMBLER_PATH}/spim
	${CC} ${CXXFLAGS} ${LDFLAGS} ${LDLIBS} -g -o ${NAME} ${OBJS} ${LIBS_DIR}/${LIBRAYLIB} -I ${INCS_DIR}
	@echo "Build ${NAME}: done"


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.cpp | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "\b${CHR}"
	@${CC} ${CXXFLAGS} -g -c $< -o $@ -I ${INCS_DIR} -MD


clean:
	@echo "Remove dependencies in ${NAME}"
	@rm -rf ${OBJS_DIR}


fclean: clean
	@echo "Remove ${NAME}"
	@make -C ${LIBS_DIR}/${RAYLIB_PATH}/src clean
	@make -C ${LIBS_DIR}/${ASSEMBLER_PATH}/spim clean
	@${RM} ${NAME} *.asm
	

re:
	@make fclean
	@make all


.PHONY: all clean fclean re


-include ${DEPS}