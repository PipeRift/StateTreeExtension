// Copyright 2015-2026 Piperift. All Rights Reserved.

#include "StateTreeExtensionModule.h"


DEFINE_LOG_CATEGORY(LogStateTreeExt)

#define LOCTEXT_NAMESPACE "StateTreeExtensionModule"

void FStateTreeExtensionModule::StartupModule() {}

void FStateTreeExtensionModule::ShutdownModule() {}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FStateTreeExtensionModule, StateTreeExtension)