/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <lzannis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:21:01 by lzannis           #+#    #+#             */
/*   Updated: 2025/12/15 22:07:49 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	draw_circle(t_scene *win_dis)
// {
//     int r;
// 	int dx;
//     int dy;
//     int x = 400;
//     int y = 300;
//     int z = 400;
//     int i;
//     int j;
//     int k;
//     int hit;

    
// 	r = 100;
//     j = y - r;
//     i = x - r;
//     k = z - r;
//     dx = x + r;
// 	dy = y + r;
//     hit = 0;
//     while (j < dy && dy < HEIGHT)
//     {
//         i = x - r;
//         k = z - r;
//         while (i < dx && dx < WIDTH)
//         {
//             if ((j - y) * (j - y) + (i - x) * (i - x) + (k - z) * (k - z) < r * r)
//                 image_pixel_put(win_dis, i, j, TRGB_GREEN + TRGB_BLUE);
           
//             i++;
//             k++;
//         }
//         hit = did_it_hit(i, j, k, r);
//         if (hit >= 2)
//             image_pixel_put(win_dis, i, j, TRGB_WHITE);
//         if (hit == 0)
//             image_pixel_put(win_dis, i, j, TRGB_GREEN + TRGB_BLUE + TRGB_WHITE);
//         else
//             image_pixel_put(win_dis, i, j, TRGB_GREEN + TRGB_BLUE + TRGB_BLACK);
//         j++;
//     }
//     mlx_put_image_to_window (win_dis->mlx_ptr, win_dis->win_ptr, \
//         win_dis->img_ptr, 0, 0);
// }

void	draw_circle(t_scene *win_dis)
{
    int r;
	int dx;
    int dy;
    int x = 400;
    int y = 300;
    int z = 400;
    int i;
    int j;
    int k;
    int hit;

	r = 100;
    j = y - r;
    i = x - r;
    k = z - r;
    dx = x + r;
	dy = y + r;
    hit = 0;
    
    
    while (j < dy && dy < HEIGHT)
    {
        i = x - r;
        k = z - r;
        while (i < dx && dx < WIDTH)
        {
            if ((j - y) * (j - y) + (i - x) * (i - x) + (k - z) * (k - z) < r * r)
                image_pixel_put(win_dis, i, j, TRGB_GREEN + TRGB_BLUE);
            i++;
            k++;
        }
        hit = did_it_hit(i, j, k, r);
        if (hit >= 2)
            image_pixel_put(win_dis, i, j, TRGB_WHITE);
        if (hit == 0)
            image_pixel_put(win_dis, i, j, TRGB_GREEN + TRGB_BLUE + TRGB_WHITE);
        else
            image_pixel_put(win_dis, i, j, TRGB_GREEN + TRGB_BLUE + TRGB_BLACK);
        j++;
    }
    mlx_put_image_to_window (win_dis->mlx_ptr, win_dis->win_ptr, \
        win_dis->img_ptr, 0, 0);
}

// eps = corrige la deviance de la ligne
void   ft_draw_line(t_line *line, t_scene *win_dis)
{
    //    t_gradient      grad;
    int     x;
    int     y;
    int     dx;
    int     dy;
    int     eps;
    dx = line->x2 - line->x1;
    dy = line->y2 - line->y1;
    eps = 0;
    y = line->y1;
    x = line->x1;
    while (x <= line->x2)
    {
            image_pixel_put(win_dis, x, y, TRGB_WHITE);
            x++;
            eps += dy;
            if ((eps << 1) >= dx)
            {
                    y++;
                    eps -= dx;
            }
    }
    mlx_put_image_to_window (win_dis->mlx_ptr, win_dis->win_ptr, \
            win_dis->img_ptr, 0, 0);
}

void   draw_rect(t_rect *rect, t_scene *win_dis)
{
    int     i;
    int     j;
    i = 0;
    j = 0;
    while (i < rect->side_h && rect->y < HEIGHT)
    {
            j = 0 ;
            while (j < rect->side_w && rect->x < WIDTH)
            {
                image_pixel_put(win_dis, (j + rect->x), (i + rect->y), rect->color);
                j++;
            }
            i++;
    }
    image_pixel_put(win_dis, rect->x, rect->y, TRGB_RED + TRGB_BLUE);
}
