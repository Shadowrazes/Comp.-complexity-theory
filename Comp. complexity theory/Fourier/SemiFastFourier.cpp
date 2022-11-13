#define _USE_MATH_DEFINES

#include "SemiFastFourier.h"

namespace Fourier 
{
//-----------------------------------------------------------------
void SemiFastFourier::Input()
{
    std::cout << "Input m_p1 and m_p2: ";
    std::cin >> m_p1 >> m_p2;

    Fourier::Input();
}
//-----------------------------------------------------------------
void SemiFastFourier::DirectSFFT()
{
    //std::cout << "\nDirect SFFT\n";
   
    std::vector<std::complex<double>> arrayA1(m_complexList.size());
    std::vector<std::complex<double>> arrayA2(m_complexList.size());

    double tempReal;
    double tempImag;

    for (int j2 = 0; j2 < m_p2; j2++)
    {
        for (int k1 = 0; k1 < m_p1; k1++)
        {
            int ind = k1 + m_p1 * j2;
            tempReal = 0;
            tempImag = 0;

            for (int j1 = 0; j1 < m_p1; j1++)
            {
                double degree = (2 * M_PI * j1 * k1) / m_p1;
                std::complex<double> neededElem = m_complexList[j2 + m_p2 * j1];

                tempReal += neededElem.real() * cos(degree) + neededElem.imag() * sin(degree);
                tempImag += neededElem.imag() * cos(degree) - neededElem.real() * sin(degree);
                m_complexity += 5;
            }

            std::complex<double> result(tempReal, tempImag);
            arrayA1[ind] = result / static_cast<double>(m_p1);
        }
    }

    for (int k2 = 0; k2 < m_p2; k2++) 
    {
        for (int k1 = 0; k1 < m_p1; k1++) 
        {
            int ind = k1 + m_p1 * k2;
            tempReal = 0;
            tempImag = 0;

            for (int j2 = 0; j2 < m_p2; j2++) 
            {
                double degree = (2 * M_PI * j2 * ind) / m_complexList.size();
                std::complex<double> neededElem = arrayA1[k1 + m_p1 * j2];

                tempReal += neededElem.real() * cos(degree) + neededElem.imag() * sin(degree);
                tempImag += neededElem.imag() * cos(degree) - neededElem.real() * sin(degree);
                m_complexity += 5;
            }

            std::complex<double> result(tempReal, tempImag);
            arrayA2[ind] = result / static_cast<double>(m_p2);
            
            //std::cout << "x[" << ind << "] " << arrayA2[ind].real() << " + " << arrayA2[ind].imag() << "i" << std::endl;
        }
    }

    m_complexList = arrayA2;
}
//-----------------------------------------------------------------
void SemiFastFourier::ReverseSFFT()
{
    //std::cout << "\nReverse SFFT\n";
    
    std::vector<std::complex<double>> arrayA1(m_complexList.size());
    std::vector<std::complex<double>> arrayA2(m_complexList.size());

    double tempReal;
    double tempImag;

    for (int j2 = 0; j2 < m_p2; j2++)
    {
        for (int k1 = 0; k1 < m_p1; k1++)
        {
            int ind = k1 + m_p1 * j2;
            tempReal = 0;
            tempImag = 0;

            for (int j1 = 0; j1 < m_p1; j1++)
            {
                double degree = (2 * M_PI * j1 * k1) / m_p1;
                std::complex<double> neededElem = m_complexList[j2 + m_p2 * j1];

                tempReal += neededElem.real() * cos(degree) - neededElem.imag() * sin(degree);
                tempImag += neededElem.imag() * cos(degree) + neededElem.real() * sin(degree);
                m_complexity += 5;
            }

            arrayA1[ind] = std::complex<double>(tempReal, tempImag);
        }
    }

    for (int k2 = 0; k2 < m_p2; k2++)
    {
        for (int k1 = 0; k1 < m_p1; k1++)
        {
            int ind = k1 + m_p1 * k2;
            tempReal = 0;
            tempImag = 0;

            for (int j2 = 0; j2 < m_p2; j2++)
            {
                double degree = (2 * M_PI * j2 * ind) / m_complexList.size();
                std::complex<double> neededElem = arrayA1[k1 + m_p1 * j2];

                tempReal += neededElem.real() * cos(degree) - neededElem.imag() * sin(degree);
                tempImag += neededElem.imag() * cos(degree) + neededElem.real() * sin(degree);
                m_complexity += 5;
            }

            arrayA2[ind] = std::complex<double>(tempReal, tempImag);

            //std::cout << "x[" << ind << "] " << arrayA2[ind].real() << " + " << arrayA2[ind].imag() << "i" << std::endl;
        }
    }

    m_complexList = arrayA2;
}
//-----------------------------------------------------------------
}