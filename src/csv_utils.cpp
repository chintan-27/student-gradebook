#include "csv_utils.hpp"
#include <fstream>
#include <sstream>
#include <iostream>  // optional for debug

std::vector<Student*> load_students_from_csv(const std::string& filename) {
    std::cout << "Loading " << filename << std::endl;
    std::vector<Student*> students;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return students;
    }

    std::string line;

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;

        // Get the name
        std::getline(ss, token, ',');
        std::string name = token;

        if (token.empty()) continue;
        std::vector<int> scores;

        // Get the scores
        while (std::getline(ss, token, ',')) {
            try {
                scores.push_back(std::stoi(token));
            } catch (...) {
                std::cerr << "Warning: Invalid score for " << name << "\n";
                scores.push_back(0);  // or skip/handle gracefully
            }
        }

        students.push_back(new Student(name, scores));
    }

    return students;
}

void save_students_to_csv(const std::string& filename, const std::vector<Student*>& students) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Cannot write to file " << filename << std::endl;
        return;
    }

    file << "name,average\n";
    for (const auto* student : students) {
        file << student->getName() << "," << student->average() << "\n";
    }
}
