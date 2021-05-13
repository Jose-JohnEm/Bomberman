/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Music
*/

void Raylib::Music::unloadMusic() const
{
    ::UnloadMusicStream(_music);
}

Raylib::Music &Raylib::Music::playMusic()
{
    ::PlayMusicStream(_music);
    return *this;
}

Raylib::Music &Raylib::Music::update()
{
    ::UpdateMusicStream(_music);
    return *this;
}

Raylib::Music &Raylib::Music::stop()
{
    ::StopMusicStream(_music);
    return *this;
}

Raylib::Music &Raylib::Music::pause()
{
    ::PauseMusicStream(_music);
    return *this;
}

Raylib::Music &Raylib::Music::resume()
{
    ::ResumeMusicStream(_music);
    return *this;
}

bool Raylib::Music::isPlaying() const
{
    return ::IsMusicPlaying(_music);
}

Raylib::Music &Raylib::Music::setVolume(const float &volume)
{
    ::SetMusicVolume(_music, volume);
    return *this;
}

Raylib::Music& Raylib::Music::setPitch(const float &pitch)
{
    ::SetMusicPitch(_music, pitch);
    return *this;
}

float Raylib::Music::getTimeLength() const
{
    return ::GetMusicTimeLength(_music);
}

float Raylib::Music::getTimePlayed() const
{
    return ::GetMusicTimePlayed(_music);
}

void Raylib::Music::set(const ::Music &music)
{
    _ctxType = music.ctxType;
    _ctxData = music.ctxData;
    _looping = music.looping;
    _sampleCount = music.sampleCount;
    _stream = music.stream;
}

void Raylib::Music::set(const Music &music)
{
    _ctxType = music._ctxType;
    _ctxData = music._ctxData;
    _looping = music._looping;
    _sampleCount = music._sampleCount;
    _stream = music._stream;
}

Raylib::Music &Raylib::Music::operator=(const Music &music)
{
    set(music);
    return *this;
}