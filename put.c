/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:53:38 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/08/27 16:53:40 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			free_list_str(char **list)
{
	int i;

	i = 0;
	while (list[i] != 0)
	{
		free(list[i++]);
	}
	free(list[i]);
	free(list);
}

void			clamp(t_mlx *mlx)
{
	mlx->color.r = min(255, max(0, mlx->color.r));
	mlx->color.g = min(255, max(0, mlx->color.g));
	mlx->color.b = min(255, max(0, mlx->color.b));
}

void			put_pix(t_mlx *mlx, int x, int y)
{
	int				len;

	x = mlx->cw + x;
	y = mlx->ch - y;
	len = (y * mlx->vw + x - 1);
	clamp(mlx);
	mlx->colo = (((int)mlx->color.r & 0xff) << 16) + (((int)mlx->color.g &
		0xff) << 8) + ((int)mlx->color.b & 0xff);
	if (len <= mlx->vw * mlx->vh && len > -1)
	{
		SDL_SetRenderDrawColor(mlx->rend, mlx->colo >> 16, mlx->colo >> 8, mlx->colo, 0xff);
		SDL_RenderDrawPoint(mlx->rend, x, y);
	}
		// mlx->data[len] = mlx->colo;
}

t_vector		vecnorm(t_mlx *mlx)
{
	t_vector	res;

	res = (t_vector){mlx->x * 1 / mlx->vw, mlx->y *
		1 / mlx->vw, 1.0};
	return (res);
}
