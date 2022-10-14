#include "../inc/token.h"

t_token	*add_node(char *str, char *symbol, int ind)
{
	t_token	*token;/*{{{*/

	token = malloc(sizeof(t_token));
	memset(token, 0, sizeof(t_token));
	ft_strcpy(token->cmd, str);
	ft_strcpy(token->type, symbol);
	token->ind = ind + 1;
	return (token);/*}}}*/
}

t_token	*add_child(char *str, char *sym, int ind)
{
	t_token	*tkn;
	t_token	*temp_tkn;
	char	**temp;
	int		i;

	temp = ft_split(str, ' ');
	i = 1;
	if (temp[2] == NULL)
	{
		remove_split(temp);
		return (NULL);
	}
	tkn = add_node(temp[0], sym, ind);
	temp_tkn = tkn;
	while (temp[i])
	{
		tkn->next = add_node(temp[i], sym, ind);
		tkn = tkn->next;
		i++;
	}
	remove_split(temp);
	return (temp_tkn);
}

void	add_token(t_tokenizer *tknzr, char *str, char *sym)
{
	char	*trim_str;/*{{{*/

	trim_str = ft_strtrim(str, ' ');
	free(str);
	if (tknzr->head == NULL)
	{
		tknzr->head = add_node(trim_str, sym, -1);
		tknzr->head->child = add_child(trim_str, sym, -1);
		tknzr->tail = tknzr->head;
	}
	else
	{
		tknzr->tail->next = add_node(trim_str, sym, tknzr->tail->ind);
		tknzr->tail->next->child = add_child(trim_str, sym, tknzr->tail->ind); 
		tknzr->tail = tknzr->tail->next;
	}/*}}}*/
	free(trim_str);
}

void	free_token(t_token **tkn)
{
	free(*tkn);
	*tkn = NULL;
}

void	remove_tokenizer(t_tokenizer *tknzr)
{
	t_token	*tkn;/*{{{*/
	t_token	*tmp;
	t_token	*child;

	tkn = tknzr->head;
	while (tkn)
	{
		tmp = tkn;
		while (tkn->child)
		{
			child = tkn->child;
			tkn->child = child->next;
			free_token(&child);
		}
		tkn = tkn->next;
		free_token(&tmp);
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
