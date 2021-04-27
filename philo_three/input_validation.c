/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_var_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <pnielly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:39:07 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/13 16:39:08 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	show_err_message(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, WARNING_MESSAGE, ft_strlen(WARNING_MESSAGE));
	write(2, ARG1, ft_strlen(ARG1));
	write(2, ARG2, ft_strlen(ARG2));
	write(2, ARG3, ft_strlen(ARG3));
	write(2, ARG4, ft_strlen(ARG4));
}

int		option_is_less_zero(char *s)
{
	if (s)
	{
		if (ft_atoi(s) <= 0)
		{
			printf(MES_MUST_EAT);
			printf("Invalid argument\n");
			return (1);
		}
	}
	return (0);
}

int		has_invalid_char(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				show_err_message("Input contains invalid char\n");
				return (1);
			}
			j++;
		}
	}
	return (0);
}

int		valid_input(int ac, char **av)
{
	int	v;

	if (!(ac == 5 || ac == 6))
	{
		show_err_message("Input is incomplete\n");
		return (1);
	}
	if (av[1] && av[1][0] == 48)
	{
		show_err_message("Nb of pilosophers should be more than 0\n");
		return (1);
	}
	v = has_invalid_char(av);
	if (v)
		return (1);
	if (option_is_less_zero(av[ac - 1]))
		return (1);
	return (0);
}
