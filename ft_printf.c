/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:58 by aes-sarg          #+#    #+#             */
/*   Updated: 2023/11/22 13:30:38 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}
void ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void print_int(int num) {
    if (num < 0) {
        ft_putchar('-');
        num = -num;
    }

    char buffer[20]; 
    int i = 0;
    do {
        buffer[i++] = '0' + num % 10;
        num /= 10;
    } while (num > 0);

    while (--i >= 0) {
        ft_putchar(buffer[i]);
    }
}
int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args,str);
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
				print_int(va_arg(args,int));
			else if (*str == 'c')
				ft_putchar(va_arg(args,int));
			else if (*str == 's')
				ft_putstr(va_arg(args,char *));
			else
				ft_putchar('%');
		}
		else{
			ft_putchar(*str);
		}
		str++;
	}
	va_end(args);
return 0;
}

int main()
{
	char c = 'q';
	int a = 1245421;
	char *s = " Hello ayoub";
	ft_printf("the character:% %c is not exist in this number: %d or in this string: %s ",c,a,s);
	return (0);
}

