# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:53:22 by pjarnac           #+#    #+#              #
#    Updated: 2024/12/20 20:08:38 by pjarnac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libneflibx.a

# ================FILES================ #

MAKE_DIR		:=	.make/
BUILD_DIR		:=	$(MAKE_DIR)build_$(shell git branch --show-current)/
BASE_BUILD_DIR	:=	normal/

SRC_DIR			=	src/

OBJS			=	$(patsubst %.c, $(BUILD_DIR)%.o, $(SRC))

DEPS			=	$(patsubst %.c, $(BUILD_DIR)%.d, $(SRC))

# ================ROOT================= #

SRC 		=	window.c \
				image.c

# ================DRAW================= #

SRC += $(addprefix $(DRAW_DIR), $(DRAW_SRC))

DRAW_DIR =		draw/
DRAW_SRC =		line.c \
				points.c \
				pixels.c \
				rectangle.c

# =================GUI================= #

SRC += $(addprefix $(GUI_DIR), $(GUI_SRC))

GUI_DIR =		gui/
GUI_SRC =		gui.c \
				gui_render.c \
				gui_events.c \
				gui_events2.c \
				gui_get.c \
				gui_utils.c \
				gui_flex.c \

# =================MLX================= #

SRC += $(addprefix $(MLX_DIR), $(MLX_SRC))

MLX_DIR =		mlx/
MLX_SRC =		loops.c \

# =================EVENTS================= #

SRC += $(addprefix $(EVENTS_DIR), $(EVENTS_SRC))

EVENTS_DIR =		events/
EVENTS_SRC =		keys.c \
					buttons.c \
					events.c \
					pointer.c \
					destroy.c \
					loop.c \

# =================GUI/ELEMS================= #

SRC += $(addprefix $(GUI/ELEMS_DIR), $(GUI/ELEMS_SRC))

GUI/ELEMS_DIR =		$(GUI_DIR)elems/
GUI/ELEMS_SRC =		button.c \
					button_events.c \
					txt_input.c \
					txt_input_events.c \
					text_box.c \
					container.c \
					container_events.c \
					slide.c \
					slide_events.c \
					check_box.c \
					check_box_events.c \

# =================GUI/DRAW================= #

SRC += $(addprefix $(GUI/DRAW_DIR), $(GUI/DRAW_SRC))

GUI/DRAW_DIR =		$(GUI_DIR)draw/
GUI/DRAW_SRC =		draw_elements.c \

# ===============GUI/STRINGS================= #

SRC += $(addprefix $(GUI/STRINGS_DIR), $(GUI/STRINGS_SRC))

GUI/STRINGS_DIR =		$(GUI_DIR)strings/
GUI/STRINGS_SRC =		draw_string.c \
						string_helper.c \

# ==============STRINGS/LETTERS============== #

SRC += $(addprefix $(STRINGS/LETTERS_DIR), $(STRINGS/LETTERS_SRC))

STRINGS/LETTERS_DIR =		$(GUI/STRINGS_DIR)letters/
STRINGS/LETTERS_SRC =		a_y.c \
							z_X.c \
							Y_9.c \
							special.c \
							special2.c \
							utils.c \

# ===============MATHS================= #

SRC += $(addprefix $(MATHS_DIR), $(MATHS_SRC))

MATHS_DIR =		maths/
MATHS_SRC =		math_utils.c \

# ================UTILS================ #

SRC += $(addprefix $(UTILS_DIR), $(UTILS_SRC))

UTILS_DIR =		utils/
UTILS_SRC =		colors.c

# ==========LIBS / INCLUDES============ #

LIBS_DIR	=	lib/
LIBS_PATH	=	minilibx/libmlx.a libft/libft.a
LIBS_PATH	:=	$(addprefix $(LIBS_DIR), $(LIBS_PATH))
LIBS		=	$(patsubst lib%.a, %, $(notdir $(LIBS_PATH)))
SYS_LIBS	=	Xext X11
SYS_LIBS	:=	$(addprefix -l, $(SYS_LIBS))

INCS_DIR	=	includes/
INCLUDES	=	$(INCS_DIR) \
				$(addprefix $(dir $(LIBS_PATH)), $(INCS_DIR)) \
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

MODES		:= debug fsanitize optimize full-optimize

MODE_TRACE	:= $(BUILD_DIR).mode_trace
LAST_MODE	:= $(shell cat $(MODE_TRACE) 2>/dev/null)

MODE ?=

ifneq ($(MODE), )
	BUILD_DIR := $(BUILD_DIR)$(MODE)/
else
	BUILD_DIR := $(BUILD_DIR)$(BASE_BUILD_DIR)
endif

ifeq ($(MODE), debug)
	CFLAGS = -g
	CPPFLAGS += -DDEBUG=1
else ifeq ($(MODE), fsanitize)
	CFLAGS = -g -fsanitize=address -fno-omit-frame-pointer -fsanitize-blacklist=sanitize_ignores.txt -O1
	LDFLAGS += -fsanitize=address -fno-omit-frame-pointer
	CPPFLAGS += -DDEBUG=1
else ifeq ($(MODE), optimize)
	CFLAGS += -O2
else ifeq ($(MODE), full-optimize)
	CFLAGS += -O3
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
	gcc -r -o libnew.o -Wl,--whole-archive $(LIBS_PATH)
	$(AR) $(ARFLAGS) $(NAME) $(LIBS_PATH) $(OBJS) libnew.o
	rm libnew.o

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

-include $(DEPS)

.DEFAULT_GOAL := all
