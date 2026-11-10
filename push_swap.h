# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef t_list	t_stack;
typedef t_list	t_lst_op;
typedef	struct s_bench{
	int		disorder;
	char	*strategy;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

/* Ops */
int		swap(t_stack **stack_a, t_stack **stack_b);
int		push(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **stack_a, t_stack **stack_b);
int		r_rotate(t_stack **stack_a, t_stack **stack_b);

/* Algorithms */
int		simple(t_stack **stack_a, t_lst_op **lst_op);
int		medium(t_stack **stack_a, t_lst_op **lst_op);
int		complex(t_stack **stack_a, t_lst_op **lst_op);
int		adaptive(t_stack **stack_a, t_lst_op **lst_op);

/* Utility */
int		el_compare(t_stack *a, t_stack *b);
int		handle_error(void);
int		check_valid_lst(int *lst_a);
t_stack	*create_stack(int *lst_a);
int		call_op(char *op, t_stack **stack_a, t_stack **stack_b, t_lst_op **lst_op);
int		call_strategy(char *strategy, t_stack **stack_a,
			t_lst_op **lst_op);
int		benchmark(t_bench *bench, t_lst_op *lst_op);
double	compute_disorder(t_stack **stack_a);
void	del(void *content);

#endif