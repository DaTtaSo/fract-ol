/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
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

# define SIZE 1000
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
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
int		draw_fractal(t_fractal *fractal, char *query);

/*init.c*/
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);

/*mandelbrot.c*/
void	*draw_mandelbrot(void *fractal_void);
void	calculate_mandelbrot(t_fractal *fractal);

/*julia.c*/
void	draw_julia(t_fractal *fractal);
void	calculate_julia(t_fractal *fractal);

/*burningship.c*/
void	calculate_burningship(t_fractal *fractal);
void	draw_burningship(t_fractal *fractal);

/*events.c*/
void	zoom(t_fractal *fractal, int x, int y, int zoom);
void	set_random_julia(double *cx, double *cy);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

/*utils.c*/
int		exit_fractal(t_fractal *fractal);
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
double	generate_random_c(void);
void	change_max_iter(t_fractal *fractal, int key_code);

#endif