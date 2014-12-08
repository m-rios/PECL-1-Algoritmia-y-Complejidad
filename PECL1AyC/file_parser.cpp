//
//  file_parser.cpp
//  PECL1AyC
//
//  Created by Mario on 18/11/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#include "file_parser.h"

Parser::Parser(const char* path)
{
    ifstream file (path);
    vector<string> content;
    string input ("\0");
    if (file.is_open()) {
        string tmp ("\0");
        while (getline(file,tmp)) {
            content.push_back(tmp);
        }
        N = stoi(content[0]);
        int posf = find(content.begin(), content.end(), "// Filas") - content.begin();
        P = stoi(content[posf+1]);
        int posg = find(content.begin() + posf, content.end(), "// Grupos") - content.begin();
        Q = stoi(content[posg + 1]);
        for (int i = posf + 2; i < posg; i++) {
            F.push_back(stoi(content[i]));
        }
        for (int i = posg + 2; i < content.size(); i++) {
            G.push_back(stoi(content[i]));
        }
    }
    else
        cout << "could not open file" << endl;
    
}

Concierto Parser::get_concierto()
{
    return Concierto(N,P,Q,F,G);
}

Parser::~Parser()
{
    
}