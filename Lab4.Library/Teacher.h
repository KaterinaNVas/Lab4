/** @file
 * @brief Объявляет класс Teacher.
 */

#pragma once

#include <string>
#include <vector>
#include "Person.h"

namespace Lab4
{
    /** @brief Преподаватель со списком преподаваемых дисциплин.
     */
    class Teacher : public Person {

        public:

            /** @brief Создаёт объект копированием.
             * @param other Исходный объект.
             */
            Teacher(const Teacher& other) = default;
            /** @brief Присваивает данные копированием.
             * @param other Исходный объект.
             * @return Ссылка на текущий объект.
             */
            Teacher& operator=(const Teacher& other) = default;
            /** @brief Создаёт объект перемещением.
             * @param other Исходный объект.
             */
            Teacher(Teacher&& other) noexcept = default;
            /** @brief Присваивает данные перемещением.
             * @param other Исходный объект.
             * @return Ссылка на текущий объект.
             */
            Teacher& operator=(Teacher&& other) noexcept = default;
            /** @brief Создаёт преподавателя с заданными ФИО и дисциплинами.
             * @param name Имя.
             * @param surname Фамилия.
             * @param patronymic Отчество.
             * @param courses Список дисциплин.
             */
            explicit Teacher(
                const std::string& name,
                const std::string& surname,
                const std::string& patronymic,
                const std::vector<std::string>& courses
            );
            /** @brief Освобождает ресурсы объекта.
             */
            ~Teacher() override = default;

            /** @brief Предоставляет список дисциплин.
             * @return Константная ссылка на список дисциплин.
             */
            const std::vector<std::string>& GetCourses() const;
            /** @brief Формирует текстовое описание.
             * @return Строка с ФИО и списком дисциплин, если он заполнен.
             */
            std::string GetInfo() const override;

            /** @brief Заменяет список дисциплин.
             * @param courses Список дисциплин.
             */
            void SetCourses(const std::vector<std::string>& courses);

        private:
            /** @brief Список дисциплин.
             */
            std::vector<std::string> courses_;

    };

}
