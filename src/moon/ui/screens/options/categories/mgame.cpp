#include "mgame.h"

#include "moon/texts/moon-loader.h"
#include "moon/ui/widgets/mw-value.h"
#include "moon/ui/moon-ui-manager.h"

using namespace std;

extern "C" {
#include "pc/configfile.h"
#include "pc/pc_main.h"
}

vector<wstring> lngNames;
vector<wstring> modes = {
    L"Auto", L"Low", L"Disabled"
};

MGameCategory::MGameCategory() : MoonCategory("TEXT_OPT_GAME"){
    for (auto &lng : Moon::languages) {
        lngNames.push_back(lng->name);
    }

    this->catOptions.push_back(new MWValue(22, 57, "TEXT_OPT_LANGUAGE", 
        MWValueBind(reinterpret_cast<int*>(&configLanguage), &lngNames, []() {
            if (configLanguage < Moon::languages.size())
                Moon::setCurrentLanguage(Moon::languages[configLanguage]);
        }), true));

    this->catOptions.push_back(new MWValue(22, 74, "TEXT_OPT_PRECACHE", 
        MWValueBind(&configPrecacheRes), true));

#ifdef TARGET_SWITCH
    this->catOptions.push_back(new MWValue(22, 91, "TEXT_OPT_SWITCH_HUD", 
        MWValueBind(&configSwitchHud), true));
#endif

    this->catOptions.push_back(new MWValue(22, 0, "Level of detail", 
        MWValueBind(reinterpret_cast<int*>(&configLODMode), &modes, nullptr), false));

    this->catOptions.push_back(new MWValue(22, 0, "Achievements", 
        MWValueBind([]() {
            MoonChangeUI(2);
        }), false));

    this->catOptions.push_back(new MWValue(22, 0, "Addons", 
        MWValueBind([]() {
            MoonChangeUI(1);
        }), false));

    this->catOptions.push_back(new MWValue(22, 0, "TEXT_EXIT_GAME", 
        MWValueBind(game_exit), true));
}