// Copyright 2021 Ziganshin Nikita
#include "MyStack.h"
#include "postfix.h"

int priority(char ch) {
    if (ch == '(') {
        return 0;
    } else if (ch == ')') {
        return 1;
    } else if (ch == '+' || ch == '-') {
        return 2;
    } else if (ch == '*' || ch == '/') {
        return 3;
    } else if (ch == ' ') {
        return 4;
    } else {
        return 5;
    }
}

std::string infix2postfix(const std::string& infix) {
    MyStack<char> st(10);
    std::string result;
    int temp = 0;
    for (char i : infix) {
        if (priority(i) == 5) {
            if (result.empty()) {
                result = i;
            } else {
                if (i == '.' || temp == 1) {
                    if (temp == 1) {
                        result += i;
                        temp = 0;
                    } else {
                        result += i;
                        temp = 1;
                    }
                } else {
                    result += ' ';
                    result += i;
                }
            }
        } else {
            if (priority(i) == 4) {
                continue;
            } else if (priority(i) == 0 || st.isEmpty() || priority(i) > priority(st.get())) {
                st.push(i);
            } else if (priority(i) == 1) {
                while (priority(st.get()) != 0) {
                    result += ' ';
                    result += st.pop();
                }
                st.pop();
            } else {
                for (;;) {
                    if (st.isEmpty()) {
                        st.push(i);
                        break;
                    } else {
                        if (priority(st.get()) >= priority(i)) {
                                result += ' ';
                                result += st.pop();
                        } else {
                            st.push(i);
                            break;
                        }
                    }
                }
            }
        }
    }
    while (!st.isEmpty()) {
        if (priority(st.get()) == 0) {
            st.pop();
        } else {
            result += ' ';
            result += st.pop();
        }
    }
    return result;
}
