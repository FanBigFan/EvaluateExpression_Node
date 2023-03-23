//
// Created by FanBig on 2023/3/23.
//

#ifndef EVALUATEEXPRESSION_NODE_EVALUATEEXPR_H
#define EVALUATEEXPRESSION_NODE_EVALUATEEXPR_H

#include <string>
#include <vector>
#include <iostream>

#include "MyNode.h"
#include "MyOdNode.h"
#include "MyOpNode.h"
#include "MyStack.h"

using namespace std;

class evaluateExpr {
public:
    double evaluateExpression(string expression, vector<MyNode *> nodeList, MyStack<MyOpNode *> ms);

    double MyAbs(double val) {
        if (val > 0) {
            return val;
        } else {
            return -val;
        }
    }

    double mod(double a, double b) {
        double c = MyAbs(a);
        double d = MyAbs(b);

        while (c >= b) {
            c = c - b;
        }

        if (a * b > 0) {
            return c;
        } else {
            return -c;
        }
    }

};


#endif //EVALUATEEXPRESSION_NODE_EVALUATEEXPR_H
