/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:52:28 by hai               #+#    #+#             */
/*   Updated: 2024/04/13 23:04:14 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_ts_node
{
	bool				cheapest;
	bool				above_middle;
	int					data;
	int					index;
	int					cost;
	struct t_ts_node	*target_node;
	struct t_ts_node	*prev;
	struct t_ts_node	*next;
}						t_ts_node;

long					ft_atoi(const char *str);
t_ts_node				*lastnode(t_ts_node *head);
int						len_node(t_ts_node *head);

//check the input is number, exceed limit, double
int						digital_check(char **av);
int						dup_check(char **av);
int						exceedlimit(char **av);
int						invalide_check(char **av);

//operations
void					swap(t_ts_node **head);
void					push(t_ts_node **dest, t_ts_node **src);
void					rotate(t_ts_node **head);
void					reverse_rotate(t_ts_node **stack);
void					sa(t_ts_node **a);
void					sb(t_ts_node **b);
void					pa(t_ts_node **a, t_ts_node **b);
void					pb(t_ts_node **b, t_ts_node **a);
void					ra(t_ts_node **a);
void					rb(t_ts_node **b);
void					rr(t_ts_node **a, t_ts_node **b);
void					rra(t_ts_node **a);
void					rrb(t_ts_node **b);
void					rrr(t_ts_node **a, t_ts_node **b);

//set to stack
t_ts_node				*iniate_node(int data);
void					append_node(t_ts_node **head, t_ts_node *temp);
t_ts_node				*set_linklist(t_ts_node **a, char **av);
void					add_index(t_ts_node **head);
void					free_stack(t_ts_node **head);

//sort stack
void					sort_allstacks(t_ts_node **a, t_ts_node **b);
void					sort_three(t_ts_node **a);
void					sort_stack(t_ts_node **a, t_ts_node **b);
bool					stack_sorted(t_ts_node **a);
t_ts_node				*max_node(t_ts_node *head);
t_ts_node				*min_node(t_ts_node *head);
void					rotate_both(t_ts_node **a, t_ts_node **b,
							t_ts_node *cheapest_node);
void					rev_rotate_both(t_ts_node **a, t_ts_node **b,
							t_ts_node *cheapest_node);
void					find_target_a(t_ts_node **a, t_ts_node **b);
void					find_target_b(t_ts_node **a, t_ts_node **b);
void					calculate_cost(t_ts_node **a, t_ts_node **b);
void					*find_cheapest(t_ts_node **head);
t_ts_node				*get_cheapest(t_ts_node *head);
void					prepare_pb(t_ts_node **a, t_ts_node **b);
void					prepare_pa(t_ts_node **a, t_ts_node **b);
void					move_on_top_a(t_ts_node **a, t_ts_node *aim_node);
void					move_on_top_b(t_ts_node **b, t_ts_node *aim_node);
void					move_a_to_b(t_ts_node **a, t_ts_node **b);
void					move_b_to_a(t_ts_node **a, t_ts_node **b);
void					min_on_top(t_ts_node **a);

#endif
