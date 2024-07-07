#include "../include/operators.hpp"
#include <ranges>
Operator::Operator(string name, string symbol, size_t precedence, Associativity associativity) : name(name), symbol(symbol), precedence(precedence), associativity(associativity) {}

string Operator::get_name() const
{
  return name;
}
string Operator::get_symbol() const
{
  return symbol;
}
size_t Operator::get_precedence() const
{
  return precedence;
}
Associativity Operator::get_associativity() const
{
  return associativity;
}
BinaryOperator::BinaryOperator(string name, string symbol, size_t precedence, Associativity associativity, std::function<int(int, int)> fn) : Operator(name, symbol, precedence, associativity), fn(fn) {}
int BinaryOperator::perform(int a, int b) const
{
  return fn(a, b);
}

UnaryOperator::UnaryOperator(string name, string symbol, size_t precedence, Associativity associativity, std::function<int(int)> fn) : Operator(name, symbol, precedence, associativity), fn(fn) {}
int UnaryOperator::perform(int a) const
{
  return fn(a);
}

std::map<string, BinaryOperator> get_binary_operator_map(std::vector<BinaryOperator> binary_operators)
{
  std::map<string, BinaryOperator> operator_map;
  for(BinaryOperator op : binary_operators)
  {
     operator_map[op.get_symbol()] = op;
  }
  return operator_map;
}
std::map<string, UnaryOperator> get_unary_operator_map(std::vector<UnaryOperator> unary_operators)
{
  std::map<string, UnaryOperator> operator_map;
  for(UnaryOperator op : unary_operators)
  {
     operator_map[op.get_symbol()] = op;
  }
  return operator_map;
}

