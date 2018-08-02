#ifndef BALL_HPP_
#define BALL_HPP_

#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball();
    ~Ball();
    float           getPosX();
    void            setPosX(const float posX);
    float           getPosY();
    void            setPosY(const float posY);
    float           getCenterX();
    float           getCenterY();
    float           getForceX();
    void            setForceX(const float forceX);
    float           getForceY();
    void            setForceY(const float forceY);
    float           getRadius();
    sf::CircleShape getSprite();
private:
    float               _posX;
    float               _posY;
    float               _centerX;
    float               _centerY;
    float               _forceX;
    float               _forceY;
    float               _radius;
    sf::CircleShape     _ballSprite;
};

#endif /* BALL_HPP_ */