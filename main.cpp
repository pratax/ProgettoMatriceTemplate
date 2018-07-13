#include <iostream>
#include "MatrixTemplate.h"
#include "MatrixFactory.h"

int main() {
    MatrixFactory<int>* matfact;
    auto pow1 = matfact->createMatrixTemplate(3,3);
    pow1->setValue(0,0,-1);
    pow1->setValue(0,1,3);
    pow1->setValue(0,2,5);
    pow1->setValue(1,0,2);
    pow1->setValue(1,1,7);
    pow1->setValue(1,2,-5);
    pow1->setValue(2,0,-9);
    pow1->setValue(2,1,0);
    pow1->setValue(2,2,0);
    auto identity1 = pow1->identity();
    identity1.print();
}