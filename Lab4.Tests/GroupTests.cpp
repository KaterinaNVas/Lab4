/** @file
 * @brief Проверяет создание группы, чтение и изменение её данных.
 */

#include "Group.h"
#include "TestSupport.h"

/** @brief Проверяет создание группы, чтение и изменение её данных.
 */
void TestGroup()
{
    const Lab4::Student student("Alex", "Brown", "Lee", 20, "RB-1");
    const Lab4::Teacher teacher("Chris", "White", "Morgan", { "Math" });
    Lab4::Group group("M-101", "Mathematics", { student }, { teacher });
    Lab4Tests::CheckEquals(group.GetGroupName(), "M-101", "Group name constructor/getter failed");
    Lab4Tests::CheckEquals(group.GetSpecialization(), "Mathematics",
        "Group specialization constructor/getter failed");
    Lab4Tests::CheckEquals(group.GetStudents().size(), 1, "Group students getter failed");
    Lab4Tests::CheckEquals(group.GetTeachers().size(), 1, "Group teachers getter failed");

    group.SetGroupName("M-102");
    group.SetSpecialization("Applied Mathematics");
    group.SetStudents({});
    group.SetTeachers({});
    Lab4Tests::CheckEquals(group.GetGroupName(), "M-102", "Group name setter failed");
    Lab4Tests::CheckEquals(group.GetSpecialization(), "Applied Mathematics",
        "Group specialization setter failed");
    Lab4Tests::CheckEquals(group.GetStudents().empty(), true, "Group students setter failed");
    Lab4Tests::CheckEquals(group.GetTeachers().empty(), true, "Group teachers setter failed");

    const Lab4::Group emptyGroup;
    Lab4Tests::CheckEquals(emptyGroup.GetGroupName().empty(), true, "Default Group constructor failed");
}
