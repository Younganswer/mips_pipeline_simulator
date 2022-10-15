SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= mips_pipeline_simulator

RAYLIB_PATH		= ./raylib
INCLUDE_PATH	= -I. -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external -I$(RAYLIB_PATH)/src/extras
LDLIBS			= -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo

CC			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -O2 -std=c++17
LDFLAGS		= -fsanitize=address -g3 -L. -L$(RAYLIB_PATH)/src
RM			= rm -f

LIBRAYLIB	= ./raylib/src/libraylib.a


INCS_DIR	= ./incs
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs

SRCS =	main.cpp \
		button/button.cpp \
		camera/camera.cpp \
		info/info.cpp \
		shape/draw_arrow.cpp \
		shape/draw_dot.cpp \
		shape/draw_mux.cpp \
		shape/draw_trapezoid.cpp \
		window/draw_camera_sight.cpp \
		window/draw_content.cpp \
		window/draw_edge.cpp \
		window/draw_guide.cpp \
		window/draw_window.cpp
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.cpp=${OBJS_DIR}/%.o}
DEPS = ${OBJS:.o=.d}


all: ${NAME}


INPUT_FILE = test.txt
run: ${NAME}
	./${NAME} < ${INPUT_FILE}


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p objs
	@mkdir -p objs/button
	@mkdir -p objs/camera
	@mkdir -p objs/info
	@mkdir -p objs/shape
	@mkdir -p objs/window


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@make -C ${RAYLIB_PATH}/src
	@${CC} ${CXXFLAGS} ${LDFLAGS} ${LDLIBS} -g -o ${NAME} ${OBJS} ${LIBRAYLIB} -I ${INCS_DIR}
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
	@make -C ${RAYLIB_PATH}/src clean


fclean: clean
	@echo "Remove ${NAME}"
	@${RM} ${NAME}
	

re:
	@make fclean
	@make all


.PHONY: all clean fclean re


-include ${DEPS}