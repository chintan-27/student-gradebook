#pragma once

#include "student.hpp"
#include <vector>
#include <string>

std::vector<Student*> load_students_from_csv(const std::string& filename);
void save_students_to_csv(const std::string& filename, const std::vector<Student*>& students);
