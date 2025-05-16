#pragma once

#include <string>
#include <vector>

class Student {
    public:
        Student(const std::string& name, const std::vector<int> scores);

        double average() const;
        const std::string& getName() const;
        const std::vector<int>& getScores() const;

    private:
        const std::string name;
        std::vector<int> scores;
};