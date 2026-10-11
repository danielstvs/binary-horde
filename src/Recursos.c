#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

#include "Recursos.h"

static ResourceManager _rm = { 0 };  // Mutável; pertencente exclusivamente a este módulo
const ResourceManager * const rm = &_rm;

void loadResourcesResourceManager( void ) {
    _rm.textureExample = LoadTexture( "resources/images/image.png" );
    _rm.soundExample = LoadSound( "resources/sfx/sound.wav" );
    _rm.musicExample = LoadMusicStream( "resources/musics/music.ogg" );
}

void unloadResourcesResourceManager( void ) {
    UnloadTexture( _rm.textureExample );
    UnloadSound( _rm.soundExample );
    UnloadMusicStream( _rm.musicExample );
}