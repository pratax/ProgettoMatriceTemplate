//
// Created by Christian Pratellesi on 13/07/18.
//
#include "gtest/gtest.h"
#include "../MatrixTemplate.h"
#include "../MatrixFactory.h"

TEST(MatrixTemplate,DefaultConstructor){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    ASSERT_EQ(3,Mat1->getRows());
    ASSERT_EQ(3,Mat1->getColumns());
    ASSERT_EQ(0,Mat1->getValue(2,2));
    auto Mat2 = intFactory->createMatrixTemplate(0,2);
    ASSERT_EQ(1,Mat2->getRows());
}

TEST(MatrixTemplate,CopyConstructor){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,1);
    Mat1->setValue(1,2,5);
    Mat1->setValue(1,3,3);
    Mat1->setValue(2,3,7);
    Mat1->setValue(3,1,5);
    Mat1->setValue(3,2,10);
    Mat1->setValue(3,3,-5);
    auto Mat2(*Mat1);
    ASSERT_TRUE(Mat2==*Mat1);
    Mat2.setValue(2,1,5);
    Mat2.setValue(1,1,-9);
    ASSERT_FALSE(Mat2==*Mat1);
}

TEST(MatrixTemplate,SelectRow){
    MatrixFactory<double>* doubleFactory;
    auto Mat1 = doubleFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,1.3);
    Mat1->setValue(1,2,2.5);
    Mat1->setValue(1,3,4.3);
    Mat1->setValue(2,3,7.7);
    Mat1->setValue(3,1,8.5);
    Mat1->setValue(3,2,1.1);
    Mat1->setValue(3,3,5.4);
    auto MatRow = Mat1->selectRow(3);
    ASSERT_EQ(8.5,MatRow.getValue(1,1));
    ASSERT_EQ(1.1,MatRow.getValue(1,2));
    ASSERT_EQ(5.4,MatRow.getValue(1,3));
    ASSERT_THROW(Mat1->selectRow(0),std::out_of_range);
    ASSERT_THROW(Mat1->selectRow(4),std::out_of_range);
}

TEST(MatrixTemplate,SelectColumn){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,1);
    Mat1->setValue(1,2,5);
    Mat1->setValue(1,3,3);
    Mat1->setValue(2,3,7);
    Mat1->setValue(3,1,5);
    Mat1->setValue(3,2,10);
    Mat1->setValue(3,3,-5);
    auto MatColumn = Mat1->selectColumn(2);
    ASSERT_EQ(5,MatColumn.getValue(1,1));
    ASSERT_EQ(0,MatColumn.getValue(2,1));
    ASSERT_EQ(10,MatColumn.getValue(3,1));
    ASSERT_THROW(Mat1->selectColumn(0),std::out_of_range);
    ASSERT_THROW(Mat1->selectColumn(4),std::out_of_range);
}

TEST(MatrixTemplate,GetValue){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,1);
    Mat1->setValue(1,2,5);
    Mat1->setValue(1,3,3);
    Mat1->setValue(2,3,7);
    Mat1->setValue(3,1,5);
    Mat1->setValue(3,2,10);
    Mat1->setValue(3,3,-5);
    ASSERT_EQ(1,Mat1->getValue(1,1));
    ASSERT_THROW(Mat1->getValue(0,0),std::out_of_range);
    ASSERT_THROW(Mat1->getValue(4,5),std::out_of_range);
}

TEST(MatrixTemplate,SetValue){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,1);
    Mat1->setValue(1,2,5);
    Mat1->setValue(1,3,3);
    Mat1->setValue(2,3,7);
    Mat1->setValue(3,1,5);
    Mat1->setValue(3,2,10);
    Mat1->setValue(3,3,-5);
    ASSERT_THROW(Mat1->setValue(5,2,10),std::out_of_range);
}

TEST(MatrixTemplate,OperatorAssignement){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,1);
    Mat1->setValue(1,2,5);
    Mat1->setValue(1,3,3);
    Mat1->setValue(2,3,7);
    Mat1->setValue(3,1,5);
    Mat1->setValue(3,2,10);
    Mat1->setValue(3,3,-5);
    auto Mat2 = *Mat1;
    ASSERT_EQ(Mat1->getValue(1,1),Mat2.getValue(1,1));
    ASSERT_EQ(Mat1->getRows(),Mat2.getRows());
    ASSERT_EQ(Mat1->getColumns(),Mat2.getColumns());
}

