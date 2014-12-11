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
    
    bool verbose = false;
    
    if (argc > 3 || argc < 2) {
        cout << "Numero de parametros incorrecto" << endl;
        cout << "Uso: [-v] path_to_file" << endl;
        return 0;
    }
    
    const char * path = NULL;
    
    if (argc == 3) {
        if (strcmp(argv[1], "-v") != 0) {
            cout << "parametro '" << argv[1] << "' no reconocido" << endl;
            return 0;
        }
        ifstream txt (argv[2]);
        if (!txt.is_open()) {
            cout << "la ruta al archivo parece incorrecta" << endl;
            return 0;
        }
        path = argv[2];
        txt.close();
        verbose = true;
    } else {
        ifstream txt (argv[1]);
        if (!txt.is_open()) {
            cout << "la ruta al archivo parece incorrecta" << endl;
            return 0;
        }
        path = argv[1];
        txt.close();
    }
    
    Parser file = Parser(path);
    Concierto concierto = file.get_concierto();

    int quejas = concierto.asignar_Lima(verbose);
    concierto.printButacas();
    cout << endl << "complains: " << quejas << endl;
    
    return 0;
}
