#ifndef SCHOOL21_LEVEL3_FDF_FDF_H
#define SCHOOL21_LEVEL3_FDF_FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
#define MAX(a,b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

typedef struct  image
{
    void        *img_ptr;
    void        *img_data;

    int         bits;
    int         lsize;
    int         endian;
}               fdf_img;

typedef struct  input
{
    int         height;
    int         width;
    int         **map;

    void        *mlx_ptr;
    void        *win_ptr;
    fdf_img     image;
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

#endif //SCHOOL21_LEVEL3_FDF_FDF_H
