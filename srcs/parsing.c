/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:53:01 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 03:39:26 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_words(char const *src, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		while (src[i] && src[i] == c)
		{
			i++;
		}
		if (src[i] && src[i] != c)
		{
			count++;
		}
		while (src[i] && src[i] != c)
			i++;
	}
	if (count == 0)
		return (0);
	return (count);
}

int	count_numbers(char **av)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (av[i])
	{
		count += count_words(av[i], ' ');
		i++;
	}
	return (count);
}

int	*parsing(char **av)
{
	int		i;
	int		j;
	int		k;
	char	**list;
	char	**tmp;

	i = 0;
	k = 0;
	list = malloc(sizeof(char *) * (count_numbers(av) + 1));
	if (!list)
		return (NULL);
	while (av[++i])
	{
		j = -1;
		tmp = ft_split(av[i], ' ');
		if (!tmp)
			return (free (list), NULL);
		while (tmp[++j])
		{
			list[k] = tmp[j];
			k++;
		}
		free(tmp);
	}
	return (list[k] = NULL, from_char_to_int(list, k));
}

int	*from_char_to_int(char **list, int size)
{
	int	i;
	int	*list_num;

	i = 0;
	if (!is_there_char(list))
	{
		free_tab(list);
		print_error("Only number require as parameter");
	}
	list_num = malloc(sizeof(int) * (len_tab(list) + 1));
	if (!list_num)
		return (free_tab(list), NULL);
	while (i < size)
	{
		list_num[i] = ft_atoi(list[i]);
		i++;
	}
	free_tab(list);
	return (list_num);
}

int	check_duplicate(int *list_num, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (list_num[i] == list_num[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
// int main(int ac, char **av)
// {
// 	char **list;
// 	list = parsing_fewav(ac, av);
// 	int i = 0;
// 	while (list[i])
// 	{
// 		printf("%s\n", list[i]);
// 		i++;
// 	}
// 	return (0);
// }