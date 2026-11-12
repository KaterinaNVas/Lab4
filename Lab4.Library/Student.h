/** @file
 * @brief Объявляет класс Student.
 */

#pragma once

#include <string>
#include "Person.h"

namespace Lab4
{
    /** @brief Студент с возрастом и номером зачётной книжки.
     */
    class Student : public Person
    {
        public:

            /** @brief Создаёт объект копированием.
             * @param other Исходный объект.
             */
            Student(const Student& other) = default;
            /** @brief Присваивает данные копированием.
             * @param other Исходный объект.
             * @return Ссылка на текущий объект.
             */
            Student& operator=(const Student& other) = default;
            /** @brief Создаёт объект перемещением.
             * @param other Исходный объект.
             */
            Student(Student&& other) noexcept = default;
            /** @brief Присваивает данные перемещением.
             * @param other Исходный объект.
             * @return Ссылка на текущий объект.
             */
            Student& operator=(Student&& other) noexcept = default;
            /** @brief Создаёт студента с заданными ФИО, возрастом и номером зачётной книжки.
             * @param name Имя.
             * @param surname Фамилия.
             * @param patronymic Отчество.
             * @param age Возраст в полных годах.
             * @param creditBookNumber Номер зачётной книжки.
             */
            explicit Student(
                const std::string& name,
                const std::string& surname,
                const std::string& patronymic,
                int age,
                const std::string& creditBookNumber
            );
            /** @brief Освобождает ресурсы объекта.
             */
            ~Student() override = default;

            /** @brief Предоставляет возраст студента.
             * @return Возраст в полных годах.
             */
            int GetAge() const;
            /** @brief Предоставляет номер зачётной книжки.
             * @return Константная ссылка на номер зачётной книжки.
             */
            const std::string& GetCreditBookNumber() const;
            /** @brief Формирует текстовое описание.
             * @return Строка с ФИО, возрастом и номером зачётной книжки.
             */
            std::string GetInfo() const override;

            /** @brief Заменяет возраст.
             * @param age Возраст в полных годах.
             */
            void SetAge(int age);
            /** @brief Заменяет номер зачётной книжки.
             * @param creditBookNumber Номер зачётной книжки.
             */
            void SetCreditBookNumber(const std::string& creditBookNumber);

        private:
            /** @brief Возраст в полных годах.
             */
            int age_;
            /** @brief Номер зачётной книжки.
             */
            std::string creditBookNumber_;
            
    };
}
