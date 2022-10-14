#include "../inc/token.h"

int	is_token(char c)
{
	return (c == '|' \
		   	|| c == '-' \
		   	|| c == '<' \
		   	|| c == '>' \
			|| c == ';');
}

int	next_symbol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_token(str[i]))
			return (i);
		i++;
	}
	return (i);
}
