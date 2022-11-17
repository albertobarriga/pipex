/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:08:22 by abarriga          #+#    #+#             */
/*   Updated: 2022/09/21 19:13:37 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

size_t	ft_strlcat(char	*dest, const char	*src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	a;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (size <= i)
		return (size + j);
	a = (i + j);
	j = 0;
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (a);
}
