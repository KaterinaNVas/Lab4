/** @file
 * @brief Реализует методы класса Department.
 */

#include "Department.h"

namespace Lab4
{
    Department::Department(
        const std::string& departmentName,
        const std::vector<std::string>& courses,
        const std::vector<Teacher>& teachers)
        : departmentName_(departmentName),
        courses_(courses),
        teachers_(teachers)
    {
    }

    const std::string& Department::GetDepartmentName() const
    {
        return departmentName_;
    }

    const std::vector<std::string>& Department::GetCourses() const
    {
        return courses_;
    }

    const std::vector<Teacher>& Department::GetTeachers() const
    {
        return teachers_;
    }

    void Department::SetDepartmentName(const std::string& departmentName)
    {
        departmentName_ = departmentName;
    }

    void Department::SetCourses(const std::vector<std::string>& courses)
    {
        courses_ = courses;
    }

    void Department::SetTeachers(const std::vector<Teacher>& teachers)
    {
        teachers_ = teachers;
    }
}
