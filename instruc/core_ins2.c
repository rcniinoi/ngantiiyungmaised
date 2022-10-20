#include "../push_swap.h"

void	ft_indexkayap_pa(t_hua *hua, int i, int j, int mode)
{
	t_stk *tmp;

	if (mode == 1)
	{
		tmp = hua->huaa;
		while (i-- > 0)
		{
			tmp->index += 1;
			tmp = tmp->next;
		}
	}
	else if (mode == 2)
	{
		tmp = hua->huab;
		while (j-- > 0)
		{
			tmp->index -= 1;
			tmp = tmp->next;
		}
	}
}

void	ft_indexkayap_pb(t_hua *hua, int i, int j, int mode)
{
	t_stk *tmp;

	if (mode == 1)
	{
		tmp = hua->huab;
		while (i-- > 0)
		{
			tmp->index += 1;
			tmp = tmp->next;
		}
	}
	else if (mode == 2)
	{
		tmp = hua->huaa;
		while (j-- > 0)
		{
			tmp->index -= 1;
			tmp = tmp->next;
		}
	}
}
