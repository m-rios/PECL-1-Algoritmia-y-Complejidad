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
    
    
    
    void custom_sort(int * master, int * slave, int ini, int fin);
    int get_max(vector<int> n);
    bool fill(int nfila, int npersonas, int id);
    
public:
    int* merge(int * a, int inia, int fina, int inib,  int finb);
    Concierto(int N, int P, int Q, vector<int> F, vector<int> G);
    vector<int> asignar_Lima();
    void print();
    //int find(vector<int>, int ini, int fin, int key);
    void sort_test(int* master, int* slave);
    int get_complains();
    void printButacas();
    ~Concierto();
};

#endif /* defined(__PECL1AyC__concierto__) */
