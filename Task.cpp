#include "Task.h"
#include <iostream>

Task::Task(const std::string& desc, const Deadline& deadline, const Executor& exec, int priority)
    : description(desc), deadline(deadline), exec(exec), priority(priority) {}

void Task::printDetails() const {
    std::cout << "Task: " << description << std::endl;
    deadline.printDetails();
    std::cout << "Priority: " << priority << std::endl;
    std::cout << std::endl;
}

const std::string& Task::getDeadline() const {
    return deadline.getDueDate();
}

const std::string& Task::getDescription() const {
    return description;
}

const std::string& Task::getExecutorName() const {
    return exec.getName();
}

const std::string& Task::getExecutorProf() const {
    return exec.getProficiency();
}

int Task::getPriority() const {
    return priority;
}

