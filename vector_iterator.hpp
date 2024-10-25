/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:59:18 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/11/29 23:09:00 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template <class T>
class vector_iterator {
 public:
  typedef typename ft::iterator_traits<T*>::value_type value_type;
  typedef typename ft::iterator_traits<T*>::pointer pointer;
  typedef typename ft::iterator_traits<T*>::reference reference;
  typedef typename ft::iterator_traits<T*>::difference_type difference_type;
  typedef typename ft::iterator_traits<T*>::iterator_category iterator_category;

 private:
  pointer _ptr;

 public:
  vector_iterator() : _ptr(pointer()) {}

  vector_iterator(pointer ptr) : _ptr(ptr) {}

  template <class C>
  vector_iterator(const vector_iterator<C>& other) {
    _ptr = other.base();
  }

  vector_iterator& operator=(const vector_iterator& other) {
    _ptr = other.base();
    return *this;
  }

  ~vector_iterator() {}

  pointer base() const { return _ptr; }

  reference operator*() const { return *_ptr; }

  pointer operator->() const { return _ptr; }

  reference operator[](difference_type n) const { return *(_ptr + n); }

  vector_iterator& operator++() {
    ++_ptr;
    return *this;
  }

  vector_iterator operator++(int) {
    vector_iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  vector_iterator& operator--() {
    --_ptr;
    return *this;
  }

  vector_iterator operator--(int) {
    vector_iterator tmp = *this;
    --(*this);
    return tmp;
  }

  vector_iterator operator+(const difference_type a) const {
    return vector_iterator(_ptr + a);
  }

  vector_iterator operator-(const difference_type& a) const {
    return vector_iterator(_ptr - a);
  }

  vector_iterator& operator+=(const difference_type& a) {
    _ptr += a;
    return *this;
  }

  vector_iterator& operator-=(const difference_type& a) {
    _ptr -= a;
    return *this;
  }

  difference_type operator-(const vector_iterator& a) const {
    return (_ptr - a._ptr);
  }
};

template <class T1, class T2>
bool operator==(const vector_iterator<T1>& lhs,
                const vector_iterator<T2>& rhs) {
  return lhs.base() == rhs.base();
}

template <class T1, class T2>
bool operator!=(const vector_iterator<T1>& lhs,
                const vector_iterator<T2>& rhs) {
  return lhs.base() != rhs.base();
}

template <class T1, class T2>
bool operator<(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs) {
  return lhs.base() < rhs.base();
}

template <class T1, class T2>
bool operator<=(const vector_iterator<T1>& lhs,
                const vector_iterator<T2>& rhs) {
  return lhs.base() <= rhs.base();
}

template <class T1, class T2>
bool operator>(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs) {
  return lhs.base() > rhs.base();
}

template <class T1, class T2>
bool operator>=(const vector_iterator<T1>& lhs,
                const vector_iterator<T2>& rhs) {
  return lhs.base() >= rhs.base();
}

template <class Iterator>
class vector_reverse_iterator {
 public:
  typedef typename ft::iterator_traits<Iterator>::value_type value_type;
  typedef typename ft::iterator_traits<Iterator>::pointer pointer;
  typedef typename ft::iterator_traits<Iterator>::reference reference;
  typedef
      typename ft::iterator_traits<Iterator>::difference_type difference_type;
  typedef typename ft::iterator_traits<Iterator>::iterator_category
      iterator_category;

 private:
  Iterator _iter;

 public:
  vector_reverse_iterator() : _iter(Iterator()) {}

  vector_reverse_iterator(Iterator iter) : _iter(iter) {}

  vector_reverse_iterator(const vector_reverse_iterator& other) {
    _iter = other.base();
  }

  vector_reverse_iterator& operator=(const vector_reverse_iterator& other) {
    _iter = other.base();
    return *this;
  }

  ~vector_reverse_iterator() {}

  Iterator base() const { return _iter; }

  reference operator*() const { return *_iter; }

  pointer operator->() const { return _iter.base(); }

  reference operator[](difference_type n) const { return *(_iter - n); }

  vector_reverse_iterator& operator++() {
    --_iter;
    return *this;
  }
  vector_reverse_iterator operator++(int) {
    vector_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  vector_reverse_iterator& operator--() {
    ++_iter;
    return *this;
  }

  vector_reverse_iterator operator--(int) {
    vector_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
  }

  vector_reverse_iterator operator+(const difference_type a) const {
    return vector_reverse_iterator(_iter - a);
  }

  vector_reverse_iterator operator-(const difference_type& a) const {
    return vector_reverse_iterator(_iter + a);
  }

  vector_reverse_iterator& operator+=(const difference_type& a) {
    _iter -= a;
    return *this;
  }

  vector_reverse_iterator& operator-=(const difference_type& a) {
    _iter += a;
    return *this;
  }

  difference_type operator-(const vector_reverse_iterator& a) const {
    return (a.base() - base());
  }
};

template <class T1, class T2>
bool operator==(const vector_reverse_iterator<T1>& lhs,
                const vector_reverse_iterator<T2>& rhs) {
  return lhs.base() == rhs.base();
}

template <class T1, class T2>
bool operator!=(const vector_reverse_iterator<T1>& lhs,
                const vector_reverse_iterator<T2>& rhs) {
  return lhs.base() != rhs.base();
}

template <class T1, class T2>
bool operator<(const vector_reverse_iterator<T1>& lhs,
               const vector_reverse_iterator<T2>& rhs) {
  return rhs.base() < lhs.base();
}

template <class T1, class T2>
bool operator<=(const vector_reverse_iterator<T1>& lhs,
                const vector_reverse_iterator<T2>& rhs) {
  return rhs.base() <= lhs.base();
}

template <class T1, class T2>
bool operator>(const vector_reverse_iterator<T1>& lhs,
               const vector_reverse_iterator<T2>& rhs) {
  return rhs.base() > lhs.base();
}

template <class T1, class T2>
bool operator>=(const vector_reverse_iterator<T1>& lhs,
                const vector_reverse_iterator<T2>& rhs) {
  return rhs.base() >= lhs.base();
}
}  // namespace ft

#endif
