# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 00:27:53 by sprodatu          #+#    #+#              #
#    Updated: 2023/11/12 07:40:51 by sprodatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -I./include

# Library Name
NAME = ft_printf.a

# List of source files
LIBFT_SRCS = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_strlen.c \
	libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c \
	libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c \
	libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c \
	libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstadd_back.c libft/ft_lstlast.c libft/ft_lstdelone.c \
	libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_itoa.c \
	libft/ft_lstmap.c libft/ft_lstclear.c libft/ft_lstiter.c

PRINTF_SRCS = src/ft_printf.c src/parse_format.c \

OBJS = $(LIBFT_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Complete list of Rules
# Rule to make the library
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

# Rule to clean everything
fclean: clean
	rm -f $(NAME)

# Rule to recompile
re: fclean all

# Phony targets
.PHONY: all clean fclean re