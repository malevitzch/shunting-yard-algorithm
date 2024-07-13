#include "../include/operators.hpp"
#include "../include/simple-linter.hpp"
#include <iostream>

std::vector<BinaryOperator> get_binary_operators()
{
  std::vector<BinaryOperator> operator_vec;
  operator_vec.push_back(BinaryOperator("+", "Addition", 2, Associativity::Left, [](int a, int b){return a+b;}));
  operator_vec.push_back(BinaryOperator("-", "Subtraction", 2, Associativity::Left, [](int a, int b){return a-b;}));
  operator_vec.push_back(BinaryOperator("*", "Multiplication", 1, Associativity::Left, [](int a, int b){return a*b;}));
  operator_vec.push_back(BinaryOperator("/", "Division", 2, Associativity::Left, [](int a, int b){return a/b;}));
  return operator_vec;
}
std::vector<UnaryOperator> get_unary_operators()
{
  std::vector<UnaryOperator> operator_vec;
  operator_vec.push_back(UnaryOperator("-", "Signchange", [](int a){return a*-1;}));
  return operator_vec;
}
int main()
{
  std::vector<UnaryOperator> unary_ops = get_unary_operators();
  std::vector<BinaryOperator> binary_ops = get_binary_operators();
  std::vector<string> tokenized_expr = tokenize_expression("x8+7--31 * (8 / -217)");
  for(string s : tokenized_expr)
  {
      std::cout<< "["<< s<<"]";
  }
}
