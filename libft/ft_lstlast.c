/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:35:52 by danali        #+#    #+#                 */
/*   Updated: 2020/10/31 11:49:53 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *ptr;

	if (lst)
	{
		ptr = lst;
		while (ptr != NULL)
		{
			if (ptr->next == NULL)
				return (ptr);
			ptr = ptr->next;
		}
	}
	return (NULL);
}
