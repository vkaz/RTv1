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
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "libft/libft.h"
# include "include/SDL2/SDL.h"
# include "include/GL/glew.h"
# include "include/SDL2/SDL_opengl.h"

typedef struct		s_col
{
	double			r;
	double			g;
	double			b;
}					t_col;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_vec
{
	char			*name;
	t_vector		vec;
	t_col			color;
	double			rad;
	t_vector		rot;
	double			spec;
}					t_vec;

typedef struct		s_light
{
	double			intensity;
	t_vector		position;
}					t_light;

typedef struct		s_mlx
{
	void			*mlx;
	void			*img;
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_GLContext glcontext;
	int				*data;
	int				bpp;
	int				sizeline;
	int				end;
	int				iter;
	int				l;
	int				i1;
	int				i2;
	int				ic;
	int				is;
	int				ip;
	int				ir;
	int				isp;
	double			vw;
	double			vh;
	double			cw;
	double			ch;
	double			hit;
	double			t0;
	double			t1;
	double			k1;
	double			k2;
	double			k3;
	double			tmp;
	double			intensity;
	double			shadow;
	double			len;
	double			lenn;
	double			vec_v;
	double			dot_v;
	unsigned int	colo;
	double			x;
	double			y;
	int				f;
	unsigned int	col;
	t_vec			*i;
	t_vector		dir;
	t_vector		dir2;
	t_vector		obj_rot;
	t_vector		origin;
	t_vector		vec_r;
	t_col			color;
	t_light			light;
	t_vector		dist;
	t_vector		point;
	t_vector		normal;
	t_vector		vec_l;
	t_vector		view;
	t_vector		tmp_v;
	t_vector		rot;
	t_vector		eye;
	t_vector		cam_rot;
	double			n_dot_l;
	double			rad;
	double			d;
	char			*name;
	int				li;
	int				lig;
	double			t_min;
	double			t_max;
}					t_mlx;

t_vector		vecsub1(t_vector v1, t_vector v2);
void				sphere(t_mlx *mlx, t_vector dir, t_vector origin);
t_vector			vecnorm(t_mlx *mlx);
void				draw(t_mlx *mlx);
void				cone(t_mlx *mlx, t_vector dir, t_vector origin);
void				plane(t_mlx *mlx, t_vector dir, t_vector origin);
t_vector			vecros(t_vector a, t_vector b);
void				cylinder(t_mlx *mlx, t_vector dir, t_vector origin);
t_vector			vecsub(t_vector v1, t_vector v2);
double				vecdot(t_vector dir1, t_vector dir2);
t_vector			vecscale(double tmp, t_vector v1);
t_vector			vectadd(t_vector v1, t_vector v2);
double				max(double x, double y);
double				min(double x, double y);
double				length(t_vector dist);
void				choise(t_mlx *mlx, t_vector origin, t_vector dir);
double				closes(t_mlx *mlx, t_vector origin, t_vector dir);
t_vector			rot(t_vector xyz, t_vector rot, int i);
void				clamp(t_mlx *mlx);
void				put_pix(t_mlx *mlx, int x, int y);
void				init_multi(t_mlx *mlx);
int					read_from_file(char *argv, t_mlx *mlx);
int					che_name(char *str, int i);
void				ft_lstpushback(t_list **blst, void const *content,
	size_t content_size);
void				get(t_list *list, t_mlx *mlx);
void				get2(t_list *list, t_mlx *mlx);
char				*find(char *str, char start, char end);
double				min_max(double x, double min, double max);
void				name(char *name, t_mlx *mlx, int i);
void				get_light(t_list *list, t_mlx *mlx, int i);
void				del(void *data, size_t size);
void				free_list_str(char **list);
void				spaces(t_list *list);
void				intens(t_mlx *mlx);
void				i_null(t_mlx *mlx);
void				eror(t_mlx *mlx);
int					count_i(t_mlx *mlx, t_list *list);
int					count_i_p(t_mlx *mlx, t_list *list);
int					count_i_s(t_mlx *mlx, t_list *list);
int					che_in(t_mlx *mlx, t_list *list);
int					count_cam(t_list *list, t_mlx *mlx);
int					count_li(t_list *list, t_mlx *mlx);
int					count_sc(t_list *list, t_mlx *mlx);
void				flist(t_list *list);
void				digit(char **xy);
void				errore(void);
t_vector			rot2(t_vector xyz, t_vector rot, int i);

#endif
