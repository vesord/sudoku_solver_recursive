/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:07:08 by matrus            #+#    #+#             */
/*   Updated: 2020/02/16 19:21:37 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoker.h"

int		main(int argc, char **argv)
{
	int **pole;

	if (argc != 10)
	{
		ft_putstr(WRONG_INPUT);
		return (0);
	}
	pole = ft_fill(argv);
	if (pole == 0)
		return (0);
	if (!ft_is_valid(pole))
	{
		ft_putstr(NOT_VALID);
		return (0);
	}
	if (ft_reshsud(&pole))
		ft_print_pole(pole);
	else
		ft_putstr(NO_SOLUTION);
	ft_free(pole);
	return (0);
}

int		ft_reshsud(int ***pole)
{
	int i;
	int c_str;
	int c_col;

	if (ft_is_cell(pole, &c_str, &c_col))
	{
		i = 1;
		while (i < 10)
		{
			if (ft_check(pole, c_str, c_col, i))
			{
				(*pole)[c_str][c_col] = i;
				if (ft_reshsud(pole))
					return (1);
				else
					i++;
			}
			else
				i++;
		}
	}
	else
		return (1);
	(*pole)[c_str][c_col] = 0;
	return (0);
}

void	ft_free(int **pole)
{
	int i;

	i = 0;
	while (i < 9)
	{
		free(pole[i]);
		i++;
	}
	free(pole);
}
