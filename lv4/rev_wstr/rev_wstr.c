/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <pham.hoang1591@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:14:00 by hopham            #+#    #+#             */
/*   Updated: 2019/12/17 12:32:36 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		i2;
	int		i3;

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
				i3++;
				i++;
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

int		ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**split;
	int		i;

	split = ft_split(av[1]);
	i = ft_strlen(split);
	i = i - 1;
	if (ac == 2)
	{
		while (i > 0)
		{
			ft_putstr(split[i]);
			write(1, " ", 1);
			i--;
		}
		ft_putstr(split[i]);
	}
	write(1, "\n", 1);
	return (0);
}
