/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 03:10:49 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/27 06:30:58 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int			main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2 || argc > 2 || !init_windows(&env, 1260, 720, argv[1]))
		return (1);
	env.path = argv[1];
	mlx_loop(env.mlx);
	return (0);
}
