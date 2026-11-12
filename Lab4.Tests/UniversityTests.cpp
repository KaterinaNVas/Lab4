/** @file
 * @brief Проверяет запросы к вузу и правило двух преподавателей лабораторной.
 */

#include <stdexcept>
#include <vector>

#include "Department.h"
#include "Group.h"
#include "LaboratoryWork.h"
#include "Student.h"
#include "Teacher.h"
#include "TestSupport.h"
#include "University.h"

namespace
{
    using namespace Lab4;

    /** @brief Создаёт данные для проверки запросов к вузу.
     * @return Вуз с кафедрами, группами и лабораторной работой.
     */
    University MakeUniversity()
    {
        const Student studentOne("Alex", "Brown", "Lee", 20, "RB-1");
        const Student studentTwo("Alex", "Brown", "Lee", 21, "RB-2");
        const Student otherStudent("Sam", "Green", "Taylor", 19, "RB-3");
        const Teacher teacherOne("Chris", "White", "Morgan", { "Math" });
        const Teacher teacherTwo("Jamie", "Black", "Jordan", { "Physics" });

        return University(
            {
                Department("Mathematics", { "Math", "Algebra" }, { teacherOne }),
                Department("Physics", { "Physics" }, { teacherTwo })
            },
            {
                Group("M-101", "Mathematics", { studentOne, otherStudent }, { teacherOne },
                    { LaboratoryWork("Math", teacherOne, teacherTwo) }),
                Group("M-102", "Mathematics", { studentTwo }, { teacherOne }),
                Group("P-101", "Physics", {}, { teacherTwo })
            });
    }

}

/** @brief Проверяет запросы к вузу и правило двух преподавателей лабораторной.
 */
void TestUniversity()
{
    using namespace Lab4;
    const University university = MakeUniversity();
    Lab4Tests::CheckEquals(university.GetDepartments().size(), 2, "University departments constructor/getter failed");
    Lab4Tests::CheckEquals(university.GetGroups().size(), 3, "University groups constructor/getter failed");

    const Student* foundStudent = university.FindStudentByCreditBookNumber("RB-1");
    Lab4Tests::CheckEquals(Lab4Tests::Equals(foundStudent, nullptr), false, "Student lookup by record-book number failed");
    Lab4Tests::CheckEquals(foundStudent->GetName(), "Alex", "Record-book lookup returned the wrong student");
    Lab4Tests::CheckEquals(university.FindStudentByCreditBookNumber("missing"), nullptr,
        "Missing record-book number should return nullptr");

    const std::vector<Student> studentsByName =
        university.FindStudentsByFullName("Brown", "Alex", "Lee");
    Lab4Tests::CheckEquals(studentsByName.size(), 2, "Full-name lookup should return all matching students");
    Lab4Tests::CheckEquals(university.FindStudentsByFullName("Missing", "Name", "Person").empty(), true,
        "Missing full name should return an empty list");

    const std::vector<std::string> courses = university.GetCoursesByDepartment("Mathematics");
    Lab4Tests::CheckEquals(courses.size(), 2, "Department course lookup failed");
    Lab4Tests::CheckEquals(courses[0], "Math", "Department course lookup failed");
    Lab4Tests::CheckEquals(courses[1], "Algebra", "Department course lookup failed");
    Lab4Tests::CheckEquals(university.GetCoursesByDepartment("Missing").empty(), true,
        "Missing department should return an empty course list");

    const std::vector<Teacher> teachers = university.GetTeachersByGroup("M-101");
    Lab4Tests::CheckEquals(teachers.size(), 2, "Group lookup should include the laboratory teachers without duplicates");
    Lab4Tests::CheckEquals(teachers[0].GetSurname(), "White", "Group lookup should include the laboratory teachers without duplicates");
    Lab4Tests::CheckEquals(teachers[1].GetSurname(), "Black", "Group lookup should include the laboratory teachers without duplicates");

    const LaboratoryWork& work = university.GetGroups().front().GetLaboratoryWorks().front();
    Lab4Tests::CheckEquals(work.GetCourse(), "Math", "A laboratory work should store its course and both teachers");
    Lab4Tests::CheckEquals(work.GetTeachers().size(), 2, "A laboratory work should store its course and both teachers");

    bool rejectedSameTeacher = false;
    try
    {
        const LaboratoryWork invalidWork("Math", teachers[0], teachers[0]);
    }
    catch (const std::invalid_argument&)
    {
        rejectedSameTeacher = true;
    }
    Lab4Tests::CheckEquals(rejectedSameTeacher, true, "A laboratory work must have two distinct teachers");
    Lab4Tests::CheckEquals(university.GetTeachersByGroup("Missing").empty(), true,
        "Missing group should return an empty teacher list");

    const std::vector<Group> groups = university.GetGroupsBySpecialization("Mathematics");
    Lab4Tests::CheckEquals(groups.size(), 2, "Specialization group lookup failed");
    Lab4Tests::CheckEquals(university.GetGroupsBySpecialization("Missing").empty(), true,
        "Missing specialization should return an empty group list");

    University mutableUniversity;
    mutableUniversity.SetDepartments({ Department("Physics") });
    mutableUniversity.SetGroups({ Group("P-101", "Physics") });
    Lab4Tests::CheckEquals(mutableUniversity.GetDepartments().size(), 1, "University SetDepartments failed");
    Lab4Tests::CheckEquals(mutableUniversity.GetGroups().size(), 1, "University SetGroups failed");
    mutableUniversity.AddDepartment(Department("Chemistry"));
    mutableUniversity.AddGroup(Group("C-101", "Chemistry"));
    Lab4Tests::CheckEquals(mutableUniversity.GetDepartments().size(), 2, "University AddDepartment failed");
    Lab4Tests::CheckEquals(mutableUniversity.GetGroups().size(), 2, "University AddGroup failed");
}
