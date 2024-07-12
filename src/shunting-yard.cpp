#include "../include/shunting-yard.hpp"
#include "../include/operators.hpp"
#include <stack>
std::vector<string> mark_unary(std::vector<string> expression, std::map<string, BinaryOperator>& binary_operators, std::map<string, UnaryOperator>& unary_operators)
{
  string prefix = PREFIX;
  bool was_last_value = false;
  for(string& cur_token : expression)
  {
    if(cur_token == "(" || cur_token == ")") continue;
    if(unary_operators.find(cur_token) != unary_operators.end())
    {
      if(!was_last_value)
      {
        cur_token = prefix + cur_token;
      }
      was_last_value = false;
    }
    else if(binary_operators.find(cur_token) != binary_operators.end())
    {
      was_last_value = false;
    }
    else
    {
      was_last_value = true;
    }
  }
  return expression; //TODO: consider making this run on references and just modify expression in-place
}

std::map<string, UnaryOperator> get_prefixed_unary_operator_map(std::map<string, UnaryOperator>& unary_operators)
{
  string prefix = PREFIX;
  std::map<string, UnaryOperator> prefixed_unary_operators;
  for(auto&[symbol, op] : unary_operators)
  {
    prefixed_unary_operators[prefix + symbol] = op;
  }
  return prefixed_unary_operators;
}
#include <iostream>
std::vector<string> infix_to_postfix(std::vector<string> expression, std::map<string, BinaryOperator>& binary_operators, std::map<string, UnaryOperator>& unary_operators)
{
  string prefix = PREFIX;
  std::map<string, UnaryOperator> prefixed_unary_operators = get_prefixed_unary_operator_map(unary_operators);
  expression = mark_unary(expression, binary_operators, unary_operators);
  for(string s : expression)
  {
      std::cout<<s << "\n";
  }
  auto is_unary_op = [&prefixed_unary_operators](string op) -> bool
  {
    return prefixed_unary_operators.find(op) != prefixed_unary_operators.end();
  };
  auto is_binary_op = [&binary_operators](string op) -> bool 
  {
    return binary_operators.find(op) != binary_operators.end();
  };
  std::vector<string> postfix_notation;
  std::stack<string> operator_stack;
  for(string token : expression)
  {
    if(token == "(")
    {
      operator_stack.push("(");
    }
    else if(token == ")")
    {
      while(1)
      {
        if(operator_stack.empty())
        {
          //TODO: error here, mismatched parentheses
        }
        if(operator_stack.top() == "(")
        {
          operator_stack.pop();
          break;
        }
        else
        {
          postfix_notation.push_back(operator_stack.top());
          operator_stack.pop();
        }
      }
    }
    else if(is_unary_op(token))
    {
      
    }
    else if(is_binary_op(token))
    {

    }
    else
    {
      postfix_notation.push_back(token);
    }
  }

  while(!operator_stack.empty())
  {
    if(operator_stack.top() == "(")
    {
      //TODO: error here
      continue;
    }
    postfix_notation.push_back(operator_stack.top());
    operator_stack.pop();
  }
  return postfix_notation;
}

int expression_eval(std::vector<string> expression, std::vector<BinaryOperator> binary_operators, std::vector<UnaryOperator> unary_operators)
{
  std::map<string, BinaryOperator> binary_op_map = get_binary_operator_map(binary_operators);
  std::map<string, UnaryOperator> unary_op_map = get_unary_operator_map(unary_operators);
  std::vector<string> postfix_notation_expression = infix_to_postfix(expression, binary_op_map, unary_op_map);
  //TODO: finish
}
