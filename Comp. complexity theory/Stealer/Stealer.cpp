#include "Stealer.h"

namespace DynamicProg 
{
void Stealer::Input() 
{
    std::string str;
    std::cout << "Enter backpack capacity (kg): ";
    std::cin >> str;
    while (!KeyboardInput::IsDigits(1, str)) 
    {
        std::cout << "Incorrect input! Enter an integer - backpack capacity: ";
    }

    m_backpackCapacity = std::stoi(str);
    m_funcList = TProductSetList(m_backpackCapacity + 1);

    // Чтение буфера потока ввода до конца, чтобы не было проблем с getline() (Очистка)
    std::cin.seekg(std::cin.eof());
    std::cout << "Enter a list of products separated by a space. The first number is the mass, the second is the price:\n ";
    std::string mass, price;
    m_minMass = 10000;
    while (std::cin >> mass >> price)
    {
        if (KeyboardInput::IsDigits(2, mass, price))
        {
            m_products.emplace_back(std::stoi(mass), std::stoi(price));
            if (std::stoi(mass) < m_minMass)
                m_minMass = std::stoi(mass);
        }

        if (std::cin.get() == '\n') break;
    }

    for (auto& productSet : m_funcList) 
    {
        productSet.ProductsCount = IntList(m_products.size());
    }
}
//-------------------------------------------------------------------------
void Stealer::Steal() {
    for (int i = 1; i < m_backpackCapacity + 1; i++) 
    {
        if (i < m_minMass)
        {
            m_funcList[i].MaxCost = 0;
            std::cout << "f(" << i << ") = 0" << std::endl;
            m_complexity += m_products.size();
            continue;
        }

        m_funcList[i].MaxCost = 0;
        std::cout << "\nf(" << i << ") = max( ";
        for (int j = 0; j < m_products.size(); j++) 
        {
            if (i - m_products[j].mass >= 0)
            {
                int max = std::max(m_funcList[i].MaxCost, m_funcList[i - m_products[j].mass].MaxCost + m_products[j].price);
                if (max != m_funcList[i].MaxCost) 
                {
                    m_funcList[i].MaxCost = max;
                    m_lastProductIdx = j;
                    m_lastFuncIdx = i - m_products[j].mass;
                }
                std::cout << "f(" << i << " - " << m_products[j].mass << ") + " << m_products[j].price << "; ";
            }
            m_complexity++;
        }
        m_funcList[i].ProductsCount = m_funcList[m_lastFuncIdx].ProductsCount;
        m_funcList[i].ProductsCount[m_lastProductIdx]++;
        std::cout << ") = " << m_funcList[i].MaxCost << std::endl;
        for (int j = 0; j < m_products.size(); j++) 
        {
            std::cout << "Product index: " << j + 1 << ", count: " << m_funcList[i].ProductsCount[j] << std::endl;
        }
    }
}
//-------------------------------------------------------------------------
}