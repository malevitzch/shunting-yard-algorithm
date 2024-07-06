#include <functional>
#include <vector>
#include <string>
using std::string;

enum class Associativity
{
  Right,
  Left
};

class Operator
{
private:
  Associativity associativity;
  string name;
  string symbol;
protected:
  Operator(string name, string symbol, Associativity associativity);
public:
  Operator() = delete;
  string get_name() const;
  string get_symbol() const;
};
class BinaryOperator : public Operator
{
private:
  std::function<int(int, int)> fn;
public:
  BinaryOperator() = delete;
  BinaryOperator(string name, string symbol, Associativity associativity, std::function<int(int, int)> fn);
  int perform(int a, int b) const;
};

class UnaryOperator : public Operator
{
private:
  std::function<int(int)> fn;
public:
  UnaryOperator() = delete;
  UnaryOperator(string name, string symbol, Associativity associativity, std::function<int(int)> fn);
  int perform(int a) const;
};
