//
// Created by FanBig on 2023/3/27.
//

#pragma once

#include <iostream>

#include "EvaluateExpr.h"

#include "MyOdNode.h"
#include "MyOpNode.h"
#include "MyNode.h"
#include "MyStack.h"
#include "ModFun.h"
#include "ReadNumber.h"

int main() {
    MyOpNode op;
    MyOdNode od;
    MyNode node;
    MyStack<MyOpNode *> ms;
    EvaluateExpr eva;
    ModFun mf;
    ReadNumber rn;
    vector<MyNode *> nodeList;

    string str = "123.1";

    cout << rn.readNum(str) - 1 << endl;

    return 0;
}
