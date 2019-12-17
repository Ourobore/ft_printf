/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:04:58 by lchapren          #+#    #+#             */
/*   Updated: 2019/12/17 10:23:00 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	f;

	f.left = 0;
	f.fill = 0;
	f.precision = -1;
	f.width = 0;
	f.error = 0;
	return (f);
}
