/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:38:18 by nbedouan          #+#    #+#             */
/*   Updated: 2025/02/24 13:59:25 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (ft_strncmp(query, "mandelbrot", 11) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(query, "julia", 6) == 0)
	{
		if (!fractal->julia_b)
		{
			fractal->cx = -0.54;
			fractal->cy = 0.54;
		}
		draw_julia(fractal);
	}
	else if (ft_strncmp(query, "burningship", 12) == 0)
		draw_burningship(fractal);
	else
	{
		ft_putendl_fd("Available fractals: mandelbrot, julia, burningship", 1);
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, \
							fractal->image, 0, 0);
	return (0);
}

static int	is_valid_number(char *str)
{
	int	i;
	int	dec;

	i = 0;
	dec = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.' && !dec)
			dec = 1;
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	julia_call(t_fractal *fractal, char **argv)
{
	fractal->julia_b = 1;
	if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
	{
		ft_putendl_fd("Invalid parameter: Please provide valid numbers", 1);
		exit_fractal(fractal);
	}
	fractal->cx = ft_atof(argv[2]);
	fractal->cy = ft_atof(argv[3]);
	if (fractal->cx < -2.0 || fractal->cx > 2.0)
	{
		ft_putendl_fd("cx has to be in [-2.0;2.0] range", 1);
		exit_fractal(fractal);
	}
	if (fractal->cy < -2.0 || fractal->cy > 2.0)
	{
		ft_putendl_fd("cy has to be in [-2.0;2.0] range", 1);
		exit_fractal(fractal);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if ((argc != 2 && argc != 4) || (argv[1][0] != 'j' && argc == 4))
	{
		ft_putendl_fd("try typing: ./fractol <fractal name>", 1);
		ft_putendl_fd("Available fractals: mandelbrot, julia, burningship", 1);
		ft_putendl_fd("for julia, you may give two numbers between" \
		" [-2.00;2.00]", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (1);
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_hook(fractal->window, 17, 0, exit_fractal, fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	if (argc == 4)
		julia_call(fractal, argv);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	exit_fractal(fractal);
	return (0);
}
