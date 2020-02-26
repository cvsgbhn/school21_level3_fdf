#include "../includes/fdf.h"

/*
** project coordinate to 2D plane
*/

t_point		project(point p, fdf_map *fdf)
{
    p.x *= fdf->camera->zoom;
    p.y *= fdf->camera->zoom;
    p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
    p.x -= (fdf->map->width * fdf->camera->zoom) / 2;
    p.y -= (fdf->map->height * fdf->camera->zoom) / 2;
    rotate_x(&p.y, &p.z, fdf->camera->alpha);
    rotate_y(&p.x, &p.z, fdf->camera->beta);
    rotate_z(&p.x, &p.y, fdf->camera->gamma);
    if (fdf->camera->projection == ISO)
        iso(&p.x, &p.y, p.z);
    p.x += (WIDTH - MENU_WIDTH) / 2 + fdf->camera->x_offset + MENU_WIDTH;
    p.y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2
           + fdf->camera->y_offset;
    return (p);
}
