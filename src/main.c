/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:04:31 by shrimech          #+#    #+#             */
/*   Updated: 2025/04/11 06:48:54 by shrimech         ###   ########.fr       */
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

void	initStack(t_list **stack, char **args)
{
	t_list	*new;
	int		i;

	i = 0;
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**args;

	if (argc < 2)
		return (1);
	ft_check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	args = read_input(argc, argv);
	initStack(stack_a, args);
	ft_free(args);
	index_stack(stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
