NAME		= Push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I. -I./libft -I./includes

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= srcs/cestqueledebut.c srcs/main.c srcs/parsing.c srcs/parsing_p_two.c\
	srcs/push.c srcs/sort.c srcs/swap.c srcs/chunksort.c srcs/utils.c srcs/sort_five.c\

OBJS		= $(SRCS:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)


%.o: %.c includes/push_swap.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re