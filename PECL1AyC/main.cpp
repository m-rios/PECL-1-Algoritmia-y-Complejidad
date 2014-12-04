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
    
    int master[10];
    int slave[10];
    int test[10] = {6,7,8,9,10,1,2,3,4,5};
    int *test2 = concierto.merge(&test[0], 0, 4, 5, 9);
    
    for (int i = 0; i < 10; i++) {
        cout << test2[i];
    }
    cout << endl;
    
    /*
    for (int i = 0; i < 10 ; i++) {
        master[i] = rand()%10;
        slave[i] = i;
    }
    concierto.sort_test(&master[0], &slave[0]);
    cout << "master" << endl;
    for (int i = 0; i < 10; i++) {
        cout << master[i];
    }
    cout << endl << "slave" << endl;;
    for (int i = 0; i < 10; i++) {
        cout << slave[i];
    }
    cout << endl;
    
    int * sol = concierto.asignar_Lima();
    concierto.print();
    cout<< ";;;;;;;;;;;;;"<<endl;
    cout << "Filas: ";
    int P = sizeof(sol) / sizeof(int);
    for (int i = 0; i < P; i++) {
        cout << "[" << sol[i] << "]";
    }*/
    cout << endl;
    return 0;
}
