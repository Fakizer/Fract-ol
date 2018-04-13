/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:01:16 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/30 15:01:17 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		push_arrow(int keykode, t_fract *fr)
{
	if (keykode == 126)
	{
		fr->y_shift += (((fr->heigth / 2)) / (fr->heigth * 10.0));
		expose_hook(fr);
	}
	else if (keykode == 125)
	{
		fr->y_shift -= (((fr->heigth / 2)) / (fr->heigth * 10.0));
		expose_hook(fr);
	}
	else if (keykode == 123)
	{
		fr->x_shift += (((fr->width / 2)) / (fr->width * 10.0));
		expose_hook(fr);
	}
	else if (keykode == 124)
	{
		fr->x_shift -= (((fr->width / 2)) / (fr->width * 10.0));
		expose_hook(fr);
	}
	return (0);
}
