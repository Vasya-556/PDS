#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-7/lab-7.cpp"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1, Degree)
		{
            std::string fname = "graph_test.txt";
            std::ofstream file(fname);
            file << "5 5\n";
            file << "1 2\n";
            file << "1 3\n";
            file << "2 4\n";
            file << "3 5\n";
            file << "4 5\n";
            file.close();

            initGraph(fname);

            std::string expected_output = "| V | in-degree | out-degree |\n";
            expected_output += "| V1|          2|           2|\n";
            expected_output += "| V2|          1|           1|\n";
            expected_output += "| V3|          1|           1|\n";
            expected_output += "| V4|          1|           1|\n";
            expected_output += "| V5|          0|           0|\n";

            Assert::AreEqual(Degree(), expected_output);
		}
        TEST_METHOD(TestMethod2, Isolated){
            std::string fname = "graph_test.txt";
            std::ofstream file(fname);
            file << "5 5\n";
            file << "1 2\n";
            file << "1 3\n";
            file << "2 4\n";
            file << "3 5\n";
            file << "4 5\n";
            file.close();

            initGraph(fname);

            std::string expected_output = "| Isolated vertices | Hanging vertices |\n";
            expected_output += "| v0                |               v0 |\n";
            expected_output += "| v1                |               v1 |\n";
            expected_output += "| v2                |               v2 |\n";
            expected_output += "| v3                |               v3 |\n";
            expected_output += "| v4                |               v4 |\n";

            Assert::AreEqual(isolated(), expected_output);
        }

	};
}
