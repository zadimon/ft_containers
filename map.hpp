#ifndef MAP_HPP
#define MAP_HPP

#include <memory>

#include "pair.hpp"
#include "red_black_tree.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {
 private:
  class value_comp {
   private:
    Compare _compare;

   public:
    value_comp() : _compare(Compare()) {}

    value_comp(const Compare& compare) : _compare(compare) {}

    bool operator()(const ft::pair<const Key, T>& lhs,
                    const ft::pair<const Key, T>& rhs) const {
      return _compare(lhs.first, rhs.first);
    }
  };

 public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef ft::pair<const key_type, mapped_type> value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
  typedef Compare key_compare;
  typedef value_comp value_compare;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef ft::red_black_tree<value_type, value_compare, allocator_type>
      tree_type;
  typedef typename tree_type::iterator iterator;
  typedef typename tree_type::const_iterator const_iterator;
  typedef typename tree_type::reverse_iterator reverse_iterator;
  typedef typename tree_type::const_reverse_iterator const_reverse_iterator;

 private:
  tree_type _tree;
  size_type _size;
  allocator_type _alloc;
  key_compare _compare;

 public:
  explicit map(const key_compare& compare = key_compare(),
               const Allocator& alloc = allocator_type())
      : _tree(tree_type(_compare, _alloc)),
        _size(_tree.size()),
        _alloc(alloc),
        _compare(compare) {}

  template <class InputIt>
  map(InputIt first, InputIt last, const key_compare& compare = key_compare(),
      const allocator_type& alloc = allocator_type())
      : _tree(tree_type(first, last, compare, alloc)),
        _size(_tree.size()),
        _alloc(alloc),
        _compare(compare) {}

  map(const map& other) { *this = other; }

  ~map() {}

  map& operator=(const map& other) {
    _tree = other._tree;
    _size = other._size;
    _compare = other._compare;
    _alloc = other._alloc;
    return *this;
  }

  allocator_type get_allocator() const { return _alloc; }

  mapped_type& at(const key_type& key) {
    iterator res = _tree.find(ft::make_pair(key, mapped_type()));
    if (res == _tree.end()) {
      throw std::out_of_range("map::at: key not found");
    }
    return res->second;
  }

  mapped_type& operator[](const key_type& key) {
    ft::pair<iterator, bool> res =
        _tree.insert(ft::make_pair(key, mapped_type()));
    return res.first->second;
  }

  iterator begin() { return _tree.begin(); }

  const_iterator begin() const { return _tree.begin(); }

  iterator end() { return _tree.end(); }

  const_iterator end() const { return _tree.end(); }

  reverse_iterator rbegin() { return _tree.rbegin(); }

  const_reverse_iterator rbegin() const { return _tree.rbegin(); }

  reverse_iterator rend() { return _tree.rend(); }

  const_reverse_iterator rend() const { return _tree.rend(); }

  bool empty() const { return _tree.empty(); }

  size_type size() const { return _tree.size(); }

  size_type max_size() const { return _tree.max_size(); }

  void clear() {
    _tree.clear();
    _size = _tree.size();
  }

  ft::pair<iterator, bool> insert(const value_type& value) {
    return _tree.insert(value);
  }

  iterator insert(iterator pos, const value_type& value) {
    return _tree.insert(pos, value);
  }

  template <class InputIt>
  void insert(InputIt first, InputIt last) {
    _tree.insert(first, last);
  }

  void erase(iterator pos) { _tree.erase(pos); }

  void erase(iterator first, iterator last) { _tree.erase(first, last); }

  size_type erase(const key_type& key) {
    return _tree.erase(ft::make_pair(key, mapped_type()));
  }

  void swap(map& other) {
    if (this == &other) {
      return;
    }
    map tmp = *this;
    *this = other;
    other = tmp;
  }

  size_type count(const key_type& key) const {
    return _tree.count(ft::make_pair(key, mapped_type()));
  }

  iterator find(const key_type& key) {
    return _tree.find(ft::make_pair(key, mapped_type()));
  }

  const_iterator find(const key_type& key) const {
    return _tree.find(ft::make_pair(key, mapped_type()));
  }

  ft::pair<iterator, iterator> equal_range(const key_type& key) {
    return _tree.equal_range(ft::make_pair(key, mapped_type()));
  }

  ft::pair<const_iterator, const_iterator> equal_range(
      const key_type& key) const {
    return _tree.equal_range(ft::make_pair(key, mapped_type()));
  }

  iterator lower_bound(const key_type& key) {
    return _tree.lower_bound(ft::make_pair(key, mapped_type()));
  }

  const_iterator lower_bound(const key_type& key) const {
    return _tree.lower_bound(ft::make_pair(key, mapped_type()));
  }

  iterator upper_bound(const key_type& key) {
    return _tree.upper_bound(ft::make_pair(key, mapped_type()));
  }

  const_iterator upper_bound(const key_type& key) const {
    return _tree.upper_bound(ft::make_pair(key, mapped_type()));
  }

  key_compare key_comp() const { return _compare; }

  value_compare value_comp() const { return value_compare(); }

  template <class K, class A, class Comp, class Alloc>
  friend bool operator==(const map<K, A, Comp, Alloc>& lhs,
                         const map<K, A, Comp, Alloc>& rhs);

  template <class K, class A, class Comp, class Alloc>
  friend bool operator!=(const map<K, A, Comp, Alloc>& lhs,
                         const map<K, A, Comp, Alloc>& rhs);

  template <class K, class A, class Comp, class Alloc>
  friend bool operator<(const map<K, A, Comp, Alloc>& lhs,
                        const map<K, A, Comp, Alloc>& rhs);

  template <class K, class A, class Comp, class Alloc>
  friend bool operator<=(const map<K, A, Comp, Alloc>& lhs,
                         const map<K, A, Comp, Alloc>& rhs);

  template <class K, class A, class Comp, class Alloc>
  friend bool operator>(const map<K, A, Comp, Alloc>& lhs,
                        const map<K, A, Comp, Alloc>& rhs);

  template <class K, class A, class Comp, class Alloc>
  friend bool operator>=(const map<K, A, Comp, Alloc>& lhs,
                         const map<K, A, Comp, Alloc>& rhs);

  template <class K, class A, class Comp, class Alloc>
  friend void swap(map<K, A, Comp, Alloc>& lhs, map<K, A, Comp, Alloc>& rhs);
};

