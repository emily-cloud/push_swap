/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:33:47 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 21:16:34 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_ts_node **dest, t_ts_node **src)
{
	t_ts_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		(*dest)->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_ts_node **a, t_ts_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_ts_node **b, t_ts_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
