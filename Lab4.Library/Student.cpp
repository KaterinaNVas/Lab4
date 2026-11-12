/** @file
 * @brief Реализует методы класса Student.
 */

#include "Student.h"

namespace Lab4
{
    Student::Student(
        const std::string& name,
        const std::string& surname,
        const std::string& patronymic,
        int age,
        const std::string& creditBookNumber)
        : Person(name, surname, patronymic),
        age_(age),
        creditBookNumber_(creditBookNumber)
    {
    }

    int Student::GetAge() const
    {
        return age_;
    }

    const std::string& Student::GetCreditBookNumber() const
    {
        return creditBookNumber_;
    }

    void Student::SetAge(int age)
    {
        age_ = age;
    }

    void Student::SetCreditBookNumber(const std::string& creditBookNumber)
    {
        creditBookNumber_ = creditBookNumber;
    }

    std::string Student::GetInfo() const
    {
        return "Студент: " + GetSurname() + " " + GetName() + " " + GetPatronymic()
            + ", возраст: " + std::to_string(age_)
            + ", зачётная книжка: " + creditBookNumber_;
    }
}
