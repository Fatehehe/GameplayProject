#pragma once
#include "framework/Core.h"
#include "framework/Object.h"
#include <SFML/Graphics.hpp>

namespace gp{
    class World;
    class Actor: public Object{
    public:
        Actor(World* ownerWorld, const std::string& texturePath =  "PNG/Default/ship_F.png");
        virtual ~Actor();

        void BeginPlayInternal();
        virtual void BeginPlay();

        void TickInternal(float deltaTime);
        virtual void Tick(float deltaTime);
        
        void Render(sf::RenderWindow& renderWindow);

        void SetTexturePath(const std::string& texturePath);

        void SetActorLocation(const sf::Vector2f& newLocation);
        void SetActorRotation(float newRotation);

        sf::Vector2f GetActorLocation() const;
        float GetActorRotation() const;

        void AddActorLocationOffset(const sf::Vector2f& offsetAmount);
        void AddActorRotationOffset(float offsetAmount);

        sf::Vector2u GetWindowSize() const;

    private:
        World* mOwnerWorld;
        bool mHasBegunPlay;

        shared<sf::Texture> mTexture;
        std::optional<sf::Sprite> mSprite;

        void CenterPivot();
    };
}