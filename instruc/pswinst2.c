/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswinst2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:37:41 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/18 17:17:07 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_hua	*hua, int mode)
{
	int		i;
	int		j;

	i = hua->aval;
	j = hua->bval - 1;
	ft_indexkayap_pa(hua, i, j, 1);
	if (hua->huab)
		ft_push(hua, hua->huab, hua->huaa, 1);
	ft_indexkayap_pa(hua, i, j, 2);
	hua->aval += 1;
	hua->bval -= 1;
	if (hua->bval == 0)
		hua->huab = NULL;
	if (mode == 1)
		ft_dprintf(1, "pa\n");
}

void	ft_pb(t_hua	*hua, int mode)
{
	int		i;
	int		j;

	i = hua->bval;
	j = hua->aval - 1;
	ft_indexkayap_pb(hua, i, j, 1);
	if (hua->huaa)
		ft_push(hua, hua->huaa, hua->huab, 2);
	ft_indexkayap_pb(hua, i, j, 2);
	hua->bval += 1;
	hua->aval -= 1;
	if (hua->aval == 0)
		hua->huaa = NULL;
	if (mode == 1)
		ft_dprintf(1, "pb\n");
}

void	ft_rr(t_hua	*hua)
{
	ft_ra(hua, hua->aval, 2);
	ft_rb(hua, hua->bval, 2);
	ft_dprintf(1, "rr\n");
}
