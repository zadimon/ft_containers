/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:56:05 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/12/02 21:12:45 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "vector_iterator.hpp"

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector {
 public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef vector_iterator<value_type> iterator;
  typedef vector_iterator<const value_type> const_iterator;
  typedef vector_reverse_iterator<iterator> reverse_iterator;
  typedef vector_reverse_iterator<const_iterator> const_reverse_iterator;
  typedef typename allocator_type::difference_type difference_type;
  typedef typename allocator_type::size_type size_type;

 private:
  pointer _array;
  size_type _size;
  size_type _capacity;
  allocator_type _alloc;

 public:
  explicit vector(const allocator_type& alloc = allocator_type())
      : _array(0), _size(0), _capacity(0), _alloc(alloc) {}

  explicit vector(size_type n, const value_type& val = value_type(),
                  const allocator_type& alloc = allocator_type())
      : _size(n), _capacity(n), _alloc(alloc) {
    _array = _alloc.allocate(n);
    for (size_type i = 0; i < n; i++) {
      _alloc.construct(_array + i, val);
    }
  }

  template <class InputIt>
  vector(InputIt first, InputIt last,
         const allocator_type& alloc = allocator_type(),
         typename ft::enable_if<!ft::is_integral<InputIt>::val,
                                InputIt>::type* = nullptr)
      : _alloc(alloc) {
    if (first > last) {
      throw std::length_error("vector");
    }
    _size = last - first;
    _array = _alloc.allocate(_size);
    for (size_type i = 0; i < _size; i++) {
      _alloc.construct(_array + i, *(first + i));
    }
    _capacity = _size;
  }

  vector(const vector& x) {
    _size = x.size();
    _array = _alloc.allocate(_size);
    _capacity = _size;
    for (size_type i = 0; i < _size; i++) {
      _alloc.construct(_array + i, x[i]);
    }
  }

  vector& operator=(const vector& x) {
    if (this == &x) {
      return *this;
    }
    for (size_type i = 0; i < _size; i++) {
      _alloc.destroy(_array + i);
    }
    _size = x.size();
    if (_size > _capacity) {
      _alloc.deallocate(_array, _capacity);
      _array = _alloc.allocate(_size);
      _capacity = _size;
    }
    for (size_type i = 0; i < _size; i++) {
      _alloc.construct(_array + i, x[i]);
    }
    return *this;
  }

  ~vector() {
    for (size_type i = 0; i < _size; i++) {
      _alloc.destroy(_array + i);
    }
    _alloc.deallocate(_array, _capacity);
  }

  iterator begin() { return (iterator(_array)); }

  const_iterator begin() const { return (const_iterator(_array)); }

  iterator end() { return (iterator(_array + _size)); }

  const_iterator end() const { return (const_iterator(_array + _size)); }

  reverse_iterator rbegin() { return (reverse_iterator(end() - 1)); }

  const_reverse_iterator rbegin() const {
    return (const_reverse_iterator(end() - 1));
  }

  reverse_iterator rend() { return (reverse_iterator(begin() - 1)); }

  const_reverse_iterator rend() const {
    return (const_reverse_iterator(begin() - 1));
  }

  size_type size() const { return (_size); }

  size_type max_size() const { return (_alloc.max_size()); }

  void resize(size_type n, value_type val = value_type()) {
    if (n < _size) {
      for (size_type i = n; i < _size; i++) {
        _alloc.destroy(_array + i);
      }
    } else if (n > _size) {
      if (n > _capacity) {
        n < _capacity * 2 ? reserve(_capacity * 2) : reserve(n);
      }
      for (size_type i = _size; i < n; i++) {
        _alloc.construct(_array + i, val);
      }
    }
    _size = n;
  }

  size_type capacity() const { return (_capacity); }

  bool empty() const {
    if (_size > 0) {
      return false;
    }
    return true;
  }

  void reserve(size_type n) {
    if (n > _capacity) {
      pointer new_array = _alloc.allocate(n);
      for (size_type i = 0; i < _size; i++) {
        _alloc.construct(new_array + i, _array[i]);
      }
      for (size_type i = 0; i < _size; i++) {
        _alloc.destroy(_array + i);
      }
      _alloc.deallocate(_array, _capacity);
      _capacity = n;
      _array = new_array;
    }
  }

  reference operator[](size_type n) { return (*(_array + n)); }

  const_reference operator[](size_type n) const { return (*(_array + n)); }

  reference at(size_type n) {
    if (n >= _size) {
      throw std::out_of_range("vector");
    }
    return (*(_array + n));
  }

  const_reference at(size_type n) const {
    if (n >= _size) {
      throw std::out_of_range("vector");
    }
    return (*(_array + n));
  }

  reference front() { return *_array; }

  const_reference front() const { return *_array; }

  reference back() { return *(_array + _size - 1); }

  const_reference back() const { return *(_array + _size - 1); }

  pointer data() { return _array; }

  const_pointer data() const { return _array; }

  template <class InputIt>
  void assign(InputIt first, InputIt last,
              typename ft::enable_if<!ft::is_integral<InputIt>::val,
                                     InputIt>::type* = nullptr) {
    _size = last - first;
    for (size_type i = 0; i < _size; i++) {
      _alloc.destroy(_array + 1);
    }
    if (_size > _capacity) {
      _alloc.deallocate(_array, _capacity);
      _array = _alloc.allocate(_size);
      _capacity = _size;
    }
    for (size_type i = 0; i < _size; i++) {
      _alloc.construct(_array + i, *(first + i));
    }
  }

  void assign(size_type n, const value_type& val) {
    for (size_type i = 0; i < _size; i++) {
      _alloc.destroy(_array + 1);
    }
    if (n > _capacity) {
      _alloc.deallocate(_array, _capacity);
      _array = _alloc.allocate(n);
      _capacity = n;
    }
    for (size_type i = 0; i < n; i++) {
      _alloc.construct(_array + i, val);
    }
    _size = n;
  }

  void push_back(const value_type& val) {
    if (_size == _capacity) {
      _capacity == 0 ? reserve(1) : reserve(_capacity * 2);
    }
    _alloc.construct(_array + _size, val);
    _size++;
  }

  void pop_back() {
    _alloc.destroy(_array + _size - 1);
    _size--;
  }

  iterator insert(iterator position, const value_type& val) {
    size_type pos_index = position - begin();
    if (_size == _capacity) {
      _capacity == 0 ? reserve(1) : reserve(_capacity * 2);
    }
    _size++;
    for (size_type i = _size - 1; i > pos_index; i--) {
      _alloc.construct(_array + i, _array[i - 1]);
      _alloc.destroy(_array + i - 1);
    }
    _alloc.construct(_array + pos_index, val);
    return iterator(_array + pos_index);
  }

  iterator insert(iterator position, size_type n, const value_type& val) {
    if (n == 0) {
      return position;
    }
    size_type pos_index = position - begin();
    _size += n;
    if (_size > _capacity) {
      _size < 2 * _capacity ? reserve(2 * _capacity) : reserve(_size + n);
    }
    for (size_type i = _size - 1; i >= pos_index + n; i--) {
      _alloc.construct(_array + i, _array[i - n]);
      _alloc.destroy(_array + i - n);
    }
    for (size_type i = pos_index; i < pos_index + n; i++) {
      _alloc.construct(_array + i, val);
    }
    return iterator(_array + pos_index);
  }

  template <class InputIt>
  iterator insert(iterator position, InputIt first, InputIt last,
                  typename ft::enable_if<!ft::is_integral<InputIt>::val,
                                         InputIt>::type* = nullptr) {
    size_type n = last - first;
    if (n == 0) {
      return position;
    }
    size_type pos_index = position - begin();
    _size += n;
    if (_size > _capacity) {
      _size < 2 * _capacity ? reserve(2 * _capacity) : reserve(_size + n);
    }
    for (size_type i = _size - 1; i >= pos_index + n; i--) {
      _alloc.construct(_array + i, _array[i - n]);
      _alloc.destroy(_array + i - n);
    }
    for (size_type i = pos_index; i < pos_index + n; i++, first++) {
      _alloc.construct(_array + i, *first);
    }
    return iterator(_array + pos_index);
  }

  iterator erase(iterator position) {
    size_type pos_index = position - begin();
    _alloc.destroy(_array + pos_index);
    for (size_type i = pos_index; i < _size - 1; i++) {
      _alloc.construct(_array + i, _array[i + 1]);
      _alloc.destroy(_array + i + 1);
    }
    _size--;
    return iterator(_array + pos_index);
  }

  iterator erase(iterator first, iterator last) {
    size_type n = last - first;
    if (n == 0) {
      return first;
    }
    size_type pos_index = first - begin();
    for (size_type i = pos_index; i < pos_index + n; i++) {
      _alloc.destroy(_array + i);
    }
    for (size_type i = pos_index; i < pos_index + n; i++) {
      _alloc.construct(_array + i, _array[i + n]);
      _alloc.destroy(_array + i + n);
    }
    _size -= n;
    return (_array + pos_index);
  }

  void swap(vector& other) {
    if (this == &other) {
      return;
    }
    vector tmp = *this;
    *this = other;
    other = tmp;
  }

  void clear() {
    for (size_type i = 0; i < _size; i++) {
      _alloc.destroy(_array + i);
    }
    _size = 0;
  }

  allocator_type get_allocator() const { return (_alloc); }

  template <class A, class Alloc>
  friend bool operator==(const vector<A, Alloc>& lhs,
                         const vector<A, Alloc>& rhs);

  template <class A, class Alloc>
  friend bool operator!=(const vector<A, Alloc>& lhs,
                         const vector<A, Alloc>& rhs);

  template <class A, class Alloc>
  friend bool operator<(const vector<A, Alloc>& lhs,
                        const vector<A, Alloc>& rhs);

  template <class A, class Alloc>
  friend bool operator<=(const vector<A, Alloc>& lhs,
                         const vector<A, Alloc>& rhs);

  template <class A, class Alloc>
  friend bool operator>(const vector<A, Alloc>& lhs,
                        const vector<A, Alloc>& rhs);

  template <class A, class Alloc>
  friend bool operator>=(const vector<A, Alloc>& lhs,
                         const vector<A, Alloc>& rhs);

  template <class A, class Alloc>
  friend void swap(vector<A, Alloc>& lhs, vector<A, Alloc>& rhs);
};

template <class A, class Alloc>
bool operator==(const vector<A, Alloc>& lhs, const vector<A, Alloc>& rhs) {
  if (lhs._size != rhs._size) {
    return false;
  }
  for (size_t i = 0; i < lhs._size; i++) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

template <class A, class Alloc>
bool operator!=(const vector<A, Alloc>& lhs, const vector<A, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <class A, class Alloc>
bool operator<(const vector<A, Alloc>& lhs, const vector<A, Alloc>& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end());
}

template <class A, class Alloc>
bool operator<=(const vector<A, Alloc>& lhs, const vector<A, Alloc>& rhs) {
  return !(rhs < lhs);
}

template <class A, class Alloc>
bool operator>(const vector<A, Alloc>& lhs, const vector<A, Alloc>& rhs) {
  return rhs < lhs;
}

template <class A, class Alloc>
bool operator>=(const vector<A, Alloc>& lhs, const vector<A, Alloc>& rhs) {
  return !(lhs < rhs);
}

template <class A, class Alloc>
void swap(vector<A, Alloc>& lhs, vector<A, Alloc>& rhs) {
  lhs.swap(rhs);
}
}  // namespace ft

#endif
