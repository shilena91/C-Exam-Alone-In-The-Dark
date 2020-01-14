/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <pham.hoang1591@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:13:32 by hopham            #+#    #+#             */
/*   Updated: 2019/11/12 10:38:46 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	repeat(char c)
{
	int	repeat;

	repeat = 1;
	if (c >= 'a' && c <= 'z')
		repeat = c - 'a' + 1;
	else if (c >= 'A' && c <= 'Z')
		repeat = c - 'A' + 1;
	return (repeat);
}

int	main(int argc, char **argv)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			count = repeat(argv[1][i]);
			while (count > 0)
			{
				write(1, &argv[1][i], 1);
				count--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
