#ifndef	UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dst, char *str);
char	*ft_strchr(char *str, char c);
char	*ft_substr(char *str, int start, int end);
int		ft_strlen(char *str);
int		ft_strcmp(char *str, char *str2);
char	*ft_strtrim(char *str, char c);
char	**ft_split(char *str, char c);
void	remove_split(char **str);

#endif
