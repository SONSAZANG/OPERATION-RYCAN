// Boss AI - 신설빈

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskCppJumpAtk.generated.h"

/**
 * 
 */
UCLASS()
class THREEFPS_API UBTTaskCppJumpAtk : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTaskCppJumpAtk();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
