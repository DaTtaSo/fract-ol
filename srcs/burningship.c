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

#include "../includes/fract-ol.h"

void *draw_burningship(void *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_burningship(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

void	calculate_burningship(t_fractal *fractal)
{

}