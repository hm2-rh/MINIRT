#include "minirt.h"

void    implement_sp(char **tab, t_list **shapes)
{
    t_sp *sp;

    sp = malloc(sizeof(t_sp));
    sp->id = SP;
    sp->center = ext_vec(tab[1]);
    sp->radius = ft_atolf(tab[2]);
    sp->color = ext_color_ratio(tab[3]);
    ft_lstadd_back(shapes, ft_lstnew(sp));
}

void	implement_pl(char **tab, t_list **shapes)
{
    t_plane *pl;

    pl = malloc(sizeof(t_plane));
    pl->id = PL;
    pl->ref = ext_vec(tab[1]);
    pl->normal = ext_vec(tab[2]);
    pl->color = ext_color_ratio(tab[3]);
    ft_lstadd_back(shapes, ft_lstnew(pl));
}

void    implement_tr(char **tab, t_list **shapes)
{
    t_tr *tr;

    tr = malloc(sizeof(t_tr));
    tr->id = TR;
    tr->p0 = ext_vec(tab[1]);
    tr->p1 = ext_vec(tab[2]);
    tr->p2 = ext_vec(tab[3]);
    tr->p0p1 = subvec(tr->p1, tr->p0);
    tr->p0p2 = subvec(tr->p2, tr->p0);
    tr->color = ext_color_ratio(tab[4]);
    ft_lstadd_back(shapes, ft_lstnew(tr));
}