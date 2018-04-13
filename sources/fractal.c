/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:54:39 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/27 14:54:40 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	equal_lam_im(int x, int y, t_im *im, t_fract *fr)
{
	int i;
	int color;

	color = 0;
	im->real = 0.5;
	im->image = 0;
	i = 0;
	while (i < fr->max_iter)
	{
		plus_lam_im(im);
		if ((im->real * im->real + im->image * im->image) > 3.0)
			break ;
		i++;
	}
	if (i < fr->max_iter && i > 0)
	{
		color = set_color(i, fr);
		img_pixel_put(x, y, color, fr);
	}
}

void	equal_im(int x, int y, t_im *im, t_fract *fr)
{
	int i;
	int color;

	color = 0;
	im->real = im->w;
	im->image = im->h;
	i = 0;
	while (i < fr->max_iter)
	{
		if (fr->tf == FRAC_TYPE_MAN)
			plus_man_im(im);
		else if (fr->tf == FRAC_TYPE_JUL)
			plus_jul_im(im);
		else if (fr->tf == FRAC_TYPE_3)
			plus_3_im(im);
		if ((im->real + im->image) > 4.0)
			break ;
		i++;
	}
	if (i < fr->max_iter && i > 0)
	{
		color = set_color(i, fr);
		img_pixel_put(x, y, color, fr);
	}
}

void	fract_create(t_fract *fr)
{
	t_im	*im;
	int		x;
	int		y;

	if ((im = init_im()) == NULL)
		init_error("");
	y = 0;
	while (y < fr->heigth)
	{
		x = 0;
		im->w = im->r_min;
		while (x < fr->width)
		{
			if (fr->tf == FRAC_TYPE_LAM)
				equal_lam_im(x, y, im, fr);
			else
				equal_im(x, y, im, fr);
			im->w = im->w + im->r_iter;
			x++;
		}
		im->h = im->h + im->i_iter;
		y++;
	}
}

void	pick_create(t_fract *fr)
{
	if ((fr->fract = mlx_new_image(fr->mlx, fr->width, fr->heigth)) == NULL)
		init_error(ERROR_MLX);
	fr->fract_data = mlx_get_data_addr(fr->fract, &fr->bpp,
		&fr->size_line, &fr->end);
	fract_create(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->fract, 0, 0);
	mlx_destroy_image(fr->mlx, fr->fract);
}
