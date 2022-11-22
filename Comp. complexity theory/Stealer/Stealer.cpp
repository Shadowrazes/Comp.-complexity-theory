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

        if (std::cin.get() == '\n') return;
    }
   
}
//-------------------------------------------------------------------------
void Stealer::Steal() {
    m_maxCostList.reserve(m_backpackCapacity + 1);
    for (int i = 0; i < m_backpackCapacity + 1; i++) 
    {
        if (i < m_minMass)
        {
            m_maxCostList[i] = 0;
            std::cout << "f(" << i << ") = 0" << std::endl;
            m_complexity += m_products.size() + 1;
            continue;
        }

        m_maxCostList[i] = 0;
        std::cout << "f(" << i << ") = max( ";
        for (int j = 0; j < m_products.size(); j++) 
        {
            if (i - m_products[j].mass >= 0)
            {
                m_maxCostList[i] = std::max(m_maxCostList[i], m_maxCostList[i - m_products[j].mass] + m_products[j].price);
                std::cout << "f(" << i << " - " << m_products[j].mass << ") + " << m_products[j].price << "; ";
            }
            m_complexity++;
        }
        std::cout << ") = " << m_maxCostList[i] << std::endl; 
        m_complexity++;
    }
}
//-------------------------------------------------------------------------
}