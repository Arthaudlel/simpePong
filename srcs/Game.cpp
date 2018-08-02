#include "Game.hpp"
#include <iostream>

Game::Game()
{
    _master.setPosX(SCREEN_WIDTH / 20);
    _master.setPosY(SCREEN_HEIGHT / 2 - (_master.getHeight() / 2));
    _master.setButtonUp(sf::Keyboard::W);
    _master.setButtonDown(sf::Keyboard::S);
    _slave.setPosX(SCREEN_WIDTH - (SCREEN_WIDTH / 20));
    _slave.setPosY(SCREEN_HEIGHT / 2 - (_slave.getHeight() / 2));
    _slave.setButtonUp(sf::Keyboard::Up);
    _slave.setButtonDown(sf::Keyboard::Down);
    _ball.setPosX(SCREEN_WIDTH / 2 - _ball.getRadius());
    _ball.setPosY(SCREEN_HEIGHT / 2 - _ball.getRadius());
    _window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
    /*
    if (!_fontMaster.loadFromFile(FONT_FILE))
        std::cout << "fuck" << std::endl;
    if (!_fontSlave.loadFromFile(FONT_FILE))
        std::cout << "fuck" << std::endl;
    _scoreMaster.setColor(sf::Color::White);
    _scoreSlave.setColor(sf::Color::White);
    _scoreMaster.setCharacterSize(24);
    _scoreSlave.setCharacterSize(24);
    _scoreMaster.setPosition(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 20);
    _scoreSlave.setPosition((SCREEN_WIDTH / 3) * 2, SCREEN_HEIGHT / 20);
    _scoreMaster.setFont(_fontMaster);
    _scoreSlave.setFont(_fontSlave);
    _scoreMaster.setStyle(sf::Text::Bold);
    _scoreSlave.setStyle(sf::Text::Bold);
    _scoreMaster.setString(std::to_string(_master.getScore()));
    _scoreSlave.setString(std::to_string(_slave.getScore()));
    */
}

Game::~Game()
{
}

void    Game::drawGame()
{
    _window.draw(_master.getSprite());
    _window.draw(_slave.getSprite());
    _window.draw(_ball.getSprite());
    /*
    _window.draw(_scoreMaster);
    _window.draw(_scoreSlave);
    */
}

void    Game::playerInput()
{
    if (sf::Keyboard::isKeyPressed(_master.getButtonUp())
    && _master.getPosY() > 0) {
        _master.setPosY(_master.getPosY() - _master.getSpeed());
    }
    if (sf::Keyboard::isKeyPressed(_master.getButtonDown())
    && _master.getPosY() + _master.getHeight() < SCREEN_HEIGHT) {
        _master.setPosY(_master.getPosY() + _master.getSpeed());
    }
    if (sf::Keyboard::isKeyPressed(_slave.getButtonUp())
    && _slave.getPosY() > 0) {
        _slave.setPosY(_slave.getPosY() - _slave.getSpeed());
    }
    if (sf::Keyboard::isKeyPressed(_slave .getButtonDown())
    && _slave.getPosY() + _slave.getHeight() < SCREEN_HEIGHT) {
        _slave.setPosY(_slave.getPosY() + _slave.getSpeed());
    }
}

void    Game::ballKickOff()
{
    /*
    _scoreMaster.setString(std::to_string(_master.getScore()));
    _scoreSlave.setString(std::to_string(_slave.getScore()));
    */
    srand(time(NULL));
    _ball.setPosX(SCREEN_WIDTH / 2 - _ball.getRadius());
    _ball.setPosY(SCREEN_HEIGHT / 2 - _ball.getRadius());
    _ball.setForceX((rand() > RAND_MAX /2) ? 0.5 : -0.5);
    _ball.setForceY((rand() > RAND_MAX /2) ? 0.5 : -0.5);
}

void    Game::ballBouncingPaddle()
{
    float   paddleCenter;
    float   intersection;
    float   normalizedIntersection;
    float   bounceAngle;

    if (_ball.getForceX() < 0) {
        paddleCenter = _master.getPosY() + (_master.getHeight() / 2);
        intersection = ((paddleCenter - _ball.getCenterY()));
        normalizedIntersection = (intersection / (_master.getHeight() / 2));
        bounceAngle = (normalizedIntersection * MAX_ANGLE);
        _ball.setForceX(0.5 * cosf(bounceAngle));
        _ball.setForceY(0.5 * (sinf(bounceAngle) * -1.f));
    } else if (_ball.getForceX() > 0) {
        paddleCenter = _slave.getPosY() + (_slave.getHeight() / 2);
        intersection = ((paddleCenter - _ball.getCenterY()));
        normalizedIntersection = (intersection / (_slave.getHeight() / 2));
        bounceAngle = (normalizedIntersection * MAX_ANGLE);
        _ball.setForceX(-0.5 * cosf(bounceAngle));
        _ball.setForceY(0.5 * (sinf(bounceAngle) * -1.f));
    }
}


void    Game::ballCollision()
{
    float   predictedPosY = _ball.getPosY() + _ball.getRadius();
    float   predictedPosX = _ball.getPosX();

    if (_ball.getForceX() < 0) {
        if (_ball.getPosX() <= _master.getCenterX()
        && _ball.getPosX() >= _master.getCenterX() - 10) {
            if ((predictedPosY >= _master.getPosY()) && 
            (predictedPosY <= (_master.getPosY() + _master.getHeight())))
                ballBouncingPaddle();
        }
        if (_ball.getCenterX() <= 0) {
            _master.addOnePoint();
            ballKickOff();
        }
    } else if (_ball.getForceX() > 0) {
        predictedPosX += (_ball.getRadius() * 2);
        if (_ball.getCenterX() + _ball.getRadius() >= _slave.getPosX()
        && _ball.getCenterX() + _ball.getRadius() <= _slave.getPosX() +  10) {
            if ((predictedPosY >= _slave.getPosY()) && 
            (predictedPosY <= (_slave.getPosY() + _slave.getHeight())))
                ballBouncingPaddle();
        }
        if (_ball.getCenterX() >= SCREEN_WIDTH) {
            _slave.addOnePoint();
            ballKickOff();
        }
    }
    if (_ball.getForceY() < 0) {
        if (_ball.getPosY() <= 1)
            _ball.setForceY(fabs(_ball.getForceY()));
    } else if (_ball.getForceY() > 0) {
        if (_ball.getCenterY() + _ball.getRadius() >= SCREEN_HEIGHT)
            _ball.setForceY(_ball.getForceY() * (-1.f));
    }
}


void    Game::ballPhysics()
{
    ballCollision();
    _ball.setPosX(_ball.getPosX() + _ball.getForceX());
    _ball.setPosY(_ball.getPosY() + _ball.getForceY());
}

void    Game::gameLoop()
{
    sf::Event event;

    ballKickOff();
    while (_window.isOpen()) {
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        drawGame();
        playerInput();
        ballPhysics();
        _window.display();
    }
}