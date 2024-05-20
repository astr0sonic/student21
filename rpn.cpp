#include "rpn.h"
#include <stack>
#include <sstream>

double calculateRPN(const std::string& expr) {
    std::stack<double> stack;
    std::istringstream is(expr);

    std::string tok;
    while (is >> tok) {
        if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
            double op2 = stack.top();
            stack.pop();
            double op1 = stack.top();
            stack.pop();

            double result;
            if (tok == "+") {
                result = op1 + op2;
            }
            else if (tok == "-") {
                result = op1 - op2;
            }
            else if (tok == "*") {
                result = op1 * op2;
            }
            else if (tok == "/") {
                result = op1 / op2;
            }

            stack.push(result);
        }
        else {
            stack.push(std::stod(tok));
        }
    }

    return stack.top();
}
