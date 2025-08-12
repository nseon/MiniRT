# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nseon <nseon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:53:22 by pjarnac           #+#    #+#              #
#    Updated: 2025/06/19 10:49:04 by nseon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

# ================FILES================ #

MAKE_DIR		:=	.make/
BUILD_DIR		:=	$(MAKE_DIR)build_$(shell git branch --show-current)/
BASE_BUILD_DIR	:=	normal/

SRC_DIR			=	src/

OBJS			=	$(patsubst %.c, $(BUILD_DIR)%.o, $(SRC))

DEPS			=	$(patsubst %.c, $(BUILD_DIR)%.d, $(SRC))

# ================ROOT================= #

SRC 		=	minirt.c \

## ===============SAMPLE================ #
#
#SRC += $(addprefix $(SAMPLE_DIR), $(SAMPLE_SRC))
#
#SAMPLE_DIR =		sample/
#SAMPLE_SRC =		sample_src.c \

# ===============INPUTS================= #

SRC += $(addprefix $(INPUTS_DIR), $(INPUTS_SRC))

INPUTS_DIR	=		inputs/
INPUTS_SRC	=		camera.c \

# ===============DEBUG================= #

SRC += $(addprefix $(DEBUG_DIR), $(DEBUG_SRC))

DEBUG_DIR	=		debug/
DEBUG_SRC	=		objects.c \

# ===============OBJECTS================= #

SRC += $(addprefix $(OBJECTS_DIR), $(OBJECTS_SRC))

OBJECTS_DIR	=		objects/
OBJECTS_SRC	=		objects_creation.c \
					transform.c \
					sphere.c \

# ===============MATHS================= #

SRC += $(addprefix $(MATHS_DIR), $(MATHS_SRC))

MATHS_DIR	=		maths/
MATHS_SRC	=		float.c \
					fcolors.c \

# ===============MATHS/TUPLE================= #

SRC += $(addprefix $(TUPLE_DIR), $(TUPLE_SRC))

TUPLE_DIR	=		$(MATHS_DIR)tuple/
TUPLE_SRC	=		multiplications.c \
					operations.c \
					creation.c \

# ===============MATHS/RAY================= #

SRC += $(addprefix $(RAY_DIR), $(RAY_SRC))

RAY_DIR	=		$(MATHS_DIR)ray/
RAY_SRC	=		ray.c \
				intersections.c \

# ===============MATHS/TRANSFORMATIONS================= #

SRC += $(addprefix $(TRANSFORMATIONS_DIR), $(TRANSFORMATIONS_SRC))

TRANSFORMATIONS_DIR	=	$(MATHS_DIR)transformations/
TRANSFORMATIONS_SRC	=	translation.c \
						scaling.c \
						rotation_x.c \
						rotation_y.c \
						rotation_z.c \
						shearing.c \


# ===============MATHS/TUPLE================= #

SRC += $(addprefix $(MATRIX_DIR), $(MATRIX_SRC))

MATRIX_DIR	=		$(MATHS_DIR)matrix/
MATRIX_SRC	=		creation.c \
					operations.c \
					mutations.c \
					inversion.c \
					submatrix.c \
					equality.c \
					determinant.c \
					minor_cofactor.c \

# ===============PARSING================ #

SRC += $(addprefix $(PARSING_DIR), $(PARSING_SRC))

PARSING_DIR =		parsing/
PARSING_SRC =		parse.c \
					parse_map.c \

# ===============PARSING/OBJECTS================ #

SRC += $(addprefix $(P_OBJECTS_DIR), $(P_OBJECTS_SRC))

P_OBJECTS_DIR =		$(PARSING_DIR)objects/
P_OBJECTS_SRC =		parsing_ambi_light.c \
					parsing_camera.c \
					parse_types.c \
					parsing_light.c \
					parsing_plane.c \
					parsing_sphere.c \
					parsing_cylinder.c \

# ===============HOOKS================ #

SRC += $(addprefix $(HOOKS_DIR), $(HOOKS_SRC))

HOOKS_DIR =		hooks/
HOOKS_SRC =		loop.c \

# ===============RENDER================= #

SRC += $(addprefix $(RENDER_DIR), $(RENDER_SRC))

