.PHONY: clean fclean re make all

NAME = fdf
SRCS =  main.c read_map_from_file.c
OBJS = ${SRCS:.c=.o}
HDR = fdf.h
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all