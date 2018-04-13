/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:34:13 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/28 15:34:13 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_help(t_fract *fr)
{
	mlx_string_put(fr->mlx, fr->win, 20, 40, WHITE, "Controls:");
	mlx_string_put(fr->mlx, fr->win, 20, 60, WHITE, "ESC         : quit");
	mlx_string_put(fr->mlx, fr->win, 20, 80, WHITE, "Scroll up   : zoom up");
	mlx_string_put(fr->mlx, fr->win, 20, 100, WHITE, "Scroll down : zoom down");
	mlx_string_put(fr->mlx, fr->win, 20, 120, WHITE,
		"Num +   : up amount dots");
	mlx_string_put(fr->mlx, fr->win, 20, 140, WHITE,
		"Num -   : down amount dots");
	mlx_string_put(fr->mlx, fr->win, 20, 160, WHITE, "Home        : reset");
	mlx_string_put(fr->mlx, fr->win, 20, 180, WHITE,
		"Num *     : switch color set");
	mlx_string_put(fr->mlx, fr->win, 20, 200, WHITE,
		"Space     : switch mode");
	mlx_string_put(fr->mlx, fr->win, 20, 220, WHITE,
		"Arrow up/down : moove fract up/down");
	mlx_string_put(fr->mlx, fr->win, 20, 240, WHITE,
		"Arrow right/left : moove fract right/left");
}

void	push_help(t_fract *fr)
{
	mlx_string_put(fr->mlx, fr->win, 10, 10, WHITE, SHOW_HELP);
	mlx_string_put(fr->mlx, fr->win, fr->width - 80, 10,
		WHITE, "dots: ");
	mlx_string_put(fr->mlx, fr->win, fr->width - 30, 10,
		WHITE, ft_itoa(fr->max_iter));
	if (fr->show_help == FT_TRUE)
		show_help(fr);
}
