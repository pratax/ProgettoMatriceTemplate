#include <iostream>
#include "MatrixTemplate.h"
#include "MatrixFactory.h"

int main() {
    MatrixFactory<float>* floatFactory;
    auto Mat1 = floatFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,1.5);
    Mat1->setValue(1,2,2.3);
    Mat1->setValue(1,3,3.2);
    Mat1->setValue(2,2,1.8);
    Mat1->setValue(3,1,4.4);
    Mat1->setValue(3,2,5.6);
    Mat1->setValue(3,3,8.7);
    auto Mat2 = *Mat1;
    Mat2.print();
}