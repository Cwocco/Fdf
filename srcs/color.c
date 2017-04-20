/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 06:14:51 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/27 06:28:56 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int z)
{
	int colors;

	colors = 0;
	if (z < 0)
		colors = 0x000D1CE4;
	else if (z == 0)
		colors = 0x0000D3FD;
	else if (z > 0 && z <= 50)
		colors = 0x0096CA2D;
	else if (z >= 51 && z <= 150)
		colors = 0x00E3B740;
	else if (z >= 151 && z <= 400)
		colors = 0x00ED01FE;
	else if (z > 401)
		colors = 0x00FFFFFF;
	return (colors);
}
