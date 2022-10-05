#include "Fourier.h"
#include <iomanip>

namespace Fourier
{
void Fourier::Input()
{
    std::cout << "Input array: ";
    std::string a, b;
    while (std::cin >> a >> b)
    {
        if (KeyboardInput::IsDigits(2, a, b))
        {
            std::complex<double> c(std::stod(a), std::stod(b));
            m_complexList.push_back(c);
        }
            
        if (std::cin.get() == '\n') return;
    }
}
//------------------------------------------------------------
void Fourier::Output() const
{
    std::cout << std::fixed << std::setprecision(10);
    for (const auto& num : m_complexList)
        std::cout << num << " ";

    std::cout << std::endl;
}
//------------------------------------------------------------
void Fourier::Output(const std::string& msg) const
{
    std::cout << "\n" << msg << std::endl;
    Output();
}
//------------------------------------------------------------
}