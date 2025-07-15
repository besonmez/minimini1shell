/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beysonme <beyzasonmez565@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:06:21 by kikiz             #+#    #+#             */
/*   Updated: 2025/07/15 14:51:32 by beysonme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PROMPT "\001\033[38;5;205m\002minimini1shell$ \001\033[0m\002"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
char *input;
    while (1)
	{
		input = readline(PROMPT);
		if (!input)
			break;
		add_history(input);
		free(input);
	}
	return (0);
}

