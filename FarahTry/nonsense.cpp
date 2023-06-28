#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

int main()
{
    // Set up the game window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fruit Shooter");

    // Player
    sf::RectangleShape player(sf::Vector2f(50, 50));
    player.setPosition(window.getSize().x / 2 - player.getSize().x / 2, window.getSize().y - player.getSize().y);
    player.setFillColor(sf::Color::Red);
    float playerSpeed = 5.0f;

    // Fruit
    sf::RectangleShape fruit(sf::Vector2f(50, 50));
    fruit.setPosition(std::rand() % (window.getSize().x - static_cast<int>(fruit.getSize().x)), -fruit.getSize().y);
    fruit.setFillColor(sf::Color::Red);
    float fruitSpeed = 3.0f;

    // Game state
    int score = 0;
    bool gameover = false;

    // Fonts
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;
    }

    // Score text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(36);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setPosition(10, 10);

    // Game loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space && !gameover)
                {
                    // Shoot a fruit
                    fruit.setPosition(std::rand() % (window.getSize().x - static_cast<int>(fruit.getSize().x)), -fruit.getSize().y);
                }
            }
        }

        // Update player position
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.getPosition().x > 0)
            player.move(-playerSpeed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getPosition().x + player.getSize().x < window.getSize().x)
            player.move(playerSpeed, 0);

        // Update fruit position
        if (!gameover)
        {
            fruit.move(0, fruitSpeed);

            // Check for collision
            if (fruit.getPosition().y > window.getSize().y)
            {
                // Fruit missed, reset its position
                fruit.setPosition(std::rand() % (window.getSize().x - static_cast<int>(fruit.getSize().x)), -fruit.getSize().y);
                score -= 1;
            }

            if (player.getGlobalBounds().intersects(fruit.getGlobalBounds()))
            {
                // Fruit hit, reset its position
                fruit.setPosition(std::rand() % (window.getSize().x - static_cast<int>(fruit.getSize().x)), -fruit.getSize().y);
                score += 1;
            }
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw player
        window.draw(player);

        // Draw fruit
        window.draw(fruit);

        // Update and draw score
        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);

        // Update the display
        window.display();

        // Check for game over
        if (score < 0)
        {
            gameover = true;
        }
    }

    return 0;
}
