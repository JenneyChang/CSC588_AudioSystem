# CSC588_AudioSystem
## Description
A multithreaded audio system that wraps around existing XAudio2 API using the Actor Model.
## Demos
* Press Key 1
  - Starts Demo 1
  - Shows basic audio manipulations (Play, Stop, Replay, Pan, etc) 
* Press Key 2
  - Starts Demo 2
  - Displays ability to stitch multiple sounds together
* Press Key 3
  - Starts Demo 3
  - Shows Pan and Volume can be smoothly adjusted over time
## Table of Contents
* [Audio Engine](#audio-engine)
* [Loading Resources](#loading-resources)
* [Sound Objects](#sound-objects)
* [Callbacks](#callbacks)
* [Miscellaneous](#miscellaneous)
## Documentation
### Audio Engine
A singleton class serves as the main way user interfaces with Audio System.
1. Starting Audio System<br>
The Audio Engine class must be initialized before the user can interact with the Audio System. Initializing the Audio Engine class also starts up the Sound Manager and spawns the threads needed to operate the system.
>```cpp
>void Game::Initialize()
>{
>    // Initialize Audio Engine before game app runs
>    AudioEngine::Init();
>}
>```
2. Shutting down Audio System<br>
The Audio Engine class must be uninitialized before the application terminates. 
>```cpp
>void Game::Unload()
>{
>    // Uninitialize or Unload audio engine
>    AudioEngine::Destroy();
>}
>```
### Loading Resources
1. Audio Files<br>
The Audio Engine can be used to load wav resources for future references.
>```cpp
>  // Loads Audio Files and stores it as a static resource
>  AudioEngine::LoadWave(AudioEngine::Blocking::LOAD, Wave::ID::WATERFALL, "filename.wav");
>```
3. Playlists<br>
A playlist can be loaded referencing a previously loaded wav file. The playlist is intended to be script-like, holding the IDs to what playlist, wav file, and commands to associate. Currently, the playlists are hard coded into the system. Ideally, they should be loaded from an external source provided by an audio engineer, etc.
>```cpp
>  // Loads static playlist manager reference
>  AudioEngine::LoadPlaylist(PlaylistRef::ID::WATERFALL, Wave::ID::WATERFALL);
>```
### Sound Objects
1. Creating a Sound Object<br>
The Audio Engine class Create Sound method returns a reference to a sound object; this object can be used to operate on a loaded audio file.
>```cpp
>  Sound* pSoundObj = AudioEngine::CreateSound(Sound::ID::WATERFALL, PlaylistRef::ID::WATERFALL, Playlist::ID::WATERFALL);
>```
3. Sound Operations<br>
The sound object provides access to public member functions to manipulate audio.
>```cpp
> class Sound
>{
>  public:
>  Handle::Status Play();
>  Handle::Status Pause();
>  Handle::Status Stop();
>  Handle::Status Replay();
>
>  Handle::Status SetVolume(float vol);
>  Handle::Status Pan(float left, float right);
>  Handle::Status Pitch(float freq);
>}
>```
5. Sound Commands<br>
All sound operations issue a request to the audio system.
>```cpp
> Handle::Status Sound::Play()
>{
>    ...
>    //Create message to send to Audio system
>    Command* msg = new PlayASound(soundID, this);
>
>    // Send message to Audio
>    QueueManager::SendToAudio(msg);
>    ...
>}
>```
## Callbacks
1. File Callback<br>
For asynchronous audio file loads, the user can specify a callback to execute custom code. The user can create a callback by deriving from an abstract File Callback interface.
>```cpp
> class FileCallback
>{
> public:
>  virtual void Loaded();
>  virtual void Error();
>}
>
> class UserFileCallback : public FileCallback
>{
> public:
>  UserFileCallback(bool& loadFlag);
>  void Loaded() override;
>}
>```
3. Sound Callback
An optional callback can be defined by the user when creating a sound object. It enables the user to execute custom code when the following events occur:
>* Sound Start
>* Sound Stop
>* Sound Ends
>* Sound Pause
>* Priority Kill (sound gets stopped by audio system)
### Miscellaneous
Sound Priority Table<br>
The table tracks active sounds; a sound that is paused or playing is considered active. When a sound object is created, a priority is assigned and determines its order in the table. The table allows system to limit the number of active sounds. When the table is at capacity, a user request can be denied if the sound object's priority is too low for request to be processed. Likewise, if the sound object has a high priority, an active sound object can be stopped and removed from the table to make room for the new request.
