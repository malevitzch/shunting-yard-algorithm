#include "../include/operators.hpp"
#include "../include/simple-linter.hpp"
#include "../include/shunting-yard.hpp"
#include <iostream>
std::vector<BinaryOperator> get_binary_operators()
{
  std::vector<BinaryOperator> operator_vec;
  operator_vec.push_back(BinaryOperator("+", "Addition", 2, Associativity::Left, [](int a, int b){return a+b;}));
  operator_vec.push_back(BinaryOperator("-", "Subtraction", 2, Associativity::Left, [](int a, int b){return a-b;}));
  operator_vec.push_back(BinaryOperator("*", "Multiplication", 1, Associativity::Left, [](int a, int b){return a*b;}));
  operator_vec.push_back(BinaryOperator("/", "Division", 1, Associativity::Left, [](int a, int b){return a/b;}));
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
  std::string expr;
  std::cout<<"INPUT EXPRESSION: ";
  std::getline(std::cin, expr);
  std::vector<UnaryOperator> unary_ops = get_unary_operators();
  std::vector<BinaryOperator> binary_ops = get_binary_operators();
  std::map<string, BinaryOperator> binary_op_map = get_binary_operator_map(binary_ops);
  std::map<string, UnaryOperator> unary_op_map = get_unary_operator_map(unary_ops);
  std::vector<string> tokenized_expr = tokenize_expression(expr);
  std::cout<<expression_eval(tokenized_expr, binary_ops, unary_ops) << "\n";
  /*std::vector<string> postfix = infix_to_postfix(tokenized_expr, binary_op_map, unary_op_map);
  for(string s : postfix)
  {
      std::cout<< s<<" ";
  }*/
  
}
