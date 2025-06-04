#include "pch.h"
#include "CppUnitTest.H"
#include "../MATHS AND ALGORITHMS/Algorithms.h"
#include "../MATHS AND ALGORITHMS/DataStructures.h"
//#include "../MATHS AND ALGORITHMS/DATASTRUCTURES.H"
#include "../MATHS AND ALGORITHMS/Maths.h"
#include "../Maths and Algorithms/Matrix.h"
#include "../MATHS AND ALGORITHMS/Vector.h"

//#INCLUDE ""
//
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TESTS
{
	TEST_CLASS(ALGORITHMS)
	{
	public:

		TEST_METHOD(STACKPUSHPOPTEST)
		{
			// ARRANGE
			Stack<int>  STACK;
			//Stack<int> STACK;

			int DATATOPUSH = 5;

			// ACT
			STACK.Push(DATATOPUSH);
			int POPPEDDATA = STACK.Pop();

			// ASSERT
			Assert::AreEqual(5, POPPEDDATA, L"POP() DID NOT RETURN THE EXPECTED VALUE");
		}

		TEST_METHOD(STACKPEEKTEST)
		{
			// ARRANGE
			Stack<int> STACK;
			int DATATOPUSH = 5;

			// ACT
			STACK.Push(DATATOPUSH);
			int PEEKEDDATA = STACK.Peek();

			// ASSERT
			Assert::AreEqual(5, PEEKEDDATA, L"PEEK() DID NOT RETURN THE EXPECTED VALUE");
		}

		TEST_METHOD(STACKPUSHMULTIPLETEST)
		{
			// ARRANGE
			Stack<int> STACK;

			// ACT
			STACK.Push(1);
			STACK.Push(2);
			STACK.Push(3);

			// ASSERT
			Assert::AreEqual(3, int(STACK.Count), L"SIZE IS INCORRECT AFTER PUSHING MULTIPLE ELEMENTS");
		}

		TEST_METHOD(QUEUEPUSHPOPTEST)
		{
			// ARRANGE
			Queue<int> QUEUE;
			int DATATOPUSH = 5;

			// ACT
			QUEUE.Push(DATATOPUSH);
			int POPPEDDATA = QUEUE.Pop();

			// ASSERT
			Assert::AreEqual(5, POPPEDDATA, L"POP() DID NOT RETURN THE EXPECTED VALUE");
		}

		TEST_METHOD(QUEUEPEEKTEST)
		{
			// ARRANGE
			Queue<int> QUEUE;
			int DATATOPUSH = 5;

			// ACT
			QUEUE.Push(DATATOPUSH);
			QUEUE.Push(10);
			int PEEKEDDATA = QUEUE.Peek();

			// ASSERT
			Assert::AreEqual(5, PEEKEDDATA, L"PEEK() DID NOT RETURN THE EXPECTED VALUE");
		}

		TEST_METHOD(QUEUEPUSHMULTIPLETEST)
		{
			// ARRANGE
			Queue<int> QUEUE;

			// ACT
			QUEUE.Push(1);
			QUEUE.Push(2);
			QUEUE.Push(3);

			// ASSERT
			Assert::AreEqual(3, int(QUEUE.Count), L"SIZE IS INCORRECT AFTER PUSHING MULTIPLE ELEMENTS");
		}

		TEST_METHOD(QUEUEPUSHFULLTEST)
		{
			// ARRANGE
			Queue<int> QUEUE;

			// ACT
			QUEUE.Push(1);
			QUEUE.Push(2);
			QUEUE.Push(3);
			QUEUE.Push(4);
			QUEUE.Push(5);
			QUEUE.Push(6);
			QUEUE.Push(7);
			QUEUE.Push(8);
			QUEUE.Push(9);
			QUEUE.Push(10);
			QUEUE.Push(11);
			QUEUE.Push(12);
			QUEUE.Push(13);

			// ASSERT
			Assert::AreEqual(10, int(QUEUE.Count), L"SIZE IS INCORRECT AFTER PUSHING MULTIPLE ELEMENTS");
		}


		//TEST_METHOD(NODEINITIALIZATIONTEST)
		//{
		//	// ARRANGE
		//	INT TESTDATA = 5;

		//	// ACT
		//	NODE<INT>* NODE = NEW NODE<INT>();
		//	NODE->DATA = TESTDATA;

		//	// ASSERT
		//	ASSERT::AREEQUAL(TESTDATA, NODE->DATA, L"NODE DATA IS NOT INITIALIZED CORRECTLY");
		//	ASSERT::ISNULL(NODE->LEFT, L"LEFT CHILD POINTER IS NOT INITIALIZED CORRECTLY");
		//	ASSERT::ISNULL(NODE->RIGHT, L"RIGHT CHILD POINTER IS NOT INITIALIZED CORRECTLY");

		//	// CLEAN UP
		//	DELETE NODE;
		//}

		//TEST_METHOD(MINHEAPADDTEST)
		//{
		//	// ARRANGE
		//	MINIMUMBINARYHEAP<INT> HEAP;
		//	INT DATATOADD = 5;

		//	// ACT
		//	HEAP.ADD(DATATOADD);

		//	// ASSERT
		//	ASSERT::AREEQUAL(DATATOADD, HEAP.ROOT->DATA, L"ROOT DATA IS NOT INITIALIZED CORRECTLY AFTER ADDING");
		//}

		//TEST_METHOD(MINHEAPREMOVETEST)
		//{
		//	// ARRANGE
		//	MINIMUMBINARYHEAP<INT> HEAP;
		//	HEAP.ADD(5);
		//	HEAP.ADD(10);
		//	HEAP.ADD(7);

		//	// ACT
		//	INT REMOVEDDATA = HEAP.REMOVE();

		//	// ASSERT
		//	ASSERT::AREEQUAL(5, REMOVEDDATA, L"REMOVE() DID NOT RETURN THE EXPECTED VALUE");
		//	ASSERT::AREEQUAL(7, HEAP.ROOT->DATA, L"ROOT DATA IS NOT UPDATED CORRECTLY AFTER REMOVAL");
		//}

	};


	TEST_CLASS(DATASTRUCTURES)
	{
	public:

		TEST_METHOD(BUBBLESORTTEST)
		{
			// ARRANGE
			int testData[] = { 5, 3, 7, 1, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);

			// ACT
			int* sortedData = Algorithms::BubbleSort(testData, size);

			// ASSERT
			Assert::AreEqual(1, sortedData[0], L"a. BUBBLESORT DID NOT SORT THE ARRAY CORRECTLY");
			Assert::AreEqual(9, sortedData[size - 1], L"b. BUBBLESORT DID NOT SORT THE ARRAY CORRECTLY");

			// CLEAN UP
		}

		//	// SIMILAR TESTS FOR OTHER SORTING FUNCTIONS: INSERTIONSORT, SELECTIONSORT, HEAPSORT, MERGESORT, QUICKSORT, BINSORT

		//	TEST_METHOD(LINEARSEARCHTEST)
		//	{
		//		// ARRANGE
		//		INT TESTDATA[] = { 5, 3, 7, 1, 9 };
		//		SIZE_T SIZE = SIZEOF(TESTDATA) / SIZEOF(TESTDATA[0]);
		//		INT TARGET = 5;
		//		// ACT
		//		INT* RESULT = ::ALGORITHMS::LINIERSEARCH(TESTDATA, SIZE, TARGET);

		//		// ASSERT
		//		// WRITE ASSERTIONS TO VERIFY THE RESULT

		//		// CLEAN UP
		//		DELETE[] RESULT;
		//	}

		//	TEST_METHOD(BINARYSEARCHTEST)
		//	{
		//		// ARRANGE
		//		INT TESTDATA[] = { 1, 3, 5, 7, 9 };
		//		SIZE_T SIZE = SIZEOF(TESTDATA) / SIZEOF(TESTDATA[0]);
		//		INT TARGET = 5;

		//		// ACT
		//		INT* RESULT = ::ALGORITHMS::BINARYSEARCH(TESTDATA, SIZE, TARGET);

		//		// ASSERT
		//		// WRITE ASSERTIONS TO VERIFY THE RESULT

		//		// CLEAN UP
		//		DELETE[] RESULT;
		//	}
		TEST_METHOD(INSERTIONSORTTEST)
		{
			{
				// ARRANGE
				int testData[] = { 5, 3, 7, 1, 9 };
				size_t size = sizeof(testData) / sizeof(testData[0]);

				// ACT
				int* sortedData = Algorithms::InsertionSort(testData, size);

				// ASSERT
				Assert::AreEqual(1, sortedData[0], L"INSERTIONSORT DID NOT SORT THE ARRAY CORRECTLY");
				Assert::AreEqual(9, sortedData[size - 1], L"INSERTIONSORT DID NOT SORT THE ARRAY CORRECTLY");

				// CLEAN UP
			}
		}
	};
	//	TEST_METHOD(SELECTIONSORTTEST)
	//	{
	//		// ARRANGE
	//		INT TESTDATA[] = { 5, 3, 7, 1, 9 };
	//		SIZE_T SIZE = SIZEOF(TESTDATA) / SIZEOF(TESTDATA[0]);

	//		// ACT
	//		INT* SORTEDDATA = ::ALGORITHMS::SELECTIONSORT(TESTDATA, SIZE);

	//		// ASSERT
	//		ASSERT::AREEQUAL(1, SORTEDDATA[0], L"SELECTIONSORT DID NOT SORT THE ARRAY CORRECTLY");
	//		ASSERT::AREEQUAL(9, SORTEDDATA[SIZE - 1], L"SELECTIONSORT DID NOT SORT THE ARRAY CORRECTLY");

	//		// CLEAN UP
	//		DELETE[] SORTEDDATA;
	//	}

	//	TEST_METHOD(HEAPSORTTEST)
	//	{
	//		// ARRANGE
	//		INT TESTDATA[] = { 5, 3, 7, 1, 9 };
	//		SIZE_T SIZE = SIZEOF(TESTDATA) / SIZEOF(TESTDATA[0]);

	//		// ACT
	//		INT* SORTEDDATA = ::ALGORITHMS::HEAPSORT(TESTDATA, SIZE);

	//		// ASSERT
	//		ASSERT::AREEQUAL(1, SORTEDDATA[0], L"HEAPSORT DID NOT SORT THE ARRAY CORRECTLY");
	//		ASSERT::AREEQUAL(9, SORTEDDATA[SIZE - 1], L"HEAPSORT DID NOT SORT THE ARRAY CORRECTLY");

	//		// CLEAN UP
	//		DELETE[] SORTEDDATA;
	//	}

	//	TEST_METHOD(MERGESORTTEST)
	//	{
	//		// ARRANGE
	//		INT TESTDATA[] = { 5, 3, 7, 1, 9 };
	//		SIZE_T SIZE = SIZEOF(TESTDATA) / SIZEOF(TESTDATA[0]);

	//		// ACT
	//		INT* SORTEDDATA = ::ALGORITHMS::MERGESORT(TESTDATA, SIZE);

	//		// ASSERT
	//		ASSERT::AREEQUAL(1, SORTEDDATA[0], L"MERGESORT DID NOT SORT THE ARRAY CORRECTLY");
	//		ASSERT::AREEQUAL(9, SORTEDDATA[SIZE - 1], L"MERGESORT DID NOT SORT THE ARRAY CORRECTLY");

	//		// CLEAN UP
	//		DELETE[] SORTEDDATA;
	//	}

	//	TEST_METHOD(QUICKSORTTEST)
	//	{
	//		// ARRANGE
	//		INT TESTDATA[] = { 5, 3, 7, 1, 9 };
	//		SIZE_T SIZE = SIZEOF(TESTDATA) / SIZEOF(TESTDATA[0]);

	//		// ACT
	//		INT* SORTEDDATA = ::ALGORITHMS::QUICKSORT(TESTDATA, SIZE);

	//		// ASSERT
	//		ASSERT::AREEQUAL(1, SORTEDDATA[0], L"QUICKSORT DID NOT SORT THE ARRAY CORRECTLY");
	//		ASSERT::AREEQUAL(9, SORTEDDATA[SIZE - 1], L"QUICKSORT DID NOT SORT THE ARRAY CORRECTLY");

	//		// CLEAN UP
	//		DELETE[] SORTEDDATA;
	//	}

	//	TEST_METHOD(BINSORTTEST)
	//	{
	//		// ARRANGE
	//		INT TESTDATA[] = { 5, 3, 7, 1, 9 };
	//		SIZE_T SIZE = SIZEOF(TESTDATA) / SIZEOF(TESTDATA[0]);

	//		// ACT
	//		INT* SORTEDDATA = ::ALGORITHMS::BINSORT(TESTDATA, SIZE);

	//		// ASSERT
	//		ASSERT::AREEQUAL(1, SORTEDDATA[0], L"BINSORT DID NOT SORT THE ARRAY CORRECTLY");
	//		ASSERT::AREEQUAL(9, SORTEDDATA[SIZE - 1], L"BINSORT DID NOT SORT THE ARRAY CORRECTLY");

	//		// CLEAN UP
	//		DELETE[] SORTEDDATA;
	//	}
	//};
	// 

	TEST_CLASS(MATHS)
	{
	public:

		TEST_METHOD(DEGTORADTEST)
		{
			// ARRANGE
			float DEGREES = 45.0F;

			// ACT
			float RADIANS = MathUtils::toRad(DEGREES);

			// ASSERT
			// VERIFY THAT THE CONVERSION FROM DEGREES TO RADIANS IS CORRECT
			Assert::AreEqual(0.785398163F, RADIANS, 0.0001F, L"CONVERSION FROM DEGREES TO RADIANS IS INCORRECT");
		}

		TEST_METHOD(RADTODEGTEST)
		{
			// ARRANGE
			float RADIANS = 0.785398163F;

			// ACT
			float DEGREES = MathUtils::toDeg(RADIANS);

			// ASSERT
			// VERIFY THAT THE CONVERSION FROM RADIANS TO DEGREES IS CORRECT
			Assert::AreEqual(45.0F, DEGREES, 0.0001F, L"CONVERSION FROM RADIANS TO DEGREES IS INCORRECT");
		}

		TEST_METHOD(PYTHAGORASTEST)
		{
			// ARRANGE
			float SIDEA = 3.0F;
			float SIDEB = 4.0F;

			// ACT
			float HYPOTENUSE = MathUtils::Pythagoras(SIDEA, SIDEB);

			// ASSERT
			// VERIFY THAT THE CALCULATION OF THE HYPOTENUSE IS CORRECT
			Assert::AreEqual(5.0f, HYPOTENUSE, 0.0001f, L"CALCULATION OF HYPOTENUSE IS INCORRECT");
		}

		TEST_METHOD(FINDSINTHETATEST)
		{
			// ARRANGE
			float oppositeSide = 3.0F;
			float hypotenuseSide = 5.0F;

			// ACT
			float sinTheta = MathUtils::FindSinTheta(oppositeSide, hypotenuseSide);

			// ASSERT
			// VERIFY THAT THE CALCULATION OF SINE THETA IS CORRECT
			Assert::AreEqual(0.6f, sinTheta, 0.0001f, L"CALCULATION OF SINE THETA IS INCORRECT");
		}

		TEST_METHOD(FINDCOSTHETATEST)
		{
			// ARRANGE
			float oppositeSide = 3.0F;
			float hypotenuseSide = 5.0F;

			// ACT
			float cosTheta = MathUtils::FindCosTheta(oppositeSide, hypotenuseSide);

			// ASSERT
			// VERIFY THAT THE CALCULATION OF COSINE THETA IS CORRECT
			Assert::AreEqual(0.8F, cosTheta, 0.0001F, L"CALCULATION OF COSINE THETA IS INCORRECT");
		}

		TEST_METHOD(FINDTANTHETATEST)
		{
			// ARRANGE
			float oppositeSide = 3.0F;
			float hypotenuseSide = 5.0F;

			// ACT
			float TANTHETA = MathUtils::FindTanTheta(oppositeSide, hypotenuseSide);

			// ASSERT
			// VERIFY THAT THE CALCULATION OF TANGENT THETA IS CORRECT
			Assert::AreEqual(0.75F, TANTHETA, 0.0001F, L"CALCULATION OF TANGENT THETA IS INCORRECT");
		}

		TEST_METHOD(FINDHYPTEST)
		{
			// ARRANGE
			float angleDegrees = 45.0f;
			float adjacentSide = 4.0f;

			// ACT
			float hypotenuse = MathUtils::FindHypotenuseFromDegrees(angleDegrees, adjacentSide);

			// ASSERT
			// VERIFY THAT THE CALCULATION OF HYPOTENUSE IS CORRECT
			Assert::AreEqual(5.65685F, hypotenuse, 0.0001F, L"CALCULATION OF HYPOTENUSE IS INCORRECT");
		}

		TEST_METHOD(FINDOPPTEST)
		{
			// ARRANGE
			float angleDegrees = 90.0f;
			float hypotenuseSide = 4.0f;

			// ACT
			float OPPOSITE = MathUtils::FindOppositeFromDegrees(angleDegrees, hypotenuseSide);

			// ASSERT
			// VERIFY THAT THE CALCULATION OF OPPOSITE SIDE IS CORRECT
			Assert::AreEqual(4.0f, OPPOSITE, 0.0001f, L"CALCULATION OF OPPOSITE SIDE IS INCORRECT");
		}

		TEST_METHOD(FINDADJTEST)
		{
			// ARRANGE
			float angleDegrees = 45.0F;
			float hypotenuseSide = 5.0F;

			// ACT
			float adjacentLength = MathUtils::FindAdjacentFromDegrees(angleDegrees, hypotenuseSide);

			// ASSERT
			// VERIFY THAT THE CALCULATION OF ADJACENT SIDE IS CORRECT
			Assert::AreEqual(3.5355f, adjacentLength, 0.0001f, L"CALCULATION OF ADJACENT SIDE IS INCORRECT");
		}
	};

	//TEST_CLASS(VECTORS)
	//{
	//PUBLIC:

	//	TEST_METHOD(CROSSPRODUCTTEST)
	//	{
	//		// ARRANGE
	//		VECTOR VECTORA(1.0, 2.0, 3.0);
	//		VECTOR VECTORB(4.0, 5.0, 6.0);
	//		VECTOR EXPECTEDCROSSPRODUCT(-3.0, 6.0, -3.0);

	//		// ACT
	//		VECTOR CROSSPRODUCT = VECTORA.CROSS(VECTORB);

	//		// ASSERT
	//		ASSERT::AREEQUAL(EXPECTEDCROSSPRODUCT.X, CROSSPRODUCT.X, L"X COMPONENT IS INCORRECT");
	//		ASSERT::AREEQUAL(EXPECTEDCROSSPRODUCT.Y, CROSSPRODUCT.Y, L"Y COMPONENT IS INCORRECT");
	//		ASSERT::AREEQUAL(EXPECTEDCROSSPRODUCT.Z, CROSSPRODUCT.Z, L"Z COMPONENT IS INCORRECT");
	//	}
	//	TEST_METHOD(MAGNITUDETEST)
	//	{
	//		// ARRANGE
	//		VECTOR VECTOR(3.0F, 4.0F, 0.0F); // A 3-4-5 RIGHT TRIANGLE
	//		FLOAT EXPECTEDMAGNITUDE = 5.0F;

	//		// ACT
	//		FLOAT MAGNITUDE = VECTOR.MAGNITUDE();

	//		// ASSERT
	//		ASSERT::AREEQUAL(EXPECTEDMAGNITUDE, MAGNITUDE, 0.0001F, L"MAGNITUDE IS INCORRECT");
	//	}
	//	TEST_METHOD(NORMALISETEST)
	//	{
	//		// ARRANGE
	//		VECTOR VECTOR(3.0F, 4.0F, 0.0F); // A VECTOR WITH MAGNITUDE 5
	//		VECTOR EXPECTEDNORMALIZEDVECTOR(0.6F, 0.8F, 0.0F); // NORMALIZED VECTOR WITH MAGNITUDE 1

	//		// ACT
	//		VECTOR.NORMALISE();

	//		// ASSERT
	//		ASSERT::AREEQUAL(EXPECTEDNORMALIZEDVECTOR.X, VECTOR.X, 0.0001F, L"X COMPONENT IS INCORRECT");
	//		ASSERT::AREEQUAL(EXPECTEDNORMALIZEDVECTOR.Y, VECTOR.Y, 0.0001F, L"Y COMPONENT IS INCORRECT");
	//		ASSERT::AREEQUAL(EXPECTEDNORMALIZEDVECTOR.Z, VECTOR.Z, 0.0001F, L"Z COMPONENT IS INCORRECT");
	//	}

	//	TEST_METHOD(SCALETEST)
	//	{
	//		// ARRANGE
	//		VECTOR VECTOR(3.0F, 4.0F, 2.0F); // A VECTOR WITH INITIAL COMPONENTS
	//		FLOAT SCALER = 2.0F; // SCALING FACTOR
	//		VECTOR EXPECTEDSCALEDVECTOR(6.0F, 8.0F, 4.0F); // EXPECTED SCALED VECTOR

	//		// ACT
	//		VECTOR.SCALE(SCALER);

	//		// ASSERT
	//		ASSERT::AREEQUAL(EXPECTEDSCALEDVECTOR.X, VECTOR.X, 0.0001F, L"X COMPONENT IS INCORRECT");
	//		ASSERT::AREEQUAL(EXPECTEDSCALEDVECTOR.Y, VECTOR.Y, 0.0001F, L"Y COMPONENT IS INCORRECT");
	//		ASSERT::AREEQUAL(EXPECTEDSCALEDVECTOR.Z, VECTOR.Z, 0.0001F, L"Z COMPONENT IS INCORRECT");
	//	}
	//	TEST_METHOD(DOTPRODUCTTEST)
	//	{
	//		// ARRANGE
	//		VECTOR VECTORA(1.0F, 2.0F, 3.0F);
	//		VECTOR VECTORB(4.0F, 5.0F, 6.0F);
	//		FLOAT EXPECTEDDOTPRODUCT = 32.0F; // EXPECTED DOT PRODUCT OF THE TWO VECTORS

	//		// ACT
	//		FLOAT DOTPRODUCT = VECTORA.DOT(VECTORB);

	//		// ASSERT
	//		ASSERT::AREEQUAL(EXPECTEDDOTPRODUCT, DOTPRODUCT, 0.0001F, L"DOT PRODUCT IS INCORRECT");
	//	}

};

