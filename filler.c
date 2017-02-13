/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:26:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/13 15:13:36 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		ft_start_place(char *map, char play)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (map[art.i] != play)
		art.i++;
	printf("depart = %d\n", art.i);
	return (art.i);
}

int		ft_enemy_start_place(char *map, char play2)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (map[art.i] != play2)
		art.i++;
	printf("depart enemy= %d\n", art.i);
	return (art.i);
}

char	ft_enemy_letter(int play)
{
	int play2;

	if (play == 'O')
		play2 = 'X';
	else
		play2 = 'O';
	return (play2);
}

int		*ft_check_battle(char *map, char *piece, char play, int x_map)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	if (piece == NULL)
		return (0);
	art.pos = ft_start_place(map, play);
	art.play2 = ft_enemy_letter(play);
	art.pos_ad = ft_enemy_start_place(map, art.play2);
	ft_middle_strategy(map, piece, play, )

	return (0);
}
