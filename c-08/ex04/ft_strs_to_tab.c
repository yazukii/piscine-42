/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:32:09 by yidouiss          #+#    #+#             */
/*   Updated: 2022/06/20 16:41:35 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strs_to_tab.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return(i);
}

char				*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;
	len = 0;
	while (src[len])
		len++;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i;
	t_stock_str	*s_argv;

	i = 0;
	if (!(s_argv = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	while (i <= ac)
	{
		s_argv[i].size = ft_strlen(av[i]);
		s_argv[i].str = av[i];
		s_argv[i].copy = ft_strdup(av[i]);
		i++;
	}
	return (s_argv);
}

int main(int argc, char **argv)
{
	(void)argc;
	ft_strs_to_tab(4, argv);
	printf("%s\n", s_argv.size)
	return (0);
}