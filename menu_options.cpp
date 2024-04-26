#include <regex>
#include <iostream>
#include "menu_options.h"
#include "globals.h"
#include "Task.h"
#include "file_operations.h"
#include "main.h"
#include "helpers.h"

using namespace std;

void add_task() {
    clearConsole();
    string desc, dueDate;
    int priority;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);

    regex dateRegex("\\d{4}-\\d{2}-\\d{2}");
    do {
        cout << "Enter deadline (YYYY-MM-DD): ";
        cin.clear();
        cin >> dueDate;
        if (!regex_match(dueDate, dateRegex)) {
            cout << "Invalid deadline format. Please enter in YYYY-MM-DD format." << endl;
        }
    } while (!regex_match(dueDate, dateRegex));

    cout << "Enter priority: ";
    cin >> priority;

    string name;
    string proficiency = "Junior";

    cout << "Enter task executor name: ";
    cin.ignore();
    getline(cin, name);

    proficiency = proficiencyChoice();

    Executor exec(name, proficiency);

    Deadline deadline(dueDate);

    Task t(desc, deadline, exec, priority);

    saveTaskToCSV(t);
    tasks.emplace_back(t);

    cout << "\nAdded task successfully!\n" << endl;
    main_menu(false);
}

void remove_task() {
    if (tasks.empty()) {
        cout << "\nYou don't have any tasks!\n" << endl;
        main_menu(false);
    }

    cout << "\nChoose a task to remove (0 - back to main menu): " << endl;

    list_all_tasks("-");

    int input;
    bool err = false;

    do {
        err = false;
        cin.clear();
        cin >> input;

        if (cin.fail() || input > tasks.size() || input < 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            err = true;
            cout << "\nEnter values in range from 0 to " << tasks.size() << "\n" << endl;
        }
    } while (err);

    if (input == 0) {
        main_menu(true);
    }

    string desc = tasks[input - 1].getDescription();

    tasks.erase(tasks.begin() + input - 1);

    removeEntryFromCSV(desc);

    cout << "\nRemoved entry number " << input << "\n" << endl;

    main_menu(false);
}

void list_tasks_menu() {
    if (tasks.empty()) {
        cout << "\nYou don't have any tasks!\n" << endl;
        main_menu(false);
    }
    clearConsole();
    do {

        cout << "List tasks by ..." << endl;
        cout << "1. Deadline" << endl;
        cout << "2. Priority" << endl;
        cout << "3. Proficiency" << endl;
        cout << "4. Back to main menu" << endl;

        cin.clear();
        cin >> option;

        invalid = option_check_4();

        invalid_option_check_3(invalid_txt_4);

    } while (invalid);

    switch (option) {
    case 1:
        sort(tasks.begin(), tasks.end(), compareTasksByDeadline);

        cout << "Tasks sorted by deadline:\n";
        list_all_tasks("-");
        break;
    case 2:
        sort(tasks.begin(), tasks.end(), compareTasksByPriority);

        cout << "\nTasks sorted by priority:\n";
        list_all_tasks("-");
        break;
    case 3:
        list_all_tasks(proficiencyChoice());
        break;
    case 4:
        main_menu(true);
        break;
    }
    main_menu(false);
}

void list_all_tasks(string prof) {
    cout << endl;
    int count = 1;
    bool profSearch = (prof != "-") ? true : false;
    for (const Task& task : tasks) {
        if ((!profSearch) || (profSearch && task.getExecutorProf() == prof)) {
            cout << count << ". "
                << "Description: " << task.getDescription() << ", "
                << "Deadline: " << task.getDeadline() << ", "
                << "Executor: " << task.getExecutorName() << ", "
                << "Executor proficiency: " << task.getExecutorProf() << ", "
                << "Priority: " << task.getPriority() << endl;
            count++;
        }
    }
    cout << endl;
}

string proficiencyChoice() {
    do {
        cout << "Choose task executor proficiency: " << endl;
        cout << "1. Junior" << endl;
        cout << "2. Middle" << endl;
        cout << "3. Senior" << endl;

        cin.clear();
        cin >> option;

        invalid = option_check_3();
        invalid_option_check_3(invalid_txt_3);

    } while (invalid);

    switch (option) {
    case 1:
        return "Junior";
    case 2:
        return "Middle";
    case 3:
        return "Senior";
    default:
        return "Junior";
    }
}