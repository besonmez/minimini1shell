/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beysonme <beyzasonmez565@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:58:21 by kikiz             #+#    #+#             */
/*   Updated: 2025/07/15 20:09:17 by beysonme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	QUOTE_S,
	QUOTE_D,
}			t_token_type;

typedef struct s_token 
{
	char *value;
	t_token_type type;
	struct s_token *next;
}				t_token;

t_token	*create_token(char *value, t_token_type type)
{
	t_token	*token = malloc(sizeof(t_token));
	if (!token)
		return NULL;
	token->value = ft_strdup(value);
	token->type = type;
	token->next = NULL;
}

void	add_token(t_token **token_list, t_token *new_token)
{
	t_token *current;

	if (!*token_list)
		*token_list = new_token;
	else
	{
		current = *token_list;
		while (current->next)
			current = current->next;
		current->next = new_token;
	}
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

char	*parse_redirection(char **input)
{
	char first;

	first = **input;
	(*input)++;
	if (**input == first && (first == '>' || first == '<'))
	{
		(*input)++;
		if (**input == '>')
			return (">>");
		else if (**input == '<')
			return ("<<");
	}
	if (first == '>')
		return (">");
	else if (first == '<')
		return ("<");
	return (NULL);
}



t_token		*tokenize(char *input)
{
	t_token *tokens;

	tokens = NULL;
	while (*input)
	{
		if (ft_isspace(*input))
			input++;
		else if (*input == '|')
		{
			add_token(&tokens, create_token("|", PIPE));
		}
		else if (*input == '>' || *input == '<')
			add_token(&tokens, create_token(parse))
	}
}



char	*parse_word(char **input)
{
	char *start = *input;
	while (**input && !ft_isspace && 
			**input != '|' && **input != '>' && **input != '<')
	{
		(*input)++;
	}
	return (ft_substr(start, 0, *input - start));
}

