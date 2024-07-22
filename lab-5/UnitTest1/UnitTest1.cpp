#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-5/lab-5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			stringstream expected;
			expected << "a1q	a1w	a1e	a2q	a2w	a2e	b1q	b1w	b1e	b2q	b2w	b2e	c1q	c1w	c1e	c2q	c2w	c2e	" << endl;

			stringstream actual;
			streambuf* coutBuffer = cout.rdbuf();
			cout.rdbuf(actual.rdbuf());

			task1();

			cout.rdbuf(coutBuffer);

			Assert::AreEqual(expected.str(), actual.str());
		}

		TEST_METHOD(TestMethod2)
		{
			istringstream input("3\n2\n2\nabc\nab\nbc\n");
			cin.rdbuf(input.rdbuf());

			ostringstream output;
			output << "Enter n: Enter ka: Enter kb: Enter U: Enter A: Enter B: U:             abc\n";
			output << "A:             110	ab\n";
			output << "B:             000	\n";
			output << "notA:          001	c\n";
			output << "AandB:         000	\n";
			output << "AorB:          110	ab\n";
			output << "AdifferenceB:  110	ab\n";
			output << "AxorB:         110	ab\n";

			ostringstream task2_output;
			streambuf* cout_backup = cout.rdbuf();
			cout.rdbuf(task2_output.rdbuf());

			task2();

			cout.rdbuf(cout_backup);

			Assert::AreEqual(output.str(), task2_output.str());

		}
	};
}
