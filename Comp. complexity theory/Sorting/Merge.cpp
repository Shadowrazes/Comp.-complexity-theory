#include "Merge.h"

#include <algorithm>

void Sorting::Merge::Sorting() {
    int mid = m_numbers.size() / 2;

    if (m_numbers.size() % 2 == 1)
        mid++;

    int h = 1; // ���
    int step;

    while (h < m_numbers.size())
    {
        step = h;

        int i = 0;   // ������ ������� ����
        int j = mid; // ������ ������� ����

        while (step <= mid)
        {
            while ((i < step) && (j < m_numbers.size()) && (j < (mid + step)))
            { // ���� �� ����� �� ����� ����
              // ��������� ��������� ������� ����������� ������������������
              // ������� �� ���� ���������������
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
            { // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                m_tempChain.push_back(m_numbers[i]);
                i++;
            }
            while ((j < (mid + step)) && (j < m_numbers.size()))
            {  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                m_tempChain.push_back(m_numbers[j]);
                j++;
            }
            step = step + h; // ��������� � ���������� �����
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