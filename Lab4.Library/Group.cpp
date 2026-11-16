/** @file
 * @brief Реализует методы класса Group.
 */

#include "Group.h"

namespace Lab4
{
    Group::Group(
        const std::string& groupName,
        const std::string& specialization,
        const std::vector<Student>& students,
        const std::vector<Teacher>& teachers,
        const std::vector<LaboratoryWork>& laboratoryWorks)
        : groupName_(groupName),
        specialization_(specialization),
        students_(students),
        teachers_(teachers),
        laboratoryWorks_(laboratoryWorks)
    {
    }

    const std::string& Group::GetGroupName() const
    {
        return groupName_;
    }

    const std::string& Group::GetSpecialization() const
    {
        return specialization_;
    }

    const std::vector<Student>& Group::GetStudents() const
    {
        return students_;
    }

    const std::vector<Teacher>& Group::GetTeachers() const
    {
        return teachers_;
    }

    const std::vector<LaboratoryWork>& Group::GetLaboratoryWorks() const
    {
        return laboratoryWorks_;
    }

    void Group::SetGroupName(const std::string& groupName)
    {
        groupName_ = groupName;
    }

    void Group::SetSpecialization(const std::string& specialization)
    {
        specialization_ = specialization;
    }

    void Group::SetStudents(const std::vector<Student>& students)
    {
        students_ = students;
    }

    void Group::SetTeachers(const std::vector<Teacher>& teachers)
    {
        teachers_ = teachers;
    }
}
