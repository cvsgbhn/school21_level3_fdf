#include "../includes/fdf.h"

t_map		*ft_parse_line(t_map *m, int h)
{
	int		i;

	m->o3d = malloc(sizeof(int *) * m->map_h * 10);
	m->o2d = malloc(sizeof(t_point *) * m->map_h * 10);
	m->rd = m->ptr;
	printf("%s\n", "parse line");
	while (m->rd)
	{
        printf("%s\n", "YAYYAYYAY");
		i = 0;
		m->line = ft_strsplit(m->rd->data, ' ');
        printf("%s\n", "YAYYAYUWUWUWUWUWUWUWU");
		while (m->line[i])
			i++;

		m->map_w = (i == 0) ? m->map_w : i;
		m->o3d[h] = malloc(sizeof(int) * m->map_w);
		m->o2d[h] = malloc(sizeof(t_point) * m->map_w);
		i = 0;
		printf("%s\n", "parse line 2");
		while (m->line[i])
		{
			m->o3d[h][i] = ft_atoi(m->line[i]);
			i++;
		}
		printf("%s\n", "YAY");
		h++;
		m->rd = m->rd->next;
        printf("%s\n", "YAYYAY");
	}
	printf("%s\n", "end line parsing");
	return (m);
}

t_map		*ft_parse_file(t_map *m, char **av)
{
	int		h;

	if ((m = (t_map *)ft_memalloc(sizeof(t_map))))
	{
		if ((m->fd = open(av[1], O_RDONLY)) == -1)
			return (0);
		h = 0;
		m->rd = malloc(sizeof(m->rd));
		m->rd->next = NULL;
		m->ptr = m->rd;
		while (get_next_line(m->fd, &(m->rd->data)) > 0)
		{
		    printf("%s\n", "gnled");
			m->rd->next = malloc(sizeof(m->rd));
			m->rd = m->rd->next;
			m->rd->next = NULL;
			m->map_h++;
		}
		printf("%s\n", "after all parsed");
		m = ft_parse_line(m, h);
		printf("%s\n", "line parsed");
		m->rd = m->ptr;
	}
	printf("%s\n", "file parsed");
	return (m);
}
