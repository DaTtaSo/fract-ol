/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:39:05 by nbedouan          #+#    #+#             */
/*   Updated: 2025/02/28 08:43:57 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0.;
	fractal->y = 0.;
	fractal->cx = 0.;
	fractal->cy = 0.;
	fractal->color = 0xFCBE11;
	fractal->zoom = 100;
	fractal->offset_x = -3;
	fractal->offset_y = -3;
	fractal->max_iter = 100;
	fractal->julia_b = 0;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return ;
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	if (!fractal->window)
		exit_fractal(fractal);
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->image)
		exit_fractal(fractal);
	fractal->ptr_img = mlx_get_data_addr(fractal->image, \
											&fractal->bit_per_pixel, \
											&fractal->size_line, \
											&fractal->endian);
}
