# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 11:36:45 by hrhirha           #+#    #+#              #
#    Updated: 2019/11/04 16:35:30 by hrhirha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c 	\
	ft_bzero.c 		\
	ft_calloc.c 	\
	ft_isalnum.c 	\
	ft_isalpha.c 	\
	ft_isascii.c 	\
	ft_isdigit.c 	\
	ft_isprint.c 	\
	ft_itoa.c 		\
	ft_atolf.c 		\
	ft_memccpy.c 	\
	ft_memchr.c 	\
	ft_memcmp.c 	\
	ft_memcpy.c 	\
	ft_memmove.c 	\
	ft_memset.c 	\
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c 	\
	ft_putstr_fd.c 	\
	ft_split.c 		\
	ft_strchr.c 	\
	ft_strdup.c 	\
	ft_strjoin.c	\
	ft_strlcat.c 	\
	ft_strlcpy.c 	\
	ft_strlen.c 	\
	ft_strmapi.c 	\
	ft_strncmp.c 	\
	ft_strnstr.c 	\
	ft_strrchr.c 	\
	ft_strtrim.c 	\
	ft_substr.c 	\
	ft_tolower.c 	\
	ft_toupper.c
OBJ = $(SRC:.c=*.o)
B_SRC = ft_lstadd_back_bonus.c 	\
		ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c 		\
		ft_lstnew_bonus.c 		\
		ft_lstsize_bonus.c
B_OBJ = $(B_SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : clean
	@$(CC) $(FLAGS) -c $(B_SRC)
	@ar rc $(NAME) $(B_OBJ)
	@ranlib $(NAME)


$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ) : $(SRC)
	@$(CC) $(FLAGS) -c $(SRC)

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean $(NAME)
