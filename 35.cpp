#include <iostream>
#include <stack>
#include <string>
#include <sstream>

// Function to evaluate a prefix expression
int evaluatePrefix(const std::string& expression) {
    std::stack<int> operands;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            // Token is an operand (either positive or negative)
            operands.push(std::stoi(token));
        } else {
            // Token is an operator
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            if (token == "+") {
                operands.push(operand1 + operand2);
            } else if (token == "-") {
                operands.push(operand1 - operand2);
            } else if (token == "*") {
                operands.push(operand1 * operand2);
            } else if (token == "/") {
                operands.push(operand1 / operand2);
            }
            // You can add more operators as needed
        }
    }

    return operands.top();
}

int main() {
    std::string prefixExpression = "+ - 3 4 * 5 6"; // Example prefix expression
    int result = evaluatePrefix(prefixExpression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
