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
    Mat1->setValue(1,1,5);
    Mat1->setValue(2,0,5);
    Mat1->setValue(2,1,10);
    Mat1->setValue(2,2,-5);
    auto Mat2 = Mat1->transposedMatrix();
    Mat2.print();
}