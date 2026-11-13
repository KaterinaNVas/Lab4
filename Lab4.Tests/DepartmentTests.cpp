/** @file
 * @brief Проверяет создание кафедры, чтение и изменение её данных.
 */

#include "Department.h"
#include "TestSupport.h"

/** @brief Проверяет создание кафедры, чтение и изменение её данных.
 */
void TestDepartment()
{
    const Lab4::Teacher teacher("Chris", "White", "Morgan", { "Math" });
    Lab4::Department department("Mathematics", { "Math", "Algebra" }, { teacher });
    Lab4Tests::CheckEquals(department.GetDepartmentName(), "Mathematics",
        "Department constructor/getter failed");
    Lab4Tests::CheckEquals(department.GetCourses().size(), 2, "Department courses getter failed");
    Lab4Tests::CheckEquals(department.GetTeachers().size(), 1, "Department teachers getter failed");

    department.SetDepartmentName("Applied Mathematics");
    department.SetCourses({ "Statistics" });
    department.SetTeachers({});
    Lab4Tests::CheckEquals(department.GetDepartmentName(), "Applied Mathematics",
        "Department name setter failed");
    Lab4Tests::CheckEquals(department.GetCourses().size(), 1, "Department courses setter failed");
    Lab4Tests::CheckEquals(department.GetCourses()[0], "Statistics", "Department courses setter failed");
    Lab4Tests::CheckEquals(department.GetTeachers().empty(), true, "Department teachers setter failed");

    const Lab4::Department emptyDepartment;
    Lab4Tests::CheckEquals(emptyDepartment.GetDepartmentName().empty(), true, "Default Department constructor failed");
}
