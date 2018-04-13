/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:26:42 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/26 19:26:43 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plus_man_im(t_im *im)
{
	double x;
	double y;

	x = im->real;
	y = im->image;
	im->real = x * x - y * y + im->w + im->cr;
	im->image = 2 * x * y + im->h + im->ci;
}

void	plus_jul_im(t_im *im)
{
	double x;
	double y;

	x = im->real;
	y = im->image;
	im->real = x * x - y * y + im->cr;
	im->image = 2 * x * y + im->ci;
}

void	plus_3_im(t_im *im)
{
	double x;
	double y;

	x = im->real;
	y = im->image;
	im->real = x * x * x - 3 * x * y * y + im->cr;
	im->image = 2 * x * x * y - y * y * y + im->ci;
}

void	plus_lam_im(t_im *im)
{
	double x;
	double y;
	double p;
	double q;

	x = im->real;
	y = im->image;
	p = x - x * x + y * y;
	q = y - 2 * x * y;
	im->real = (im->w + 1) * p - im->h * q + im->cr;
	im->image = (im->w + 1) * q + im->h * p + im->ci;
}
