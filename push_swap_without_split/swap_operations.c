/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:15:18 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 21:11:58 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ts_node **head)
{
	t_ts_node	*current;
	t_ts_node	*ptr;

	current = NULL;
	ptr = *head;
	if (ptr->next == NULL || ptr == NULL)
		return ;
	current = ptr->next;
	ptr->next = current->next;
	ptr->prev = current;
	current->next = ptr;
	if (ptr->next)
		ptr->next->prev = ptr;
	current->prev = NULL;
	*head = current;
}

void	sa(t_ts_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_ts_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}
