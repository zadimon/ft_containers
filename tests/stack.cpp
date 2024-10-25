#include "../main.hpp"

unsigned long get_start_time() {
  struct timeval start = {};
  gettimeofday(&start, nullptr);
  return start.tv_sec * 1000000 + start.tv_usec;
}

unsigned long get_time_diff(long int start_ms) {
  struct timeval end = {};
  gettimeofday(&end, nullptr);
  long int end_ms = end.tv_sec * 1000000 + end.tv_usec;
  return end_ms - start_ms;
}

void stack_test() {
  long int start_ms = get_start_time();
  ft::stack<int> ft_stack;
  long int res = get_time_diff(start_ms);
  std::cout << "\tDefault constructor: time: " << res << std::endl;

  start_ms = get_start_time();
  bool empty_res = ft_stack.empty();
  res = get_time_diff(start_ms);
  std::cout << "\tEmpty func: res: " << ((empty_res == 1) ? "true" : "false")
            << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft_stack.push(1);
  ft_stack.push(2);
  ft_stack.push(3);
  res = get_time_diff(start_ms);
  std::cout << "\tPush func: time: " << res << std::endl;

  start_ms = get_start_time();
  size_t size_res = ft_stack.size();
  res = get_time_diff(start_ms);
  std::cout << "\tSize func: res: " << size_res << ", time: " << res
            << std::endl;

  ft::stack<int> copy_stack;
  copy_stack.push(99);
  copy_stack.push(99);
  start_ms = get_start_time();
  copy_stack = ft_stack;
  res = get_time_diff(start_ms);
  std::cout << "\tOperator=: res: ";
  for (size_t i = 0; i < 3; i++) {
    std::cout << copy_stack.top();
    copy_stack.pop();
    if (i != 2) {
      std::cout << " ";
    }
  }
  std::cout << ", time: " << res << std::endl;

  start_ms = get_start_time();
  int top_res = ft_stack.top();
  res = get_time_diff(start_ms);
  std::cout << "\tTop func: res: " << top_res << ", time: " << res << std::endl;

  start_ms = get_start_time();
  ft_stack.pop();
  res = get_time_diff(start_ms);
  std::cout << "\tPop func: res: " << ft_stack.top() << ", time: " << res
            << std::endl;

  ft::stack<int> empty_stack1;
  ft::stack<int> empty_stack2;
  start_ms = get_start_time();
  std::cout << "\tTwo empty stacks:" << std::endl
            << "\t\t==: " << ((empty_stack1 == empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t!=: " << ((empty_stack1 != empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t<: " << ((empty_stack1 < empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t<=: " << ((empty_stack1 <= empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t>: " << ((empty_stack1 > empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t>=: " << ((empty_stack1 >= empty_stack2) ? "true" : "false")
            << std::endl;
  res = get_time_diff(start_ms);
  std::cout << "\t\ttime: " << res << std::endl;

  empty_stack1.push(21);
  empty_stack1.push(21);
  empty_stack2.push(42);
  start_ms = get_start_time();
  std::cout << "\tTwo not empty stacks:" << std::endl
            << "\t\t==: " << ((empty_stack1 == empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t!=: " << ((empty_stack1 != empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t<: " << ((empty_stack1 < empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t<=: " << ((empty_stack1 <= empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t>: " << ((empty_stack1 > empty_stack2) ? "true" : "false")
            << std::endl
            << "\t\t>=: " << ((empty_stack1 >= empty_stack2) ? "true" : "false")
            << std::endl;
  res = get_time_diff(start_ms);
  std::cout << "\t\ttime: " << res << std::endl;
}
