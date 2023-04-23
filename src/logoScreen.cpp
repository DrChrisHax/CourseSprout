#include "functions.h"

bool logoFade(sf::RenderWindow& window) {

    sf::Texture logoTexture;
    if (!logoTexture.loadFromFile("pictures/CourseSprout.png")) {
        std::cout << "Failed to load logo" << std::endl;
        return 1;
    }

    sf::Sprite logoSprite(logoTexture);
    logoSprite.setPosition(window.getSize().x / 2.f - logoTexture.getSize().x / 2.f + 30, window.getSize().y / 2.f - logoTexture.getSize().y / 2.f);

    sf::Clock clock;
    float alpha = 0.f;
    float fadeSpeed = 50.f;

    bool fadeIn = true;
    bool fadeOut = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 1;
            }
        }

        float deltaTime = clock.restart().asSeconds();

        if (fadeIn)
        {
            alpha += fadeSpeed * deltaTime;
            if (alpha >= 255.f)
            {
                alpha = 255.f;
                fadeIn = false;
                fadeOut = true;
            }
        }
        else if (fadeOut)
        {
            alpha -= fadeSpeed * deltaTime;
            if (alpha <= 0.f)
            {
                alpha = 0.f;
                fadeOut = false;
            }
        }

        sf::Color color(255, 255, 255, alpha);
        logoSprite.setColor(color);

        window.clear(sf::Color::Black);
        window.draw(logoSprite);
        window.display();
        if(!fadeIn && !fadeOut) {
            return 0;
        }
    }

    return 0;
}
