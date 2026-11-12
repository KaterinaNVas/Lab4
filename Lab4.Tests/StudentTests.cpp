/** @file
 * @brief Проверяет данные студента, формат ФИО, копирование и перемещение.
 */

#include <string>
#include <utility>

#include "Student.h"
#include "TestSupport.h"

/** @brief Проверяет данные студента, формат ФИО, копирование и перемещение.
 */
void TestStudent()
{
    Lab4::Student student("Alex", "Brown", "Lee", 20, "RB-1");
    Lab4Tests::CheckEquals(student.GetName(), "Alex", "Student inherited name getter failed");
    Lab4Tests::CheckEquals(student.GetAge(), 20, "Student age constructor/getter failed");
    Lab4Tests::CheckEquals(student.GetCreditBookNumber(), "RB-1", "Student record-book getter failed");
    Lab4Tests::CheckEquals(Lab4Tests::Equals(student.GetInfo().find("RB-1"), std::string::npos), false, "Student GetInfo failed");

    student.SetSurname("Green");
    student.SetAge(22);
    student.SetCreditBookNumber("RB-22");
    Lab4Tests::CheckEquals(student.GetSurname(), "Green", "Student inherited surname setter failed");
    Lab4Tests::CheckEquals(student.GetAge(), 22, "Student SetAge failed");
    Lab4Tests::CheckEquals(student.GetCreditBookNumber(), "RB-22", "Student SetCreditBookNumber failed");

    Lab4Tests::CheckEquals(Lab4Tests::Equals(student.GetInfo().find("Green Alex Lee"), std::string::npos), false,
        "Student GetInfo should display updated surname, name and patronymic");

    const Lab4::Student copiedStudent(student);
    Lab4Tests::CheckEquals(copiedStudent.GetCreditBookNumber(), "RB-22", "Student copy constructor failed");
    Lab4::Student assignedStudent("Other", "Person", "Name", 18, "RB-18");
    assignedStudent = student;
    Lab4Tests::CheckEquals(assignedStudent.GetName(), "Alex", "Student copy assignment failed");

    Lab4::Student movedStudent(std::move(assignedStudent));
    Lab4Tests::CheckEquals(movedStudent.GetCreditBookNumber(), "RB-22", "Student move constructor failed");
    Lab4::Student moveAssignedStudent("Other", "Person", "Name", 18, "RB-18");
    moveAssignedStudent = std::move(movedStudent);
    Lab4Tests::CheckEquals(moveAssignedStudent.GetAge(), 22, "Student move assignment failed");
}
