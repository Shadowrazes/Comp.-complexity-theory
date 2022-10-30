//-------------------------------------------------------------------------------------------
// SemiFastFourierFolding.h
// Description: Класс, реализующий свертку с использованием полубыстрого преобразования фурье
// Date: 30.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include "Folding.h"
#include "../Fourier/SemiFastFourier.h"

namespace Folding
{
class SemiFastFourierFolding : public Folding {
public:
			// Folding implemetation
	void	Fold() override;
	void	Output() const override;
	void	Output(const std::string& msg) const override;
			//	//
};
}