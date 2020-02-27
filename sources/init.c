#include "../includes/fdf.h"

t_img		*init_img(t_img *i, t_env *env)
{
	if ((i = (t_img *)ft_memalloc(sizeof(t_img))))
	{
		i->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
		printf("%s\n", "created mlx_ptr");
		//i->rot_y = 10;
		//i->rot_x = 10;
		//i->image_z = -3;
		//i->step = 30;
		i->img_data = (int *)mlx_get_data_addr(i->img_ptr, &(i->bits), &(i->linesize), &(i->endian));
	}
	printf("%s\n", "ft init_img");
	return (i);
}

t_img		*ft_update_img(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	env->image->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->image->img_data = (int *)mlx_get_data_addr(env->image->img_ptr, &(env->image->bits), &(env->image->linesize), &(env->image->endian));
	if (env->image == NULL)
		ft_error("fdf", "Can`t update image");
	return (env->image);
}

void	start_window(t_env *env)
{
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "FDF");
}

t_env		*init_env(t_env *all)
{
    printf("%s\n", "init env");
	if ((all = (t_env *)ft_memalloc(sizeof(t_env))))
	{
		all->width = 0;
		all->height = 0;
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
	start_window(all);
	printf("%s\n", "started window");
	if ((all->image = init_img(all->image, all)) == NULL)
		ft_error("fdf", "Can`t INIT IMAGE");
	printf("%s\n", "image created");
	draw(all);
	printf("%s\n", "after redraw");
	//mlx_hook(all->win_ptr, 2, 0, ft_key_catch, all);
	mlx_loop(all->mlx_ptr);
}
