#pragma once

#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H
#include "Task.h"

void readTasksFromFile();
void saveTaskToCSV(Task&);
void removeEntryFromCSV(const std::string&);

#endif