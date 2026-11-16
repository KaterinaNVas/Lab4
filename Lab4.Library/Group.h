/** @file
 * @brief Объявляет класс Group.
 */

#pragma once

#include <string>
#include <vector>
#include "LaboratoryWork.h"
#include "Student.h"
#include "Teacher.h"

namespace Lab4
{
    /** @brief Учебная группа со студентами, преподавателями и лабораторными работами.
     */
    class Group
    {
    public:
        /** @brief Создаёт группу с пустыми названием, специальностью и списками.
         */
        Group() = default;
        /** @brief Создаёт учебную группу.
         * @param groupName Название группы.
         * @param specialization Название специальности.
         * @param students Список студентов группы.
         * @param teachers Список преподавателей.
         * @param laboratoryWorks Лабораторные работы группы.
         */
        Group(
            const std::string& groupName,
            const std::string& specialization,
            const std::vector<Student>& students = {},
            const std::vector<Teacher>& teachers = {},
            const std::vector<LaboratoryWork>& laboratoryWorks = {}
        );

        /** @brief Предоставляет название группы.
         * @return Константная ссылка на название группы.
         */
        const std::string& GetGroupName() const;
        /** @brief Предоставляет название специальности.
         * @return Константная ссылка на название специальности.
         */
        const std::string& GetSpecialization() const;
        /** @brief Предоставляет список студентов группы.
         * @return Константная ссылка на список студентов группы.
         */
        const std::vector<Student>& GetStudents() const;
        /** @brief Предоставляет основной список преподавателей группы.
         * @return Константная ссылка на список. Преподаватели лабораторных хранятся в записях этих работ.
         */
        const std::vector<Teacher>& GetTeachers() const;

        /** @brief Предоставляет список лабораторных работ группы.
         * @return Константная ссылка на список лабораторных работ группы.
         */
        const std::vector<LaboratoryWork>& GetLaboratoryWorks() const;

        /** @brief Заменяет название группы.
         * @param groupName Название группы.
         */
        void SetGroupName(const std::string& groupName);
        /** @brief Заменяет название специальности.
         * @param specialization Название специальности.
         */
        void SetSpecialization(const std::string& specialization);
        /** @brief Заменяет список студентов.
         * @param students Список студентов группы.
         */
        void SetStudents(const std::vector<Student>& students);
        /** @brief Заменяет список преподавателей.
         * @param teachers Список преподавателей.
         */
        void SetTeachers(const std::vector<Teacher>& teachers);

    private:
        /** @brief Название группы.
         */
        std::string groupName_;
        /** @brief Название специальности.
         */
        std::string specialization_;
        /** @brief Список студентов группы.
         */
        std::vector<Student> students_;
        /** @brief Список преподавателей.
         */
        std::vector<Teacher> teachers_;
        /** @brief Лабораторные работы группы.
         */
        std::vector<LaboratoryWork> laboratoryWorks_;
    };
}
