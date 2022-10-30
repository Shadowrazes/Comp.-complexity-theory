//-------------------------------------------------------------------------------------------
// DiscreteFourierFolding.h
// Description: Класс, реализующий свертку с использованием дискретного преобразования фурье
// Date: 30.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include "Folding.h"
#include "../Fourier/DiscreteFourier.h"

namespace Folding 
{
class DiscreteFourierFolding : public Folding {
public:
			// Folding implemetation
	void	Fold() override;
	void	Output() const override;
	void	Output(const std::string& msg) const override;
			//	//
};
}
