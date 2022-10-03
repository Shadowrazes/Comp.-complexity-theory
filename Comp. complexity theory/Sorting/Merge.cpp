#include "Merge.h"

#include <algorithm>

namespace Sorting 
{
void Merge::Sorting() 
{
    int sectionSize = 1;        // ������ ������������ ����������� [1, 2, 4, ... m_numbers.size()]
    std::vector<double> temp;

    while (sectionSize < m_numbers.size())
    {
        temp.clear();

        int leftBorderIdx = 0;                                  // ����� ������� ����������
        int middleIdx = leftBorderIdx + sectionSize;            // �������� ����������
        int rightBorderIdx = leftBorderIdx + sectionSize * 2;   // ������ ������� ����������

        do
        {
            // ����������� ��������� �� ������ �������� �� ������� ������������������
            middleIdx = middleIdx < m_numbers.size() ? middleIdx : m_numbers.size();
            rightBorderIdx = rightBorderIdx < m_numbers.size() ? rightBorderIdx : m_numbers.size();

            // ������� ������������ ���������
            int leftCurrentNumIdx = leftBorderIdx,
                rightCurrentNumIdx = middleIdx;

            // ��������� �������������� ������, ���� ����� ������� �� ����� �� �������� � ������ �� ����� �� �����
            for (; leftCurrentNumIdx < middleIdx && rightCurrentNumIdx < rightBorderIdx; )
            {
                if (m_numbers[leftCurrentNumIdx] < m_numbers[rightCurrentNumIdx])
                    temp.push_back(m_numbers[leftCurrentNumIdx++]);
                else
                    temp.push_back(m_numbers[rightCurrentNumIdx++]);
                m_comparisons++;
                m_assignments++;
            }

            // ������� ���������� �������� ����������� ����������� � �������������� ������
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

            // ����������� �� ��������� ����������� �������
            leftBorderIdx += sectionSize * 2;
            middleIdx += sectionSize * 2;
            rightBorderIdx += sectionSize * 2;

        } while (leftBorderIdx < m_numbers.size());

        m_numbers = temp;
        sectionSize *= 2; // ��� ��������� �2

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