PHILO = philo/
BPHILO = philo_bonus/

CC = gcc
CFLAG = -Wall -Werror -Wextra

all: 
	@make -C $(PHILO)
	@make -C $(BPHILO)

clean:
	@make clean -C $(PHILO)
	@make clean -C $(BPHILO)

fclean: clean
	@make fclean -C $(PHILO)
	@make fclean -C $(BPHILO)

re: fclean all clean