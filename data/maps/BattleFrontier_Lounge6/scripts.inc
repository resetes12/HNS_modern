BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "My POKéMON is a SKITTY.\n"
	.string "Do you know it?\l"
	.string "It's quite cute and rather nice.\p"
	.string "This little one, I couldn't trade with\n"
	.string "pride!$"

@	
@	lock
@	faceplayer
@	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
@	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
@	copyvar VAR_0x8004, VAR_0x8008
@	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
@	copyvar VAR_0x8009, VAR_RESULT
@	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
@	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
@	special ChoosePartyMon
@	waitstate
@	copyvar VAR_0x800A, VAR_0x8004
@	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
@	copyvar VAR_0x8005, VAR_0x800A
@	specialvar VAR_RESULT, GetTradeSpecies
@	copyvar VAR_0x800B, VAR_RESULT
@	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
@	copyvar VAR_0x8004, VAR_0x8008
@	copyvar VAR_0x8005, VAR_0x800A
@	special CreateInGameTradePokemon
@	special DoInGameTradeScene
@	waitstate
@	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
@	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
@	release
@	end
@
@BattleFrontier_Lounge6_EventScript_DeclineTrade::
@	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
@	release
@	end
@
@BattleFrontier_Lounge6_EventScript_NotRequestedMon::
@	bufferspeciesname STR_VAR_1, VAR_0x8009
@	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
@	release
@	end
@
@BattleFrontier_Lounge6_EventScript_TradeCompleted::
@	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
@	release
@	end

@BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
@	.string "Oh, it's adorable!\n"
@	.string "Thank you!\l"
@	.string "I promise I'll be good to it!\p"
@	.string "Oh! I hope you'll be good to\n"
@	.string "my {STR_VAR_2}, too!$"
@
@BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
@	.string "Oh, I'm sorry!\n"
@	.string "I don't intend to trade for anything\l"
@	.string "but a {STR_VAR_1}.$"
@
@BattleFrontier_Lounge6_Text_WellThatsFineToo:
@	.string "Oh, you won't?\n"
@	.string "Well, that's fine, too.\l"
@	.string "Please come visit us again.$"
@
@BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
@	.string "Giggle!\n"
@	.string "A SKITTY is so much cuter than I had\l"
@	.string "imagined. I'm delighted!$"

BattleFrontier_Lounge6_EventScript_Hiker::
	faceplayer
	goto_if_set FLAG_ARCEUS_EGG, BattleFrontier_Lounge6_EventScript_Hiker_FinishedEvent
	msgbox BattleFrontier_Lounge6_Text_Hiker, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge6_EventScript_Hiker_Yes
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_Hiker_No
	closemessage
	end

BattleFrontier_Lounge6_EventScript_Hiker_No::
	faceplayer
	msgbox BattleFrontier_Lounge6_Text_Hiker_No, MSGBOX_NPC
	closemessage
	end

BattleFrontier_Lounge6_EventScript_Hiker_Yes::
	faceplayer
	msgbox BattleFrontier_Lounge6_Text_Hiker_Yes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_Lounge6_EventScript_Hiker_Yes_Pay
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_Hiker_No_Pay
	closemessage
	end

BattleFrontier_Lounge6_EventScript_Hiker_No_Pay::
	faceplayer
	msgbox BattleFrontier_Lounge6_Text_Hiker_No_Pay, MSGBOX_NPC
	closemessage
	end

BattleFrontier_Lounge6_EventScript_Hiker_Yes_Pay::
	setvar VAR_0x8008, 9999
	specialvar VAR_TEMP_C, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_C, VAR_0x8008, BattleFrontier_Lounge6_EventScript_Hiker_Yes_Pay_EnoughMoney
	faceplayer
	msgbox BattleFrontier_Lounge6_Text_Hiker_Pay_NoMoney, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_Hiker_Yes_Pay_EnoughMoney::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	faceplayer
	msgbox BattleFrontier_Lounge6_Text_Hiker_Yes_Pay, MSGBOX_NPC
	setflag FLAG_ARCEUS_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_ARCEUS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BattleFrontier_Lounge6_EventScript_Hiker_ArceusEggToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BattleFrontier_Lounge6_EventScript_Hiker_ArceusEggToPC
	release
	end

BattleFrontier_Lounge6_EventScript_Hiker_ArceusEggToParty::
	call Common_EventScript_GetGiftMonPartySlot
	faceplayer
	msgbox BattleFrontier_Lounge6_Text_Hiker_Yes_AcceptedEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_Hiker_ArceusEggToPC::
	call Common_EventScript_TransferredToPC
	faceplayer
	msgbox BattleFrontier_Lounge6_Text_Hiker_Yes_AcceptedEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_Hiker_FinishedEvent::
	faceplayer
	msgbox BattleFrontier_Lounge6_Text_Hiker_PostEvent, MSGBOX_NPC
	closemessage
	end

BattleFrontier_Lounge6_Text_Hiker:
	.string "I'm here because a friend of mine told\n"
	.string "me that after the recent earthquakes\l"
	.string "you can find literal gold around here!\p"
	.string "I love money, so I had to come here to\n"
	.string "take a good look. Then…\l"
	.string "I found a strange, sturdy EGG!\p"
	.string "It was under the rubble. I say EGG, but\n"
	.string "it looks more like a fossil than an EGG,\l"
	.string "to be honest.\p"
	.string "Would you like to have it?$"

BattleFrontier_Lounge6_Text_Hiker_Yes:
	.string "I see…\p"
	.string "So you see value in this strange EGG?\p"
	.string "Then it must mean that it's valuable!\p"
	.string "Hmmm…"
	.string "Then, I'll give it to you for the\n"
	.string "low price of 999 BATTLE POINTS!\p"
	.string "That's surely a good price, right?$"

BattleFrontier_Lounge6_Text_Hiker_No:
	.string "Of course you don't.\n"
	.string "This EGG has no value, right?$"

BattleFrontier_Lounge6_Text_Hiker_No_Pay:
	.string "The price is non-negotiable.\n"
	.string "I won't give you a discount.$"

BattleFrontier_Lounge6_Text_Hiker_Pay_NoMoney:
	.string "You don't have enough BP.\p"
	.string "The price is non-negotiable.\n"
	.string "I won't give you a discount.$"

BattleFrontier_Lounge6_Text_Hiker_Yes_Pay:
	.string "There, for you.$"

BattleFrontier_Lounge6_Text_Hiker_Yes_AcceptedEgg:
	.string "Who knows which POKéMON might hatch,\n"
	.string "if it's really a POKéMON EGG.$"

BattleFrontier_Lounge6_Text_Hiker_PostEvent:
	.string "BATTLE POINTS are a worldwide\n"
	.string "currency.\p"
	.string "There are places where you can exchange\n"
	.string "them for real money.\p"
	.string "You can't do it here, however.$"
