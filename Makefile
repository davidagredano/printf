AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -MMD -Wall -Wextra -Werror
COMPILE.c = $(CC) $(CFLAGS) -c
OUTPUT_OPTION = -o $@

RM = rm -f
RMDIR = rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = libftprintf.a
SRCS_DIR = srcs
SRCS = ft_printf.c spec_parser.c print_c.c print_s.c print_p.c print_d.c \
		print_u.c print_x.c utils.c
BUILD_DIR = build
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS = $(SRCS:%.c=$(BUILD_DIR)/%.d)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c $(BUILD_DIR)/%.d Makefile | $(BUILD_DIR)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILD_DIR):
	mkdir -p $@


%.d: ;

-include $(DEPS)


clean:
	$(RMDIR) $(BUILD_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re:	fclean all
