#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.4.1/Vector.h"
#include "../Lab_2.4.1/Vector.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest241
{
	TEST_CLASS(UnitTest241)
	{
	public:
		
		TEST_METHOD(TestNorm)
		{
			int arr[] = { 3,4 };
			Vector v(2, arr);
			Assert::AreEqual(5.0, v.norm(), 0.000001);
		}

		TEST_METHOD(TestScalarMultiplication)
		{
			int arr[] = { 1,2,3 };
			Vector v(3, arr);
			Vector result = v * 2;

			Assert::AreEqual(2, result[0]);
			Assert::AreEqual(4, result[1]);
			Assert::AreEqual(6, result[2]);
		}

		TEST_METHOD(TestEquality)
		{
			int arr1[] = { 10,20 };
			int arr2[] = { 10,20 };
			int arr3[] = { 10,21 };

			Vector v1(2, arr1);
			Vector v2(2, arr2);	
			Vector v3(2, arr3);

			Assert::IsTrue(v1 == v2);
			Assert::IsFalse(v1 == v3);
		}

		TEST_METHOD(TestComparisonByNorm)
		{
			int arr1[] = { 1,1 };
			int arr2[] = { 5,5 };

			Vector v1(2, arr1);
			Vector v2(2, arr2);

			Assert::IsTrue(v1 < v2);
			Assert::IsTrue(v2 > v1);
		}
	};
}
