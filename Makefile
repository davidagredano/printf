SRCS = ft_printf.c ft_print_c.c ft_print_s.c ft_print_p.c ft_print_di.c \
       ft_print_uint.c ft_print_percent.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_printf_bonus.c ft_print_c_bonus.c ft_print_s_bonus.c \
             ft_print_p_bonus.c ft_print_di_bonus.c ft_print_u_bonus.c \
             ft_print_x_bonus.c ft_print_percent_bonus.c ft_spec_parser.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libftprintf.a

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

CLIB = ar rcs

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	$(CLIB) $@ $(OBJS)
	make bclean

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c ft_printf.h Makefile
	$(CC) -c $(CFLAGS) -o $@ $<

clean: mclean bclean lclean

fclean: clean
	$(RM) $(LIBFT) $(NAME)

re:	fclean all

bonus: $(LIBFT) $(OBJS_BONUS)
	cp $(LIBFT) $(NAME)
	$(CLIB) $(NAME) $(OBJS_BONUS)
	make mclean
	@touch bonus

mclean:
	$(RM) $(OBJS)

bclean:
	$(RM) $(OBJS_BONUS) bonus

lclean:
	make clean -C $(LIBFT_DIR)

.PHONY: all clean fclean re mclean bclean
