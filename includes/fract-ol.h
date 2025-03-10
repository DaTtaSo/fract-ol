/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:26:43 by nbedouan          #+#    #+#             */
/*   Updated: 2025/02/27 20:27:02 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <pthread.h>

#defin	SIZE 1000
#define
#define

typedef struct	s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*ptr_img;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iter;
}				t_fractal;

/*main.c*/
int	draw_fractal(t_fractal *fractal, char *query);

/*init.c*/
void	init_fractal(t_fractal *fractal);
void init_mlx(t_fractal *fractal);

/*mandelbrot.c*/
void *draw_mandelbrot(void *fractal_void);
void	calculate_mandelbrot(t_fractal *fractal);

/*julia.c*/
void	draw_julia(t_fractal *fractal);
void	calculate_julia(t_fractal *fractal);

/*burningship.c*/
void	calculate_burningship(t_fractal *fractal);
void *draw_burningship(void *fractal);

/*colors.c*/


/*events.c*/


/*utils.c*/
void	exit_fractal(t_fractal *fractal);

#endif
