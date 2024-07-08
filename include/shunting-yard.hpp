#include <string>
#include <vector>
#include <map>

#ifndef prefix
#define prefix "u";
#endif
//"u" is the default prefix added to unary operators
//if, for some reason, the symbol "u" + operator name might be a valid symbol in your code, you need to change the prefix to something else

class BinaryOperator;
class UnaryOperator;
using std::string;

std::vector<string> mark_unary(std::vector<string> expression, std::map<string, BinaryOperator>& binary_operators, std::map<string, UnaryOperator>& unary_operators);
std::vector<string> infix_to_postfix(std::vector<string> expression, std::map<string, BinaryOperator>& binary_operators, std::map<string, UnaryOperator>& unary_operators); 
