/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepehr <sepehr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:56:53 by mtoof             #+#    #+#             */
/*   Updated: 2023/01/28 16:59:06 by sepehr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_confirm(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\033m\nMessage has been delivered! :)\n", 1);
	else
		ft_printf("\033m\nMessage has been delivered! :)\n", 1);
}

void	ft_send_char(pid_t s_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	s_pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		s_pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			signal(SIGUSR1, ft_confirm);
			signal(SIGUSR2, ft_confirm);
			ft_send_char(s_pid, argv[2][i]);
			i++;
		}
		ft_send_char(s_pid, '\0');
	}
	else
	{
		ft_printf("Wrong Arguments !! \n");
		ft_printf("Please try : ./client 'Server PID' 'text to be send'\n");
		return (1);
	}
}
