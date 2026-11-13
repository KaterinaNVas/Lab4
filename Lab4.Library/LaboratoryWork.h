/** @file
 * @brief Объявляет класс LaboratoryWork.
 */

#pragma once

#include <array>
#include <string>

#include "Teacher.h"

namespace Lab4
{
    /** @brief Лабораторная работа по дисциплине, которую ведут два преподавателя.
     */
    class LaboratoryWork
    {
    public:
        /** @brief Назначает двух преподавателей на лабораторную работу.
         * @param course Название дисциплины.
         * @param firstTeacher Первый преподаватель.
         * @param secondTeacher Второй преподаватель.
         * @throws std::invalid_argument Если переданы две записи об одном преподавателе с одинаковым ID.
         */
        LaboratoryWork(
            const std::string& course,
            const Teacher& firstTeacher,
            const Teacher& secondTeacher
        );

        /** @brief Предоставляет название дисциплины.
         * @return Константная ссылка на название дисциплины.
         */
        const std::string& GetCourse() const;
        /** @brief Предоставляет пару преподавателей лабораторной работы.
         * @return Константная ссылка на массив из двух преподавателей.
         */
        const std::array<Teacher, 2>& GetTeachers() const;

    private:
        /** @brief Название дисциплины.
         */
        std::string course_;
        /** @brief Два преподавателя лабораторной работы.
         */
        std::array<Teacher, 2> teachers_;
    };
}
