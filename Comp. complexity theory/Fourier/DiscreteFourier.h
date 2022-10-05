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
public:
			// прямое дискретное преобразование Фурье
	void	DirectDFT();

			// обратное дискретное преобразование Фурье
	void	ReverseDFT();

			// трудоемкость, или кол-во операций
	int		GetOperationCount() { return 5 * std::pow(m_complexList.size(), 2); };
};
}