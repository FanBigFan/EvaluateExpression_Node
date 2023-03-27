//
// Created by FanBig on 2023/3/23.
//

#include "EvaluateExpr.h"

double
EvaluateExpr::evaluateExpression(string expression, vector<MyNode *> nodeList, MyStack<MyOpNode *> ms, ModFun mf) {
    int index = 0;

    while (index < expression.length()) {
        char ch = expression[index];

        if (ch <= '9' && ch >= '0') {
            int tempIndex = index + 1;

            while ((tempIndex < expression.length()) &&
                   (expression[tempIndex] >= '0' && expression[tempIndex] <= '9' || expression[tempIndex] == '.')) {
                tempIndex++;
            }

            string tempStr;
            if (tempIndex >= expression.length()) {
                tempStr = expression.substr(index);
            } else {
                tempStr = expression.substr(index, tempIndex - index);
            }

            index = tempIndex;

            MyNode *tempNode = new MyOdNode(tempStr);
            nodeList.push_back(tempNode);
        }

        if (ch == '+' || ch == '-') {
            auto *tempOpNode = new MyOpNode(ch, 1);
            MyOpNode *tempTopNode = ms.top();

            while (tempTopNode != nullptr && tempTopNode->level >= tempOpNode->level) {
                MyOpNode *tempNode = ms.pop();
                nodeList.push_back(tempNode);
                tempTopNode = ms.top();
            }

            ms.push(tempOpNode);
            index++;
        }

        if (ch == '*' || ch == '/' || ch == '%') {
            auto *tempOpNode = new MyOpNode(ch, 2);
            MyOpNode *tempTopNode = ms.top();

            while (tempTopNode != nullptr && tempTopNode->level >= tempOpNode->level) {
                MyOpNode *tempNode = ms.pop();
                nodeList.push_back(tempNode);
                tempTopNode = ms.top();
            }

            ms.push(tempOpNode);
            index++;
        }

        if (ch == '(') {
            auto *tempOpNode = new MyOpNode(ch, -1);
            ms.push(tempOpNode);
            index++;
        }

        if (ch == ')') {
            MyOpNode *tempTopNode = ms.top();

            while (tempTopNode->op != '(') {
                nodeList.push_back(tempTopNode);
                ms.pop();
                tempTopNode = ms.top();
            }

            ms.pop();
            index++;
        }
    }

    while (!ms.isEmpty()) {
        MyOpNode *tempOpNode = ms.top();
        nodeList.push_back(tempOpNode);
        ms.pop();
    }

    // -------------  Output Suffix  -------------

    cout << "Suffix:\t";
    for (auto tempNode: nodeList) {
        auto *odp = dynamic_cast<MyOdNode *>(tempNode);

        if (odp) {
            double d = ((MyOdNode *) tempNode)->val;
            cout << d << " ";
        } else {
            cout << ((MyOpNode *) tempNode)->op << " ";
        }
    }
    cout << "\nResult:\t";

    // -------------  Output Suffix  -------------

    MyStack<double *> mns;
    int cIndex = 0;

    while (cIndex < nodeList.size()) {
        MyNode *tempNode = nodeList[cIndex];
        auto *opp = dynamic_cast<MyOpNode *>(tempNode);

        if (opp) {
            char op = opp->op;

            double od2 = *mns.pop();
            double od1 = *mns.pop();
            double re = 0;

            switch (op) {
                case '+':
                    re = od1 + od2;
                    break;
                case '-':
                    re = od1 - od2;
                    break;
                case '*':
                    re = od1 * od2;
                    break;
                case '/':
                    re = od1 / od2;
                    break;
                case '%':
                    re = mf.mod(od1, od2);
                    break;
                default:
                    break;
            }

            auto *res = new double(re);
            mns.push(res);
        } else {
            auto *res = new double(((MyOdNode *) tempNode)->val);
            mns.push(res);
        }
        cIndex++;
    }

    double result = 0;

    while (!mns.isEmpty()) {
        result = *mns.pop();
    }

    return result;
}