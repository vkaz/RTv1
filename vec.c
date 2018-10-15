/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:07:40 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/08/27 14:07:42 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector		vecscale(double tmp, t_vector v1)
{
	t_vector v;

	v = (t_vector){tmp * v1.x, tmp * v1.y, tmp * v1.z};
	return (v);
}

t_vector		vecsub(t_vector v1, t_vector v2)
{
	t_vector ress;

	ress = (t_vector){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
	return (ress);
}

double			vecdot(t_vector dir1, t_vector dir2)
{
	return (dir1.x * dir2.x + dir1.y * dir2.y + dir1.z * dir2.z);
}

t_vector		vectadd(t_vector v1, t_vector v2)
{
	t_vector result;

	result = (t_vector){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
	return (result);
}

t_vector		vecros(t_vector a, t_vector b)
{
	t_vector resss;

	resss = (t_vector){a.y * b.z - a.z * b.y, a.y * b.x - a.x * b.z, a.x *
		b.y - a.y * b.x};
	return (resss);
}
