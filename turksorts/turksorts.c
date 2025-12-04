/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 03:49:14 by felix             #+#    #+#             */
/*   Updated: 2025/12/04 04:47:27 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int turk_sort(t_list **stack_a, t_list **stack_b)
{
    push_all_but_three(stack_a, stack_b);
    sort_three(stack_a);
}

void push_all_but_three(t_list **stack_a, t_list **stack_b)
{
    int size;

    size = ft_lstsize(*stack_a);
    while (size > 3)
    {
        pa(stack_b, stack_a, "pb");
        size--;
    }
}
int find_target_postion(int element_b, t_list *stack_a)
{
    t_list *tmp;
    int     pos;
    int     val_a;
    int     target_pos;
    int     best_match;
    
    pos = 0;
    val_a = (int)(long)tmp->content;
    tmp = stack_a;
    target_pos = -1;
    best_match = 2147483647;
    while (tmp)
    {
        if (val_a > element_b && val_a < best_match)
        {
            best_match = val_a;
            target_pos = pos;
        }
    }
    if (target_pos == -1)
        target_pos = find_min_position(stack_a);
    return (target_pos);
}

t_cost calculate_cost(int pos_b, int target_a, int size_a, int size_b)
{
    t_cost cost;
    if (pos_b <= size_b / 2)
        cost.cost_b = pos_b;
    else
        cost.cost_b = size_b - pos_b;
    if (target_a <= size_a / 2)
        cost.cost_a = target_a;
    else
        cost.cost_a = size_a - target_a;
    cost.total = cost.cost_a + cost.cost_b;
    return (cost);
}

int find_cheapest(t_list *stack_a, t_list *stack_b)
{
    t_cost cost;
    t_list *tmp;
    t_cheap cheap;

    tmp = stack_b;
    cheap.pos = 0;
    cheap.cheapest_pos = 0;
    cheap.min_cost = 2147483647;
    cheap.size_a = ft_lstsize(stack_a);
    cheap.size_b = ft_lstsize(stack_b);
    while (tmp)
    {
        cheap.element_b = (int)(long)tmp->content;
        cheap.target = find_target_postion(cheap.element_b, stack_a);
        cost = calculate_cost(cheap.pos, cheap.target, cheap.size_a, cheap.size_b);
        if (cost.total < min_cost)
            min_cost
    }
}
