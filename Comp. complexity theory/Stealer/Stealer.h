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
	typedef std::vector<int> IntList;
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

	struct ProductSet
	{
		int		MaxCost = 0;		// максимальная стоимость всех товаров, которые можно унести
		IntList ProductsCount;		// индекс - порядковый номер в продуктс, значение - количество товаров в рюкзаке
	};
	typedef std::vector<Product> TProductList;
	typedef std::vector<ProductSet> TProductSetList;


	Stealer() = default;
	~Stealer() = default;

	// KeyboardInput impl
	void Input() override;
	// //

	void Steal();

	int GetComplexitry() { return m_complexity; }
	
protected:
	TProductList		m_products;			// Все доступные товары для кражи
	TProductSetList		m_funcList;		// Список функций, аргументом (индексом) каждой является вместимость рюкзака, а  значением - содержимое рюкзака (количество и стоимость)
	int m_minMass = 0;
	int m_backpackCapacity = 0;
	int m_complexity = 0;
	int m_lastProductIdx = 0;	// Индекс последнего продукта, который положили в рюкзак
	int m_lastFuncIdx = 0;
};
}