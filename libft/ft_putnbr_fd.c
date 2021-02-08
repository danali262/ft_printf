/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 19:32:03 by danali        #+#    #+#                 */
/*   Updated: 2020/10/30 10:14:22 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * (-1), fd);
	}
	else if (n >= 0 && n != -2147483648)
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd((n % 10 + '0'), fd);
		}
	}
}
