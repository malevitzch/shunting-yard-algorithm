#include "../include/operators.hpp"
#include "../include/simple-linter.hpp"
#include <iostream>

int add(int a, int b)
{
  return a+b;
}
int neg(int a)
{
  return a*-1;
}
int main()
{
  BinaryOperator addition("+", "Addition", 2, Associativity::Left, add);
  //int x(7), y(8);
  //std::cout<<addition.perform(x, y) << "\n";
  std::vector<string> tokenized_expr = tokenize_expression("x8+7--31 * (8 / -217)");
  for(string s : tokenized_expr)
  {
      std::cout<< "["<< s<<"]";
  }
}
