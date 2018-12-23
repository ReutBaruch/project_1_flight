

#include "lexer.h"

lexer::lexer(string name){
    this->fileName = name;
}

vector<string> lexer::lexerFile() {
    vector<string> buffer;
    string line;
    char* toChar;
    char* cut;
    ifstream lexFile;
    lexFile.open(this->fileName, ios::in);
    if (lexFile.is_open()){
        while (getline(lexFile, line)){
            toChar = const_cast <char *>(line.c_str());
            cut = strtok(toChar, " ");
            do{
                buffer.push_back(cut);
                cut = strtok(NULL, " ");
            } while (cut != NULL);
           buffer.push_back(";");
        }
        lexFile.close();
    } else {
        throw "unable to open file.";
    }
    return buffer;
}
