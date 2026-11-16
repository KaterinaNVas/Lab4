/** @file
 * @brief Точка входа программы модульных тестов.
 */

#include <exception>
#include <iostream>
#include <string>

#include "TestSupport.h"

void TestPerson();
void TestStudent();
void TestTeacher();
void TestDepartment();
void TestGroup();
void TestUniversity();

namespace
{
    /** @brief Запускает одну группу проверок и сообщает об успехе.
     * @param name Название группы проверок.
     * @param test Функция группы проверок.
     */
    void RunTest(const std::string& name, void (*test)())
    {
        test();
        std::cout << "[PASS] " << name << '\n';
    }
}

/** @brief Последовательно запускает группы модульных тестов.
 * @return 0 при успехе, 1 при первой обнаруженной ошибке.
 */
int main()
{
    try
    {
        RunTest("Person", TestPerson);
        RunTest("Student", TestStudent);
        RunTest("Teacher", TestTeacher);
        RunTest("Department", TestDepartment);
        RunTest("Group", TestGroup);
        RunTest("University", TestUniversity);
    }
    catch (const std::exception& error)
    {
        std::cerr << "[FAIL] " << error.what() << '\n';
        return 1;
    }

    std::cout << "All tests passed.\n";
    return 0;
}
