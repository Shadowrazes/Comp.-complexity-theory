#include "Folding.h"
#include <iomanip>

namespace Folding
{
void Folding::Input()
{
    std::cout << "Input first array: ";
    std::string a, b;
    while (std::cin >> a >> b)
    {
        if (KeyboardInput::IsDigits(2, a, b))
        {
            std::complex<double> c(std::stod(a), std::stod(b));
            m_firstComplexList.push_back(c);
        }
            
        if (std::cin.get() == '\n') break;
    }

    std::cout << "Input second array: ";
    while (std::cin >> a >> b)
    {
        if (KeyboardInput::IsDigits(2, a, b))
        {
            std::complex<double> c(std::stod(a), std::stod(b));
            m_secondComplexList.push_back(c);
        }

        if (std::cin.get() == '\n') break;
    }

    /*while (m_firstComplexList.size() > m_secondComplexList.size()) {
        m_secondComplexList.push_back(std::complex<double>(0, 0));
    }

    while (m_firstComplexList.size() < m_secondComplexList.size()) {
        m_firstComplexList.push_back(std::complex<double>(0, 0));
    }*/

    m_result = TComplexList(m_firstComplexList.size() + m_secondComplexList.size() - 1);
}
//------------------------------------------------------------
void Folding::Output() const
{
    std::cout << std::fixed << std::setprecision(3);
    for (const auto& num : m_firstComplexList)
        std::cout << num.real() << " ";

    std::cout << std::endl << std::endl;

    for (const auto& num : m_secondComplexList)
        std::cout << num.real() << " ";

    std::cout << std::endl << std::endl;
}
//------------------------------------------------------------
void Folding::Output(const std::string& msg) const
{
    std::cout << "\n" << msg << std::endl;
    Output();
}
//------------------------------------------------------------
}