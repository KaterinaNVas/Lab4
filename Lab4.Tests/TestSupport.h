/** @file
 * @brief Сравнение значений в модульных тестах.
 */

#pragma once

#include <functional>
#include <stdexcept>
#include <string>

namespace Lab4Tests
{
    /** @brief Проверяет совпадение хэшей и равенство значений.
     * @details Ожидаемое значение преобразуется к типу фактического. Совпадение
     * хэшей дополнительно проверяется сравнением самих значений из-за коллизий.
     * @tparam T Тип фактического значения, для которого определён std::hash.
     * @tparam Expected Тип ожидаемого значения, преобразуемого к T.
     * @param actual Фактическое значение.
     * @param expected Ожидаемое значение.
     * @return true, если оба значения равны и их хэши совпадают.
     */
    template <typename T, typename Expected>
    bool Equals(const T& actual, const Expected& expected)
    {
        const T expectedValue(expected);
        const std::hash<T> hash;
        return std::equal_to<>{}(hash(actual), hash(expectedValue))
            && std::equal_to<T>{}(actual, expectedValue);
    }

    /** @brief Проверяет фактическое значение через Equals.
     * @tparam T Тип фактического значения.
     * @tparam Expected Тип ожидаемого значения.
     * @param actual Фактическое значение.
     * @param expected Ожидаемое значение.
     * @param message Сообщение при несовпадении.
     * @throws std::runtime_error Если значения не совпали.
     */
    template <typename T, typename Expected>
    void CheckEquals(const T& actual, const Expected& expected, const std::string& message)
    {
        if (!Equals(actual, expected))
        {
            throw std::runtime_error(message);
        }
    }
}
