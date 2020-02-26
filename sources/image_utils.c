# include "../includes/fdf.h"

/*
** put pixel into image
*/
void    put_pix_in_img(fdf_img *img, float x, float y, int color)
{
    int     index;

    if(x >= 0 && x <= WIN_WID && y >= 0 && y <= WIN_HGT)
    {
        index = (x * img->bits / 8) + (y * img->lsize);
        img->img_data[index] = color;
    }
}

/*
** clean image (not freeing!) for drawing next image
*/
void		img_clean(fdf_img *img)
{
    ft_bzero(img->img_ptr, 1000 * 1000 * img->bits);
}

/*
** create empty image
*/
void    create_image(fdf_map *info)
{
    fdf_img *img;

    img = (fdf_img *)malloc(sizeof(fdf_img));
    info->image = img;
    img->img_ptr = mlx_new_image(info->mlx_ptr, info->width, info->height);
    img->img_data = mlx_get_data_addr(img->img_ptr, &img->bits, &img->lsize, &img->endian);
    if (!(img->img_data))
    {
        ft_putendl("error");
    }
}
