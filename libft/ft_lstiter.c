/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 13:03:02 by danali        #+#    #+#                 */
/*   Updated: 2020/10/31 14:11:08 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *ptr;

	if (lst && f)
	{
		ptr = lst;
		while (ptr != NULL)
		{
			(*f)(ptr->content);
			ptr = ptr->next;
		}
	}
}
