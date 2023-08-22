/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:51:27 by isromero          #+#    #+#             */
/*   Updated: 2023/08/22 20:51:27 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    for(int i = 1; argv[i]; i++) {
      for(int j = 0; argv[i][j]; j++) {
        argv[i][j] = toupper(argv[i][j]);
        std::cout << argv[i][j];
      }
    }
    std::cout << std::endl;
  }
}
