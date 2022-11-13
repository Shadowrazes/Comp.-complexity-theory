//-------------------------------------------------------------------------------------------
// DiscreteFourier.h
// Description: Класс, реализующий дискретное преобразование Фурье
// Date: 01.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include "Fourier.h"

namespace Fourier
{
class DiscreteFourier : public Fourier
{
	typedef std::vector<std::complex<double>> TComplexList;
public:
			// прямое дискретное преобразование Фурье
	void	DirectDFT();

			// обратное дискретное преобразование Фурье
	void	ReverseDFT();
};
}