TEST(MatrixTemplate,TransposedMatrix){
    MatrixFactory<float>* floatFactory;
    auto Mat1 = floatFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,1.5);
    Mat1->setValue(1,2,2.3);
    Mat1->setValue(1,3,3.2);
    Mat1->setValue(2,2,1.8);
    Mat1->setValue(3,1,4.4);
    Mat1->setValue(3,2,5.4);
    Mat1->setValue(3,3,8.7);
    auto Mat2 = Mat1->transposedMatrix();
    ASSERT_FLOAT_EQ(1.5,Mat2.getValue(1,1));
    ASSERT_FLOAT_EQ(2.3,Mat2.getValue(2,1));
    ASSERT_FLOAT_EQ(5.4,Mat2.getValue(2,3));
    ASSERT_EQ(3,Mat2.getRows());
    ASSERT_EQ(3,Mat2.getColumns());
}

TEST(MatrixTemplate,OperatorPlus){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,5);
    Mat1->setValue(1,2,3);
    Mat1->setValue(1,3,2);
    Mat1->setValue(2,2,8);
    Mat1->setValue(3,1,4);
    Mat1->setValue(3,2,4);
    Mat1->setValue(3,3,7);
    auto Mat2 = intFactory->createMatrixTemplate(3,3);
    auto Mat3 = intFactory->createMatrixTemplate(2,2);
    Mat2->setValue(1,1,1);
    Mat2->setValue(1,2,2);
    Mat2->setValue(1,3,3);
    Mat2->setValue(2,2,5);
    Mat2->setValue(3,1,8);
    Mat2->setValue(3,2,4);
    Mat2->setValue(3,3,0);
    auto Mat4 = *Mat1 + *Mat2;
    ASSERT_EQ(Mat4.getValue(1,1),6);
    ASSERT_EQ(Mat4.getValue(1,3),5);
    ASSERT_THROW(*Mat1+*Mat3,std::logic_error);
}

TEST(MatrixTemplate,OperatorPlusEqual){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,5);
    Mat1->setValue(1,2,3);
    Mat1->setValue(1,3,2);
    Mat1->setValue(2,2,8);
    Mat1->setValue(3,1,4);
    Mat1->setValue(3,2,4);
    Mat1->setValue(3,3,7);
    auto Mat2 = intFactory->createMatrixTemplate(3,3);
    auto Mat3 = intFactory->createMatrixTemplate(2,2);
    Mat2->setValue(1,1,1);
    Mat2->setValue(1,2,2);
    Mat2->setValue(1,3,3);
    Mat2->setValue(2,2,5);
    Mat2->setValue(3,1,8);
    Mat2->setValue(3,2,4);
    Mat2->setValue(3,3,0);
    *Mat1 += *Mat2;
    ASSERT_EQ(Mat1->getValue(1,1),6);
    ASSERT_EQ(Mat1->getValue(1,3),5);
    ASSERT_THROW(*Mat1+=*Mat3,std::logic_error);
}

TEST(MatrixTemplate,OperatorEquality){
    MatrixFactory<float>* floatFactory;
    auto Mat1 = floatFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,2.3);
    Mat1->setValue(1,2,5.6);
    Mat1->setValue(1,3,3.1);
    Mat1->setValue(2,1,7.4);
    Mat1->setValue(2,2,8.9);
    Mat1->setValue(2,3,9.9);
    Mat1->setValue(3,1,3.4);
    Mat1->setValue(3,2,1.1);
    Mat1->setValue(3,3,0.2);
    auto Mat2(*Mat1);
    ASSERT_TRUE(*Mat1==Mat2);
    Mat2.setValue(3,3,8.7);
    ASSERT_FALSE(*Mat1==Mat2);
}

TEST(MatrixTemplate,OperatorDisequality){
    MatrixFactory<float>* floatFactory;
    auto Mat1 = floatFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,2.3);
    Mat1->setValue(1,2,5.6);
    Mat1->setValue(1,3,3.1);
    Mat1->setValue(2,1,7.4);
    Mat1->setValue(2,2,8.9);
    Mat1->setValue(2,3,9.9);
    Mat1->setValue(3,1,3.4);
    Mat1->setValue(3,2,1.1);
    Mat1->setValue(3,3,0.2);
    auto Mat2(*Mat1);
    ASSERT_FALSE(*Mat1!=Mat2);
    Mat2.setValue(3,3,8.7);
    ASSERT_TRUE(*Mat1!=Mat2);
}

