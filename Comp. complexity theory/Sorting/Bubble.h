// �����, ����������� ���������� ������� ��������

#pragma once

#include "Sort.h"

namespace Sorting {
	class Bubble : public Sort {
	public:
		Bubble(const std::vector<double>& numbers) : Sort(numbers) {}

		void Sorting() override;
		void Output() const override;
	};
}
