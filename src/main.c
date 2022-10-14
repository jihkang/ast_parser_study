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

void	tokenizer(t_tokenizer *tknzr, char **read_line)
{
	int		i;
	int		cur_flag;
	char	cur_char;
	char	next_char;
	int		db_flag;
	int		next_ind;

	if (tknzr == NULL)
		exit(1);
	i = 0;
	cur_flag = 1;
	next_ind = next_symbol(*read_line);
	if (!is_token(*read_line[0]))
		add_token(tknzr, ft_substr(*read_line, 0, next_symbol(*read_line) - 1), print_switch('\0', '\0'));
	i = i + next_ind;
	while ((*read_line)[i])
	{
		if (is_token((*read_line)[i]) || 
			(!is_token((*read_line)[i] && i == 0)))
		{
			if (cur_flag == 0)
			{
				printf("??? it something wrong");
				break ;
			}
			cur_char = (*read_line)[i];
			next_char = (*read_line)[i + 1];
			db_flag = 0;
			if (cur_char == next_char)
				db_flag = 1;
			i += db_flag;
			next_ind = next_symbol(*read_line + i + 1);
			add_token(tknzr, ft_substr(*read_line + i + 1, 0, next_ind),
					print_switch(cur_char, db_flag));
			i += next_ind;
		}
		else if (cur_flag != 1 && (*read_line)[i] != 32)
		{
			cur_flag = 1;
		}
		i++;
	}
}

int main()
{
	t_tokenizer	*tknzr;
	char		*test = "abcd -n | asdf q;asdf -n";

	printf("input str : %s\n\n\n", test);
	tknzr = malloc(sizeof(t_tokenizer));
	tokenizer(tknzr, &test);
	make_ast(tknzr);
	remove_tokenizer(tknzr);
	return (0);
}
