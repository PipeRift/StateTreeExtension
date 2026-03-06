// Copyright 2015-2026 Piperift. All Rights Reserved.
#pragma once

#include <Modules/ModuleManager.h>

DECLARE_LOG_CATEGORY_EXTERN(LogStateTreeExt, All, All);


class FStateTreeExtensionModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual bool SupportsDynamicReloading() override
	{
		return true;
	}

	static FStateTreeExtensionModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FStateTreeExtensionModule>("StateTreeExtension");
	}
};
