/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 03:10:49 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/22 03:11:23 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int main(int argc, char **argv)
{
	t_env env;
	t_pos size;		

	argc++;
	size.x = 1920;
	size.y = 1080;
	//env.path = argv[1];
	init_windows(&env, size, argv[0]);
	mlx_loop(env.mlx);
	return (0);
}
