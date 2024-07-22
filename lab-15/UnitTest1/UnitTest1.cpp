#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-15/lab-15.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			stringstream input;
			input << "4\n";
			streambuf* cinBuffer = cin.rdbuf();
			cin.rdbuf(input.rdbuf());
			stringstream expected;

			expected << "Enter n: . Q . . " << endl;
			expected << ". . . Q " << endl;
			expected << "Q . . . " << endl;
			expected << ". . Q . " << endl;
			expected << "" << endl;
			expected << ". . Q . " << endl;
			expected << "Q . . . " << endl;
			expected << ". . . Q " << endl;
			expected << ". Q . . " << endl;
			expected << "" << endl;
			expected << "Number of solutions: 2";

			stringstream actual;
			streambuf* coutBuffer = cout.rdbuf();
			cout.rdbuf(actual.rdbuf());

			main();

			cout.rdbuf(coutBuffer);

			cin.rdbuf(cinBuffer);

			Assert::AreEqual(expected.str(), actual.str());
		}
	};
}
