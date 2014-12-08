//
//  row.cpp
//  PECL1AyC
//
//  Created by Mario on 06/12/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#include "row.h"

Row::Row(int size)
{
    free = 0;
    chairs.resize(size);
}