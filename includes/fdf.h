#ifndef SCHOOL21_LEVEL3_FDF_FDF_H
#define SCHOOL21_LEVEL3_FDF_FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
#define MAX(a,b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)
#define ONE(a, b) ((a < b) ? 1 : -1)
#define WIN_WID 1000
#define WIN_HGT 1000
#define WHITE 0xFFFFFF
#define SPRING_GREEN 0xFF7F
#define TOMATO 0xFF6347
#define SKYBLUE 0x87CEFF

typedef struct  s_point
{
    int         x;
    int         y;
    int         z;
    int         color;
}               point;

typedef struct  s_image
{
    void        *img_ptr;
    char        *img_data;

    int         bits;
    int         lsize;
    int         endian;
}               fdf_img;

typedef struct  s_input
{
    int         height;
    int         width;
    int         **map;

    void        *mlx_ptr;
    void        *win_ptr;
    fdf_img     *image;
}               fdf_map;

/*
** read_map_from_file.c
*/
void    fill_line(int *map_line, char *fd_line);
void    fill_matrix(fdf_map *chr_map, char *file);
int     get_height(char *file);
int     get_width(char *file);
void    int_arr_transformation(char *file, fdf_map *initial);
void    read_from_file(fdf_map *actual_map, char *file);

/*
** draw.c
*/
void    draw_image(fdf_map *fmap);
void    bresenham_draw_line(point start, point fi, fdf_map *map_info);

/*
** point_utils.c
*/
point    *to_point(int x, int y, fdf_map *fmap);

/*
** image_utils.c
*/
void    put_pix_in_img(fdf_img *img, float x, float y, int color);
void		img_clean(fdf_img *img);
void    create_image(fdf_map *info);
#endif //SCHOOL21_LEVEL3_FDF_FDF_H
