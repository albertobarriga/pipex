/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:07:32 by abarriga          #+#    #+#             */
/*   Updated: 2022/09/28 10:15:19 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_count_numbers(int n)
{
	int	a;

	a = 0;
	if (n <= 0)
		a++;
	while (n != 0)
	{
		n = n / 10;
		a++;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char		*num;
	long long	n1;
	int			a;

	a = ft_count_numbers(n);
	n1 = (long long)n;
	num = (char *)malloc(sizeof(char) * (a + 1));
	if (!num)
		return (0);
	if (n1 < 0)
	{
		num[0] = '-';
		n1 = n1 * (-1);
	}
	if (n1 == 0)
		num[0] = '0';
	num[a] = '\0';
	while (n1)
	{
		num[--a] = (n1 % 10) + '0';
		n1 = n1 / 10;
	}
	return (num);
}
