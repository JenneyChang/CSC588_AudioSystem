#pragma once
#ifndef AUDIO_THREAD_H
#define AUDIO_THREAD_H

void AudioThread(std::atomic_bool& quitFlag);

#endif // !AUDIO_THREAD_H
