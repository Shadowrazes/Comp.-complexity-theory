#include "SimpleFolding.h"
#include <iomanip>

namespace Folding {
//-----------------------------------------------------------------
void SimpleFolding::Fold() {
    for (int i = 0; i < m_firstComplexList.size(); i++)
    {
        for (int j = 0; j < m_secondComplexList.size(); j++)
        {
            m_result[i + j] += m_firstComplexList[i] * m_secondComplexList[j];
            m_operationCount += 2;
        }
    }
}
//-----------------------------------------------------------------
void SimpleFolding::Output() const {
    Folding::Output();

    std::cout << std::fixed << std::setprecision(3) << "Result: ";
    for (const auto& num : m_result)
        std::cout << num.real() << " ";

    std::cout << std::endl << std::endl;
}
//-----------------------------------------------------------------
void SimpleFolding::Output(const std::string& msg) const {
    std::cout << "\n" << msg << std::endl;
    Output();
}
//-----------------------------------------------------------------
}