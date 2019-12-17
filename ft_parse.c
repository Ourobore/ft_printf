/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:26:52 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/17 10:24:28 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(const char *s, t_flags *f, va_list *va)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			ft_convert(s, &i, f, va);
		else
			write(1, &s[i], 1);
		i++;
	}
	return ;
}

int		get_length(char *formula)
{
	int i;

	i = 0;
	while (formula[i] >= '0' && formula[i] <= '9')
		i++;
	return (i);
}

t_flags	get_flags(char *formula, t_flags *f)
{
	int		i;

	i = 1;
	*f = ft_init_flags();
	while (formula[i + 1])
	{
		if (formula[i] == '0' && !(*f).width && (*f).precision == -1)
			(*f).fill = 1;
		else if (formula[i] == '-' && !(*f).width && (*f).precision == -1)
			(*f).left = 1;
		else if (formula[i] == '.' && (*f).precision == -1)
		{
			(*f).precision = ft_atoi(formula + i + 1);
			i += get_length(formula + i + 1);
		}
		else if (formula[i] >= '1' && formula[i] <= '9' &&
					!(*f).width && (*f).precision == -1)
		{
			(*f).width = ft_atoi(formula + i);
			i += get_length(formula + i) - 1;
		}
		else
			(*f).error = 1;
		i++;
	}
	if ((*f).left && (*f).fill)
		(*f).error = 1;
	printf("%d:%d:%d:%d:%d\n", (*f).left, (*f).fill, (*f).precision, (*f).width, (*f).error);
	return (*f);
}
