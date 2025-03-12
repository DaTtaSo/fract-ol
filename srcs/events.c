/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:39:25 by nbedouan          #+#    #+#             */
/*   Updated: 2025/02/28 08:44:46 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_ratio;

	zoom_ratio = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) \
				- (x / (fractal->zoom * zoom_ratio));
		fractal->offset_y = (y / fractal->zoom * fractal->offset_y) \
				- (y / (fractal->zoom * zoom_ratio));
		fractal->zoom *= zoom_ratio;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) \
							- (x / (fractal->zoom * zoom_ratio));
		fractal->offset_y = (y / fractal->zoom * fractal->offset_y) \
							- (y / (fractal->zoom * zoom_ratio));
		fractal->zoom /= zoom_ratio;
	}
	else
		return ;
}

void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == RIGHT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == LEFT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		init_fractal(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cy);
	else if (key_code == M || key_code == P)
		change_max_iter(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}
