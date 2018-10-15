/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:15:52 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/10/11 11:15:53 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			count_li(t_list *list, t_mlx *mlx)
{
	i_null(mlx);
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "pos"))
			mlx->ip++;
		else if (ft_strstr(list->content, "power"))
			mlx->is++;
		list = list->next;
	}
	if (mlx->is == 0 || mlx->ip == 0)
		return (-1);
	return (0);
}

int			count_cam(t_list *list, t_mlx *mlx)
{
	i_null(mlx);
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "cam_pos"))
			mlx->ip++;
		else if (ft_strstr(list->content, "cam_dir"))
			mlx->is++;
		else if (ft_strstr(list->content, "display_size"))
			mlx->ic++;
		list = list->next;
	}
	if (mlx->ic == 0 || mlx->is == 0 || mlx->ip == 0)
		return (-1);
	return (0);
}

int			count_i(t_mlx *mlx, t_list *list)
{
	i_null(mlx);
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "pos"))
			mlx->ip++;
		else if (ft_strstr(list->content, "size"))
			mlx->is++;
		else if (ft_strstr(list->content, "color"))
			mlx->ic++;
		else if (ft_strstr(list->content, "spec"))
			mlx->isp++;
		else if (ft_strstr(list->content, "rot"))
			mlx->ir++;
		list = list->next;
	}
	if (mlx->ic == 0 || mlx->is == 0 || mlx->ip == 0 || mlx->ir == 0 ||
		mlx->isp == 0)
		return (-1);
	return (0);
}

int			count_i_s(t_mlx *mlx, t_list *list)
{
	i_null(mlx);
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "pos"))
			mlx->ip++;
		else if (ft_strstr(list->content, "size"))
			mlx->is++;
		else if (ft_strstr(list->content, "color"))
			mlx->ic++;
		else if (ft_strstr(list->content, "spec"))
			mlx->isp++;
		list = list->next;
	}
	if (mlx->ic == 0 || mlx->is == 0 || mlx->ip == 0 || mlx->isp == 0)
		return (-1);
	return (0);
}

int			count_i_p(t_mlx *mlx, t_list *list)
{
	i_null(mlx);
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "pos"))
			mlx->ip++;
		else if (ft_strstr(list->content, "rot"))
			mlx->ir++;
		else if (ft_strstr(list->content, "color"))
			mlx->ic++;
		else if (ft_strstr(list->content, "spec"))
			mlx->isp++;
		list = list->next;
	}
	if (mlx->ic == 0 || mlx->ir == 0 || mlx->ip == 0 || mlx->isp == 0)
		return (-1);
	return (0);
}
