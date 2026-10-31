/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:38:23 by gabrlee           #+#    #+#             */
/*   Updated: 2026/10/31 16:03:08 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack **stack_a)
{
	double		mistakes;
	double		total_pairs;
	t_stack		*cur;
	t_stack		*next;

	mistakes = 0.0;
	total_pairs = 0.0;
	cur = *stack_a;
	while (cur)
	{
		next = cur->next;
		while (next)
		{
			total_pairs++;
			if (el_compare(cur, next) > 0)
				mistakes++;
			next = next->next;
		}
		cur = cur->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((mistakes / total_pairs));
}