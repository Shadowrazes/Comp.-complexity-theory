// Базовый класс для сортировок

#pragma once

#include <iostream>
#include <vector>

namespace Sorting {
	class Sort {

	protected:
		int m_comparisons = 0;	// Количество сравнений
		int m_assignments = 0;	// Количество присваиваний
		int m_iterations = 0;	// Общее количество итераций

		std::vector<double> m_numbers = {};	// Массив для сортировки

	public:
		Sort(const std::vector<double>& numbers) : m_numbers(numbers) {}
		~Sort() = default;

		// Метод сортировки
		virtual void Sorting() = 0;

		// Вывод результата
		virtual void Output() const = 0;
	};
}