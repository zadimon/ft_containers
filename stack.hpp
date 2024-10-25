/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:30:37 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/12/02 18:41:58 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {
 public:
  typedef Container container_type;
  typedef typename Container::value_type value_type;
  typedef typename Container::size_type size_type;
  typedef typename Container::reference reference;
  typedef typename Container::const_reference const_reference;

 protected:
  container_type c;

 public:
  explicit stack(const container_type &cont = container_type()) : c(cont) {}

  bool empty() const { return (c.empty()); }

  size_type size() const { return (c.size()); }

  reference top() { return (c.back()); }

  const_reference top() const { return (c.back()); }

  void push(const value_type &val) { c.push_back(val); }

  void pop() { c.pop_back(); }

  stack &operator=(const stack &other) {
    c = other.c;
    return (*this);
  }

  template <class A, class Cont>
  friend bool operator==(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs);

  template <class A, class Cont>
  friend bool operator!=(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs);

  template <class A, class Cont>
  friend bool operator<(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs);

  template <class A, class Cont>
  friend bool operator<=(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs);

  template <class A, class Cont>
  friend bool operator>(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs);

  template <class A, class Cont>
  friend bool operator>=(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs);
};

template <class A, class Cont>
bool operator==(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs) {
  return (lhs.c == rhs.c);
}

template <class A, class Cont>
bool operator!=(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs) {
  return (lhs.c != rhs.c);
}

template <class A, class Cont>
bool operator<(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs) {
  return (lhs.c < rhs.c);
}

template <class A, class Cont>
bool operator<=(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs) {
  return (lhs.c <= rhs.c);
}

template <class A, class Cont>
bool operator>(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs) {
  return (lhs.c > rhs.c);
}

template <class A, class Cont>
bool operator>=(const stack<A, Cont> &lhs, const stack<A, Cont> &rhs) {
  return (lhs.c >= rhs.c);
}
}  // namespace ft

#endif
