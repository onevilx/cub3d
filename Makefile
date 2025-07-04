# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 22:14:24 by adechaji          #+#    #+#              #
#    Updated: 2025/07/04 06:48:32 by adechaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -Iincludes -IMLX42/include -g -fsanitize=address

LDFLAGS		= -ldl -lm -pthread

SRC			= main.c

SRC_PARS	= parsing/parsing.c parsing/r_paths.c parsing/r_map.c parsing/cleanup.c parsing/helper_1.c parsing/r_map_pars.c \
				parsing/surr_walls.c

SRC_EXEC	=

SRC_HLP		= helpers/ft_strncmp.c helpers/ft_strrchr.c helpers/ft_strrchr_custom.c helpers/Get_Next_Line/get_next_line.c \
				helpers/Get_Next_Line/get_next_line_utils.c helpers/ft_putstr_fd.c helpers/ft_atoi.c helpers/free_splited_args.c \
				helpers/ft_old_split.c helpers/ft_memcpy.c helpers/ft_strcmp.c helpers/ft_strtrim.c helpers/ft_bzero.c \
				helpers/ft_calloc.c helpers/ft_strlen.c helpers/ft_strdup.c

ALL_SRC		= $(SRC) $(SRC_PARS) $(SRC_EXEC) $(SRC_HLP)

OBJ			= $(ALL_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c includes/cub3d.h includes/parsing.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
