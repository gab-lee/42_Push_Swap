#ifndef TEST_UTILS_H
# define TEST_UTILS_H

# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include "../push_swap.h"

/* content holds the value itself, cast to a pointer (see el_compare) */

static inline t_stack	*build_stack(const int *values, int n)
{
	t_stack	*head;
	t_stack	*node;
	int		i;

	head = NULL;
	i = n;
	while (i-- > 0)
	{
		node = malloc(sizeof(t_stack));
		node->content = (void *)(intptr_t)values[i];
		node->next = head;
		head = node;
	}
	return (head);
}

static inline void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

static inline int	stack_size(t_stack *stack)
{
	int	n;

	n = 0;
	while (stack)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

/* 1 if the stack holds exactly values[0..n-1], top first */
static inline int	stack_equals(t_stack *stack, const int *values, int n)
{
	int	i;

	i = 0;
	while (stack && i < n)
	{
		if ((intptr_t)stack->content != values[i])
			return (0);
		stack = stack->next;
		i++;
	}
	return (i == n && !stack);
}

static inline int	stack_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if ((intptr_t)stack->content > (intptr_t)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static inline int	report(const char *name, int ok)
{
	printf("%s  %s\n", ok ? "PASS" : "FAIL", name);
	return (!ok);
}

#endif
