#include "gameFramework/GameApplication.h"
#include "framework/Actor.h"
#include "framework/World.h"

namespace gp{
    Application* GetApplication(){
        return new GameApplication();
    }

    GameApplication::GameApplication()
    : Application{800,600, "Gameplay Window", sf::Style::Titlebar | sf::Style::Close}
    {
        weak<World> testWorld = LoadWorld<World>();
        testActor = testWorld.lock()->SpawnActor<Actor>();

        // testActor.lock()->SetPosition({400.f, 300.f});
    }

    GameApplication::~GameApplication(){}

    // void GameApplication::Render(sf::RenderWindow& window){
    //     Application::Render(window);
    // }

    void GameApplication::Tick(float deltaTime){

    }
}