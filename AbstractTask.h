#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include <string>

class AbstractTask {
public:
    virtual ~AbstractTask() = default;
    virtual void printDetails() const = 0;
    virtual int getPriority() const = 0;
    virtual const std::string& getDeadline() const = 0;
    virtual const std::string& getDescription() const = 0;
    virtual const std::string& getExecutorName() const = 0;
    virtual const std::string& getExecutorProf() const = 0;

};

#endif // ABSTRACTTASK_H
