/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 03:49:14 by felix             #+#    #+#             */
/*   Updated: 2025/12/07 03:59:50 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min(int *stack, int *new_stack, int size);

void	ft_chunk(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;
	int	chunk;

	i = 0;
	size = ft_lstsize(*stack_a);
	chunk = 30;
	if (size <= 100)
		chunk = 20;
	while (*stack_a)
	{
		if ((int)(long)(*stack_a)->content <= i)
		{
			pa(stack_b, stack_a, "pb");
			rotate(stack_b, "rb");
			i++;
		}
		else if ((int)(long)(*stack_a)->content <= i + chunk)
		{
			pa(stack_b, stack_a, "pb");
			i++;
		}
		else
			rotate(stack_a, "ra");
	}
}

void	ft_medium_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	min_index;

	while (ft_lstsize(*stack_a) > 3)
	{
		min_index = find_min_position(*stack_a);
		size = ft_lstsize(*stack_a);
		if (min_index <= size / 2)
		{
			while (min_index > 0)
				(rotate(stack_a, "ra"), min_index--);
		}
		else
		{
			while (min_index < size)
				(reverse_rotate(stack_a, "rra"), min_index++);
		}
		pa(stack_b, stack_a, "pb");
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, "pa");
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	if (size <= 3)
		return (sort_three(stack_a));
	else if (size == 4 || size == 5)
		return (ft_medium_sort(stack_a, stack_b));
	else
	{
		ft_chunk(stack_a, stack_b);
		ft_sort_to_a(stack_a, stack_b);
		final_rotation(stack_a);
	}
}

static int	get_min(int *stack, int *new_stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (new_stack[i] != -1)
		i++;
	min = i;
	i = 0;
	while (i < size)
	{
		if (stack[i] < stack[min] && new_stack[i] == -1)
			min = i;
		i++;
	}
	return (min);
}

int	*int_to_index(int *stack, int size)
{
	int	i;
	int	j;
	int	min;
	int	*new_stack;

	i = 0;
	j = 0;
	min = 0;
	new_stack = malloc(sizeof(int) * size);
	if (new_stack == NULL)
		return (free(stack), NULL);
	while (i < size)
		new_stack[i++] = -1;
	i = -1;
	while (++i < size)
		new_stack[get_min(stack, new_stack, size)] = i;
	free(stack);
	return (new_stack);
}
