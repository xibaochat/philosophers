# COLOR
GREEN       = \033[33;32m
YELLOW      = \033[33;33m
RED         = \033[33;31m
WHITE       = \033[33;37m
MAGENTA     = \e[95m

ARC_RED     = \e[41m
ARC_ORANGE  = \e[101m
ARC_YELLOW  = \e[43m
ARC_GREEN   = \e[102m
ARC_BLUE    = \e[44m
ARC_MAGENTA = \e[45m
ARC_NC      = \e[49m

F_STATUS_0 = | xargs sh -c 'printf "$(GREEN)喜$(YELLOW)喜$(RED)喜 $(WHITE)$$0 $$1:    \t"'
F_STATUS_1 = echo "$(GREEN)DONE 喜$(YELLOW)喜$(RED)喜"

NAME = philo_three

SRC =	init_simu.c main.c init_phi.c \
		input_validation.c util.c time.c show_message.c \
		job.c job_action.c monitoring.c \
		free_var.c ft_strjoin.c ft_itoa.c \
		init_process.c show_welcom.c


CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: nyancat
	@gcc -g  $(CFLAGS) $(SRC) -c
	@gcc -pthread $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *~
	@/bin/rm -f *#

re: fclean all

nyancat:
	@ echo "$(MAGENTA)                             "
	@ clear
	@ echo "          ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄         "
	@ echo "        ▄▀░░░░░░░░░░░░▄░░░░░░░▀▄       "
	@ echo "        █░░▄░░░░▄░░░░░░░░░░░░░░█       "
	@ echo "$(ARC_RED)        $(ARC_NC)█░░░░░░░░░░░░▄█▄▄░░▄░░░█ ▄▄▄   "
	@ echo "$(ARC_ORANGE) ▄▄▄▄▄  $(ARC_NC)█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██  "
	@ echo "$(ARC_YELLOW) $(ARC_NC)██▄▀██$(ARC_YELLOW)▄$(ARC_NC)█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██  "
	@ echo "$(ARC_GREEN)  ▀$(ARC_NC)██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██ "
	@ echo "$(ARC_BLUE)    ▀$(ARC_NC)████░▀░░░░▄░░░██░░░$(GREEN)▄█$(MAGENTA)░░░░▄░$(GREEN)▄█$(MAGENTA)░░██ "
	@ echo "$(ARGC_MAGENTA)       ▀$(ARC_NC)█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██ "
	@ echo "       ▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀  "
	@ echo "      █▀▀█████████▀▀▀▀████████████▀    "
	@ echo "      ████▀   ███▀      ▀███  ▀██▀     "
	@ echo "\n       ♥♥♥  Maobe's Makefile  ♥♥♥\n"
