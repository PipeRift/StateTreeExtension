// Copyright 2015-2026 Piperift. All Rights Reserved.
#pragma once

#include <Modules/ModuleManager.h>


DECLARE_LOG_CATEGORY_EXTERN(LogStateTreeExtEd, All, All)

class FStateTreeExtensionEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
