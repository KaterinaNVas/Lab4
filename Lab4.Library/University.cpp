/** @file
 * @brief Реализует методы класса University.
 */

#include "University.h"

#include <algorithm>

namespace Lab4
{
    University::University(
        const std::vector<Department>& departments,
        const std::vector<Group>& groups)
        : departments_(departments),
        groups_(groups)
    {
    }

    const std::vector<Department>& University::GetDepartments() const
    {
        return departments_;
    }

    const std::vector<Group>& University::GetGroups() const
    {
        return groups_;
    }

    void University::SetDepartments(const std::vector<Department>& departments)
    {
        departments_ = departments;
    }

    void University::SetGroups(const std::vector<Group>& groups)
    {
        groups_ = groups;
    }

    void University::AddDepartment(const Department& department)
    {
        departments_.push_back(department);
    }

    void University::AddGroup(const Group& group)
    {
        groups_.push_back(group);
    }

    const Student* University::FindStudentByCreditBookNumber(const std::string& creditBookNumber) const
    {
        for (const Group& group : groups_)
        {
            for (const Student& student : group.GetStudents())
            {
                if (student.GetCreditBookNumber() == creditBookNumber)
                {
                    return &student;
                }
            }
        }
        return nullptr;
    }

    std::vector<Student> University::FindStudentsByFullName(
        const std::string& surname,
        const std::string& name,
        const std::string& patronymic) const
    {
        std::vector<Student> result;
        for (const Group& group : groups_)
        {
            for (const Student& student : group.GetStudents())
            {
                if (student.GetSurname() == surname
                    && student.GetName() == name
                    && student.GetPatronymic() == patronymic)
                {
                    result.push_back(student);
                }
            }
        }
        return result;
    }

    std::vector<std::string> University::GetCoursesByDepartment(const std::string& departmentName) const
    {
        for (const Department& department : departments_)
        {
            if (department.GetDepartmentName() == departmentName)
            {
                return department.GetCourses();
            }
        }
        return {};
    }

    std::vector<Teacher> University::GetTeachersByGroup(const std::string& groupName) const
    {
        for (const Group& group : groups_)
        {
            if (group.GetGroupName() == groupName)
            {
                std::vector<Teacher> teachers = group.GetTeachers();
                for (const LaboratoryWork& work : group.GetLaboratoryWorks())
                {
                    for (const Teacher& teacher : work.GetTeachers())
                    {
                        const bool alreadyListed = std::any_of(teachers.cbegin(), teachers.cend(),
                            [&teacher](const Teacher& listedTeacher)
                            {
                                return listedTeacher.HasSameFullName(teacher);
                            });
                        if (!alreadyListed)
                        {
                            teachers.push_back(teacher);
                        }
                    }
                }
                return teachers;
            }
        }
        return {};
    }

    std::vector<Group> University::GetGroupsBySpecialization(const std::string& specialization) const
    {
        std::vector<Group> result;
        for (const Group& group : groups_)
        {
            if (group.GetSpecialization() == specialization)
            {
                result.push_back(group);
            }
        }
        return result;
    }
}
