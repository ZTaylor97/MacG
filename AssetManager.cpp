#include "AssetManager.h"

namespace MacG
{
	AssetManager::AssetManager(EntityManager* manager, SDL_Renderer* renderer) : manager(manager), renderer(renderer)
	{
	}

	void AssetManager::ClearData()
	{
		textures.clear();
		fonts.clear();
	}

	TTF_Font* AssetManager::AddFont(std::string assignFontId, const char* filePath, int fontSize) 
	{
		return TTF_OpenFont(filePath, fontSize);
	}

	SDL_Texture* AssetManager::GetTexture(std::string textureId)
	{
		if (textures.find(textureId) != textures.end())
		{
			return textures.at(textureId);
		}
		else
		{
			std::cerr << "Error: Texture not found" << std::endl;
			return NULL;
		}
	}

	TTF_Font* AssetManager::GetFont(std::string fontId)
	{
		if (fonts.find(fontId) != fonts.end())
		{
			return fonts.at(fontId);
		}
		else
		{
			std::cerr << "Error: Font not found" << std::endl;
			return NULL;
		}
	}

	SDL_Texture* AssetManager::LoadTexture(const char* filePath, std::string textureId) {
		SDL_Surface* surface = IMG_Load(filePath);

		if (surface == NULL)
		{
			std::cout << "Error: Image loading failed, check that the filepath is correct." << std::endl;
		}
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		return texture;
	}
}

