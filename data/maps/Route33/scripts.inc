Route33_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten, Route33_EventScript_HikerAnthony_Register
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route33_EventScript_HikerAnthony_Rematch
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_HikerAnthony_Register::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route33_Text_HikerAnthony_Register, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANTHONY
	release
	end

Route33_EventScript_HikerAnthony_Rematch::
	trainerbattle_rematch TRAINER_ANTHONY, Route33_Text_HikerAnthony_Seen_Rematch, Route33_Text_HikerAnthony2Beaten
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "I came through the tunnel,\n"
	.string "but I still have plenty\l"
	.string "of energy left.$"

Route33_Text_HikerAnthony_Seen_Rematch:
	.string "I still have plenty of energy\n"
	.string "left for a rematch!$"

Route33_Text_HikerAnthony_Register:
	.string "You have lots of energy!\p"
	.string "Will you be up for a rematch?$"

Route33_Text_HikerAnthony2Beaten:
	.string "Whoa! You've got more zip\n"
	.string "than me!$"

Route33_Text_HikerAnthony2After:
	.string "We Hikers are at our best\n"
	.string "in the mountains.$"

Route33_Text_HikerAnthonyDunsparce:
	.string "Hey, did you get a Dunsparce?\p"
	.string "I caught one too.\p"
	.string "Take a look at it in the light.\n"
	.string "It's got a funny face!$"

Route33_Text_Lass:
	.string "Pant, pant…\p"
	.string "That cave was bigger than\n"
	.string "I'd expected.\p"
	.string "I got too tired exploring\n"
	.string "for Marill, so I came outside.$"
