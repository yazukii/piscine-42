/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:32:09 by yidouiss          #+#    #+#             */
/*   Updated: 2022/06/20 16:41:35 by yidouiss         ###    ########.fr	  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_rev(char *str)
{
	int		length;
	int		j;
	int		i;
	char	temp;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	i = 0;
	j = length - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	//printf("num inverted: %s\n", num);
	return (str);
}

char *ft_2drev(char **num)
{
	int i;
	int j;
	int size;
	char *rev;

	i = 0;
	j = 1;
	while (num[j])
		j++;
	size = j;
	j--;
	while (i < (size / 2))
	{
		rev = num[j];
		num[j] = num[i];
		num[i] = rev;
		j--;
		i++;
	}
	return (*num);
}

char *ft_itoc(char *num)
{
	int i;
	int x;
	int type;
	int dat;
	char *cent[4];
	char *unit[9];
	char *tens[8];
	char *sptens[10];
	char *fin[10000];
	char *tho;

	cent[0] = "hundred";
	cent[1] = "thousand";
	cent[2] = "million";
	cent[3] = "billion";

	unit[0] = "one";
	unit[1] = "two";
	unit[2] = "three";
	unit[3] = "four";
	unit[4] = "five";
	unit[5] = "six";
	unit[6] = "seven";
	unit[7] = "eight";
	unit[8] = "nine";

	tens[0] = "twenty";
	tens[1] = "thirty";
	tens[2] = "forty";
	tens[3] = "fifty";
	tens[4] = "sixty";
	tens[5] = "seventy";
	tens[6] = "eighty";
	tens[7] = "ninety";

	sptens[0] = "ten";
	sptens[1] = "eleven";
	sptens[2] = "twelve";
	sptens[3] = "thirteen";
	sptens[4] = "fourteen";
	sptens[5] = "fifteen";
	sptens[6] = "sixteen";
	sptens[7] = "seventeen";
	sptens[8] = "eighteen";
	sptens[9] = "nineteen";
	dat = 0;
	i = 0;
	x = 0;
	num = ft_rev(num);
	while (num[i])
	{
		type = i % 3;
		//printf("%d", type);
		//Check si le chiffre est une unité, dizaine ou centaine

		//Check pour centaines
		if (type == 2)
		{
				tho = cent[((i + 1) / 3)];
				if (num[i] != '0')
				{
					fin[x] = cent[0];
					//printf("%s ", fin[x]);
					x++;
				}
				fin[x] = "-";
				//printf("%s ", fin[x]);
				x++;
				fin[x] = unit[num[i] - 49];
				//printf("%s ", fin[x]);
				x++;
		}

		//Check pour dizaines
		if (type == 1)
		{
			if(num[i] != '0')
			{
				if (num[i] == '1')
				{
					dat = num[i - 1] - 47;
					fin[x] = sptens[dat - 1];
					//printf("%s ", fin[x]);
					x++;
				}
				else if (num[i] == '3')
				{
					fin[x] = tens[num[i] - 50];
					//printf("now lol");
					x++;
				}
			}
		}

		//Check pour unités
		if (type == 0)
		{
			if (num[i] != '0')
			{
				if (num[i + 1] != '1')
				{
					if (num[i + 2] >= '0')
					{
						fin[x] = tho;
						//printf("%s ", fin[x]);
						x++;
					}
					fin[x] = unit[num[i] - 49];
					//printf("%s ", fin[x]);
					x++;
				}
			}
		}
		i++;
	}
	//printf("\n");
	x = 0;
	ft_2drev(fin);
	while (fin[x])
	{
		printf("%s ", fin[x]);
		x++;
	}
	printf("\n");
	return (num);
}

int main(int ac, char **av)
{
	(void)ac;
	ft_itoc(av[1]);
	return (0);
}