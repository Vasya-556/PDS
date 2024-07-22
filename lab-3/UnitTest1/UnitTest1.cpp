#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-3/lab-3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            std::stringstream expected;
            expected << "Result = 6720" << std::endl;

            std::stringstream actual;
            std::streambuf* coutBuffer = std::cout.rdbuf();
            std::cout.rdbuf(actual.rdbuf());

            task1();
            std::cout.rdbuf(coutBuffer);

            Assert::AreEqual(expected.str(), actual.str());

		}
		TEST_METHOD(TestMethod2)
		{
			std::stringstream input;
			input << "1";
			std::streambuf* cinBuffer = std::cin.rdbuf();
			std::cin.rdbuf(input.rdbuf());

			std::stringstream expected;
			expected << "Enter variant: Stirling numbers:" << std::endl;
			expected << "1 " << std::endl;
			expected << "1 1 " << std::endl;
			expected << "1 3 1 " << std::endl;
			expected << "1 7 6 1 " << std::endl;
			expected << "1 15 25 10 1 " << std::endl;
			expected << "1 31 90 65 15 1 " << std::endl;
			expected << "Bell numbers:" << std::endl;
			expected << "1 2 5 15 52 203 " << std::endl;

			/*
			Enter variant: Stirling numbers:
1 
1 1 
1 3 1 
1 7 6 1 
1 15 25 10 1 
1 31 90 65 15 1 
Bell numbers:
1 2 5 15 52 203 
			*/

			std::stringstream actual;
			std::streambuf* coutBuffer = std::cout.rdbuf();
			std::cout.rdbuf(actual.rdbuf());


			task2();

			std::cout.rdbuf(coutBuffer);

			std::cin.rdbuf(cinBuffer);

			Assert::AreEqual(expected.str(), actual.str());

		}
	};
}
