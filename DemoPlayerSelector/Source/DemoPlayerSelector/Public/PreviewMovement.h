#pragma once

UENUM(BlueprintType)
enum class EPreviewMovementType : uint8 {
	PM_Idle		UMETA(DisplayName = "Idle"),
	PM_Walk		UMETA(DisplayName = "Walk"),
	PM_Run		UMETA(DisplayName = "Run"),
	PM_Gesture1	UMETA(Displayname = "Gesture 1"),
	PM_Gesture2 UMETA(DisplayName = "Gesture 2"), 
	PM_Spawn	UMETA(DisplayName = "Spawn")
};
