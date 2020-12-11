/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:13:47 by matrus            #+#    #+#             */
/*   Updated: 2020/02/16 20:14:04 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKER_H
# define FT_SUDOKER_H

# define NO_SOLUTION "Error\n"
# define WRONG_INPUT "Error\n"
# define NOT_VALID "Error\n"

# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_is_cell(int ***pole, int *str, int *col);
int		ft_reshsud(int ***pole);
int		ft_check(int ***pole, int str, int col, int val);
int		ft_val_in_sqr(int ***pole, int str, int col, int val);
int		ft_val_in_str(int ***pole, int str, int val);
int		ft_val_in_col(int ***pole, int col, int val);
int		**ft_fill(char **av);
void	ft_free(int **pole);
void	ft_print_pole(int **pole);
void	ft_putnbr(int nb);
int		ft_is_col_valid(int **pole);
int		ft_is_str_valid(int **pole);
int		ft_is_valid(int **pole);
int		ft_is_box_valid(int **pole, int str, int col);
int		ft_is_s_box_valid(int *s_box);
int		ft_add_dig(char c);
#endif
