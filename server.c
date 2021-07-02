#include "minitalk.h"

void signal_handlers(int signal, siginfo_t *info, void *context)    // делаем статические переменные, так как все в бесконечном цикле
{
	static int i = 0;
	static int count = 128;
	static char out_char = 0;  //символ, который будет собирать все числа из бинарных чисел
    
    (void)context;
	if (signal == SIGUSR1)
	{
		out_char += count;
		count /= 2;
		i++;
	}
	else if (signal == SIGUSR2)
	{
		count /= 2;
		i++;
	}
	if (i == 8) //если собирается байт, все обнуляется
	{
		write(1, &out_char, 1);
		i = 0;
		count = 128;
		out_char = 0;
	}
    // if (i == 0)
    // kill(info->si_pid, SIGUSR1);
    // else 
    kill(info->si_pid, signal);
    // usleep(1);
}


int main()
{

	ft_putnbr_fd(getpid(), 1);       //Печатаем номер процесса
	write(1, "\n", 1);

    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_sigaction = signal_handlers;
  
	// signal(SIGUSR1, signal_handlers);
	// signal(SIGUSR2, signal_handlers);

	while (1) {    
    sigaction(SIGUSR1, &act, 0);
    sigaction(SIGUSR2, &act, 0);
        pause();
        usleep(1);
	}
}