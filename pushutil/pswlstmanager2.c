/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswlstmanager2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:47:53 by rchiewli          #+#    #+#             */
/*   Updated: 2022/10/15 03:07:41 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stk	*ft_lstlast2(t_stk *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stk	*ft_lstfirst(t_stk *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_stk	*ft_stkabini(int *array, int count)
{
	int		i;
	t_stk	*stka;
	t_stk	*tmp;

	stka = NULL;
	i = 0;
	while (i++ < count)
	{
		if (stka == NULL)
		{
			stka = ft_lstaddklang(NULL, NULL);
			ft_t_stkini(stka);
			stka->index = i - 1;
			stka->lek = array[i - 1];
		}
		else
		{
			tmp = stka;
			tmp = ft_lstaddklang(stka, NULL);
			tmp = ft_lstlast2(stka);
			tmp->index = i - 1;
			tmp->lek = array[i - 1];
		}
	}
	return (stka);
}

void	ft_tmpstarter(t_tmp *tmp)
{
	tmp->tmp1 = NULL;
	tmp->tmp2 = NULL;
	tmp->tmp3 = NULL;
	tmp->tmp4 = NULL;
}
