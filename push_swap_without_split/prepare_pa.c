/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:36:35 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 21:20:25 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_on_top_a(t_ts_node **a, t_ts_node *aim_node)
{
	while (*a != aim_node)
	{
		if (aim_node->above_middle)
			ra(a);
		else
			rra(a);
	}
}

void	move_on_top_b(t_ts_node **b, t_ts_node *aim_node)
{
	while (*b != aim_node)
	{
		if (aim_node->above_middle)
			rb(b);
		else
			rrb(b);
	}
}

void	find_target_b(t_ts_node **a, t_ts_node **b)
{
	int			closest_big;
	t_ts_node	*ptr_a;
	t_ts_node	*ptr_b;
	t_ts_node	*target_node;

	ptr_b = *b;
	while (ptr_b)
	{
		closest_big = INT_MAX;
		ptr_a = *a;
		while (ptr_a)
		{
			if ((ptr_a->data > ptr_b->data) && (ptr_a->data < closest_big))
			{
				closest_big = ptr_a->data;
				target_node = ptr_a;
			}
			ptr_a = ptr_a->next;
		}
		if (closest_big == INT_MAX)
			ptr_b->target_node = min_node(*a);
		else
			ptr_b->target_node = target_node;
		ptr_b = ptr_b->next;
	}
}

void	prepare_pa(t_ts_node **a, t_ts_node **b)
{
	add_index(a);
	add_index(b);
	find_target_b(a, b);
}

void	move_b_to_a(t_ts_node **a, t_ts_node **b)
{
	move_on_top_a(a, (*b)->target_node);
	pa(a, b);
}
