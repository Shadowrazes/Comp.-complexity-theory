//-------------------------------------------------------------------------------------------
// SemiFastFourier.h
// Description: Класс, реализующий полубыстрое преобразование Фурье
// Date: 05.10.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------

#pragma once

#include "Fourier.h"

namespace Fourier
{
class SemiFastFourier : public Fourier {
	typedef std::vector<std::complex<double>> TComplexList;
public:
			// Ввод данных
	void	Input();

			// Прямое полубыстрое преобразование Фурье
	void	DirectSFFT();

			// Обратное полубыстрое преобразование Фурье
	void	ReverseSFFT();

			// Трудоемкость, или кол-во операций
	int		GetOperationCount() const { return m_complexity /*m_complexList.size() * (m_p1 + m_p2)*/; };

	void	SetP(int p1, int p2) { m_p1 = p1; m_p2 = p2; }
	void	ResetComplexity(){ m_complexity = 0; }

private:
	int m_p1 = 0;
	int m_p2 = 0;
	int m_complexity = 0;
};
}