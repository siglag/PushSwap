/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 00:11:17 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/03 12:32:13 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_parsed(t_parsed *parsed)
{
	if (parsed->sequence)
		free(parsed->sequence);
	if (parsed)
		free(parsed);
	return (0);
}

int	init_parsed(t_parsed **parsed)
{
	*parsed = malloc(sizeof(t_parsed));
	if (!(*parsed))
		return (0);
	(*parsed)->sequence = NULL;
	(*parsed)->sequence_size = 0;
	(*parsed)->is_bench = false;
	(*parsed)->strategy = ADAPTIVE;
	(*parsed)->adaptive = false;
	(*parsed)->disorder = -1;
	(*parsed)->operations = (t_operations){0};
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

/*
	extract the flags out of the args
*/
int	extract_flags(t_parsed *parsed, int argc, char **args)
{
	int	arg;
	int	flags_found;
	int	has_strategy;
	int	result;

	arg = 0;
	flags_found = 0;
	has_strategy = 0;
	while (arg < argc)
	{
		if (ft_strncmp(args[arg], "--", 2) == 0)
		{
			result = handle_flag(parsed, args[arg], &has_strategy);
			if (result < 0)
				return (-1);
			if (!result)
				return (-1);
			flags_found++;
		}
		arg++;
	}
	return (flags_found);
}

t_parsed	*parser(int argc, char **argv)
{
	t_parsed	*parsed;
	int			flags;

	if (argc < 2 || !validate_format(argc, argv))
		return (NULL);
	if (!init_parsed(&parsed))
		return (NULL);
	flags = extract_flags(parsed, argc, argv);
	if (flags < 0 || flags > 2)
		return (free_parsed(parsed), NULL);
	if (parsed->strategy == ADAPTIVE)
		parsed->adaptive = true;
	if (!extract_sequence(parsed, argc, argv))
		return (free_parsed(parsed), NULL);
	if (parsed->sequence_size == 0)
		return (free_parsed(parsed), NULL);
	return (parsed);
}
