/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_unsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 15:17:56 by danali        #+#    #+#                 */
/*   Updated: 2020/12/01 09:31:17 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_length(unsigned int n)
{
	int length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static char		*make_string_non_zero(char *res, unsigned int n, int num_len)
{
	while (n != 0)
	{
		res[num_len] = (n % 10) + '0';
		n = n / 10;
		num_len--;
	}
	return (res);
}

char			*ft_itoa_unsigned(unsigned int n)
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
