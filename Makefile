# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 00:27:53 by sprodatu          #+#    #+#              #
#    Updated: 2024/05/03 22:08:26 by sprodatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Library Name
NAME = libftprintf.a

LIBFT = libft

PRINTF_SRCS = apply_precision.c ft_printf.c ft_putstr.c handle_char.c handle_i_neg_n_min.c \
		handle_percent.c handle_uint.c parse_format.c print_hex_prefix.c prnt_hexpad.c \
		zero_padding.c add_padding.c calculate_hex_digits.c \
		handle_format.c handle_int.c handle_pointer.c is_flag.c print_hex.c print_int_padding.c \
		prt_pad_n_prefix.c add_sign.c calculate_padding.c ft_putchar.c ft_utoa.c handle_hexa.c \
		handle_int_flags.c handle_str.c print_hex_digit.c print_padding.c put_hexa.c

OBJS = $(PRINTF_SRCS:.c=.o)

# Complete list of Rules
# Rule to make the library 
all: $(NAME) $(LIBFT)
	
# Rule to compile the library
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "\033[0;32mcompiled succesfully\033[0m"

bonus:$(NAME)
	@echo "\033[0;32mbonus compiled succesfully\033[0m"

clean:
	@make -C $(LIBFT) clean
	rm -f $(OBJS)

# Rule to clean everything
fclean: clean
	@make -C $(LIBFT) fclean
	rm -f $(NAME)

# Rule to recompile
re: fclean all

# Phony targets
.PHONY: all clean fclean re
