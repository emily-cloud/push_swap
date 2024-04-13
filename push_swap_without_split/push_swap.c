/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:48:39 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 23:07:14 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	number;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}

void	min_on_top(t_ts_node **a)
{
	t_ts_node	*min;

	min = min_node(*a);
	while ((*a)->data != min->data)
	{
		if (min->above_middle)
			ra(a);
		else
			rra(a);
	}
}

void	add_index(t_ts_node **head)
{
	int			index;
	int			middle;
	t_ts_node	*ptr;

	ptr = *head;
	index = 0;
	if (*head == NULL)
		return ;
	middle = len_node(*head) / 2;
	while (ptr)
	{
		ptr->index = index++;
		if (ptr->index <= middle)
			ptr->above_middle = true;
		else
			ptr->above_middle = false;
		ptr = ptr->next;
	}
}

void	sort_allstacks(t_ts_node **a, t_ts_node **b)
{
	if (!stack_sorted(a))
	{
		if (len_node(*a) == 2)
			sa(a);
		else if (len_node(*a) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
}

int	main(int argc, char **av)
{
	t_ts_node	*a;
	t_ts_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && av[1][0] == '\0'))
		return (1);
	if (invalide_check(av + 1))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	set_linklist(&a, av + 1);
	sort_allstacks(&a, &b);
	free_stack(&a);
}
