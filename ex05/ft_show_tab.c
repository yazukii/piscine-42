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

#include "ft_show_tab.h"
#include <stdio.h>
#include <stdlib.h>



void ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (i < 3)
	{
		printf("size: %d\n", par[i].size);
		printf("str: %s\n", par[i].str);
		printf("copy: %s\n", par[i].copy);
		i++;
	}
}