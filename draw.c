/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:06:48 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/08/27 14:06:49 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		intens(t_mlx *mlx)
{
	mlx->color.r = mlx->color.r * mlx->intensity;
	mlx->color.g = mlx->color.g * mlx->intensity;
	mlx->color.b = mlx->color.b * mlx->intensity;
}

int			shadow(t_mlx *mlx)
{
	mlx->t_min = 0.001;
	mlx->t_max = 1;
	// mlx->t_min = 1;
	// mlx->t_max = INFINITY;
	mlx->shadow = closes(mlx, mlx->point, mlx->vec_l);
	if (mlx->shadow != INFINITY)
	{
		mlx->color = (t_col){0, 0, 0};
		return (-1);
	}
	return (0);
}

void		lighti(t_mlx *mlx, int a)
{
	mlx->len = length(mlx->normal);
	mlx->lenn = length(mlx->view);
	mlx->vec_l = vecsub(mlx->light.position, mlx->point);
	// mlx->vec_l = mlx->light.position;
	if (shadow(mlx) == -1)
		return ;
	mlx->n_dot_l = vecdot(mlx->normal, mlx->vec_l);
	if (mlx->n_dot_l > 0)
		mlx->intensity += mlx->light.intensity * mlx->n_dot_l / (1 *
			length(mlx->vec_l));
	mlx->vec_r = vecsub(vecscale(2.0 * vecdot(mlx->normal, mlx->vec_l),
		mlx->normal), mlx->vec_l);
	mlx->dot_v = vecdot(mlx->vec_r, mlx->view);
	if (mlx->dot_v > 0 && (ft_strcmp(mlx->i[a].name, "plane") != 0))
		mlx->intensity += mlx->light.intensity * pow(mlx->dot_v /
				(length(mlx->vec_r) * mlx->lenn), mlx->i[a].spec);
	intens(mlx);
}

void		trace(t_mlx *mlx)
{
	mlx->t_min = 1;
	mlx->t_max = INFINITY;
	mlx->hit = closes(mlx, mlx->origin, mlx->dir);
	if (mlx->hit == INFINITY)
		mlx->color = (t_col){0, 0, 0};
	else if (mlx->hit < INFINITY && mlx->hit > 1)
	{
		mlx->intensity = 0;
		mlx->color = mlx->i[mlx->f].color;
		mlx->point = vectadd(mlx->origin, vecscale(mlx->hit, mlx->dir));
		mlx->normal = vecsub(mlx->point, mlx->i[mlx->f].vec);
		mlx->normal = vecscale(1.0 / length(mlx->normal), mlx->normal);
		mlx->view = vecscale(-1, mlx->dir);
		lighti(mlx, mlx->f);
	}
	put_pix(mlx, mlx->x, mlx->y);
}

void		draw(t_mlx *mlx)
{
	mlx->x = -mlx->cw;
	while (mlx->x <= mlx->cw)
	{
		mlx->y = -mlx->ch;
		while (mlx->y <= mlx->ch)
		{
			mlx->dir = vecnorm(mlx);
			mlx->dir = rot(mlx->dir, mlx->cam_rot, -1);
			trace(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
}
