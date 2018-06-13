/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:10:34 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/06/04 14:10:35 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
# include "libft/libft.h"

typedef int 	i;
typedef float 	f;

typedef struct 	s_vector
{
	double 			x;
	double 			y;
	double 			z;
}				t_vector;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				sizeline;
	int				end;
	int				vw;
	int				vh;
	int				cw;
	int				ch;
	int				t_min;
	unsigned int	t_max;
	unsigned int	color;
	double			tnear;
	t_vector		pos;
	t_vector		bd;
	t_vector		centre;
	t_vector		cam;
	t_vector		plan;
	t_vector		vector;
	int 			rad;
	double 			d;
	double			t1;
	double			t2;
	double 			f;
	double 			dis;
}					t_mlx;

void 	init(t_mlx *mlx);
void	rot(t_vector *xyz, t_vector *rot, int i);
void	calc(int x, int y, t_mlx *mlx);

#endif
