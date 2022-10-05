//-------------------------------------------------------------------------------------------
// Sort.h
// Description: Базовый класс для сортировок
// Date: 07.09.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <vector>
#include "../Input/KeyboardInput.h"

namespace Sorting 
{
class Sort : public Input::KeyboardInput
{

protected:
	// Разбиение строки на числа и их конвертация
	std::vector<double> Parse();


	int m_comparisons = 0;	// Количество сравнений
	int m_assignments = 0;	// Количество присваиваний
	int m_iterations = 0;	// Общее количество итераций

	std::vector<double> m_numbers;	// Массив для сортировки

public:
	Sort() = default;
	~Sort() = default;

	void Input() override;

	// Метод сортировки
	virtual void Sorting() = 0;

	// Вывод результата
	virtual void Output() const = 0;
};
}