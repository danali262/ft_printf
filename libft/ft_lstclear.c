/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 12:22:45 by danali        #+#    #+#                 */
/*   Updated: 2020/10/31 12:59:24 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;

	if (*lst && lst && del)
	{
		while (*lst != NULL)
		{
			ptr = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = ptr;
		}
	}
}
