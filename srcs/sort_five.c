/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:23:56 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 03:54:51 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 01:45:00 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 01:45:00 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_small_pos(t_list *stack_a)
{
	t_list	*tmp;
	int		pos;
	int		i;

	tmp = stack_a;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if ((int)(long)tmp->content == 0 || (int)(long)tmp->content == 1)
		{
			pos = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	rotate_small_to_top(t_list **stack_a, int pos)
{
	if (pos <= 2)
	{
		while ((int)(long)(*stack_a)->content != 0
			&& (int)(long)(*stack_a)->content != 1)
			rotate(stack_a, "ra");
	}
	else
	{
		while ((int)(long)(*stack_a)->content != 0
			&& (int)(long)(*stack_a)->content != 1)
			reverse_rotate(stack_a, "rra");
	}
}

void	push_two_smallest(t_list **stack_a, t_list **stack_b)
{
	int	pushed;
	int	pos;

	pushed = 0;
	while (pushed < 2)
	{
		pos = find_small_pos(*stack_a);
		rotate_small_to_top(stack_a, pos);
		pa(stack_b, stack_a, "pb");
		pushed++;
	}
}
