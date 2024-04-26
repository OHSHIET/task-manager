#include "helpers.h"
#include "globals.h"
#include <iostream>

using namespace std;

bool option_check_3() {
    return option != 1 && option != 2 && option != 3;
}

bool option_check_4() {
    return option != 1 && option != 2 && option != 3 && option != 4;
}

void clearConsole() {
    cout << "\033[2J\033[H";
}

void invalid_option_check_3(const string& txt) {
    if (cin.fail()) {
        clearConsole();
        cerr << txt << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if (invalid) {
        clearConsole();
        cerr << txt << endl;
    }
}

bool compareTasksByDeadline(const Task& task1, const Task& task2) {
    return task1.getDeadline() < task2.getDeadline();
}

bool compareTasksByPriority(const Task& task1, const Task& task2) {
    return task1.getPriority() < task2.getPriority();
}