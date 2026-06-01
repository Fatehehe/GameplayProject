#include "framework/Actor.h"
#include "framework/World.h"
#include "framework/AssetManager.h"

namespace gp{
    Actor::Actor(World* ownerWorld, const std::string& texturePath) : 
    mOwnerWorld{ownerWorld}, 
    mHasBegunPlay{false}
    {
        SetTexturePath(texturePath);
    }

    void Actor::BeginPlayInternal() {
        mHasBegunPlay = true;
        BeginPlay();
    }

    void Actor::TickInternal(float deltaTime){
        if(IsPendingDestroy() || !mSprite.has_value()) return;
        Tick(deltaTime);
    }

    void Actor::BeginPlay() {
        LOG("Actor::BeginPlay");
    }

    void Actor::Tick(float deltaTime) {
        LOG("Actor::Tick");
    }

    Actor::~Actor(){
        LOG("Actor::destructor");
    }

    void Actor::Render(sf::RenderWindow& renderWindow){
        if(IsPendingDestroy()) return;
        renderWindow.draw(*mSprite);
    }

    void Actor::SetTexturePath(const std::string& texturePath){
        mTexture = AssetManager::Get().LoadTexture(texturePath);
        if(!mTexture){
            LOG("Failed to load texture: %s", texturePath.c_str());
            return;
        }

        mSprite.emplace(*mTexture);

        int textureWidth = mTexture->getSize().x;
        int  textureHeight = mTexture->getSize().y;

        mSprite->setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight}});
        CenterPivot();
    }
    
    void Actor::SetActorLocation(const sf::Vector2f &newLocation){
        mSprite->setPosition(newLocation);
    }

    void Actor::SetActorRotation(float newRotation){
        mSprite->setRotation(sf::degrees(newRotation));
    }

    sf::Vector2f Actor::GetActorLocation() const {return mSprite->getPosition();}

    float Actor::GetActorRotation() const {return mSprite->getRotation().asDegrees();}

    void Actor::AddActorLocationOffset(const sf::Vector2f &offsetAmount){
        mSprite->setPosition(GetActorLocation() + offsetAmount);
    }

    void Actor::AddActorRotationOffset(float offsetAmount){
        mSprite->setRotation(sf::degrees(GetActorRotation() + offsetAmount));
    }

    sf::Vector2u Actor::GetWindowSize() const{
        // return mOwnerWorld->GetWindowSize();
    }

    void Actor::CenterPivot(){
        sf::FloatRect bounds = mSprite->getGlobalBounds();
        mSprite->setOrigin(bounds.getCenter());
    }
}

