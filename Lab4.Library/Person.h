/** @file
 * @brief Объявляет класс Person.
 */

#pragma once

#include <atomic>
#include <cstdint>
#include <string>

namespace Lab4
{
    /** @brief Абстрактный базовый класс студента и преподавателя. Хранит ФИО.
     */
    class Person
    {
    public:
        /** @brief Заполняет ФИО.
         * @param name Имя.
         * @param surname Фамилия.
         * @param patronymic Отчество.
         */
        Person(
            const std::string& name,
            const std::string& surname,
            const std::string& patronymic
        );
        /** @brief Создаёт объект копированием.
         */
        /// @brief Копирует данные и ID того же человека.
        Person(const Person&) = default;
        /** @brief Присваивает данные копированием.
         * @return Ссылка на текущий объект.
         */
        Person& operator=(const Person&) = default;
        /** @brief Создаёт объект перемещением.
        Person(Person&&) noexcept = default;
        /** @brief Присваивает данные перемещением.
         * @return Ссылка на текущий объект.
         */
        Person& operator=(Person&&) noexcept = default;
        /** @brief Освобождает ресурсы объекта.
         */
        virtual ~Person() = default;

        /** @brief Возвращает идентификатор человека в рамках запуска программы.
         * @return ID, общий для всех копий записи о человеке.
         */
        std::uint64_t GetId() const;

        /** @brief Предоставляет имя.
         * @return Константная ссылка на имя.
         */
        const std::string& GetName() const;
        /** @brief Предоставляет фамилию.
         * @return Константная ссылка на фамилию.
         */
        const std::string& GetSurname() const;
        /** @brief Предоставляет отчество.
         * @return Константная ссылка на отчество.
         */
        const std::string& GetPatronymic() const;
        /** @brief Сравнивает имя, фамилию и отчество.
         * @param other Человек, с которым выполняется сравнение.
         * @return true, если все три поля совпадают с учётом регистра.
         */
        bool HasSameFullName(const Person& other) const;
        /** @brief Формирует текстовое описание.
         * @return Строка с информацией об объекте. Формат определяет производный класс.
         */
        virtual std::string GetInfo() const = 0;

        /** @brief Заменяет имя.
         * @param name Имя.
         */
        void SetName(const std::string& name);
        /** @brief Заменяет фамилию.
         * @param surname Фамилия.
         */
        void SetSurname(const std::string& surname);
        /** @brief Заменяет отчество.
         * @param patronymic Отчество.
         */
        void SetPatronymic(const std::string& patronymic);

    private:
        /// @brief Общий счётчик ID для Person и всех его наследников.
        static std::atomic<std::uint64_t> nextId_;

        /// @brief Идентификатор записи о человеке.
        std::uint64_t id_;


        /** @brief Имя.
         */
        std::string name_;
        /** @brief Фамилия.
         */
        std::string surname_;
        /** @brief Отчество.
         */
        std::string patronymic_;
    };
}
