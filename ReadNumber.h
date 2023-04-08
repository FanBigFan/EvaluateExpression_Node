//
// Created by FanBig on 2023/3/27.
//

#ifndef EVALUATEEXPRESSION_NODE_READNUMBER_H
#define EVALUATEEXPRESSION_NODE_READNUMBER_H

#include <string>

class ReadNumber {
public:
    double readNum(const std::string &str) {
        int dotIndex;
        double sum = 0;
        double result = 0;

        for (int i = 0; i < str.length(); ++i) {
            if (std::isdigit(str[i])) {
                sum = sum * 10 + (str[i] - '0');
            } else if (str[i] == '.') {
                dotIndex = i;
            }
        }
    }
};


#endif //EVALUATEEXPRESSION_NODE_READNUMBER_H
