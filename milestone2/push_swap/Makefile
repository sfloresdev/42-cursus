NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft
FTPRINTF_DIR = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

SRC = push_swap.c \
	  parser.c \
	  utils.c \
	  stack_utils.c \
	  operations/operations_a.c \
	  operations/operations_b.c \
	  operations/operations_both.c \
	  algo/sort_small.c \
	  algo/redix.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I. -I$(LIBFT_DIR) -I$(FTPRINTF_DIR)

all:$(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(FTPRINTF):
	@make -C $(FTPRINTF_DIR)

# Compilar push_swap
$(NAME): $(LIBFT) $(FTPRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FTPRINTF) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FTPRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
