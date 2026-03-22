// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavesLAB01USFX/Enemigo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigo() {}
// Cross Module References
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AEnemigo_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AEnemigo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NavesLAB01USFX();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void AEnemigo::StaticRegisterNativesAEnemigo()
	{
	}
	UClass* Z_Construct_UClass_AEnemigo_NoRegister()
	{
		return AEnemigo::StaticClass();
	}
	struct Z_Construct_UClass_AEnemigo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VelocidadMovimiento_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VelocidadMovimiento;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldLimitesMin_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WorldLimitesMin;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldLimitesMax_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WorldLimitesMax;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IndiceFormacion_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_IndiceFormacion;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CentroFormacion_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CentroFormacion;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEnFormacion_MetaData[];
#endif
		static void NewProp_bEnFormacion_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnFormacion;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EscalaFormacion_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EscalaFormacion;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemigo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// Clase del enemigo que hereda de Actor que es la clase base de Unreal\n// Se mueve solo por el nivel con waypoints aleatorios\n" },
		{ "IncludePath", "Enemigo.h" },
		{ "ModuleRelativePath", "Enemigo.h" },
		{ "ToolTip", "Clase del enemigo que hereda de Actor que es la clase base de Unreal\nSe mueve solo por el nivel con waypoints aleatorios" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_VelocidadMovimiento_MetaData[] = {
		{ "Category", "Enemigo" },
		{ "Comment", "// La figura 3D del enemigo que se ve en el nivel\n" },
		{ "ModuleRelativePath", "Enemigo.h" },
		{ "ToolTip", "La figura 3D del enemigo que se ve en el nivel" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_VelocidadMovimiento = { "VelocidadMovimiento", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, VelocidadMovimiento), METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_VelocidadMovimiento_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_VelocidadMovimiento_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMin_MetaData[] = {
		{ "Category", "Enemigo" },
		{ "Comment", "// Qu\xc3\xa9 tan r\xc3\xa1pido se mueve en cm por segundo\n" },
		{ "ModuleRelativePath", "Enemigo.h" },
		{ "ToolTip", "Qu\xc3\xa9 tan r\xc3\xa1pido se mueve en cm por segundo" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMin = { "WorldLimitesMin", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, WorldLimitesMin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMin_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMax_MetaData[] = {
		{ "Category", "Enemigo" },
		{ "Comment", "// L\xc3\xadmite inferior del \xc3\xa1rea donde genera sus waypoints\n" },
		{ "ModuleRelativePath", "Enemigo.h" },
		{ "ToolTip", "L\xc3\xadmite inferior del \xc3\xa1rea donde genera sus waypoints" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMax = { "WorldLimitesMax", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, WorldLimitesMax), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMax_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_IndiceFormacion_MetaData[] = {
		{ "Category", "Formacion" },
		{ "Comment", "// L\xc3\xadmite superior del \xc3\xa1rea donde genera sus waypoints\n" },
		{ "ModuleRelativePath", "Enemigo.h" },
		{ "ToolTip", "L\xc3\xadmite superior del \xc3\xa1rea donde genera sus waypoints" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_IndiceFormacion = { "IndiceFormacion", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, IndiceFormacion), METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_IndiceFormacion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_IndiceFormacion_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_CentroFormacion_MetaData[] = {
		{ "Category", "Formacion" },
		{ "Comment", "// N\xc3\xbamero del 0 al 9 que dice qu\xc3\xa9 parte del avi\xc3\xb3n le toca a este enemigo\n" },
		{ "ModuleRelativePath", "Enemigo.h" },
		{ "ToolTip", "N\xc3\xbamero del 0 al 9 que dice qu\xc3\xa9 parte del avi\xc3\xb3n le toca a este enemigo" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_CentroFormacion = { "CentroFormacion", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, CentroFormacion), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_CentroFormacion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_CentroFormacion_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_bEnFormacion_MetaData[] = {
		{ "Category", "Formacion" },
		{ "Comment", "// Punto central del avi\xc3\xb3n, los offsets se calculan desde aqu\xc3\xad\n" },
		{ "ModuleRelativePath", "Enemigo.h" },
		{ "ToolTip", "Punto central del avi\xc3\xb3n, los offsets se calculan desde aqu\xc3\xad" },
	};
#endif
	void Z_Construct_UClass_AEnemigo_Statics::NewProp_bEnFormacion_SetBit(void* Obj)
	{
		((AEnemigo*)Obj)->bEnFormacion = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_bEnFormacion = { "bEnFormacion", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AEnemigo), &Z_Construct_UClass_AEnemigo_Statics::NewProp_bEnFormacion_SetBit, METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_bEnFormacion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_bEnFormacion_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemigo_Statics::NewProp_EscalaFormacion_MetaData[] = {
		{ "Category", "Formacion" },
		{ "Comment", "// true = va a su posici\xc3\xb3n en el avi\xc3\xb3n, false = vaga libre por el nivel\n" },
		{ "ModuleRelativePath", "Enemigo.h" },
		{ "ToolTip", "true = va a su posici\xc3\xb3n en el avi\xc3\xb3n, false = vaga libre por el nivel" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigo_Statics::NewProp_EscalaFormacion = { "EscalaFormacion", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemigo, EscalaFormacion), METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::NewProp_EscalaFormacion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::NewProp_EscalaFormacion_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemigo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_VelocidadMovimiento,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_WorldLimitesMax,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_IndiceFormacion,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_CentroFormacion,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_bEnFormacion,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigo_Statics::NewProp_EscalaFormacion,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemigo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemigo_Statics::ClassParams = {
		&AEnemigo::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEnemigo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemigo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemigo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemigo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemigo, 1273312024);
	template<> NAVESLAB01USFX_API UClass* StaticClass<AEnemigo>()
	{
		return AEnemigo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemigo(Z_Construct_UClass_AEnemigo, &AEnemigo::StaticClass, TEXT("/Script/NavesLAB01USFX"), TEXT("AEnemigo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
