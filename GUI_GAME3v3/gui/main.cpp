#include <QCoreApplication>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


#include <iostream>

#include "game3v3include.h"

struct uiState
{
    sf::Color color(int guy)
    {
        enum {TEAMA=3, TEAMB=4};

        if(selected==guy==5)
            std::cout << "within active: " << active << std::endl
                      << "within selected: " << selected << std::endl;
        if(active==selected && selected==guy)
            return sf::Color::Yellow;
        if(active==guy)
            return sf::Color::Green;

        if((active<TEAMB && guy<TEAMB) || (active>TEAMA && guy>TEAMA))
        {
            if(selected==guy)
                return sf::Color::Cyan;
            return sf::Color::Blue;
        }
        if(selected==guy)
            return sf::Color::Red;
        return sf::Color::Magenta;
    }

    int active, selected;
};

float distance(sf::Vector2f a, sf::Vector2i b)
{
    sf::Vector2f out = a-sf::Vector2f(b);
    return (out.x*out.x+out.y*out.y);
}

int main(int argc, char *argv[])
{
    int resolution_horizontal = 1250, resolution_vertical = 700;
    sf::RenderWindow window(sf::VideoMode(resolution_horizontal, resolution_vertical), "collision1");

    sf::Font helvetica;
    if (!helvetica.loadFromFile("HelveticaNeue.ttf"))
    {
        std::cout << "FONT NOT FOUND" << std::endl;
    }
    sf::Text text;
    text.setFont(helvetica);
    text.setString("Hello world");
    text.setCharacterSize(resolution_horizontal/32);
    text.setColor(sf::Color::Red);

    uiState state;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        int guyRadius = resolution_vertical/16;
        sf::CircleShape guy(guyRadius);
        guy.setOrigin(guyRadius,guyRadius);
        guy.setFillColor(sf::Color::Magenta);

        sf::RectangleShape currentHealth(sf::Vector2f(resolution_horizontal/9/2,resolution_vertical/8));
        sf::RectangleShape maxHealth(sf::Vector2f(resolution_horizontal/9,resolution_vertical/8));
        currentHealth.setFillColor(sf::Color::Magenta);
        maxHealth.setOutlineColor(sf::Color::Magenta);
        maxHealth.setFillColor(sf::Color::Transparent);
        maxHealth.setOutlineThickness(-5);

        state.active = 5;

        int guyCurrent;
        sf::Vector2f guyPosition;
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        for(int i=0; i<3; ++i)
        {
            state.selected = 0;
            guyCurrent = i+1;
            guyPosition = sf::Vector2f(resolution_horizontal*(1+i*2)/8,resolution_vertical/3);
            guy.setPosition(guyPosition);
            if( distance(guyPosition,mousePosition) <= guyRadius*guyRadius )
                state.selected = guyCurrent;
            guy.setFillColor( state.color(guyCurrent) );
            window.draw(guy);

            currentHealth.setPosition(resolution_horizontal*(1+i*2)/8-guyRadius,resolution_vertical/3+guyRadius*3/2);
            maxHealth.setPosition(resolution_horizontal*(1+i*2)/8-guyRadius,resolution_vertical/3+guyRadius*3/2);
            window.draw(currentHealth);
            window.draw(maxHealth);


            state.selected = 0;
            guyCurrent = i+4;
            guyPosition = sf::Vector2f(resolution_horizontal*(6-i*2)/8,resolution_vertical*2/3);
            guy.setPosition(guyPosition);
            if( distance(guyPosition,mousePosition) <= guyRadius*guyRadius )
                state.selected = guyCurrent;
            if(state.selected)
                std::cout << "selected: " << state.selected << std::endl
                          << "active: " << state.active << std::endl
                          << "guyCurrent: " << guyCurrent << std::endl
                          << "i: " << i << std::endl << std::endl;
            guy.setFillColor( state.color(guyCurrent) );
            window.draw(guy);

            currentHealth.setPosition(resolution_horizontal*(6-i*2)/8-guyRadius,resolution_vertical*2/3+guyRadius*3/2);
            maxHealth.setPosition(resolution_horizontal*(6-i*2)/8-guyRadius,resolution_vertical*2/3+guyRadius*3/2);
            window.draw(currentHealth);
            window.draw(maxHealth);
        }

        text.setPosition(guyRadius/2, guyRadius/2);
        text.setString("Barbman\n\tHealth: 7/12");
        window.draw(text);
        text.setPosition(resolution_horizontal*2/8, guyRadius/2);
        text.setString("Cooldowns-\n\tRend CD: 2\n\tThirst CD: 1");
        window.draw(text);
        text.setPosition(resolution_horizontal*5/8+guyRadius*3/2, guyRadius/2);
        text.setString("Status-\n\tBleed: 2d 2t");
        window.draw(text);

        window.display();
    }
}
