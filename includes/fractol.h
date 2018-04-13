/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:39:05 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/23 14:39:06 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# define PROG_NAME			"fractol"
# define ERROR_MLX			"minilibx error occured"
# define SHOW_HELP			"Press 'F1' to show/hide help"
# define FRAC_TYPE_MAN		'1'
# define FRAC_TYPE_JUL		'2'
# define FRAC_TYPE_3		'3'
# define FRAC_TYPE_LAM		'4'
# define EXIT_OK			0
# define EXIT_ERROR			1
# define ERROR_EXIT			1

typedef unsigned char		t_tsvet;

typedef enum				e_color
{
	RED = 0xA00000,
	WHITE = 0xFFFFFF,
	BROWN = 0x663300,
	GREEN = 0x007000,
}							t_color;

typedef enum				e_bool
{
	FT_FALSE,
	FT_TRUE
}							t_bool;

typedef enum				e_key
{
	ESC = 53,
	F1 = 122,
	ZOOM_UP = 4,
	ZOOM_DOWN = 5,
	HOME = 115,
	LEFT_MOUSE = 1,
	RIGHT_MOUSE = 2,
}							t_key;

typedef struct				s_fract
{
	void					*mlx;
	void					*win;
	void					*fract;
	char					*fract_data;
	int						bpp;
	int						end;
	int						size_line;
	char					tf;
	double					zoom;
	double					x_shift;
	double					y_shift;
	double					z_shift;
	int						mod;
	t_bool					show_help;
	double					cr;
	double					ci;
	double					cj;
	t_bool					motion;
	int						width;
	int						heigth;
	int						max_iter;
	int						step_iter;
	int						push_star;
}							t_fract;

typedef struct				s_tf
{
	char					man;
	char					jul;
}							t_tf;

typedef struct				s_im
{
	double					real;
	double					image;
	double					r;
	double					i;
	double					r_min;
	double					i_min;
	double					r_max;
	double					i_max;
	double					r_iter;
	double					i_iter;
	double					w;
	double					h;
	double					cr;
	double					ci;
}							t_im;

void						choice_fract(char *typ_fr);
void						init_error(char *pref);
void						error_input();
void						input_error(char *av);
t_fract						*init_fract(char tf);
t_im						*init_im();
int							key_hook(int keycode, t_fract *fr);
int							mouse_hook(int button, int x, int y, t_fract *fr);
int							expose_hook(t_fract *fr);
int							motion_hook(int x, int y, t_fract *fr);
int							push_keys(int keycode, t_fract *fr);
int							push_arrow(int keykode, t_fract *fr);
void						img_pixel_put(int x, int y, int color, t_fract *fr);
void						pick_create(t_fract *fr);
void						fract_create(t_fract *fr);
void						equal_im(int x, int y, t_im *im, t_fract *fr);
void						equal_lam_im(int x, int y, t_im *im, t_fract *fr);
void						plus_man_im(t_im *im);
void						plus_jul_im(t_im *im);
void						plus_3_im(t_im *im);
void						plus_lam_im(t_im *im);
void						push_help(t_fract *fr);
void						res_fract(t_fract *fr);
int							set_color(int i, t_fract *fr);
int							set_color1(int i);
int							set_color2(int i);
int							set_color3(int i);
int							set_color4(int i);

#endif
