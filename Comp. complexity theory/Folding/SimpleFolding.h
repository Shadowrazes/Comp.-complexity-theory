//-------------------------------------------------------------------------------------------
// SimpleFolding.h
// Description: Класс, реализующий простую свертку
// Date: 05.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include "Folding.h"

namespace Folding
{
class SimpleFolding : public Folding
{
public:
			// Folding implemetation
	void	Fold() override;
	void	Output() const override;
	void	Output(const std::string& msg) const override;
			//	//

			// Трудоемкость, или кол-во операций
	int		GetOperationCount() const { return 0; };

private:
	int		m_operationCount = 0;	// Трудоемкость
};
}
