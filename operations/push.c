/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiechang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:52:01 by jiechang          #+#    #+#             */
/*   Updated: 2026/11/14 09:48:26 by jiechang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!*stack_b)
		return (0);
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp;

	return (0);
}

