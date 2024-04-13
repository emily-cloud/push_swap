/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:27:54 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 21:21:57 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ts_node	*lastnode(t_ts_node *head)
{
	t_ts_node	*ptr;

	ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

int	len_node(t_ts_node *head)
{
	int			len;
	t_ts_node	*ptr;

	len = 0;
	ptr = head;
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}

bool	stack_sorted(t_ts_node **a)
{
	t_ts_node	*ptr;

	ptr = *a;
	if (ptr == NULL)
		return (true);
	while (ptr->next)
	{
		if (ptr->data > ptr->next->data)
			return (false);
		ptr = ptr->next;
	}
	return (true);
}

t_ts_node	*max_node(t_ts_node *head)
{
	t_ts_node	*ptr;
	t_ts_node	*max;

	ptr = NULL;
	max = NULL;
	ptr = head;
	max = head;
	if (ptr == NULL)
		return (NULL);
	if (ptr->next == NULL)
		return (max);
	while (ptr)
	{
		if (ptr->data > max->data)
			max = ptr;
		ptr = ptr->next;
	}
	return (max);
}

t_ts_node	*min_node(t_ts_node *head)
{
	t_ts_node	*min;
	t_ts_node	*ptr;

	min = NULL;
	ptr = NULL;
	min = head;
	ptr = head;
	if (!head)
		return (NULL);
	while (ptr)
	{
		if (ptr->data < min->data)
			min = ptr;
		ptr = ptr->next;
	}
	return (min);
}
