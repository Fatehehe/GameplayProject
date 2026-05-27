#include "gameFramework/GameApplication.h"

namespace gp{
    Application* GetApplication(){
        return new GameApplication();
    }

    GameApplication::GameApplication()
    : Application{800,600, "Gameplay Window", sf::Style::Titlebar | sf::Style::Close}
    {

    }
}