#pragma once
#include "framework/Core.h"
#include "SFML/Graphics.hpp"

namespace gp{
    class Animation{
    public:
        Animation(const std::string& spritePath, sf::Vector2u imageCount, float switchTime);
        ~Animation();
        
        void Update(int row, float deltaTime, int face, sf::Sprite& targetSprite);

        void SetSpriteTexturePath(const std::string& path);

        sf::IntRect uvRect;

    private:
        shared<sf::Texture> mTexture;

        sf::Vector2u mImageCount;
        sf::Vector2u mCurrentImage;
        float mTotalTime;
        float mSwitchTime;
    };
}