#ifdef BETTERCAMERA

#include "mcamera.h"

#include "moon/texts/moon-loader.h"
#include "moon/ui/widgets/mw-value.h"

using namespace std;

extern "C" {
#include "pc/configfile.h"
}

MCameraCategory::MCameraCategory() : MoonCategory("TEXT_OPT_CAMERA") {
    this->catOptions.push_back(new MWValue(22, 57, "TEXT_OPT_CAMON",
        MWValueBind(&configEnableCamera), true));
    this->catOptions.push_back(new MWValue(22, 74, "TEXT_OPT_ANALOGUE",
        MWValueBind(&configCameraAnalog), true));
    this->catOptions.push_back(new MWValue(22, 91, "TEXT_OPT_MOUSE",
        MWValueBind(&configCameraMouse), true));
    this->catOptions.push_back(new MWValue(22, 108, "TEXT_OPT_INVERTX",
        MWValueBind(&configCameraInvertX), true));
    this->catOptions.push_back(new MWValue(22, 125, "TEXT_OPT_INVERTY",
        MWValueBind(&configCameraInvertY), true));
    this->catOptions.push_back(new MWValue(22, 142, "TEXT_OPT_CAMX",
        MWValueBind(reinterpret_cast<int*>(&configCameraXSens), 100.0f, 0.1f, 1.0f), true));
    this->catOptions.push_back(new MWValue(22, 159, "TEXT_OPT_CAMY",
        MWValueBind(reinterpret_cast<int*>(&configCameraYSens), 100.0f, 0.1f, 1.0f), true));
    this->catOptions.push_back(new MWValue(22, 176, "TEXT_OPT_CAMC",
        MWValueBind(reinterpret_cast<int*>(&configCameraAggr), 100.0f, 0.0f, 1.0f), true));
    this->catOptions.push_back(new MWValue(22, 193, "TEXT_OPT_CAMP",
        MWValueBind(reinterpret_cast<int*>(&configCameraPan), 100.0f, 0.0f, 1.0f), true));
    this->catOptions.push_back(new MWValue(22, 210, "TEXT_OPT_CAMD",
        MWValueBind(reinterpret_cast<int*>(&configCameraDegrade), 100.0f, 0.0f, 1.0f), true));
}

#endif