template <class K, class A, class Comp, class Alloc>
bool operator==(const map<K, A, Comp, Alloc>& lhs,
                const map<K, A, Comp, Alloc>& rhs) {
  return lhs._tree == rhs._tree;
}

template <class K, class A, class Comp, class Alloc>
bool operator!=(const map<K, A, Comp, Alloc>& lhs,
                const map<K, A, Comp, Alloc>& rhs) {
  return lhs._tree != rhs._tree;
}

template <class K, class A, class Comp, class Alloc>
bool operator<(const map<K, A, Comp, Alloc>& lhs,
               const map<K, A, Comp, Alloc>& rhs) {
  return lhs._tree < rhs._tree;
}

template <class K, class A, class Comp, class Alloc>
bool operator<=(const map<K, A, Comp, Alloc>& lhs,
                const map<K, A, Comp, Alloc>& rhs) {
  return lhs._tree <= rhs._tree;
}

template <class K, class A, class Comp, class Alloc>
bool operator>(const map<K, A, Comp, Alloc>& lhs,
               const map<K, A, Comp, Alloc>& rhs) {
  return lhs._tree > rhs._tree;
}

template <class K, class A, class Comp, class Alloc>
bool operator>=(const map<K, A, Comp, Alloc>& lhs,
                const map<K, A, Comp, Alloc>& rhs) {
  return lhs._tree >= rhs._tree;
}

template <class K, class A, class Comp, class Alloc>
void swap(map<K, A, Comp, Alloc>& lhs, map<K, A, Comp, Alloc>& rhs) {
  lhs.swap(rhs);
}
}  // namespace ft

#endif