TEST_CLASS(MATRICES)
{
public:

	TEST_METHOD(DETERMINATETEST)
	{
		// ARRANGE
		Matrix MATRIX;
		// FILL IN MATRIX WITH APPROPRIATE VALUES

		float sample[3][3] = {
			{3, 2, 1},
			{1, 0, 2},
			{4, 1, 3}
		};

		MATRIX.SetMatrix(sample);

		// EXPECTED DETERMINANT calculated manually
		float EXPECTEDDETERMINANT = 5.0f;

		// ACT
		float DET = MATRIX.Determinate();

		// ASSERT
		Assert::AreEqual(EXPECTEDDETERMINANT, DET, 0.0001F, L"DETERMINANT IS INCORRECT");
	}


	TEST_METHOD(ROTATEAROUNDXTEST)
	{
		// ARRANGE
		// create 3 matrices for the original; the rotation matrix and the result of the transformation
		Matrix originalMatrix;
		Matrix rotationMatrix;
		Matrix transformationMatrix;

		// FILL IN MATRIX WITH APPROPRIATE VALUES
		float ANGLE = 45.0F; // ANGLE to rortate

		originalMatrix.Data[0][0] = 1.0F;
		originalMatrix.Data[0][1] = 0.0F;
		originalMatrix.Data[0][2] = 1.0F;

		originalMatrix.Data[1][0] = 0.0F;
		originalMatrix.Data[1][1] = 1.0F;
		originalMatrix.Data[1][2] = 0.0F;

		originalMatrix.Data[2][0] = 1.0F;
		originalMatrix.Data[2][1] = 1.0F;
		originalMatrix.Data[2][2] = 1.0F;

		// ACT
		// set the rotation matrix transform
		rotationMatrix.SetRotateAroundX(ANGLE);

		// apply the rotation matrix to the original matrix by multiplying them together
		transformationMatrix = originalMatrix * rotationMatrix;

		// print the matrices to std out
		rotationMatrix.Print();
		transformationMatrix.Print();

		Assert::AreEqual(0.707f, transformationMatrix.Data[1][1], 0.001f, L"a. ROTATED ELEMENT IS INCORRECT");
		Assert::AreEqual(-0.707f, transformationMatrix.Data[1][2], 0.001f, L"b. ROTATED ELEMENT IS INCORRECT");

		Assert::AreEqual(1.41421f, transformationMatrix.Data[2][1], 0.001f, L"c. ROTATED ELEMENT IS INCORRECT");
		Assert::AreEqual(0.0f, transformationMatrix.Data[2][2], 0.001f, L"d. ROTATED ELEMENT IS INCORRECT");

	}

	TEST_METHOD(ROTATEAROUNDYTEST)
	{
		// ARRANGE
		// create 3 matrices for the original; the rotation matrix and the result of the transformation
		Matrix originalMatrix;;
		Matrix rotationMatrix;
		Matrix transformationMatrix;

		// FILL IN MATRIX WITH APPROPRIATE VALUES
		float ANGLE = 45.0F; // ANGLE to rortate

		originalMatrix.Data[0][0] = 1.0F;
		originalMatrix.Data[0][1] = 0.0F;
		originalMatrix.Data[0][2] = 1.0F;

		originalMatrix.Data[1][0] = 0.0F;
		originalMatrix.Data[1][1] = 1.0F;
		originalMatrix.Data[1][2] = 0.0F;

		originalMatrix.Data[2][0] = 1.0F;
		originalMatrix.Data[2][1] = 1.0F;
		originalMatrix.Data[2][2] = 1.0F;

		// ACT
		// set the rotation matrix transform
		rotationMatrix.SetRotateAroundY(ANGLE);

		// apply the rotation matrix to the original matrix by multiplying them together
		transformationMatrix = originalMatrix * rotationMatrix;

		// print the matrices to std out
		rotationMatrix.Print();
		transformationMatrix.Print();

		//Data[0][0] = cosA;  Data[0][1] = 0; Data[0][2] = sinA;
		//Data[1][0] = 0;     Data[1][1] = 1; Data[1][2] = 0;
		//Data[2][0] = -sinA; Data[2][1] = 0; Data[2][2] = cosA;

			//0.0000   0.0000   1.4142
			//0.0000   1.0000   0.0000
			//0.0000   1.0000   1.4142
		// ASSERT
		Assert::AreEqual(0.0f, transformationMatrix.Data[0][0], 0.001f, L"a. ROTATED ELEMENT IS INCORRECT");
		Assert::AreEqual(1.4142f, transformationMatrix.Data[0][2], 0.001f, L"b. ROTATED ELEMENT IS INCORRECT");

		Assert::AreEqual(0.0f, transformationMatrix.Data[2][0], 0.001f, L"c. ROTATED ELEMENT IS INCORRECT");
		Assert::AreEqual(1.4142f, transformationMatrix.Data[2][2], 0.001f, L"d. ROTATED ELEMENT IS INCORRECT");
	}

	TEST_METHOD(ROTATEAROUNDZTEST)
	{
		// ARRANGE
		// create 3 matrices for the original; the rotation matrix and the result of the transformation
		Matrix originalMatrix;
		Matrix rotationMatrix;
		Matrix transformationMatrix;

		// FILL IN MATRIX WITH APPROPRIATE VALUES
		float ANGLE = 45.0F; // ANGLE to rortate

		originalMatrix.Data[0][0] = 1.0F;
		originalMatrix.Data[0][1] = 0.0F;
		originalMatrix.Data[0][2] = 1.0F;

		originalMatrix.Data[1][0] = 0.0F;
		originalMatrix.Data[1][1] = 1.0F;
		originalMatrix.Data[1][2] = 0.0F;

		originalMatrix.Data[2][0] = 1.0F;
		originalMatrix.Data[2][1] = 1.0F;
		originalMatrix.Data[2][2] = 1.0F;

		// ACT
		// set the rotation matrix transform
		rotationMatrix.SetRotateAroundZ(ANGLE);

		// apply the rotation matrix to the original matrix by multiplying them together
		transformationMatrix = originalMatrix * rotationMatrix;

		// print the matrices to std out
		rotationMatrix.Print();
		transformationMatrix.Print();

		//0.7071 - 0.7071   1.0000
		//0.7071   0.7071   0.0000
		//1.4142   0.0000   1.0000

		Assert::AreEqual(transformationMatrix.Data[0][0], 0.7071f, 0.0001f, L"a. ROTATED ELEMENT IS INCORRECT");
		Assert::AreEqual(transformationMatrix.Data[0][1], -0.7071f, 0.0001f, L"b. ROTATED ELEMENT IS INCORRECT");

		Assert::AreEqual(transformationMatrix.Data[1][0], 0.7071f, 0.7071f, L"c. ROTATED ELEMENT IS INCORRECT");
		Assert::AreEqual(transformationMatrix.Data[1][1], 0.7071f, 0.0001f, L"d. ROTATED ELEMENT IS INCORRECT");
	}

	TEST_METHOD(TRANSLATETEST)
	{
		// ARRANGE
		Matrix MATRIX;
		MATRIX.Data[0][0] = 1.0f;
		MATRIX.Data[0][1] = 0.0f;
		MATRIX.Data[0][2] = 1.0f;

		MATRIX.Data[1][0] = 0.0f;
		MATRIX.Data[1][1] = 1.0f;
		MATRIX.Data[1][2] = 0.0f;

		MATRIX.Data[2][0] = 1.0f;
		MATRIX.Data[2][1] = 1.0f;
		MATRIX.Data[2][2] = 1.0f;

		MATRIX.Data[0][2] = 1.0f;
		MATRIX.Data[2][0] = 1.0f;
		MATRIX.Data[2][1] = 1.0f;


		Vector DELTA(1.0f, 2.0f, 3.0f); // transformation delta

		// ACT
		MATRIX.Translate(DELTA);

		// ASSERT
		Assert::AreEqual(MATRIX.Data[0][2], 2.0f, 0.0001f, L"a. TRANSLATE ELEMENT IS INCORRECT");
		Assert::AreEqual(MATRIX.Data[1][2], 2.0f, 0.0001f, L"b. TRANSLATE ELEMENT IS INCORRECT");
		Assert::AreEqual(MATRIX.Data[2][2], 4.0f, 0.0001f, L"c. TRANSLATE ELEMENT IS INCORRECT");

	}



	TEST_METHOD(MATRIXMULTIPLICATIONTEST)
	{
		// ARRANGE
		Matrix matrix1;
		// INITIALIZE MATRIX1
		float A[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
		matrix1.SetMatrix(A);

		Matrix matrix2;
		// INITIALIZE MATRIX2
		float B[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
		matrix2.SetMatrix(B);

		// ACT
		Matrix RESULT = matrix1 * matrix2;

		// ASSERT

		// first row of matrix A * first column of matrix B
		// i.e.  [1, 2, 3] * [9, 6, 3]
		// (1 × 9) + (2 × 6) + (3 × 3) = 9 + 12 + 9 = 30
		Assert::AreEqual(RESULT.Data[0][0], 30, 0.0001F, L"a. MULTIPLICATION OF MATRACES IS INCORRECT");
		Assert::AreEqual(RESULT.Data[0][1], 24, 0.0001F, L"b. MULTIPLICATION OF MATRACES IS INCORRECT");
		Assert::AreEqual(RESULT.Data[0][2], 18, 0.0001F, L"c. MULTIPLICATION OF MATRACES IS INCORRECT");
		Assert::AreEqual(RESULT.Data[1][0], 84, 0.0001F, L"d. MULTIPLICATION OF MATRACES IS INCORRECT");
		Assert::AreEqual(RESULT.Data[1][1], 69, 0.0001F, L"e. MULTIPLICATION OF MATRACES IS INCORRECT");
		Assert::AreEqual(RESULT.Data[1][2], 54, 0.0001F, L"f. MULTIPLICATION OF MATRACES IS INCORRECT");
		Assert::AreEqual(RESULT.Data[2][0], 138, 0.0001F, L"g. MULTIPLICATION OF MATRACES IS INCORRECT");
		Assert::AreEqual(RESULT.Data[2][1], 114, 0.0001F, L"h. MULTIPLICATION OF MATRACES IS INCORRECT");
		Assert::AreEqual(RESULT.Data[2][2], 90, 0.0001F, L"i. MULTIPLICATION OF MATRACES IS INCORRECT");
	}
};