/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:14:51 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/31 11:24:03 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*prev;

	(void)stack_b;
	if (!*stack_a || !(*stack_a)->next)
		return (0);
	while (prev->next->next)
		prev = (prev)->next;
	last = prev->next;
	ft_lstadd_front(stack_a, last);
	prev->next = NULL;
	return (0);
}