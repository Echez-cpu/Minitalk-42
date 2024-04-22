/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:46:55 by pokpalae          #+#    #+#             */
/*   Updated: 2024/04/22 17:13:05 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	signl_handler(int signl, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (signl == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sig;
	struct sigaction	*sig_ptr;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./server\n");
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for a message...\n");
	sig.sa_sigaction = signl_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig_ptr = &sig;
	while (argc == 1)
	{
		sigaction(SIGUSR1, sig_ptr, ((void *)0));
		sigaction(SIGUSR2, sig_ptr, ((void *)0));
		pause();
	}
	return (0);
}
