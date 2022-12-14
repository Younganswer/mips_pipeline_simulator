SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= mips_pipeline_simulator

LIBS_DIR		= ./libs
RAYLIB_PATH		= raylib
INCLUDE_PATH	= -I. -I${LIBS_DIR}/${RAYLIB_PATH}/src -I${LIBS_DIR}/${RAYLIB_PATH}/src/external -I${LIBS_DIR}/${RAYLIB_PATH}/src/extras
LDLIBS_SRC		= ${LIBS_DIR}/${RAYLIB_PATH}/src/.ldlibs
LIBRAYLIB		= ${LIBS_DIR}/${RAYLIB_PATH}/src/libraylib.a
LDLIBS			=

ASSEMBLER_PATH	= assembler
SPIM			= ${LIBS_DIR}/${ASSEMBLER_PATH}/spim/spim

CC			= g++
CXXFLAGS	= -Wall -Wextra -Werror -O2 -std=c++17
LDFLAGS		= -fsanitize=address -g3 -L. -L${LIBS_DIR}/${RAYLIB_PATH}/src
RM			= rm -f

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
ASMS := ${addprefix ${LIBS_DIR}/${ASSEMBLER_PATH}/spim/, ${ASMS}}

SIZE_FACTOR	= 0
ifeq (${SIZE_FACTOR}, ${filter ${SIZE_FACTOR}, 7 8 9})
	CXXFLAGS += -DSIZE_FACTOR=${SIZE_FACTOR}
else
	CXXFLAGS += -DSIZE_FACTOR=8
endif


all: ${NAME}
	

INPUT_FILE = test.s
run: ${NAME}
	@cd ${LIBS_DIR}/${ASSEMBLER_PATH}/spim; ./spim -file ../../../${INPUT_FILE} -dump; cd ../../../;
	@echo ${ASMS}
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


${LIBRAYLIB}:
	@echo -n "Build raylib static library"
	@make -s -C ${LIBS_DIR}/${RAYLIB_PATH}/src
	@echo ": done"


${SPIM}:
	@echo -n "Build spim"
	@make -s -C ${LIBS_DIR}/${ASSEMBLER_PATH}/spim
	@echo ": done"


${NAME}: ${LIBRAYLIB} ${SPIM} ${OBJS}
	@printf "\bdone\n"
	@LDLIBS=`cat ${LDLIBS_SRC}`; ${CC} ${CXXFLAGS} ${LDFLAGS} $$LDLIBS -g -o ${NAME} ${OBJS} ${LIBRAYLIB} -I ${INCS_DIR}
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


install:
	@make -C ${LIBS_DIR}/${ASSEMBLER_PATH}/spim install


.PHONY: all clean fclean re run install


-include ${DEPS}