/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:35:12 by roglopes          #+#    #+#             */
/*   Updated: 2024/01/25 16:20:37 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/mini_talk_bonus.h"

int	g_confirmation_received;

void	ft_send_signal(int pid, unsigned char c)
{
	unsigned char	bit;
	int				index;

	index = 8;
	while (index > 0)
	{
		g_confirmation_received = 0;
		index--;
		bit = c >> index;
		if (bit % 2 == 1)
		{
			kill(pid, SIGUSR1);
			while (g_confirmation_received == 0)
				;
		}
		else
		{
			kill(pid, SIGUSR2);
			while (g_confirmation_received == 0)
				;
		}
	}
}

void	ft_receive_signal(int signal, siginfo_t *info, void *context)
{
	int	pid;
	int	sig1;
	int	sig2;

	sig1 = 1;
	sig2 = 0;
	(void)context;
	pid = info->si_pid;
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		g_confirmation_received = 1;
		if (signal == SIGUSR1)
			ft_printf("Signal received from server: %d\n", sig1);
		if (signal == SIGUSR2)
			ft_printf("Signal received from server: %d\n", sig2);
	}
	else
		exit(ft_printf("Error: Invalid signal received\n"));
}

void	ft_check_parameters(int argc, char *argv[])
{
	int	index;

	index = 0;
	if (argc != 3)
		exit(ft_printf("Error: number of arguments invalid\n"));
	while (argv[1][index] != '\0')
	{
		if (!ft_isdigit(argv[1][index]))
			exit(ft_printf("Error: Invalid PID\n"));
		index++;
	}
}

void	ft_main_client(int argc, char *argv[])
{
	struct sigaction	action;
	sigset_t			set;
	int					pid;
	int					index;

	index = 0;
	ft_check_parameters(argc, argv);
	sigemptyset(&set);
	action.sa_handler = NULL;
	action.sa_mask = set;
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_receive_signal;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = ft_atoi(argv[1]);
	while (argv[2][index] != '\0')
	{
		ft_send_signal(pid, argv[2][index]);
		index++;
	}
	g_confirmation_received = 0;
}

int	main(int argc, char *argv[])
{
	ft_main_client(argc, argv);
}
