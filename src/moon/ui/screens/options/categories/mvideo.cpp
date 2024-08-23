#include "mvideo.h"

#include "moon/texts/moon-loader.h"
#include "moon/ui/widgets/mw-value.h"

using namespace std;

extern "C" {
#include "pc/configfile.h"
}

vector<wstring> filters = {
    L"TEXT_OPT_NEAREST",
    L"TEXT_OPT_LINEAR",
    L"TEXT_OPT_THREEPT"
};

MVideoCategory::MVideoCategory() : MoonCategory("TEXT_OPT_VIDEO"){
    int texY = 91;
    int hudY = 108;
#ifndef TARGET_SWITCH
    this->catOptions.push_back(new MWValue(22, 57, "TEXT_OPT_FSCREEN",
        MWValueBind(&configWindow.fullscreen), true));
    this->catOptions.push_back(new MWValue(22, 74, "TEXT_OPT_VSYNC",
        MWValueBind(&configWindow.vsync), true));
#else
    texY = 57;
    hudY = 74;
#endif

    this->catOptions.push_back(new MWValue(22, texY, "TEXT_OPT_TEXFILTER",
        MWValueBind(reinterpret_cast<int*>(&configFiltering), &filters, true), true));

#ifndef TARGET_SWITCH
    this->catOptions.push_back(new MWValue(22, texY, "Enable antialias",
        MWValueBind(&configWindow.enable_antialias), false));
    this->catOptions.push_back(new MWValue(22, texY, "Antialias level",
        MWValueBind(reinterpret_cast<int*>(&configWindow.antialias_level), 16.0f, 2.0f, 2.0f, true), false));
#endif
    this->catOptions.push_back(new MWValue(22, hudY, "TEXT_OPT_HUD",
        MWValueBind(&configHUD), true));

#ifndef TARGET_SWITCH
    this->catOptions.push_back(new MWValue(22, 125, "TEXT_OPT_RESETWND",
        MWValueBind([]() {
            configWindow.reset = true;
            configWindow.settings_changed = true;
        }), true));
    this->catOptions.push_back(new MWValue(22, 142, "TEXT_OPT_APPLY",
        MWValueBind([]() {
            configWindow.settings_changed = true;
        }), true));
#endif
}