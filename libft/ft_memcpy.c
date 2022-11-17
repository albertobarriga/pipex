/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:14:40 by abarriga          #+#    #+#             */
/*   Updated: 2022/09/24 13:18:07 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char			*ptr1;
	const unsigned char		*ptr2;

	if (!dst && !src)
		return (NULL);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n > 0)
	{
		*(ptr1++) = *(ptr2++);
		n--;
	}
	return (dst);
}
