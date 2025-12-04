/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 03:57:05 by felix             #+#    #+#             */
/*   Updated: 2025/12/04 03:57:27 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int count_numbers(int ac, char **av)
{
	int	i;
	int	count;
	char **tmp;

	i = 1;
	count = 1;
	while (av[i])
	{
		count = count_words(av[i], ' ');
		i++;
	}
	return (i);
}

int	*parsing(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**list;
	char	**tmp;

	i = 1;
	j = 0;
	k = 0;
	list = malloc(sizeof(char *) * count_numbers(ac, av) + 1);
	while(av[i])
	{
		tmp = ft_split(av[i], ' ');
		while (tmp[j])
		{
			list[k] = tmp[j];
			k++;
			j++;
		}
		j = 0;
		i++;
		free(tmp);
	}
	list[k] = NULL;
	return (from_char_to_int(list));
}

int *from_char_to_int(char **list)
{
	int	i;
	int	*list_num;

	i = 0;
	if (!is_there_char(list))
		print_error("Only number require as parameter");
	list_num = malloc(sizeof(int) * len_tab(list) + 1);
	while (list[i])
	{
		list_num[i] = ft_atoi(((const char *)list)[i]);
		i++;
	}
	return (list_num);
}

int check_duplicate(int *list_num)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (list_num[i])
	{
		while (list_num[j] && j < i)
		{
			if (list_num[i] == list_num[j])
				return (0);
			else
				j++;
		}
		j = 0;
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