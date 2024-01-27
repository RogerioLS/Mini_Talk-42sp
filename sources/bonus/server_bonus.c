/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:01:56 by roglopes          #+#    #+#             */
/*   Updated: 2024/01/25 14:57:13 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/mini_talk_bonus.h"

void	ft_receive_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character;
	static int				index;

	(void)context;
	if (signal == SIGUSR1)
		character |= 1;
	index++;
	if (index == 8)
	{
		write(1, &character, 1);
		index = 0;
		character = 0;
	}
	character = character << 1;
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

void	ft_main_server(void)
{
	struct sigaction	lead;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	lead.sa_handler = NULL;
	lead.sa_mask = set;
	lead.sa_flags = SA_SIGINFO;
	lead.sa_sigaction = ft_receive_signal;
	sigaction(SIGUSR1, &lead, NULL);
	sigaction(SIGUSR2, &lead, NULL);
	ft_putstr_fd("Server PID: [", 1);
	ft_printf("%d", getpid());
	ft_putstr_fd("]\n", 1);
	while (1)
		pause();
}

int	main(void)
{
	ft_main_server();
}
