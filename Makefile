# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 20:08:43 by snuts             #+#    #+#              #
#    Updated: 2021/12/05 20:51:35 by snuts            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NAME_B = fdf_bonus

SRCS	=	./mandatory/main.c ./mandatory/ft_strchr.c ./mandatory/ft_atoi.c ./mandatory/ft_strlen.c ./mandatory/ft_split.c ./mandatory/ft_memmove.c ./GNL-main/get_next_line_utils.c ./GNL-main/get_next_line.c ./GNL-main/get_next_line.h#./mandatory/ft_check.c	./mandatory/ft_hook.c	./mandatory/ft_move.c\
			./mandatory/main.c	./mandatory/massiv.c	./mandatory/render.c\
			./mandatory/split.c	./mandatory/steps.c \


#SRCS_B	=	./bonus/ft_check_bonus.c	./bonus/ft_hook_bonus.c	./bonus/ft_move_bonus.c\
			./bonus/main_bonus.c	./bonus/massiv_bonus.c	./bonus/render_bonus.c\
			./bonus/split_bonus.c	./bonus/steps_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

LINKS = -L./mandatory/lft.a -lft#-lmlx -framework OpenGL -framework AppKit

HEADER	=	mandatory/fdf.h 

#HEADER_B	=	bonus/solong.h

CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror
MLXFLAGS	=	-L./mandatory/ -lft#-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(SRCS) $(MLXFLAGS) $(CFLAGS) $(HEADER) -o $(NAME)

$(NAME_B):	$(OBJS_B)
			$(CC) $(SRCS_B) $(MLXFLAGS) $(CFLAGS) -o $(NAME_B)

%o:			%.c
			$(CC) $(CFLAGS) -L./mandatory/ -lft -c $< -o $@#-Imlx -c $< -o $@

bonus:		$(NAME_B)

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean re