#ifndef ES8388AUDIOSINK_H
#define ES8388AUDIOSINK_H

#include <vector>
#include <iostream>
#include "BufferedAudioSink.h"
#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"

#include "audio_element.h"
#include "board.h"

class ES8388AudioSink : public BufferedAudioSink
{
public:
    ES8388AudioSink();
    ~ES8388AudioSink();
private:
};

#endif