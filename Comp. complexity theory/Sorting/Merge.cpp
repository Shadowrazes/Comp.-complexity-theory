#include "Merge.h"

#include <algorithm>

void Sorting::Merge::Sorting() {
    int mid = m_numbers.size() / 2;

    if (m_numbers.size() % 2 == 1)
        mid++;

    int h = 1; // шаг
    int step;

    while (h < m_numbers.size())
    {
        step = h;

        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути

        while (step <= mid)
        {
            while ((i < step) && (j < m_numbers.size()) && (j < (mid + step)))
            { // пока не дошли до конца пути
              // заполняем следующий элемент формируемой последовательности
              // меньшим из двух просматриваемых
                if (m_numbers[i] < m_numbers[j])
                {
                    m_tempChain.push_back(m_numbers[i]);
                    i++;
                }
                else {
                    m_tempChain.push_back(m_numbers[j]);
                    j++;
                }
            }
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                m_tempChain.push_back(m_numbers[i]);
                i++;
            }
            while ((j < (mid + step)) && (j < m_numbers.size()))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                m_tempChain.push_back(m_numbers[j]);
                j++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        
        m_numbers.assign(m_tempChain.begin(), m_tempChain.end());
        m_tempChain.clear();
    }

    m_iterations = m_comparisons + m_assignments;
}
//---------------------------------------------------------------------------
void Sorting::Merge::Output() const {
    for (const auto& num : m_numbers) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
    std::cout << "Comparisons: " << m_comparisons << std::endl
        << "Assignments: " << m_assignments << std::endl
        << "Iterations: " << m_iterations << std::endl;
}