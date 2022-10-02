//-------------------------------------------------------------------------------------------
// Description: Класс, реализующий дискретное преобразованое Фурье
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
	void	DirectDFT();	// прямое дискретное преобразование Фурье
	void	ReverseDFT();	// обратное дискретное преобразование Фурье
	int		GetOperationCount() { return 5 * std::pow(m_complexList.size(), 2); };	// трудоемкость, или кол-во операций
};
}