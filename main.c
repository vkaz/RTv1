/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:08:39 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/06/04 14:08:40 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int u_i;

#include "rtv1.h"

int			key_hook(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_image(param->mlx, param->mlx);
		exit(1);
	}
	return (0);
}

void 	traceray(t_mlx *mlx, int x, int y)
{
	int k1, k2, k3;

	t_vector	a;

	a.x = mlx->cam.x - mlx->pos.x;
	a.y = mlx->cam.y - mlx->pos.y;
	a.z = mlx->cam.z - mlx->pos.z;
	k1 = pow(mlx->bd.x, 2) + pow(mlx->bd.y, 2) + pow(mlx->bd.z, 2);
	k2 = 2 * (a.x * mlx->bd.x + a.y * mlx->bd.y + a.z * mlx->bd.z);
	k3 = pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) - pow(mlx->rad, 2);
	mlx->dis = k2 * k2 - 4 * k1 * k3;
	mlx->t1 = (mlx->dis >= 0 ? (-k2 + sqrt(mlx->dis)) / (2 * k1) : INFINITY);
	mlx->t2 = (mlx->dis >= 0 ? (-k2 - sqrt(mlx->dis)) / (2 * k1) : INFINITY);
	if (mlx->t1 < INFINITY && mlx->t1 > 1)
	{
		mlx->tnear = mlx->t1;
		mlx->data[mlx->vw * y + x] = 0x005cf2;
	}
	// else
	// 	mlx->data[mlx->vw * y + x] = 0xFFFFFF;
	// if ( mlx->t2 > 1 && mlx->t2 < INFINITY)
	// {
	// 	mlx->tnear = mlx->t2;
	// 	mlx->data[mlx->vw * y + x] = 0x005cf2;
	// }
}

void 	init_sphare(t_mlx *mlx)
{
	int x,y;

	y = 0;
	while (y <= mlx->vh)
	{
		x = 0;
		while (x <= mlx->vw)
		{
			// mlx->bd = (t_vector){x * (mlx->vw / mlx->cw), y * (mlx->vh / mlx->ch), 1};
			mlx->bd = (t_vector){x * mlx->vw / mlx->cw, y * mlx->vh / mlx->ch, 1};
			traceray(mlx, x, y);
			x++;
		}
		y++;
	}
	mlx->win = mlx_new_window(mlx->mlx, mlx->vw, mlx->vh, "RTv1");
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void 	init(t_mlx *mlx)
{
	mlx->pos = (t_vector){0, 0, 0};
	mlx->cam = (t_vector){0, 0, -30};
	mlx->rad = 10000;
	mlx->tnear = INFINITY;
	mlx->ch = mlx->vh / 2;
	mlx->cw = mlx->vw / 2;
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, mlx->vw, mlx->vh);
	mlx->data = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->end);
	mlx->t_max = mlx->bpp;
	mlx->t_min = 1;
	init_sphare(mlx);
}

int		main(void)
{
	t_mlx	mlx;

	mlx.vh = 720;
	mlx.vw = 720;
	init(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return(0);
}
