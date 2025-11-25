Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_CheatStart::
	lockall
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_GARBAGEFLAGS_LAB_BIRCH
	setflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 2
	setvar VAR_GARBAGEVAR, 3
	givemon SPECIES_TREECKO, 20, ITEM_NONE
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_GARBAGEVAR, 4 @ 4: Received Running Shoes
	setvar VAR_GARBAGEVAR, 7 @ 7: Told to go meet rival
	setvar VAR_GARBAGEVAR, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_GARBAGEVAR, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_GARBAGEVAR, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_GARBAGEVAR, 2
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	closemessage
	release
	end

Debug_Script_1::
	msgbox Debug_Script_1_Text, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, Debug_Script_1_Closemessage
	case MULTI_B_PRESSED, Debug_Script_1_Closemessage
	msgbox Debug_Script_1_Text2, MSGBOX_DEFAULT
	closemessage
	callnative Task_ChooseChallenge_NoNewGame
	end

Debug_Script_1_Closemessage::
	closemessage
	end

Debug_Script_1_Text:
	.string "WARNING! ENTERING THE CHALLENGES\n"
	.string "MENU COULD MESS YOUR SAVE DATA.\p"
	.string "SOME OPTIONS MAY NOT WORK UNLESS A\n"
	.string "NEW GAME IS STARTED. PLEASE BACKUP\p"
	.string "YOUR DATA BEFORE PRESSING YES.$"

Debug_Script_1_Text2:
	.string "ALL OPTIONS YOU CHOSE AT THE START\n"
	.string "OF THE GAME WILL RESET AND YOU\l"
	.string "WILL HAVE TO ENABLE THEM AGAIN.$"

Debug_Script_2::
	goto GoldenrodCity_NameRatersHouse_EventScript_RenameRival
	end

Debug_Script_3::
	callnative CheckNuzlockeMode
	buffernumberstring STR_VAR_1, VAR_UNUSED_0x40DB
	msgbox Text_Easy_Mode, MSGBOX_DEFAULT
	closemessage
	buffernumberstring STR_VAR_1, VAR_UNUSED_0x40DC
	msgbox Text_Normal_Mode, MSGBOX_DEFAULT
	closemessage
	buffernumberstring STR_VAR_1, VAR_UNUSED_0x40FB
	msgbox Text_Hard_Mode, MSGBOX_DEFAULT
	closemessage
	end

Text_Easy_Mode::
	.string "Easy mode is {STR_VAR_1}$"

Text_Normal_Mode::
	.string "Normal mode is {STR_VAR_1}$"

Text_Hard_Mode::
	.string "Hard mode is {STR_VAR_1}$"

Debug_Script_4::
	end

Debug_Script_5::
	end

Debug_Script_6::
	end

Debug_Script_7::
	end

Debug_Script_8::
	end

Debug_CheckSaveBlock::
	callnative CheckSaveBlock1Size
	msgbox Debug_SaveBlock1Size, MSGBOX_DEFAULT
	callnative CheckSaveBlock2Size
	msgbox Debug_SaveBlock2Size, MSGBOX_DEFAULT
	callnative CheckPokemonStorageSize
	msgbox Debug_PokemonStorageSize, MSGBOX_DEFAULT
	release
	end

Debug_SaveBlock1Size::
	.string "SaveBlock1 size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
	.string "Free space: {STR_VAR_3}b.$"

Debug_SaveBlock2Size::
	.string "SaveBlock2 size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
	.string "Free space: {STR_VAR_3}b.$"

Debug_PokemonStorageSize::
	.string "{PKMN}Storage size: {STR_VAR_1}b/{STR_VAR_2}b.\n"
	.string "Free space: {STR_VAR_3}b.$"

Debug_HatchAnEgg::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_HatchAnEgg_NoPokemon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_HatchAnEgg_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_ne VAR_RESULT, SPECIES_EGG, DebugScript_HatchAnEgg_CantForceHatch
	special EggHatch
	waitstate
Debug_HatchAnEgg_End::
	releaseall
	end

Debug_HatchAnEgg_NoPokemon::
	msgbox DebugScript_HatchAnEgg_Text_EmptyParty, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_HatchAnEgg_CantForceHatch::
	msgbox DebugScript_HatchAnEgg_Text_NotAnEgg, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_HatchAnEgg_Text_EmptyParty::
	.string "You have no Pokémon nor Eggs.$"

DebugScript_HatchAnEgg_Text_NotAnEgg::
	.string "That's not a Pokémon Egg.$"
