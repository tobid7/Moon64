#ifndef MoonWidgetValue
#define MoonWidgetValue

#include "moon/ui/interfaces/moon-widget.h"
#include <string>
#include <vector>
#include <cstdint>

struct MWValueBind{
    bool  *bvar;

    float *fvar;
    int   *ivar;
    float max;
    float min;
    float step;
    void (*btn)();

    int   *index;
    std::vector<std::wstring>* values;
    bool valueKeys;
    bool rawValue;

    uint32_t* bindKeys;
    std::string keyIcon;

    void (*callback)();

    // Additial Constructors (Using them as the 3ds Version had Problems with the setup)
   MWValueBind()
        : bvar(nullptr), fvar(nullptr), ivar(nullptr), max(0.0f), min(0.0f), step(0.0f),
          btn(nullptr), index(nullptr), values(nullptr), valueKeys(false), rawValue(false),
          bindKeys(nullptr), keyIcon(""), callback(nullptr) {}

    MWValueBind(uint32_t* bindKeys, const std::string& keyIcon)
        : bvar(nullptr), fvar(nullptr), ivar(nullptr), max(0.0f), min(0.0f), step(0.0f),
          btn(nullptr), index(nullptr), values(nullptr), valueKeys(false), rawValue(false),
          bindKeys(bindKeys), keyIcon(keyIcon), callback(nullptr) {}

    MWValueBind(float max, float min, float step, uint32_t* bindKeys)
        : bvar(nullptr), fvar(nullptr), ivar(nullptr), max(max), min(min), step(step),
          btn(nullptr), index(nullptr), values(nullptr), valueKeys(false), rawValue(false),
          bindKeys(bindKeys), keyIcon(""), callback(nullptr) {}

    MWValueBind(int* ivar, float max, float min, float step, bool rawValue = false)
        : bvar(nullptr), fvar(nullptr), ivar(ivar), max(max), min(min), step(step),
          btn(nullptr), index(nullptr), values(nullptr), valueKeys(false), rawValue(rawValue),
          bindKeys(nullptr), keyIcon(""), callback(nullptr) {}

    MWValueBind(bool* bvar)
        : bvar(bvar), fvar(nullptr), ivar(nullptr), max(0.0f), min(0.0f), step(0.0f),
          btn(nullptr), index(nullptr), values(nullptr), valueKeys(false), rawValue(false),
          bindKeys(nullptr), keyIcon(""), callback(nullptr) {}

    MWValueBind(void (*button)())
        : btn(button), bvar(nullptr), fvar(nullptr), ivar(nullptr), max(0.0f), min(0.0f),
          step(0.0f), index(nullptr), values(nullptr), valueKeys(false), rawValue(false),
          bindKeys(nullptr), keyIcon(""), callback(nullptr) {}

    MWValueBind(int* index, std::vector<std::wstring>* values, void (*cb)() = nullptr)
        : index(index), values(values), callback(cb), bvar(nullptr), fvar(nullptr),
          ivar(nullptr), max(0.0f), min(0.0f), step(0.0f), btn(nullptr), valueKeys(false),
          rawValue(false), bindKeys(nullptr), keyIcon("") {}
    MWValueBind(int* index, std::vector<std::wstring>* values, bool vkeys)
        : index(index), values(values), callback(nullptr), bvar(nullptr), fvar(nullptr),
          ivar(nullptr), max(0.0f), min(0.0f), step(0.0f), btn(nullptr), valueKeys(vkeys),
          rawValue(false), bindKeys(nullptr), keyIcon("") {}
};

class MWValue : public MoonWidget {
    protected:
        bool titleKey;
    public:
        MWValueBind bind;
        std::wstring title;
        MWValue(float x, float y, std::wstring title, MWValueBind bind);
        MWValue(float x, float y, std::wstring title, MWValueBind bind, bool titleKey);
        MWValue(float x, float y, std::string title, MWValueBind bind);
        MWValue(float x, float y, std::string title, MWValueBind bind, bool titleKey);
        void Init();
        void Draw();
        void Update();
        void Dispose();
};

#endif
