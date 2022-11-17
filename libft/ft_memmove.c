/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:04:48 by abarriga          #+#    #+#             */
/*   Updated: 2022/09/24 12:13:07 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t		i;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			((char *) dst)[i - 1] = ((char *) src)[i - 1];
			i--;
		}
	}
	else if (dst < src)
	{
		while (i < len)
		{
			((char *) dst)[i] = ((char *) src)[i];
			i++;
		}
	}
	return (((void *) dst));
}
