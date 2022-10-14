#include "../inc/token.h"

char	*print_switch(char c, int db_flag)
{
	char	*ret;

	ret = "COMMAND";
	if (c == ';')
		ret = "COMMAND";
	if (c == '|')
		ret = "PIPE";
	else if (c == '<')
	{
		if (db_flag == 1)
			ret = "HEREDOC";
		else
			ret = "REDIR_INPUT";
	}
	else if (c == '>')
	{
		if (db_flag == 1)
			ret = "ADD_REDIR_OUTPUT";
		else
			ret = "REDIR_OUTPUT";
	}
	else if (c == '-')
		ret = "OPTION";
	return (ret);
}

int	in_space(char *str, int e)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (i < e)
	{
		if (str[i] != ' ')
			cnt++;
		i++;
	}
	return (cnt);
}

int	tokenizer(t_tokenizer *tknzr, char *line)
{
	int		i;
	int		db_flag;
	int		next_ind;

	next_ind = next_symbol(line);
	i = next_ind;
	if (!is_token(line[0]))
		add_token(tknzr, ft_substr(line, 0, next_symbol(line) - 1), print_switch('\0', '\0'));
	while (line[i])
	{
		if (is_token(line[i]))
		{
			db_flag = 0;
			if (line[i] == line[i + 1])
				db_flag = 1;
			i += db_flag;
			next_ind = next_symbol(line + i + 1);
			if (!in_space(line + i + 1, next_ind))
				return (1);
			add_token(tknzr, ft_substr(line + i + 1, 0, next_ind), print_switch(line[i], db_flag));
			i += next_ind;
		}
		i++;
	}
	return (0);
}

int main()
{
	t_tokenizer	*tknzr;
	char		*test = "abcd -n | auto <<  asdf q;asdf -n";
	int			r;

	printf("input str : %s\n\n\n", test);
	tknzr = malloc(sizeof(t_tokenizer));
	r = tokenizer(tknzr, test);
	if (r == 1)
	{
		remove_tokenizer(tknzr);
		return (1);
	}
	make_ast(tknzr);
	remove_tokenizer(tknzr);
	return (0);
}
