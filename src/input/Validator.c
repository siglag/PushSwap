/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 08:45:33 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/29 09:38:04 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_flag(char *flag)
{
	if (ft_strcasecmp(flag, "--simple") == 0)
		return (1);
	if (ft_strcasecmp(flag, "--medium") == 0)
		return (1);
	if (ft_strcasecmp(flag, "--complex") == 0)
		return (1);
	if (ft_strcasecmp(flag, "--adaptive") == 0)
		return (1);
	if (ft_strcasecmp(flag, "--bench") == 0)
		return (1);
	return (0);
}

int	validate_ordering(int argc, char **argv)
{
	int	index;
	int	sequence_started;
	int	flags_ended;

	index = 1;
	sequence_started = 0;
	flags_ended = 0;
	while (index < argc)
	{
		if (ft_strncmp(argv[index], "--", 2) == 0)
		{
			if (sequence_started)
				flags_ended = 1;
		}
		else
		{
			if (flags_ended)
				return (0);
			sequence_started = 1;
		}
		index++;
	}
	return (1);
}

int	validate_format(int argc, char **argv)
{
	int	arg;
	int	has_sequence;

	has_sequence = 0;
	arg = 1;
	while (arg < argc)
	{
		if (ft_strncmp(argv[arg], "--", 2) == 0)
		{
			if (!validate_flag(argv[arg]))
				return (0);
		}
		else
		{
			if (!ft_isdigit(argv[arg]))
				return (0);
			has_sequence = 1;
		}
		arg++;
	}
	if (!has_sequence)
		return (0);
	return (validate_ordering(argc, argv));
}
