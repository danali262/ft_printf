/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dgiannop <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:15:43 by dgiannop      #+#    #+#                 */
/*   Updated: 2020/10/30 11:18:03 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *s;
	unsigned char *d;

	s = NULL;
	d = NULL;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n > 0)
	{
		if (*s == (unsigned char)c)
		{
			*d = *s;
			d++;
			return (d);
		}
		else
		{
			*d = *s;
			d++;
			s++;
			n--;
		}
	}
	return (NULL);
}
