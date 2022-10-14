#include "../inc/utils.h"

int	ft_strlen(char *str)
{
	int	i;/*{{{*/

	i = 0;
	while (str[i])
		i++;
	return (i);/*}}}*/
}

char	*ft_strcpy(char *dst, char *str)
{
	int	i;/*{{{*/

	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);/*}}}*/
}

char	*ft_strchr(char *str, char c)
{
	int	i;/*{{{*/

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i + 1);
		i++;
	}
	return (NULL);/*}}}*/
}

char	*ft_substr(char *str, int s, int e)
{
	char	*ret;/*{{{*/
	int		i;

	i = 0;
	ret = malloc(e - s + 1);
	while (i + s < e)
	{
		ret[i] = str[i + s];
		i++;
	}
	ret[i] = 0;
	return (ret);/*}}}*/
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] == str2[i])
			i++;
		else
			return (str[i] - str2[i]);
	}
	return (str[i] - str2[i]);
}
