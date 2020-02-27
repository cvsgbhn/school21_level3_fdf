#include "../includes/fdf.h"

t_img		*init_img(t_img *i, t_env *env)
{
	if ((i = (t_img *)ft_memalloc(sizeof(t_img))))
	{
		i->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
		//i->rot_y = 10;
		//i->rot_x = 10;
		//i->image_z = -3;
		//i->step = 30;
		i->img_data = mlx_get_data_addr(i->img_ptr, &(i->bits), &(i->linesize), &(i->endian));
	}
	return (i);
}

t_img		*ft_update_img(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	env->image->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->image->img_data = mlx_get_data_addr(i->img_ptr, &(i->bits), &(i->linesize), &(i->endian));
	if (i == NULL)
		ft_error("fdf", "Can`t update image");
	return (i);
}

void	start_window(t_env *env)
{
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(w->mlx, w->WIDTH, w->HEIGHT, "FDF");
}

t_env		*init_env(t_env *all)
{
    printf("%s\n", "init env");
	if ((all = (t_env *)ft_memalloc(sizeof(t_env))))
	{
		all->col_num = 0;
		all->row_num = 0;
		all->image = NULL;
		all->map = NULL;
		all->mlx_ptr = NULL;
		all->win_ptr = NULL;
	}
	return (all);
}

void		start_env(t_env *all)
{
    printf("%s\n", "start env");
	all->win_ptr= start_window(all);
	printf("%s\n", "started window");
	if ((all->image = init_img(all->image, all->win_ptr)) == NULL)
		ft_error("fdf", "Can`t INIT IMAGE");
	ft_redraw(all, all->map, all->image, all->win_ptr);
	printf("%s\n", "after redraw");
	mlx_hook(all->win_ptr->win, 2, 0, ft_key_catch, all);
	mlx_loop(all->mlx_ptr);
}
