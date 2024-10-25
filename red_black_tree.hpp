/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:18:02 by ebhakaz           #+#    #+#             */
/*   Updated: 2022/12/07 17:48:57 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include <memory>

#include "lexicographical_compare.hpp"
#include "pair.hpp"
#include "red_black_tree_iterator.hpp"

namespace ft {

template <class T, class Compare = std::less<T>,
          class Allocator = std::allocator<T> >
class red_black_tree {
 private:
  enum Color { RED, BLACK };

  struct node {
    T val;
    Color color;
    node* left;
    node* right;
    node* parent;

    node()
        : val(T()),
          color(RED),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}

    explicit node(const T& val)
        : val(val),
          color(RED),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}

    node(const T& val, Color color, node* left, node* right, node* parent)
        : val(val), color(color), left(left), right(right), parent(parent) {}

    node(const node& other)
        : val(other.val),
          color(other.color),
          left(other.left),
          right(other.right),
          parent(other.parent) {}

    ~node() {}

    node& operator=(const node& other) {
      val = other.val;
      color = other.color;
      left = other.left;
      right = other.right;
      parent = other.parent;
      return *this;
    }
  };

 public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename Allocator::template rebind<node>::other node_allocator_type;
  typedef size_t size_type;
  typedef typename node_allocator_type::difference_type difference_type;
  typedef Compare key_compare;
  typedef Compare value_compare;
  typedef typename node_allocator_type::reference reference;
  typedef typename node_allocator_type::const_reference const_reference;
  typedef typename node_allocator_type::pointer pointer;
  typedef typename node_allocator_type::const_pointer const_pointer;
  typedef red_black_tree_iterator<value_type> iterator;
  typedef red_black_tree_iterator<value_type> const_iterator;
  typedef red_black_tree_reverse_iterator<iterator> reverse_iterator;
  typedef red_black_tree_reverse_iterator<const_iterator>
      const_reverse_iterator;

 private:
  pointer _root;
  pointer _sentinel;
  size_type _size;
  allocator_type _elem_alloc;
  node_allocator_type _node_alloc;
  value_compare _compare;

  void _rotate_left(pointer x) {
    pointer y = x->right;
    x->right = y->left;
    if (y->left) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent != _sentinel) {
      if (x == x->parent->left) {
        x->parent->left = y;
      } else {
        x->parent->right = y;
      }
    } else {
      _root = y;
      _root->parent = _sentinel;
      _sentinel->left = _root;
      _sentinel->right = _root;
    }
    y->left = x;
    x->parent = y;
  }

  void _rotate_right(pointer x) {
    pointer y = x->left;
    x->left = y->right;
    if (y->right) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent != _sentinel) {
      if (x == x->parent->left) {
        x->parent->left = y;
      } else {
        x->parent->right = y;
      }
    } else {
      _root = y;
      _root->parent = _sentinel;
      _sentinel->left = _root;
      _sentinel->right = _root;
    }
    y->right = x;
    x->parent = y;
  }

  void _insert_fixup(pointer x) {
    while (x != _root && x->parent->color == RED) {
      if (x->parent == x->parent->parent->left) {
        pointer uncle = x->parent->parent->right;
        if (uncle && uncle->color == RED) {
          x->parent->color = BLACK;
          uncle->color = BLACK;
          x->parent->parent->color = RED;
          x = x->parent->parent;
        } else {
          if (x == x->parent->right) {
            x = x->parent;
            _rotate_left(x);
          }
          x->parent->color = BLACK;
          x->parent->parent->color = RED;
          _rotate_right(x->parent->parent);
        }
      } else {
        pointer uncle = x->parent->parent->left;
        if (uncle && uncle->color == RED) {
          x->parent->color = BLACK;
          uncle->color = BLACK;
          x->parent->parent->color = RED;
          x = x->parent->parent;
        } else {
          if (x == x->parent->left) {
            x = x->parent;
            _rotate_right(x);
          }
          x->parent->color = BLACK;
          x->parent->parent->color = RED;
          _rotate_left(x->parent->parent);
        }
      }
    }
    _root->color = BLACK;
  }

  void _delete_fixup(pointer x) {
    while (x != _root && x->color == BLACK) {
      if (x == x->parent->left) {
        pointer uncle = x->parent->right;
        if (uncle && uncle->color == RED) {
          uncle->color = BLACK;
          x->parent->color = RED;
          _rotate_left(x->parent);
          uncle = x->parent->right;
        }
        if (uncle && (!uncle->left || uncle->left->color == BLACK) &&
            (!uncle->right || uncle->right->color == BLACK)) {
          uncle->color = RED;
          x = x->parent;
        } else {
          if (uncle && (!uncle->right || uncle->right->color == BLACK)) {
            if (uncle->left) uncle->left->color = BLACK;
            uncle->color = RED;
            _rotate_right(uncle);
            uncle = x->parent->right;
          }
          if (uncle) uncle->color = x->parent->color;
          x->parent->color = BLACK;
          if (uncle && uncle->right) uncle->right->color = BLACK;
          _rotate_left(x->parent);
          x = _root;
        }
      } else {
        pointer uncle = x->parent->left;
        if (uncle && uncle->color == RED) {
          uncle->color = BLACK;
          x->parent->color = RED;
          _rotate_right(x->parent);
          uncle = x->parent->left;
        }
        if (uncle && (!uncle->left || uncle->left->color == BLACK) &&
            (!uncle->right || uncle->right->color == BLACK)) {
          uncle->color = RED;
          x = x->parent;
        } else {
          if (uncle && (!uncle->left || uncle->left->color == BLACK)) {
            if (uncle->right) uncle->right->color = BLACK;
            uncle->color = RED;
            _rotate_left(uncle);
            uncle = x->parent->left;
          }
          if (uncle) uncle->color = x->parent->color;
          x->parent->color = BLACK;
          if (uncle && uncle->left) uncle->left->color = BLACK;
          _rotate_right(x->parent);
          x = _root;
        }
      }
    }
    x->color = BLACK;
  }

  void _clear(pointer p) {
    if (p) {
      _clear(p->left);
      _clear(p->right);
      _node_alloc.destroy(p);
      _node_alloc.deallocate(p, 1);
    }
  }

  void _swap_node(pointer x, value_type& y) {
    pointer left = x->left;
    pointer right = x->right;
    pointer parent = x->parent;
    Color color = x->color;
    int is_left = 0;
    if (x == _root) {
      is_left = -1;
    } else if (x == x->parent->left) {
      is_left = 1;
    }
    _node_alloc.destroy(x);
    _node_alloc.deallocate(x, 1);
    pointer new_node = _node_alloc.allocate(1);
    _node_alloc.construct(new_node, y);
    new_node->color = color;
    new_node->left = left;
    if (left) left->parent = new_node;
    new_node->right = right;
    if (right) right->parent = new_node;
    new_node->parent = parent;
    if (is_left == -1) {
      _root = new_node;
      _sentinel->left = new_node;
      _sentinel->right = new_node;
    } else if (is_left == 1) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }
  }

 public:
  explicit red_black_tree(const value_compare& compare = key_compare(),
                          const allocator_type& alloc = allocator_type())
      : _root(nullptr),
        _size(0),
        _elem_alloc(alloc),
        _node_alloc(node_allocator_type()),
        _compare(compare) {
    pointer x = _node_alloc.allocate(1);
    _node_alloc.construct(x, value_type());
    x->color = BLACK;
    _sentinel = x;
  }

  template <class InputIterator>
  red_black_tree(InputIterator first, InputIterator last,
                 const value_compare& compare = key_compare(),
                 const allocator_type& alloc = allocator_type())
      : _root(nullptr),
        _size(0),
        _elem_alloc(alloc),
        _node_alloc(node_allocator_type()),
        _compare(compare) {
    pointer x = _node_alloc.allocate(1);
    _node_alloc.construct(x, value_type());
    x->color = BLACK;
    _sentinel = x;
    for (; first != last; first++) {
      insert(*first);
    }
  }

  red_black_tree(const red_black_tree& other)
      : _root(nullptr),
        _size(0),
        _elem_alloc(other._elem_alloc),
        _node_alloc(other._node_alloc),
        _compare(other._compare) {
    pointer x = _node_alloc.allocate(1);
    _node_alloc.construct(x, value_type());
    x->color = BLACK;
    _sentinel = x;
    iterator first = other.begin();
    iterator last = other.end();
    for (; first != last; first++) {
      insert(*first);
    }
  }

  ~red_black_tree() {
    clear();
    _node_alloc.destroy(_sentinel);
    _node_alloc.deallocate(_sentinel, 1);
    _size = 0;
  }

  red_black_tree& operator=(const red_black_tree& other) {
    if (this == &other) {
      return *this;
    }
    clear();
    _node_alloc.destroy(_sentinel);
    _node_alloc.deallocate(_sentinel, 1);
    _node_alloc = other._node_alloc;
    _compare = other._compare, _elem_alloc = other._elem_alloc;
    pointer x = _node_alloc.allocate(1);
    _node_alloc.construct(x, value_type());
    x->color = BLACK;
    _sentinel = x;
    const_iterator first = other.begin();
    const_iterator last = other.end();
    for (; first != last; first++) {
      insert(*first);
    }
    return *this;
  }

  iterator begin() {
    if (!_root) {
      return iterator(_sentinel);
    }
    pointer current = _root;
    while (current->left) {
      current = current->left;
    }
    return iterator(current);
  }

  const_iterator begin() const {
    if (!_root) {
      return const_iterator(_sentinel);
    }
    pointer current = _root;
    while (current->left) {
      current = current->left;
    }
    return const_iterator(current);
  }

  iterator end() { return iterator(_sentinel); }

  const_iterator end() const { return const_iterator(_sentinel); }

  reverse_iterator rbegin() {
    if (!_root) {
      return reverse_iterator(iterator(_sentinel));
    }
    pointer current = _root;
    while (current->right) {
      current = current->right;
    }
    return reverse_iterator(iterator(current));
  }

  const_reverse_iterator rbegin() const {
    if (!_root) {
      return const_reverse_iterator(const_iterator(_sentinel));
    }
    pointer current = _root;
    while (current->right) {
      current = current->right;
    }
    return const_reverse_iterator(const_iterator(current));
  }

  reverse_iterator rend() { return reverse_iterator(iterator(_sentinel)); }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(const_iterator(_sentinel));
  }

  bool empty() const {
    if (_size > 0) {
      return false;
    }
    return true;
  }

  size_type size() const { return (_size); }

  size_type max_size() const { return (_node_alloc.max_size()); }

  void clear() {
    _clear(_root);
    _root = nullptr;
    _size = 0;
  }

  ft::pair<iterator, bool> insert(const value_type& val) {
    pointer current = _root;
    pointer parent = nullptr;
    while (current) {
      if (!_compare(val, current->val) && !_compare(current->val, val)) {
        return pair<iterator, bool>(iterator(current), false);
      }
      parent = current;
      if (_compare(val, current->val)) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    pointer x = _node_alloc.allocate(1);
    _node_alloc.construct(x, val);
    x->parent = parent;
    if (parent) {
      if (_compare(val, parent->val)) {
        parent->left = x;
      } else {
        parent->right = x;
      }
    } else {
      _root = x;
      _root->parent = _sentinel;
      _sentinel->left = _root;
      _sentinel->right = _root;
    }
    _insert_fixup(x);
    _size++;
    return pair<iterator, bool>(iterator(x), true);
  }

  iterator insert(iterator pos, const value_type& val) {
    iterator tmp1 = pos;
    iterator next = ++tmp1;
    if (pos != end() && _compare(*pos, val) && next == end()) {
      void* tmp = pos.base();
      pointer parent = static_cast<pointer>(tmp);
      pointer x = _node_alloc.allocate(1);
      _node_alloc.construct(x, val);
      x->parent = parent;
      parent->right = x;
      _insert_fixup(x);
    }
    ft::pair<iterator, bool> pair = insert(val);
    return iterator(pair.first);
  }

  template <class InputIt>
  void insert(InputIt first, InputIt last) {
    for (; first != last; first++) {
      insert(*first);
    }
  }

  void erase(iterator pos) {
    void* tmp = pos.base();
    pointer x = static_cast<pointer>(tmp);
    pointer y, z;
    if (!x || x == _sentinel) return;
    if (x->left && x->right) {
      y = x->left;
      while (y->right) y = y->right;
      _swap_node(x, y->val);
    } else {
      y = x;
    }
    if (y->left) {
      z = y->left;
    } else if (y->right) {
      z = y->right;
    } else {
      z = y;
    }
    if (z != y) {
      if (z) z->parent = y->parent;
      if (z->parent != _sentinel) {
        if (y == y->parent->left) {
          y->parent->left = z;
        } else {
          y->parent->right = z;
        }
      } else {
        _root = z;
        _root->parent = _sentinel;
        _sentinel->left = _root;
        _sentinel->right = _root;
      }
    }
    if (y->color == BLACK) _delete_fixup(z);
    if (z == y) {
      if (y->parent != _sentinel) {
        if (y == y->parent->left) {
          y->parent->left = nullptr;
        } else {
          y->parent->right = nullptr;
        }
      } else {
        _root = nullptr;
        _sentinel->left = _root;
        _sentinel->right = _root;
      }
    }
    _node_alloc.destroy(y);
    _node_alloc.deallocate(y, 1);
    _size--;
  }

  size_type erase(const value_type& val) {
    iterator it = find(val);
    erase(it);
    if (it != end()) {
      return 1;
    }
    return 0;
  }

  void erase(iterator first, iterator last) {
    while (first != last) {
      erase(first++);
    }
  }

  void swap(red_black_tree& other) {
    if (this == &other) {
      return;
    }
    red_black_tree tmp = *this;
    *this = other;
    other = tmp;
  }

  size_type count(const value_type& val) const {
    if (find(val) != end()) {
      return 1;
    }
    return 0;
  }

  iterator find(const value_type& val) {
    pointer current = _root;
    while (current) {
      if (!_compare(val, current->val) && !_compare(current->val, val)) {
        return iterator(current);
      }
      if (_compare(val, current->val)) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return end();
  }

  const_iterator find(const value_type& val) const {
    pointer current = _root;
    while (current) {
      if (!_compare(val, current->val) && !_compare(current->val, val)) {
        return const_iterator(current);
      }
      if (_compare(val, current->val)) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return end();
  }

  ft::pair<iterator, iterator> equal_range(const value_type& val) {
    return pair<iterator, iterator>(lower_bound(val), upper_bound(val));
  }

  ft::pair<const_iterator, const_iterator> equal_range(
      const value_type& val) const {
    return pair<const_iterator, const_iterator>(lower_bound(val),
                                                upper_bound(val));
  }

  iterator lower_bound(const value_type& val) {
    iterator it_begin = begin();
    iterator it_end = end();
    for (; it_begin != it_end; it_begin++) {
      if (!_compare(*it_begin, val)) {
        return it_begin;
      }
    }
    return --it_end;
  }

  const_iterator lower_bound(const value_type& val) const {
    const_iterator it_begin = begin();
    const_iterator it_end = end();
    for (; it_begin != it_end; it_begin++) {
      if (!_compare(*it_begin, val)) {
        return it_begin;
      }
    }
    return --it_end;
  }

  iterator upper_bound(const value_type& val) {
    iterator it_begin = begin();
    iterator it_end = end();
    for (; it_begin != it_end; it_begin++) {
      if (_compare(val, *it_begin)) {
        return it_begin;
      }
    }
    return it_end;
  }

  const_iterator upper_bound(const value_type& val) const {
    const_iterator it_begin = begin();
    const_iterator it_end = end();
    for (; it_begin != it_end; it_begin++) {
      if (_compare(val, *it_begin)) {
        return it_begin;
      }
    }
    return it_end;
  }

  key_compare key_comp() const { return _compare; }

  value_compare value_comp() const { return _compare; }

  void _print_all_nodes(pointer p) const {
    if (p) {
      _print_all_nodes(p->left);
      std::cout << "Address: " << p;
      std::cout << " val: " << p->val;
      std::cout << " color: ";
      p->color == 0 ? std::cout << " RED " : std::cout << " BLACK ";
      std::cout << " left: ";
      p->left ? std::cout << p->left->val : std::cout << " NULL ";
      std::cout << " right: ";
      p->right ? std::cout << p->right->val : std::cout << " NULL ";
      std::cout << " parent: ";
      p->parent ? std::cout << p->parent->val : std::cout << " NULL ";
      std::cout << std::endl;
      _print_all_nodes(p->right);
    }
  }

  void print_tree() const {
    _print_all_nodes(_root);
    //    std::cout << "Address: " << _sentinel;
    //    std::cout << " val: " << _sentinel->val;
    //    std::cout << " color: ";
    //    _sentinel->color == 0 ? std::cout << " RED " : std::cout << " BLACK ";
    //    std::cout << " left: ";
    //    _sentinel->left ? std::cout << _sentinel->left->val : std::cout << "
    //    NULL "; std::cout << " right: "; _sentinel->right ? std::cout <<
    //    _sentinel->right->val: std::cout << " NULL ";std::cout << " parent: ";
    //    _sentinel->parent ? std::cout << _sentinel->parent->val
    //                      : std::cout << " NULL ";
    //    std::cout << std::endl;
  }

  template <class A, class Comp, class Alloc>
  friend bool operator==(const red_black_tree<A, Comp, Alloc>& lhs,
                         const red_black_tree<A, Comp, Alloc>& rhs);

  template <class A, class Comp, class Alloc>
  friend bool operator!=(const red_black_tree<A, Comp, Alloc>& lhs,
                         const red_black_tree<A, Comp, Alloc>& rhs);

  template <class A, class Comp, class Alloc>
  friend bool operator<(const red_black_tree<A, Comp, Alloc>& lhs,
                        const red_black_tree<A, Comp, Alloc>& rhs);

  template <class A, class Comp, class Alloc>
  friend bool operator<=(const red_black_tree<A, Comp, Alloc>& lhs,
                         const red_black_tree<A, Comp, Alloc>& rhs);

  template <class A, class Comp, class Alloc>
  friend bool operator>(const red_black_tree<A, Comp, Alloc>& lhs,
                        const red_black_tree<A, Comp, Alloc>& rhs);

  template <class A, class Comp, class Alloc>
  friend bool operator>=(const red_black_tree<A, Comp, Alloc>& lhs,
                         const red_black_tree<A, Comp, Alloc>& rhs);
};

template <class A, class Comp, class Alloc>
bool operator==(const red_black_tree<A, Comp, Alloc>& lhs,
                const red_black_tree<A, Comp, Alloc>& rhs) {
  if (lhs._size != rhs._size) {
    return false;
  }
  typename ft::red_black_tree<A, Comp, Alloc>::iterator begin_lhs = lhs.begin();
  typename ft::red_black_tree<A, Comp, Alloc>::iterator end_lhs = lhs.end();
  typename ft::red_black_tree<A, Comp, Alloc>::iterator begin_rhs = rhs.begin();
  typename ft::red_black_tree<A, Comp, Alloc>::iterator end_rhs = rhs.end();
  for (; begin_lhs != end_lhs && begin_rhs != end_rhs;
       begin_lhs++, begin_rhs++) {
    if (begin_lhs != begin_rhs) {
      return false;
    }
  }
  return true;
}

template <class A, class Comp, class Alloc>
bool operator!=(const red_black_tree<A, Comp, Alloc>& lhs,
                const red_black_tree<A, Comp, Alloc>& rhs) {
  return !(lhs == rhs);
}

template <class A, class Comp, class Alloc>
bool operator<(const red_black_tree<A, Comp, Alloc>& lhs,
               const red_black_tree<A, Comp, Alloc>& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end());
}

template <class A, class Comp, class Alloc>
bool operator<=(const red_black_tree<A, Comp, Alloc>& lhs,
                const red_black_tree<A, Comp, Alloc>& rhs) {
  return !(rhs < lhs);
}

template <class A, class Comp, class Alloc>
bool operator>(const red_black_tree<A, Comp, Alloc>& lhs,
               const red_black_tree<A, Comp, Alloc>& rhs) {
  return rhs < lhs;
}

template <class A, class Comp, class Alloc>
bool operator>=(const red_black_tree<A, Comp, Alloc>& lhs,
                const red_black_tree<A, Comp, Alloc>& rhs) {
  return !(lhs < rhs);
}
}  // namespace ft

#endif
