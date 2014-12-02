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
using namespace std;

#define MAX_F 10

class Concierto {
private:
    int N,P,Q;
    int *F, *G;
    int **B;
    
public:
    Concierto(int N, int P, int Q, int *F, int *G);
    int* asignar_Lima();
    void print();
    int find(int*a, int ini, int fin, int key);
    ~Concierto();
};

#endif /* defined(__PECL1AyC__concierto__) */
