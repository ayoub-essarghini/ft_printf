#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putnbr_u(unsigned int nb);
int	ft_put_p(unsigned long nbr, char *base);
int	ft_printf(const char *str, ...);
int	ft_strlen(char *s);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int nb);

#endif