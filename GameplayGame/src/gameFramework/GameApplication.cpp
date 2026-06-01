#include "gameFramework/GameApplication.h"
#include "framework/AssetManager.h"
#include "framework/Actor.h"
#include "framework/World.h"
#include "config.h"

namespace gp{
    Application* GetApplication(){
        return new GameApplication();
    }

    GameApplication::GameApplication()
    : Application{800,600, "Gameplay Window", sf::Style::Titlebar | sf::Style::Close}
    {
        AssetManager::Get().SetAssetRootDirectory(GetResourceDirectory());
        weak<World> testWorld = LoadWorld<World>();
        testActor = testWorld.lock()->SpawnActor<Actor>();
        testActor.lock()->SetActorLocation(sf::Vector2f{400.f, 300.f});
        testActor.lock()->SetActorRotation(0.f);


        // testActor.lock()->SetPosition({400.f, 300.f});
    }

    GameApplication::~GameApplication(){}

    // void GameApplication::Render(sf::RenderWindow& window){
    //     Application::Render(window);
    // }

    void GameApplication::Tick(float deltaTime){

    }
}