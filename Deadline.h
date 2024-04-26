#pragma once
#ifndef DEADLINE_H
#define DEADLINE_H

#include <string>

class Deadline {
public:
    Deadline(const std::string& dueDate);
    void printDetails() const;
    const std::string& getDueDate() const;
    bool operator<(const Deadline& other) const; // Less-than operator declaration

private:
    std::string dueDate;
};

#endif // DEADLINE_H
