LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

LIBFT_SRCS = $(addprefix $(LIBFT_DIR), ft_isalpha.c ft_isdigit.c ft_isalnum.c \
             ft_isascii.c ft_isprint.c ft_strlen.c ft_strnlen.c ft_memset.c \
             ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
             ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
             ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
             ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
             ft_itoa.c ft_uitoa.c ft_uitoa_caps.c ft_ultoa.c ft_strmapi.c \
             ft_striteri.c ft_putchar.c ft_putchar_fd.c ft_putstr_fd.c \
             ft_putstr.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
             ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
             ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

SRCS = ft_printf.c print_conversions.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_printf_bonus.c spec_parser_bonus.c ft_print_c_bonus.c \
             ft_print_s_bonus.c ft_print_p_bonus.c ft_print_d_bonus.c \
             ft_print_u_bonus.c ft_print_x_bonus.c utils_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

CLIB = ar rcs

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	$(CLIB) $@ $(OBJS)
	make bclean

$(LIBFT): $(LIBFT_OBJS)
	make -C $(LIBFT_DIR)

%.o: %.c ft_printf.h Makefile $(LIBFT_DIR)libft.h $(LIBFT_DIR)Makefile
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
