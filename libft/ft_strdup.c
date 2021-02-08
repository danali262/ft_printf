/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 10:28:09 by danali        #+#    #+#                 */
/*   Updated: 2020/11/06 11:09:26 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;
	char	*str;

	str = (char *)s;
	len = ft_strlen(str) + 1;
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, str, len);
	return (ptr);
}
