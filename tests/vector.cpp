#include "../main.hpp"

void print_vector(ft::vector<int> ft_vector) {
  ft::vector<int>::iterator it_begin = ft_vector.begin();
  ft::vector<int>::iterator it_end = ft_vector.end();
  size_t last = ft_vector.size() - 1;

  for (size_t i = 0; it_begin != it_end; it_begin++, i++) {
    std::cout << *it_begin;
    if (i != last) std::cout << " ";
  }
}

void vector_test() {
  long int start_ms = get_start_time();
  ft::vector<int> ft_vector;
  long int res = get_time_diff(start_ms);
  std::cout << "\tEmpty constructor: size: " << ft_vector.size()
            << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::vector<int> ft_vector_with_params(10);
  res = get_time_diff(start_ms);
  std::cout << "\tConstructor with params: size: "
            << ft_vector_with_params.size()
            << ", value: " << ft_vector_with_params.front() << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft_vector.push_back(42);
  ft_vector.push_back(21);
  res = get_time_diff(start_ms);
  std::cout << "\tPush_back func: size: " << ft_vector.size() << ", values: ";
  print_vector(ft_vector);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::vector<int>::iterator it_begin = ft_vector.begin();
  res = get_time_diff(start_ms);
  std::cout << "\tBegin func: value: " << *it_begin << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft::vector<int>::iterator it_end = ft_vector.end();
  res = get_time_diff(start_ms);
  std::cout << "\tEnd func: time: " << res << std::endl;

  start_ms = get_start_time();
  ft::vector<int> ft_vector_with_iterator(it_begin, it_end);
  res = get_time_diff(start_ms);
  std::cout << "\tConstructor with iterator: size: "
            << ft_vector_with_iterator.size() << ", values: ";
  print_vector(ft_vector_with_iterator);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::vector<int> ft_copy_vector(ft_vector);
  res = get_time_diff(start_ms);
  std::cout << "\tCopy constructor: size: " << ft_copy_vector.size()
            << ", values: ";
  print_vector(ft_copy_vector);
  std::cout << ", time: " << res << std::endl;

  ft::vector<int> ft_assign_vector;
  ft_assign_vector.push_back(1);
  ft_assign_vector.push_back(2);
  ft_assign_vector.push_back(3);
  start_ms = get_start_time();
  ft_assign_vector = ft_vector;
  res = get_time_diff(start_ms);
  std::cout << "\tOperator=: size: " << ft_assign_vector.capacity()
            << ", values: ";
  print_vector(ft_assign_vector);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft::vector<int>::reverse_iterator rit_begin = ft_vector.rbegin();
  res = get_time_diff(start_ms);
  std::cout << "\tRbegin func: value: " << *rit_begin << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft::vector<int>::reverse_iterator rit_end = ft_vector.rend();
  res = get_time_diff(start_ms);
  (void)rit_end;
  std::cout << "\tRend func: values: ";
  for (size_t i = 0; rit_begin != rit_end; rit_begin++, i++) {
    std::cout << *rit_begin;
    if (i != ft_vector.size()) std::cout << " ";
  }
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  size_t max_size_res = ft_vector.max_size();
  res = get_time_diff(start_ms);
  std::cout << "\tMax size func: value: " << max_size_res << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft_copy_vector.resize(1);
  res = get_time_diff(start_ms);
  std::cout << "\tResize(1) func when < size vector: size: "
            << ft_copy_vector.size() << ", values: ";
  print_vector(ft_copy_vector);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  size_t cap_res = ft_copy_vector.capacity();
  res = get_time_diff(start_ms);
  std::cout << "\tCapacity func: value: " << cap_res << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  ft_copy_vector.resize(3);
  res = get_time_diff(start_ms);
  std::cout << "\tResize(3) func when > capacity vector: capacity: "
            << ft_copy_vector.capacity() << ", values: ";
  print_vector(ft_copy_vector);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  bool empty_res = ft_copy_vector.empty();
  res = get_time_diff(start_ms);
  std::cout << "\tEmpty func: value: " << ((empty_res == 1) ? "true" : "false")
            << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft_copy_vector.reserve(6);
  res = get_time_diff(start_ms);
  std::cout << "\tReserve(6) func: capacity: " << ft_copy_vector.capacity()
            << ", values: ";
  print_vector(ft_copy_vector);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  int res_op = ft_copy_vector[0];
  res = get_time_diff(start_ms);
  std::cout << "\tOperator[](0) func: value: " << res_op << ", time: " << res
            << std::endl;

  try {
    start_ms = get_start_time();
    int res_at = ft_copy_vector.at(6);
    res = get_time_diff(start_ms);
    std::cout << "\tAt(6) func throw exp: value: " << res_at
              << ", time: " << res << std::endl;
  } catch (std::out_of_range &e) {
    std::cout << "\texception: " << e.what() << std::endl;
  }

  start_ms = get_start_time();
  int res_front = ft_copy_vector.front();
  res = get_time_diff(start_ms);
  std::cout << "\tFront func: value: " << res_front << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  int res_back = ft_copy_vector.back();
  res = get_time_diff(start_ms);
  std::cout << "\tBack func: value: " << res_back << ", time: " << res
            << std::endl;

  start_ms = get_start_time();
  int *res_data = ft_copy_vector.data();
  res = get_time_diff(start_ms);
  std::cout << "\tData func: value: ";
  for (size_t i = 0; i < ft_copy_vector.size(); i++) {
    std::cout << res_data[i];
    if (i != ft_copy_vector.size() - 1) std::cout << " ";
  }
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore assign: capacity: " << ft_vector.capacity()
            << ", value: ";
  print_vector(ft_vector);
  std::cout << std::endl;
  start_ms = get_start_time();
  ft_vector.assign(5, 999);
  res = get_time_diff(start_ms);
  std::cout << "\tAssign with val func: capacity: " << ft_vector.capacity()
            << ", value: ";
  print_vector(ft_vector);
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore assign: capacity: " << ft_copy_vector.capacity()
            << ", value: ";
  print_vector(ft_copy_vector);
  std::cout << std::endl;
  start_ms = get_start_time();
  ft_copy_vector.assign(ft_vector.begin(), ++(ft_vector.begin()));
  res = get_time_diff(start_ms);
  std::cout << "\tAssign with iter func: capacity: "
            << ft_copy_vector.capacity() << ", value: ";
  print_vector(ft_copy_vector);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft_vector.push_back(5);
  res = get_time_diff(start_ms);
  std::cout << "\tPush back func: capacity: " << ft_vector.capacity()
            << ", value: ";
  print_vector(ft_vector);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft_vector.pop_back();
  res = get_time_diff(start_ms);
  std::cout << "\tPop back func: capacity: " << ft_vector.capacity()
            << ", value: ";
  print_vector(ft_vector);
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft_vector.clear();
  res = get_time_diff(start_ms);
  std::cout << "\tClear func: capacity: " << ft_vector.capacity() << " ";
  print_vector(ft_vector);
  std::cout << ", time: " << res << std::endl;

  ft_vector.push_back(1);
  ft_vector.push_back(2);
  ft_vector.push_back(3);
  ft_vector.push_back(4);
  ft_vector.push_back(5);
  std::cout << "\tBefore insert: capacity: " << ft_vector.capacity()
            << ", value: ";
  it_begin = ft_vector.begin();
  for (size_t i = 0; *it_begin != 3; it_begin++, i++) {
    std::cout << *it_begin;
    if (i != 2) std::cout << " ";
  }
  std::cout << std::endl;
  start_ms = get_start_time();
  it_begin = ft_vector.insert(it_begin, 42);
  res = get_time_diff(start_ms);
  it_end = ft_vector.end();
  std::cout << "\tInsert value func: capacity: " << ft_vector.capacity()
            << ", value: ";
  for (size_t i = 0; it_begin != it_end; it_begin++, i++) {
    std::cout << *it_begin;
    if (i != 3) std::cout << " ";
  }
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore insert: capacity: " << ft_vector.capacity()
            << ", value: ";
  it_begin = ft_vector.begin();
  for (size_t i = 0; *it_begin != 42; it_begin++, i++) {
    std::cout << *it_begin;
    if (i != 2) std::cout << " ";
  }
  std::cout << std::endl;
  start_ms = get_start_time();
  it_begin = ft_vector.insert(it_begin, 5, 21);
  res = get_time_diff(start_ms);
  it_end = ft_vector.end();
  std::cout << "\tInsert value n count func: capacity: " << ft_vector.capacity()
            << ", value: ";
  for (size_t i = 0; it_begin != it_end; it_begin++, i++) {
    std::cout << *it_begin;
    if (i != 8) std::cout << " ";
  }
  std::cout << ", time: " << res << std::endl;

  ft_vector_with_params.clear();
  ft_vector_with_params.push_back(999);
  ft_vector_with_params.push_back(999);
  ft_vector_with_params.push_back(999);
  std::cout << "\tBefore insert: capacity: " << ft_vector.capacity()
            << ", value: ";
  it_begin = ft_vector.begin();
  for (size_t i = 0; *it_begin != 42; it_begin++, i++) {
    std::cout << *it_begin;
    if (i != 6) std::cout << " ";
  }
  std::cout << std::endl;
  start_ms = get_start_time();
  it_begin = ft_vector.insert(it_begin, ft_vector_with_params.begin(),
                              ft_vector_with_params.end());
  res = get_time_diff(start_ms);
  it_end = ft_vector.end();
  std::cout << "\tInsert with iter func: capacity: " << ft_vector.capacity()
            << ", value: ";
  for (size_t i = 0; it_begin != it_end; it_begin++, i++) {
    std::cout << *it_begin;
    if (i != 6) std::cout << " ";
  }
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore erase: capacity: " << ft_vector.capacity()
            << ", value: ";
  it_begin = ft_vector.begin();
  for (size_t i = 0; *it_begin != 42; it_begin++, i++) {
    std::cout << *it_begin;
    if (i != 9) std::cout << " ";
  }
  std::cout << std::endl;
  start_ms = get_start_time();
  it_begin = ft_vector.erase(it_begin);
  res = get_time_diff(start_ms);
  it_end = ft_vector.end();
  std::cout << "\tErase func: capacity: " << ft_vector.capacity()
            << ", value: ";
  for (size_t i = 0; it_begin != it_end; it_begin++, i++) {
    std::cout << *it_begin;
    if (i != 2) std::cout << " ";
  }
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore erase: capacity: " << ft_vector.capacity()
            << ", value: ";
  it_begin = ft_vector.begin();
  for (; *it_begin != 999; it_begin++) {
    std::cout << *it_begin << " ";
  }
  it_end = it_begin;
  for (; *it_end == 999; it_end++) {
  }
  std::cout << std::endl;
  start_ms = get_start_time();
  it_begin = ft_vector.erase(it_begin, it_end);
  res = get_time_diff(start_ms);
  it_end = ft_vector.end();
  std::cout << "\tErase with iter func: capacity: " << ft_vector.capacity()
            << ", value: ";
  for (; it_begin != it_end; it_begin++) {
    std::cout << *it_begin << " ";
  }
  std::cout << ", time: " << res << std::endl;

  std::cout << "\tBefore swap: first vector values: ";
  print_vector(ft_vector);
  std::cout << std::endl << "\tBefore swap: second vector values: ";
  print_vector(ft_vector_with_params);
  std::cout << std::endl;
  start_ms = get_start_time();
  ft_vector.swap(ft_vector_with_params);
  res = get_time_diff(start_ms);
  std::cout << "\tAfter swap: first vector values: ";
  print_vector(ft_vector);
  std::cout << std::endl << "\tAfter swap: second vector values: ";
  print_vector(ft_vector_with_params);
  std::cout << std::endl;
  std::cout << "\ttime: " << res << std::endl;

  start_ms = get_start_time();
  ft::vector<int>::allocator_type alloc = ft_vector.get_allocator();
  res = get_time_diff(start_ms);
  std::cout << "\tGet allocator func: max size: " << alloc.max_size()
            << ", time: " << res << std::endl;

  ft::vector<int> empty_vector1;
  ft::vector<int> empty_vector2;
  start_ms = get_start_time();
  std::cout
      << "\tTwo empty vectors:" << std::endl
      << "\t\t==: " << ((empty_vector1 == empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t!=: " << ((empty_vector1 != empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t<: " << ((empty_vector1 < empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t<=: " << ((empty_vector1 <= empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t>: " << ((empty_vector1 > empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t>=: " << ((empty_vector1 >= empty_vector2) ? "true" : "false")
      << std::endl;
  res = get_time_diff(start_ms);
  std::cout << "\t\ttime: " << res << std::endl;

  empty_vector1.push_back(21);
  empty_vector1.push_back(21);
  empty_vector2.push_back(42);
  start_ms = get_start_time();
  std::cout
      << "\tTwo not empty vectors:" << std::endl
      << "\t\t==: " << ((empty_vector1 == empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t!=: " << ((empty_vector1 != empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t<: " << ((empty_vector1 < empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t<=: " << ((empty_vector1 <= empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t>: " << ((empty_vector1 > empty_vector2) ? "true" : "false")
      << std::endl
      << "\t\t>=: " << ((empty_vector1 >= empty_vector2) ? "true" : "false")
      << std::endl;
  res = get_time_diff(start_ms);
  std::cout << "\t\ttime: " << res << std::endl;

  std::cout << "\tBefore swap: first vector values: ";
  print_vector(ft_vector);
  std::cout << std::endl << "\tBefore swap: second vector values: ";
  print_vector(ft_vector_with_params);
  std::cout << std::endl;
  start_ms = get_start_time();
  swap(ft_vector, ft_vector_with_params);
  res = get_time_diff(start_ms);
  std::cout << "\tAfter swap: first vector values: ";
  print_vector(ft_vector);
  std::cout << std::endl << "\tAfter swap: second vector values: ";
  print_vector(ft_vector_with_params);
  std::cout << std::endl;
  std::cout << "\ttime: " << res << std::endl;
}
