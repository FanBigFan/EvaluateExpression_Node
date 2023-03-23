#pragma once

#include <iostream>

#include "evaluateExpr.h"

#include "MyOdNode.h"
#include "MyOpNode.h"
#include "MyNode.h"
#include "MyStack.h"

int main() {
    MyOpNode op;
    MyOdNode od;
    MyNode node;
    MyStack<MyOpNode *> ms;
    evaluateExpr eva;
    vector<MyNode *> nodeList;

    string str = "3.01/(5-3+2)-9%7+5";
    eva.evaluateExpression(str, nodeList, ms);

    return 0;
}
