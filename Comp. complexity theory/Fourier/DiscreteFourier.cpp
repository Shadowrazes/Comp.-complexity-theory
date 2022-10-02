#include "DiscreteFourier.h"
#include <cmath>
#include <complex>

const double pi = 3.141592653589793;

namespace Fourier
{
void DiscreteFourier::DirectDFT()
{
    std::cout << "\nDirect DPF\n";
    std::vector<std::complex<double>> tempComplexList;
    double tempReal;
    double tempImag;
    for (int i = 0; i < m_complexList.size(); i++)
    { // i = j
        tempReal = 0;
        tempImag = 0;
        for (int j = 0; j < m_complexList.size(); j++)
        { // j = k
            double expDegree = (2 * pi * j * i) / m_complexList.size(); // 2*pi*k*j/N
            // ( validArray + i * imaginaryArray ) * ( cos ( 2*pi*k*j/N ) - i * sin( 2*pi*k*j/N ) )
            tempReal += m_complexList[j].real() * cos(expDegree) - m_complexList[j].imag() * sin(expDegree);
            tempImag += - m_complexList[j].real() * sin(expDegree) + m_complexList[j].imag() * cos(expDegree);
        }
        // 1/N
        tempImag /= m_complexList.size();
        tempReal /= m_complexList.size();
        std::cout << "x[" << i << "] " << tempReal << " + " << tempImag << "i" << std::endl;
        tempComplexList.emplace_back(tempReal, tempImag);
    }
    m_complexList = tempComplexList;
}
//-----------------------------------------------------------------
void DiscreteFourier::ReverseDFT()
{
    std::cout << "\nReverse DPF\n";
    std::vector<std::complex<double>> tempComplexList;
    double tempReal;
    double tempImag;
    for (int i = 0; i < m_complexList.size(); i++)
    { // i = j
        tempReal = 0;
        tempImag = 0;
        for (int j = 0; j < m_complexList.size(); j++)
        { // j = k
            double expDegree = (2 * pi * j * i) / m_complexList.size(); // 2*pi*k*j/N
            // ( validArray + i * imaginaryArray ) * ( cos ( 2*pi*k*j/N ) + i * sin( 2*pi*k*j/N ) )
            tempReal += m_complexList[j].real() * cos(expDegree) + m_complexList[j].imag() * sin(expDegree);
            tempImag += m_complexList[j].real() * sin(expDegree) + m_complexList[j].imag() * cos(expDegree);
        }
        std::cout << "x[" << i << "] " << tempReal << " + " << tempImag << "i" << std::endl;
        tempComplexList.emplace_back(tempReal, tempImag);
    }
    m_complexList = tempComplexList;
}
//-----------------------------------------------------------------
}