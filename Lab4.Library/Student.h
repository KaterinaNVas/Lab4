#pragma once

#include <string>

namespace Lab4
{
    class Student 
    {
        public:

            Student(const Student& other);
            Student& operator=(const Student& other);
            Student (Student&& other) noexcept;
            Student& operator=(Student&& other) noexcept;
            explicit Student(const std::string& name, const std::string& surname, const std::string& patronymic, int age, const std::string& creditBookNumber, const std::string& groupName, const std::string& specialization);
            ~Student() = default;


            const std::string& GetName() const;
            const std::string& GetSurname() const;
            const std::string& GetPatronymic() const;
            int GetAge() const;
            const std::string& GetCreditBookNumber() const;
            const std::string& GetGroupName() const;
            const std::string& GetSpecialization() const;

        private:
            std::string name_;
            std::string surname_;
            std::string patronymic_;
            int age_;
            std::string creditBookNumber_;
            std::string groupName_;
            std::string specialization_;
            
    };
}