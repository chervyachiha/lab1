#include <SFML/Graphics.hpp>

class anime
{
private:
    sf::Text text;
    sf::Font font;
    std::string str = "";
    std::string str1 = "Hello world";
public:
    anime()
    {
        font.loadFromFile("C:/Users/настя/Downloads/прога/л1/FOERTE.ttf");
        text.setFont(font);
        text.setString("");
        sf::Time t = sf::seconds(13.0f);
        text.setCharacterSize(45);
        text.setColor(sf::Color::Blue);
        text.setPosition(100, 95);
    }
    void draw()
    {
        sf::RenderWindow window(sf::VideoMode(900, 800), "SFML works!");
        sf::Clock timer;
        int x = 0;

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            if ((timer.getElapsedTime().asSeconds() > 1) && (x < str1.length()))
            {
                str += str1[x];
                x++;
                text.setString(str);
                timer.restart();
            }

            window.clear();
            window.draw(text);
            window.display();
        }
    }
};

int main()
{
    anime an;
    an.draw();
    return 0;
}
