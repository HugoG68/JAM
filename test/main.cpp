#include <SFML/Graphics.hpp>
#include "Flame.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flame Simulation");
    window.setFramerateLimit(60);

    Flame flame(400.0f, 500.0f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();

        flame.update(dt);

        window.clear();
        flame.draw(window);
        window.display();
    }

    return 0;
}
