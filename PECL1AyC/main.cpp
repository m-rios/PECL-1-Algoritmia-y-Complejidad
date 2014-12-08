//
//  main.cpp
//  PECL1AyC
//
//  Created by Mario on 18/11/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "file_parser.h"
#include "concierto.h"
using namespace std;

#define MAX_F 10
int main(int argc, const char * argv[]) {

    const char * path;
    
    path = argv[2];
    
    Parser file = Parser(path);
    
    Concierto concierto = file.get_concierto();

    vector<int> sol = concierto.asignar_Lima();
    for (int i = 0; i < sol.size(); i++) {
        cout << "[" << sol[i] << "]";
    }
    cout << endl;
    concierto.printButacas();
    cout << endl << "complains: " << concierto.get_complains() << endl;
    
    return 0;
}
