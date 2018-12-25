#include <iostream>
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "Command.h"
#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include "Expression.h"
#include "CreateExpression.h"
#include <iostream>
#include <fstream>
#include <list>
#include "lexer.h"
#include "parser.h"


int main() {


    lexer* lex = new lexer("test.txt");
    vector<string> toParser;
    toParser = lex->lexerFile();
    parser* par = new parser();
    par->runParser(toParser);




    /*list<string> myList;

    string line;
    char* toChar;
    char* cut;
    ifstream ifstream1;
    ifstream1.open("test.txt", ios::in);

    if (ifstream1.is_open()) {
        while (getline(ifstream1, line)) {
            toChar = const_cast <char *>(line.c_str());
            cut = strtok(toChar, " ");
            do {
                //myList.insert(cut);
                myList.push_back(cut);
                cut = strtok(NULL, " ");
            } while (cut != NULL);
        }
    }
         OpenServerCommand openServerCommand;
         openServerCommand.doCommand("5400 10");

         ConnectCommand connectCommand;
         connectCommand.execute("127.0.0.1 5400");

         std::cout << "Hello, World!" << std::endl;*/
    /*string s="3+(4/2)*5";
    createExpression* c;
    Expression* e=c->convertToExpression(s);
    cout<<e->calculate()<<endl;*/
    //cout << "hello" << endl;
    return 0;
}