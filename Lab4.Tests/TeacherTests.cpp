/** @file
 * @brief Проверяет данные преподавателя, дисциплины, копирование и перемещение.
 */

#include <string>
#include <utility>
#include <vector>

#include "Teacher.h"
#include "TestSupport.h"

/** @brief Проверяет данные преподавателя, дисциплины, копирование и перемещение.
 */
void TestTeacher()
{
    Lab4::Teacher teacher("Chris", "White", "Morgan", { "Math" });
    Lab4Tests::CheckEquals(teacher.GetName(), "Chris", "Teacher inherited name getter failed");
    Lab4Tests::CheckEquals(teacher.GetCourses().size(), 1, "Teacher courses constructor/getter failed");
    Lab4Tests::CheckEquals(teacher.GetCourses()[0], "Math", "Teacher courses constructor/getter failed");
    Lab4Tests::CheckEquals(Lab4Tests::Equals(teacher.GetInfo().find("Math"), std::string::npos), false, "Teacher GetInfo failed");

    teacher.SetName("Taylor");
    teacher.SetCourses({ "Physics", "Chemistry" });
    Lab4Tests::CheckEquals(teacher.GetName(), "Taylor", "Teacher inherited setter failed");
    Lab4Tests::CheckEquals(teacher.GetCourses().size(), 2, "Teacher SetCourses failed");
    Lab4Tests::CheckEquals(teacher.GetCourses()[1], "Chemistry", "Teacher SetCourses failed");
    Lab4Tests::CheckEquals(Lab4Tests::Equals(teacher.GetInfo().find("Physics, Chemistry"), std::string::npos), false,
        "Teacher GetInfo did not use updated courses");

    const Lab4::Teacher copiedTeacher(teacher);
    Lab4Tests::CheckEquals(copiedTeacher.GetCourses().size(), 2, "Teacher copy constructor failed");
    Lab4::Teacher assignedTeacher("Other", "Person", "Name", {});
    assignedTeacher = teacher;
    Lab4Tests::CheckEquals(assignedTeacher.GetName(), "Taylor", "Teacher copy assignment failed");

    Lab4::Teacher movedTeacher(std::move(assignedTeacher));
    Lab4Tests::CheckEquals(movedTeacher.GetSurname(), "White", "Teacher move constructor failed");
    Lab4::Teacher moveAssignedTeacher("Other", "Person", "Name", {});
    moveAssignedTeacher = std::move(movedTeacher);
    Lab4Tests::CheckEquals(moveAssignedTeacher.GetCourses().size(), 2, "Teacher move assignment failed");
}
