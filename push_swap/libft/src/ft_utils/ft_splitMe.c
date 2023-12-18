/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitMe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:07:07 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 12:27:56 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_words(const char *str, char sep)
{
	int	words;
	int	index;

	words = 0;
	index = 0;
	while (str[index])
	{
		while (str[index] && str[index] == sep)
			index++;
		if (str[index])
			words++;
		while (str[index] && str[index] != sep)
			index++;
	}
	return (words + 1);
}

static int	ft_words_len(const char *str, char sep)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	return (len);
}

static char	*make_words(const char *str, char sep)
{
	int		index;
	char	*word;
	int		word_size;

	index = 0;
	word_size = ft_words_len(str, sep);
	word = malloc(sizeof(char) * (word_size + 1));
	if (!word)
		return (NULL);
	while (index < word_size)
	{
		word[index] = str[index];
		index++;
	}
	word[index] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**output;
	int		index;
	int		i;

	index = 0;
	i = 0;
	output = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!output)
		return (NULL);
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index])
		{
			output[i] = make_words(&s[index], c);
			i++;
		}
		while (s[index] && s[index] != c)
			index++;
	}
	output[i] = NULL;
	return (output);
}
