#include "../inc/token.h"

void	print(t_token *tkn)
{
	t_token	*tmp_tkn;

	printf("\t{\n");
	printf("\t\ttype : %s,\n", tkn->type);
	tmp_tkn = tkn->child;
	if (tmp_tkn)
	{
		printf("\t\t{\n");
		while (tmp_tkn)
		{
			printf("\t\t\t{str : %s},\n", tmp_tkn->cmd);
			tmp_tkn = tmp_tkn->next;
		}
		printf("\t\t}\n");
	}
	else
	{
		printf("\t\t{value : %s},\n", tkn->cmd);
	}
	printf("\t},\n");
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
	printf("}");
	if (tkn != NULL)
	{
		printf(",\n");
		is_open(tkn);
	}
	else
		printf("\n");
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
