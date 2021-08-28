/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 10:50:35 by cvenkman          #+#    #+#             */
/*   Updated: 2021/05/03 15:56:05 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*th;

	if (*lst && lst && del)
	{
		while (*lst && lst)
		{
			th = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = th;
		}
	}
}
