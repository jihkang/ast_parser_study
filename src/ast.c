#include "../inc/token.h"

void	print(t_token *tkn)
{
	printf("{\n");
	printf("\ttype : %s,\n", tkn->type);
	printf("\tstring : %s\n", tkn->cmd);
	printf("},\n");
}

void	is_open(t_token *tkn)
{
	static	int	flag;

	if (flag == 0)
	{
		if (tkn != NULL)
		{
			printf("{\n");
			print(tkn);
		}
		flag = 1;
		return ;
	}
	flag = 0;
	printf("}\n");
	if (tkn != NULL)
	{
		is_open(tkn);
	}
}

int		check_symbol(char *str)
{
	if (ft_strcmp(str, "PIPE") == 0 ||
		ft_strcmp(str, "OPTION") == 0 ||
		ft_strcmp(str, "HEREDOC") == 0 ||
		ft_strcmp(str, "REDIR_INPUT") == 0 ||
		ft_strcmp(str, "ADD_REDIR_OUTPUT") == 0 ||
		ft_strcmp(str, "REDIR_OUTPUT") == 0)
		return (1);
	return (0);
}

char	*make_ast(t_tokenizer *tknzr)
{
	char	*ret;
	t_token	*tkn;
	int		chk;

	ret = NULL;
	if (tknzr == NULL)
		return ("Failed");
	tkn = tknzr->head;
	while (tkn)
	{
		chk = check_symbol(tkn->type);
		if (chk == 0)
			is_open(tkn);
		else
			print(tkn);	
		tkn = tkn->next;
	}
	is_open(NULL);
	return (ret);
}
