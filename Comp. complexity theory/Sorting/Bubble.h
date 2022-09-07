// Класс, реализующий сортировку методом пузырька

#pragma once

#include "Sort.h"

namespace Sorting {
	class Bubble : public Sort {
	public:
		Bubble(const std::vector<int>& numbers) : Sort(numbers) {}

		void Sorting() override;
		void Output() const override;
	};
}
