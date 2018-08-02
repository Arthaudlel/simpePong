#include "Ball.hpp"
#include "Game.hpp"

Ball::Ball()
{
    _posX = 0;
    _posY = 0;
    _forceX = 0;
    _forceY = 0;
    _radius = SCREEN_HEIGHT / 100;
    _ballSprite.setRadius(_radius);
    _ballSprite.setFillColor(sf::Color::White);
}

Ball::~Ball()
{
}

float           Ball::getPosX()
{
    return _posX;
}

void            Ball::setPosX(const float posX)
{
    _posX = posX;
    _centerX = _posX + _radius;
    _ballSprite.setPosition(_posX, _posY);
}

float           Ball::getPosY()
{
    return _posY;
}

void            Ball::setPosY(const float posY)
{
    _posY = posY;
    _centerY = _posY + _radius;
    _ballSprite.setPosition(_posX, _posY);

}

float           Ball::getCenterX()
{
    return _centerX;
}

float           Ball::getCenterY()
{
    return _centerY;
}

float           Ball::getForceX()
{
    return _forceX;
}

void            Ball::setForceX(const float forceX)
{
    _forceX = forceX;
}

float           Ball::getForceY()
{
    return _forceY;
}

void            Ball::setForceY(const float forceY)
{
    _forceY = forceY;
}

float           Ball::getRadius()
{
    return _radius;
}

sf::CircleShape Ball::getSprite()
{
    return _ballSprite;
}