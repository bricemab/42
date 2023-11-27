/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:52:01 by bmabilla          #+#    #+#             */
/*   Updated: 2023/11/22 15:58:04 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, char *str)
{
	unsigned char	c;
	int				bits;

	while (*str)
	{
		c = *str;
		bits = 8;
		while (bits--)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		str++;
	}
}

void	client_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	ft_printf("Char has been receive\n");
}

int	main(int ac, char **args)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = client_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR2, &sigact, NULL) == -1)
		ft_printf("Failed on SIGUSR2");
	if (ac != 3 || !ft_atoi(args[1]))
		return (1);
	send_msg(ft_atoi(args[1]), args[2]);
}
