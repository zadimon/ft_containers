/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:29:41 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/12/06 18:15:32 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.hpp"

int main() {
  std::cout << std::endl << "Stack test" << std::endl;
  stack_test();
  std::cout << std::endl << "Vector test" << std::endl;
  vector_test();
  std::cout << std::endl << "Map test" << std::endl;
  map_test();
  std::cout << std::endl << "Set test" << std::endl;
  set_test();
}
