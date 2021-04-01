NAME = philo_one

SRC =  main.c init_fork.c  init_phi.c  util.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all:
	@gcc $(CFLAGS) $(SRC) -c
	@gcc -pthread $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *~
	@/bin/rm -f *#

re: fclean all
