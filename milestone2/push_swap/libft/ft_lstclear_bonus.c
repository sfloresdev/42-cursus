/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:07:53 by seflores          #+#    #+#             */
/*   Updated: 2025/10/19 19:07:16 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_next;

	while (*lst != NULL)
	{
		tmp_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp_next;
	}
	*lst = NULL;
}
