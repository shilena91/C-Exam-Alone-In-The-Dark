/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:12:36 by hopham            #+#    #+#             */
/*   Updated: 2020/01/07 13:37:09 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cur;
	t_list	*tmp;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		cur = *begin_list;
		*begin_list = (*begin_list)->next;
		free(cur);
	}
	cur = *begin_list;
	while (cur && cur->next)
	{
		if (cmp(cur->next->data, data_ref) == 0)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			free(tmp);
		}
		cur = cur->next;
	}
}
