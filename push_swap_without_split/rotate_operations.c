/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:32:48 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 21:22:20 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_ts_node **stack)
{
	t_ts_node	*last_node;
	int			len;

	len = len_node(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = lastnode(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_ts_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_ts_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_ts_node **a, t_ts_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
