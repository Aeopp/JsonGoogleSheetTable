// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GlobalData.generated.h"

// 해당 타입을 바탕으로 시트를 가져옴.

FString GetTypeID(enum class ESheetType WantTypeID);

UENUM(BlueprintType)
enum class ESheetType : uint8
{
	First,

	TableVersion,
	Weapon,
	Armor,
	Stage,
	Enemy,
	SheetIDs,

	Last,
};

UENUM(BlueprintType)
enum class ETableVersion
{
	First,

	Version,
	MyID,

	Last,

};

USTRUCT(BlueprintType)
struct FTableVersion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=TableVersion)
	float Version;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TableVersion)
	const FString MyID = TEXT("0");

	FORCEINLINE static inline const FString GetSheetID()
	{return Sheet::GetTypeID(ESheetType::TableVersion);}

};

USTRUCT(BlueprintType)
struct FWeapon
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		float Range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		float Pow;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		float Dex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
		float Int;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	const FString MyID = TEXT("133809556");

	FORCEINLINE static inline const FString GetSheetID()
	{return Sheet::GetTypeID(ESheetType::Weapon);}
};




USTRUCT(BlueprintType)
struct FArmor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Armor)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Armor)
		float Defence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Armor)
		float Hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Armor)
		float Shield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Armor)
		float Parts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Armor)
		float Mp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Armor)
		const FString MyID = TEXT("1494651191");

	FORCEINLINE static inline const FString GetSheetID()
	{
		return Sheet::GetTypeID(ESheetType::Armor);
	}
};



USTRUCT(BlueprintType)
struct FStage
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stage)
	int32 Chapter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stage)
		int32 Stage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stage)
		int32 Boss;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stage)
		int32 Monster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stage)
		const FString MyID = TEXT("87110839");

	FORCEINLINE static inline const FString GetSheetID()
	{
		return Sheet::GetTypeID(ESheetType::Stage);
	}
};

USTRUCT(BlueprintType)
struct FEnemy
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
		float  Hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
		float Mp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
		float Def;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
		float Int;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
		const FString MyID = TEXT("87110839");

	FORCEINLINE static inline const FString GetSheetID()
	{
		return Sheet::GetTypeID(ESheetType::Enemy);
	}
};








UENUM(BlueprintType)
enum class EWeapon
{
	First,

	Name,
	Damage,
	Range,
	Pow,
	Dex,
	Int,
	
	MyID,

	Last,

};

UENUM(BlueprintType)
enum class EArmor
{
	First,

	Name,
	Defence,
	Hp,
	Shield,
	Parts,
	Mp,

	MyID,

	Last,
};


UENUM(BlueprintType)
enum class EStage
{
	First,

	Chapter,
	Stage,
	Boss,
	Monster,

	MyID,

	Last,
};

UENUM(BlueprintType)
enum class EEnemy
{
	First,

	Name,
	Hp,
	Mp,
	Def,
	Pow,
	Int,

	MyID,

	Last,
};

UENUM(BlueprintType)
enum class ESheetIDs
{
	First,

	SheetName,
	SheetID,

	MyID,

	Last,
};

namespace Sheet
{
	// 타입 아이디를 넣어주면 그 타입 아이디의 키를 돌려줌
	FORCEINLINE FString GetTypeID(ESheetType WantTypeID)
	{
		FString ReturnTypeID;

		switch (WantTypeID)
		{
		case ESheetType::TableVersion:
			ReturnTypeID = TEXT("0");
			break;
		case ESheetType::Weapon:
			ReturnTypeID =  TEXT("133809556");
			break;
		case ESheetType::Armor:
			ReturnTypeID = TEXT("1494651191");
			break;
		case ESheetType::Stage:
			ReturnTypeID = TEXT("87110839");
			break;
		case ESheetType::Enemy:
			ReturnTypeID = TEXT("1480008117");
			break;
		case ESheetType::SheetIDs:
			ReturnTypeID = TEXT("685081835");
			break;
		default:
			return TEXT("Nothing");
			break;
		}
		return ReturnTypeID;
	}
	// 시트키를 반환한다.
	FORCEINLINE FString GetSheetKey()
	{
		return	TEXT("1pNgAdzAmWeTpXosoRruWd34hQh0heDLf2sKeb2uJ5-E");
	}
}










UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JSONGOOGLEPARSER_API UGlobalData : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGlobalData();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
