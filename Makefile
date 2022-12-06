SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= mips_pipeline_simulator

RAYLIB_PATH		= ./raylib
INCLUDE_PATH	= -I. -I${LIBS_DIR}/${RAYLIB_PATH}/src -I${LIBS_DIR}/${RAYLIB_PATH}/src/external -I${LIBS_DIR}/${RAYLIB_PATH}/src/extras
#LDLIBS			= -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo
LDLIBS 	= -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

ASSEMBLER_PATH	= ./assembler

SIZE_FACTOR		= 0

CC			= g++
CXXFLAGS	= -Wall -Wextra -Werror -O2 -std=c++17
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
		forward/forward.cpp \
		hazard/hazard.cpp \
		info/info.cpp \
		instruction/instruction.cpp \
		render/render.cpp \
		render/render_camera_sight.cpp \
		render/render_data.cpp \
		render/render_contents.cpp \
		render/render_units.cpp \
		render/render_stages.cpp \
		render/render_pipelines.cpp \
		pipelines/pipelines.cpp \
		shape/draw_arrow.cpp \
		shape/draw_circle_lines_ex.cpp \
		shape/draw_circle_sector_lines_ex.cpp \
		shape/draw_dot.cpp \
		shape/draw_mux.cpp \
		shape/draw_trapezoid.cpp \
		stages/fetch.cpp \
		stages/decode.cpp \
		stages/execute.cpp \
		stages/memory.cpp \
		stages/writeback.cpp \
		update/update.cpp

		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.cpp=${OBJS_DIR}/%.o}
DEPS = ${OBJS:.o=.d}

ASMS = text.asm data.asm


ifeq (${SIZE_FACTOR}, ${filter ${SIZE_FACTOR}, 7 8 9})
	CXXFLAGS += -DSIZE_FACTOR=${SIZE_FACTOR}
else
	CXXFLAGS += -DSIZE_FACTOR=8
endif


all: ${NAME}
	

INPUT_FILE = test.s
run: ${NAME}
	@${LIBS_DIR}/${ASSEMBLER_PATH}/spim/spim -file ${INPUT_FILE} -dump
	@./${NAME} ${ASMS}


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p objs
	@mkdir -p objs/button
	@mkdir -p objs/camera
	@mkdir -p objs/forward
	@mkdir -p objs/hazard
	@mkdir -p objs/info
	@mkdir -p objs/instruction
	@mkdir -p objs/pipelines
	@mkdir -p objs/render
	@mkdir -p objs/shape
	@mkdir -p objs/stages
	@mkdir -p objs/update


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@make -s -C ${LIBS_DIR}/${RAYLIB_PATH}/src
	@make -s -C ${LIBS_DIR}/${ASSEMBLER_PATH}/spim
	@${CC} ${CXXFLAGS} ${LDFLAGS} ${LDLIBS} -g -o ${NAME} ${OBJS} ${LIBS_DIR}/${LIBRAYLIB} -I ${INCS_DIR}
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
	@rm -rf ${OBJS_DIR} ${ASMS}


fclean: clean
	@echo "Remove ${NAME}"
	@make -C ${LIBS_DIR}/${RAYLIB_PATH}/src clean
	@make -C ${LIBS_DIR}/${ASSEMBLER_PATH}/spim clean
	@${RM} ${NAME}
	

re:
	@make clean
	@make all


.PHONY: all clean fclean re


-include ${DEPS}