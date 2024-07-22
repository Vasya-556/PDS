#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-4/lab-4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			stringstream input;
			input << "3\n";
			streambuf* cinBuffer = cin.rdbuf();
			cin.rdbuf(input.rdbuf());
			stringstream expected;
			
			expected << "Enter n: ";
			expected << "123" << endl;
			expected << "132" << endl;
			expected << "213" << endl;
			expected << "231" << endl;
			expected << "312" << endl;
			expected << "321" << endl;

			stringstream actual;
			streambuf* coutBuffer = cout.rdbuf();
			cout.rdbuf(actual.rdbuf());

			task1();

			cout.rdbuf(coutBuffer);

			cin.rdbuf(cinBuffer);

			Assert::AreEqual(expected.str(), actual.str());
		}

		TEST_METHOD(TestMethod2)
		{
			stringstream input;
			input << "5\n4\n";
			streambuf* cinBuffer = cin.rdbuf();
			cin.rdbuf(input.rdbuf());
			stringstream expected;

			expected << "Enter n: ";
			expected << "Enter r(r<=n): ";
			expected << "0123" << endl;
			expected << "0124" << endl;
			expected << "0134" << endl;
			expected << "0234" << endl;
			expected << "1234" << endl;
			
			stringstream actual;
			streambuf* coutBuffer = cout.rdbuf();
			cout.rdbuf(actual.rdbuf());

			task2();

			cout.rdbuf(coutBuffer);

			cin.rdbuf(cinBuffer);

			Assert::AreEqual(expected.str(), actual.str());
		}
	};
}
