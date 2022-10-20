#include "../push_swap.h"

void	ft_indexsort(t_hua *hua, t_array *ray, int count)
{
	int		i;
	t_stk	*tmp;

	i = 0;
	while (hua->aval > 3 && i < count)
	{
		tmp = hua->huaa;
		while (tmp->lek != ray->fakearray[i])
			tmp = tmp->next;
		if (tmp->index <= (hua->aval - (hua->aval % 2)) / 2)
		{
			while (hua->huaa->lek != ray->fakearray[i])
				ft_ra(hua, hua->aval, 1);
			ft_pb(hua, 1);
		}
		if (tmp->index > (hua->aval - (hua->aval % 2)) / 2)
		{
			while (hua->huaa->lek != ray->fakearray[i])
				ft_rra(hua, hua->aval, 1);
			ft_pb(hua, 1);
		}
		i++;
	}
	ft_sortsammlast(hua, ray, count);
	while (hua->bval > 0)
	{
		ft_pa(hua, 1);
	}
}

void	ft_sortsammlast(t_hua *hua, t_array *ray, int count)
{
	if (hua->huaa->next->next->lek == ray->fakearray[count - 1])
	{
		if (hua->huaa->next->lek == ray->fakearray[count - 3])
			ft_sa(hua, 1);
	}
	if (hua->huaa->next->next->lek == ray->fakearray[count - 2])
	{
		if (hua->huaa->lek < hua->huaa->next->lek)
			ft_sa(hua, 1);
		ft_ra(hua, hua->aval, 1);
	}
	if (hua->huaa->next->next->lek == ray->fakearray[count - 3])
	{
		if (hua->huaa->lek > hua->huaa->next->lek)
			ft_sa(hua, 1);
		ft_rra(hua, hua->aval, 1);
	}
}

// void	ft_sortroi(t_hua *hua, t_array *ray, int count)
// {

// }

void	ft_atob(t_hua *hua, t_array *ray, int count, int times)
{
	int	par;
	int	i;
	int	mul;

	i = times - 1;
	par = ((count - 3) - ((count - 3) % times)) / times;
	while (hua->aval > 3 )
	{
		mul = par * i;
		while (hua->aval > mul + 3 && hua->aval > 3)
		{
			// if (hua->huaa->next->lek <= ray->fakearray[(count - mul) - 4] && hua->huaa->lek > ray->fakearray[(count - mul) - 4])
			// 	ft_sa(hua, 1);
			if (hua->huaa->lek <= ray->fakearray[(count - mul) - 4])
				ft_pb(hua, 1);
			else
				ft_ra(hua, hua->aval, 1);
		}
		i--;
	}
	ft_sortsammlast(hua, ray, count);
}

void	ft_btoa(t_hua *hua, t_array *ray, int count)
{
	int		i;
	t_stk	*tmp;


	tmp = hua->huab;
	i = count - 4;
	while (hua->bval > 0 && i >= 0)
	{
		// printf("looppppp\n");
		// printf("bval = %d i = %d fake i = %d\n", hua->bval, i, ray->fakearray[i]);
		while (tmp->lek != ray->fakearray[i])
		{
			// printf("tmp lek %d fake i %d\n", tmp->lek, ray->fakearray[i]);
			tmp = tmp->next;
			// printf("bbbbb\n");
		}
		if (tmp->index == 1)
		{
			ft_sb(hua , 1);
			ft_pa(hua, 1);
		}
		else if (tmp->index > hua->bval / 2 && tmp->index != 0)
		{
			// printf("tmpindex %d bval/2 %d\n", tmp->index, hua->bval / 2);
			while (hua->huab->lek != ray->fakearray[i])
			{
				// printf("huab lek %d fake i %d\n", hua->huab->lek, ray->fakearray[i]);
				ft_rb(hua, hua->bval, 1);
			}
		}
		else if (tmp->index <= hua->bval / 2 && tmp->index != 0)
		{
			// printf("tmpindex %d bval/2 %d\n", tmp->index, hua->bval / 2);
			while (hua->huab->lek != ray->fakearray[i])
			{
				// printf("huab lek %d fake i %d\n", hua->huab->lek, ray->fakearray[i]);
				ft_rb(hua, hua->bval, 1);
			}
		}
		if (hua->huab->lek == ray->fakearray[i])
			ft_pa(hua, 1);
		if (hua->bval != 0)
			tmp = ft_lstfirst(hua->huab);
		else
			break;
		i--;
	}
}

void	atob2(t_hua *hua, t_array *ray, int count)
{
	int	i;

	while (hua->bval > 0)
	{
		i = count - 1 - hua->aval;
		if (hua->huab->lek == ray->fakearray[i])
		{
			ft_pa(hua, 1);
			i = count - 1 - hua->aval;
		}
		else
		{
			ft_pa(hua, 1);
			ft_pa(hua, 1);
			ft_pa(hua, 1);
			if (hua->huaa->lek == ray->fakearray[i] && hua->huaa->next->lek == ray->fakearray[i - 2])
			{
				if (hua->huab->next->lek == ray->fakearray[i - 3] || (hua->huab->next->lek == ray->fakearray[i - 4] && hua->huab->lek == ray->fakearray[i - 5]))
					ft_ss(hua);
				else
					ft_sa(hua, 1);
				ft_ra(hua, count, 1);
				ft_sa(hua, 1);
				ft_rra(hua, hua->aval, 1);
			}
		}

	}
}
