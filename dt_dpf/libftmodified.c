/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmodified.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:31:04 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/13 18:18:22 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_intret(int fd, int n)
{
	int		ret;
	char	*str;

	ret = 0;
	str = ft_itoa2(n);
	ret += ft_intputstr(fd, str);
	free (str);
	return (ret);
}

int	ft_putnbr_uret(int fd, long int n)
{
	int		ret;
	char	*str;

	ret = 0;
	str = ft_itoa2(n);
	ret += ft_intputstr(fd, str);
	free (str);
	return (ret);
}

int	ft_putchar_ret(int fd, char c)
{
	int	ret;

	ret = 0;
	ret += write(fd, &c, 1);
	return (ret);
}
