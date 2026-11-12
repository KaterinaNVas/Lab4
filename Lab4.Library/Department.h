/** @file
 * @brief Объявляет класс Department.
 */

#pragma once

#include <string>
#include <vector>
#include "Teacher.h"

namespace Lab4
{
    /** @brief Кафедра, её дисциплины и преподаватели.
     */
    class Department
    {
    public:
        /** @brief Создаёт кафедру с пустым названием и списками.
         */
        Department() = default;
        /** @brief Создаёт кафедру с заданными дисциплинами и преподавателями.
         * @param departmentName Название кафедры.
         * @param courses Список дисциплин.
         * @param teachers Список преподавателей.
         */
        explicit Department(
            const std::string& departmentName,
            const std::vector<std::string>& courses = {},
            const std::vector<Teacher>& teachers = {}
        );

        /** @brief Предоставляет название кафедры.
         * @return Константная ссылка на название кафедры.
         */
        const std::string& GetDepartmentName() const;
        /** @brief Предоставляет список дисциплин.
         * @return Константная ссылка на список дисциплин.
         */
        const std::vector<std::string>& GetCourses() const;
        /** @brief Предоставляет преподавателей кафедры.
         * @return Константная ссылка на список преподавателей кафедры.
         */
        const std::vector<Teacher>& GetTeachers() const;

        /** @brief Заменяет название кафедры.
         * @param departmentName Название кафедры.
         */
        void SetDepartmentName(const std::string& departmentName);
        /** @brief Заменяет список дисциплин.
         * @param courses Список дисциплин.
         */
        void SetCourses(const std::vector<std::string>& courses);
        /** @brief Заменяет список преподавателей.
         * @param teachers Список преподавателей.
         */
        void SetTeachers(const std::vector<Teacher>& teachers);

    private:
        /** @brief Название кафедры.
         */
        std::string departmentName_;
        /** @brief Список дисциплин.
         */
        std::vector<std::string> courses_;
        /** @brief Список преподавателей.
         */
        std::vector<Teacher> teachers_;
    };
}
