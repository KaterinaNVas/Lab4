/** @file
 * @brief Консольное меню и демонстрационные данные вуза.
 */

#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

#include "Department.h"
#include "Group.h"
#include "LaboratoryWork.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "University.h"

namespace Lab4
{
	/** @brief Читает строку из стандартного ввода.
	 * @details При прямом вводе в консоли Windows читает UTF-16 и преобразует его в UTF-8.
	 * @param[out] value Прочитанная строка без перевода строки.
	 * @return true, если строка прочитана, иначе false.
	 */
	bool ReadInputLine(std::string& value)
	{
#ifdef _WIN32
		const HANDLE input = GetStdHandle(STD_INPUT_HANDLE);
		DWORD mode = 0;
		if (GetConsoleMode(input, &mode))
		{
			std::wstring line;
			wchar_t buffer[256];
			DWORD count = 0;
			do
			{
				if (!ReadConsoleW(input, buffer, 256, &count, nullptr) || count == 0)
				{
					return false;
				}
				line.append(buffer, count);
			}
			while (line.back() != L'\n');

			line.pop_back();
			if (!line.empty() && line.back() == L'\r')
			{
				line.pop_back();
			}
			if (!line.empty() && line.front() == L'\x1a')
			{
				return false;
			}

			const int length = static_cast<int>(line.size());
			const int bytes = WideCharToMultiByte(
				CP_UTF8, 0, line.data(), length, nullptr, 0, nullptr, nullptr);
			value.resize(bytes);
			if (bytes > 0)
			{
				WideCharToMultiByte(
					CP_UTF8, 0, line.data(), length, value.data(), bytes, nullptr, nullptr);
			}
			return true;
		}
#endif
		return static_cast<bool>(std::getline(std::cin, value));
	}

	/** @brief Выводит приглашение и читает строку.
	 * @param prompt Текст приглашения.
	 * @return Введённая строка. При завершении ввода возвращается пустая строка.
	 */
	std::string ReadLine(const std::string& prompt)
	{
		std::cout << prompt << std::flush;
		std::string value;
		ReadInputLine(value);
		return value;
	}

	/** @brief Выводит доступные пункты меню.
	 */
	void PrintMenu()
	{
		std::cout << "\n=== Меню университета ===\n"
			<< "1. Найти студента по номеру зачётной книжки\n"
			<< "2. Найти студента по ФИО\n"
			<< "3. Показать дисциплины кафедры\n"
			<< "4. Показать преподавателей группы\n"
			<< "5. Показать группы по специальности\n"
			<< "6. Показать студентов и преподавателей\n"
			<< "0. Выход\n"
			<< "Выберите пункт: ";
	}
}

/** @brief Создаёт демонстрационные данные и запускает меню запросов к вузу.
 * @return Код завершения 0 после выхода из меню.
 */
