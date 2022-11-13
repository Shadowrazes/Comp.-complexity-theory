//-------------------------------------------------------------------------------------------
// Multiplication.h
// Description: Базовый класс для реализации умножения чисел
// Date: 30.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include "../Input/KeyboardInput.h"
#include <vector>

namespace Multiplication
{
class Multiplication : public Input::KeyboardInput
{		
public:
	Multiplication() = default;
	virtual  ~Multiplication() = default;

	// KeyboardInput Implementation
	void	Input() override;
	// //
	virtual void Output();
	virtual void Process() = 0;
	virtual int  GetOperationCount() { return m_operationCount; }

protected:
	int				 m_operationCount = 0;
	std::vector<int> m_firstNumber;
	std::vector<int> m_secondNumber;
	std::vector<int> m_result;
};
}