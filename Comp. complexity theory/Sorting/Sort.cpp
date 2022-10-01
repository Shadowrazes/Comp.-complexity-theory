#include "Sort.h"
#include <iostream>
#include <vector>
#include <iostream>

namespace Sorting
{
void Sort::Input()
{
    while (true)
    {
        std::cout << "Input mass: ";

        // Чтение буфера потока ввода до конца, чтобы не было проблем с getline() (Очистка)
        std::cin.seekg(std::cin.eof());
        std::string input;
        while (std::cin >> input)
        {
            if (KeyboardInput::StringIsDigit(input))
                m_numbers.push_back(stod(input));
                
            if (std::cin.get() == '\n') return;
        }
    }
}
//-----------------------------------------------------------------
}