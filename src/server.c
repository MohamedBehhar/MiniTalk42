/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:40:48 by mbehhar           #+#    #+#             */
/*   Updated: 2021/12/26 18:54:43 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

void	ft_incr_variables(int *pow_count, int *sig_count)
{
	(*pow_count)++;
	(*sig_count)++;
}

void	ft_handle_variables(char *c, int *pow_count, int *sig_count, int n)
{
	if (n == 0)
	{
		(*c) = 0;
		(*pow_count) = 0;
		(*sig_count) = 0;
	}
	if (n == 1)
	{
		(*c) += ft_power(2, *pow_count);
		(*pow_count)++;
		*sig_count = 0;
	}
}

void	server_sig_handler(int signal, siginfo_t *info, void *uc)
{
	static char	c;
	static int	pow_count;
	static int	sig_count;
	static int	new_pid;

	(void) *uc;
	(void) *info;
	if (new_pid != info->si_pid && pow_count != 0)
		ft_handle_variables(&c, &pow_count, &sig_count, 0);
	if (signal == SIGUSR1)
		ft_handle_variables(&c, &pow_count, &sig_count, 1);
	else if (signal == SIGUSR2)
		ft_incr_variables(&pow_count, &sig_count);
	if (pow_count == 8 && sig_count < 8)
	{
		ft_putchar_fd(c, 1);
		ft_handle_variables(&c, &pow_count, &sig_count, 0);
	}
	if (sig_count == 8)
	{
		kill(info->si_pid, SIGUSR1);
		ft_handle_variables(&c, &pow_count, &sig_count, 0);
	}
	new_pid = info->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	action.sa_sigaction = server_sig_handler;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("id = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		usleep(5000);
}
