// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavesLAB01USFX/NavesLAB01USFXGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNavesLAB01USFXGameMode() {}
// Cross Module References
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_ANavesLAB01USFXGameMode_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_ANavesLAB01USFXGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_NavesLAB01USFX();
// End Cross Module References
	void ANavesLAB01USFXGameMode::StaticRegisterNativesANavesLAB01USFXGameMode()
	{
	}
	UClass* Z_Construct_UClass_ANavesLAB01USFXGameMode_NoRegister()
	{
		return ANavesLAB01USFXGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// GameMode del juego que hereda de AGameModeBase de Unreal, es el que controla todo como: spawna las naves, maneja los timers y decide cu\xc3\xa1ndo formar o romper la silueta del avi\xc3\xb3n\n" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "NavesLAB01USFXGameMode.h" },
		{ "ModuleRelativePath", "NavesLAB01USFXGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "GameMode del juego que hereda de AGameModeBase de Unreal, es el que controla todo como: spawna las naves, maneja los timers y decide cu\xc3\xa1ndo formar o romper la silueta del avi\xc3\xb3n" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANavesLAB01USFXGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::ClassParams = {
		&ANavesLAB01USFXGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANavesLAB01USFXGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANavesLAB01USFXGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANavesLAB01USFXGameMode, 4049123320);
	template<> NAVESLAB01USFX_API UClass* StaticClass<ANavesLAB01USFXGameMode>()
	{
		return ANavesLAB01USFXGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANavesLAB01USFXGameMode(Z_Construct_UClass_ANavesLAB01USFXGameMode, &ANavesLAB01USFXGameMode::StaticClass, TEXT("/Script/NavesLAB01USFX"), TEXT("ANavesLAB01USFXGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANavesLAB01USFXGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
