/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:46:51 by abarriga          #+#    #+#             */
/*   Updated: 2022/09/26 13:11:39 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (start >= ft_strlen(s))
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (0);
		return (substr);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	substr = ft_calloc(sizeof(char), len + 1);
	if (!substr)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
