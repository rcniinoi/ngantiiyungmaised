#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	wcount;
	t_array	*ray;
	t_hua	*hua;
	// int	i = 0;

	ray = ft_calloc(1, sizeof(t_array));
	ft_rayini(ray);
	if (argc < 2)
		exit (0);
	wcount = ft_wordcountall(argc, argv);
	if (wcount == 2)
		ft_printerrorexit();
	ray->charbuffer = ft_argumontobuffer(argc,argv, wcount);
	// while (i < wcount)
	// {
	// 	printf("-%s-\n", ray->charbuffer[i]);
	// 	i++;
	// }
	if (ft_errorchkall(wcount, ray) == 0)
		ft_printerrorexit();
	ray->realarray = ft_atoisembe(ray->charbuffer, wcount);
	hua = malloc(sizeof(t_hua));
	ft_huaini(hua, ray, wcount);

	if (ft_chksworded(hua) != 1)
	{
		if (argc == 4)
			ft_sortsammlast(hua, ray, wcount);
		else if (argc <= 6)
			ft_indexsort(hua, ray, wcount);
		else if (argc <= 101)
		{
			ft_atob(hua, ray, wcount, 33);
			// ft_printlst(hua->huaa);
			// ft_printlst(hua->huab);
			ft_btoa(hua, ray, wcount);
		}
		else if (argc <= 501)
		{
			ft_atob(hua, ray, wcount, 11);
			// ft_printlst(hua->huaa);
			// ft_printlst(hua->huab);
			ft_btoa(hua, ray, wcount);
		}
	}
		// printf("asdfghjklk;klkhkghjfhjf ===================== / s s====================%d\n", (wcount - 3) / 3);

	// ft_ra(hua, hua->aval, 1);
	// ft_ra(hua, hua->aval, 1);
	// ft_pb(hua, 1);
	// ft_pb(hua, 1);
	// ft_ra(hua, hua->aval, 1);
	// ft_pb(hua, 1);
	// ft_ra(hua, hua->aval, 1);
	// ft_pb(hua, 1);
	// ft_ra(hua, hua->aval, 1);
	// ft_pb(hua, 1);
	// ft_ra(hua, hua->aval, 1);
	// ft_pb(hua, 1);
	// ft_pb(hua, 1);
	// ft_pb(hua, 1);

	// ft_pa(hua, 1);
	// ft_pa(hua, 1);
	// ft_pa(hua, 1);
	// ft_pa(hua, 1);
	// ft_pa(hua, 1);
	// ft_rb(hua, hua->bval, 1);
	// ft_pa(hua, 1);
	// ft_rb(hua, hua->bval, 1);
	// ft_pa(hua, 1);
	// ft_rb(hua, hua->bval, 1);
	// ft_pa(hua, 1);
	// ft_pa(hua, 1);
	// ft_pa(hua, 1);

	// ft_printlst(hua->huaa);
	// ft_printlst(hua->huab);
	// ft_rrb(hua, hua->bval, 1);
	// ft_printlst(hua->huaa);
	// ft_printlst(hua->huab);


	free (hua);
	// ft_freestrstr(ray->charbuffer);
	free (ray);
}
