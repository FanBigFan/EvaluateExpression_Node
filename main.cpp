#pragma once

#include <iostream>
#include <windows.h>

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

    LARGE_INTEGER t1, t2, tc;
    double time = 0;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    string str = "3.01/(5-3+2)-9%7+5";
    cout << "\nInfix :\t" << str << endl;
    cout << eva.evaluateExpression(str, nodeList, ms, mf) << endl;

    QueryPerformanceCounter(&t2);
    time = (double) (t2.QuadPart - t1.QuadPart) / (double) tc.QuadPart;
    cout << "Time  : " << time * 1000 << "ms" << endl;  //输出时间（单位：ｓ）

    return 0;
}
