// Класс, реализующий сортировку методом прямого выбора

#pragma once

#include "Sort.h"

namespace Sorting {
	class Select : public Sort {
	public:
		Select(const std::vector<double>& numbers) : Sort(numbers) {}

		void Sorting() override;
		void Output() const override;
	};
}