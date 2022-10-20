#include "../push_swap.h"

int	ft_chksworded(t_hua *hua)
{
	t_stk	*tmp;

	tmp = hua->huaa;
	while (tmp->next != NULL)
	{
		if (tmp->lek < tmp->next->lek)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	ft_huaini(t_hua *hua, t_array *ray, int count)
{
	hua->aval = count;
	hua->bval = 0;
	hua->huaa = ft_stkabini(ray->realarray, count);
	hua->huab = NULL;
}

void	ft_rayini(t_array *ray)
{
	ray->charbuffer = NULL;
	ray->fakearray = NULL;
	ray->realarray = NULL;
}
