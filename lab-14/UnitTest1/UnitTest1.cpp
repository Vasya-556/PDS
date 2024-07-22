#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-14/lab-14.cpp"

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
			
			bool a;
			a = isIrreflexive();
			Assert::AreEqual(a, true);
		}
		TEST_METHOD(TestMethod2)
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

			bool a;
			a = isSymmetric();
			Assert::AreEqual(a, true);
		}
	};
}
