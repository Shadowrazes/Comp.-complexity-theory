//-------------------------------------------------------------------------------------------
// FileInput.h
// Description: Класс реализующий ввод чисел с файла
// Date: 12.09.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once
#include "KeyboardInput.h"
#include <fstream>

namespace Input
{
class FileInput : public KeyboardInput
{
public:
	FileInput(const std::string fileName) { m_fileName = fileName; }

	// Ввод строки и проверка его корректности
	virtual void Input() override;

	virtual void SetFileName(const std::string fileName) { m_fileName = fileName; }

	virtual std::fstream& GetFileStream() { return m_file; }

protected:
	std::string m_fileName = "";
	std::fstream m_file;
};
}