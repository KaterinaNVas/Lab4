/** @file
 * @brief Реализует методы класса LaboratoryWork.
 */

#include "LaboratoryWork.h"

#include <stdexcept>

namespace Lab4
{
    LaboratoryWork::LaboratoryWork(
        const std::string& course,
        const Teacher& firstTeacher,
        const Teacher& secondTeacher)
        : course_(course), teachers_{ firstTeacher, secondTeacher }
    {
        if (firstTeacher.HasSameFullName(secondTeacher))
        {
            throw std::invalid_argument("A laboratory work requires two distinct teachers");
        }
    }

    const std::string& LaboratoryWork::GetCourse() const
    {
        return course_;
    }

    const std::array<Teacher, 2>& LaboratoryWork::GetTeachers() const
    {
        return teachers_;
    }
}
