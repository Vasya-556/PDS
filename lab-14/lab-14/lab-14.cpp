﻿#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

int** incidence;
int** adjacency;
int vertices;
int edges;

void initGraph(string fname);
void makeIncidenceMatrix(string line, int lineNumber);
void makeAdjacencyMatrix(string line);
string adjacencyMatrixToString();
string incidenceMatrixToString();
void printMatrix(string matrix);
void saveMatrixToFile(string matrix, string filePath);
bool isIrreflexive();
bool isSymmetric();

int main()
{
    char fname[] = "graph_01_1.txt";
    initGraph(fname);
    string fileToSave;
    int menu;
    do
    {
        cout << "Chose operation:" << endl;
        cout << "[1] - Print incidence matrix into console" << endl;
        cout << "[2] - Print adjacency matrix into console" << endl;
        cout << "[3] - Save incidence matrix into file" << endl;
        cout << "[4] - Save adjacency matrix into file" << endl;
        cout << "[5] - Check if graph irreflexive" << endl;
        cout << "[6] - Check if graph symmetric" << endl;
        cout << "[0] - Exit" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            printMatrix(incidenceMatrixToString());
            break;

        case 2:
            printMatrix(adjacencyMatrixToString());
            break;

        case 3:
            cout << "Input file to save(without .txt): ";
            cin.ignore();
            getline(cin, fileToSave);
            fileToSave += ".txt";
            saveMatrixToFile(incidenceMatrixToString(), fileToSave);
            break;
        case 4:
            cout << "Input file to save(without .txt): ";
            cin.ignore();
            getline(cin, fileToSave);
            fileToSave += ".txt";
            saveMatrixToFile(adjacencyMatrixToString(), fileToSave);
            break;
        case 5:
            cout << (isIrreflexive ? "graph are irreflexive\n" : "graph are not irreflexive\n") << endl;
            break;
        case 6:
            cout << (isSymmetric ? "graph are symmetric\n" : "graph are not symmetric\n") << endl;
            break;
        default:
            break;
        }
    } while (menu != 0);
}

void initGraph(string fname) {
    ifstream input(fname);
    if (!input.is_open()) {
        cout << "Error opening file " << fname << endl;
        return;
    }

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
}

void makeIncidenceMatrix(string line, int lineNumber) {

    int from = stoi(line.substr(0, line.find(" ")));
    int to = stoi(line.substr(line.find(" ") + 1));

    if (from == to) {
        incidence[from - 1][lineNumber] = 2;
    }
    else {
        incidence[from - 1][lineNumber] = -1;
        incidence[to - 1][lineNumber] = 1;
    }
}

void makeAdjacencyMatrix(string line) {

    int from = stoi(line.substr(0, line.find(" ")));
    int to = stoi(line.substr(line.find(" ") + 1));
    adjacency[from - 1][to - 1]++;
}

string adjacencyMatrixToString() {
    stringstream result;
    result << "| v\\v |";
    for (int i = 1; i <= vertices; i++) {
        result << " v" << setw(2) << setfill(' ') << i << "|";
    }
    for (int i = 0; i < vertices; i++) {
        result << "\n| v" << setw(2) << setfill(' ') << i + 1 << " |";
        for (int j = 0; j < vertices; j++) {
            result << " " << setw(2) << setfill(' ') << adjacency[i][j] << " |";
        }
    }
    return result.str();
}

string incidenceMatrixToString() {
    stringstream result;
    result << "| v\\e |";
    for (int i = 1; i <= edges; i++) {
        result << " e" << setw(2) << setfill(' ') << i << "|";
    }
    for (int i = 0; i < vertices; i++) {
        result << "\n| v" << setw(2) << setfill(' ') << i + 1 << " |";
        for (int j = 0; j < edges; j++) {
            result << " " << setw(2) << setfill(' ') << incidence[i][j] << " |";
        }
    }
    return result.str();
}

void printMatrix(string matrix) {
    cout << matrix << endl;
}

void saveMatrixToFile(string matrix, string filePath) {
    ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << matrix;
        outputFile.close();
    }
    else {
        cerr << "Cannot open file to write" << endl;
    }
}

bool isIrreflexive() {
    for (int i = 0; i < vertices; i++) {
        if (incidence[i][i] == 1) {
            return false;
        }
    }
    return true;
}

bool isSymmetric() {
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (adjacency[i][j] != adjacency[j][i]) {
                return false;
            }
        }
    }
    return true;
}