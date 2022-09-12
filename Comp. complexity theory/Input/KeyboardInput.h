//-------------------------------------------------------------------------------------------
// Description: Класс реализующий ввод чисел с консоли
// Date: 12.09.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace Input {
	class KeyboardInput {
	protected:
		std::string m_stroke = "";		// Строка, подаваемая на вход консоли

		// Разбиение строки на числа и их конвертация
		std::vector<double> Parse();

	public:
		KeyboardInput() = default;
		~KeyboardInput() = default;

		// Ввод строки и проверка его корректности
		std::vector<double> Input();
	};
}