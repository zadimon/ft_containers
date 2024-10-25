#include "../main.hpp"

void print_set(ft::set<int> set) {
  ft::set<int>::iterator begin = set.begin();
  ft::set<int>::iterator end = set.end();
  for (; begin != end; begin++) {
    std::cout << *begin << " ";
  }
}

void set_test() {
  long int start_ms = get_start_time();
  ft::set<int> ft_set;
  long int res = get_time_diff(start_ms);
  std::cout << "\tEmpty constructor: size: " << ft_set.size()
            << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::pair<ft::set<int>::iterator, bool> ins_res = ft_set.insert(99);
  res = get_time_diff(start_ms);
  std::cout << "\tInsert func insert: size: " << ft_set.size()
            << " values: " << *(ins_res.first)
            << ((ins_res.second == 1) ? " true" : " false") << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ins_res = ft_set.insert(99);
  res = get_time_diff(start_ms);
  std::cout << "\tInsert func not insert: size: " << ft_set.size()
            << " values: " << *(ins_res.first)
            << ((ins_res.second == 1) ? " true" : " false") << ", time: " << res
            << std::endl;

  ft_set.insert(88);
  ft_set.insert(77);

  ft::set<int>::iterator begin = ft_set.begin();
  ft::set<int>::iterator end = ft_set.end();
  start_ms = get_start_time();
  ft::set<int> set_with_iter(begin, end);
  res = get_time_diff(start_ms);
  std::cout << "\tConstructor with iter: size: " << set_with_iter.size()
            << " values: ";
  print_set(set_with_iter);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::set<int> copy_set(ft_set);
  res = get_time_diff(start_ms);
  std::cout << "\tCopy constructor: size: " << copy_set.size() << " values: ";
  print_set(copy_set);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::set<int> assign_set;
  assign_set = ft_set;
  res = get_time_diff(start_ms);
  std::cout << "\tOperator=: size: " << assign_set.size() << " values: ";
  print_set(assign_set);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::set<int>::allocator_type alloc = assign_set.get_allocator();
  res = get_time_diff(start_ms);
  std::cout << "\tGet allocator func: max size value: " << alloc.max_size()
            << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::set<int>::iterator it_begin = ft_set.begin();
  res = get_time_diff(start_ms);
  std::cout << "\tBegin func: value: " << *it_begin << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft::set<int>::iterator it_end = ft_set.end();
  res = get_time_diff(start_ms);
  std::cout << "\tEnd func: value: " << *it_end << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft::set<int>::reverse_iterator rit_begin = ft_set.rbegin();
  res = get_time_diff(start_ms);
  std::cout << "\tRbegin func: value: " << *rit_begin << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft::set<int>::reverse_iterator rit_end = ft_set.rend();
  res = get_time_diff(start_ms);
  std::cout << "\tRend func: size: " << ft_set.size() << " values: ";
  for (; rit_begin != rit_end; rit_begin++) {
    std::cout << *rit_begin << " ";
  }
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  bool empty_res = ft_set.empty();
  res = get_time_diff(start_ms);
  std::cout << "\tEmpty func: value: " << ((empty_res == 1) ? "true" : "false")
            << ", time: " << res << std::endl;

  start_ms = get_start_time();
  size_t size_res = ft_set.size();
  res = get_time_diff(start_ms);
  std::cout << "\tSize func: value: " << size_res << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  size_t max_size_res = ft_set.max_size();
  res = get_time_diff(start_ms);
  std::cout << "\tSize func: value: " << max_size_res << ", time: " << res
            << std::endl;

  ft::set<int> tmp_set = ft_set;
  start_ms = get_start_time();
  tmp_set.clear();
  res = get_time_diff(start_ms);
  std::cout << "\tClear func: size: " << tmp_set.size() << " values: ";
  print_set(tmp_set);
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore insert: size: " << ft_set.size() << " values: ";
  it_begin = ft_set.begin();
  it_end = ft_set.end();
  for (; it_begin != it_end; it_begin++) {
    std::cout << *it_begin << " ";
  }
  std::cout << std::endl;
  start_ms = get_start_time();
  it_begin = ft_set.insert(it_begin, 44);
  res = get_time_diff(start_ms);
  it_end = ft_set.end();
  std::cout << "\tInsert func with pos: size: " << ft_set.size() << " values: ";
  for (; it_begin != it_end; it_begin++) {
    std::cout << *it_begin << " ";
  }
  std::cout << ", time: " << res << std::endl;
  
  std::cout << "\tBefore insert: size: " << ft_set.size() << " values: ";
  print_set(ft_set);
  std::cout << std::endl;
  it_begin = ft_set.begin();
  it_end = ft_set.end();
  for (; it_begin != it_end; it_begin++) {
  }
  start_ms = get_start_time();
  it_begin = ft_set.insert(it_begin, 101);
  res = get_time_diff(start_ms);
  std::cout << "\tInsert func with pos: size: " << ft_set.size() << " values: ";
  print_set(ft_set);
  std::cout << ", time: " << res << std::endl;

  tmp_set.clear();
  it_begin = ft_set.begin();
  it_end = ft_set.end();
  start_ms = get_start_time();
  tmp_set.insert(it_begin, it_end);
  res = get_time_diff(start_ms);
  std::cout << "\tInsert func with iters: size: " << tmp_set.size()
            << " values: ";
  print_set(tmp_set);
  std::cout << ", time: " << res << std::endl;

  it_begin = tmp_set.begin();
  for (; *it_begin != 88; it_begin++) {
  }
  start_ms = get_start_time();
  tmp_set.erase(it_begin);
  res = get_time_diff(start_ms);
  std::cout << "\tErase func with pos: size: " << tmp_set.size() << " values: ";
  print_set(tmp_set);
  std::cout << ", time: " << res << std::endl;

  it_begin = tmp_set.begin();
  for (; *it_begin != 44; it_begin++) {
  }
  it_end = it_begin;
  for (; *it_end != 99; it_end++) {
  }
  start_ms = get_start_time();
  tmp_set.erase(it_begin, it_end);
  res = get_time_diff(start_ms);
  std::cout << "\tErase func with iters: size: " << tmp_set.size()
            << " values: ";
  print_set(tmp_set);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  tmp_set.erase(101);
  res = get_time_diff(start_ms);
  std::cout << "\tErase func with val: size: " << tmp_set.size() << " values: ";
  print_set(tmp_set);
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore swap: first set: values: ";
  print_set(ft_set);
  std::cout << "second set: values: ";
  print_set(tmp_set);
  std::cout << std::endl;
  start_ms = get_start_time();
  ft_set.swap(tmp_set);
  res = get_time_diff(start_ms);
  std::cout << "\tAfter swap: first set: values: ";
  print_set(ft_set);
  std::cout << " second set: values: ";
  print_set(tmp_set);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  size_t res_count = tmp_set.count(88);
  res = get_time_diff(start_ms);
  std::cout << "\tCount func: value: " << res_count << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  begin = tmp_set.find(99);
  res = get_time_diff(start_ms);
  std::cout << "\tFind func: value: " << *begin << ", time: " << res
            << std::endl;

  tmp_set.insert(100);
  start_ms = get_start_time();
  ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> res_equ =
      tmp_set.equal_range(100);
  res = get_time_diff(start_ms);
  std::cout << "\tEqual range func: values: " << *res_equ.first << " "
            << *res_equ.second << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::set<int>::iterator res_low = tmp_set.lower_bound(100);
  res = get_time_diff(start_ms);
  std::cout << "\tLower bound func: value: " << *res_low << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft::set<int>::iterator res_upp = tmp_set.upper_bound(100);
  res = get_time_diff(start_ms);
  std::cout << "\tUpper bound func: value: " << *res_upp << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft::set<int>::key_compare key_comp = tmp_set.key_comp();
  res = get_time_diff(start_ms);
  std::cout << "\tKey compare func: value: "
            << (key_comp(1, 2) == 1 ? "true" : "false") << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft::set<int>::value_compare value_comp = tmp_set.value_comp();
  res = get_time_diff(start_ms);
  std::cout << "\tValue compare func: value: "
            << (value_comp(42, 21) == 1 ? "true" : "false") << ", time: " << res
            << std::endl;

  ft::set<int> empty_set1;
  ft::set<int> empty_set2;
  start_ms = get_start_time();
  std::cout << "\tTwo empty sets:" << std::endl
            << "\t\t==: " << ((empty_set1 == empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t!=: " << ((empty_set1 != empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t<: " << ((empty_set1 < empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t<=: " << ((empty_set1 <= empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t>: " << ((empty_set1 > empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t>=: " << ((empty_set1 >= empty_set2) ? "true" : "false")
            << std::endl;
  res = get_time_diff(start_ms);
  std::cout << "\t\ttime: " << res << std::endl;

  empty_set1.insert(21);
  empty_set1.insert(21);
  empty_set2.insert(42);
  start_ms = get_start_time();
  std::cout << "\tTwo not empty sets:" << std::endl
            << "\t\t==: " << ((empty_set1 == empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t!=: " << ((empty_set1 != empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t<: " << ((empty_set1 < empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t<=: " << ((empty_set1 <= empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t>: " << ((empty_set1 > empty_set2) ? "true" : "false")
            << std::endl
            << "\t\t>=: " << ((empty_set1 >= empty_set2) ? "true" : "false")
            << std::endl;
  res = get_time_diff(start_ms);
  std::cout << "\t\ttime: " << res << std::endl;

  std::cout << "\tBefore swap: first set: values: ";
  print_set(ft_set);
  std::cout << " second set: values: ";
  print_set(tmp_set);
  std::cout << std::endl;
  start_ms = get_start_time();
  swap(ft_set, tmp_set);
  res = get_time_diff(start_ms);
  std::cout << "\tAfter swap: first set: values: ";
  print_set(ft_set);
  std::cout << " second set: values: ";
  print_set(tmp_set);
  std::cout << ", time: " << res << std::endl;
}
