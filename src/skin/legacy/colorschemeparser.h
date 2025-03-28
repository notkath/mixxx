#pragma once

#include "preferences/usersettings.h"
#include "skin/legacy/legacyskinparser.h"
#include "skin/legacy/skincontext.h"

class ImgSource;

class ColorSchemeParser {
  public:
    static void setupLegacyColorSchemes(
            const QDomElement& docElem,
            UserSettingsPointer pConfig,
            QString* pStyle,
            SkinContext* pContext);
    static QDomNode findConfiguredColorSchemeNode(
            const QDomElement& docElem,
            UserSettingsPointer pConfig);

  private:
    static ImgSource* parseFilters(const QDomNode& filter);
    ColorSchemeParser() { }
    ~ColorSchemeParser() { }
};
