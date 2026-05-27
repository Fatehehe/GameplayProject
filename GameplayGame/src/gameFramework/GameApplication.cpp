#include "gameFramework/GameApplication.h"

namespace gp{
    Application* GetApplication(){
        return new GameApplication();
    }

    GameApplication::GameApplication()
    : Application{800,600, "Gameplay Window", sf::Style::Titlebar | sf::Style::Close}
    {

    }

    GameApplication::~GameApplication(){}

    void GameApplication::Render(sf::RenderWindow& window){
        Application::Render(window);
    }

    void GameApplication::Tick(float deltaTime){
        Application::Tick(deltaTime);
    }
}