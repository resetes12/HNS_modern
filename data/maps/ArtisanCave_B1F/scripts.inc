.set LOCALID_BRANDON, 4
.set LOCALID_BRANDON2, 3

ArtisanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
	.byte 0

ArtisanCave_B1F_OnTransition:
	setflag FLAG_LANDMARK_ARTISAN_CAVE
	end

ArtisanCave_B1F_EventScript_Brandon_1::
	lock
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	msgbox ArtisanCave_B1F_Text_Brandon_Cave_1, MSGBOX_NPC
	closemessage
	setflag FLAG_BF_BRANDON_CAVE_1
	applymovement LOCALID_BRANDON, ArtisanCave_B1F_EventScript_Brandon_Movement_1
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	callnative UpdateFollowingPokemon
	release
	end

ArtisanCave_B1F_Text_Brandon_Cave_1::
	.string "BRANDON: Do you know where we are,\n"
	.string "young explorer?\p"
	.string "This cave is known as the ARTISAN CAVE,\n"
	.string "and it usually holds only one kind of\l"
	.string "POKéMON. Well… or so we believed.\p"
	.string "It turns out there are ancient ruins\n"
	.string "here that no one had ever discovered\l"
	.string "until now.\p"
	.string "Strange tremors began some time ago. At\n"
	.string "first, we blamed faulty construction,\l"
	.string "until we heard drilling sounds.\p"
	.string "Six ancient POKéMON forced their way\n"
	.string "into the old cave network beneath us.\p"
	.string "They are known as the LEGENDARY TITANS,\n"
	.string "and I actually have some of them in my\l"
	.string "POKéMON party.\p"
	.string "They are strong! Hahahah!\p"
	.string "Anyway, there are six chambers here.\n"
	.string "Each TITAN is sleeping inside one.\p"
	.string "SCOTT and I think that dealing with\n"
	.string "the TITANS should prevent more cave\l"
	.string "collapses.\p"
	.string "We need someone capable, someone who\n"
	.string "can handle legendary threats, like you.\p"
	.string "Maybe even capture them, if you’re\n"
	.string "up to the task.\p"
	.string "I'm heading up ahead to the final\n"
	.string "chamber. I'll see you there.$"

ArtisanCave_B1F_EventScript_Brandon_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	set_invisible
	step_end

ArtisanCave_B1F_EventScript_Brandon_2::
	lock
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	msgbox ArtisanCave_B1F_Text_Brandon_Cave_2, MSGBOX_NPC
	closemessage
	goto_if_set FLAG_HIDE_REGIROCK, ArtisanCave_B1F_EventScript_Brandon_2_Checked_Regirock
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	callnative UpdateFollowingPokemon
	release
	end

ArtisanCave_B1F_EventScript_Brandon_2_Checked_Regirock::
	goto_if_set FLAG_HIDE_REGICE, ArtisanCave_B1F_EventScript_Brandon_2_Checked_Regice
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	callnative UpdateFollowingPokemon
	release
	end

ArtisanCave_B1F_EventScript_Brandon_2_Checked_Regice::
	goto_if_set FLAG_HIDE_REGISTEEL, ArtisanCave_B1F_EventScript_Brandon_2_Checked_Registeel
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	callnative UpdateFollowingPokemon
	release
	end

ArtisanCave_B1F_EventScript_Brandon_2_Checked_Registeel::
	goto_if_set FLAG_HIDE_REGIELEKI, ArtisanCave_B1F_EventScript_Brandon_2_Checked_Regieleki
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	callnative UpdateFollowingPokemon
	release
	end

ArtisanCave_B1F_EventScript_Brandon_2_Checked_Regieleki::
	goto_if_set FLAG_HIDE_REGIDRAGO, ArtisanCave_B1F_EventScript_Brandon_2_AllChecksCompleted
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	callnative UpdateFollowingPokemon
	release
	end

ArtisanCave_B1F_EventScript_Brandon_2_AllChecksCompleted::
	delay 40
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement OBJ_EVENT_ID_PLAYER, ArtisanCave_B1F_EventScript_PlayerMovement_None
	waitmovement 0
	msgbox ArtisanCave_B1F_Text_Brandon_Cave_2_2, MSGBOX_NPC
	closemessage
	setflag FLAG_BF_BRANDON_CAVE_REGIGAS
	applymovement OBJ_EVENT_ID_PLAYER, ArtisanCave_B1F_EventScript_PlayerMovement
	waitmovement 0
	applymovement LOCALID_BRANDON2, ArtisanCave_B1F_EventScript_Brandon_Movement_2
	waitmovement 0
	callnative RemoveFollowingPokemon
	callnative UpdateFollowingPokemon
	release
	end

ArtisanCave_B1F_Text_Brandon_Cave_2::
	.string "BRANDON: Herein lies REGIGIGAS.\p"
	.string "REGIGIGAS is the strongest of the\n"
	.string "LEGENDARY TITANS.\p"
	.string "However, before letting you proceed,\n"
	.string "you must prove your prowess by\l"
	.string "defeating or capturing the other\l"
	.string "FIVE TITANS.\p"
	.string "Come back when you're done.$"

ArtisanCave_B1F_Text_Brandon_Cave_2_2::
	.string "Oh, you've already dealt with them?\p"
	.string "Excellent. I'll grant you passage to\n"
	.string "the final chamber.\p"
	.string "Good luck, young explorer!\p"
	.string "I'll see you at the BATTLE PYRAMID!$"

ArtisanCave_B1F_EventScript_PlayerMovement:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	face_up
	step_end

ArtisanCave_B1F_EventScript_Brandon_Movement_2:	
	walk_down
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

ArtisanCave_B1F_EventScript_PlayerMovement_None:
	step_end
