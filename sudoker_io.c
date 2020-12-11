/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoker_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:51:54 by matrus            #+#    #+#             */
/*   Updated: 2020/02/16 20:13:19 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoker.h"

void	ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i = i + 1;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_pole(int **pole)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(pole[i][j] + '0');
			if (j < 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		**ft_fill(char **av)
{
	int i;
	int j;
	int **pole;

	pole = (int**)malloc(sizeof(int*) * 9);
	i = 0;
	while (++i < 10)
	{
		j = 0;
		pole[i - 1] = (int*)malloc(sizeof(int) * 9);
		while (j < 9 && ((av[i][j] >= 49 && av[i][j] <= 57) || av[i][j] == 46))
		{
			pole[i - 1][j] = ft_add_dig(av[i][j]);
			j++;
		}
		if ((j < 9) || (j == 9 && av[i][j] != '\0'))
		{
			ft_putstr(WRONG_INPUT);
			return (0);
		}
	}
	return (pole);
}

int		ft_add_dig(char c)
{
	if (c == 46)
		return (0);
	else
		return (c - '0');
}
