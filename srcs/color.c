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
	int red;

	red = z % 255 + 40;
	colors = 0;
	if (z < 0)
		colors = 0x000D1CE4;
	else if (z == 0)
		colors = 0x00FFFFFF;
	else if (z > 0 && z <= 5)
		colors = 0x00300053 + (red << 16);
	else if (z >= 2 && z <= 5)
		colors = 0x00E3B740 + (red << 16);
	else if (z >= 51 && z <= 70)
		colors = 0x00582900 + (red << 16);
	else if (z > 70)
		colors = 0x00FFFFFF;
	return (colors);
}