/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:12:36 by hopham            #+#    #+#             */
/*   Updated: 2020/01/21 11:47:37 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*remove;
	t_list	*curr;

	curr = *begin_list;
	while (curr && curr->next)
	{
		if ((*cmp)(curr->next->data, data_ref) == 0)
		{
			remove = curr->next;
			curr->next = curr->next->next;
			free(remove);
		}
		curr = curr->next;
	}
	curr = *begin_list;
	if (curr && (*cmp)(curr->data, data_ref) == 0)
	{
		*begin_list = curr->next;
		free(curr);
	}
}
