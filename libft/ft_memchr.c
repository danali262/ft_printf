/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 18:53:36 by danali        #+#    #+#                 */
/*   Updated: 2020/10/30 08:32:37 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *src;

	src = NULL;
	src = (unsigned char *)s;
	while (n > 0)
	{
		if (*src == (unsigned char)c)
			return (src);
		src++;
		n--;
	}
	return (NULL);
}
