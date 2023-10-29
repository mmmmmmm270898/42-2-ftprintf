// goal of this is to convert integer to_hex to a Hexadecimal number
// if the type is x it will do it with lowercase numbers
// if the type is X it will do it with uppercase numbers

// the function returns the total amount of "written" characters

#include "ft_printf.h"
#include "libft.h"

int	ft_hex_len(long	long num)
{
	unsigned long	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_handle_x(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_handle_x(num / 16, format);
		ft_handle_x(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_handle_x(num, format);
	return (ft_hex_len(num));
}
