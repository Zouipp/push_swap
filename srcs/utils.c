/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 03:14:41 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 03:52:17 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*create_stack_from_array(int *arr, int size)
{
	int		i;
	t_list	*stack;
	t_list	*node;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		node = ft_lstnew((void *)(long)arr[i]);
		if (!node)
		{
			ft_lstclear(&stack, NULL);
			return (NULL);
		}
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}

int	find_min_position(t_list *stack)
{
	t_list	*tmp;
	int		count;

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

int	find_max_postion(t_list *stack)
{
	int		max;
	int		count;
	int		actual_count;
	t_list	*tmp;

	tmp = stack;
	count = 0;
	actual_count = 0;
	if (!stack)
		return (0);
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

int	find_target_postion(int element_b, t_list *stack_a)
{
	t_list	*tmp;
	int		pos;
	int		val_a;
	int		target_pos;
	int		best_match;

	pos = 0;
	tmp = stack_a;
	target_pos = -1;
	best_match = 2147483647;
	while (tmp)
	{
		val_a = (int)(long)tmp->content;
		if (val_a > element_b && val_a < best_match)
		{
			best_match = val_a;
			target_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (target_pos == -1)
		target_pos = find_min_position(stack_a);
	return (target_pos);
}
