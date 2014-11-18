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
    string input ("\0");
    if (file.is_open()) {
        string tmp ("\0");
        //valor de N es lo primero que encontramos
        getline(file, tmp);
        N = stoi(tmp);
        //capturar '// Filas'
        getline(file, tmp);
        //tomar tamaño P e iterar sobre F
        getline(file, tmp);
        P = stoi(tmp);
        getline(file,tmp);
        int i = 0;
        while (tmp != "// Grupos") {
            F[i] = stoi(tmp);
            i++;
            getline(file,tmp);
        }
        // ya hemos leido '// Grupos'
        getline(file,tmp);
        Q = stoi(tmp);
        i = 0;
        while (getline(file,tmp)) {
            G[i] = stoi(tmp);
            i ++;
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