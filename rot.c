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

t_vector	rot(t_vector xyz, t_vector rot, int i)
{
	t_vector	new;
	t_vector	xy;

	new.x = xyz.x;
	new.y = xyz.y * cos(rot.x * i) + xyz.z * sin(rot.x * i);
	new.z = -xyz.y * sin(rot.x * i) + xyz.z * cos(rot.x * i);
	xy.x = new.x * cos(rot.y * i) + new.z * sin(rot.y * i);
	xy.y = new.y;
	xy.z = -new.x * sin(rot.y * i) + new.z * cos(rot.y * i);
	new.x = xy.x * cos(rot.z * i) - xy.y * sin(rot.z * i);
	new.y = xy.x * sin(rot.z * i) + xy.y * cos(rot.z * i);
	new.z = xy.z;
	return (new);
}
