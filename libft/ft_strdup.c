/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:25:31 by abarriga          #+#    #+#             */
/*   Updated: 2022/09/26 11:43:49 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include"libft.h"
#include<stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		i;
	size_t	size;
	size_t	count;

	i = 0;
	size = ft_strlen (s1);
	count = sizeof(char);
	a = (char *)malloc(count * size + 1);
	if (!a)
		return (0);
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