TEST(MatrixTemplate,OperatorMinus){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,5);
    Mat1->setValue(1,2,3);
    Mat1->setValue(1,3,2);
    Mat1->setValue(2,2,8);
    Mat1->setValue(3,1,4);
    Mat1->setValue(3,2,4);
    Mat1->setValue(3,3,7);
    auto Mat2 = intFactory->createMatrixTemplate(3,3);
    auto Mat3 = intFactory->createMatrixTemplate(2,2);
    Mat2->setValue(1,1,1);
    Mat2->setValue(1,2,2);
    Mat2->setValue(1,3,3);
    Mat2->setValue(2,2,5);
    Mat2->setValue(3,1,8);
    Mat2->setValue(3,2,4);
    Mat2->setValue(3,3,0);
    auto Mat4 = *Mat1 - *Mat2;
    ASSERT_EQ(Mat4.getValue(1,1),4);
    ASSERT_EQ(Mat4.getValue(1,3),-1);
    ASSERT_THROW(*Mat1+*Mat3,std::logic_error);
}

TEST(MatrixTemplate,OperatorMinusEqual){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,5);
    Mat1->setValue(1,2,3);
    Mat1->setValue(1,3,2);
    Mat1->setValue(2,2,8);
    Mat1->setValue(3,1,4);
    Mat1->setValue(3,2,4);
    Mat1->setValue(3,3,7);
    auto Mat2 = intFactory->createMatrixTemplate(3,3);
    auto Mat3 = intFactory->createMatrixTemplate(2,2);
    Mat2->setValue(1,1,1);
    Mat2->setValue(1,2,2);
    Mat2->setValue(1,3,3);
    Mat2->setValue(2,2,5);
    Mat2->setValue(3,1,8);
    Mat2->setValue(3,2,4);
    Mat2->setValue(3,3,0);
    *Mat1 -= *Mat2;
    ASSERT_EQ(Mat1->getValue(1,1),4);
    ASSERT_EQ(Mat1->getValue(1,3),-1);
    ASSERT_THROW(*Mat1+=*Mat3,std::logic_error);
}

TEST(MatrixTemplate,OperatorProductMatrix){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,5);
    Mat1->setValue(1,2,3);
    Mat1->setValue(1,3,2);
    Mat1->setValue(2,2,8);
    Mat1->setValue(3,1,4);
    Mat1->setValue(3,2,4);
    Mat1->setValue(3,3,7);
    auto Mat2 = intFactory->createMatrixTemplate(3,3);
    auto Mat3 = intFactory->createMatrixTemplate(2,2);
    Mat2->setValue(1,1,1);
    Mat2->setValue(1,2,2);
    Mat2->setValue(1,3,3);
    Mat2->setValue(2,2,5);
    Mat2->setValue(3,1,8);
    Mat2->setValue(3,2,4);
    Mat2->setValue(3,3,0);
    auto Mat4 = *Mat1 * *Mat2;
    ASSERT_EQ(Mat4.getRows(),3);
    ASSERT_EQ(Mat4.getColumns(),3);
    ASSERT_EQ(Mat4.getValue(1,1),21);
    ASSERT_EQ(Mat4.getValue(1,3),15);
    ASSERT_THROW(*Mat1 * *Mat3,std::logic_error);
}

TEST(MatrixTemplate,OperatorProductNumber){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(2,3);
    Mat1->setValue(1,1,2);
    Mat1->setValue(1,2,5);
    Mat1->setValue(1,3,4);
    Mat1->setValue(2,1,7);
    Mat1->setValue(2,2,9);
    Mat1->setValue(2,3,1);
    auto Mat2 = (*Mat1)*3;
    ASSERT_EQ(6,Mat2.getValue(1,1));
    ASSERT_EQ(15,Mat2.getValue(1,2));
    ASSERT_EQ(12,Mat2.getValue(1,3));
}

TEST(MatrixTemplate,ElMult){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,5);
    Mat1->setValue(1,2,3);
    Mat1->setValue(1,3,2);
    Mat1->setValue(2,2,8);
    Mat1->setValue(3,1,4);
    Mat1->setValue(3,2,4);
    Mat1->setValue(3,3,7);
    auto Mat2 = intFactory->createMatrixTemplate(3,3);
    auto Mat3 = intFactory->createMatrixTemplate(2,2);
    Mat2->setValue(1,1,1);
    Mat2->setValue(1,2,2);
    Mat2->setValue(1,3,3);
    Mat2->setValue(2,2,5);
    Mat2->setValue(3,1,8);
    Mat2->setValue(3,2,4);
    Mat2->setValue(3,3,0);
    auto Mat4 = Mat1->elMult(*Mat2);
    ASSERT_EQ(Mat4.getRows(),3);
    ASSERT_EQ(Mat4.getColumns(),3);
    ASSERT_EQ(Mat4.getValue(1,1),5);
    ASSERT_EQ(Mat4.getValue(1,3),6);
    ASSERT_THROW(Mat1->elMult(*Mat3),std::logic_error);
}

