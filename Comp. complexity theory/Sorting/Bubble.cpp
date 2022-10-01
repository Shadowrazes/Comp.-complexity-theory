#include "Bubble.h"
#include <algorithm>

namespace Sorting {
void Bubble::Sorting() {
    for (int i = 0; i < m_numbers.size(); i++) {
        for (int j = 0; j < m_numbers.size() - (i + 1); j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
                std::swap(m_numbers[j], m_numbers[j + 1]);
                m_assignments += 3;
            }
            m_comparisons++;
        }
    }

    m_iterations = m_comparisons + m_assignments;
}
//---------------------------------------------------------------------------
void Bubble::Output() const {
    for (const auto& num : m_numbers) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
    std::cout << "Comparisons: " << m_comparisons << std::endl
              << "Assignments: " << m_assignments << std::endl
              << "Iterations: "  << m_iterations  << std::endl;

    std::cout << std::endl << "-------------------------------------------" << std::endl;
}
//---------------------------------------------------------------------------
}