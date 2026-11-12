/** @file
 * @brief Реализует методы класса Teacher.
 */

#include "Teacher.h"

namespace Lab4
{
    Teacher::Teacher(
        const std::string& name,
        const std::string& surname,
        const std::string& patronymic,
        const std::vector<std::string>& courses)
        : Person(name, surname, patronymic),
        courses_(courses)
    {}

    const std::vector<std::string>& Teacher::GetCourses() const {
        return courses_;
    }

    void Teacher::SetCourses(const std::vector<std::string>& courses) {
        courses_ = courses;
    }

    std::string Teacher::GetInfo() const
    {
        std::string info = "Преподаватель: " + GetSurname() + " " + GetName() + " " + GetPatronymic();
        if (!courses_.empty())
        {
            info += ", дисциплины: ";
            for (std::size_t index = 0; index < courses_.size(); ++index)
            {
                if (index != 0)
                {
                    info += ", ";
                }
                info += courses_[index];
            }
        }
        return info;
    }
}
