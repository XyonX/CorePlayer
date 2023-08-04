/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CorePlugin/Data/AnimationData.h"
#include "CoreAnimInstance.generated.h"


struct FCoreAnimInstanceProxy;
UCLASS()
class COREPLAYER_API UCoreAnimInstance : public UAnimInstance
{
	
	GENERATED_BODY()

public:
	UCoreAnimInstance();

	//Function only called at the starting
	virtual void NativeInitializeAnimation() override;


	UFUNCTION(BlueprintCallable, Category = "Animation")
	void UpdateAnimationData(FAnimationData InAnimationData){CurrentAnimationData=InAnimationData;};

	
	/** Animation data Receiver */
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Receiver_AnimationData (FAnimationData InAnimData);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Receiver_Velocity (FVector InValue);
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Receiver_CharacterWorldLocation (FVector InValue);
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Receiver_MovementDirection (FVector InValue);
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Receiver_ControlRotation (FRotator InValue);
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Receiver_CharacterRotation (FRotator InValue);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Receiver_JumpingStatus (bool InValue);
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Receiver_CrouchStatus (bool InValue);
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Receiver_InAirStatus (bool InValue);


	
protected:

	/** Default Animation data to start with */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data")
	FAnimationData DefaultAnimationData;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Data")
	FAnimationData CurrentAnimationData;
	

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float MovementOffset;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float MovementOffsetAccel ;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float Character_Yaw;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float Character_Yaw_LastFrame;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float Root_Yaw_Offset_PerFrame;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bIsAccelerating ;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float Root_Yaw_Offset;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float PivotTime;
	
	float NormalTolerance ;
	


	TSharedPtr<FCoreAnimInstanceProxy>Proxy;
	
};
