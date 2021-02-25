# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: danali <danali@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/01 09:02:27 by danali        #+#    #+#                  #
#    Updated: 2020/12/11 16:35:20 by danali        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	aux_functions.c handle_char.c handle_string.c handle_pointer.c\
		handle_integer.c handle_unsigned.c field_width.c precision.c flags.c\
		ft_printf.c handle_args.c

OBJS =	$(SRCS:.c=.o)

CFLAGS =	-Wall -Wextra -Werror

CC =	gcc

LIBFT = libft.a

LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)/
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re %.o
