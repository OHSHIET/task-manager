#pragma once
#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <string>

class Executor {
private:
    std::string name;
    std::string proficiency;

public:
    Executor(std::string&, std::string&);
    const std::string& getName() const;
    const std::string& getProficiency() const;
};

#endif