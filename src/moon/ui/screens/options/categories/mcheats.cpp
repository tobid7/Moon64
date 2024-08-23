#include "mcheats.h"

#include "moon/texts/moon-loader.h"
#include "moon/ui/widgets/mw-value.h"

using namespace std;

extern "C" {
#include "pc/cheats.h"
}

MCheatsCategory::MCheatsCategory() : MoonCategory("TEXT_OPT_CHEATS"){
    this->catOptions.push_back(new MWValue(22, 57,  "TEXT_OPT_CHEAT1", MWValueBind(&Cheats.EnableCheats), true));
    this->catOptions.push_back(new MWValue(22, 74,  "TEXT_OPT_CHEAT2", MWValueBind(&Cheats.MoonJump), true));
    this->catOptions.push_back(new MWValue(22, 91,  "TEXT_OPT_CHEAT3", MWValueBind(&Cheats.GodMode), true));
    this->catOptions.push_back(new MWValue(22, 108, "TEXT_OPT_CHEAT4", MWValueBind(&Cheats.InfiniteLives), true));
    this->catOptions.push_back(new MWValue(22, 125, "TEXT_OPT_CHEAT5", MWValueBind(&Cheats.SuperSpeed), true));
    this->catOptions.push_back(new MWValue(22, 142, "TEXT_OPT_CHEAT6", MWValueBind(&Cheats.Responsive), true));
    this->catOptions.push_back(new MWValue(22, 159, "TEXT_OPT_CHEAT7", MWValueBind(&Cheats.ExitAnywhere), true));
    this->catOptions.push_back(new MWValue(22, 176, "TEXT_OPT_CHEAT8", MWValueBind(&Cheats.HugeMario), true));
    this->catOptions.push_back(new MWValue(22, 193, "TEXT_OPT_CHEAT9", MWValueBind(&Cheats.TinyMario), true));
}