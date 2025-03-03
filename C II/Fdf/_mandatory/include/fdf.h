/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:58:30 by achoukri          #+#    #+#             */
/*   Updated: 2025/03/02 21:10:08 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

//to endicate the behavier of function that check for somthing
# define SUCCESS 1
# define FAILURE 0

# include <string.h> // for streeror
# include <stdio.h> // for perror
# include <stdlib.h> // for exit
# include <fcntl.h> // for open
# include <unistd.h> // for close
// # include <math.h> // for cos

// Input handling
void	check_file(char **av, int ac);
int		check_file_exist(const char *filename);
int		check_file_extension(const char *filename);

#endif