/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:27:24 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/29 17:27:25 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_color4(int i)
{
	int color;

	color = 0;
	color = i == 0 ? 0xffd700 : color;
	color = i == 1 ? 0x800000 : color;
	color = i == 2 ? 0xA020F0 : color;
	color = i == 3 ? 0xB3EE3A : color;
	color = i == 4 ? 0xCD5555 : color;
	color = i == 5 ? 0xEE2C2C : color;
	color = i == 6 ? 0xFF7F00 : color;
	color = i == 7 ? 0xEE7600 : color;
	color = i == 8 ? 0xCD6600 : color;
	color = i == 9 ? 0x8B4500 : color;
	color = i == 10 ? 0xFF7F24 : color;
	color = i == 11 ? 0xEE7621 : color;
	color = i == 12 ? 0xCD661D : color;
	color = i == 13 ? 0x8B4513 : color;
	color = i == 14 ? 0xFF3030 : color;
	color = i == 15 ? 0xEE2C2C : color;
	color = i == 16 ? 0xCD2626 : color;
	color = i == 17 ? 0x8B1A1A : color;
	color = i == 18 ? 0xFF4040 : color;
	color = i == 19 ? 0xEE3B3B : color;
	color = i == 20 ? 0xCD3333 : color;
	return (color);
}

int		set_color3(int i)
{
	int color;

	color = 0;
	color = i == 0 ? 0xffd700 : color;
	color = i == 1 ? 0xEEC900 : color;
	color = i == 2 ? 0xCDAD00 : color;
	color = i == 3 ? 0x8B7500 : color;
	color = i == 4 ? 0xFFC125 : color;
	color = i == 5 ? 0xEEB422 : color;
	color = i == 6 ? 0xCD9B1D : color;
	color = i == 7 ? 0x8B6914 : color;
	color = i == 8 ? 0xFFB90F : color;
	color = i == 9 ? 0xEEAD0E : color;
	color = i == 10 ? 0xCD950C : color;
	color = i == 11 ? 0x8B658B : color;
	color = i == 12 ? 0xFF6A6A : color;
	color = i == 13 ? 0xEE6363 : color;
	color = i == 14 ? 0xCD5555 : color;
	color = i == 15 ? 0x8B3A3A : color;
	color = i == 16 ? 0xFF8247 : color;
	color = i == 17 ? 0xEE7942 : color;
	color = i == 18 ? 0xCD6839 : color;
	color = i == 19 ? 0x8B4726 : color;
	color = i == 20 ? 0xFFD39B : color;
	return (color);
}

int		set_color2(int i)
{
	int color;

	color = 0;
	color = i == 0 ? 0xD02090 : color;
	color = i == 1 ? 0xB22222 : color;
	color = i == 2 ? 0xD2691E : color;
	color = i == 3 ? 0xCD5C5C : color;
	color = i == 4 ? 0xCD5555 : color;
	color = i == 5 ? 0xFFD700 : color;
	color = i == 6 ? 0xFF7F00 : color;
	color = i == 7 ? 0x7CFC00 : color;
	color = i == 8 ? 0x1C1C1C : color;
	color = i == 9 ? 0x8B0000 : color;
	color = i == 10 ? 0xFAEBD7 : color;
	color = i == 11 ? 0xCAFF70 : color;
	color = i == 12 ? 0xBCEE68 : color;
	color = i == 13 ? 0xA2CD5A : color;
	color = i == 14 ? 0x6E8B3D : color;
	color = i == 15 ? 0xFFF68F : color;
	color = i == 16 ? 0xEEE685 : color;
	color = i == 17 ? 0xCDC673 : color;
	color = i == 18 ? 0x8B864E : color;
	color = i == 19 ? 0xFFEC8B : color;
	color = i == 20 ? 0xEEDC82 : color;
	return (color);
}

int		set_color1(int i)
{
	int color;

	color = 0;
	color = i == 0 ? 0xffd700 : color;
	color = i == 1 ? 0x800000 : color;
	color = i == 2 ? 0xA020F0 : color;
	color = i == 3 ? 0xB3EE3A : color;
	color = i == 4 ? 0xCD5555 : color;
	color = i == 5 ? 0xEE2C2C : color;
	color = i == 6 ? 0xFF7F00 : color;
	color = i == 7 ? 0xEE9A00 : color;
	color = i == 8 ? 0x1C1C1C : color;
	color = i == 9 ? 0x8B0000 : color;
	color = i == 10 ? 0x8B658B : color;
	color = i == 11 ? 0x8B3A3A : color;
	color = i == 12 ? 0xFFD700 : color;
	color = i == 13 ? 0xFFF68F : color;
	color = i == 14 ? 0xBCEE68 : color;
	color = i == 15 ? 0xFFF68F : color;
	color = i == 16 ? 0x698B22 : color;
	color = i == 17 ? 0xBCEE68 : color;
	color = i == 18 ? 0x00008B : color;
	color = i == 19 ? 0xA020F0 : color;
	color = i == 20 ? 0xFF0000 : color;
	return (color);
}

int		set_color(int i, t_fract *fr)
{
	int color;

	color = 0;
	if (fr->push_star % 4 == 0)
		color = set_color1(i);
	else if (fr->push_star % 4 == 1)
		color = set_color2(i);
	else if (fr->push_star % 4 == 2)
		color = set_color3(i);
	else if (fr->push_star % 4 == 3)
		color = set_color4(i);
	return (color);
}
