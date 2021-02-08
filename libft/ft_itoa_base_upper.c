/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_upper.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 15:17:56 by danali        #+#    #+#                 */
/*   Updated: 2020/12/01 09:24:44 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_length(unsigned int nbr, int base)
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

static char	*do_itoa(int i, unsigned int nbr, char *base_chars, char *res)
{
	int		digit;
	int		base;
	int		len;

	len = 0;
	base = ft_strlen(base_chars);
	if (nbr == 0)
		res[i] = '0';
	while (nbr > 0)
	{
		digit = nbr % base;
		res[i] = base_chars[digit];
		nbr = nbr / base;
		i--;
		len++;
	}
	res[len + 1] = '\0';
	return (res);
}

char		*ft_itoa_base_upper(unsigned int nbr, int base)
{
	char	*result;
	char	*base_chars;
	int		len;
	int		i;

	base_chars = malloc((base + 1) * sizeof(char));
	if (base_chars == NULL)
		return (NULL);
	base_chars = "0123456789ABCDEF";
	len = find_length(nbr, base) + 1;
	result = malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = len - 2;
	result = do_itoa(i, nbr, base_chars, result);
	return (result);
}
