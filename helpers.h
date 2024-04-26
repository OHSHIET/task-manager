#pragma once

#ifndef HELPERS_H
#define HELPERS_H

#include "Task.h"

void clearConsole();
bool option_check_3();
bool option_check_4();
void invalid_option_check_3(const std::string&);
bool compareTasksByDeadline(const Task&, const Task&);
bool compareTasksByPriority(const Task&, const Task&);


#endif // !HELPERS_H
