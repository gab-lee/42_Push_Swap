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

/* Algorithms */
int		simple(t_stack **stack_a, t_lst_op **lst_operations);
int		medium(t_stack **stack_a, t_lst_op **lst_operations);
int		complex(t_stack **stack_a, t_lst_op **lst_operations);
int		adaptive(t_stack **stack_a, t_lst_op **lst_operations);

/* Utility */
int		el_compare(t_stack *a, t_stack *b);
int		handle_error(void);
int		check_valid_lst(int *stack_a);

#endif