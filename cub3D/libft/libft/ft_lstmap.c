/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hregina <hregina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:47:21 by hregina           #+#    #+#             */
/*   Updated: 2021/09/19 16:47:23 by hregina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lst_clone(void *content,
		void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_el;

	new_content = f(content);
	new_el = ft_lstnew(new_content);
	if (new_el == 0)
		del(new_content);
	return (new_el);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_el;
	t_list	*new_next;

	new_next = 0;
	if (lst == 0 || f == 0)
		return (0);
	new_el = ft_lst_clone(lst->content, f, del);
	if (new_el == 0)
		return (0);
	new_lst = new_el;
	lst = lst->next;
	while (lst != 0)
	{
		new_next = ft_lst_clone(lst->content, f, del);
		if (new_next == 0)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		new_el->next = new_next;
		lst = lst->next;
		new_el = new_next;
	}
	return (new_lst);
}
