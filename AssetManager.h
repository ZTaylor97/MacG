#pragma once
#include "EntityManager.h"
#include <iostream>
#include <map>
#include <SDL_ttf.h>
#include <SDL_image.h>
namespace MacG
{
	class AssetManager
	{
	private:
		EntityManager* manager;
		std::map<std::string, SDL_Texture*> textures;
		std::map<std::string, TTF_Font*> fonts;

		SDL_Renderer* renderer;
	public:
		AssetManager(EntityManager* manager, SDL_Renderer* renderer);
		void ClearData();
		SDL_Texture* LoadTexture(const char* filePath, std::string textureId);
		TTF_Font* AddFont(std::string fontId, const char* filePath, int fontSize);
		SDL_Texture* GetTexture(std::string textureId);
		TTF_Font* GetFont(std::string fontId);
	};
}


