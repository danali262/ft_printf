/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 21:18:54 by danali        #+#    #+#                 */
/*   Updated: 2020/10/30 12:16:20 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*res;
	int		i;

	str = (char *)s;
	res = NULL;
	i = 0;
	while (*str)
	{
		if (*str == c)
		{
			res = str;
			i++;
		}
		str++;
	}
	if (*str == c)
		return (str);
	else
		return (res);
}
