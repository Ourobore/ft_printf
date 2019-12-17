/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:03:08 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/17 10:22:45 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flags
{
	int		left;
	int		fill;
	int		precision;
	int		width;
	int		error;
}				t_flags;

int				ft_printf(const char *s, ...);
void			ft_parse(const char *s, t_flags *f, va_list *va);
void			ft_convert(const char *s, int *i, t_flags *f, va_list *va);
void			ft_call(char *formula, char c, t_flags *f, va_list *va);
t_flags			ft_init_flags(void);
t_flags			get_flags(char *formula, t_flags *f);
int				get_length(char *formula);

char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strlen(char *s);
int				ft_atoi(const char *s);
#endif
