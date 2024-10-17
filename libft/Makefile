# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 13:03:02 by tkaragoz          #+#    #+#              #
#    Updated: 2024/10/07 18:07:00 by tkaragoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c \
	    ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c \
	    ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c \
	    ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c ft_calloc.c \
	    ft_isascii.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c \
	    ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c get_next_line.c get_next_line_utils.c
BNS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	    ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c
NAME = libft.a
SRCS = $(SRC_FILES)
BNS = $(BNS_FILES)

OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(BNS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_BNS)
	$(AR) $(NAME) $(OBJS_BNS)

clean:
	rm -f $(OBJS) $(OBJS_BNS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
