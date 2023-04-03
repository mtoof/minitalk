/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepehr <sepehr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:56:49 by mtoof             #+#    #+#             */
/*   Updated: 2023/02/17 20:45:06 by sepehr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_check(char *ptr, siginfo_t *info)
{
	kill(info->si_pid, SIGUSR2);
	ft_printf("%s\n", ptr);
	ptr = NULL;
	return (ptr);
}

void	ft_receive_char(int signal, siginfo_t *info, void *s)
{
	static char	bit;
	static char	c;
	static char	*ptr;
	char		*tmp;

	(void)s;
	if (!ptr)
		ptr = ft_calloc(1, sizeof(char));
	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			ptr = ft_check(ptr, info);
		tmp = ft_strjoin(ptr, &c);
		free(ptr);
		ptr = tmp;
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("Server pid is : %d\n", pid);
	act.sa_sigaction = ft_receive_char;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
