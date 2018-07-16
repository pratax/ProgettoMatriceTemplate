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
    ASSERT_ANY_THROW(Mat1->selectRow(0));
    ASSERT_ANY_THROW(Mat1->selectRow(4));
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
    ASSERT_ANY_THROW(Mat1->selectColumn(0));
    ASSERT_ANY_THROW(Mat1->selectColumn(4));
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
    ASSERT_ANY_THROW(Mat1->getValue(0,0));
    ASSERT_ANY_THROW(Mat1->getValue(4,5));
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
    ASSERT_ANY_THROW(Mat1->setValue(5,2,10));
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



