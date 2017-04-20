/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 01:36:27 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/27 06:29:29 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	fdf_error(int n)
{
	if (n == 1)
	{
		ft_putendl("File does not exist.");
		exit(0);
	}
	else if (n == 2)
	{
		ft_putendl("Malloc failed.");
		exit(-1);
	}
	else if (n == 3)
	{
		ft_putendl("Open file failed.");
		exit(-1);
	}
	else if (n == 4)
	{
		ft_putendl("Map format not valid.");
		exit(-1);
	}
}
