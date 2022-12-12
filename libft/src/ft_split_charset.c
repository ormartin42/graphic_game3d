/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 08:16:54 by ormartin          #+#    #+#             */
/*   Updated: 2020/09/29 11:49:16 by ormartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_is_sep(char c, char *charset)
{
	int i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!ft_is_sep(str[0], charset))
		count++;
	while (str[++i])
	{
		if (!ft_is_sep(str[i], charset) && ft_is_sep(str[i - 1], charset))
			count++;
	}
	return (count);
}

char	*ft_word_dup(char *str, int first_letter)
{
	int		i;
	char	*word;

	i = -1;
	if (!str)
		return (NULL);
	if (!(word = malloc((first_letter + 1) * sizeof(char))))
		return (NULL);
	while (++i < first_letter)
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

char	**ft_split_charset(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		first_letter;
	int		word;

	if (!(tab = malloc((ft_count_words(str, charset) + 1) * sizeof(char *))))
		return (NULL);
	i = -1;
	word = 0;
	while (str[++i])
	{
		first_letter = 0;
		while (!ft_is_sep(str[i + first_letter], charset))
			first_letter++;
		if (first_letter)
		{
			tab[word] = ft_word_dup(&str[i], first_letter);
			word++;
			i += first_letter;
		}
	}
	tab[word] = NULL;
	return (tab);
}
