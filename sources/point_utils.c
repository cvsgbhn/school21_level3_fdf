#include "../includes/fdf.h"

point    *to_point(int x, int y, fdf_map *fmap)
{
    point   *new;

    new = (point *)malloc(sizeof(point));
    new->x = x;
    new->y = y;
    new->z = fmap->map[x][y];
    new->color = SPRING_GREEN;
    return (new);
}