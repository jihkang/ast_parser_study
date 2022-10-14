#include "../inc/utils.h"

static char ft_strlen_without(char *str, char c)
{
	int	i;/*{{{*/

	i = 0;
	while (str[i] == c)
		str++;
	while (str[i])
		i++;
	while (str[i - 1] == c)
		i--;
	return (i);/*}}}*/
}

char	*ft_strtrim(char *str, char c)
{
	int		i;/*{{{*/
	int		len;
	char	*ret;

	i = 0;
	len = ft_strlen_without(str, c);
	ret = malloc(len + 1);
	while (str[i] == c)
		str++;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);/*}}}*/
}

static	int	split_count(char *str, char c)
{/*{{{*/
	int	chk;
	int	cnt;
	int i;

	i = 0;
	cnt = 0;
	chk = 1;
	while (str[i])
	{
		if (str[i] != c && chk != 0)
		{
			cnt++;
			chk = 0;
		}
		if (str[i] == c)
		{
			chk = 1;
		}
		i++;
	}
	return (cnt);/*}}}*/
}

static int	ft_get_next(char *str, char c)
{/*{{{*/
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);/*}}}*/
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		len;
	char	**ret;
	int		nxt;

	len = split_count(str, c);
	ret = malloc(sizeof(char *) * (len + 2));
	i = 0;
	while (i <= len)
	{
		while (*str == c)
			str++;
		nxt = ft_get_next(str, c);
		ret[i] = ft_substr(str, 0, nxt);
		str = str + nxt + 1;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
