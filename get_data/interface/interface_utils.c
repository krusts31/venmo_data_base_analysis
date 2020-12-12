#include "interface.h"

void	*ft_lstadd_back(p_list **head, p_list *new)
{
	p_list	*temp;
	
	temp = lst;
	if (temp == 0)
	{
		*lst = *new;
		return ;
	}
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
}

p_list	*ft_lstnew(char *content[])
{
	p_list	*profile_ptr;

	profile_ptr = (p_list*)malloc(sizeof(p_list));
	if (profile_ptr == 0)
		return (0);
	profile_ptr->username = profile[0];
	profile_ptr->displayname = profile[1];
	profile_ptr->date = profile[2];
	profile_ptr->comment = profile[3];
	profile_ptr->next = 0;
	return (profile_ptr);
}
