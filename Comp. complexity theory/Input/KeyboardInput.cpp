#include "KeyboardInput.h"
#include <stdarg.h>

namespace Input
{
bool KeyboardInput::StringIsDigit(const std::string& str)
{
	if (str.empty())
		return false;

	for (const auto& it : str)
		if (!std::isdigit(it) && it != '-')
			return false;

	return true;
}
//----------------------------------------------------------
bool KeyboardInput::IsDigits(int paramAmount, ...)
{
	va_list factor;
	va_start(factor, paramAmount);
	
	for (int i = 0; i < paramAmount; i++)
	{
		if (!StringIsDigit(va_arg(factor, std::string)))
		{
			return false;
		}	
	}

	return true;
}
//----------------------------------------------------------
}