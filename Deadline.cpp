#include "Deadline.h"
#include <iostream>

Deadline::Deadline(const std::string& dueDate)
    : dueDate(dueDate) {}

void Deadline::printDetails() const {
    std::cout << "Due Date: " << dueDate << std::endl;
}

const std::string& Deadline::getDueDate() const {
    return dueDate;
}

bool Deadline::operator<(const Deadline& other) const {
    return dueDate < other.dueDate;
}
