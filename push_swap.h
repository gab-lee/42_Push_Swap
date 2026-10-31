# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lst_op
{
	void			*op;
	struct s_lst_op	*next;
}	t_lst_op;

/* Operations */
int		swap(t_stack **stack_a, t_stack **stack_b);
int		push(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **stack_a, t_stack **stack_b);
int		r_rotate(t_stack **stack_a, t_stack **stack_b);

#endif