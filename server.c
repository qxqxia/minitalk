/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:57:13 by qxia              #+#    #+#             */
/*   Updated: 2022/02/10 17:07:25 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sig(int sig)
{
	static unsigned int		i;
	static unsigned char	c;

	i = 0;
	c = 0;
	if (sig == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid == -1)
		return (1);
	if (pid == 0)
		sleep (5);
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	ft_putstr("pid:");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
