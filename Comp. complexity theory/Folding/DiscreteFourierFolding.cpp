#include "DiscreteFourierFolding.h"
#include <iomanip>

namespace Folding {
//-----------------------------------------------------------------
void DiscreteFourierFolding::Fold() {
    m_result.clear();
    int N = m_firstComplexList.size() > m_secondComplexList.size() ? m_firstComplexList.size() : m_secondComplexList.size();

    while (m_firstComplexList.size() < N * 2)
        m_firstComplexList.emplace_back(0, 0);

    while (m_secondComplexList.size() < N * 2)
        m_secondComplexList.emplace_back(0, 0);

    Fourier::DiscreteFourier discrFurier;
    discrFurier.SetArray(m_firstComplexList);
    discrFurier.DirectDFT();
    m_firstComplexList = discrFurier.GetArray();

    discrFurier.SetArray(m_secondComplexList);
    discrFurier.DirectDFT();
    m_secondComplexList = discrFurier.GetArray();

    for (int i = 0; i < 2 * N; i++)
    {
        double tempReal;
        double tempImag;
        tempReal = m_firstComplexList[i].real() * m_secondComplexList[i].real() - m_firstComplexList[i].imag() * m_secondComplexList[i].imag();
        tempImag = m_firstComplexList[i].real() * m_secondComplexList[i].imag() + m_firstComplexList[i].imag() * m_secondComplexList[i].real();
        tempReal *= 2 * N;
        tempImag *= 2 * N;
        m_result.emplace_back(tempReal, tempImag);
        m_operationCount += 2;
    }

    discrFurier.SetArray(m_result);
    discrFurier.ReverseDFT();
    m_operationCount += discrFurier.GetOperationCount();
    m_result = discrFurier.GetArray();
}
//-----------------------------------------------------------------
void DiscreteFourierFolding::Output() const {
    //Folding::Output();

    std::cout << std::fixed << std::setprecision(3) << "Result: ";
    for (const auto& num : m_result)
        std::cout << num.real() << " ";

    std::cout << std::endl << std::endl;
}
//-----------------------------------------------------------------
void DiscreteFourierFolding::Output(const std::string& msg) const {
    std::cout << "\n" << msg << std::endl;
    Output();
}
//-----------------------------------------------------------------
}
