/** @file
 * @brief Объявляет класс University.
 */

#pragma once

#include <string>
#include <vector>
#include "Department.h"
#include "Group.h"

namespace Lab4
{
    /** @brief Кафедры и учебные группы вуза. Предоставляет запросы по этим данным.
     */
    class University
    {
    public:
        /** @brief Создаёт вуз без кафедр и групп.
         */
        University() = default;
        /** @brief Создаёт вуз с указанными кафедрами и группами.
         * @param departments Список кафедр.
         * @param groups Список учебных групп.
         */
        University(
            const std::vector<Department>& departments,
            const std::vector<Group>& groups
        );

        /** @brief Предоставляет список кафедр вуза.
         * @return Константная ссылка на список кафедр вуза.
         */
        const std::vector<Department>& GetDepartments() const;
        /** @brief Предоставляет список учебных групп.
         * @return Константная ссылка на список учебных групп.
         */
        const std::vector<Group>& GetGroups() const;

        /** @brief Заменяет список кафедр.
         * @param departments Список кафедр.
         */
        void SetDepartments(const std::vector<Department>& departments);
        /** @brief Заменяет список групп.
         * @param groups Список учебных групп.
         */
        void SetGroups(const std::vector<Group>& groups);
        /** @brief Добавляет кафедру в вуз.
         * @param department Добавляемая кафедра.
         */
        void AddDepartment(const Department& department);
        /** @brief Добавляет группу в вуз.
         * @param group Добавляемая группа.
         */
        void AddGroup(const Group& group);

        /** @brief Ищет студента по номеру зачётной книжки.
         * @param creditBookNumber Номер зачётной книжки.
         * @return Указатель на первого найденного студента или nullptr.
         * @warning Указатель относится к данным вуза. Его следует получать заново после изменения списка групп.
         */
        const Student* FindStudentByCreditBookNumber(const std::string& creditBookNumber) const;
        /** @brief Ищет всех студентов с указанным ФИО.
         * @param surname Фамилия.
         * @param name Имя.
         * @param patronymic Отчество.
         * @return Копии всех совпавших студентов. При отсутствии совпадений список пуст.
         */
        std::vector<Student> FindStudentsByFullName(
            const std::string& surname,
            const std::string& name,
            const std::string& patronymic
        ) const;
        /** @brief Ищет дисциплины указанной кафедры.
         * @param departmentName Название кафедры.
         * @return Копия списка дисциплин первой найденной кафедры или пустой список.
         */
        std::vector<std::string> GetCoursesByDepartment(const std::string& departmentName) const;
        /** @brief Собирает преподавателей указанной группы.
         * @param groupName Название группы.
         * @return Копия списка преподавателей первой найденной группы или пустой список.
         * @details Преподаватель лабораторной работы добавляется, если в списке ещё нет преподавателя с таким ID.
         */
        std::vector<Teacher> GetTeachersByGroup(const std::string& groupName) const;
        /** @brief Ищет все группы указанной специальности.
         * @param specialization Название специальности.
         * @return Копии всех совпавших групп. При отсутствии совпадений список пуст.
         */
        std::vector<Group> GetGroupsBySpecialization(const std::string& specialization) const;

    private:
        /** @brief Список кафедр.
         */
        std::vector<Department> departments_;
        /** @brief Список учебных групп.
         */
        std::vector<Group> groups_;
    };
}
