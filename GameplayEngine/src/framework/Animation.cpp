#include "framework/Animation.h"
#include "framework/AssetManager.h"

namespace gp {
    Animation::Animation(const std::string &spritePath, sf::Vector2u imageCount, float switchTime)
    : mImageCount{imageCount},
    mSwitchTime{switchTime},
    mTotalTime{0.0f},
    mCurrentImage{0, 0}
    {
        SetSpriteTexturePath(spritePath);
    }

    Animation::~Animation(){}
    
    void Animation::SetSpriteTexturePath(const std::string& path){
        mTexture = AssetManager::Get().LoadTexture(path);
        if(mTexture) return;
        uvRect.size.x = static_cast<int>(mTexture->getSize().x / mImageCount.x);
        uvRect.size.y = static_cast<int>(mTexture->getSize().y / mImageCount.y);
    }

void Animation::Update(int row, float deltaTime, int face, sf::Sprite& targetSprite) {
    mCurrentImage.y = row;
    mTotalTime += deltaTime;
    
    if (mTotalTime >= mSwitchTime) {
        mTotalTime -= mSwitchTime;
        mCurrentImage.x++;
        if (mCurrentImage.x >= mImageCount.x) mCurrentImage.x = 0;
    }

    // Hitung posisi koordinat SFML 3
    uvRect.position.y = static_cast<int>(mCurrentImage.y * std::abs(uvRect.size.y));

    if (face >= 0) { // Kanan
        uvRect.position.x = static_cast<int>(mCurrentImage.x * std::abs(uvRect.size.x));
        uvRect.size.x = std::abs(uvRect.size.x);
    } else { // Kiri
        uvRect.position.x = static_cast<int>((mCurrentImage.x + 1) * std::abs(uvRect.size.x));
        uvRect.size.x = -std::abs(uvRect.size.x);
    }

    // TERAPKAN KE SPRITE TARGET (Milik Actor)
    if (mTexture) {
        targetSprite.setTexture(*mTexture); // Pastikan tekstur sinkron saat berganti animasi
    }
    targetSprite.setTextureRect(uvRect);
}

}