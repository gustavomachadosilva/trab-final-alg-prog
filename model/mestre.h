//
//  mestre.h
//  INFmon
//
//  Created by Gustavo Machado Silva on 26/07/24.
//

#ifndef mestre_h
#define mestre_h

#include <stdio.h>
#include "infmon.h"

#define MAX_INFMONS 4

typedef struct {
    int x;
    int y;
    Infmon infmons[MAX_INFMONS];
}Mestre;

#endif /* mestre_h */
