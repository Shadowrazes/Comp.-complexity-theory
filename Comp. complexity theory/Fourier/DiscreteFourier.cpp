#define _USE_MATH_DEFINES
#include "DiscreteFourier.h"
#include <algorithm>

namespace Fourier
{
void DiscreteFourier::DirectDFT()
{
    //std::cout << "\nDirect DPF\n";
    std::vector<std::complex<double>> tempComplexList;
    double tempReal;
    double tempImag;
    for (int i = 0; i < m_complexList.size(); i++)
    {
        tempReal = 0;
        tempImag = 0;
        for (int j = 0; j < m_complexList.size(); j++)
        {
            double expDegree = (2 * M_PI * j * i) / m_complexList.size(); // 2*M_PI*k*j/N
            tempReal += m_complexList[j].real() * cos(expDegree) - m_complexList[j].imag() * sin(expDegree);
            tempImag += - m_complexList[j].real() * sin(expDegree) + m_complexList[j].imag() * cos(expDegree);
            m_complexity += 5;
        }
        tempImag /= m_complexList.size();
        tempReal /= m_complexList.size();
        //std::cout << "x[" << i << "] " << tempReal << " + " << tempImag << "i" << std::endl;
        tempComplexList.emplace_back(tempReal, tempImag);
    }
    m_complexList = tempComplexList;
}
//-----------------------------------------------------------------
void DiscreteFourier::ReverseDFT()
{
    //std::cout << "\nReverse DPF\n";
    std::vector<std::complex<double>> tempComplexList;
    double tempReal;
    double tempImag;
    for (int i = 0; i < m_complexList.size(); i++)
    { // i = j
        tempReal = 0;
        tempImag = 0;
        for (int j = 0; j < m_complexList.size(); j++)
        { // j = k
            double expDegree = (2 * M_PI * j * i) / m_complexList.size();
            tempReal += m_complexList[j].real() * cos(expDegree) + m_complexList[j].imag() * sin(expDegree);
            tempImag += m_complexList[j].real() * sin(expDegree) + m_complexList[j].imag() * cos(expDegree);
            m_complexity += 5;
        }
        std::complex<double> result(tempReal, tempImag);
        tempComplexList.push_back(result);
    }
    tempComplexList.push_back(tempComplexList[0]);
    std::reverse(tempComplexList.begin(), tempComplexList.end());
    tempComplexList.pop_back();

    /*for (int i = 0; i < tempComplexList.size(); i++) {
        std::cout << "x[" << i << "] " << tempComplexList[i].real() << " + " << tempComplexList[i].imag() << "i" << std::endl;
    }*/

    m_complexList = tempComplexList;
}
//-----------------------------------------------------------------
}