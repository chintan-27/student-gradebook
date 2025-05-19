#include "csv_utils.hpp"
#include <iostream>
#include <sstream>

void cleanup(std::vector<Student*>& students) {
    for (auto* student : students) {
        delete student;
    }
    students.clear();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_csv>\n";
        return 1;
    }

    std::string filename = argv[1];
    auto students = load_students_from_csv(filename);

    if (students.empty()) {
        std::cerr << "No students loaded. Exiting.\n";
        return 1;
    }

    int choice;
    do {
        std::cout << "\n--- Student Gradebook ---\n";
        std::cout << "1. Show all students and averages\n";
        std::cout << "2. Show top student\n";
        std::cout << "3. Show students below a threshold\n";
        std::cout << "4. Export to averages.csv\n";
        std::cout << "5. Exit\n";
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (!(ss >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                for (const auto* s : students)
                    std::cout << s->getName() << ": " << s->average() << "\n";
                break;

            case 2: {
                const Student* top = nullptr;
                double highest = -1.0;
                for (const auto* s : students) {
                    if (s->average() > highest) {
                        highest = s->average();
                        top = s;
                    }
                }
                if (top)
                    std::cout << "Top Student: " << top->getName()
                              << " with average " << top->average() << "\n";
                else
                    std::cout << "No students.\n";
                break;
            }

            case 3: {
                std::string threshold_input;
                double threshold;
                std::cout << "Enter threshold: ";
                std::getline(std::cin, threshold_input);
                std::stringstream ts(threshold_input);
                if (!(ts >> threshold)) {
                    std::cout << "Invalid threshold.\n";
                    continue;
                }
                break;
            }

            case 4:
                save_students_to_csv("averages.csv", students);
                std::cout << "Exported to averages.csv\n";
                break;

            case 5:
                std::cout << "Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    cleanup(students);
    return 0;
}
