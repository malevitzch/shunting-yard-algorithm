#include "../include/operators.hpp"


//put your precedence here for now
//std::vector<string> precedence = {"*", "/", "+", "-"};


Operator::Operator(string name, string symbol, Associativity associativity) : name(name), symbol(symbol), associtivity(associativity) {}

string Operator::get_name() const
{
  return name;
}
string Operator::get_symbol() const
{
  return symbol;
}


BinaryOperator::BinaryOperator(string name, string symbol, Associativity associativity, std::function<int(int, int)> fn) : Operator(name, symbol, associativity), fn(fn) {}
int BinaryOperator::perform(int a, int b) const
{
  return fn(a, b);
}

UnaryOperator::UnaryOperator(string name, string symbol,  Associativity associativity, std::function<int(int)> fn) : Operator(name, symbol, associativity), fn(fn) {}
int UnaryOperator::perform(int a) const
{
  return fn(a);
}
