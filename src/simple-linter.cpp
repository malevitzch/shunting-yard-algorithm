#include "../include/simple-linter.hpp"
#include <set>
enum Token
{
  Operator,
  Number,
  Other, //keyword or variable name
  None
};
bool is_digit(char ch)
{
  return ch >= '0' && ch <= '9';
}
bool is_singleton(char ch)
{
  std::set<char> singletons = {'(', ')', '[', ']'};
  return singletons.find(ch) != singletons.end();
}
bool is_operator_char(char ch)
{
  std::set<char> operator_chars = {'+', '-', '=', '*', '/'};
  return operator_chars.find(ch) != operator_chars.end();
}
std::vector<string> tokenize_expression(std::string expression)
{
  std::set<char> leading_operator_chars = {'-', '!'}; //characters that can only ever start an operator and will never appear as a continuation
  auto is_leading_opchar = [&leading_operator_chars](char ch)
  {
    return leading_operator_chars.find(ch) != leading_operator_chars.end();
  };
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
      if(cur_token_type == Token::Number || cur_token_type == Other)
      {
        cur_token += ch;
      }
      if(cur_token_type == Token::Operator)
      {
        finish_token();
      }
      if(cur_token_type == Token::None)
      {
        cur_token_type = Token::Number;
        cur_token += ch;
      }
    }
    else if(is_singleton(ch))
    {
      finish_token();
      cur_token += ch;
      finish_token();
    }
    else if(is_operator_char(ch))
    {
      if(cur_token_type != Token::Operator || is_leading_opchar(ch))
      {
        finish_token();
        cur_token += ch;
      }
      else
      {
        cur_token += ch;
      }
      cur_token_type = Token::Operator;
    }
    else
    {
      if(cur_token_type != Token::Other)
      {
        finish_token();
      }
      cur_token += ch;
      cur_token_type = Token::Other;
    }
  }
  finish_token();
  return tokenized_expression;
}
