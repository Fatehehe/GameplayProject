#include "framework/Actor.h"
#include "framework/World.h"

namespace gp{
    Actor::Actor(World* ownerWorld, const std::string& texturePath)
    :
    mOwnerWorld{ownerWorld},
    mHasBegunPlay{false}
    {

    }

    Actor::~Actor(){}

    void Actor::BeginPlayInternal(){
        mHasBegunPlay = true;
        BeginPlay();
    }

    void Actor::TickInternal(float deltaTime){
        Tick(deltaTime);
        LOG("Actor Tick Internal: %f", deltaTime);
    }

    void Actor::BeginPlay(){}

    void Actor::Tick(float deltaTime){}

    void Actor::Render(sf::RenderWindow& renderWindow){

    }
}