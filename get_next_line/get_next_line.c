/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:42:26 by tochen            #+#    #+#             */
/*   Updated: 2023/11/22 20:27:05 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
    t_list		*head;
    char		*line;
	char		*rest;
	char		buf[(BUFFER_SIZE + 1)];
	ssize_t		bytes_read;

	buf[BUFFER_SIZE] = '\0';
	if (fd < 0 || (BUFFER_SIZE) <= 0) 
		return (NULL);
	bytes_read = read(fd, buf, (BUFFER_SIZE));
	if(bytes_read < 0)
	{		//TODO: Free all memory and return NULL
		return (NULL);
	}
	if(bytes_read < (BUFFER_SIZE))
		buf[bytes_read] = '\0';
	
	rest=ft_strchr(buf, '\n');
	if(rest){
		rest++;
		*rest='\0';
		line=get_from_list(buf, head);
		ft_lstclear(&head,free);
		head=ft_strdup(rest);
		return(line);
	}else{
		ft_lstadd_back(&head, ft_strdup(buf));
	}
	    
}

