# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 00:27:53 by sprodatu          #+#    #+#              #
#    Updated: 2023/12/11 22:55:54 by sprodatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Library Name
NAME = libftprintf.a

PRINTF_SRCS = ft_printf.c parse_format.c handle_char.c handle_format.c \
	is_flag.c ft_putchar.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c \
	ft_lstmap.c ft_lstclear.c ft_lstiter.c handle_str.c ft_strcpy.c handle_percent.c handle_int.c \
	calculate_padding.c print_padding.c zero_padding.c ft_putstr.c add_padding.c \
	handle_uint.c ft_utoa.c handle_hexa.c handle_pointer.c prnt_hexpad.c print_hex_prefix.c put_hexa.c \
	put_hexa.c prt_pad_n_prefix.c print_hex.c print_hex_digit.c handle_int_flags.c apply_precision.c \
	handle_i_neg_n_min.c print_int_padding.c calculate_hex_digits.c add_sign.c

OBJS = $(PRINTF_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Complete list of Rules
# Rule to make the library
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "\033[0;32mcompiled succesfully\033[0m"

bonus:$(NAME)
	@echo "\033[0;32mbonus compiled succesfully\033[0m"

clean:
	rm -f $(OBJS)

# Rule to clean everything
fclean: clean
	rm -f $(NAME)

# Rule to recompile
re: fclean all

# Phony targets
.PHONY: all clean fclean re