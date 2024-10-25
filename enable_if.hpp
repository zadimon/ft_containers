/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:44:52 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/11/30 20:45:08 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft {

template <bool, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {
  typedef T type;
};
}  // namespace ft

#endif
