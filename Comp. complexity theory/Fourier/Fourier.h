//-------------------------------------------------------------------------------------------
// Fourier.h
// Description: Базовый класс для реализации преобразований Фурье
// Date: 01.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include <vector>
#include <complex>
#include <cmath>
#include "../Input/KeyboardInput.h"

namespace Fourier
{
class Fourier : public Input::KeyboardInput
{
	typedef std::vector<std::complex<double>> TComplexList;
public:
	Fourier() = default;
	virtual ~Fourier() = default;

	void Input() override;
	virtual void SetArray(TComplexList& complexList) { m_complexList = complexList; };
	virtual void Output() const;
	virtual void Output(const std::string& msg) const;
	virtual TComplexList GetArray() const { return m_complexList; }

	int GetListSize() { return m_complexList.size(); };

			// трудоемкость, или кол-во операций
	int		GetOperationCount() { return m_complexity; };

	int		GetComplexity() { return m_complexity / 5; }

	void	ResetComplexity() { m_complexity = 0; }

protected:
	TComplexList m_complexList;		// массив комплесных чисел
	int			 m_complexity = 0;
};
}
