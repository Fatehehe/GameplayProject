#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace gp{
    class AssetManager{
    protected:
        AssetManager();
    public:
        static AssetManager& Get();
        shared<sf::Texture> LoadTexture(const std::string& texturePath);
        void CleanCycle();
        void SetAssetRootDirectory(const std::string& dir);

    private:
        static unique<AssetManager> assetManager;
        Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
        std::string mRootDirectory;
    };
}