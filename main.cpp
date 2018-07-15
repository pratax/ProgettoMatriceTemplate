#include <iostream>
#include "MatrixTemplate.h"
#include "MatrixFactory.h"

int main() {
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,1);
    Mat1->setValue(1,2,9);
    Mat1->setValue(1,3,3);
    Mat1->setValue(2,1,7);
    Mat1->setValue(2,2,5);
    Mat1->setValue(3,1,5);
    Mat1->setValue(3,2,10);
    Mat1->setValue(3,3,-5);
    Mat1->print();
    auto Mat3(*Mat1);
    bool i = (Mat3!=*Mat1);
    std::cout<<i;
}