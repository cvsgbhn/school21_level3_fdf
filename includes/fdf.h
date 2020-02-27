#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>

# define WIDTH 1200
# define HEIGHT 1000
# define FDF_ABS(a) ((a < 0) ? -a : a)

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}				t_p;

typedef struct	s_image
{
	void		*img_ptr;
	void		*img_data;
	int			bits;
	int			linesize;
	int			endian;
}				t_img;

typedef struct	s_map
{
	int			**map_arr;
}				t_map;


typedef struct	s_env
{
	int			row_num;
	int			col_num;
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_img		*image;
}				t_env;

/*
** init.c
*/
t_image				*init_img(t_image *i, t_window *w);
t_image				*ft_update_img(t_image *i, t_window *w);
t_window			*start_window(t_window *w);
t_env				*init_env(t_env *all);
void				start_env(t_env *all);

/*
** read.c
*/
void    fill_line(int *map_line, char *fd_line);
void    fill_matrix(t_env *chr_map, char *file);
void    int_arr_transformation(char *file, t_env *initial);
int     get_width(char *file);
int     get_height(char *file);
void    read_from_file(t_env *actual_map, char *file);


/*
** key.c
*/
void				ft_key_size(int key, t_env *all);
int					ft_key_catch(int key, t_env *all);

/*
** print.c
*/
void				ft_print_info(t_window *w, t_image *i);
void				ft_line(t_env *all, int x0, int y0);
void				ft_redraw(t_env *all, t_map *m, t_image *i, t_window *w);
void				ft_error(char *name, char *msg);

#endif
