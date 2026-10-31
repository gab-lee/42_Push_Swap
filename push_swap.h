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

#endif