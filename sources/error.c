/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:27:31 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/23 18:27:32 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_error(char *pref)
{
	ft_putstr_fd(PROG_NAME, 2);
	ft_putstr_fd(": ", 2);
	perror(pref);
	exit(ERROR_EXIT);
}

void	error_input(void)
{
	ft_putstr("------------------------------");
	ft_putstr("\n");
	ft_putstr("Chose one of suppose fractal's:");
	ft_putstr("\n");
	ft_putstr("------------------------------");
	ft_putstr("\n");
	ft_putstr("1 to Mandelbrot");
	ft_putstr("\n");
	ft_putstr("2 to Julia");
	ft_putstr("\n");
	ft_putstr("3 to specific");
	ft_putstr("\n");
	ft_putstr("4 to Lamda fractal's");
	ft_putstr("\n");
}

void	input_error(char *av)
{
	if ((av[0] != '1' && av[0] != '2' && av[0] != '3' &&
		av[0] != '4') || av[1] != '\0')
	{
		ft_putstr("Wrong input");
		ft_putstr("\n");
		error_input();
		exit(1);
	}
}
