/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:15:20 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/07 12:25:31 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int *lst_a)
{
	int		i;
	t_stack	*cur;
	t_stack	*next;

	i = 0;
	cur = ft_lstnew(lst_a[0]);
	while (++i, lst_a[i])
		cur->next = ft_lstnew(lst_a[i]);
	cur->next = NULL;
}