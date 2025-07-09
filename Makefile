# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 22:14:24 by adechaji          #+#    #+#              #
#    Updated: 2025/07/09 12:05:06 by adechaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -Iincludes -IMLX42/include -I/mnt/homes/$(USER)/brew/include -g #-fsanitize=address

LDFLAGS		= -LMLX42/build -L/mnt/homes/$(USER)/homebrew/lib -lmlx42 -ldl -lglfw -lm -pthread

SRC			= mandatory/main.c

SRC_PARS	= mandatory/parsing/parsing.c mandatory/parsing/r_paths.c \
            	mandatory/parsing/r_map.c mandatory/parsing/cleanup.c \
            	mandatory/parsing/helper_1.c mandatory/parsing/helper_2.c \
            	mandatory/parsing/r_map_pars.c mandatory/parsing/surr_walls.c \
            	mandatory/padding/texture_rend.c

SRC_EXEC	= mandatory/raycasting/raycasting.c mandatory/raycasting/init_things1.c \
            	mandatory/raycasting/ft_helpers1.c mandatory/raycasting/hot_keys.c \
            	mandatory/raycasting/init_things2.c mandatory/raycasting/init_player.c \
				mandatory/raycasting/init_things3.c

SRC_HLP		= mandatory/helpers/ft_strncmp.c mandatory/helpers/ft_strrchr.c \
            	mandatory/helpers/ft_strrchr_custom.c mandatory/helpers/Get_Next_Line/get_next_line.c \
            	mandatory/helpers/Get_Next_Line/get_next_line_utils.c \
            	mandatory/helpers/ft_putstr_fd.c mandatory/helpers/ft_atoi.c \
            	mandatory/helpers/free_splited_args.c mandatory/helpers/ft_old_split.c \
            	mandatory/helpers/ft_memcpy.c mandatory/helpers/ft_strcmp.c \
            	mandatory/helpers/ft_strtrim.c mandatory/helpers/ft_bzero.c \
            	mandatory/helpers/ft_calloc.c mandatory/helpers/ft_strlen.c \
            	mandatory/helpers/ft_strdup.c mandatory/helpers/ft_isdigit.c

ALL_SRC		= $(SRC) $(SRC_PARS) $(SRC_EXEC) $(SRC_HLP)

OBJ			= $(ALL_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c mandatory/includes/cub3d.h mandatory/includes/parsing.h mandatory/includes/raycasting.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
