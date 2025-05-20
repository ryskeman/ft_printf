# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 11:56:21 by fernafer          #+#    #+#              #
#    Updated: 2025/05/20 19:38:29 by fernafer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_NAME = libft.a
LIBFT_DIR = ./libft

CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs

SRCS = ft_printf.c \
	   ft_formats_chars.c \
	   ft_formats_ints.c \
	   ft_formats_hex.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_DIR)/$(LIBFT_NAME) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(NAME) created!"

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "objects cleanded!!"

fclean:
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) $(LIBFT_NAME) and objects cleaned!!"

re: fclean all

.PHONY: all clean fclean re
