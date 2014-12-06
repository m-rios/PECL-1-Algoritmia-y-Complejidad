//
//  concierto.cpp
//  PECL1AyC
//
//  Created by Mario on 18/11/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#include "concierto.h"

Concierto::Concierto(int N, int P, int Q, vector<int> F, vector<int> G)
{
    this->N = N; // n personas
    this->P = P; //n filas
    this->Q = Q; //n grupos
    this->F = F; // array filas
    this->G = G; // array grupos
}

Concierto::~Concierto()
{
    
}

vector<int> Concierto::asignar_Lima()
{
    int complains = 0;
    vector<int> filas = F;
    vector<int> grupos = G;;
    int* first(&filas[0]);
    int* last(first + P);
    int c = 0;
    int pos;
    while (c < Q) {
        //look for empty space of groups size
        pos = find(filas, 0, P, grupos[c]);
        if (pos > -1) { //space found
            filas[pos] -=grupos[c];
        } else {
            int max = get_max(filas);
            if (grupos[c] < filas[max]) {
                filas[max] -= grupos[c];
            } else {
                max = get_max(filas);
                while (grupos[c] > filas[max]) {
                    grupos[c] -= filas[max];
                    filas[max] = 0;
                    get_max(filas);
                    c++;
                }
                filas[max] -= grupos[c];
            }
        }
        c++;
    }
    cout << endl;
    return filas;
}

int Concierto::get_max(vector<int> n)
{
    //O(n)
    int max = 0;
    int size = (int) sizeof(n) / (int) sizeof(int);
    for (int i = 0; i < size; i++) {
        if (max < n[i]) {
            max = n[i];
        }
    }
    return max;
}

int Concierto::find(vector<int> a, int ini, int fin, int key)
{ //binary search
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

void Concierto::custom_sort(int * master, int * slave, int ini, int fin)
{ //merge sort on master & slave, taking master's value as reference
    if (ini != fin) {
        int mid = (ini + fin) / 2;
        custom_sort(master, slave, ini, mid);
        custom_sort(master, slave, mid+1, fin);
        master = merge(master, ini, mid, mid+1, fin);
        slave = merge(slave, ini, mid, mid+1, fin);
    }
}

int* Concierto::merge(int * a, int inia, int fina, int inib,  int finb)
{
    int n = (fina - inia) + (finb - inib);
    int* sol = (int*) malloc(n*sizeof(int));
    
    int c = 0;
    int i = inia;
    int j = inib;
    
    while ((i <= fina) && (j <= finb)) {
        if (a[i] >= a[j]) {
            sol[c] = a[i];
            i++;
        } else {
            sol[c] = a[j];
            j++;
        }
        c++;
    }
    
    if (i < fina) {
        while (i <= fina) {
            sol[c] = a[i];
            i++;
            c++;
        }
    }else if (j < finb) {
        while (j <= finb) {
            sol[c] = a[j];
            j++;
            c++;
        }
    }
    
    /*
    cout << "sol" << endl;
    
    for (int i = 0; i < n ; i++) {
        cout << sol[i];
    }
    cout << endl;
    */
    return sol;
}

void Concierto::sort_test(int * master, int * slave)
{
    custom_sort(master, slave, 0, 9);
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