/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:51:32 by danali        #+#    #+#                 */
/*   Updated: 2020/11/06 11:16:20 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	max_copy;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	max_copy = size - dst_len - 1;
	while (*dst)
		dst++;
	if (dst_len < size - 1 && size > 0)
	{
		while (*src && max_copy > 0)
		{
			max_copy--;
			*dst = *src;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	if (dst_len >= size)
		dst_len = size;
	return (dst_len + src_len);
}
