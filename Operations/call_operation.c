#include "push_swap.h"

int cal_operation(char *operation, t_stack stack_a, t_stack stack_b)
{
	if (operation == "pa")
		return (push(stack_a, stack_b));
	if (operation == "pb")
		return (push(stack_b, stack_a));
	if (operation == "sa")
		return (swap(stack_a, stack_b));
	if (operation == "sb")
		return (swap(stack_b, stack_a));
	if (operation == "ra")
		return (rotate(stack_a, stack_b));
	if (operation == "rb")
		return (rotate(stack_b, stack_a));
	if (operation == "rr")
		return (rotate(stack_a, stack_b) && rotate(stack_b, stack_a));
	if (operation == "rra")
		return (reverse_rotate(stack_a, stack_b));
	if (operation == "rrb")
		return (reverse_rotate(stack_b, stack_a));
	if (operation == "rrr")
		return (reverse_rotate(stack_a, stack_b) && reverse_rotate(stack_b, stack_a));
}
