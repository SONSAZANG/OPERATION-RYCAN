﻿#include "InventoryEntry.h"
#include "ThreeFPS/Item/ItemDatabase.h"
#include "Components/TextBlock.h"
#include "Character/ThreeFPSCharacter.h"
#include "Components/Button.h"
#include "InventoryWidget.h"
#include "ThreeFPS/Item/ItemBase.h"
#include "Components/Image.h"

void UInventoryEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UItemUIObject* UIItem = Cast<UItemUIObject>(ListItemObject);

	UTexture2D* NewIconTexture = UIItem->ItemData.ItemIcon;
	IconImage->SetBrushFromTexture(NewIconTexture);

	ItemName->SetText(FText::FromString(UIItem->ItemData.ItemName.ToString()));
	ItemDescription->SetText(FText::FromString(UIItem->ItemData.ItemDescription));
	
	UseButton->SetVisibility(UIItem->ItemData.IsUsable ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	UseButton->OnClicked.Clear();
	UseButton->OnClicked.AddDynamic(this, &UInventoryEntry::UseItem);

	DropButton->OnClicked.Clear();
	DropButton->OnClicked.AddDynamic(this, &UInventoryEntry::DropItem);
}

void UInventoryEntry::UseItem()
{
	AThreeFPSCharacter* PlayerCharacter = Cast<AThreeFPSCharacter>(GetOwningPlayer()->GetPawn());
	FItemData ItemData = GetListItem<UItemUIObject>()->ItemData;
	if (!ItemData.IsUsable) return;
	if (AItemBase* ItemBase = Cast<AItemBase>(ItemData.Class->ClassDefaultObject))
	{
		ItemBase->Use(PlayerCharacter);
	}
	PlayerCharacter->Inventory.RemoveSingle(ItemData);
	PlayerCharacter->InventoryWidget->RefreshInventory(PlayerCharacter->Inventory);
}

void UInventoryEntry::DropItem()
{
	AThreeFPSCharacter* PlayerCharacter = Cast<AThreeFPSCharacter>(GetOwningPlayer()->GetPawn());
	FItemData ItemData = GetListItem<UItemUIObject>()->ItemData;
	GetWorld()->SpawnActor<AItemBase>(ItemData.Class, PlayerCharacter->GetActorLocation() + PlayerCharacter->GetActorForwardVector() * 100, FRotator());
	PlayerCharacter->Inventory.RemoveSingle(ItemData);
	PlayerCharacter->InventoryWidget->RefreshInventory(PlayerCharacter->Inventory);
	DropButton->OnClicked.Clear(); 
}
