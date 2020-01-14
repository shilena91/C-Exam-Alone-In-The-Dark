/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgdc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:14:23 by hopham            #+#    #+#             */
/*   Updated: 2019/11/19 11:25:46 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int denomitor(int a, int b)
{
	int	i;

	if (a <= b)
		i = a;
	i = b;
	while (i > 0)
	{
		if (a % i == 0 && b % i == 0)
			return (i);
		i--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%i\n", denomitor(atoi(av[1]), atoi(av[2])));
	}
	else
		printf("\n");
	
	return (0);
}
