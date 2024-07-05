#include <functional>
#include <vector>
#include <string>
using std::string;

class BinaryOperator
{
private:
  string name;
  std::function<int(int, int)> fn;
public:
  BinaryOperator() = delete;
  BinaryOperator(string name, std::function<int(int, int)> fn);
  int peform(int a, int b) const;
  string get_name() const;
};

class UnaryOperator
{
private:
  string name;
  std::function<int(int)> fn;
public:
  UnaryOperator() = delete;
  UnaryOperator(string name, std::function<int(int)> fn);
  int perform(int a) const;
  string get_name() const;
};
