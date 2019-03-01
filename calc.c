/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:06:42 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/08/27 14:06:43 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float		calc_magnitude(t_vector *p)
{
	return (sqrtf((*p).x * (*p).x + (*p).y * (*p).y + (*p).z * (*p).z));
}

t_vector	normalize(t_vector p)
{
	float		a;

	a = calc_magnitude(&p);
	if (a == 0)
		return (p);
	return ((t_vector){(p.x) / a, (p.y) / a, (p.z) / a});
}

double	length(t_vector dist)
{
	double temp;

	temp = sqrt(vecdot(dist, dist));
	return (temp);
}

void	sphere(t_mlx *mlx, t_vector dir, t_vector origin)
{
	mlx->dist = vecsub(origin, mlx->i[mlx->iter].vec);
	mlx->k1 = vecdot(dir, dir);
	mlx->k2 = 2 * vecdot(dir, mlx->dist);
	mlx->k3 = vecdot(mlx->dist, mlx->dist) - (mlx->i[mlx->iter].rad
		* mlx->i[mlx->iter].rad);
	mlx->d = mlx->k2 * mlx->k2 - 4 * mlx->k1 * mlx->k3;
	if (mlx->d < 0)
	{
		mlx->t0 = INFINITY;
		mlx->t1 = INFINITY;
		return ;
	}
	mlx->t0 = (-mlx->k2 + sqrtf(mlx->d)) / (2 * mlx->k1);
	mlx->t1 = (-mlx->k2 - sqrtf(mlx->d)) / (2 * mlx->k1);
}

void	cone(t_mlx *mlx, t_vector dir, t_vector origin)
{
	mlx->i[mlx->iter].rot = normalize(mlx->i[mlx->iter].rot);
	mlx->dist = vecsub(origin, mlx->i[mlx->iter].vec);
	mlx->k1 = vecdot(dir, dir) - (powf(tanf(0.785), 2) + 1) * 
		powf(vecdot(dir, mlx->i[mlx->iter].rot), 2);
	mlx->k2 = 2 * (vecdot(dir, mlx->dist) - 
		(powf(tanf(0.785), 2) + 1) * vecdot(dir, mlx->i[mlx->iter].rot)
		* vecdot(mlx->dist, mlx->i[mlx->iter].rot));
	mlx->k3 = vecdot(mlx->dist, mlx->dist) - (powf(tanf(0.785), 2) + 1)
		* powf(vecdot(mlx->dist, mlx->i[mlx->iter].rot), 2);
	mlx->d = mlx->k2 * mlx->k2 - 4 * mlx->k1 * mlx->k3;
	if (mlx->d < 0)
	{
		mlx->t0 = INFINITY;
		mlx->t1 = INFINITY;
		return ;
	}
	mlx->t0 = (-mlx->k2 + sqrtf(mlx->d)) / (2 * mlx->k1);
	mlx->t1 = (-mlx->k2 - sqrtf(mlx->d)) / (2 * mlx->k1);
}

void	plane(t_mlx *mlx, t_vector dir, t_vector origin)
{
	t_vector	k;
	float		dot;

	dot = vecdot(mlx->i[mlx->iter].rot, dir);
	if (dot != 0)
	{
		k = vecsub(mlx->i[mlx->iter].vec, origin);
		mlx->t0 = (vecdot(k, mlx->i[mlx->iter].rot) / dot);
	}
	else
		mlx->t0 = INFINITY;
}

void	cylinder(t_mlx *mlx, t_vector dir, t_vector origin)
{
	float		k;

	k = mlx->i[mlx->iter].rad;
	mlx->i[mlx->iter].rot  = normalize(mlx->i[mlx->iter].rot);
	mlx->dist = vecsub(origin, mlx->i[mlx->iter].vec);
	mlx->k1 = vecdot(dir, dir) -
			powf(vecdot(dir, mlx->i[mlx->iter].rot), 2);
	mlx->k2 = 2 * (vecdot(dir, mlx->dist) - vecdot(dir,
			mlx->i[mlx->iter].rot) * vecdot(mlx->dist, mlx->i[mlx->iter].rot));
	mlx->k3 = vecdot(mlx->dist, mlx->dist) - powf(vecdot(mlx->dist, mlx->i[mlx->iter].rot), 2) -
			k;
	mlx->d = (mlx->k2 * mlx->k2 - 4 * mlx->k1 * mlx->k3);
	if (mlx->d < 0)
	{
		mlx->t0 = INFINITY;
		mlx->t1 = INFINITY;
		return ;
	}
	mlx->t0 = (-mlx->k2 + sqrtf(mlx->d)) / (2 * mlx->k1);
	mlx->t1 = (-mlx->k2 - sqrtf(mlx->d)) / (2 * mlx->k1);
}
