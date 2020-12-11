/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoker_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:41:28 by matrus            #+#    #+#             */
/*   Updated: 2020/02/16 19:30:57 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoker.h"

int	ft_is_valid(int **pole)
{
	int i_str;
	int i_col;

	if (!ft_is_str_valid(pole))
		return (0);
	if (!ft_is_col_valid(pole))
		return (0);
	i_str = 0;
	while (i_str < 3)
	{
		i_col = 0;
		while (i_col < 3)
		{
			if (!ft_is_box_valid(pole, i_str * 3, i_col * 3))
				return (0);
			i_col++;
		}
		i_str++;
	}
	return (1);
}

int	ft_is_box_valid(int **pole, int str, int col)
{
	int i_str;
	int i_col;
	int *s_box;
	int i;

	s_box = (int *)malloc(sizeof(s_box) * 9);
	i_str = str;
	i = 0;
	while (i_str < str + 3)
	{
		i_col = col;
		while (i_col < col + 3)
		{
			s_box[i] = pole[i_str][i_col];
			i++;
			i_col++;
		}
		i_str++;
	}
	if (ft_is_s_box_valid(s_box))
		return (1);
	else
		return (0);
}

int	ft_is_s_box_valid(int *s_box)
{
	int i;
	int j;
	int val;

	i = 0;
	while (i < 9)
	{
		val = s_box[i];
		j = i + 1;
		while (j < 9)
		{
			if (val == s_box[j] && val != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_str_valid(int **pole)
{
	int i_str;
	int i_col;
	int i;
	int val;

	i_str = 0;
	while (i_str < 9)
	{
		i_col = 0;
		while (i_col < 9)
		{
			val = pole[i_str][i_col];
			i = i_col + 1;
			while (i < 9)
			{
				if (val == pole[i_str][i] && val != 0)
					return (0);
				i++;
			}
			i_col++;
		}
		i_str++;
	}
	return (1);
}

int	ft_is_col_valid(int **pole)
{
	int i_str;
	int i_col;
	int i;
	int val;

	i_col = 0;
	while (i_col < 9)
	{
		i_str = 0;
		while (i_str < 9)
		{
			val = pole[i_str][i_col];
			i = i_str + 1;
			while (i < 9)
			{
				if (val == pole[i][i_col] && val != 0)
					return (0);
				i++;
			}
			i_str++;
		}
		i_col++;
	}
	return (1);
}
