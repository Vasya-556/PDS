#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-2/lab-2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            string expectedOutput = "=============\n|p|q|r|func |\n-------------\n|0|0|0|1    |\n-------------\n|0|0|1|1    |\n-------------\n|0|1|0|1    |\n-------------\n|0|1|1|1    |\n-------------\n|1|0|0|1    |\n-------------\n|1|0|1|0    |\n-------------\n|1|1|0|0    |\n-------------\n|1|1|1|1    |\n=============\n";

            // Redirect cout to a stringstream
            stringstream ss;
            streambuf* oldCout = cout.rdbuf(ss.rdbuf());

            // Call the function
            table();

            // Restore cout
            cout.rdbuf(oldCout);

            // Check the output
            string actualOutput = ss.str();
            Assert::AreEqual(expectedOutput, actualOutput);
		}
	};
}
