/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:53:44 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/12/01 23:11:37 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {

template <class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2,
                             InputIt2 last2) {
  for (; first1 != last1 && first2 != last2; first1++, first2++) {
    if (*first1 < *first2) {
      return true;
    }
    if (*first1 > *first2) {
      return false;
    }
  }
  return (first1 == last1) && (first2 != last2);
}

template <class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2,
                             InputIt2 last2, Compare comp) {
  for (; first1 != last1 && first2 != last2; first1++, first2++) {
    if (comp(*first1, *first2)) {
      return true;
    }
    if (comp(*first2, *first1)) {
      return false;
    }
  }
  return (first1 == last1) && (first2 != last2);
}
}  // namespace ft

#endif
