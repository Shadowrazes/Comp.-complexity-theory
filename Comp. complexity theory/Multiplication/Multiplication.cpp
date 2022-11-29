#include "Multiplication.h"
#include <iostream>
#include <string>

namespace Multiplication
{
void Multiplication::Input()
{
	std::cout << "Enter 2 numbers separated by a space: ";
    std::string str;
    std::vector<std::string> tempList;
    std::vector<int> nums;
    while (std::cin >> str)
    {
        if (KeyboardInput::IsDigits(1, str))
        {
            tempList.push_back(str);
            nums.push_back(std::stoi(str));
        }

        if (std::cin.get() == '\n' || tempList.size() >= 2) break;
    }

    for (const auto& el : tempList[0])
        m_firstNumber.push_back(el - '0');

    for (const auto& el : tempList[1])
        m_secondNumber.push_back(el - '0');

    /*while (nums[0] > 0) {
        m_firstNumber.push_back(nums[0] % 2);
        nums[0] /= 2;
    }

    while (nums[1] > 0) {
        m_secondNumber.push_back(nums[1] % 2);
        nums[1] /= 2;
    }

    std::reverse(m_firstNumber.begin(), m_firstNumber.end());
    std::reverse(m_secondNumber.begin(), m_secondNumber.end());*/
}
//----------------------------------------------------------------
void Multiplication::Output()
{
    std::cout << "First num: ";
    for (const auto& el : m_firstNumber)
        std::cout << el;

    std::cout << std::endl;
    std::cout << "Second num: ";
    for (const auto& el : m_secondNumber)
        std::cout << el;

    std::cout << std::endl;
    std::cout << "Result: ";
    for (const auto& el : m_result)
        std::cout << el;

    std::cout << "\nOperations: " << GetOperationCount();

    std::cout << std::endl;
}
//----------------------------------------------------------------
}