#ifndef BAMT_TEXTURE_ATLAS
#define BAMT_TEXTURE_ATLAS
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define TEXTURE_MAX_SIZE 1000

#include <experimental/filesystem>
#include <iostream>
#include <SDL_mixer.h>

#include "Debug.h"
#include <SDL_render.h>
#include <SDL_ttf.h>
#include <vector>

/// <summary>
/// Images are used mainly for sprites.
/// </summary>
struct Image
{
	Image(const std::experimental::filesystem::path& png, SDL_Renderer* renderer);
	~Image();
	std::string name;
	SDL_Texture* texture;
};

/// <summary>
/// Fonts are used by TextRenderer's. Upon creation they make a glyph atlas that can be used to
///	create custom text prompts.
/// </summary>
struct Font
{
	Font(const std::experimental::filesystem::path& ttf, SDL_Renderer* renderer);
	~Font();
	std::string name;
	TTF_Font* ttf = nullptr;
	SDL_Texture* glyphAtlas = nullptr;
	SDL_Rect glyphs[128];
};

/// <summary>
/// AudioClips are used by AudioSources to tell that AudioSource what to play.
/// </summary>
struct AudioClip
{
	AudioClip(const std::experimental::filesystem::path& path);
	~AudioClip();
	std::string name;
	Mix_Chunk* clip = nullptr;
};

/// <summary>
/// MusicClips are similar to AudioClips, however MusicClips use MIX_Music.
/// </summary>
struct MusicClip
{
	MusicClip(const std::experimental::filesystem::path& path);
	~MusicClip();
	std::string name;
	Mix_Music* music = nullptr;
};


/// <summary>
/// The asset warehouse is where all assets are stored. Upon the engine starting, the asset warehouse will
///	look though the "Assets" folder and attempts to find any files matching certain types.
///	These can then be used in the engine for whatever purpose.
/// </summary>
class AssetWarehouse
{
	std::vector<Image*> _textures;
	std::vector<Font*> _fonts;
	std::vector<AudioClip*> _audio;
	std::vector<MusicClip*> _music;

	public:
		~AssetWarehouse();

		std::vector<std::experimental::filesystem::path> png_files;
		std::vector<std::experimental::filesystem::path> ttf_files;
		std::vector<std::experimental::filesystem::path> wav_files;
		std::vector<std::experimental::filesystem::path> mp3_files;

		void FindAssets(const std::experimental::filesystem::path& directory, std::vector<std::experimental::filesystem::path>& png_files);
		void LoadTextures(SDL_Renderer* renderer);
		void LoadFonts(SDL_Renderer* renderer);
		void LoadAudioClips();
		void LoadMusicClips();
		SDL_Texture* GetTexture(const char* filename) const;
		Font* GetFont(const char* filename) const;
		Mix_Music* GetMusic(const char* filename) const;
		Mix_Chunk* GetAudioClip(const char* filename) const;
};
#endif