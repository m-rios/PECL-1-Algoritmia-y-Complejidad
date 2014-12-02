//
//  concierto.cpp
//  PECL1AyC
//
//  Created by Mario on 18/11/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#include "concierto.h"

Concierto::Concierto(int N, int P, int Q, int *F, int *G)
{
    this->N = N; // n personas
    this->P = P; //n filas
    this->Q = Q; //n grupos
    this->F = F; // array filas
    this->G = G; // array grupos
    B = (int**) malloc(P*sizeof(int*));
    for (int i = 0; i < P; i++) {
        B[i] = (int*) malloc(F[i]*sizeof(int));
    }
}

Concierto::~Concierto()
{
    
}

int* Concierto::asignar_Lima()
{
    int complains = 0;
    int* sol = (int*) malloc(10*sizeof(int));
    sol = F;
    int* first(&sol[0]);
    int* last(first + P);
    int pos;
    for (int i = 0; i < Q; i++) {
        sort(first, last, greater<int>()); //nlog(n)
        pos = find(sol, 0, P, G[i]); //lg(n)
        if (pos > -1) { //exact empty space
            sol[pos] = 0;
            continue;
        }
        if (sol[0] > G[i]) {
            sol[0] -= G[i];
            continue;
        }
        complains += G[i];
        int g_size = G[i];
        int c = 0;
        while (g_size > sol[c]) {
            g_size -= sol[c];
            sol[c] = 0;
            c++;
        }
        sol[c] -= g_size;
    }
    cout << endl;
    return sol;
}

int Concierto::find(int* a, int ini, int fin, int key)
{
    if (ini == fin) {
        if (a[ini] == key) {
            return ini;
        }
        return -1;
    }
    int mid = (fin + ini) / 2;
    if (key <= mid) {
        find(a, ini, mid, key);
    } else {
        find(a,mid+1,fin,key);
    }
    return -2; // to avoid compiler error, theoretically unnecesary
}

void Concierto::print()
{
    cout << "N: "<< N << endl;
    cout << "P: " << P<< endl;
    cout << "Q: " << Q<< endl;
    cout << "Filas: ";
    for (int i = 0; i < P; i++) {
        cout << "[" << F[i] << "]";
    }
    cout << endl;
}