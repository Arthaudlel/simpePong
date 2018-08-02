#ifndef GAME_HPP_
#define GAME_HPP_

#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

#define MAX_ANGLE      5 * M_PI / 18

class Game 
{
public:
    Game();
    ~Game();
    void    gameLoop();
    void    playerInput();
    void    ballPhysics();
    void    ballKickOff();
    void    ballCollision();
    void    ballBouncingPaddle();
private:
    void    drawGame();
    sf::RenderWindow    _window;
    Paddle              _master;
    Paddle              _slave;
    Ball                _ball;
};

#endif /* GAME_HPP_ */