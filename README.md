# Task manager
This is a task manager console application, made with C++ in Visual Studio, as a final project for C++ course at Singidunum University.

Each task is saved to a `.csv` file, and is read from there into the memory. The tasks have a deadline, a priority, and an executor: person who is responsible for completing the task. Executor class includes a name and a proficiency: either `Junior`, `Middle` or `Senior`.

You can choose 4 options from the menu:
1. List your tasks by ...
2. Add a task
3. Remove a task
4. Exit

## Listing tasks
By choosing this option, you are presented with another choice: list tasks by deadline, priority, or proficiency.

Choosing deadline or priority sorts your tasks accordingly. Deadlines are presented in format `YYYY-MM-DD`.

Choosing proficiency asks which proficiency you want and lists only tasks with specified proficiency.

At any point you are allowed to go back to main menu, if you changed your mind.

## Adding a task
When adding a task, you are presented with inputs asking for:
* Description
* Deadline
* Priority
* Task executor name
* Task executor proficiency (choice)

Before adding a deadline, there is a check in the program if user entered deadline in proper form specified above, otherwise program asks to input it again.

Considering priority, every non-integer input is defaulted to 0.

After all that the task is saved in the `.csv` file.

## Removing a task
When removing a task the user is presented with an ordered list of tasks.

When user inputs number of the task, first program removes the task from its memory (vector) depending on the provided index, and then removes it from file depending on the task name.

User has the option to enter 0, which returns them back to main menu.
