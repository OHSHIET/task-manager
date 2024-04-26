#include <iostream>
#include "Task.h"
#include "Executor.h"
#include "globals.h"
#include "file_operations.h"
#include "main.h"
#include "menu_options.h"
#include "helpers.h"

using namespace std;

int main() {
    readTasksFromFile();
    main_menu(false);
    return 0;
}

void main_menu(bool clearScreen) {
    if(clearScreen) clearConsole();
    do {
        cout << "Choose an option:" << endl;
        cout << "1. List your tasks by ..." << endl;
        cout << "2. Add a task" << endl;
        cout << "3. Remove a task" << endl;
        cout << "4. Exit" << endl;

        cin.clear();
        cin >> option;

        invalid = option_check_4();
        invalid_option_check_3(invalid_txt_4);

    } while (invalid);

    switch (option) {
    case 1:
        list_tasks_menu();
        break;
    case 2:
        add_task();
        break;
    case 3:
        remove_task();
        break;
    case 4:
        exit(EXIT_SUCCESS);
        break;
    }
}