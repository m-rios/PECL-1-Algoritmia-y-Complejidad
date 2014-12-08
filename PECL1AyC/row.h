//
//  row.h
//  PECL1AyC
//
//  Created by Mario on 06/12/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#ifndef __PECL1AyC__row__
#define __PECL1AyC__row__

#include <stdio.h>
#include <vector>

using namespace std;
class Row {
    
public:
    int free;
    vector<int> chairs;
    
    Row(int size);
};

#endif /* defined(__PECL1AyC__row__) */