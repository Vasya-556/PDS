#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-1/lab-1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::stringstream input;
			input << "1\n1\n";
			std::streambuf* cinBuffer = std::cin.rdbuf();
			std::cin.rdbuf(input.rdbuf());
			std::stringstream expected;
			expected << "1 - True 0 - False" << std::endl;
			expected << "Enter p: " << std::endl;
			expected << "1 - True 0 - False" << std::endl;
			expected << "Enter q: " << std::endl;
			expected << "AND" << std::endl;
			expected << "1" << std::endl;
			expected << std::endl;
			expected << "OR" << std::endl;
			expected << "1" << std::endl;
			expected << std::endl;
			expected << "XOR" << std::endl;
			expected << "0" << std::endl;
			expected << std::endl;
			expected << "p->q" << std::endl;
			expected << "1" << std::endl;
			expected << std::endl;
			expected << "q->p" << std::endl;
			expected << "1" << std::endl;
			expected << std::endl;
			expected << "p~q" << std::endl;
			expected << "1" << std::endl;
			expected << std::endl;

			std::stringstream actual;
			std::streambuf* coutBuffer = std::cout.rdbuf();
			std::cout.rdbuf(actual.rdbuf());

			funct1();

			std::cout.rdbuf(coutBuffer);

			std::cin.rdbuf(cinBuffer);

			Assert::AreEqual(expected.str(), actual.str());

		}
        TEST_METHOD(TestMethod2) {
            std::stringstream expected;
            expected << "a =      111100000" << std::endl;
            expected << "b =      101010011" << std::endl;
            expected << "a || b = 111110011" << std::endl;
            expected << "a && b = 101000000" << std::endl;
            expected << "a ^ b =  010110011" << std::endl;

            // Capture console output to a stringstream
            std::stringstream actual;
            std::streambuf* coutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(actual.rdbuf());

            funct2();

            // Restore console output
            std::cout.rdbuf(coutBuffer);

            // Compare expected and actual output
            Assert::AreEqual(expected.str(), actual.str());
        }
	};
}
