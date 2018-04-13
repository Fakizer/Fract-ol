/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 19:18:53 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/29 19:18:54 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_fract *fr)
{
	pick_create(fr);
	push_help(fr);
	return (0);
}

int		motion_hook(int x, int y, t_fract *fr)
{
	if (fr->motion == FT_TRUE)
	{
		if (x >= 0 && x <= fr->width && y >= 0 && y <= fr->heigth)
		{
			fr->cr = (x - fr->width / 2) * (1.0 / (fr->width / 2.0));
			fr->ci = (y - fr->heigth / 2) * (1.0 / (fr->heigth / 2.0));
			expose_hook(fr);
		}
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_fract *fr)
{
	if (button == ZOOM_UP)
	{
		fr->x_shift += ((x - (fr->width / 2)) / (fr->width * 20.0));
		fr->y_shift += ((y - (fr->heigth / 2)) / (fr->heigth * 20.0));
		fr->zoom -= fr->zoom / 10.0;
		expose_hook(fr);
	}
	else if (button == ZOOM_DOWN)
	{
		fr->x_shift -= ((x - (fr->width / 2)) / (fr->width * 10.0));
		fr->y_shift -= ((y - (fr->heigth / 2)) / (fr->heigth * 10.0));
		fr->zoom += fr->zoom / 10.0;
		expose_hook(fr);
	}
	return (0);
}

int		push_keys(int keycode, t_fract *fr)
{
	if (keycode == 69)
	{
		fr->max_iter += 25;
		expose_hook(fr);
	}
	else if (keycode == 78)
	{
		fr->max_iter -= 25;
		expose_hook(fr);
	}
	else if (keycode == 67)
	{
		fr->push_star++;
		expose_hook(fr);
	}
	return (0);
}

int		key_hook(int keycode, t_fract *fr)
{
	if (keycode == ESC)
		exit(EXIT_OK);
	else if (keycode == F1)
	{
		fr->show_help = (fr->show_help ==
			FT_FALSE) ? FT_TRUE : FT_FALSE;
		expose_hook(fr);
	}
	else if (keycode == HOME)
	{
		res_fract(fr);
		expose_hook(fr);
	}
	else if (keycode == 49)
		fr->motion = (fr->motion == FT_FALSE) ? FT_TRUE : FT_FALSE;
	push_keys(keycode, fr);
	push_arrow(keycode, fr);
	return (0);
}
