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

        // ������ ������ ������ ����� �� �����, ����� �� ���� ������� � getline() (�������)
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