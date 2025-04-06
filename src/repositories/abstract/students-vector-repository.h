#ifndef STUDENTS_VECTOR_REPOSITORY_H
#define STUDENTS_VECTOR_REPOSITORY_H

#include "../contracts/students-repository-contract.h"
#include "../contracts/input-manager-repository-contract.h"
#include <vector>
#include <algorithm>

class StudentsVectorRepository : public StudentsRepositoryContract
{
private:
    std::vector<StudentWithGradesVector> students;
    InputManagerRepositoryContract* inputManagerRepositoryRepository;

public:
    StudentsVectorRepository(InputManagerRepositoryContract* inputManagerRepositoryRepository);
    ~StudentsVectorRepository();

    void save(StudentWithGradesVector studentWithGradesVector) override;
    StudentContainer getStudentWithGradesVector() override;
    void sortData() override;
    void clearData() override;
};

#endif 