.set LOCALID_NURSE, 1
.set LOCALID_ECRUTEAK_BILL, 6

EcruteakCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Link_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_LinkWoman, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Link_Fixer::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Fixer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EcruteakCity_PokemonCenter_EventScript_Link_Fixer_Yes_First
	goto_if_eq VAR_RESULT, NO, EcruteakCity_PokemonCenter_EventScript_Link_Fixer_No
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Link_Fixer_No::
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Fixer_No, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Link_Fixer_Yes_First::
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Fixer_Yes_First, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EcruteakCity_PokemonCenter_EventScript_Link_Fixer_Yes_Second
	goto_if_eq VAR_RESULT, NO, EcruteakCity_PokemonCenter_EventScript_Link_Fixer_No
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Link_Fixer_Yes_Second::
	special ChoosePartyMon
	waitstate
	special ReverseFixSavePokemon1
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EcruteakCity_PokemonCenter_EventScript_Link_Fixer_No
	msgbox EcruteakCity_PokemonCenter1F_Text_Fixer_Yes_Second, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "Hi, I'm Bill. And who are you?\p"
	.string "Hmm, {PLAYER}, huh?\n"
	.string "You've come at the right time.$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "I just finished adjustments on my\n"
	.string "Pokémon Storage System.\p"
	.string "You know that PC you use to store\n"
	.string "all your Pokémon?\p"
	.string "I developed that myself!\p"
	.string "Now that I've installed this one,\n"
	.string "my PC is running at all\l"
	.string "Pokémon Centers in Johto and Kanto.\p"
	.string "I have to hurry on back to\n"
	.string "Goldenrod and see my folks. Feel\l"
	.string "free to visit anytime!\p"
	.string "Buh-bye!$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "The way the Kimono Girls dance is\n"
	.string "marvelous.\p"
	.string "Just like the way they use their\n"
	.string "Pokémon.$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "You must be hoping to battle more\n"
	.string "people, right?\p"
	.string "There's apparently some place where\n"
	.string "Trainers gather.\p"
	.string "Where, you ask?\p"
	.string "It's a little past Olivine City.$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "Morty, the Gym Leader, is soooo\n"
	.string "cool.\p"
	.string "His Pokémon are really tough too.$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "Lake of Rage…\p"
	.string "The appearance of a Gyarados\n"
	.string "swarm…\p"
	.string "I smell a conspiracy. I know it!$"

EcruteakCity_PokemonCenter1F_Text_LinkWoman:
	.string "Welcome!\p"
	.string "The Ecruteak PokéCenter is the only\n"
	.string "only Pokémon Center that offers\l"
	.string "Trading and Battling with players\l"
	.string "from different games, including:\p"
	.string "Pokémon Modern Emerald 3.3+,\n"
	.string "Pokémon Modern Heart & Soul,\l"
	.string "Pokémon Modern FireRed & LeafGreen,\l"
	.string "and all the official games (only tested\l"
	.string "with Pokémon Emerald).\p"
	.string "{COLOR RED}Pokémon that are in the following\n"
	.string "Poké Balls can't be traded:\p"
	.string "{COLOR DARK_GRAY}Love Ball, Lure Ball, Friend Ball\n"
	.string "Heavy Ball, Moon Ball, Level Ball\l"
	.string "Fast Ball or GS Ball.\p"
	.string "Pokémon that have been in the mentioned\n"
	.string "Poké Balls at any point will show up as\l"
	.string "{COLOR RED}BAD EGGS{COLOR DARK_GRAY} in the second player screen.\p"
	.string "You can fix these Pokémon by talking\n"
	.string "to the Man sitting on the sofa.$"

EcruteakCity_PokemonCenter1F_Text_Fixer:
	.string "I'm the Trading Fixer.\p"
	.string "I can fix your Pokémon if they've ever\n"
	.string "been placed in Heart & Soul extra\l"
	.string "Poké Balls or if they show up as\l"
	.string "BAD EGGS in other games.\p"
	.string "Continue?$"

EcruteakCity_PokemonCenter1F_Text_Fixer_No:
	.string "I'll be here if you need me.$"

EcruteakCity_PokemonCenter1F_Text_Fixer_Yes_First:
	.string "Are you sure you want to fix your\n"
	.string "Pokémon?\p"
	.string "Pokémon on the PC are not affected.\n"
	.string "The selected Pokémon will be placed in a\l"
	.string "common Poké Ball again.\p"
	.string "Just making sure you're absolutely sure\n"
	.string "about this operation.\l"
	.string "{COLOR RED}Don't{COLOR DARK_GRAY} press yes if you aren't sure.$"

EcruteakCity_PokemonCenter1F_Text_Fixer_Yes_Second:
	.string "Done.$"
