/*
            This file is part of: 
                NoahFrame
            https://github.com/ketoo/NoahGameFrame

   Copyright 2009 - 2018 NoahFrame(NoahGameFrame)

   File creator: lvsheng.huang
   
   NoahFrame is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


#ifndef NFC_HERO_MODULE_MODULE_H
#define NFC_HERO_MODULE_MODULE_H

#include "NFComm/NFCore/NFMap.hpp"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIHeroModule.h"
#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFMessageDefine/NFProtocolDefine.hpp"
#include "NFComm/NFPluginModule/NFIGameServerNet_ServerModule.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFISceneProcessModule.h"
#include "NFComm/NFPluginModule/NFIHeroPropertyModule.h"
#include "NFComm/NFPluginModule/NFISceneAOIModule.h"

class NFCHeroModule
    : public NFIHeroModule
{
public:
    NFCHeroModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual ~NFCHeroModule() {};

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();

    virtual bool AfterInit();
    virtual bool BeforeShut();

	virtual NFGUID AddHero(const NFGUID& self, const std::string& strID);
	virtual bool AddHeroExp(const NFGUID& self, const int64_t nExp);
	virtual bool AddHeroExp(const NFGUID& self, const NFGUID& xHeroID, const int64_t nExp);
	virtual bool SetFightHero(const NFGUID& self, const NFGUID& xHeroID, const EConsHero_Pos nPos);
	virtual bool SwitchFightHero(const NFGUID& self, const NFGUID& xHeroID);

	virtual NFGUID GetHeroGUID(const NFGUID& self, const std::string& strID);
	EConsHero_Pos GetFightPos(const NFGUID& self, const NFGUID& xHeroID);

protected:
	void OnSetFightHeroMsg(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
	void OnSwitchFightHeroMsg( const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen );

protected:

	int OnPlayerClassEvent(const NFGUID& self, const std::string& strClassName, const CLASS_OBJECT_EVENT eClassEvent, const NFDataList& var);
	int OnPlayerHPEvent(const NFGUID& self, const std::string& strPropertyName, const NFData& oldVar, const NFData& newVar);

	int BeforeEnterSceneGroupEvent(const NFGUID& self, const int nSceneID, const int nGroupID, const int nType, const NFDataList& argList);
	int AfterEnterSceneGroupEvent(const NFGUID& self, const int nSceneID, const int nGroupID, const int nType, const NFDataList& argList);
	int BeforeLeaveSceneGroupEvent(const NFGUID& self, const int nSceneID, const int nGroupID, const int nType, const NFDataList& argList);
	int AfterLeaveSceneGroupEvent(const NFGUID& self, const int nSceneID, const int nGroupID, const int nType, const NFDataList& argList);


protected:
	NFISceneAOIModule* m_pSceneAOIModule;
    NFIClassModule* m_pLogicClassModule;
    NFIElementModule* m_pElementModule;
	NFIKernelModule* m_pKernelModule;
	NFINetModule* m_pNetModule;
	NFIHeroPropertyModule* m_pHeroPropertyModule;
	NFIGameServerNet_ServerModule* m_pGameServerNet_ServerModule;
    NFISceneProcessModule* m_pSceneProcessModule;
private:
};

#endif
