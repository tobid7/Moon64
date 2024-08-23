#include "maudio.h"

#include "moon/texts/moon-loader.h"
#include "moon/ui/widgets/mw-value.h"

using namespace std;

extern "C" {
#include "pc/configfile.h"
}

MAudioCategory::MAudioCategory() : MoonCategory("TEXT_OPT_AUDIO"){
    this->catOptions.push_back(new MWValue(22.0f, 57.0f,  "TEXT_OPT_MVOLUME",  MWValueBind((int*)&configMasterVolume, 127.0f, 0.0f, 1.0f), true));
    this->catOptions.push_back(new MWValue(22.0f, 74.0f,  "TEXT_OPT_MUSVOLUME", MWValueBind((int*)&configMusicVolume, 127.0f, 0.0f, 1.0f), true));
    this->catOptions.push_back(new MWValue(22.0f, 91.0f,  "TEXT_OPT_SFXVOLUME", MWValueBind((int*)&configSfxVolume, 127.0f, 0.0f, 1.0f), true));
    this->catOptions.push_back(new MWValue(22.0f, 108.0f, "TEXT_OPT_ENVVOLUME", MWValueBind((int*)&configEnvVolume, 127.0f, 0.0f, 1.0f), true));
}