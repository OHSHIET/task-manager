#include "file_operations.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "globals.h"

using namespace std;

void readTasksFromFile() {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string desc, dueDate, execName, execProf;
            int priority;
            getline(iss, desc, ',');
            getline(iss, dueDate, ',');
            getline(iss, execName, ',');
            getline(iss, execProf, ',');
            iss >> priority;
            Deadline deadline(dueDate);
            Executor exec(execName, execProf);
            Task t(desc, deadline, exec, priority);

            tasks.emplace_back(t);

        }
    }
    else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void removeEntryFromCSV(const string& descriptionToRemove) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    vector<string> lines;

    string line;
    while (getline(inFile, line)) {
        if (line.find(descriptionToRemove) == string::npos) {
            lines.push_back(line);
        }
    }

    inFile.close();

    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open file " << filename << " for writing" << endl;
        return;
    }

    for (const auto& line : lines) {
        outFile << line << endl;
    }

    outFile.close();
}

void saveTaskToCSV(Task& task) {
    ofstream outputFile(filename, ios::app);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    outputFile << task.getDescription() << ","
        << task.getDeadline() << ","
        << task.getExecutorName() << ","
        << task.getExecutorProf() << ","
        << task.getPriority() << endl;

    outputFile.close();
}