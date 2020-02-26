# include "../includes/fdf.h"

/*
** Bresenham drawing line implementation
*/
void       bresenham_draw_line(point start, point fi, fdf_map *map_info)
{
   point diff;
   point signed_one;
   point curr_point;
   int      error[2];

   diff.x = MOD(start.x - fi.x);
   diff.y = MOD(start.y - fi.y);
   signed_one.x = ONE(start.x, fi.x);
   signed_one.y = ONE(start.y, fi.y);
   error[0] = diff.x - diff.y;
   curr_point = start;
   while (curr_point.x != fi.x || curr_point.y != fi.y)
   {
       put_pix_in_img(map_info->image, curr_point.x, curr_point.y, SPRING_GREEN);
       if ((error[1] = error[0] * 2) > -diff.y)
       {
           error[0] -= diff.y;
           curr_point.x += signed_one.x;
       }
       if (error[1] < diff.x)
       {
           error[0] += diff.x;
           curr_point.y += signed_one.y;
       }
   }
}

/*
** drawing manager
*/
void    draw_image(fdf_map *fmap)
{
    int     x;
    int     y;
    point   *p_st;
    point   *p_fi;

    y = 0;
    while (y < fmap->height)
    {
        x = 0;
        while (x < fmap->width)
        {
            p_st = to_point(x, y, fmap);
            p_fi = to_point(x + 1, y, fmap);
            bresenham_draw_line(p_st, p_fi, fmap);
            free(p_fi);
            p_fi = to_point(x, y + 1, fmap);
            bresenham_draw_line(p_st, p_fi, fmap);
            free((void *)p_fi);
            free((void *)p_st);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->image.img_ptr, 0, 0);
}