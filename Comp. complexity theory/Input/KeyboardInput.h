#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace Input {
	class KeyboardInput {
	protected:
		std::string m_stroke = "";
		std::vector<double> Parse();

	public:
		KeyboardInput() = default;
		~KeyboardInput() = default;

		std::vector<double> Input();
	};
}