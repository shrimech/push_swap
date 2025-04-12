/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:56:43 by shrimech          #+#    #+#             */
/*   Updated: 2025/04/12 01:59:02 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(int size, char **av)
{
	char	**split;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 1;
	while (i < size)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (exit(1), 0);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		ft_free(split);
		i++;
	}
	return (count);
}

void	ft_copy(char **split, char **args, int *k)
{
	int	j;

	j = 0;
	while (split[j])
	{
		args[*k] = ft_strdup(split[j]);
		if (!args[*k])
		{
			ft_free(args);
			ft_free(split);
			exit(1);
		}
		j++;
		(*k)++;
	}
}

char	**read_input(int ac, char **av)
{
	char	**args;
	char	**split;
	int		count;
	int		i;
	int		k;

	k = 0;
	count = 0;
	count = count_args(ac, av);
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (ft_free(args), NULL);
	i = 0;
	while (i <= count)
		args[i++] = NULL;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i++], ' ');
		if (!split)
			return (ft_free(args), NULL);
		ft_copy(split, args, &k);
		ft_free(split);
	}
	return (args[k] = NULL, args);
}
