#include "../main.hpp"

void print_map(ft::map<int, int> map) {
  ft::map<int, int>::iterator begin = map.begin();
  ft::map<int, int>::iterator end = map.end();
  for (; begin != end; begin++) {
    std::cout << begin->first << "=" << begin->second << " ";
  }
}

void map_test() {
  long int start_ms = get_start_time();
  ft::map<int, int> ft_map;
  long int res = get_time_diff(start_ms);
  std::cout << "\tEmpty constructor: size: " << ft_map.size()
            << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::pair<ft::map<int, int>::iterator, bool> ins_res =
      ft_map.insert(ft::make_pair<int, int>(1, 99));
  res = get_time_diff(start_ms);
  std::cout << "\tInsert func insert: size: " << ft_map.size()
            << " values: " << ins_res.first->first << "="
            << ins_res.first->second
            << ((ins_res.second == 1) ? " true" : " false") << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ins_res = ft_map.insert(ft::make_pair<int, int>(1, 99));
  res = get_time_diff(start_ms);
  std::cout << "\tInsert func not insert: size: " << ft_map.size()
            << " values: " << ins_res.first->first << "="
            << ins_res.first->second
            << ((ins_res.second == 1) ? " true" : " false") << ", time: " << res
            << std::endl;

  ft_map.insert(ft::make_pair<int, int>(2, 88));
  ft_map.insert(ft::make_pair<int, int>(3, 77));

  ft::map<int, int>::iterator begin = ft_map.begin();
  ft::map<int, int>::iterator end = ft_map.end();
  start_ms = get_start_time();
  ft::map<int, int> map_with_iter(begin, end);
  res = get_time_diff(start_ms);
  std::cout << "\tConstructor with iter: size: " << map_with_iter.size()
            << " values: ";
  print_map(map_with_iter);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int> copy_map(ft_map);
  res = get_time_diff(start_ms);
  std::cout << "\tCopy constructor: size: " << copy_map.size() << " values: ";
  print_map(copy_map);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int> assign_map;
  assign_map = ft_map;
  res = get_time_diff(start_ms);
  std::cout << "\tOperator=: size: " << assign_map.size() << " values: ";
  print_map(assign_map);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int>::allocator_type alloc = ft_map.get_allocator();
  res = get_time_diff(start_ms);
  std::cout << "\tGet allocator func: max size value: " << alloc.max_size()
            << ", time: " << res << std::endl;

  try {
    start_ms = get_start_time();
    int res_at = ft_map.at(4);
    res = get_time_diff(start_ms);
    std::cout << "\tAt(4) func throw exp: value: " << res_at
              << ", time: " << res << std::endl;
  } catch (std::out_of_range &e) {
    std::cout << "\texception: " << e.what() << std::endl;
  }

  start_ms = get_start_time();
  int res_op = ft_map[4];
  res = get_time_diff(start_ms);
  std::cout << "\tOperator[] not found: size: " << ft_map.size()
            << " func res: " << res_op << " values: ";
  print_map(ft_map);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  res_op = ft_map[3];
  res = get_time_diff(start_ms);
  std::cout << "\tOperator[] found: size: " << ft_map.size()
            << " func res: " << res_op << " values: ";
  print_map(ft_map);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int>::iterator it_begin = ft_map.begin();
  res = get_time_diff(start_ms);
  std::cout << "\tBegin func: value: " << it_begin->first << "="
            << it_begin->second << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int>::iterator it_end = ft_map.end();
  res = get_time_diff(start_ms);
  std::cout << "\tEnd func: value: " << it_end->first << "=" << it_end->second
            << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int>::reverse_iterator rit_begin = ft_map.rbegin();
  res = get_time_diff(start_ms);
  std::cout << "\tRbegin func: value: " << rit_begin->first << "="
            << rit_begin->second << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int>::reverse_iterator rit_end = ft_map.rend();
  res = get_time_diff(start_ms);
  std::cout << "\tRend func: size: " << ft_map.size() << " values: ";
  for (; rit_begin != rit_end; rit_begin++) {
    std::cout << rit_begin->first << "=" << rit_begin->second << " ";
  }
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  bool empty_res = ft_map.empty();
  res = get_time_diff(start_ms);
  std::cout << "\tEmpty func: value: " << ((empty_res == 1) ? "true" : "false")
            << ", time: " << res << std::endl;

  start_ms = get_start_time();
  size_t size_res = ft_map.size();
  res = get_time_diff(start_ms);
  std::cout << "\tSize func: value: " << size_res << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  size_t max_size_res = ft_map.max_size();
  res = get_time_diff(start_ms);
  std::cout << "\tSize func: value: " << max_size_res << ", time: " << res
            << std::endl;

  ft::map<int, int> tmp_map = ft_map;
  start_ms = get_start_time();
  tmp_map.clear();
  res = get_time_diff(start_ms);
  std::cout << "\tClear func: size: " << tmp_map.size() << " values: ";
  print_map(tmp_map);
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore insert: size: " << ft_map.size() << " values: ";
  it_begin = ft_map.begin();
  it_end = ft_map.end();
  for (; it_begin != it_end; it_begin++) {
    std::cout << it_begin->first << "=" << it_begin->second << " ";
  }
  std::cout << std::endl;
  start_ms = get_start_time();
  it_begin = ft_map.insert(it_begin, ft::make_pair<int, int>(6, 44));
  res = get_time_diff(start_ms);
  it_end = ft_map.end();
  std::cout << "\tInsert func with pos: size: " << ft_map.size() << " values: ";
  for (; it_begin != it_end; it_begin++) {
    std::cout << it_begin->first << "=" << it_begin->second << " ";
  }
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore insert: size: " << ft_map.size() << " values: ";
  print_map(ft_map);
  std::cout << std::endl;
  it_begin = ft_map.begin();
  for (; it_begin->first != 3; it_begin++) {
  }
  start_ms = get_start_time();
  ft_map.insert(it_begin, ft::make_pair<int, int>(5, 55));
  res = get_time_diff(start_ms);
  it_end = ft_map.end();
  std::cout << "\tInsert func with pos: size: " << ft_map.size() << " values: ";
  for (; it_begin != it_end; it_begin++) {
    std::cout << it_begin->first << "=" << it_begin->second << " ";
  }
  std::cout << ", time: " << res << std::endl;

  tmp_map.clear();
  it_begin = ft_map.begin();
  it_end = ft_map.end();
  start_ms = get_start_time();
  tmp_map.insert(it_begin, it_end);
  res = get_time_diff(start_ms);
  std::cout << "\tInsert func with iters: size: " << tmp_map.size()
            << " values: ";
  print_map(tmp_map);
  std::cout << ", time: " << res << std::endl;

  it_begin = tmp_map.begin();
  for (; it_begin->first != 4; it_begin++) {
  }
  start_ms = get_start_time();
  tmp_map.erase(it_begin);
  res = get_time_diff(start_ms);
  std::cout << "\tErase func with pos: size: " << tmp_map.size() << " values: ";
  print_map(tmp_map);
  std::cout << ", time: " << res << std::endl;

  it_begin = tmp_map.begin();
  for (; it_begin->first != 2; it_begin++) {
  }
  it_end = it_begin;
  for (; it_end->first != 6; it_end++) {
  }
  start_ms = get_start_time();
  tmp_map.erase(it_begin, it_end);
  res = get_time_diff(start_ms);
  std::cout << "\tErase func with iters: size: " << tmp_map.size()
            << " values: ";
  print_map(tmp_map);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  tmp_map.erase(6);
  res = get_time_diff(start_ms);
  std::cout << "\tErase func with val: size: " << tmp_map.size() << " values: ";
  print_map(tmp_map);
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore swap: first map: values: ";
  print_map(ft_map);
  std::cout << " second map: values: ";
  print_map(tmp_map);
  std::cout << std::endl;
  start_ms = get_start_time();
  ft_map.swap(tmp_map);
  res = get_time_diff(start_ms);
  std::cout << "\tAfter swap: first map: values: ";
  print_map(ft_map);
  std::cout << "second map: values: ";
  print_map(tmp_map);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  size_t res_count = tmp_map.count(7);
  res = get_time_diff(start_ms);
  std::cout << "\tCount func: value: " << res_count << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  begin = tmp_map.find(6);
  res = get_time_diff(start_ms);
  std::cout << "\tFind func: value: " << begin->first << "=" << begin->second
            << ", time: " << res << std::endl;

  tmp_map.insert(ft::make_pair<int, int>(8, 22));
  start_ms = get_start_time();
  ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> res_equ =
      tmp_map.equal_range(6);
  res = get_time_diff(start_ms);
  std::cout << "\tEqual range func: values: " << res_equ.first->first << "="
            << res_equ.first->second << " " << res_equ.second->first << "="
            << res_equ.second->second << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int>::iterator res_low = tmp_map.lower_bound(6);
  res = get_time_diff(start_ms);
  std::cout << "\tLower bound func: value: " << res_low->first << "="
            << res_low->second << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int>::iterator res_upp = tmp_map.upper_bound(6);
  res = get_time_diff(start_ms);
  std::cout << "\tUpper bound func: value: " << res_upp->first << "="
            << res_upp->second << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::map<int, int>::key_compare key_comp = tmp_map.key_comp();
  res = get_time_diff(start_ms);
  std::cout << "\tKey compare func: value: "
            << (key_comp(1, 2) == 1 ? "true" : "false") << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft::map<int, int>::value_compare value_comp = tmp_map.value_comp();
  res = get_time_diff(start_ms);
  std::cout << "\tValue compare func: value: "
            << (value_comp(ft::make_pair<int, int>(0, 42),
                           ft::make_pair<int, int>(1, 21)) == 1
                    ? "true"
                    : "false")
            << ", time: " << res << std::endl;

  ft::map<int, int> empty_map1;
  ft::map<int, int> empty_map2;
  start_ms = get_start_time();
  std::cout << "\tTwo empty maps:" << std::endl
            << "\t\t==: " << ((empty_map1 == empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t!=: " << ((empty_map1 != empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t<: " << ((empty_map1 < empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t<=: " << ((empty_map1 <= empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t>: " << ((empty_map1 > empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t>=: " << ((empty_map1 >= empty_map2) ? "true" : "false")
            << std::endl;
  res = get_time_diff(start_ms);
  std::cout << "\t\ttime: " << res << std::endl;

  empty_map1.insert(ft::make_pair<int, int>(21, 0));
  empty_map1.insert(ft::make_pair<int, int>(21, 0));
  empty_map2.insert(ft::make_pair<int, int>(42, 0));
  start_ms = get_start_time();
  std::cout << "\tTwo not empty maps:" << std::endl
            << "\t\t==: " << ((empty_map1 == empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t!=: " << ((empty_map1 != empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t<: " << ((empty_map1 < empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t<=: " << ((empty_map1 <= empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t>: " << ((empty_map1 > empty_map2) ? "true" : "false")
            << std::endl
            << "\t\t>=: " << ((empty_map1 >= empty_map2) ? "true" : "false")
            << std::endl;
  res = get_time_diff(start_ms);
  std::cout << "\t\ttime: " << res << std::endl;

  std::cout << "\tBefore swap: first map: values: ";
  print_map(ft_map);
  std::cout << " second map: values: ";
  print_map(tmp_map);
  std::cout << std::endl;
  start_ms = get_start_time();
  swap(ft_map, tmp_map);
  res = get_time_diff(start_ms);
  std::cout << "\tAfter swap: first map: values: ";
  print_map(ft_map);
  std::cout << " second map: values: ";
  print_map(tmp_map);
  std::cout << ", time: " << res << std::endl;
}
