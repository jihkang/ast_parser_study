#ifndef	TOKEN_H
#define TOKEN_H

/** for memset **/
# include <string.h>
# include "utils.h"

typedef struct	s_token
{
	char			cmd[100];
	char			type[100];
	int				ind;
	struct s_token	*next;
	struct s_token	*child;
}t_token;

typedef struct	s_tokenizer
{
	struct s_token	*tail;
	struct s_token	*head;
}t_tokenizer;

void	print_token(t_token *token);
void	add_token(t_tokenizer *tknzr, char *str, char *sym);
void	remove_tokenizer(t_tokenizer *tknzr);
int		is_token(char c);
int		next_symbol(char *str);
char	*make_ast(t_tokenizer *tknzr);

#endif
