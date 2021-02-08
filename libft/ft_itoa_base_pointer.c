/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_pointer.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 15:17:56 by danali        #+#    #+#                 */
/*   Updated: 2020/12/01 09:24:36 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_length(unsigned long nbr, int base)
{
	int len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

static int	add_header(int i, char *string)
{
	string[i] = '0';
	i++;
	string[i] = 'x';
	i++;
	return (i);
}

static char	*do_itoa(int i, unsigned long nbr, char *base_chars, char *res)
{
	int		digit;
	int		base;

	base = ft_strlen(base_chars);
	if (nbr == 0)
		res[i] = '0';
	while (nbr > 0)
	{
		digit = nbr % base;
		res[i] = base_chars[digit];
		nbr = nbr / base;
		i--;
	}
	return (res);
}

char		*ft_itoa_base_pointer(unsigned long nbr, int base)
{
	char	*result;
	char	*base_chars;
	int		len;
	int		i;

	base_chars = malloc((base + 1) * sizeof(char));
	if (base_chars == NULL)
		return (NULL);
	base_chars = "0123456789abcdef";
	len = find_length(nbr, base) + 3;
	result = malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	i = add_header(i, result);
	result[len - 1] = '\0';
	i = len - 2;
	result = do_itoa(i, nbr, base_chars, result);
	return (result);
}
