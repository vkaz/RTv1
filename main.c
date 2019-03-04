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

void			init(t_mlx *mlx)
{
	mlx->ch = mlx->vh / 2;
	mlx->cw = mlx->vw / 2;
}

void 			dod(t_mlx *mlx)
{
	draw(mlx);
	SDL_RenderPresent(mlx->rend);
}

void 			move(t_mlx *mlx, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_s)
		mlx->origin = rot(mlx->origin, (t_vector){-0.15, 0, 0}, -1);
	else if (event.key.keysym.sym == SDLK_d)
		mlx->origin = rot(mlx->origin, (t_vector){0, 0, -0.15}, -1);
	else if (event.key.keysym.sym == SDLK_w)
		mlx->origin = rot(mlx->origin, (t_vector){0.15, 0, 0}, -1);
    else if (event.key.keysym.sym == SDLK_a)
		mlx->origin = rot(mlx->origin, (t_vector){0, 0, 0.15}, -1);
}

int				main(int argc, char **argv)
{
	t_mlx	mlx;
    SDL_Event event;

	if (argc == 2)
	{
		mlx.i1 = 0;
		if (read_from_file(argv[1], &mlx) == -1)
			errore();
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
			errore();
		int oglIdx = -1;
		mlx.win = SDL_CreateWindow( "RTv1", 20, 20, mlx.vw, mlx.vh, SDL_WINDOW_OPENGL);
    	SDL_GLContext glcontext = SDL_GL_CreateContext(mlx.win);
    	mlx.rend = SDL_CreateRenderer(mlx.win, oglIdx, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    	glMatrixMode(GL_PROJECTION|GL_MODELVIEW);
		SDL_bool done = SDL_FALSE;
        while (!done)
        {
           	init(&mlx);
			dod(&mlx);
            while (SDL_PollEvent(&event))
            {
                if (event.key.keysym.sym == SDLK_UP && event.type == SDL_KEYDOWN)
					mlx.cam_rot.x += 0.15;
				else if (event.key.keysym.sym == SDLK_DOWN && event.type == SDL_KEYDOWN)
					mlx.cam_rot.x -= 0.15;
				else if (event.key.keysym.sym == SDLK_RIGHT && event.type == SDL_KEYDOWN)
					mlx.cam_rot.y += 0.15;
				else if (event.key.keysym.sym == SDLK_LEFT && event.type == SDL_KEYDOWN)
					mlx.cam_rot.y -= 0.15;
                else if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = SDL_TRUE;
                else if (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_w
                	|| event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_s
                	|| event.key.keysym.sym == SDLK_d))
                	move(&mlx, event);
            }
        }
    	SDL_GL_DeleteContext(glcontext);
	}
	else
		printf("\033[31mError\n\033[33mUsage: ./RTv1 (scenes/test)\n");
	return (0);
}
