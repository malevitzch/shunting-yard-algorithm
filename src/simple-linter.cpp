#include "../include/simple-linter.hpp"

enum Token
{
  Operator,
  Number,
  Other,
  None
};
bool is_digit(char ch)
{
  return ch >= '0' && ch <= '9';
}
std::vector<string> tokenize_expression(std::string expression)
{
  std::vector<string> tokenized_expression;
  string cur_token = "";
  Token cur_token_type = Token::None;
  auto finish_token = [&cur_token, &cur_token_type, &tokenized_expression]()
  {
    if(cur_token.size() > 0)
    {
        tokenized_expression.push_back(cur_token);
        cur_token = "";
        cur_token_type = Token::None;
    }
  };
  for(char ch : expression)
  {
    if(isspace(ch))
    {
      finish_token(); 
    }
    else if(is_digit(ch))
    {
      if(cur_token_type == Token::Operator)
      {
        finish_token();
      }
      if(cur_token_type == Token::None)
      {
        cur_token_type = Token::Operator;
      }
    }
  }
  return tokenized_expression;
}
