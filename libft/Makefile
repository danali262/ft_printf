# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: danali <danali@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/30 09:10:54 by danali        #+#    #+#                  #
#    Updated: 2020/12/01 09:22:22 by danali        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

REG_SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c\
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
			ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c\
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
			ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c\
			ft_itoa_base_lower.c ft_itoa_base_pointer.c ft_itoa_base_upper.c\
			ft_itoa_unsigned.c

REG_OBJS = $(REG_SRCS:.c=.o)

BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = libft.h

ifdef WITH_BONUS
OBJS = $(REG_OBJS) ${BONUS_OBJS}
else
OBJS = $(REG_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(REG_OBJS) ${BONUS_OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus %.o
