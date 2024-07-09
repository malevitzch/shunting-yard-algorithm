#include "../include/shunting-yard.hpp"
#include "../include/operators.hpp"
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
std::vector<string> infix_to_postfix(std::vector<string> expression, std::map<string, BinaryOperator>& binary_operators, std::map<string, UnaryOperator>& unary_operators)
{
  //TODO
}
