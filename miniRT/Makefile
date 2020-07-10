# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 09:54:42 by hrhirha           #+#    #+#              #
#    Updated: 2020/04/25 20:40:07 by hrhirha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
LIBFT = libft/libft.a
MAKE_LIBFT = make -C libft/ && make bonus -C libft/
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
	@$(MAKE_LIBFT)
	@$(CC) $(OBJS) $(LIBFT) -lm $(MLX) -o $(NAME)

$(OBJS) : $(SRCS)
	@$(CC) -c $(SRCS)

clean :
	@make clean -C libft/
	@rm -rf *.o

fclean : clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re : fclean $(NAME)
