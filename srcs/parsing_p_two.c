/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_p_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:49:43 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 03:07:02 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_there_char(char **list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (list[j])
	{
		if (list[j][i] == '-' || list[j][i] == '+')
			i++;
		if (!list[j][i])
			return (0);
		while (list[j][i])
		{
			if (list[j][i] >= '0' && list[j][i] <= '9')
				i++;
			else
				return (0);
		}
		i = 0;
		j++;
	}
	return (1);
}

int	is_it_too_big(char *str)
{
	char	*i_max;
	char	*i_min;

	i_max = "2147483647";
	i_min = "2147483648";
	if (str[0] == '-')
		return (int_min(str, i_min));
	else
		return (int_max(str, i_max));
}

int	int_min(char *str, char *i_min)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ft_strlen(str) > 11)
		return (0);
	else if (ft_strlen(str) < 11)
		return (1);
	while (str[i])
	{
		if (str[i] - i_min[j] > 0)
			print_error("Arg under the min_int");
		else if (str[i] - i_min[j] < 0)
			return (1);
		i++;
		j++;
	}
	return (1);
}

int	int_max(char *str, char *i_max)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 10)
		return (0);
	else if (ft_strlen(str) < 10)
		return (1);
	while (str[i])
	{
		if (str[i] - i_max[i] < 0)
			print_error("Arg above the max_int !");
		else if (str[i] - i_max[i] > 0)
			return (1);
		i++;
	}
	return (1);
}
