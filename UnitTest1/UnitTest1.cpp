#include "pch.h"
#include "CppUnitTest.h"
#include "Test_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        /// returnDistance
        TEST_METHOD(Test_returnDistance01)
        {
            // input
            const int loc1[] = { 3, 4 };
            const int loc2[] = { 3, 4 };
            double minDest = 5;
            // function test
            double result = returnDistance(loc1, loc2, &minDest);
            // output
            Assert::AreEqual(0.0, result);
        }

        TEST_METHOD(Test_returnDistance02)
        {
            // input
            const int loc1[] = { 2, 4 };
            const int loc2[] = { 8, 4 };
            double minDest = 5;
            // function test
            double result = returnDistance(loc1, loc2, &minDest);
            // output
            Assert::AreEqual(6.0, result);
        }

        TEST_METHOD(Test_returnDistance03)
        {
            // input
            const int loc1[] = { 5, 3 };
            const int loc2[] = { 5, 9 };
            double minDest = 8;
            // function test
            double result = returnDistance(loc1, loc2, &minDest);
            // output
            Assert::AreEqual(6.0, result);
        }

        TEST_METHOD(Test_returnDistance04)
        {
            // input
            const int loc1[] = { 2, 2 };
            const int loc2[] = { 5, 6 };
            double minDest = 10;
            // function test
            double result = returnDistance(loc1, loc2, &minDest);
            // output
            Assert::AreEqual(5.0, result);
        }

        TEST_METHOD(Test_returnDistance05)
        {
            // input
            const int loc1[] = { 0, 0 };
            const int loc2[] = { 10, 10 };
            double minDest = 15;
            // function test
            double result = returnDistance(loc1, loc2, &minDest);
            // output
            Assert::AreEqual(14.1421356237, 14.1421356237, result);
        }


        TEST_METHOD(Test_returnDistance06)
        {
            // input
            const int loc1_case6[] = { 0, 0 };
            const int loc2_case6[] = { 3, 4 };
            double minDest_case6 = 5;
            // function test
            double result_case6 = returnDistance(loc1_case6, loc2_case6, &minDest_case6);
            // output
            Assert::AreEqual(5.0, minDest_case6);
        }


        //null pointer
        TEST_METHOD(Test_returnDistance07)
        {
            // input
            const int loc1_case7[] = { 0, 0 };
            const int loc2_case7[] = { 10, 10 };
            double* minDest_case7 = nullptr;
            // function test
            double result_case7 = returnDistance(loc1_case7, loc2_case7, minDest_case7);
            // output
            Assert::AreEqual(-1.0, result_case7); // Assuming -1 is an indicator of failure
        }

        /// checkEmpty
        TEST_METHOD(Test_checkEmpty08)
        {
            // input
            double weightLeft = 1000.0;
            int volumeLeft = 5;
            double weight = 500.0;
            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(1, result);
        }

        TEST_METHOD(Test_checkEmpty09)
        {
            // input
            double weightLeft = 500.0;
            int volumeLeft = 10;
            double weight = 1000.0;
            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(Test_checkEmpty10)
        {
            // input
            double weightLeft = 1000.0;
            int volumeLeft = 0;
            double weight = 500.0;
            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(Test_checkEmpty11)
        {
            // input
            double weightLeft = 1000.0;
            int volumeLeft = 5;
            double weight = 1000.0;
            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(1, result);
        }

        TEST_METHOD(Test_checkEmpty12)
        {
            // input
            double weightLeft = 500.0;
            int volumeLeft = 0;
            double weight = 1000.0;
            // function test
            int result = checkEmpty(weight, weightLeft, volumeLeft);
            // output
            Assert::AreEqual(0, result);
        }

        //negative value
        TEST_METHOD(Test_checkEmpty13)
        {
            // input
            double weightLeft_case6 = 1000.0;
            int volumeLeft_case6 = 5;
            double weight_case6 = -200.0;
            // function test
            int result_case6 = checkEmpty(weight_case6, weightLeft_case6, volumeLeft_case6);
            // output
            Assert::AreEqual(0, result_case6);
        }

        //negative value
        TEST_METHOD(Test_checkEmpty14)
        {
            // input
            double weightLeft_case7 = 1000.0;
            int volumeLeft_case7 = -2;
            double weight_case7 = 500.0;
            // function test
            int result_case7 = checkEmpty(weight_case7, weightLeft_case7, volumeLeft_case7);
            // output
            Assert::AreEqual(0, result_case7);
        }

        /// checkSize
        TEST_METHOD(Test_checkSize15)
        {
            // function test
            int result_case1 = checkSize(QUARTER_SIZE);
            // output
            Assert::AreEqual(1, result_case1);
        }

        TEST_METHOD(Test_checkSize16)
        {
            // function test
            int result_case2 = checkSize(HALF_SIZE);
            // output
            Assert::AreEqual(1, result_case2);
        }

        TEST_METHOD(Test_checkSize17)
        {
            // function test
            int result_case3 = checkSize(FULL_SIZE);
            // output
            Assert::AreEqual(1, result_case3);
        }

        TEST_METHOD(Test_checkSize18)
        {
            // function test
            int result_case4 = checkSize(0.75);
            // output
            Assert::AreEqual(0, result_case4);
        }

        //value greater than FULL_SIZE
        TEST_METHOD(Test_checkSize19)
        {
            // function test
            int result_case6 = checkSize(1.5);
            // output
            Assert::AreEqual(0, result_case6);
        }

        //negative value
        TEST_METHOD(Test_checkSize20)
        {
            // function test
            int result_case7 = checkSize(-0.5);
            // output
            Assert::AreEqual(0, result_case7);
        }

        /// validDestination

        TEST_METHOD(Test_validDestination21)
        {
            // input
            int row = 10;
            const char* column = "C";

            // function test
            int result = validDestination(row, column);

            // output
            Assert::AreEqual(1, result);
        }

        TEST_METHOD(Test_validDestination22)
        {
            // input
            int row = 0;
            char column = 'A';
            // function test
            int result = validDestination(row, &column);
            // output
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(Test_validDestination23)
        {
            // input
            int row = 30;
            char column = 'B';
            // function test
            int result = validDestination(row, &column);
            // output
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(Test_validDestination24)
        {
            // input
            int row = 15;
            char column = '@';
            // function test
            int result = validDestination(row, &column);
            // output
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(Test_validDestination25)
        {
            // input
            int row = 20;
            char column = 'Z';
            // function test
            int result = validDestination(row, &column);
            // output
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(Test_validDestination26)
        {
            // input
            int row = 1;
            const char* column = "A"; // A valid column character
            // function test
            int result = validDestination(row, column);
            // output
            Assert::AreEqual(1, result);
        }

        // Invalid row (negative value)
        TEST_METHOD(Test_validDestination27)
        {
            // input
            int row = -1;
            char column = 'B'; // A valid column character
            // function test
            int result = validDestination(row, &column);
            // output
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(Test_validDestination28)
        {
            // input
            int row = 1;
            const char* column = "a";
            // function test
            int result = validDestination(row, column);
            // output
            Assert::AreEqual(1, result);
        }

        TEST_METHOD(Test_validDestination29)
        {
            // input
            int row = 1;
            const char* column = "AB";
            // function test
            int result = validDestination(row, column);
            // output
            Assert::AreEqual(0, result);
        }
       
    };
}
