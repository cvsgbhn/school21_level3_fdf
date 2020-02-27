#include "../includes/fdf.h"

void		ft_error(char *name, char *msg)
{
	ft_putstr(name);
	ft_putstr(": ");
	ft_putendl(msg);
	exit(1);
}

/*void		ft_print_info(t_env *env)
{
	mlx_put_image_to_window(w->mlx, w->win, i->img, 0, 0);
	mlx_string_put(w->mlx, w->win, 20, 20, 0xFFFFFF, "Arrows or WASD to move");
	mlx_string_put(w->mlx, w->win, 20, 40, 0xFFFFFF, "ZX to zoom");
	mlx_string_put(w->mlx, w->win, 20, 60, 0xFFFFFF, "+/- or QE to height");
	mlx_string_put(w->mlx, w->win, 20, 80, 0xFFFFFF, "ESC to quit");
	mlx_string_put(w->mlx, w->win, 20, 100, 0xFFFFFF, "R to reset");
}*/

void	put_pix_to_img(t_env *env, t_p p)
{
	int		i;

	if(p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
	{
		i = (p.x * env->image->bits / 8) + (p.y * env->image->linesize);
		if(p.z == 0)
            env->image->img_data[i] = 0xFFFFFF;
		else
            env->image->img_data[i] = 0x87CEEB;
		printf("%s\n", "putpix");
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
	printf("%d %d %d %d %d\n", delta.x, delta.y, sign.x, sign.y, error[0]);
	current = st;
	while(current.x != fi.x || current.y != fi.y)
	{
		put_pix_to_img(env, current);
		if((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			current.x += sign.x;
            printf("%s %d\n", "current x", current.x);
		}
		if(error[1] < delta.x)
		{
			error[0] += delta.x;
			current.y += sign.y;
            printf("%s %d\n", "current y", current.y);
		}
	}
    put_pix_to_img(env, current);
}

void	draw(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while(x < env->row_num)
	{
		y = 0;
		printf("%s %d\n", "Y", y);
		while(y < env->col_num)
		{
		    printf("%s\n", "drawing actions");
			if (x != env->row_num - 1)
				bresenham_draw_line(*new_point(x ,y, env), *new_point(x + 1, y, env), env);
			if (y != env->col_num - 1)
				bresenham_draw_line(*new_point(x, y, env), *new_point(x, y + 1, env), env);
			y++;
            printf("%s %d\n", "X", x);
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->image->img_ptr, 0, 0);
}