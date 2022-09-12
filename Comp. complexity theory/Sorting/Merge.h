﻿//-------------------------------------------------------------------------------------------
// Description: Класс, реализующий сортировку методом слияния
// Date: 07.09.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include "Sort.h"

namespace Sorting {
	class Merge : public Sort {
	public:
		Merge(const std::vector<double>& numbers) : Sort(numbers) {}

		void Sorting() override;
		void Output() const override;
	};
}