#ifndef TASK_H
#define TASK_H

#include "Deadline.h"
#include "AbstractTask.h"
#include "Executor.h"

class Task : public AbstractTask {
public:
    Task(const std::string& desc, const Deadline& deadline, const Executor& exec, int priority);
    void printDetails() const override;
    const std::string& getDeadline() const override;
    const std::string& getDescription() const override;
    const std::string& getExecutorName() const override;
    const std::string& getExecutorProf() const override;
    int getPriority() const override;

private:
    std::string description;
    Deadline deadline;
    Executor exec;
    int priority;
};

#endif