int main()
{
	using namespace Lab4;

#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	const Teacher mathTeacher(
		"Ольга", "Петрова", "Сергеевна",
		{ "Математический анализ", "Линейная алгебра" });
	const Teacher programmingTeacher(
		"Павел", "Сидоров", "Андреевич",
		{ "Программирование", "Алгоритмы", "Лабораторная работа по физике" });
	const Teacher laboratoryTeacher(
		"Марина", "Волкова", "Игоревна",
		{ "Лабораторная работа по физике" });

	const Student firstStudent(
		"Иван", "Иванов", "Иванович", 19, "1001");
	const Student secondStudent(
		"Анна", "Смирнова", "Петровна", 20, "1002");
	const Student thirdStudent(
		"Иван", "Иванов", "Иванович", 21, "2001");

	const Department mathematicsDepartment(
		"Математика",
		{ "Математический анализ", "Линейная алгебра" },
		{ mathTeacher });
	const Department computerScienceDepartment(
		"Информатика",
		{ "Программирование", "Алгоритмы", "Лабораторная работа по физике" },
		{ programmingTeacher, laboratoryTeacher });

	const LaboratoryWork physicsLab(
		"Лабораторная работа по физике", programmingTeacher, laboratoryTeacher);

	const Group softwareGroup(
		"ПИ-101",
		"Программная инженерия",
		{ firstStudent, secondStudent },
		{ mathTeacher, programmingTeacher },
		{ physicsLab });
	const Group secondSoftwareGroup(
		"ПИ-102",
		"Программная инженерия",
		{ thirdStudent },
		{ programmingTeacher },
		{ physicsLab });
	const Group dataGroup(
		"АД-101",
		"Анализ данных",
		{},
		{ mathTeacher, programmingTeacher });

	const University university(
		{ mathematicsDepartment, computerScienceDepartment },
		{ softwareGroup, secondSoftwareGroup, dataGroup });

	std::vector<std::unique_ptr<const Person>> people;
	people.push_back(std::make_unique<Student>(firstStudent));
	people.push_back(std::make_unique<Teacher>(programmingTeacher));

	while (true)
	{
		PrintMenu();
		std::cout << std::flush;
		std::string line;
		if (!ReadInputLine(line))
		{
			break;
		}

		std::istringstream input(line);
		int choice = 0;
		char extra = '\0';
		if (!(input >> choice) || (input >> extra))
		{
			std::cout << "Введите номер пункта меню.\n";
			continue;
		}

		if (choice == 0)
		{
			break;
		}

		switch (choice)
		{
		case 1:
		{
			const std::string number = ReadLine("Номер зачётной книжки: ");
			const Student* student = university.FindStudentByCreditBookNumber(number);
			if (student)
			{
				std::cout << student->GetInfo() << '\n';
			}
			else
			{
				std::cout << "Студент не найден.\n";
			}
			break;
		}
		case 2:
		{
			const std::string surname = ReadLine("Фамилия: ");
			const std::string name = ReadLine("Имя: ");
			const std::string patronymic = ReadLine("Отчество: ");
			const std::vector<Student> students =
				university.FindStudentsByFullName(surname, name, patronymic);
			if (students.empty())
			{
				std::cout << "Студент не найден.\n";
			}
			else
			{
				for (const Student& student : students)
				{
					std::cout << student.GetInfo() << '\n';
				}
			}
			break;
		}
		case 3:
		{
			const std::string department = ReadLine("Название кафедры: ");
			const std::vector<std::string> courses = university.GetCoursesByDepartment(department);
			if (courses.empty())
			{
				std::cout << "Дисциплины для этой кафедры не найдены.\n";
			}
			else
			{
				for (const std::string& course : courses)
				{
					std::cout << "  - " << course << '\n';
				}
			}
			break;
		}
		case 4:
		{
			const std::string groupName = ReadLine("Номер группы: ");
			const std::vector<Teacher> teachers = university.GetTeachersByGroup(groupName);
			if (teachers.empty())
			{
				std::cout << "Преподаватели для этой группы не найдены.\n";
			}
			else
			{
				for (const Teacher& teacher : teachers)
				{
					std::cout << "  " << teacher.GetInfo() << '\n';
				}
			}
			break;
		}
		case 5:
		{
			const std::string specialization = ReadLine("Название специальности: ");
			const std::vector<Group> groups = university.GetGroupsBySpecialization(specialization);
			if (groups.empty())
			{
				std::cout << "Группы по этой специальности не найдены.\n";
			}
			else
			{
				for (const Group& group : groups)
				{
					std::cout << "  " << group.GetGroupName() << '\n';
				}
			}
			break;
		}
		case 6:
			for (const std::unique_ptr<const Person>& person : people)
			{
				std::cout << "  " << person->GetInfo() << '\n';
			}
			break;
		default:
			std::cout << "Выберите пункт от 0 до 6.\n";
			break;
		}
	}

	std::cout << "До свидания!\n";
	return 0;
}
