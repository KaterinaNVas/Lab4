/** @file
 * @brief Проверяет чтение и изменение ФИО через тестового наследника Person.
 */

#include "Person.h"
#include "TestSupport.h"

namespace
{
    /** @brief Минимальный наследник для проверки поведения абстрактного Person.
     */
    class TestPersonImplementation final : public Lab4::Person
    {
    public:
        /// @brief Использует конструкторы базового класса.
        using Person::Person;

        /** @brief Формирует ФИО тестового объекта.
         * @return Фамилия, имя и отчество через пробел.
         */
        std::string GetInfo() const override
        {
            return GetSurname() + " " + GetName() + " " + GetPatronymic();
        }
    };
}

/** @brief Проверяет чтение и изменение ФИО через тестового наследника Person.
 */
void TestPerson()
{
    TestPersonImplementation person("Alex", "Brown", "Lee");
    Lab4Tests::CheckEquals(person.GetName(), "Alex", "Person name constructor/getter failed");
    Lab4Tests::CheckEquals(person.GetSurname(), "Brown", "Person surname constructor/getter failed");
    Lab4Tests::CheckEquals(person.GetPatronymic(), "Lee", "Person patronymic constructor/getter failed");

    person.SetName("Avery");
    person.SetSurname("Green");
    person.SetPatronymic("Taylor");
    Lab4Tests::CheckEquals(person.GetInfo(), "Green Avery Taylor", "Person setters failed");
}
