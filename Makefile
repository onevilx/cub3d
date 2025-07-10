# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 22:14:24 by adechaji          #+#    #+#              #
#    Updated: 2025/07/10 15:35:13 by adechaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D
NAME_BONUS		= cub3D_bonus

CC				= cc
RM				= rm -f
AR				= ar rcs

CFLAGS			= -Wall -Wextra -Werror -Iincludes -IMLX42/include -I/mnt/homes/$(USER)/brew/include -g -fsanitize=address
LDFLAGS			= -LMLX42/build -L/mnt/homes/$(USER)/homebrew/lib -lmlx42 -ldl -lglfw -lm -pthread

# ================= MANDATORY ================= #

MAND_DIR		= mandatory

SRC_MAND		= $(MAND_DIR)/main.c \
				  $(MAND_DIR)/parsing/parsing.c $(MAND_DIR)/parsing/r_paths.c \
				  $(MAND_DIR)/parsing/r_map.c $(MAND_DIR)/parsing/cleanup.c \
				  $(MAND_DIR)/parsing/helper_1.c $(MAND_DIR)/parsing/helper_2.c \
				  $(MAND_DIR)/parsing/r_map_pars.c $(MAND_DIR)/parsing/surr_walls.c \
				  $(MAND_DIR)/padding/texture_rend.c \
				  $(MAND_DIR)/raycasting/raycasting.c $(MAND_DIR)/raycasting/init_things1.c \
				  $(MAND_DIR)/raycasting/init_things2.c $(MAND_DIR)/raycasting/init_things3.c \
				  $(MAND_DIR)/raycasting/init_player.c $(MAND_DIR)/raycasting/hot_keys.c \
				  $(MAND_DIR)/raycasting/ft_helpers1.c \
				  $(MAND_DIR)/helpers/ft_strncmp.c $(MAND_DIR)/helpers/ft_strrchr.c \
				  $(MAND_DIR)/helpers/ft_strrchr_custom.c $(MAND_DIR)/helpers/ft_putstr_fd.c \
				  $(MAND_DIR)/helpers/ft_atoi.c $(MAND_DIR)/helpers/free_splited_args.c \
				  $(MAND_DIR)/helpers/ft_old_split.c $(MAND_DIR)/helpers/ft_memcpy.c \
				  $(MAND_DIR)/helpers/ft_strcmp.c $(MAND_DIR)/helpers/ft_strtrim.c \
				  $(MAND_DIR)/helpers/ft_bzero.c $(MAND_DIR)/helpers/ft_calloc.c \
				  $(MAND_DIR)/helpers/ft_strlen.c $(MAND_DIR)/helpers/ft_strdup.c \
				  $(MAND_DIR)/helpers/ft_isdigit.c \
				  $(MAND_DIR)/helpers/Get_Next_Line/get_next_line.c \
				  $(MAND_DIR)/helpers/Get_Next_Line/get_next_line_utils.c

OBJS_MAND		= $(SRC_MAND:.c=.o)

# ================= BONUS ================= #

BONUS_DIR		= bonus

SRC_BONUS		= $(BONUS_DIR)/main.c \
				  $(BONUS_DIR)/parsing_bonus/parsing.c $(BONUS_DIR)/parsing_bonus/r_paths.c \
				  $(BONUS_DIR)/parsing_bonus/r_map.c $(BONUS_DIR)/parsing_bonus/cleanup.c \
				  $(BONUS_DIR)/parsing_bonus/helper_1.c $(BONUS_DIR)/parsing_bonus/helper_2.c \
				  $(BONUS_DIR)/parsing_bonus/r_map_pars.c $(BONUS_DIR)/parsing_bonus/surr_walls.c \
				  $(BONUS_DIR)/padding_bonus/texture_rend.c \
				  $(BONUS_DIR)/raycasting_bonus/raycasting.c $(BONUS_DIR)/raycasting_bonus/init_things1.c \
				  $(BONUS_DIR)/raycasting_bonus/init_things2.c $(BONUS_DIR)/raycasting_bonus/init_things3.c \
				  $(BONUS_DIR)/raycasting_bonus/init_player.c $(BONUS_DIR)/raycasting_bonus/hot_keys.c \
				  $(BONUS_DIR)/raycasting_bonus/ft_helpers1.c \
				  $(BONUS_DIR)/helpers_bonus/ft_strncmp.c $(BONUS_DIR)/helpers_bonus/ft_strrchr.c \
				  $(BONUS_DIR)/helpers_bonus/ft_strrchr_custom.c $(BONUS_DIR)/helpers_bonus/ft_putstr_fd.c \
				  $(BONUS_DIR)/helpers_bonus/ft_atoi.c $(BONUS_DIR)/helpers_bonus/free_splited_args.c \
				  $(BONUS_DIR)/helpers_bonus/ft_old_split.c $(BONUS_DIR)/helpers_bonus/ft_memcpy.c \
				  $(BONUS_DIR)/helpers_bonus/ft_strcmp.c $(BONUS_DIR)/helpers_bonus/ft_strtrim.c \
				  $(BONUS_DIR)/helpers_bonus/ft_bzero.c $(BONUS_DIR)/helpers_bonus/ft_calloc.c \
				  $(BONUS_DIR)/helpers_bonus/ft_strlen.c $(BONUS_DIR)/helpers_bonus/ft_strdup.c \
				  $(BONUS_DIR)/helpers_bonus/ft_isdigit.c \
				  $(BONUS_DIR)/helpers_bonus/Get_Next_Line/get_next_line.c \
				  $(BONUS_DIR)/helpers_bonus/Get_Next_Line/get_next_line_utils.c

OBJS_BONUS		= $(SRC_BONUS:.c=.o)

# ================= RULES ================= #

all: $(NAME)

$(NAME): $(OBJS_MAND)
	$(CC) $(CFLAGS) $(OBJS_MAND) -o $(NAME) $(LDFLAGS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(LDFLAGS)

$(MAND_DIR)/%.o: $(MAND_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_MAND) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
