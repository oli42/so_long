SRC =	main.c parsing.c \
		get_next_line.c get_next_line_utils.c \
		checking.c \
		window.c \
		hook.c \
		motion.c \
		utils.c \
		drawing.c \
		ft_strchr.c ft_putstr_fd.c ft_strcmp.c ft_strrchr.c ft_putnbr_fd.c ft_putchar_fd.c\

SRC_BONUS =	main_bonus.c parsing_bonus.c \
			get_next_line_bonus.c get_next_line_utils_bonus.c \
			checking_bonus.c \
			window_bonus.c \
			hook_bonus.c \
			motion_bonus.c \
			utils_bonus.c \
			drawing_bonus.c \
			a_bonus.c b_bonus.c \
			ft_strchr_bonus.c ft_putstr_fd_bonus.c ft_strcmp_bonus.c \
			ft_strrchr_bonus.c ft_putnbr_fd_bonus.c ft_putchar_fd_bonus.c ft_atoi_bonus.c\

NAME = so_long
NAME_BONUS = so_long_bonus
MLX_DIR = minilibx-linux
MLX = libmlx.a 
CC = gcc
cyan = /bin/echo -e "\x1b[33m\#\# $1\x1b[0m"
CFLAGS = -Wall -Wextra -Werror -g 
OBJ_DIR = obj
OBJ_DIR_BONUS = obj_bonus
SRC_DIR = src
SRC_DIR_BONUS = src_bonus
INC_DIR = inc
INC_DIR_BONUS = inc_bonus
TEXT = "A toi de jouer!\n"
TEXT2 = " created!\n"
TEXT3 = " deleted!\n"
TEXT4 = "Obj"
TEXT5 = "Obj_bonus"

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(SRC_BONUS:.c=.o))

all:
	@$(MAKE) -j $(NAME)
	@printf "\033[33m"$(TEXT)

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
$(NAME): $(OBJ)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
		@printf "\033[0m"$(NAME)$(TEXT2)
endif
ifeq ($(UNAME), Darwin)
$(NAME): $(OBJ)
		@${CC} $(CFLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit
		@printf "\n"
		@printf "\033[0m"$(NAME)$(TEXT2)
endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@printf "Please wait... $@\r"
		@${CC} $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@


clean:
	@rm -rf $(OBJ_DIR)
	@printf "\033[0;31m"$(TEXT4)$(TEXT3)


clean_bonus:
	@rm -rf $(OBJ_DIR_BONUS)
	@printf "\033[0;31m"$(TEXT5)$(TEXT3)


fclean:	clean
	@rm -rf $(NAME)
	@$(printf "\033[0;31m"$(NAME)$(TEXT3)


fclean_bonus: clean_bonus
	@rm -rf $(NAME_BONUS)
	@printf "\033[0m"$(NAME_BONUS)$(TEXT3)


bonus:
	@$(MAKE) -j $(NAME_BONUS)

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
$(NAME_BONUS): $(OBJ_BONUS)
	@${CC} $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
	@$(call cyan,"$(NAME_BONUS) Created!")
	@echo "#####    if you want you can choose your difficulty level - 1, 2, or 3   =>    ./so_long_bonus map.ber 1   #####"
endif

ifeq ($(UNAME), Darwin)
$(NAME_BONUS): $(OBJ_BONUS)
		@${CC} $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit
		@printf "\n"
		@printf "\033[33m"$(NAME_BONUS)$(TEXT2)
		@echo "#####    if you want you can choose your difficulty level - 1, 2, or 3  => ./so_long_bonus map.ber 1  #####"
endif

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
		@mkdir -p $(OBJ_DIR_BONUS)
		@printf "Working on... $@\r"
		@${CC} $(CFLAGS) -I $(INC_DIR_BONUS) -I $(MLX_DIR) -c $< -o $@


re: fclean all

re_bonus: fclean_bonus bonus	

.PHONY: all, clean, fclean, re, bonus
