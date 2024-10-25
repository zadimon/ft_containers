#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include <iostream>

#include "iterator_traits.hpp"

namespace ft {

template <class T>
class red_black_tree_iterator {
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
  typedef typename ft::iterator_traits<T*>::value_type value_type;
  typedef typename ft::iterator_traits<T*>::pointer pointer;
  typedef const value_type& reference;
  typedef typename ft::iterator_traits<T*>::difference_type difference_type;
  typedef typename std::bidirectional_iterator_tag iterator_category;
  typedef node* node_ptr;

 private:
  node_ptr _node;

 public:
  red_black_tree_iterator() : _node(node_ptr()) {}

  red_black_tree_iterator(void* node) : _node(static_cast<node_ptr>(node)) {}

  red_black_tree_iterator(const red_black_tree_iterator& other) {
    _node = other.base();
  }

  red_black_tree_iterator& operator=(const red_black_tree_iterator& other) {
    _node = other.base();
    return *this;
  }

  ~red_black_tree_iterator() {}

  node_ptr base() const { return _node; }

  reference operator*() const { return _node->val; }

  pointer operator->() const { return &_node->val; }

  red_black_tree_iterator& operator++() {
    if (_node->right) {
      _node = _node->right;
      while (_node->left) {
        _node = _node->left;
      }
    } else {
      node_ptr y = _node->parent;
      while (y && _node == y->right) {
        _node = y;
        y = y->parent;
      }
      if (y) _node = y;
    }
    return *this;
  }

  red_black_tree_iterator operator++(int) {
    red_black_tree_iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  red_black_tree_iterator& operator--() {
    if (_node->left) {
      _node = _node->left;
      while (_node->right) {
        _node = _node->right;
      }
    } else {
      node_ptr y = _node->parent;
      while (y && _node == y->left) {
        _node = y;
        y = y->parent;
      }
      if (y) _node = y;
    }
    return *this;
  }

  red_black_tree_iterator operator--(int) {
    red_black_tree_iterator tmp = *this;
    --(*this);
    return tmp;
  }
};

template <class T1, class T2>
bool operator==(const red_black_tree_iterator<T1>& lhs,
                const red_black_tree_iterator<T2>& rhs) {
  return lhs.base() == rhs.base();
}

template <class T1, class T2>
bool operator!=(const red_black_tree_iterator<T1>& lhs,
                const red_black_tree_iterator<T2>& rhs) {
  return lhs.base() != rhs.base();
}

template <class Iterator>
class red_black_tree_reverse_iterator {
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
  red_black_tree_reverse_iterator() : _iter(Iterator()) {}

  red_black_tree_reverse_iterator(Iterator iter) : _iter(iter) {}

  red_black_tree_reverse_iterator(
      const red_black_tree_reverse_iterator& other) {
    _iter = other.base();
  }

  red_black_tree_reverse_iterator& operator=(
      const red_black_tree_reverse_iterator& other) {
    _iter = other.base();
    return *this;
  }

  ~red_black_tree_reverse_iterator() {}

  Iterator base() const { return _iter; }

  reference operator*() const { return *_iter; }

  pointer operator->() const { return &_iter.base()->val; }

  red_black_tree_reverse_iterator& operator++() {
    --_iter;
    return *this;
  }

  red_black_tree_reverse_iterator operator++(int) {
    red_black_tree_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  red_black_tree_reverse_iterator& operator--() {
    ++_iter;
    return *this;
  }

  red_black_tree_reverse_iterator operator--(int) {
    red_black_tree_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
  }
};

template <class T1, class T2>
bool operator==(const red_black_tree_reverse_iterator<T1>& lhs,
                const red_black_tree_reverse_iterator<T2>& rhs) {
  return lhs.base() == rhs.base();
}

template <class T1, class T2>
bool operator!=(const red_black_tree_reverse_iterator<T1>& lhs,
                const red_black_tree_reverse_iterator<T2>& rhs) {
  return lhs.base() != rhs.base();
}
}  // namespace ft

#endif
