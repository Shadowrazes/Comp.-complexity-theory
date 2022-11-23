#include "FileInput.h"

namespace Input
{
void FileInput::Input() {
	m_file.open(m_fileName);
	if (!m_file.is_open()) {
		std::cout << "Error opening the file" << std::endl;
	}
}
}