
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include "level.h"
#include <cstdlib>
std::string resourcesDir()
{
    return "resources/";
}
using namespace sf;
int main()
{
    // Создаем главное окно приложения
    sf::RenderWindow window(sf::VideoMode(1280, 960), "Ya nerusskiy");
    Level lvl(10, 10);

    // Главный цикл приложения
    while (window.isOpen())
    {
        // Обрабатываем события в цикле
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            window.display();
            // Кроме обычного способа наше окно будет закрываться по нажатию на Escape
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        // Очистка
        window.clear();
        // Тут будут вызываться функции обновления и отрисовки объектов
        // Отрисовка
        sf::RectangleShape rect(sf::Vector2f(200, 100));
        rect.setFillColor(Color::Cyan);
        window.draw(rect);
        lvl.Show(window);
        window.display();
    }
    return EXIT_SUCCESS;
}
