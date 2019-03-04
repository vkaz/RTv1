/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:07:20 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/08/27 14:07:21 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		errore(void)
{
	printf("Wrong file format\n");
	exit(1);
}

void		digit(char **xy)
{
	if ((xy[0] == NULL) || (xy[1] == NULL) || (xy[2] == NULL))
		errore();
}
t_vector	x(t_vector xyz, t_vector rot)
{
	t_vector	new;

	new.x = xyz.x;
	new.y = xyz.y * cos(rot.x) + xyz.z * sin(rot.x);
	new.z = -xyz.y * sin(rot.x) + xyz.z * cos(rot.x);
	return(new);
}

t_vector 	y(t_vector new, t_vector rot)
{
	t_vector	xy;

	xy.x = new.x * cos(rot.y ) + new.z * sin(rot.y);
	xy.y = new.y;
	xy.z = -new.x * sin(rot.y) + new.z * cos(rot.y);
	return(xy);
}

t_vector  	z(t_vector xy, t_vector rot)
{
	t_vector	new;

	new.x = xy.x * cos(rot.z) - xy.y * sin(rot.z);
	new.y = xy.x * sin(rot.z) + xy.y * cos(rot.z);
	new.z = xy.z;
	return(new);
}

t_vector	rot(t_vector xyz, t_vector rot, int i)
{
	t_vector	new;

	new = x(xyz, rot);
	new = y(new, rot);
	new = z(new, rot);
	return (new);
}
