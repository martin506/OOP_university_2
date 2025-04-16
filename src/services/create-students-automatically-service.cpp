#include "abstract/create-students-automatically-service.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

CreateStudentsAutomaticallyService::CreateStudentsAutomaticallyService(StudentsRepositoryContract& studentsRepository)
    : studentsRepository(studentsRepository) {
    std::srand(std::time(nullptr));
}

std::pair<std::string, std::string> CreateStudentsAutomaticallyService::getRandomNameAndSurname() {
    int nameIndex = std::rand() % names.size();
    int surnameIndex = std::rand() % surnames.size();
    return {names[nameIndex], surnames[surnameIndex]};
}

int CreateStudentsAutomaticallyService::getRandomGrade() {
    return std::rand() % 10 + 1;
}

void CreateStudentsAutomaticallyService::execute(int numberOfStudents) {
    try {
        for (int i = 0; i < numberOfStudents; ++i) {
            auto [name, surname] = getRandomNameAndSurname();
            std::vector<int> grades;
            for (int j = 0; j < 5; ++j) {
                grades.push_back(getRandomGrade());
            }
            int examGrade = getRandomGrade();
    
            StudentWithGradesVector studentWithGrades;
            studentWithGrades.setGrades(grades);
            Student student;
            student.setName(name);
            student.setSurname(surname);
            student.setExamGrade(examGrade);
            studentWithGrades.setStudent(student);
            student.setFinalGradeWithAverage(studentWithGrades.calculateAverage());
            student.setFinalGradeWithMedian(studentWithGrades.calculateMedian());
            studentWithGrades.setStudent(student);
            studentsRepository.save(studentWithGrades);
        }

        std::cout << "Generated " << numberOfStudents << " students successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
