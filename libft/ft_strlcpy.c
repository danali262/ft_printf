/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 14:43:26 by danali        #+#    #+#                 */
/*   Updated: 2020/10/30 18:13:19 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	res;

	res = 0;
	if (size > 0)
	{
		while (src[res] && res < (size - 1))
		{
			dst[res] = src[res];
			res++;
		}
		dst[res] = '\0';
	}
	while (src[res])
		res++;
	return (res);
}
