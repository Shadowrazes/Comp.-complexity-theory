﻿//-------------------------------------------------------------------------------------------
// Description: Класс, реализующий сортировку методом пузырька
// Date: 07.09.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include "Sort.h"

namespace Sorting {
	class Bubble : public Sort {
	public:
		Bubble(const std::vector<double>& numbers) : Sort(numbers) {}

		void Sorting() override;
		void Output() const override;
	};
}
