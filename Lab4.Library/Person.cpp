/** @file
 * @brief Реализует методы класса Person.
 */

#include "Person.h"

namespace Lab4
{
    std::atomic<std::uint64_t> Person::nextId_{1};

    Person::Person(
        const std::string& name,
        const std::string& surname,
        const std::string& patronymic)
        : id_(nextId_.fetch_add(1, std::memory_order_relaxed)),
        name_(name),
        surname_(surname),
        patronymic_(patronymic)
    {
    }

    std::uint64_t Person::GetId() const
    {
        return id_;
    }

    const std::string& Person::GetName() const
    {
        return name_;
    }

    const std::string& Person::GetSurname() const
    {
        return surname_;
    }

    const std::string& Person::GetPatronymic() const
    {
        return patronymic_;
    }

    bool Person::HasSameFullName(const Person& other) const
    {
        return name_ == other.name_
            && surname_ == other.surname_
            && patronymic_ == other.patronymic_;
    }

    void Person::SetName(const std::string& name)
    {
        name_ = name;
    }

    void Person::SetSurname(const std::string& surname)
    {
        surname_ = surname;
    }

    void Person::SetPatronymic(const std::string& patronymic)
    {
        patronymic_ = patronymic;
    }
}
