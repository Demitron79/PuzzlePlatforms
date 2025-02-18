// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

USTRUCT()
struct FServerData 
{
	GENERATED_BODY()

	FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUsername;
};

/**
*
*/
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize();

public:

	UMainMenu(const FObjectInitializer & ObjectInitialize);

	void SetServerList(TArray<FServerData> ServerName);

	void SelectIndex(uint32 Index);

private:

	TSubclassOf<class UUserWidget> ServerRowClass;

	UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* DirectIPButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ConfirmJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
		class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
		class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
		class UWidget* HostMenu;

	UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* ServerHostName;

	UPROPERTY(meta = (BindWidget))
		class UButton* CancelDirectIPMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ConfirmDirectIPMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UPanelWidget* ServerList;

	UFUNCTION()
		void HostServer();

	UFUNCTION()
		void JoinServer();

	UFUNCTION()
		void DirectIPJoinServer();

	UFUNCTION()
		void OpenJoinMenu();

	UFUNCTION()
		void OpenHostMenu();

	UFUNCTION()
		void OpenMainMenu();

	UFUNCTION()
		void ExitPressed();

	TOptional<uint32> SelectedIndex;

	void UpdateChildren();
};