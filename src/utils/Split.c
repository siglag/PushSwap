/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:17:41 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/29 17:26:43 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char c)
{
	int	index;
	int	count;
	int	is_word;

	index = 0;
	count = 0;
	is_word = 0;
	while (str[index])
	{
		if (str[index] == c)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			count++;
		}
		index++;
	}
	return (count);
}

static int	get_word_length(const char *str, int start, char c)
{
	int	length;

	length = 0;
	while (str[start + length] && str[start + length] != c)
		length++;
	return (length);
}

void	free_words(char **words)
{
	int	index;

	if (!words)
		return ;
	index = 0;
	while (words[index])
	{
		free(words[index]);
		index++;
	}
	free(words);
}

static int	fill_result(char **result, const char *str, char c)
{
	int	index;
	int	word;
	int	length;

	index = 0;
	word = 0;
	while (str[index])
	{
		while (str[index] && str[index] == c)
			index++;
		if (!str[index])
			break ;
		length = get_word_length(str, index, c);
		result[word] = ft_substr(str, index, length);
		if (!result[word])
		{
			while (word > 0)
				free(result[--word]);
			return (free(result), 0);
		}
		word++;
		index += length;
	}
	result[word] = NULL;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		words;

	if (!str)
		return (NULL);
	words = count_words(str, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!fill_result(result, str, c))
		return (NULL);
	return (result);
}
