#include "../inc/token.h"

t_token	*add_node(char *str, char *symbol, int ind)
{
	t_token	*token;/*{{{*/

	token = malloc(sizeof(t_token));
	memset(token, 0, sizeof(t_token));
	ft_strcpy(token->cmd, str);
	ft_strcpy(token->type, symbol);
	token->ind = ind + 1;
	token->next = NULL;
	return (token);/*}}}*/
}

void	add_token(t_tokenizer *tknzr, char *str, char *sym)
{
	if (tknzr->head == NULL)/*{{{*/
	{
		tknzr->head = add_node(str, sym, -1);
		tknzr->tail = tknzr->head;
	}
	else
	{
		tknzr->tail->next = add_node(str, sym, tknzr->tail->ind);
		tknzr->tail = tknzr->tail->next;
	}/*}}}*/
}

void	remove_tokenizer(t_tokenizer *tknzr)
{
	t_token	*tkn;/*{{{*/
	t_token	*tmp;

	tkn = tknzr->head;
	while (tkn)
	{
		tmp = tkn;
		tkn = tkn->next;
		free(tmp);
		tmp = NULL;
	}
	free(tknzr);/*}}}*/
}

void	print_token(t_token *token)
{
	t_token	*tmp;/*{{{*/

	tmp = token;
	while (tmp)
	{
		printf("%d\n", tmp->ind);
		printf("str : %s\nsymbol type : %s\n",tmp->cmd, tmp->type);
		tmp = tmp->next;
	}/*}}}*/
}

void	tests(char **str)
{
	t_tokenizer	*tkn;

	tkn = malloc(sizeof(t_tokenizer));
	for (int i = 0; i < 10; i ++)
	{
		add_token(tkn, str[i], "");
	}
	print_token(tkn->head);

	remove_tokenizer(tkn);
}
