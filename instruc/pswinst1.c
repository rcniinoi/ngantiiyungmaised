/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswinst1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:36:06 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/19 18:04:43 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_hua	*hua, int	mode)
{
	if (hua->huaa && hua->huaa->next)
	{
			ft_swap(hua->huaa);
		hua->huaa = ft_lstfirst(hua->huaa);
		ft_swapab(&hua->huaa->next->index, &hua->huaa->index);
		if (mode == 1)
			ft_dprintf(1, "sa\n");
	}
}

void	ft_sb(t_hua	*hua, int	mode)
{
	if (hua->huab && hua->huab->next)
	{
			ft_swap(hua->huab);
		hua->huab = ft_lstfirst(hua->huab);
		ft_swapab(&hua->huab->next->index, &hua->huab->index);
		if (mode == 1)
			ft_dprintf(1, "sb\n");
	}
}

void	ft_ss(t_hua	*hua)
{
	if (hua->huaa && hua->huab && hua->huaa->next && hua->huab->next)
	{
		ft_sb(hua, 2);
		ft_sa(hua, 2);
		ft_dprintf(1, "ss\n");
	}
}

void	ft_ra(t_hua	*hua, int count, int mode)
{
	t_stk	*tmplast;
	int		i;

	i = count - 1;
	tmplast = ft_lstlast2(hua->huaa);
	if (hua->huaa && hua->huaa->next && tmplast)
	{
		ft_rotate(hua->huaa, tmplast);
		tmplast = ft_lstlast2(hua->huaa);
		hua->huaa = ft_lstfirst(hua->huaa);
		while (i > 0 && tmplast->prev != NULL)
		{
			ft_swapab(&tmplast->index, &tmplast->prev->index);
			tmplast = tmplast->prev;
			i--;
		}
	}
	if (mode == 1)
		ft_dprintf(1, "ra\n");
}

void	ft_rb(t_hua	*hua, int count, int mode)
{
	t_stk	*tmplast;
	int		i;

	i = count - 1;
	tmplast = ft_lstlast2(hua->huab);
	if (hua->huab && hua->huab->next && tmplast)
	{
		ft_rotate(hua->huab, tmplast);
		tmplast = ft_lstlast2(hua->huab);
		hua->huab = ft_lstfirst(hua->huab);
		while (i > 0 && tmplast->prev != NULL)
		{
			ft_swapab(&tmplast->index, &tmplast->prev->index);
			tmplast = tmplast->prev;
			i--;
		}
	}
	if (mode == 1)
		ft_dprintf(1, "rb\n");
}
