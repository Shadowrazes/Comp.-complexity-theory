// ������� ����� ��� ����������

#pragma once

#include <iostream>
#include <vector>

namespace Sorting {
	class Sort {

	protected:
		int m_comparisons = 0;	// ���������� ���������
		int m_assignments = 0;	// ���������� ������������
		int m_iterations = 0;	// ����� ���������� ��������

		std::vector<int> m_numbers = {};	// ������ ��� ����������

	public:
		Sort(const std::vector<int>& numbers) : m_numbers(numbers) {}
		~Sort() = default;

		// ����� ����������
		virtual void Sorting() = 0;

		// ����� ����������
		virtual void Output() const = 0;
	};
}