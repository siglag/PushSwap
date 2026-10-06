/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 02:03:13 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/03 12:33:34 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(int *sequence, int index)
{
	int	previous;

	previous = 0;
	while (previous < index)
	{
		if (sequence[previous] == sequence[index])
			return (1);
		previous++;
	}
	return (0);
}

int	extract_token(int *sequence, char **numbers, int *index)
{
	int	token;

	token = 0;
	while (numbers[token])
	{
		if (!ft_atoi(numbers[token], &sequence[*index]))
			return (-1);
		if (is_duplicate(sequence, *index))
			return (-1);
		(*index)++;
		token++;
	}
	return (token);
}

int	extract_numbers(int *sequence, int argc, char **argv)
{
	int		arg;
	int		index;
	char	**numbers;
	int		token;

	arg = 1;
	index = 0;
	while (arg < argc)
	{
		if (ft_strncmp(argv[arg], "--", 2) != 0)
		{
			numbers = ft_split(argv[arg], ' ');
			if (!numbers)
				return (0);
			token = extract_token(sequence, numbers, &index);
			if (token < 0)
			{
				free_words(numbers);
				return (0);
			}
			free_words(numbers);
		}
		arg++;
	}
	return (1);
}

int	extract_strategy(char *strategy)
{
	if (ft_strcasecmp(strategy, "--adaptive") == 0)
		return (ADAPTIVE);
	if (ft_strcasecmp(strategy, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcasecmp(strategy, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcasecmp(strategy, "--complex") == 0)
		return (COMPLEX);
	return (0);
}

int	handle_flag(t_parsed *parsed, char *arg, int *has_strategy)
{
	int	strategy;

	if (ft_strcasecmp(arg, "--bench") == 0)
	{
		parsed->is_bench = true;
		return (1);
	}
	strategy = extract_strategy(arg);
	if (!strategy)
		return (0);
	if (*has_strategy)
		return (-1);
	parsed->strategy = strategy;
	*has_strategy = 1;
	return (1);
}
