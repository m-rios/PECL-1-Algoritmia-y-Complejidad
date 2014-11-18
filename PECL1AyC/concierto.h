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
using namespace std;

#define MAX_F 10

class Concierto {
private:
    int N,P,Q;
    int F[MAX_F], G[MAX_F];
    
public:
    Concierto(int N, int P, int Q, int *F, int *G);
    int asignar_Lima();
    void print();
    ~Concierto();
};

#endif /* defined(__PECL1AyC__concierto__) */
