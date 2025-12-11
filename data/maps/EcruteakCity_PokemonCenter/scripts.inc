.set LOCALID_NURSE, 1
.set LOCALID_ECRUTEAK_BILL, 6

EcruteakCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
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
	faceplayer
	callnative TradeFix
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
	.string "Hi, I'm BILL. And who are you?\p"
	.string "Hmm, {PLAYER}, huh?\n"
	.string "You've come at the right time.$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "I just finished adjustments on my\n"
	.string "POKéMON STORAGE SYSTEM.\p"
	.string "You know that PC you use to store\n"
	.string "all your POKéMON?\p"
	.string "I developed that myself!\p"
	.string "Now that I've installed this one,\n"
	.string "my PC is running at all\l"
	.string "POKéMON CENTERS in JOHTO and KANTO.\p"
	.string "I have to hurry on back to\n"
	.string "GOLDENROD and see my folks. Feel\l"
	.string "free to visit anytime!\p"
	.string "Buh-bye!$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "The way the KIMONO GIRLS dance is\n"
	.string "marvelous.\p"
	.string "Just like the way they use their\n"
	.string "POKéMON.$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "You must be hoping to battle more\n"
	.string "people, right?\p"
	.string "There's apparently some place where\n"
	.string "trainers gather.\p"
	.string "Where, you ask?\p"
	.string "It's a little past OLIVINE CITY.$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "MORTY, the GYM LEADER, is soooo\n"
	.string "cool.\p"
	.string "His POKéMON are really tough too.$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "LAKE OF RAGE…\p"
	.string "The appearance of a GYARADOS\n"
	.string "swarm…\p"
	.string "I smell a conspiracy. I know it!$"

EcruteakCity_PokemonCenter1F_Text_LinkWoman:
	.string "Welcome!\p"
	.string "The ECRUTEAK POKéCENTER is the only\n"
	.string "only POKéMON CENTER that offers\l"
	.string "TRADING and BATTLING with players\l"
	.string "from different games, including:\p"
	.string "POKéMON MODERN EMERALD 3.3+ and official\n"
	.string "POKéMON EMERALD, plus probably the\l"
	.string "rest of the official games (untested!).\p"
	.string "{COLOR RED}Please, DON'T TRY TO TRADE or BATTLE\n"
	.string "with POKéMON that have been put in\l"
	.string "the following POKéBALLS:\p"
	.string "{COLOR DARK_GRAY}LOVE BALL, LURE BALL, FRIEND BALL\n"
	.string "HEAVY BALL, MOON BALL, LEVEL BALL\l"
	.string "FAST BALL or GS BALL.\p"
	.string "At best, nothing will happen.\p"
	.string "At worst, data might get corrupted\n"
	.string "(Not probable, but might be possible).\p"
	.string "Please, fix your Pokémon by talking\n"
	.string "to the MAN sitting on the sofa.$"

EcruteakCity_PokemonCenter1F_Text_Fixer:
	.string "I'm the TRADING FIXER.\p"
	.string "I can fix your {COLOR RED}PARTY{COLOR DARK_GRAY}, meaning {COLOR RED}all six\n"
	.string "of your current POKéMON{COLOR DARK_GRAY} if they've\l"
	.string "been placed in HEART AND SOUL extra\l"
	.string "POKéBALLS.\p"
	.string "You {COLOR RED}don't need{COLOR DARK_GRAY} to do this if you haven't\n"
	.string "placed any of your six POKéMON in HEART\l"
	.string "and SOUL newly added POKéBALLS.\p"
	.string "Continue?$"

EcruteakCity_PokemonCenter1F_Text_Fixer_No:
	.string "I'll be here if you need me.$"

EcruteakCity_PokemonCenter1F_Text_Fixer_Yes_First:
	.string "Are you sure you want to fix your\n"
	.string "{COLOR RED}whole{COLOR DARK_GRAY} party?\l"
	.string "POKéMON on the PC are not affected.\p"
	.string "They will be placed in a normal POKéBALL\n"
	.string "again, if it's necessary.\p"
	.string "Just making sure you're absolutely sure\n"
	.string "about this operation. {COLOR RED}Don't{COLOR DARK_GRAY} press yes if\l"
	.string "you still have POKéMON that haven't\l"
	.string "been placed in the POKéBALLS that the\l"
	.string "the woman at the entrance hasn't\l"
	.string "mentioned.$"

EcruteakCity_PokemonCenter1F_Text_Fixer_Yes_Second:
	.string "Done.$"
