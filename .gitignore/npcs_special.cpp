#define GOSSIP_TEXT_EXP 14736
#define GOSSIP_CHOOSE_FACTION "I would like to join the horde"
#define GOSSIP_CHOOSE_FACTION2 "I would like to join the alliance"

class npc_Spirit_of_Master_Shang_Xi : public CreatureScript
{
public:
npc_Spirit_of_Master_Shang_Xi() : CreatureScript("npc_Spirit_of_Master_Shang_Xi") { }

bool OnGossipHello(Player* player, Creature* creature)
{
if (creature->IsQuestGiver())
player->PrepareQuestMenu(creature->GetGUID());

if (player->getRace() == RACE_PANDAREN_NEUTRAL)

{
if (player->GetQuestStatus(31450) == QUEST_STATUS_INCOMPLETE)
{ 
AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOOSE_FACTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_CHOOSE_FACTION2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
}
}

player->PlayerTalkClass->SendGossipMenu(GOSSIP_TEXT_EXP, creature->GetGUID());
return true;
}

bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
{
if (action == GOSSIP_ACTION_INFO_DEF + 1)
{
player->SetByteValue(UNIT_FIELD_BYTES_0, 0, RACE_PANDAREN_HORDE);
player->setFactionForRace(RACE_PANDAREN_HORDE);
player->SaveToDB();
WorldLocation location(1, 1357.62f, -4373.55f, 26.13f, 0.13f);
player->TeleportTo(location);
player->SetHomebind(location, 363);
player->LearnSpell(668, false); // Language Common
player->LearnSpell(108127, false); // Language Pandaren
player->KilledMonsterCredit(64594);
}

if (action == GOSSIP_ACTION_INFO_DEF + 2)
{
player->SetByteValue(UNIT_FIELD_BYTES_0, 0, RACE_PANDAREN_ALLIANCE);
player->setFactionForRace(RACE_PANDAREN_ALLIANCE);
player->SaveToDB();
WorldLocation location(0, -8960.02f, 516.10f, 96.36f, 0.67f);
player->TeleportTo(location);
player->SetHomebind(location, 9);
player->LearnSpell(668, false); // Language Common
player->LearnSpell(108127, false); // Language Pandaren
player->KilledMonsterCredit(64594);
}

player->PlayerTalkClass->SendCloseGossip();
return true;
}
};

void AddSC_npcs_special()
{
new npc_Spirit_of_Master_Shang_Xi();
}
