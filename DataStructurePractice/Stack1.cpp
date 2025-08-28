#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int top = 0;
    char arr[1000];  // Using char array for simpler bracket storage
    
    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }
    
    void push(char x) {
        if (!isFull()) {
            arr[top] = x;
            top++;
        }
    }
    
    bool isEmpty() {
        return (top == 0);
    }
    
    bool isFull() {
        return (top == 1000);
    }
    
    char peek() {
        if (!isEmpty()) {
            return arr[top-1];
        }
        return '\0';
    }
    
    bool isMatching(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']') ||
               (open == '<' && close == '>') ||
               (open == 'D' && close == 'd'); // 'D' represents <<, 'd' represents >>
    }

    bool isValid(string s) {
        top = 0; // Reset stack
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '<') {
                // Count consecutive '<' characters
                int count = 0;
                int j = i;
                while (j < s.length() && s[j] == '<') {
                    count++;
                    j++;
                }
                
                // Push appropriate brackets onto stack
                for (int k = 0; k < count / 2; k++) {
                    push('D'); // 'D' represents <<
                }
                if (count % 2 == 1) {
                    push('<'); // Single <
                }
                
                i = j - 1; // Adjust loop counter
            }
            else if (s[i] == '>') {
                // Count consecutive '>' characters
                int count = 0;
                int j = i;
                while (j < s.length() && s[j] == '>') {
                    count++;
                    j++;
                }
                
                // Match with stack in proper order (LIFO)
                if (count % 2 == 1) {
                    if (isEmpty() || !isMatching(peek(), '>')) {
                        return false;
                    }
                    pop();
                }
                for (int k = 0; k < count / 2; k++) {
                    if (isEmpty() || !isMatching(peek(), 'd')) {
                        return false;
                    }
                    pop();
                }
                
                
                i = j - 1; // Adjust loop counter
            }
            else if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                push(s[i]);
            }
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (isEmpty() || !isMatching(peek(), s[i])) {
                    return false;
                }
                pop();
            }
        }
        
        // Stack should be empty for valid input
        return isEmpty();
    }
};

int main() {
    Solution sol;
    
    string tests[] = {
        "<<<30+20>*20>>",           // true
        "({[]})",           // true  
        "<<{[()]}>>",       // true
        "<<{[()]}>",        // false (mismatched)
        "<<<([])>>>",       // true
        "([)]",             // false (improper nesting)
        "<<>>",             // true
        "<>",               // true
        "((()))",           // true
        "((())",            // false (unmatched)
        "",                 // true (empty)
        "<<({[]})>>",       // true
        "<<<{[()]}>>>"      // false (mismatched angle counts)
    };
    
    for (const string& test : tests) {
        cout << "Testing: '" << test << "' -> " << sol.isValid(test) << endl;
    }
    
    return 0;
}