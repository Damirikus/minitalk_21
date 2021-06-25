#include "minitalk.h"


int main(int argc, char **argv)
{
	int pid;
	int i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 1)
		{
			i = 0;
			while (argv[2][i])
			{
				ft_binary(pid, argv[2][i]);
				i++;
			}
			ft_binary(pid, '\n');
		}
		else
			ft_putstr_fd("server not found\n", 2);
	}
	else
		printf("./client [PID] [messege]\n");
	return (0);
}

//PID > 1	Сигнал посылается процессу с соответствующим PID.
//PID == 0	Сигнал посылается всем процессам из той же группы что и процесс-источник.
//PID < 0	Сигнал посылается всем процессам, чей идентификатор группы равен абсолютному значению PID.
//PID == 1	Сигнал посылается всем процессам системы.


int ft_binary(int pid, char c)
{
	int t;
	t = 128;

	while (t >= 1)
	{
		if (c & t)  //сравнивает двоичный код числа t и двоичный код символа
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error", 2);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error", 2);
				exit(1);
			}
		}
		t /= 2;
		usleep(10);
	}
	return 0;
}