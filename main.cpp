#include <iostream>
#include "MatrixTemplate.h"

int main() {
    MatrixTemplate<int>pow(2,2);
    pow.setValue(0,0,2);
    pow.setValue(0,1,3);
    pow.setValue(1,0,4);
    pow.setValue(1,1,5);
    MatrixTemplate<int>pow2(2,2);
    pow2.setValue(0,0,3);
    pow2.setValue(0,1,7);
    pow2.setValue(1,0,5);
    pow2.setValue(1,1,1);
    MatrixTemplate<int>mult=pow.elpow(3);
    mult.print();
}