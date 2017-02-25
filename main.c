/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:18:56 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/25 18:43:51 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		main(int argc, char **argv)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	if (argc == 2)
	{
		ref.fd = open(argv[1], O_RDONLY);
		ref.play = ft_record_playnbr(ref.fd);
		while (ref.i < 1)
		{
			ref.tab = ft_record_size_map(ref.fd);
			ref.x = ref.tab[0];
			ref.y = ref.tab[1];
			ref.map = ft_record_map(ref.x, ref.fd);
			free(ref.tab);
			ref.tab2 = ft_record_size_piece(ref.fd);
			ref.xp = ref.tab2[0];
			ref.piece = ft_record_piece(ref.xp, ref.fd);
			free(ref.tab);
			if (ref.flag == 0)
			{
				ref.start = ft_start_place(ref.map, ref.play);
				ref.e_co = ft_enemy_start_place(ref.map, ref.play);
				ref.flag = 1;
			}
			if (ft_check_battle(&ref) == 0)
				break ;
			free (ref.map);
			free (ref.piece);
			ref.i++;

		}
	}
	return (0);
}
