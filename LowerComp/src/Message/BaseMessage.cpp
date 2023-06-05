#include "Message/BaseMessage.h"
#include "Message/FifoMessage.h"
#include "Message/MqMessage.h"

//Message Queue Init
#define use_mq 1

#if use_mq
      std::shared_ptr<CBaseMessageInfo> CBaseMessageInfo::pSharedMqMessage =
            std::make_shared<CMqMessageInfo>();
#else
      std::shared_ptr<CBaseMessageInfo> CBaseMessageInfo::pSharedMqMessage =
            std::make_shared<CFifoManageInfo>();
#endif