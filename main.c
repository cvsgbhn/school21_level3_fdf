#include "fdf.h"

void    int_array_print(fdf_map *my_map)
{
    int     i;
    int     j;

    i = 0;
    while(i < my_map->height)
    {
        j = 0;
        while(j < my_map->width)
        {
            printf("%3d ", my_map->map[i][j]);
            j++;
        }
        printf("%c", '\n');
        i++;
    }
}

int     deal_key(int key, void *data)
{
    printf("%d\n", key);
    return (0);
}

int     main(int argc, char **argv)
{
    fdf_map     *input_map;

    if (argc < 2)
        return (-1);
    input_map = (fdf_map*)malloc(sizeof(fdf_map));
    read_from_file(input_map, argv[1]);
    int_array_print(input_map);
    input_map->mlx_ptr = mlx_init();
    input_map->win_ptr = mlx_new_window(input_map->mlx_ptr, 1000, 1000, "fdf");
    mlx_key_hook(input_map->win_ptr, deal_key, NULL);
    mlx_loop(input_map->mlx_ptr);

    return (1);
}