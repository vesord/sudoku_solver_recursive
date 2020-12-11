/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoker_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:04:00 by matrus            #+#    #+#             */
/*   Updated: 2020/02/16 19:24:24 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoker.h"

int	ft_is_cell(int ***pole, int *str, int *col)
{
	*str = 0;
	*col = 0;
	while (*str < 9)
	{
		*col = 0;
		while (*col < 9)
		{
			if ((*pole)[*str][*col] == 0)
				return (1);
			(*col)++;
		}
		(*str)++;
	}
	return (0);
}

int	ft_check(int ***pole, int str, int col, int val)
{
	if (ft_val_in_str(pole, str, val))
		return (0);
	if (ft_val_in_col(pole, col, val))
		return (0);
	if (ft_val_in_sqr(pole, str, col, val))
		return (0);
	else
		return (1);
}

int	ft_val_in_sqr(int ***pole, int str, int col, int val)
{
	int i;
	int j;
	int s_s;
	int s_c;

	s_s = 0;
	s_c = 0;
	i = (str / 3) * 3;
	j = (col / 3) * 3;
	while (s_s < 3)
	{
		s_c = 0;
		while (s_c < 3)
		{
			if ((*pole)[i + s_s][j + s_c] == val)
				return (1);
			s_c++;
		}
		s_s++;
	}
	return (0);
}

int	ft_val_in_str(int ***pole, int str, int val)
{
	int i;

	i = 0;
	while (i != 9)
	{
		if ((*pole)[str][i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	ft_val_in_col(int ***pole, int col, int val)
{
	int i;

	i = 0;
	while (i != 9)
	{
		if ((*pole)[i][col] == val)
			return (1);
		i++;
	}
	return (0);
}
