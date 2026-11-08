NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -Ilibft

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= push_swap.c \
			  Operations/call_operation.c \
			  Operations/push.c \
			  Operations/r_rotate.c \
			  Operations/rotate.c \
			  Operations/swap.c \
			  algorithm/adaptive.c \
			  algorithm/complex.c \
			  algorithm/disorder_metric.c \
			  algorithm/medium.c \
			  algorithm/simple.c \
			  utility/call_strategy.c \
			  utility/check_valid_lst.c \
			  utility/check_valid_strategy.c \
			  utility/clear_lst_op.c \
			  utility/clear_stack.c \
			  utility/create_stack.c \
			  utility/handle_error.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
