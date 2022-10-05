//-------------------------------------------------------------------------------------------
// KeyboardInput.h
// Description: Базовый класс для реализации ввода данных с консоли
// Date: 12.09.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace Input
{
class KeyboardInput 
{
protected:
	std::string m_stroke = "";		// Строка, подаваемая на вход консоли
public:
	KeyboardInput() = default;
	~KeyboardInput() = default;

	static bool IsDigits(int paramAmount, ...);
	static bool StringIsDigit(const std::string& str);

	// Ввод строки и проверка его корректности
	virtual void Input() = 0;
};
}