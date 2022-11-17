/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:13:03 by abarriga          #+#    #+#             */
/*   Updated: 2022/09/29 11:53:20 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		num;
	long long	c;

	c = (long long)n;
	if (c < 0)
	{
		write(fd, "-", 1);
		c = c * (-1);
	}
	if (c >= 10)
	{
		ft_putnbr_fd(c / 10, fd);
		ft_putnbr_fd(c % 10, fd);
	}
	else
	{
		num = c + '0';
		write(fd, &num, 1);
	}
}
