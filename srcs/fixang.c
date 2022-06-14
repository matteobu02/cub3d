/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixang.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:59:41 by lyaiche           #+#    #+#             */
/*   Updated: 2022/06/13 16:00:03 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	fixang(float a)
{
	if (a > 359)
		a -= 360.0;
	if (a < 0)
		a += 360.0;
	return (a);
}