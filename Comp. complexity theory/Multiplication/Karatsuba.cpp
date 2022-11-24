#include "Karatsuba.h"
#include <algorithm>

namespace Multiplication
{
std::vector<int> Karatsuba::SimpleMulti(const std::vector<int>& firstNum, const std::vector<int>& secondNum) {
    std::vector<int> result(2 * firstNum.size());
        
    for (auto i = 0; i < firstNum.size(); ++i) {
        for (auto j = 0; j < firstNum.size(); ++j) {
            result[i + j] += firstNum[i] * secondNum[j];
            if(firstNum[i] * secondNum[j] != 0)
                m_operationCount++;
        }
    }
        
    return result;
}

std::vector<int> Karatsuba::Process(const std::vector<int>& firstNum, const std::vector<int>& secondNum)
{
    int len = firstNum.size();
    std::vector<int> result(2 * len);

    if (len <= 1) {
        return SimpleMulti(firstNum, secondNum);
    }

    auto k = len / 2;

    std::vector<int> firstNumRight{ firstNum.begin(), firstNum.begin() + k };
    std::vector<int> firstNumLeft{ firstNum.begin() + k, firstNum.end() };
    std::vector<int> secondNumRight{ secondNum.begin(), secondNum.begin() + k };
    std::vector<int> secondNumLeft{ secondNum.begin() + k, secondNum.end() };

    std::vector<int> part1 = Process(firstNumLeft, secondNumLeft);
    std::vector<int> part2 = Process(firstNumRight, secondNumRight);

    std::vector<int> firstNumLR(k);
    std::vector<int> secondNumLR(k);

    for (int i = 0; i < k; ++i) {
        firstNumLR[i] = firstNumLeft[i] + firstNumRight[i];
        secondNumLR[i] = secondNumLeft[i] + secondNumRight[i];
    }

    std::vector<int> part3 = Process(firstNumLR, secondNumLR);

    for (auto i = 0; i < len; ++i) {
        part3[i] -= part2[i] + part1[i];
    }

    for (auto i = 0; i < len; ++i) {
        result[i] = part2[i];
    }

    for (auto i = len; i < 2 * len; ++i) {
        result[i] = part1[i - len];
    }

    for (auto i = k; i < len + k; ++i) {
        result[i] += part3[i - k];
    }

    return result;
}
//----------------------------------------------------
void Karatsuba::Normalize(int &addedZeroes) {
    m_result = std::vector<int>{ m_result.begin() + addedZeroes, m_result.end() };

    for (auto i = 0; i < m_result.size() - 1; ++i) {
        m_result[i + 1] += m_result[i] / m_digitCapacity;
        m_result[i] %= m_digitCapacity;
    }
    std::reverse(m_result.begin(), m_result.end());

    auto it = m_result.begin();
    while (*it == 0)
        it++;

    m_result = std::vector<int>{ it, m_result.end() };
}

void Karatsuba::Process() {
    int maxSize = m_firstNumber.size() > m_secondNumber.size() ? m_firstNumber.size() : m_secondNumber.size();
    int addedZeroes = 0;
    if (maxSize % 2 == 1)
        maxSize++;

    for (int i = m_firstNumber.size(); i < maxSize; i++) {
        m_firstNumber.push_back(0);
        addedZeroes++;
    }

    for (int i = m_secondNumber.size(); i < maxSize; i++) {
        m_secondNumber.push_back(0);
        addedZeroes++;
    }

    std::reverse(m_firstNumber.begin(), m_firstNumber.end());
    std::reverse(m_secondNumber.begin(), m_secondNumber.end());

    m_result = Process(m_firstNumber, m_secondNumber);

    Normalize(addedZeroes);
}
}

