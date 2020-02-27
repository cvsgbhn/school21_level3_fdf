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
	int		    *img_data;
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
	int			height;
	int			width;
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_img		*image;
}				t_env;

/*
** init.c
*/
t_img		*init_img(t_img *i, t_env *env);
t_img		*ft_update_img(t_env *env);
void	start_window(t_env *env);
t_env		*init_env(t_env *all);
void		start_env(t_env *all);

/*
** read.c
*/
void    fill_line(int *map_line, char *fd_line);
void    fill_matrix(t_env *chr_map, char *file);
void    int_arr_transformation(char *file, t_env *initial);
int     get_width(char *file);
int     get_height(char *file);
int    read_from_file(t_env *actual_map, char *file);


/*
** key.c

void				ft_key_size(int key, t_env *all);
int					ft_key_catch(int key, t_env *all);
*/
/*
** print.c
*/
void		ft_error(char *name, char *msg);
void	put_pix_to_img(t_env *env, t_p p);
t_p		*new_point(int x, int y, t_env *env);
void	bresenham_draw_line(t_p st, t_p fi, t_env *env);
void	draw(t_env *env);

#endif
