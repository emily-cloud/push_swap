/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:38:09 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 20:38:09 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_ts_node **a, t_ts_node **b, t_ts_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b);
	add_index(a);
	add_index(b);
}

void	rev_rotate_both(t_ts_node **a, t_ts_node **b, t_ts_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b);
	add_index(a);
	add_index(b);
}

t_ts_node	*get_cheapest(t_ts_node *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	sort_three(t_ts_node **a)
{
	t_ts_node	*max;

	max = max_node(*a);
	if (max == *a)
		ra(a);
	else if (max == (*a)->next)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort_stack(t_ts_node **a, t_ts_node **b)
{
	int	len_a;

	len_a = len_node(*a);
	if (len_a-- > 3 && !stack_sorted(a))
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(a))
	{
		prepare_pb(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prepare_pa(a, b);
		move_b_to_a(a, b);
	}
	add_index(a);
	min_on_top(a);
}
