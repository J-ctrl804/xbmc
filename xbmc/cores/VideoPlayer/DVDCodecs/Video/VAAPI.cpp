/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "VAAPI.h"
#include "cores/VideoPlayer/DVDCodecs/DVDCodecUtils.h"
#include "cores/VideoPlayer/Process/ProcessInfo.h"
#include "utils/log.h"
#include "ServiceBroker.h"
#include "settings/Settings.h"
#include "settings/AdvancedSettings.h"
#include "settings/lib/Setting.h"
#include "windowing/GraphicContext.h"

#include <mutex>
#include <va/va.h>
#include <va/va_drm.h>
#include <va/va_x11.h>
#if VA_CHECK_VERSION(1, 0, 0)
#include <va/va_wayland.h>
#endif

using namespace VAAPI;

// Helper function to check VA status
static bool CheckSuccess(VAStatus status, const char* function)
{
  if (status != VA_STATUS_SUCCESS)
  {
    CLog::Log(LOGERROR, "VAAPI::{} - Error: {}", function, vaErrorStr(status));
    return false;
  }
  return true;
}

CVAAPI::CVAAPI()
  : m_display(nullptr),
    m_context(VA_INVALID_ID),
    m_configId(VA_INVALID_ID),
    m_width(0),
    m_height(0),
    m_renderState(0),
    m_hwContext(nullptr),
    m_usePic(false)
{
  CLog::Log(LOGDEBUG, "VAAPI::CVAAPI - Constructor initialized");
}
