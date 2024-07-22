#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-8/lab-8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string fname = "graph_test.txt";
			ofstream file(fname);
			file << "10 21\n";
			file << "1 5\n";
			file << "5 1\n";
			file << "1 10\n";
			file << "10 1\n";
			file << "2 2\n";
			file << "4 5\n";
			file << "5 4\n";
			file << "4 7\n";
			file << "7 4\n";
			file << "4 8\n";
			file << "8 4\n";
			file << "8 10\n";
			file << "10 8\n";
			file << "2 5\n";
			file << "5 2\n";
			file << "2 3\n";
			file << "3 2\n";
			file << "3 6\n";
			file << "6 3\n";
			file << "6 9\n";
			file << "9 6\n";
			file.close();
	
			initGraph(fname);
			stringstream expected;
			expected << "| vertex | DFS number | stack " << endl;
			expected << "| v4    | 1          | 4" << endl;
			expected << "| v5    | 2          | 4 5 " << endl;
			expected << "| v1    | 3          | 4 5 1 " << endl;
			expected << "| v10    | 4          | 4 5 1 10 " << endl;
			expected << "| v8    | 5          | 4 5 1 10 8 " << endl;
			expected << "| v2    | 6          | 4 5 2 " << endl;
			expected << "| v3    | 7          | 4 5 2 3 " << endl;
			expected << "| v6    | 8          | 4 5 2 3 6 " << endl;
			expected << "| v9    | 9          | 4 5 2 3 6 9 " << endl;
			expected << "| v7    | 10          | 4 7 " << endl;

			stringstream actual;
			streambuf* coutBuffer = cout.rdbuf();
			cout.rdbuf(actual.rdbuf());

			DFS(4);

			cout.rdbuf(coutBuffer);

			Assert::AreEqual(expected.str(), actual.str());
		}
	};
}
