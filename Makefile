SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra

CLIB = ar rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CLIB) $@ $(LIBFT) $^

%.o: %.c ft_printf.h Makefile
	$(CC) -c $(FLAGS) -o $@ $<

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
