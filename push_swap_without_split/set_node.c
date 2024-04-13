/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:14:35 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 23:03:54 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_ts_node **head)
{
	t_ts_node	*current;
	t_ts_node	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

t_ts_node	*iniate_node(int data)
{
	t_ts_node	*temp;

	temp = NULL;
	temp = malloc(sizeof(t_ts_node));
	if (temp == NULL)
		return (NULL);
	temp->data = data;
	temp->cheapest = false;
	temp->above_middle = false;
	temp->target_node = NULL;
	temp->index = 0;
	temp->cost = INT_MAX;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

void	append_node(t_ts_node **head, t_ts_node *temp)
{
	t_ts_node	*end;

	end = NULL;
	if (*head == NULL)
	{
		*head = temp;
		return ;
	}
	end = lastnode(*head);
	end->next = temp;
	temp->prev = end;
}

t_ts_node	*set_linklist(t_ts_node **head, char **av)
{
	t_ts_node	*temp;
	long		data;
	int			i;

	temp = NULL;
	if (*av[0] == '\0')
		return (NULL);
	i = 0;
	while (av[i])
	{
		data = ft_atoi(av[i]);
		temp = iniate_node(data);
		if (temp == NULL)
		{
			free_stack(head);
			return (NULL);
		}
		append_node(head, temp);
		i++;
	}
	return (*head);
}
