NAME = philo_one

SRC =	init_fork.c init_simu.c main.c init_phi.c \
		input_validation.c util.c time.c show_message.c \
		job.c get_two_fork.c job_action.c monitoring.c \
		free_var.c


#CFLAGS = -Wall -Wextra -Werror

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
