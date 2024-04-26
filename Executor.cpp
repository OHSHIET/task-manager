#include "Executor.h"
#include <iostream>

Executor::Executor(std::string& name, std::string& proficiency)
	: name(name), proficiency(proficiency) {}

const std::string& Executor::getName() const {
	return name;
}

const std::string& Executor::getProficiency() const {
	return proficiency;
}