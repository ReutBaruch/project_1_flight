cmake_minimum_required(VERSION 3.13)
project(project1)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")

add_executable(project1 main.cpp BineryExpression.h Command.h ConnectCommand.cpp ConnectCommand.h
        createExpression.cpp createExpression.h Div.cpp Div.h Expression.h Minus.cpp Minus.h
        Mul.cpp Mul.h Num.cpp Num.h OpenServerCommand.h Plus.cpp Plus.h lexer.cpp lexer.h VarCommand.cpp VarCommand.h conditionParser.cpp conditionParser.h ifCommand.cpp ifCommand.h LoopCommand.cpp LoopCommand.h OpenServerCommand.cpp SymbolTable.h CommandExpression.cpp CommandExpression.h SymbolTable.cpp printCommand.cpp printCommand.h sleepCommmand.cpp sleepCommmand.h CheckConnection.cpp CheckConnection.h PathMap.cpp PathMap.h FlightValueMap.cpp FlightValueMap.h StringFlightControls.cpp StringFlightControls.h SetControlCommand.cpp SetControlCommand.h parser.cpp parser.h)