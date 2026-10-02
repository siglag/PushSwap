/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 02:03:13 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/02 22:32:56 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	extract_token(int *sequence, char **numbers, int *index)
{
	int	token;

	token = 0;
	while (numbers[token])
	{
		if (!ft_atoi(numbers[token], &sequence[*index]))
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
				free_words(numbers, 0);
				return (0);
			}
			free_words(numbers, token);
		}
		arg++;
	}
	return (1);
}

int	extract_sequence(t_parsed *parsed, int argc, char **argv)
{
	int	arg;
	int	length;

	arg = 1;
	length = 0;
	while (arg < argc)
	{
		if (ft_isdigit(argv[arg]))
			length += count_numbers(argv[arg]);
		arg++;
	}
	parsed->sequence_size = length;
	parsed->sequence = malloc(sizeof(int) * length);
	if (!parsed->sequence)
		return (0);
	if (!extract_numbers(parsed->sequence, argc, argv))
		return (0);
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
	if (ft_strcasecmp(strategy, "--bench") == 0)
		return (ADAPTIVE);
	return (0);
}

/*
	extract the flags out of the args
*/
int	extract_flags(t_parsed *parsed, int argc, char **args)
{
	int	arg;
	int	flags_found;
	int	has_startegy;

	arg = 0;
	flags_found = 0;
	has_startegy = 0;
	while (arg < argc)
	{
		if (ft_strncmp(args[arg], "--", 2) == 0)
		{
			parsed->strategy = extract_strategy(args[arg]);
			if (parsed->strategy)
			{
				if (has_startegy)
					return (-1);
				has_startegy = 1;
			}
			else
				parsed->is_bench = true;
			flags_found++;
		}
		arg++;
	}
	return (flags_found);
}
