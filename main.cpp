#include <iostream>
#include "MatrixTemplate.h"
#include "MatrixFactory.h"

int main() {
    MatrixFactory<int>* matfact;
    auto pow = matfact->createMatrixTemplate(1,3);
    pow->setValue(0,0,-1);
    pow->setValue(0,1,3);
    pow->setValue(0,2,5);
    /*pow->setValue(1,0,2);
    pow->setValue(1,1,7);
    pow->setValue(1,2,-5);
    pow->setValue(2,0,-9);
    pow->setValue(2,1,0);
    pow->setValue(2,2,0);*/
    int n1=pow->norma1();
    std::cout<<n1;
}