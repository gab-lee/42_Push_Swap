/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:25:34 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/31 16:17:54 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_valid_lst(int *stack_a)
{
	if (!(*stack_a))
		return (-1);
	cur = *stack_a;
	while (cur)
	{
		while(next)
		cur = cur->next;
	}	
}
- check stack a is valid list of integers > 1
- if number 1 -> 0 (no sorting required)
- if invalid -> -1
not integers, integers outside the
valid range, or duplicate values.
0 successful
-1 fail


Errors include, for example: arguments that are not integers, integers outside the
valid range, or duplicate values.