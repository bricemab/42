/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:55:14 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/22 15:33:13 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit = 7;
	static int	c = 0;

	(void)context;
	if (signum == SIGUSR1)
		c += 1 << bit;
	if (signum == SIGUSR2)
		c += 0 << bit;
	bit--;
	if (bit == -1)
	{
		bit = 7;
		ft_printf("%c", c);
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_printf("Failed on responding client on SIGUSR2");
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = server_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		if (sigaction(SIGUSR1, &sigact, NULL) == -1)
			ft_printf("Failed on SIGUSR1");
		if (sigaction(SIGUSR2, &sigact, NULL) == -1)
			ft_printf("Failed on SIGUSR2");
		pause();
	}
	return (1);
}
