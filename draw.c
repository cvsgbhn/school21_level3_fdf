# include "fdf.h"

void       bresenham_draw_line(int x, int y, int x1, int y1, fdf_map *map_info)
{
    float   x_step;
    float   y_step;
    int     max;

    x_step = x1 - x;
    y_step = y1 -y;
    while((int)(x - x1) || (int)(y - y1))
    {
       // put every created pixel ti image
    }
    max = MAX(MOD(x_step), MOD(y_step));
    x_step =/ max;
    y_step =/ max;
}

int		count_index(int row, int col, int depth)
{
    return (row * depth + col);
}

void    put_pix_in_img(fdf_img *img, float x, float y, int color)
{
    if(x >= 0 && x <= 1000 && y >= 0 && y <= 1000)
        *(int *)(img->img_ptr + (int)count_index(x, y, 1000) * img->bits) = color;
}

void		img_clean(fdf_img *img)
{
    ft_bzero(img->img_ptr, 1000 * 1000 * img->bits);
}

void    create_image(fdf_map *info)
{
    fdf_img *img;

    img = &info->image;
    img->img_ptr = mlx_new_image(img->mlx_ptr, img->width, img->height);
    img->img_data = mlx_get_data_addr(img->img_ptr, img->bits, img->lsize, img->endian);
    bits /= 8;
    if (img->img_data)
    {
        ft_putendl("error");
    }
}
