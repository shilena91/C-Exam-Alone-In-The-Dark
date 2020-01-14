/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:00:14 by hopham            #+#    #+#             */
/*   Updated: 2020/01/07 13:08:43 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str)
{
	int		i;
	int		i2;
	int		i3;
	char	**tab;

	i = 0;
	i2 = 0;
	tab = (char**)malloc(sizeof(**tab) * 1000);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] > 32)
		{
			i3 = 0;
			tab[i2] = (char*)malloc(sizeof(char) * 1000);
			while (str[i] > 32)
			{
				tab[i2][i3] = str[i];
				i++;
				i3++;
			}
			tab[i2][i3] = '\0';
			i2++;
		}
		else
			i++;
	}
	tab[i2] = 0;
	return (tab);
}
