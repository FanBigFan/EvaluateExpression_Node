#pragma once

#include <iostream>

#include "EvaluateExpr.h"

#include "MyOdNode.h"
#include "MyOpNode.h"
#include "MyNode.h"
#include "MyStack.h"
#include "ModFun.h"

int main() {
    MyOpNode op;
    MyOdNode od;
    MyNode node;
    MyStack<MyOpNode *> ms;
    EvaluateExpr eva;
    ModFun mf;
    vector<MyNode *> nodeList;

    string str = "3.01/(5-3+2)-9%7+5";
    cout << "\nInfix :\t" << str << endl;
    cout << eva.evaluateExpression(str, nodeList, ms, mf) << endl;
    return 0;
}
