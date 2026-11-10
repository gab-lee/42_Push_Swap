/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:25:34 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/07 11:53:34 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_lst(int *lst_a)
{
	int		i;
	int		j;

	i = -1;
	while (++i, lst_a[i])
	{
		if (!ft_isdigit(lst_a[i]))
			return (-1);
		j = i;
		while (++j, lst_a[j])
		{
			if (lst_a[i] == lst_a[j])
				return (-1);
		}
	}
	return (0);
}
