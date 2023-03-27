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
#include "ModFun.h"

using namespace std;

class EvaluateExpr {
public:
    double evaluateExpression(string expression, vector<MyNode *> nodeList, MyStack<MyOpNode *> ms, ModFun mf);

};


#endif //EVALUATEEXPRESSION_NODE_EVALUATEEXPR_H
