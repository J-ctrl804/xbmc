#include "RenderSystem.h"

#include "ServiceBroker.h"
#include "settings/Settings.h"
#include "settings/lib/Setting.h"
#include "utils/log.h"

using namespace KODI;

CRenderSystem::CRenderSystem()
{
  CLog::Log(LOGDEBUG, "CRenderSystem::CRenderSystem - Constructor initialized");
}

CRenderSystem::~CRenderSystem()
{
  CLog::Log(LOGDEBUG, "CRenderSystem::~CRenderSystem - Destroyed render system object");
}

bool CRenderSystem::Init()
{
  CLog::Log(LOGDEBUG, "CRenderSystem::Init - Initializing render system");
  
  if (!CServiceBroker::GetSettings()->GetBool(CSettings::SETTING_VIDEOSCREEN_RENDER))
  {
    CLog::Log(LOGERROR, "CRenderSystem::Init - Render system disabled in settings");
    return false;
  }

  return true;
}

void CRenderSystem::Deinit()
{
  CLog::Log(LOGDEBUG, "CRenderSystem::Deinit - Deinitializing render system");
}
