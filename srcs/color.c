/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 06:14:51 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/23 06:14:52 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		get_color(int z)
{
	int colors;

	colors = 0;
	if (z < 0)
		colors = 0x000D1CE4;
	else if (z == 0)
		colors = 0x00FFFFFF;
	else if (z > 0 && z <= 30)
		colors = 0x0030C253;
	else if (z >= 31 && z <= 50)
		colors = 0x00E3B740;
//	else if (z >= 40 && z <= 50)
//		colors = 0x00875910;
//	else if (z > 50)
//		colors = 0x00582900;
//	else 
//		colors = 0x00FF0000;
	return (colors);
}