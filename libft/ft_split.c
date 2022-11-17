/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:33:56 by abarriga          #+#    #+#             */
/*   Updated: 2022/09/30 18:40:30 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	c_words;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		return (0);
	c_words = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			c_words++;
		i++;
	}
	return (c_words);
}

static char	*ft_calloc_str(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = ((char *)ft_calloc(sizeof(char), i + 1));
	if (!word)
	{
		free(word);
		return (0);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

static char	**ft_free_mem(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
	return (0);
}

char	**ft_split(char const	*s, char c)
{
	int		num_words;
	char	**strs;
	int		i;

	num_words = ft_count_words(s, c);
	strs = (char **)ft_calloc(sizeof(char *), (num_words + 1));
	if (!strs)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			strs[i] = ft_calloc_str(s, c);
			if (strs[i] == NULL)
				return (ft_free_mem(strs, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (strs);
}
