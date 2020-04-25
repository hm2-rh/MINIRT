# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 09:54:42 by hrhirha           #+#    #+#              #
#    Updated: 2020/04/23 15:49:41 by hrhirha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
LIBFT = libft/libft.a
CC = clang -Wall -Wextra -Werror -g -fsanitize=address
MLX = -lmlx -lX11 -lXext
SRCS =	main.c \
		calc_color.c \
		implement.c \
		implement_shapes.c \
		ext_funcs.c \
		utils.c \
		intersections/*.c \
		ray_trace.c \
		read_fd.c \
		vector_math.c \
		vector_math2.c \
		errors.c \
		gnl/get_next_line.c \
		bmp.c
		
OBJS = *.o

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft/
	@$(CC) $(OBJS) $(LIBFT) -lm $(MLX) -o $(NAME)

$(OBJS) : $(SRCS)
	@$(CC) -c $(SRCS)

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean $(NAME)
