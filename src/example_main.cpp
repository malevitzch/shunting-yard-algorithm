#include "../include/operators.hpp"
#include <iostream>

int add(int a, int b)
{
  return a+b;
}

int main()
{
  BinaryOperator addition("+", "Addition", 2, Associativity::Left, add);
  int x(7), y(8);
  std::cout<<addition.perform(x, y) << "\n";
}
