// Copyright 2021 Ziganshin Nikita
#include <iostream>
#include <string>

#include "postfix.h"

int main() {
    std::string inf = "2 + 2";
    std::string postf = infix2postfix(inf);
    std::cout << postf;
    return 0;
}
