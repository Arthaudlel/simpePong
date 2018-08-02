#ifndef PADDLE_HPP_
#define PADDLE_HPP_

#include <SFML/Graphics.hpp>

class Paddle
{
public:
    Paddle();
    ~Paddle();
    void                setPosX(const float posX);
    float               getPosX();
    void                setPosY(const float posY);
    float               getPosY();
    float               getCenterX();
    float               getCenterY();
    int                 getHeight();
    int                 getWidth();
    float               getSpeed();
    void                setButtonUp(const sf::Keyboard::Key buttonUp);
    sf::Keyboard::Key   getButtonUp();
    void                setButtonDown(const sf::Keyboard::Key buttonDown);
    sf::Keyboard::Key   getButtonDown();
    sf::RectangleShape  getSprite();
    void                addOnePoint();
    int                 getScore();
private:
    float               _posX;
    float               _posY;
    float               _centerX;
    float               _centerY;
    int                 _height;
    int                 _width;
    float               _speed;
    sf::Keyboard::Key   _buttonUp;
    sf::Keyboard::Key   _buttonDown;
    sf::RectangleShape  _paddleSprite;
    int                 _score;
};

#endif /* PADDLE_HPP_ */