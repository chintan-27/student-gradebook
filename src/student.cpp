#include "student.hpp"
#include <numeric>

Student::Student(const std::string& name, const std::vector<int> scores) 
    :name(name), scores(scores) {}


double Student::average() const {
    if (scores.empty()) return 0.0;
    double sum = std::accumulate(scores.begin(), scores.end(), 0.0);
    return sum / scores.size();
}

const std::string& Student::getName() const {
    return name;
}

const std::vector<int>& Student::getScores() const {
    return scores;
}
