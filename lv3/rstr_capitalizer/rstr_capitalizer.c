/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:54:29 by hopham            #+#    #+#             */
/*   Updated: 2019/11/19 11:10:47 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		write(1, "\n", 1);
	j = ft_strlen(av[i]) - 1;
	while (++i < ac)
	{
		if (av[i][j] >= 'a' && av[i][j] <= 'z')
			av[i][j] -= 32;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= 'A' && av[i][j] <= 'Z' && av[i][j + 1] > 32)
				av[i][j] += 32;
			if (av[i][j] >= 'a' && av[i][j] <= 'z' &&
				(av[i][j + 1] == ' ' || av[i][j + 1] == '\t'))
				av[i][j] -= 32;
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
