#include "SemiFastFourierFolding.h"
#include <iomanip>

namespace Folding {
//-----------------------------------------------------------------
void SemiFastFourierFolding::Fold() {
    m_result.clear();
    int N = m_firstComplexList.size() > m_secondComplexList.size() ? m_firstComplexList.size() : m_secondComplexList.size();

    while (m_firstComplexList.size() < N * 2)
        m_firstComplexList.emplace_back(0, 0);

    while (m_secondComplexList.size() < N * 2)
        m_secondComplexList.emplace_back(0, 0);

    Fourier::SemiFastFourier semiFastFourier;
    semiFastFourier.SetP(2, N);
    semiFastFourier.SetArray(m_firstComplexList);
    semiFastFourier.DirectSFFT();
    m_firstComplexList = semiFastFourier.GetArray();

    semiFastFourier.SetArray(m_secondComplexList);
    semiFastFourier.DirectSFFT();
    m_secondComplexList = semiFastFourier.GetArray();

    for (int i = 0; i < 2 * N; i++)
    {
        std::complex<double> tempRes = m_firstComplexList[i] * m_secondComplexList[i] * static_cast<double>(2 * N);
        m_result.push_back(tempRes);
        m_operationCount += 2;
    }

    semiFastFourier.SetArray(m_result);
    semiFastFourier.ReverseSFFT();
    m_operationCount += semiFastFourier.GetComplexity();
    m_result = semiFastFourier.GetArray();
}
//-----------------------------------------------------------------
void SemiFastFourierFolding::Output() const {
    //Folding::Output();

    std::cout << std::fixed << std::setprecision(3) << "Result: ";
    for (const auto& num : m_result)
        std::cout << num.real() << " ";

    std::cout << std::endl << std::endl;
}
//-----------------------------------------------------------------
void SemiFastFourierFolding::Output(const std::string& msg) const {
    std::cout << "\n" << msg << std::endl;
    Output();
}
//-----------------------------------------------------------------
}
