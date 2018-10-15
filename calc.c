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
	float		k;

	k = mlx->i[mlx->iter].rad;
	mlx->i[mlx->iter].rot.y = 1;
	mlx->dist = vecsub(origin, mlx->i[mlx->iter].vec);
	mlx->k1 = vecdot(dir, dir) - pow(vecdot(dir, mlx->i[mlx->iter].rot), 2)
		* (1 + k * k);
	mlx->k2 = 2 * (vecdot(dir, mlx->dist) - (1 + k * k)
		* vecdot(dir, mlx->i[mlx->iter].rot)
		* vecdot(mlx->dist, mlx->i[mlx->iter].rot));
	mlx->k3 = vecdot(mlx->dist, mlx->dist) - (1 + k * k)
		* pow(vecdot(mlx->dist, mlx->i[mlx->iter].rot), 2);
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
	if (mlx->f < 6 && mlx->f > -1)
	{
		mlx->t0 = -((vecdot(mlx->i[mlx->iter].rot, origin) -
			vecdot(mlx->i[mlx->iter].rot, mlx->i[mlx->iter].vec)) /
			vecdot(mlx->i[mlx->iter].rot, dir));
		mlx->t1 = INFINITY;
		if (mlx->t0 < 0)
			mlx->t0 = INFINITY;
	}
}

void	cylinder(t_mlx *mlx, t_vector dir, t_vector origin)
{
	float		k;

	k = mlx->i[mlx->iter].rad;
	mlx->i[mlx->iter].rot.y = 0;
	mlx->dir2 = rot(dir, mlx->i[mlx->iter].rot, 1);
	mlx->dist = vecsub(origin, mlx->i[mlx->iter].vec);
	mlx->k1 = mlx->dir2.x * mlx->dir2.x + mlx->dir2.z * mlx->dir2.z;
	mlx->k2 = 2 * (mlx->dir2.x * mlx->dist.x + mlx->dir2.z * mlx->dist.z);
	mlx->k3 = mlx->dist.x * mlx->dist.x + mlx->dist.z * mlx->dist.z
		- (k * k);
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
