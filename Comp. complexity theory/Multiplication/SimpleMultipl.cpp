#include "SimpleMultipl.h"

namespace Multiplication
{
void SimpleMultipl::Process()
{
	int inMind = 0;
	for (int secondNumIdx = m_secondNumber.size() - 1; secondNumIdx >= 0; secondNumIdx--)
	{
		for (int firstNumIdx = m_firstNumber.size() - 1; firstNumIdx >= 0; firstNumIdx--)
		{
			int res = m_firstNumber[firstNumIdx] * m_secondNumber[secondNumIdx] + inMind;
			inMind = res / 10;
			res = res % 10;

			if (secondNumIdx == m_secondNumber.size() - 1)
				m_result.insert(m_result.begin(), res);
			else
			{
				int idx = m_result.size() - (m_secondNumber.size() - secondNumIdx) - (m_firstNumber.size() - firstNumIdx - 1);
				if (idx < 0)
					m_result.insert(m_result.begin(), res);
				else
				{
					m_result[idx] += res;
					if (m_result[idx] >= 10)
					{
						if (idx == 0) {
							m_result.insert(m_result.begin(), m_result[idx] / 10 + inMind);
							idx++;
						}
						else 
							m_result[idx - 1] += m_result[idx] / 10 + inMind;

						m_result[idx] = m_result[idx] % 10;
						inMind = 0;
					}
						
				}
					
			}
				
		}
		if (inMind == 0)
			continue;

		m_result.insert(m_result.begin(), inMind);

		inMind = 0;
	}
}
//----------------------------------------------------
}

