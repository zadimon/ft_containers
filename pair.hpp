/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:45:58 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/12/02 21:19:09 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

template <class T1, class T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  first_type first;
  second_type second;

  pair() : first(first_type()), second(second_type()) {}

  pair(const first_type& x, const second_type& y) : first(x), second(y) {}

  template <class U1, class U2>
  pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

  ~pair() {}

  pair& operator=(const pair& other) {
    first = other.first;
    second = other.second;
    return *this;
  }
};

template <class T1, class T2>
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  if (lhs.first < rhs.first) {
    return true;
  } else if (lhs.first > rhs.first) {
    return false;
  }
  return (lhs.second < rhs.second);
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return (rhs < lhs);
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return !(lhs < rhs);
}

template <class T1, class T2>
ft::pair<T1, T2> make_pair(T1 t, T2 u) {
  return ft::pair<T1, T2>(t, u);
}
}  // namespace ft

#endif
