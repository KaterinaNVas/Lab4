#include "Student.h"
#include <utility>


namespace Lab4
{
    Student::Student(const Student& other)
        : name_(other.name_), surname_(other.surname_), patronymic_(other.patronymic_), age_(other.age_), creditBookNumber_(other.creditBookNumber_), groupName_(other.groupName_), specialization_(other.specialization_)
    {
    }

    Student& Student::operator=(const Student& other)
    {
        if (this != &other)
        {
            name_ = other.name_;
            surname_ = other.surname_;
            patronymic_ = other.patronymic_;
            age_ = other.age_;
            creditBookNumber_ = other.creditBookNumber_;
            groupName_ = other.groupName_;
            specialization_ = other.specialization_;
        }
        return *this;
    }

    Student::Student(Student&& other) noexcept
        : name_(std::move(other.name_)), surname_(std::move(other.surname_)), patronymic_(std::move(other.patronymic_)), age_(other.age_), creditBookNumber_(std::move(other.creditBookNumber_)), groupName_(std::move(other.groupName_)), specialization_(std::move(other.specialization_))
    {
    }

    Student& Student::operator=(Student&& other) noexcept
    {
        if (this != &other)
        {
            name_ = std::move(other.name_);
            surname_ = std::move(other.surname_);
            patronymic_ = std::move(other.patronymic_);
            age_ = other.age_;
            creditBookNumber_ = std::move(other.creditBookNumber_);
            groupName_ = std::move(other.groupName_);
            specialization_ = std::move(other.specialization_);
        }
        return *this;
    }
    

    Student::Student(const std::string& name, const std::string& surname, const std::string& patronymic, int age, const std::string& creditBookNumber, const std::string& groupName, const std::string& specialization)
        : name_(name), surname_(surname), patronymic_(patronymic), age_(age), creditBookNumber_(creditBookNumber), groupName_(groupName), specialization_(specialization)
    {
    }

    const std::string& Student::GetName() const
    {
        return name_;
    }

    const std::string& Student::GetSurname() const
    {
        return surname_;
    }

    const std::string& Student::GetPatronymic() const
    {
        return patronymic_;
    }

    int Student::GetAge() const
    {
        return age_;
    }

    const std::string& Student::GetCreditBookNumber() const
    {
        return creditBookNumber_;
    }

    const std::string& Student::GetSpecialization() const
    {
        return specialization_;
    }

    const std::string& Student::GetGroupName() const
    {
        return groupName_;
    }


}