/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:22:09 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/08 19:18:06 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_op(char *op, t_lst_op **lst_op);

int	call_op(char *op, t_stack **stack_a, t_stack **stack_b, t_lst_op **lst_op)
{
	add_op(op, lst_op);
	if (!ft_strncmp(op, "rra", 3))
		return (r_rotate(stack_a, stack_b));
	if (!ft_strncmp(op, "rrb", 3))
		return (r_rotate(stack_b, stack_a));
	if (!ft_strncmp(op, "rrr", 3))
		return (r_rotate(stack_a, stack_b) && r_rotate(stack_b, stack_a));
	if (!ft_strncmp(op, "pa", 2))
		return (push(stack_a, stack_b));
	if (!ft_strncmp(op, "pb", 2))
		return (push(stack_b, stack_a));
	if (!ft_strncmp(op, "sa", 2))
		return (swap(stack_a, stack_b));
	if (!ft_strncmp(op, "sb", 2))
		return (swap(stack_b, stack_a));
	if (!ft_strncmp(op, "ra", 2))
		return (rotate(stack_a, stack_b));
	if (!ft_strncmp(op, "rb", 2))
		return (rotate(stack_b, stack_a));
	if (!ft_strncmp(op, "rr", 2))
		return (rotate(stack_a, stack_b) && rotate(stack_b, stack_a));
	return (-1);
}

static int	add_op(char *op, t_lst_op **lst_op)
{
	t_lst_op	*new;

	new = ft_lstnew(op);
	if (!new)
		return (-1);
	ft_lstadd_back(lst_op, new);
	return (0);
}
