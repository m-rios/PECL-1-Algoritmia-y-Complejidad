//
//  concierto.h
//  PECL1AyC
//
//  Created by Mario on 18/11/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#ifndef __PECL1AyC__concierto__
#define __PECL1AyC__concierto__

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include "row.h"


using namespace std;

#define MAX_F 10

class Concierto {
private:
    int N,P,Q;
    int complains;
    vector<int> F, G;
    vector<Row> B;
    
    int get_max(vector<int> n);
    int get_min(vector<int> n);
    bool fill(int nfila, int npersonas, int id);
    int asignar_Lima(vector<int> filas, vector<int> grupos);
    int asignar_Lima_Verbose(vector<int> filas, vector<int> grupos);
    
public:
    Concierto(int N, int P, int Q, vector<int> F, vector<int> G);
    int asignar_Lima(bool verbose);
    int get_complains();
    void printButacas();
    ~Concierto();
};

#endif /* defined(__PECL1AyC__concierto__) */
