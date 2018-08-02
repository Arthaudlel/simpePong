#include "Paddle.hpp"
#include "Game.hpp"

Paddle::Paddle()
{
    _score = 0;
    _posX = 0;
    _posY = 0;
    _speed = 0.5;
    _height = SCREEN_HEIGHT / 15;
    _width = SCREEN_WIDTH / 100;
    _paddleSprite.setSize(sf::Vector2f(_width, _height));
    _paddleSprite.setFillColor(sf::Color::White);
}

Paddle::~Paddle()
{
}

void                Paddle::setPosX(const float posX)
{
    _posX = posX;
    _centerX = _posX + _width;
    _paddleSprite.setPosition(_posX, _posY);
}

float               Paddle::getPosX()
{
    return _posX;
}

void                Paddle::setPosY(const float posY)
{
    _posY = posY;
    _centerY = _posY + (_height / 2);
    _paddleSprite.setPosition(_posX, _posY);
}

float               Paddle::getPosY()
{
    return _posY;
}

float               Paddle::getCenterX()
{
    return _centerX;
}

float               Paddle::getCenterY()
{
    return _centerY;
}

int                 Paddle::getHeight()
{
    return _height;
}

int                 Paddle::getWidth()
{
    return _width;
}

float                 Paddle::getSpeed()
{
    return _speed;
}

void                Paddle::setButtonUp(const sf::Keyboard::Key buttonUp)
{
    _buttonUp = buttonUp;
}

sf::Keyboard::Key   Paddle::getButtonUp()
{
    return _buttonUp;
}

void                Paddle::setButtonDown(const sf::Keyboard::Key buttonDown)
{
    _buttonDown = buttonDown;
}

sf::Keyboard::Key   Paddle::getButtonDown()
{
    return _buttonDown;
}

sf::RectangleShape  Paddle::getSprite()
{
    return _paddleSprite;
}

int                 Paddle::getScore()
{
    return _score;
}

void                Paddle::addOnePoint()
{
    _score += 1;
}