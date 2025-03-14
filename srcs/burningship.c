/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:39:53 by nbedouan          #+#    #+#             */
/*   Updated: 2025/02/28 08:45:18 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_burningship(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < SIZE)
	{
		fractal->x = 0;
		while (fractal->x < SIZE)
		{
			calculate_burningship(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
}

void	calculate_burningship(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->name = "burningship";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iter)
	{
		x_temp = fractal->zx * fractal->zx \
						- (fractal->zy * fractal->zy) + fractal->cx;
		fractal->zy = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = fabs(x_temp);
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
	}
	if (i == fractal->max_iter)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, \
										(fractal->color * i));
}
