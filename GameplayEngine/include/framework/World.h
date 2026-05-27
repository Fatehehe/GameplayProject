#pragma once
#include "framework/Core.h"
#include <SFML/Graphics.hpp>

namespace gp{
    class Actor;
    class Application;
    class World{
    public:
        World(Application* ownerApp);
        virtual ~World();

        void BeginPlayInternal();
        void TickInternal(float deltaTime);

        virtual void BeginPlay();
        virtual void Tick(float deltaTime);
        void Render(sf::RenderWindow& renderWindow);

        template<typename ActorType>
        weak<ActorType> SpawnActor();

    private:

        Application *mOwnerApp;
        bool mHasBegunPlay;

        List<shared<Actor>> mActors;
        List<shared<Actor>> mPendingActors;
    };

    template <typename ActorType>
    weak<ActorType> World::SpawnActor()
    {
        shared<ActorType> newActor { new ActorType(this) };
        mPendingActors.push_back(newActor);
        return newActor;
    }
}