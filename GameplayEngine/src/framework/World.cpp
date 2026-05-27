#include "framework/World.h"
#include "framework/Actor.h"

namespace gp{
    World::World(Application* ownerApp): 
    mOwnerApp{ownerApp}, 
    mHasBegunPlay{false},
    mActors{},
    mPendingActors{}
    {
    }

    World::~World(){}

    void World::BeginPlayInternal() {
        if(!mHasBegunPlay){
            mHasBegunPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float deltaTime) {
        for(shared<Actor> actor : mPendingActors){
            mActors.push_back(actor);
            actor->BeginPlayInternal();
        }

        mPendingActors.clear();

        for(auto iter = mActors.begin(); iter != mActors.end();){
            if(iter->get()->IsPendingDestroy()){
                iter = mActors.erase(iter);
            } else {
                iter->get()->TickInternal(deltaTime);
                ++iter;
            }
        }

        Tick(deltaTime);
    }

    void World::Render(sf::RenderWindow& renderWindow){
        for(auto& actor : mActors){
            actor->Render(renderWindow);
        }
    }

    void World::BeginPlay(){}

    void World::Tick(float deltaTime){}
}