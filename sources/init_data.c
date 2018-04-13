/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:49:58 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/23 17:49:59 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		res_fract(t_fract *fr)
{
	fr->zoom = 1.0;
	fr->x_shift = 0;
	fr->y_shift = 0;
	fr->mod = 0;
	fr->cr = 0;
	fr->ci = 0;
	fr->motion = FT_FALSE;
	fr->max_iter = 50;
	fr->push_star = 0;
}

t_fract		*init_fract(char tf)
{
	t_fract	*fr;

	if ((fr = (t_fract*)malloc(sizeof(t_fract))) == NULL)
		return (NULL);
	fr->mlx = NULL;
	fr->win = NULL;
	fr->fract = NULL;
	fr->fract_data = NULL;
	fr->bpp = 0;
	fr->end = 0;
	fr->size_line = 0;
	fr->zoom = 1.0;
	fr->x_shift = 0;
	fr->y_shift = 0;
	fr->tf = tf;
	fr->mod = 0;
	fr->show_help = FT_FALSE;
	fr->cr = 0;
	fr->ci = 0;
	fr->motion = FT_FALSE;
	fr->width = 480;
	fr->heigth = 320;
	fr->max_iter = 50;
	fr->push_star = 0;
	return (fr);
}

t_im		*init_im(t_fract *fr)
{
	t_im	*im;

	if ((im = (t_im*)malloc(sizeof(t_im))) == NULL)
		return (NULL);
	im->real = 0;
	im->image = 0;
	im->r = 6 * fr->zoom;
	im->i = (im->r * fr->heigth) / fr->width;
	im->r_min = -im->r / 2 + fr->x_shift;
	im->i_min = -im->i / 2 + fr->y_shift;
	im->r_max = im->r_min + im->r;
	im->i_max = im->i_min + im->i;
	im->r_iter = (im->r_max - im->r_min) / fr->width;
	im->i_iter = (im->i_max - im->i_min) / fr->heigth;
	im->h = im->i_min;
	im->w = im->r_min;
	im->cr = fr->cr;
	im->ci = fr->ci;
	return (im);
}
