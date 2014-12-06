//
//  file_parser.h
//  PECL1AyC
//
//  Created by Mario on 18/11/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#ifndef __PECL1AyC__file_parser__
#define __PECL1AyC__file_parser__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "concierto.h"
using namespace std;

#define MAX_F 10

class Parser {
private:
    char* path;
    int N,P,Q;
    vector<int> F;
    vector<int> G;
    
public:
    Parser(const char* path);
    ~Parser();
    Concierto get_concierto();

};

#endif /* defined(__PECL1AyC__file_parser__) */
