// Класс, реализующий сортировку методом слияния

#pragma once

#include "Sort.h"

namespace Sorting {
	class Merge : public Sort {
	public:
		Merge(const std::vector<int>& numbers) : Sort(numbers) {}

		void Sorting() override;
		void Output() const override;
	};
}