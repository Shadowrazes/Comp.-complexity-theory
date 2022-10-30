//-------------------------------------------------------------------------------------------
// SimpleMultipl.h
// Description: Класс для реализации умножения чисел столбиком
// Date: 30.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include "../Input/KeyboardInput.h"
#include "Multiplication.h"
#include <vector>

namespace Multiplication
{
class SimpleMultipl : public Multiplication
{
public:
	SimpleMultipl() = default;
	virtual  ~SimpleMultipl() = default;

	void Process() override;
};
}