RENDER_DIR	=		render/
RENDER_SRC	=		test_render.c \

# ===============GUI================ #

SRC += $(addprefix $(GUI_DIR), $(GUI_SRC))

GUI_DIR =		gui/
GUI_SRC =		gui_init.c \

# ==========LIBS / INCLUDES============ #

LIBS_DIR	=	lib/
#LIBS_PATH	=	libft/libft.a
LIBS_PATH	=	neflibx/libneflibx.a minilibx/libmlx.a
LIBS_PATH	:=	$(addprefix $(LIBS_DIR), $(LIBS_PATH))
LIBS		=	$(patsubst lib%.a, %, $(notdir $(LIBS_PATH)))
#SYS_LIBS	=	readline
SYS_LIBS	=	m X11 Xext
SYS_LIBS	:=	$(addprefix -l, $(SYS_LIBS))

INCS_DIR	=	includes/
INCLUDES	=	$(INCS_DIR) \
				$(addsuffix $(INCS_DIR), $(dir $(LIBS_PATH))) \
				$(dir $(LIBS_PATH))

# ===============CONFIGS=============== #

CC			=	cc
CFLAGS		+=	-Wall -Wextra -Werror
CPPFLAGS	+=	$(addprefix -I, $(INCLUDES)) \
			-MMD -MP

LDFLAGS		+=	$(addprefix -L, $(dir $(LIBS_PATH)))
LDLIBS		+=	$(addprefix -l, $(LIBS)) $(SYS_LIBS)

AR			=	ar
ARFLAGS		=	-rcs

MAKEFLAGS	+=	--no-print-directory

# ================MODES================ #

MODES		:= debug fsanitize optimize full-optimize test bonus

MODE_TRACE	:= $(BUILD_DIR).mode_trace
LAST_MODE	:= $(shell cat $(MODE_TRACE) 2>/dev/null)

MODE ?=

ifneq ($(MODE), )
	BUILD_DIR := $(BUILD_DIR)$(MODE)/
else
	BUILD_DIR := $(BUILD_DIR)$(BASE_BUILD_DIR)
endif

ifeq ($(MODE), debug)
	CFLAGS = -g3 -DDEBUG=1
else ifeq ($(MODE), fsanitize)
	CFLAGS = -g -fsanitize=address -fno-omit-frame-pointer -O1
    LDFLAGS += -fsanitize=address -fno-omit-frame-pointer
    CPPFLAGS += -DDEBUG=1
else ifeq ($(MODE), optimize)
	CFLAGS += -O3
else ifeq ($(MODE), full-optimize)
	CFLAGS += -Ofast
else ifeq ($(MODE), bonus)
	CFLAGS += -Ofast
	CPPFLAGS += -DBONUS
else ifeq ($(MODE), test)
	CFLAGS = -g3 -D UNITY_OUTPUT_COLOR -D UNITY_INCLUDE_DOUBLE -D UNITY_INCLUDE_EXEC_TIME
	SRC := $(filter-out $(NAME).c, $(SRC))
	SRC += $(NAME)_test.c tests/ray_tests.c
	TEST = ~/unity/unity.c
else ifneq ($(MODE),)
	ERROR = MODE
endif

ifneq ($(LAST_MODE), $(MODE))
$(NAME): force
endif

# ================TARGETS============== #

.PHONY: all
all: $(NAME)

$(NAME): $(LIBS_PATH) $(OBJS)
	@echo $(MODE) > $(MODE_TRACE)
	$(CC) $(CFLAGS) $(OBJS) $(TEST) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBS_PATH): force
	@$(MAKE) -C $(@D)

.PHONY: $(MODES)
$(MODES):
	@$(MAKE) MODE=$@

.PHONY: clean
clean:
	-for lib in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	-for lib in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR) $(NAME)

.PHONY: re
re: fclean
	@$(MAKE)

# ================MISC================= #

.PHONY: print-%
print-%:
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

.PHONY: force
force:

.PHONY: norminette
norminette:
	@norminette $(addprefix $(SRC_DIR), $(SRC)) $(INCS_DIR)

.PHONY: valgrind
valgrind: debug
	@valgrind  --leak-check=full --track-fds=yes ./minirt

-include $(DEPS)

.DEFAULT_GOAL := all
