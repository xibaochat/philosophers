/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <pnielly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:39:07 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/13 16:39:08 by xinwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		pilo_process(t_phi *phi)
{
	int		i;
	t_phi	*tmp;

	i = -1;
	tmp = phi;
	phi->simu->start_time = get_actual_time();
	while (phi && ++i < phi->simu->nb_p)
	{
		if (!(i % 2))
			init_process(phi, i);
		usleep(70);
		phi = phi->next;
	}
	i = -1;
	phi = tmp;
	while (phi && ++i < phi->simu->nb_p)
	{
		if (i % 2)
			init_process(phi, i);
		usleep(70);
		phi = phi->next;
	}
}

void		kill_philo(t_phi *phi)
{
	int	i;

	i = -1;
	while (++i < phi->simu->nb_p)
		kill(phi->simu->pid[i], SIGKILL);
}

void		track_child(t_phi *phi)
{
	int				status;
	int				status_value;
	int				i;

	i = -1;
	while (++i < phi->simu->nb_p)
	{
		waitpid(-1, &status, 0);
		if ((WIFEXITED(status) || WIFSIGNALED(status)))
		{
			status_value = WEXITSTATUS(status);
			if (status_value == 0)
			{
				i = -1;
				while (++i < phi->simu->nb_p)
					kill(phi->simu->pid[i], SIGKILL);
				sem_post(phi->simu->display);
				return ;
			}
		}
	}
	printf("All meals eaten\n");
}

int			main(int ac, char **av)
{
	int			err_input;
	t_phi		*phi;
	t_simu		*simu;

	err_input = valid_input(ac, av);
	if (err_input)
		return (1);
	simu = init_simu(av);
	if (!simu)
		return (1);
	phi = init_phi_node(simu);
	if (!phi)
		return (1);
	show_welcome_message();
	pilo_process(phi);
	track_child(phi);
	ft_free_var(phi);
	return (0);
}
