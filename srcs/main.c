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

	if (argc < 3 || !init_windows(&env, ft_atoi(argv[1]), ft_atoi(argv[2]), argv[0]))
		return (1);
	env.path = argv[1];
	mlx_loop(env.mlx);
	return (0);
}
