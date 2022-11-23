//-------------------------------------------------------------------------------------------
// Stealer.h
// Description: Класс, реализующий решение задачи динамического программирования (задача о грабителе)
// Date: 20.11.2022
// Authors: Хьюго М.А. & Наумов Н.В.
// Ⓒ Sibsutis university
//-------------------------------------------------------------------------------------------
#pragma once
#include "../Input/KeyboardInput.h"
#include <vector>

namespace DynamicProg {
class Stealer : public Input::KeyboardInput
{
public:
	struct Product;
	typedef std::vector<Product> TProductList;
	typedef std::vector<int> TMaxCostList;

	Stealer() = default;
	~Stealer() = default;

	// KeyboardInput impl
	void Input() override;
	// //

	void Steal();

	struct Product
	{
		Product(int a = 0, int b = 0)
		{
			mass = a;
			price = b;
		}
		int mass;
		int price;
	};

	int GetComplexitry() { return m_complexity; }
	
protected:
	TProductList m_products;	// Все доступные товары для кражи
	TMaxCostList m_productsCount; // индекс - порядковый номер в продуктс, значение - количество товаров в рюкзаке
	TMaxCostList m_maxCostList; // Список функций, аргументом (индексом) каждой является вместимость рюкзака, а  значением - максимальная стоимость всех товаров, которые можно унести
	int m_minMass = 0;
	int m_backpackCapacity = 0;
	int m_complexity = 0;
	int m_lastY = 0;
	int m_resultIdx = 0;
};
}