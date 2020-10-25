# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 09:54:42 by hrhirha           #+#    #+#              #
#    Updated: 2020/10/14 14:00:18 by hrhirha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
LIBFT = libft/libft.a
MAKE_LIBFT = make -C libft/ && make bonus -C libft/
CC = clang -Wall -Wextra -Werror #-g -fsanitize=address
MLX = -lmlx -framework OpenGL -framework AppKit
SRCS =	main.c \
		calc_color.c \
		implement.c \
		implement_shapes.c \
		ext_funcs.c \
		utils.c \
		keys.c \
		intersections/*.c \
		render_scenes.c \
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
	@$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(OBJS) : $(SRCS)
	@$(CC) -c $(SRCS)

clean :
	@make clean -C libft/
	@rm -rf *.o

fclean : clean
	@make fclean -C libft/
	@rm -rf $(NAME)
	@rm -rf $(LIBRT)

re : fclean $(NAME)
