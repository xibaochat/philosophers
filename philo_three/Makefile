NAME = philo_three

SRC =	init_simu.c main.c init_phi.c \
		input_validation.c util.c time.c show_message.c \
		job.c job_action.c monitoring.c \
		free_var.c ft_strjoin.c ft_itoa.c \
		init_process.c


#CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all:
	@gcc -g  $(CFLAGS) $(SRC) -c
	@gcc -pthread $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *~
	@/bin/rm -f *#

re: fclean all