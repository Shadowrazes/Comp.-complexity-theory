#include "Merge.h"

#include <algorithm>

namespace Sorting 
{
void Merge::Sorting() 
{
    int sectionSize = 1;        // Размер сравниваемых подмассивов [1, 2, 4, ... m_numbers.size()]
    std::vector<double> temp;

    while (sectionSize < m_numbers.size())
    {
        temp.clear();

        int leftBorderIdx = 0;                                  // Левая граница подмассива
        int middleIdx = leftBorderIdx + sectionSize;            // Середина подмассива
        int rightBorderIdx = leftBorderIdx + sectionSize * 2;   // Правая граница подмассива

        do
        {
            // Сортируемый подмассив не должен выходить за границы последовательности
            middleIdx = middleIdx < m_numbers.size() ? middleIdx : m_numbers.size();
            rightBorderIdx = rightBorderIdx < m_numbers.size() ? rightBorderIdx : m_numbers.size();

            // Индексы сравниваемых элементов
            int leftCurrentNumIdx = leftBorderIdx,
                rightCurrentNumIdx = middleIdx;

            // Заполняем результирующий массив, пока левый элемент не дошёл до середины и правый не дошёл до конца
            for (; leftCurrentNumIdx < middleIdx && rightCurrentNumIdx < rightBorderIdx; )
            {
                if (m_numbers[leftCurrentNumIdx] < m_numbers[rightCurrentNumIdx])
                    temp.push_back(m_numbers[leftCurrentNumIdx++]);
                else
                    temp.push_back(m_numbers[rightCurrentNumIdx++]);
                m_comparisons++;
                m_assignments++;
            }

            // Заносим оставшиеся элементы сортируемых подмассивов в результирующий массив
            while (leftCurrentNumIdx < middleIdx) 
            {
                temp.push_back(m_numbers[leftCurrentNumIdx++]);
                m_assignments++;
            }

            while (rightCurrentNumIdx < rightBorderIdx) 
            {
                temp.push_back(m_numbers[rightCurrentNumIdx++]);
                m_assignments++;
            }

            // Перемещение на следующий сортируемый участок
            leftBorderIdx += sectionSize * 2;
            middleIdx += sectionSize * 2;
            rightBorderIdx += sectionSize * 2;

        } while (leftBorderIdx < m_numbers.size());

        m_numbers = temp;
        sectionSize *= 2; // Шаг разбиения х2

        for (const auto& num : m_numbers) 
        {
            std::cout << num << " ";
        }
        std::cout << std::endl << std::endl;
    }

    m_iterations = m_comparisons + m_assignments;
}
//---------------------------------------------------------------------------
void Merge::Output() const 
{
    std::cout << std::endl;
    std::cout << "Comparisons: " << m_comparisons << std::endl
        << "Assignments: " << m_assignments << std::endl
        << "Iterations: " << m_iterations << std::endl;

    std::cout << std::endl << "-------------------------------------------" << std::endl;
}
//---------------------------------------------------------------------------
}