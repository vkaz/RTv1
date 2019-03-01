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

#include "rtv1.h"

// int				key_hook(int keycode, t_mlx *param)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(param->mlx, param->win);
// 		mlx_destroy_image(param->mlx, param->mlx);
// 		exit(1);
// 	}
// 	return (0);
// }

// int				mouse_hook(void)
// {
// 	exit(1);
// 	return (0);
// }

// int				expose(t_mlx *mlx)
// {
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
// 	return (0);
// }

void			init(t_mlx *mlx)
{
	mlx->ch = mlx->vh / 2;
	mlx->cw = mlx->vw / 2;
	// mlx->mlx = mlx_init();
	// mlx->img = mlx_new_image(mlx->mlx, mlx->vw, mlx->vh);
	// mlx->data = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline,
	// 	&mlx->end);
}

int				main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		mlx.i1 = 0;
		if (read_from_file(argv[1], &mlx) == -1)
		{
			errore();
		}
		SDL_Init(SDL_INIT_VIDEO);
		SDL_CreateWindowAndRenderer(mlx.vw, mlx.vh, 0, &mlx.win, &mlx.rend);
		SDL_bool done = SDL_FALSE;
            while (!done)
            {
            	init(&mlx);
				draw(&mlx);
     			SDL_RenderPresent(mlx.rend);
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        done = SDL_TRUE;
                    }
                }
            }
	// 	mlx.win = mlx_new_window(mlx.mlx, mlx.vw, mlx.vh, "RTv1");
	// 	mlx_expose_hook(mlx.win, &expose, &mlx);
	// 	mlx_key_hook(mlx.win, key_hook, &mlx);
	// 	mlx_hook(mlx.win, 17, 1L << 17, mouse_hook, 0);
	// 	mlx_loop(mlx.mlx);
	}
	else
		printf("\033[31mError\n\033[33mUsage: ./RTv1 (scenes/test)\n");
	return (0);
}
