/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:45:17 by abarriga          #+#    #+#             */
/*   Updated: 2022/09/23 12:17:50 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

size_t	ft_strlcpy(char	*dest, const char	*src, size_t size)
{
	unsigned int	i;
	unsigned int	cont;

	cont = 0;
	while (src[cont] != '\0')
		cont++;
	if (size == 0)
		return (cont);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (cont);
}