TEST(MatrixTemplate,OperatorPower){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,5);
    Mat1->setValue(1,2,3);
    Mat1->setValue(1,3,2);
    Mat1->setValue(2,2,8);
    Mat1->setValue(3,1,4);
    Mat1->setValue(3,2,4);
    Mat1->setValue(3,3,7);
    auto Mat2 = (*Mat1)^2;
    ASSERT_EQ(Mat2.getRows(),3);
    ASSERT_EQ(Mat2.getColumns(),3);
    ASSERT_EQ(Mat2.getValue(1,1),33);
    ASSERT_EQ(Mat2.getValue(1,3),24);
    ASSERT_THROW((*Mat1)^(-5),std::logic_error);
}

TEST(MatrixTemplate,ElPow){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,5);
    Mat1->setValue(1,2,3);
    Mat1->setValue(1,3,2);
    Mat1->setValue(2,2,8);
    Mat1->setValue(3,1,4);
    Mat1->setValue(3,2,4);
    Mat1->setValue(3,3,7);
    auto Mat2 = (*Mat1).elPow(2);
    ASSERT_EQ(Mat2.getRows(),3);
    ASSERT_EQ(Mat2.getColumns(),3);
    ASSERT_EQ(Mat2.getValue(1,1),25);
    ASSERT_EQ(Mat2.getValue(1,3),4);
    Mat2 = (*Mat1).elPow(0);
    ASSERT_EQ(Mat2.getValue(1,1),1);
    ASSERT_EQ(Mat2.getValue(3,3),1);
    ASSERT_THROW((*Mat1).elPow(-1),std::logic_error);
}

TEST(MatrixTemplate,NormaInf){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(1,3);
    auto Mat2 = intFactory->createMatrixTemplate(3,1);
    Mat1->setValue(1,1,3);
    Mat1->setValue(1,2,6);
    Mat1->setValue(1,3,4);
    Mat2->setValue(1,1,2);
    Mat2->setValue(2,1,6);
    Mat2->setValue(3,1,8);
    ASSERT_EQ(6,Mat1->normainf());
    ASSERT_EQ(8,Mat2->normainf());
    auto Mat3 = intFactory->createMatrixTemplate(3,3);
    Mat3->setValue(1,1,4);
    Mat3->setValue(1,2,6);
    Mat3->setValue(1,3,7);
    Mat3->setValue(2,1,8);
    Mat3->setValue(2,2,-9);
    Mat3->setValue(2,3,-4);
    Mat3->setValue(3,1,-1);
    Mat3->setValue(3,3,5);
    ASSERT_EQ(21,Mat3->normainf());
}

TEST(MatrixTemplate,NormaUno){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(1,3);
    auto Mat2 = intFactory->createMatrixTemplate(3,1);
    Mat1->setValue(1,1,3);
    Mat1->setValue(1,2,6);
    Mat1->setValue(1,3,4);
    Mat2->setValue(1,1,2);
    Mat2->setValue(2,1,6);
    Mat2->setValue(3,1,8);
    ASSERT_EQ(13,Mat1->norma1());
    ASSERT_EQ(16,Mat2->norma1());
    auto Mat3 = intFactory->createMatrixTemplate(3,3);
    Mat3->setValue(1,1,4);
    Mat3->setValue(1,2,6);
    Mat3->setValue(1,3,7);
    Mat3->setValue(2,1,8);
    Mat3->setValue(2,2,-9);
    Mat3->setValue(2,3,-4);
    Mat3->setValue(3,1,-1);
    Mat3->setValue(3,3,5);
    ASSERT_EQ(16,Mat3->norma1());
}

TEST(MatrixTemplate,NormaDue){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(1,1,5);
    Mat1->setValue(1,2,3);
    Mat1->setValue(1,3,2);
    Mat1->setValue(2,2,8);
    Mat1->setValue(3,1,4);
    Mat1->setValue(3,2,4);
    Mat1->setValue(3,3,7);
    ASSERT_THROW(Mat1->norma2(),std::logic_error);
    auto Mat2 = intFactory->createMatrixTemplate(1,5);
    Mat2->setValue(1,1,2);
    Mat2->setValue(1,2,5);
    Mat2->setValue(1,3,7);
    Mat2->setValue(1,4,2);
    Mat2->setValue(1,5,6);
    auto norma2 = Mat2->norma2();
    ASSERT_DOUBLE_EQ(norma2,sqrt(118));
}
