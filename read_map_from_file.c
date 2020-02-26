#include "fdf.h"

void    fill_line(int *map_line, char *fd_line)
{
    char    **int_line;
    int     tik;

    int_line = ft_strsplit(fd_line, ' ');
    tik = 0;
    while (int_line[tik])
    {
        map_line[tik] = ft_atoi(int_line[tik]);
        tik++;
    }
}

void    fill_matrix(fdf_map *chr_map, char *file)
{
    int     fd;
    int     tik;
    char    *line;

    fd = open(file, O_RDONLY);
    tik = 0;
    while(get_next_line(fd, &line))
    {
        fill_line(chr_map->map[tik], line);
        tik++;
        free(line);
    }
}

void    int_arr_transformation(char *file, fdf_map *initial)
{
    int     tik;

    initial->map = (int **)malloc(sizeof(int*) * initial->height);
    tik = 0;
    while(tik < initial->height)
    {
        initial->map[tik] = (int *)malloc(sizeof(int) * initial->width);
        tik++;
    }
   fill_matrix(initial, file);
}

int     get_width(char *file)
{
    int     fd;
    int     width;
    char    *line;

    fd = open(file, O_RDONLY);
    get_next_line(fd, &line);
    width = ft_count_words(line, ' ');
    free(line);
    close(fd);
    return (width);
}

int     get_height(char *file)
{
    int     fd;
    int     height;
    char    *line;

    fd = open(file, O_RDONLY);
    height = 0;
    while(get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

void    read_from_file(fdf_map *actual_map, char *file)
{
    actual_map->height = get_height(file);
    actual_map->width = get_width(file);
    int_arr_transformation(file, actual_map);
}
