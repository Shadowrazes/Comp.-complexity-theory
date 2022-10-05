//-------------------------------------------------------------------------------------------
// Folding.h
// Description: Базовый класс для реализации сверток
// Date: 05.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include <vector>
#include <complex>
#include <cmath>
#include "../Input/KeyboardInput.h"

namespace Folding
{
class Folding : public Input::KeyboardInput
{
	typedef std::vector<std::complex<double>> TComplexList;
public:
	Folding() = default;
	virtual ~Folding() = default;

	void	Input() override;

					// Свертка
	virtual void	Fold() = 0;

	virtual void	Output() const;
	virtual void	Output(const std::string& msg) const;

	int GetListSize() { return m_firstComplexList.size(); };

protected:
	TComplexList m_firstComplexList;	// Массив комплесных чисел
	TComplexList m_secondComplexList;
	TComplexList m_result;				// Результат свертки
};
}