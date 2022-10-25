/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-0-ft_countdown.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:46:59 by yidouiss          #+#    #+#             */
/*   Updated: 2022/06/30 12:54:59 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (!(argv[1][i] <= 'z' && argv[1][i] >= 'a'))
			write(1, &argv[1][i], 1);
		else
		{
			while (j < argv[1][i] - 96)
			{
				write(1, &argv[1][i], 1);
				j++;
			}
		}
		j = 0;
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
