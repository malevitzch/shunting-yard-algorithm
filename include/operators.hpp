#include <functional>
#include <vector>
#include <string>
#include <map>

using std::string;

enum class Associativity
{
  Right,
  Left
};

class Operator
{
private:
  string name;
  string symbol;
protected:
  Operator(string symbol, string name);
public:
  Operator() = default;
  string get_name() const;
  string get_symbol() const;
};
class BinaryOperator : public Operator
{
private:
  std::function<int(int, int)> fn;
  size_t precedence; //the lower precedence the earlier the operator is processed
  Associativity associativity;
public:
  BinaryOperator() = default;
  BinaryOperator(string symbol, string name, size_t precedence, Associativity associativity, std::function<int(int, int)> fn);
  size_t get_precedence() const;
  Associativity get_associativity() const;
  int perform(int a, int b) const;
};

class UnaryOperator : public Operator
{
private:
  std::function<int(int)> fn;
public:
  UnaryOperator() = default;
  UnaryOperator(string symbol, string name, std::function<int(int)> fn);
  int perform(int a) const;
};

std::map<string, BinaryOperator> get_binary_operator_map(std::vector<BinaryOperator> binary_operators);
std::map<string, UnaryOperator> get_unary_operator_map(std::vector<UnaryOperator> unary_operators);

