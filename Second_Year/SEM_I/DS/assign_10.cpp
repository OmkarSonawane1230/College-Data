// ======================================================================
// Name        : assign_10.cpp
// Author      : Omkar Sonawane
// Description : This program implements Infix to postfix converstion 
//               using stack.
// ======================================================================

#include <iostream>
#include <string>

using namespace std;

class InfixToPostfix {
    char stack[100];
    int top;

public:
    InfixToPostfix() {
        top = -1;
    }
    
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0;
    }

    
    bool isOperand(char c) {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    
    string infixToPostfix(const string &infix) {
        string postfix = "";
        for (int i = 0; i < infix.length(); i++) {
            char current = infix[i];

            if (isOperand(current)) {
                postfix += current;
            } else if (current == '(') {
                stack[++top] = current;
            } else if (current == ')') {
                while (top != -1 && stack[top] != '(') {
                    postfix += stack[top--];
                }
                top--; 
            } else if (isOperator(current)) {
                while (top != -1 && precedence(stack[top]) >= precedence(current)) {
                    postfix += stack[top--];
                }
                stack[++top] = current; 
            }
        }

        while (top != -1) {
            postfix += stack[top--];
        }

        return postfix;
    }
};

int main() {
    InfixToPostfix converter;

    string infixExpression;
    cout << "Enter infix expression: ";
    cin >> infixExpression;

    string postfixExpression = converter.infixToPostfix(infixExpression);
    
    cout << "Postfix expression: " << postfixExpression << endl;
    
    return 0;
}


/*
Enter infix expression: A+B*(C^D-E)
Postfix expression: ABCD^E-*+
*/