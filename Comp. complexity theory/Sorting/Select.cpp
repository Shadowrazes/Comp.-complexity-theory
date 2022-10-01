#include "Select.h"

#include <algorithm>

namespace Sorting 
{
void Select::Sorting() 
{
    int minInd;
    for (int i = 0; i < m_numbers.size() - 1; i++)
    {
        minInd = i;
        for (int j = i + 1; j < m_numbers.size(); j++) 
        {
            if (m_numbers[j] < m_numbers[minInd]) 
            {
                minInd = j;
                m_assignments++;
            }
            m_comparisons++;
        }

        if (minInd != i) 
        {
            std::swap(m_numbers[i], m_numbers[minInd]);
            m_assignments += 3;
        }
        m_comparisons++;
    }

    m_iterations = m_comparisons + m_assignments;
}
//---------------------------------------------------------------------------
void Select::Output() const 
{
    for (const auto& num : m_numbers) 
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;
    std::cout << "Comparisons: " << m_comparisons << std::endl
        << "Assignments: " << m_assignments << std::endl
        << "Iterations: " << m_iterations << std::endl;

    std::cout << std::endl << "-------------------------------------------" << std::endl;
}
//---------------------------------------------------------------------------
}