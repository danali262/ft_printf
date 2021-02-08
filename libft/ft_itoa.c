/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 17:25:43 by danali        #+#    #+#                 */
/*   Updated: 2020/11/06 11:14:00 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_length(int n)
{
	int length;

	if (n > 0)
		length = 0;
	else
		length = 1;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static char		*make_string_non_zero(char *res, int n, int num_len)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(res, "-2147483648", 12);
			return (res);
		}
		res[0] = '-';
		n = n * (-1);
	}
	while (n != 0)
	{
		res[num_len] = (n % 10) + '0';
		n = n / 10;
		num_len--;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		num_len;

	num_len = number_length(n);
	res = (char *)malloc((num_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[num_len] = '\0';
	num_len--;
	if (n != 0)
		res = make_string_non_zero(res, n, num_len);
	else if (n == 0)
		res[0] = '0';
	return (res);
}
