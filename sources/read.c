#include "../includes/fdf.h"

/*
** write one line of map to matrix
*/
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

/*
** read map file line by line
*/
void    fill_matrix(t_env *chr_map, char *file)
{
    int     fd;
    int     tik;
    char    *line;

    fd = open(file, O_RDONLY);
    tik = 0;
    while(get_next_line(fd, &line))
    {
        fill_line(chr_map->fmap->map[tik], line);
        tik++;
        free(line);
    }
}

/*
** writing map to int** array
*/
void    int_arr_transformation(char *file, t_env *initial)
{
    int     tik;

    initial->map = (t_map *)malloc(sizeof(t_map));
    initial->map->map_arr = (int **)malloc(sizeof(int*) * initial->row_num);
    tik = 0;
    while(tik < initial->fmap->height)
    {
        initial->fmap->map[tik] = (int *)malloc(sizeof(int) * initial->fmap->width);
        tik++;
    }
   fill_matrix(initial, file);
}

/*
** read file and count width of a map
*/
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

/*
** read file and count height of a map
*/
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

/*
** reading from file "manager"
*/
void    read_from_file(t_env *actual_map, char *file)
{
    actual_map->row_num = get_height(file);
    actual_map->col_nums = get_width(file);
    int_arr_transformation(file, actual_map);
}
