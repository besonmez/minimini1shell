/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beysonme <beyzasonmez565@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:34:40 by kikiz             #+#    #+#             */
/*   Updated: 2025/07/26 19:45:32 by beysonme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdbool.h>

#define PROMPT "\001\033[38;5;205m\002minimini1shell$ \001\033[0m\002"

#include "builtins/builtins.h"

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

# endif
