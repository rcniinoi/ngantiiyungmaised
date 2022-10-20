/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswinst3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:31:59 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/19 17:38:26 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_hua *hua, int count, int mode)
{
	t_stk	*tmplast;
	t_stk	*tmp;
	int		i;

	i = count - 1;
	tmplast = ft_lstlast2(hua->huaa);
	if (hua->huaa && tmplast && tmplast->prev)
	{
		ft_rerotate(hua->huaa, tmplast);
		hua->huaa = ft_lstfirst(hua->huaa);
		tmp = ft_lstfirst(hua->huaa);
		while (i > 0)
		{
			ft_swapab(&tmp->index, &tmp->next->index);
			tmp = tmp->next;
			i--;
		}
	}
	if (mode == 1)
		ft_dprintf(1, "rra\n");
}

void	ft_rrb(t_hua *hua, int count, int mode)
{
	t_stk	*tmplast;
	t_stk	*tmp;
	int		i;

	i = count - 1;
	tmplast = ft_lstlast2(hua->huab);
	if (hua->huab && tmplast && tmplast->prev)
	{
		ft_rerotate(hua->huab, tmplast);
		hua->huab = ft_lstfirst(hua->huab);
		tmp = ft_lstfirst(hua->huab);
		while (i > 0)
		{
			ft_swapab(&tmp->index, &tmp->next->index);
			tmp = tmp->next;
			i--;
		}
	}
	if (mode == 1)
		ft_dprintf(1, "rrb\n");
}

void	ft_rrr(t_hua *hua)
{
	ft_rra(hua, hua->aval, 2);
	ft_rrb(hua, hua->bval, 2);
	ft_dprintf(1, "rrr\n");
}
