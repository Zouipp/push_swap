/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 03:55:00 by felix             #+#    #+#             */
/*   Updated: 2025/12/04 04:25:33 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_intlen(int *in)
{
	int	i;

	i = 0;
	while (in[i])
		i++;
	return (i);		
}

int find_min_position(t_list *stack)
{
    t_list *tmp;
    int count;

    count = 0;
    tmp = stack;
    while (tmp)
    {
        if ((int)(long)tmp->content == 0)
            return (count);
        tmp = tmp->next;
        count++;
    }
    return (count);
}
int find_max_position(t_list *stack)
{
    int max;
    int count;
    int actual_count;
    t_list *tmp;

    count = 0;
    tmp = stack;
    actual_count = 0;
    max = (int)(long)tmp->content;
    while (tmp)
    {
        if ((int)(long)tmp->content > max)
        {
            max = (int)(long)tmp->content;
            count = actual_count;
        }
        tmp = tmp->next;
        actual_count++;
    }
    return (count);
}