// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef NAVESLAB01USFX_NavesLAB01USFXProjectile_generated_h
#error "NavesLAB01USFXProjectile.generated.h already included, missing '#pragma once' in NavesLAB01USFXProjectile.h"
#endif
#define NAVESLAB01USFX_NavesLAB01USFXProjectile_generated_h

#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_SPARSE_DATA
#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANavesLAB01USFXProjectile(); \
	friend struct Z_Construct_UClass_ANavesLAB01USFXProjectile_Statics; \
public: \
	DECLARE_CLASS(ANavesLAB01USFXProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NavesLAB01USFX"), NO_API) \
	DECLARE_SERIALIZER(ANavesLAB01USFXProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesANavesLAB01USFXProjectile(); \
	friend struct Z_Construct_UClass_ANavesLAB01USFXProjectile_Statics; \
public: \
	DECLARE_CLASS(ANavesLAB01USFXProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NavesLAB01USFX"), NO_API) \
	DECLARE_SERIALIZER(ANavesLAB01USFXProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANavesLAB01USFXProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANavesLAB01USFXProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANavesLAB01USFXProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANavesLAB01USFXProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANavesLAB01USFXProjectile(ANavesLAB01USFXProjectile&&); \
	NO_API ANavesLAB01USFXProjectile(const ANavesLAB01USFXProjectile&); \
public:


#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANavesLAB01USFXProjectile(ANavesLAB01USFXProjectile&&); \
	NO_API ANavesLAB01USFXProjectile(const ANavesLAB01USFXProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANavesLAB01USFXProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANavesLAB01USFXProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANavesLAB01USFXProjectile)


#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileMesh() { return STRUCT_OFFSET(ANavesLAB01USFXProjectile, ProjectileMesh); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(ANavesLAB01USFXProjectile, ProjectileMovement); }


#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_12_PROLOG
#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_SPARSE_DATA \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_RPC_WRAPPERS \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_INCLASS \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_SPARSE_DATA \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_INCLASS_NO_PURE_DECLS \
	NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NAVESLAB01USFX_API UClass* StaticClass<class ANavesLAB01USFXProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NavesLAB01USFX_master_Source_NavesLAB01USFX_NavesLAB01USFXProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
