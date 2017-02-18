/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 23:32:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/18 12:56:56 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_line(char *piece)
{
	int i;

	i = 0;
	while (piece[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}

int		check_diff(char *str, int i)
{
	int j;
	int res;

	j = 0;
	res = 0;
	while (j < i)
	{
		if (str[j] == '\n')
			res = 0;
		j++;
		res++;
	}
	return (res);
}

int		ckeck_place_piece(char *str, char *piece, int i, char play)
{
	int j;
	t_pos pos;

	j = 0;
	ft_memset(&pos, 0, sizeof(pos));
	pos.flag2 = i;
	pos.flag = check_diff(str, i);
	while (piece[j] && str[i])
	{
		if (str[i] == '.' && piece[j] == '*')
			pos.auth++;
		if (str[i] == play && piece[j] == '*')
			pos.cpt++;
		if (i == (ft_check_line(str) + pos.flag2))
			j++;
		if (piece[j] != '\n')
			j++;
		i++;
	}
	if (pos.cpt == 1 && pos.auth == 1)
		return (1);
	return (0);
}
