#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
#include <signal.h>

int ft_binary(int pid, char c);
void signal_handlers(int signal, siginfo_t *info, void *context);
void ft_dist(char *str, int pid);
int G_SIGNAL;
void ft_cheker(int sig);
#endif