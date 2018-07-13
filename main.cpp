#include <iostream>
#include "MatrixTemplate.h"
#include "MatrixFactory.h"

int main() {
    MatrixFactory<int>* matfact;
    auto pow1 = matfact->createMatrixTemplate(1,3);
    pow1->setValue(0,0,-1);
    pow1->setValue(0,1,3);
    pow1->setValue(0,2,5);
    /*pow->setValue(1,0,2);
    pow->setValue(1,1,7);
    pow->setValue(1,2,-5);
    pow->setValue(2,0,-9);
    pow->setValue(2,1,0);
    pow->setValue(2,2,0);*/
    double n2=pow1->norma2();
    std::cout<<n2;
}