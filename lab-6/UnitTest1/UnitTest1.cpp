#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-6/lab-6.cpp"
#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
        TEST_METHOD(Testmethod) {
			
			stringstream expected;
			expected << "| v\\v | v 1| v 2| v 3| v 4| v 5| v 6| v 7| v 8| v 9| v10|" << endl;
			expected << "| v 1 |  0 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  1 |" << endl;
			expected << "| v 2 |  0 |  1 |  1 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |" << endl;
			expected << "| v 3 |  0 |  1 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |" << endl;
			expected << "| v 4 |  0 |  0 |  0 |  0 |  1 |  0 |  1 |  1 |  0 |  0 |" << endl;
			expected << "| v 5 |  1 |  1 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |" << endl;
			expected << "| v 6 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |" << endl;
			expected << "| v 7 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |" << endl;
			expected << "| v 8 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  1 |" << endl;
			expected << "| v 9 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |" << endl;
			expected << "| v10 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |  0 |" << endl;

			stringstream actual;
			streambuf* coutBuffer = cout.rdbuf();
			cout.rdbuf(actual.rdbuf());

            char fname[] = "graph_01_1.txt"; 
            ifstream input(fname);

            string line;
            getline(input, line);
            if (!line.empty()) {
                istringstream iss(line);
                iss >> vertices >> edges;
                incidence = new int* [vertices];
                adjacency = new int* [vertices];
                for (int i = 0; i < vertices; i++) {
                    incidence[i] = new int[edges];
                    adjacency[i] = new int[vertices];
                }
            }
            else {
                cout << "Empty input file" << endl;
                return;
            }

            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    adjacency[i][j] = 0;
                }
            }

            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < edges; j++) {
                    incidence[i][j] = 0;
                }
            }

            int lineNumber = 0;
            while (getline(input, line)) {
                makeIncidenceMatrix(line, lineNumber);
                makeAdjacencyMatrix(line);
                lineNumber++;
            }

            input.close();


			adjacencyMatrixToString();

			cout.rdbuf(coutBuffer);

			Assert::AreEqual(expected.str(), adjacencyMatrixToString());
        }
	};
}