/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:40:44 by mbehhar           #+#    #+#             */
/*   Updated: 2021/12/26 18:48:00 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

void	client_sig_handler(int signal, siginfo_t *info, void *uc)
{
	(void) *uc;
	(void) *info;
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("\033[0;37m\e[1mMessage Received\n", 1);
		exit(0);
	}
}

void	bitshift_char(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(150);
	}
}

int	main(int ac, char **av)
{
	size_t				i;
	int					pid;
	struct sigaction	action;

	action.sa_sigaction = client_sig_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	pid = ft_atoi(av[1]);
	i = -1;
	if (!ac)
		return (0);
	while (++i <= ft_strlen(av[2]))
	{
		bitshift_char(av[2][i], pid);
		usleep(150);
	}
	while (1)
		usleep(5000);
}
