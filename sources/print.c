#include "../includes/fdf.h"

void		ft_error(char *name, char *msg)
{
	ft_putstr(name);
	ft_putstr(": ");
	ft_putendl(msg);
	exit(1);
}

void		ft_print_info(t_env *env)
{
	mlx_put_image_to_window(w->mlx, w->win, i->img, 0, 0);
	mlx_string_put(w->mlx, w->win, 20, 20, 0xFFFFFF, "Arrows or WASD to move");
	mlx_string_put(w->mlx, w->win, 20, 40, 0xFFFFFF, "ZX to zoom");
	mlx_string_put(w->mlx, w->win, 20, 60, 0xFFFFFF, "+/- or QE to height");
	mlx_string_put(w->mlx, w->win, 20, 80, 0xFFFFFF, "ESC to quit");
	mlx_string_put(w->mlx, w->win, 20, 100, 0xFFFFFF, "R to reset");
}

void	*put_pix_to_img(t_env *env, t_p p)
{
	int		i;

	if(p.x > 0 && p.x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * env->image->bits / 8) + (y * env->image->linesize);
		env->image->img_data[i] = p.color;
		env->image->img_data[++i] = p.color >> 8;
		env->image->img_data[++i] = p.color >> 16;
	}
}

t_p		*new_point(int x, int y, t_env *env)
{
	t_p		*new;

	new = (t_p *)malloc(sizeof(t_p));
	new->x = x;
	new->y = y;
	new->z = env->map->map_arr[x][y];
	new->color = 0xFAEBD7;
	return (new);
}

void	bresenham_draw_line(t_p st, t_p fi, t_env *env)
{
	t_p		delta;
	t_p		sign;
	t_p		current;
	int		error[2];

	delta.x = FDF_ABS(fi.x - st.x);
	delta.y = FDF_ABS(fi.y - st.y);
	sign.x = st.x > fi.x ? -1 : 1;
	sign.y = st.y > fi.y ? -1 : 1;
	error[0] = delta.x - delta.y;
	current = st;
	while(current.x != fi.x || current.y != fi.y)
	{
		put_pix_to_img();
		if((error[1] = error[0] * 2 > -delta.y))
		{
			error[0] -= delta.y;
			curr.x += sign.x;
		}
		if(error[1] < delta.x)
		{
			error[0] += delta.x;
			curr.y += sign.y;
		}
	}
}

void	*draw(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while(y < env->row_num)
	{
		x = 0;
		while(x < env->col_num)
		{
			if (x != env->row_num - 1)
				bresenham_draw_line(new_point(x ,y, env), new_point(x + 1, y, env), env);
			if (y != env->col_num - 1)
				bresenham_draw_line(new_point(x, y, env), new_point(x, y + 1, env), env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->image->img_ptr, 0, 0);
}