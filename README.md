# State Tree Extension
[![Version](https://img.shields.io/github/v/release/piperift/StateTreeExtension?label=version)](https://github.com/PipeRift/ActionsExtension/releases)
![UE](https://img.shields.io/badge/UE5-5.7%2B-orange)
[![Piperift Discord](https://img.shields.io/discord/288221302089711616?color=%237289da&label=discord)](https://discord.gg/nnsdr22)

State Tree Extension is a lightweight plugin that adds common missing features for State Trees (Unreal Engine).

If you like Piperift´s work, consider becoming a Patron. It will go a long way in helping us and our projects!

[![patron](Resources/patron_small.png)](https://www.patreon.com/join/piperift)

## Features
Keep in mind all features are related to state trees.

- Tasks
  - Add Tag
  - Remove Tag
- Property Functions
  - Vectors
    - Add: FVector, FVector2D, FIntVector & FIntPoint
    - Subtract: FVector, FVector2D, FIntVector & FIntPoint
    - Distance: FVector, FVector2D, FIntVector & FIntPoint
    - Distance Squared: FVector, FVector2D, FIntVector & FIntPoint
  - Gameplay Tags
    - Has Tag
    - Has Any Tags
    - Has All Tags
    - Matches Query
  - Components
    - Get Component Location
  - Enums
    - Has Any: check if the left enum mask has any of the right flags
      ![Has Any](Docs/Assets/EnumHasAnyFunction.png)
    - Has All: check if the left enum mask has all of the right flags
      ![Has All](Docs/Assets/EnumHasAllFunction.png)
    - Equals: check if the left enum equals the right
      ![Equals](Docs/Assets/EnumEqualsFunction.png)
- Conditions
  - Distance Compare: FVector2D, FIntVector & FIntPoint. (FVector already supported by the engine)
    ![Distance Compare](Docs/Assets/DistanceCompare.png)
  - Flag Compare: check if a flag enum value matches another (Exactly, Any or All)
    ![Flag Compare](Docs/Assets/FlagCompare.png)