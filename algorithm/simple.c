/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiechang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:10:25 by jiechang          #+#    #+#             */
/*   Updated: 2026/11/14 09:49:31 by jiechang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *stack)
{
	t_stack	*min_node;
	int		i;
	int		min_idx;

	i = 0;
	min_idx = 0;
	min_node = stack;
	while (stack)
	{
		if (*(int *)stack->content < *(int *)min_node->content)
		{
			min_node = stack;
			min_idx = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_idx);
}

static int	chk_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->next->content < *(int *)stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_three(t_stack **stack_a, t_stack **stack_b, t_lst_op **lst_op)
{
	int	top;
	int	mid;
	int	btm;

	top = *(int *)stack_a->content;
	mid = *(int *)stack_a->next->content;
	btm = *(int *)stack_a->next->next->content;
	if (top > mid && top > btm)
		call_op("ra", stack_a, stack_b, lst_op);
	else if (mid > top && mid > btm)
		call_op("rra", stack_a, stack_b, lst_op);
	if (*(int *)stack_a->content > *(int *)stack_a->next->content)
		call_op("sa", stack_a, stack_b, lst_op);
}

void	sel_sort(t_stack **stack_a, t_stack **stack_b, t_lst_op **lst_op)
{
	int	size;
	int	min_idx;

	if (chk_sorted(*stack_a))
		return ;
	while (ft_lstsize(*stack_a) > 3)
	{
		size = ft_lstsize(*stack_a);
		min_idx = find_min(*stack_a);
		while (min_idx > 0 && min_idx < size)
		{
			if (min_idx <= size / 2 && min_idx--)
				call_op("ra", stack_a, stack_b, lst_op);
			else if (min_idx++)
				call_op("rra", stack_a, stack_b, lst_op);
		}
		call_op("pb", stack_a, stack_b, lst_op);
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a, stack_b, lst_op);
	else
		call_op("sa", stack_a, stack_b, lst_op);
	while (*stack_b)
		call_op("pa", stack_a, stack_b, lst_op);
}

