#include "../push_swap.h"

void	ft_swap(t_stk *huax)
{
	t_stk	*tmp1;
	t_stk	*tmp2;
	t_stk	*tmp3;

	if (huax && huax->next)
	{
		tmp1 = huax;
		tmp2 = huax->next;
		if (huax->next->next)
			tmp3 = huax->next->next;
		else
			tmp3 = NULL;
		tmp2->next = tmp1;
		tmp1->next = tmp3;
		tmp2->prev = NULL;
		tmp1->prev = tmp2;
		if (tmp3 != NULL)
			tmp3->prev = tmp1;
		huax = tmp2;
		huax->next = tmp1;
	}
}

void	ft_rotate(t_stk *huax, t_stk *end)
{
	if (huax == NULL || end == NULL || huax->next == NULL)
		return ;
	end->next = huax;
	huax->prev = end;
	huax = huax->next;
	huax->prev = NULL;
	end = end->next;
	end->next = NULL;
}

void	ft_rerotate(t_stk *huax, t_stk *end)
{
	if (huax == NULL || end == NULL || end->prev == NULL)
		return ;
	huax->prev = end;
	end->next = huax;
	huax = end;
	end = end->prev;
	end->next = NULL;
	huax->prev = NULL;
}

void	ft_push(t_hua *hua, t_stk *huafrom, t_stk *huato, int mode)
{
	t_tmp	stmp;

	ft_tmpstarter(&stmp);
	stmp.tmp1 = huafrom;
	stmp.tmp2 = huafrom->next;
	stmp.tmp3 = huato;
	stmp.tmp1->next = stmp.tmp3;
	if (stmp.tmp2 != NULL)
		stmp.tmp2->prev = NULL;
	if (stmp.tmp3 != NULL)
		stmp.tmp3->prev = stmp.tmp1;
	huafrom = stmp.tmp2;
	huato = stmp.tmp1;
	if (mode == 1 && huato)
	{
		hua->huaa = ft_lstfirst(huato);
		if (huafrom)
			hua->huab = ft_lstfirst(huafrom);
	}
	else if (mode == 2 && huato)
	{
		hua->huab = ft_lstfirst(huato);
		if (huafrom)
			hua->huaa = ft_lstfirst(huafrom);
	}
}

