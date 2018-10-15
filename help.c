/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:06:57 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/08/27 14:06:58 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		spaces(t_list *list)
{
	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
}

double		max(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

double		min(double x, double y)
{
	if (x < y)
		return (x);
	return (y);
}

void		choise(t_mlx *mlx, t_vector origin, t_vector dir)
{
	if (ft_strcmp(mlx->name, "sphere") == 0)
		sphere(mlx, dir, origin);
	else if (ft_strcmp(mlx->name, "cone") == 0)
		cone(mlx, dir, origin);
	else if (ft_strcmp(mlx->name, "plane") == 0)
		plane(mlx, dir, origin);
	else if (ft_strcmp(mlx->name, "cylinder") == 0)
		cylinder(mlx, dir, origin);
}

double		closes(t_mlx *mlx, t_vector origin, t_vector dir)
{
	mlx->tmp = INFINITY;
	mlx->iter = -1;
	mlx->f = INFINITY;
	while (++mlx->iter < mlx->l)
	{
		mlx->name = mlx->i[mlx->iter].name;
		choise(mlx, origin, dir);
		if (mlx->t0 < mlx->tmp && mlx->t_min < mlx->t0 && mlx->t0 < mlx->t_max)
		{
			mlx->tmp = mlx->t0;
			mlx->f = mlx->iter;
		}
		if (mlx->t1 < mlx->tmp && mlx->t_min < mlx->t1 && mlx->t1 < mlx->t_max)
		{
			mlx->tmp = mlx->t1;
			mlx->f = mlx->iter;
		}
	}
	return (mlx->tmp);
}
