/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:36:50 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 21:21:25 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_a(t_ts_node **a, t_ts_node **b)
{
	int			closest_small;
	t_ts_node	*ptr_a;
	t_ts_node	*ptr_b;
	t_ts_node	*target_node;

	ptr_a = *a;
	while (ptr_a)
	{
		closest_small = INT_MIN;
		ptr_b = *b;
		while (ptr_b)
		{
			if ((ptr_a->data > ptr_b->data) && (ptr_b->data > closest_small))
			{
				closest_small = ptr_b->data;
				target_node = ptr_b;
			}
			ptr_b = ptr_b->next;
		}
		if (closest_small == INT_MIN)
			ptr_a->target_node = max_node(*b);
		else
			ptr_a->target_node = target_node;
		ptr_a = ptr_a->next;
	}
}

void	calculate_cost(t_ts_node **a, t_ts_node **b)
{
	int			len_a;
	int			len_b;
	t_ts_node	*ptr_a;

	len_a = len_node(*a);
	len_b = len_node(*b);
	ptr_a = *a;
	while (ptr_a)
	{
		ptr_a->cost = ptr_a->index;
		if (!(ptr_a->above_middle))
			ptr_a->cost = len_a - (ptr_a->index);
		if (ptr_a->target_node->above_middle)
			ptr_a->cost += ptr_a->target_node->index;
		else
			ptr_a->cost += len_b - (ptr_a->target_node->index);
		ptr_a = ptr_a->next;
	}
}

void	*find_cheapest(t_ts_node **head)
{
	int			cheapest_value;
	t_ts_node	*cheapest_node;
	t_ts_node	*ptr;

	if (!*head)
		return (NULL);
	ptr = *head;
	cheapest_value = INT_MAX;
	while (ptr)
	{
		if (ptr->cost < cheapest_value)
		{
			cheapest_value = ptr->cost;
			cheapest_node = ptr;
		}
		ptr = ptr->next;
	}
	cheapest_node->cheapest = true;
	return (NULL);
}

void	prepare_pb(t_ts_node **a, t_ts_node **b)
{
	add_index(a);
	add_index(b);
	find_target_a(a, b);
	calculate_cost(a, b);
	find_cheapest(a);
}

void	move_a_to_b(t_ts_node **a, t_ts_node **b)
{
	t_ts_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_middle && cheapest_node->target_node->above_middle)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle) && \
				!(cheapest_node->target_node->above_middle))
		rev_rotate_both(a, b, cheapest_node);
	move_on_top_a(a, cheapest_node);
	move_on_top_b(b, cheapest_node->target_node);
	pb(b, a);
}
