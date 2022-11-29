//-------------------------------------------------------------------------------------------
// Karatsuba.h
// Description: Класс реализующий метод Карацубы (быстрое умножение)
// Date: 30.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include "../Input/KeyboardInput.h"
#include "Multiplication.h"
#include <vector>
#include <cmath>

namespace Multiplication
{
class Karatsuba : public Multiplication
{
public:
	Karatsuba(int digitCapacity = 10) { m_digitCapacity = digitCapacity; }
	virtual  ~Karatsuba() = default;

	void Process() override;
	std::vector<int> Process(const std::vector<int>& firstNum, const std::vector<int>& secondNum);

protected:
	void Normalize(int& addedZeroes);
	void Normalize() { m_operationCount = ceil(pow(m_numMaxSize, 1.56)); }
	std::vector<int> SimpleMulti(const std::vector<int>& firstNum, const std::vector<int>& secondNum);
	int m_digitCapacity;
	int m_numMaxSize = 0;
};
}