#ifndef MAIN_HPP
#define MAIN_HPP

#include <sys/time.h>
#include <unistd.h>

#include <iostream>

#if 1  // CREATE A REAL STL EXAMPLE
#include <map>
#include <set>
#include <stack>
#include <vector>
namespace ft = std;
#else
#include "map.hpp"
#include "set.hpp"
#include "stack.hpp"
#include "vector.hpp"
#endif

unsigned long get_start_time();
unsigned long get_time_diff(long int start_ms);

void stack_test();
void vector_test();
void map_test();
void set_test();

#endif  // MAIN_HPP
