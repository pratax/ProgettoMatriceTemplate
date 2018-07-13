#include <iostream>
#include "MatrixTemplate.h"
#include "MatrixFactory.h"

int main() {
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(0,0,1);
    Mat1->setValue(0,1,5);
    Mat1->setValue(0,2,3);
    Mat1->setValue(1,2,7);
    Mat1->setValue(2,0,5);
    Mat1->setValue(2,1,10);
    Mat1->setValue(2,2,-5);
    MatrixTemplate<int>Mat2(*Mat1);
    Mat2.setValue(2,1,5);
    Mat2.setValue(1,1,-9);
    Mat1->print();
    std::cout<<std::endl;
    Mat2.print();
}