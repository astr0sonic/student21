#include "bracket.h"

bool checkBrackets(const std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{' || c == '<') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}' || c == '>') {
            if (!st.empty() && isCorrectBracket(st.top(), c)) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}