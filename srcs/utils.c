/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:40:22 by nbedouan          #+#    #+#             */
/*   Updated: 2025/02/28 08:45:26 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_max_iter(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iter > 100)
			fractal->max_iter -= 50;
	}
	else if (key_code == P)
	{
		if (fractal->max_iter < 4200)
			fractal->max_iter += 50;
	}
}

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->ptr_img;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	exit_fractal(t_fractal *fractal)
{
	if (fractal->image)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (fractal->mlx)
	{
		mlx_loop_end(fractal->mlx);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	free(fractal);
	exit(0);
}

double	ft_atof(char *str)
{
	int		i;
	int		neg;
	double	nb;
	double	div;

	i = 0;
	nb = 0.0;
	div = 0.1;
	neg = 1;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
		{
			nb += (str[i] - '0') * div;
			div *= 0.1;
			i++;
		}
	}
	return (nb * neg);
}
