/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiechang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:29:42 by jiechang          #+#    #+#             */
/*   Updated: 2026/11/15 00:35:02 by jiechang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	compute_disorder(t_stack **stack_a)
{
	t_stack	*i;	
	t_stack	*j;	
	long	disorder;
	long	pairs;

	disorder = 0;
	pairs = 0;
	i = *stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if ((int)(long)i->content > (int)(long)j->content)
				disorder++;
			j = j->next;
		}
		i = i->next;
	}
	if (pairs == 0)
		return (0.0);
	return ((double)disorder / pairs);
}
