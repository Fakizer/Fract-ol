/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:02:06 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/23 14:02:07 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pixel_put(int x, int y, int color, t_fract *fr)
{
	t_tsvet			r;
	t_tsvet			g;
	t_tsvet			b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	if (x >= 0 && y >= 0 && x < fr->width && y < fr->heigth)
	{
		if (fr->end == 0)
		{
			fr->fract_data[(y * fr->size_line) + ((fr->bpp / 8) * x)] = b;
			fr->fract_data[(y * fr->size_line) + ((fr->bpp / 8) * x) + 1] = g;
			fr->fract_data[(y * fr->size_line) + ((fr->bpp / 8) * x) + 2] = r;
		}
		else if (fr->end == 1)
		{
			fr->fract_data[(y * fr->size_line) + ((fr->bpp / 8) * x) + 1] = r;
			fr->fract_data[(y * fr->size_line) + ((fr->bpp / 8) * x) + 2] = g;
			fr->fract_data[(y * fr->size_line) + ((fr->bpp / 8) * x) + 3] = b;
		}
	}
}

void	choice_fract(char *typ_fr)
{
	char	tf;
	t_fract	*fr;

	tf = typ_fr[0];
	if ((fr = init_fract(tf)) == NULL)
		init_error("");
	if ((fr->mlx = mlx_init()) == NULL)
		init_error(ERROR_MLX);
	if ((fr->win = mlx_new_window(fr->mlx, fr->width,
		fr->heigth, PROG_NAME)) == NULL)
		init_error(ERROR_MLX);
	mlx_key_hook(fr->win, key_hook, fr);
	mlx_mouse_hook(fr->win, mouse_hook, fr);
	mlx_expose_hook(fr->win, expose_hook, fr);
	mlx_hook(fr->win, 6, 1L << 6, motion_hook, fr);
	mlx_loop(fr->mlx);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Wrong input");
		ft_putstr("\n");
		error_input();
		return (0);
	}
	input_error(av[1]);
	choice_fract(av[1]);
	return (0);
}
