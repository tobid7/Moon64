#include "mcontrols.h"

#include "moon/texts/moon-loader.h"
#include "moon/ui/widgets/mw-value.h"

using namespace std;

extern "C" {
#include "pc/configfile.h"
}

MControllerCategory::MControllerCategory() : MoonCategory("TEXT_OPT_CONTROLS"){
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_A",       MWValueBind(3.0f, 0.0f, 1.0f, configKeyA), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_B",       MWValueBind(3.0f, 0.0f, 1.0f, configKeyB), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_START",   MWValueBind(3.0f, 0.0f, 1.0f, configKeyStart), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_L",       MWValueBind(3.0f, 0.0f, 1.0f, configKeyL), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_R",       MWValueBind(3.0f, 0.0f, 1.0f, configKeyR), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_Z",       MWValueBind(3.0f, 0.0f, 1.0f, configKeyZ), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_C_UP",    MWValueBind(3.0f, 0.0f, 1.0f, configKeyCUp), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_C_DOWN",  MWValueBind(3.0f, 0.0f, 1.0f, configKeyCDown), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_C_LEFT",  MWValueBind(3.0f, 0.0f, 1.0f, configKeyCLeft), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_C_RIGHT", MWValueBind(3.0f, 0.0f, 1.0f, configKeyCRight), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_UP",      MWValueBind(3.0f, 0.0f, 1.0f, configKeyStickUp), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_DOWN",    MWValueBind(3.0f, 0.0f, 1.0f, configKeyStickDown), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_LEFT",    MWValueBind(3.0f, 0.0f, 1.0f, configKeyStickLeft), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_BIND_RIGHT",   MWValueBind(3.0f, 0.0f, 1.0f, configKeyStickRight), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_OPT_DEADZONE", MWValueBind((int*)&configStickDeadzone, 100.0f, 0.0f, 1.0f), true));
    this->catOptions.push_back(new MWValue(22.0f, 0.0f, "TEXT_OPT_RUMBLE",   MWValueBind((int*)&configRumbleStrength, 127.0f, 0.0f, 1.0f), true));
}