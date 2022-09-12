#include "KeyboardInput.h"

std::vector<double> Input::KeyboardInput::Input() {
    while (true) {
        try {
            std::cin.seekg(std::cin.eof());
            std::cout << "Input data with a space at the end: ";
            std::string input;
            std::getline(std::cin, input);
            for (const auto& it : input)
                if (!std::isdigit(it) && it != '-' && it != ' ')
                    throw std::invalid_argument("A numbers was expected, but a string was received");

            m_stroke = input;
            return Parse();
        }
        catch (std::exception) {
            std::cout << "Incorrect input, try again" << std::endl;
        }
    }
}

std::vector<double> Input::KeyboardInput::Parse() {
    std::string buff = "";
    std::vector<double> array;
    for (const auto& it : m_stroke) {
        if (it == ' ') {
            if (buff.size() != 0) {
                array.push_back(stod(buff));
                buff.clear();
            }
            continue;
        }
        else
            buff += it;
    }
    return array;
}