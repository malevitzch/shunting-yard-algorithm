#include <string>
#include <vector>
#include <map>
class BinaryOperator;
class UnaryOperator;
using std::string;
constexpr std::string_view prefix = "u"; //The prefix used by 

std::vector<string> infix_to_postfix(std::vector<string> expression, std::map<string, BinaryOperator> binary_operators, std::map<string, UnaryOperator> unary_operators); 
