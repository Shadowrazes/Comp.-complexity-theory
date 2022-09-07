// �����, ����������� ���������� ������� �������

#pragma once

#include "Sort.h"

namespace Sorting {
	class Merge : public Sort {
	private:
		std::vector<int> m_tempChain = {};		// ������������� ������

	public:
		Merge(const std::vector<int>& numbers) : Sort(numbers) {}

		void Sorting() override;
		void Output() const override;
	};
}