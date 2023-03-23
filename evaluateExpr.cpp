//
// Created by FanBig on 2023/3/23.
//

#include "evaluateExpr.h"

double evaluateExpr::evaluateExpression(string expression, vector<MyNode *> nodeList, MyStack<MyOpNode *> ms) {
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

            while (tempOpNode->level <= tempTopNode->level) {
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

            while (tempOpNode->level <= tempTopNode->level) {
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
                nodeList.push_back(ms.pop());
                tempTopNode = ms.top();
            }

            ms.pop();
            index++;
        }

        while (!ms.isEmpty()) {
            MyOpNode *tempOpNode = ms.top();
            nodeList.push_back(tempOpNode);
            ms.pop();
        }


        for (auto tempNode: nodeList) {
            auto *odp = dynamic_cast<MyOdNode *>(tempNode);

            if (odp) {
                double d = ((MyOdNode *) tempNode)->val;
                cout << d << "|";
            } else {
                cout << ((MyOpNode *) tempNode)->op << "|";
            }
        }
        cout << endl;
    }
}