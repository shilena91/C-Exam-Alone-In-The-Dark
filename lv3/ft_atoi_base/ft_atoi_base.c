/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:40:57 by hopham            #+#    #+#             */
/*   Updated: 2019/11/19 17:09:05 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_char_with_base(char c, int base)
{
	char	str1[17] = "0123456789abcdef";
	char	str2[17] = "0123456789ABCDEF";

	while (base--)
	{
		if (str1[base] == c || str2[base] == c)
			return (1);
	}
	return (0);
}

int	value_of_c(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		i++;
		n = -1;
	}
	while (check_char_with_base(str[i], str_base))
	{
		result = result * str_base + value_of_c(str[i]);
		i++;
	}
	return (result * n);
}

int	main(void)
{
	printf("%i\n", ft_atoi_base("100", 10));
}
