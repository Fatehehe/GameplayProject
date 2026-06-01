#include "framework/AssetManager.h"

namespace gp{
    AssetManager::AssetManager()
    : mLoadedTextureMap {},
    mRootDirectory{}
    {}

    unique<AssetManager> AssetManager::assetManager{nullptr};

    AssetManager& AssetManager::Get(){
        if(!assetManager){
            assetManager = unique<AssetManager>{new AssetManager};
        }
        return *assetManager;
    }

    shared<sf::Texture> AssetManager::LoadTexture(const std::string& texturePath){
        auto foundTexture = mLoadedTextureMap.find(texturePath);
        if(foundTexture != mLoadedTextureMap.end()){
            return foundTexture->second;
        }

        shared<sf::Texture> newTexture = std::make_shared<sf::Texture>();
        if(newTexture->loadFromFile(mRootDirectory + texturePath)){
            mLoadedTextureMap.insert({texturePath, newTexture});
            return newTexture;
        }

        return shared<sf::Texture>{nullptr}; 
    }

    void AssetManager::CleanCycle(){
        for(auto iter = mLoadedTextureMap.begin(); iter != mLoadedTextureMap.end();){
            if(iter->second.unique()){
                LOG("Cleaning up texture: %s", iter->first.c_str());
                iter = mLoadedTextureMap.erase(iter);
            }else{
                iter++;
            }
        }
    }

    void AssetManager::SetAssetRootDirectory(const std::string& directory){
        mRootDirectory = directory;
    }
}