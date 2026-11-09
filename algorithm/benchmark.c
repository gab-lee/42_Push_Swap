/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrlee <gabrlee@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:24:38 by gabrlee           #+#    #+#             */
/*   Updated: 2026/11/09 10:38:05 by gabrlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	benchmark(t_bench *bench)
{
	ft_printf("disorder: %d\n", bench->disorder);
	ft_printf("strategy: %d\n", bench->strategy);
	ft_printf("total_ops: %d\n", bench->total_ops);
	ft_printf("sa: %d\tsb: %d\tss: %d\tpa: %d\tpb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("ra: %d\trb: %d\trr: %d\trra: %d\trrb: %d\trrr: %d\n",
		bench->ra, bench->rb, bench->rr,
		bench->rra, bench->rrb, bench->rrr);
	return (0);
}
