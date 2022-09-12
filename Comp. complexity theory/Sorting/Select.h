//-------------------------------------------------------------------------------------------
// Description: Класс, реализующий сортировку методом прямого выбора
// Date: 07.09.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

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