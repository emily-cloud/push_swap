/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:13:33 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 17:06:14 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digital_check(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] != '+' && av[i][j] != '-' \
			&& !(av[i][j] >= '0' && av[i][j] <= '9'))
			return (1);
		if ((av[i][j] == '+' || av[i][j] == '-') && \
			!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
			return (1);
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
		}
		i++;
	}
	return (0);
}

int	dup_check(char **av)
{
	int		i;
	int		j;
	long	n1;
	long	n2;

	i = 0;
	while (av[i])
	{
		n1 = ft_atoi(av[i]);
		j = i + 1;
		while (av[j])
		{
			n2 = ft_atoi(av[j]);
			if (n1 == n2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	exceedlimit(char **av)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	invalide_check(char **av)
{
	if (digital_check(av))
		return (1);
	if (dup_check(av))
		return (1);
	if (exceedlimit(av))
		return (1);
	return (0);
}
