//-------------------------------------------------------------------------------------------
// Description: Базовый класс для реализации преобразований Фурье
// Date: 01.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include <vector>
#include <complex>
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
	virtual void Output();
	virtual void Output(const std::string& msg);

	int GetListSize() { return m_complexList.size(); };

protected:
	TComplexList m_complexList;		// массив комплесных чисел
};
}
