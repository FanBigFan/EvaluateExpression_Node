cmake_minimum_required(VERSION 3.24)
project(EvaluateExpression_Node)

set(CMAKE_CXX_STANDARD 17)

add_executable(EvaluateExpression_Node main.cpp MyStack.cpp MyStack.h MyNode.h MyOdNode.cpp MyOdNode.h MyOpNode.cpp MyOpNode.h EvaluateExpr.cpp EvaluateExpr.h ModFun.cpp ModFun.h)
