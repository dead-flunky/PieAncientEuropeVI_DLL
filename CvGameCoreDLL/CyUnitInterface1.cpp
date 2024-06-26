#include "CvGameCoreDLL.h"
#include "CyUnit.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CyArea.h"
#include "CySelectionGroup.h"
#include "CyArtFileMgr.h"
#include "CvInfos.h"

//# include <boost/python/manage_new_object.hpp>
//# include <boost/python/return_value_policy.hpp>

//
// published python interface for CyUnit
//

void CyUnitPythonInterface1(python::class_<CyUnit>& x)
{
	OutputDebugString("Python Extension Module - CyUnitPythonInterface1\n");

	x
		.def("isNone", &CyUnit::isNone, "bool () - Is this a valid unit instance?")
		.def("convert", &CyUnit::convert, "void (CyUnit* pUnit)")
		.def("kill", &CyUnit::kill, "void (bool bDelay, int (PlayerTypes) ePlayer)")
		.def("NotifyEntity", &CyUnit::NotifyEntity, "void (int (MissionTypes) eEvent)")
		
		.def("isActionRecommended", &CyUnit::isActionRecommended, "bool (int i)")
		.def("isBetterDefenderThan", &CyUnit::isBetterDefenderThan, "bool (CyUnit* pDefender, CyUnit* pAttacker)")

		.def("canDoCommand", &CyUnit::canDoCommand, "bool (CommandTypes eCommand, int iData1, int iData2, bool bTestVisible) - can the unit perform eCommand?")
		.def("doCommand", &CyUnit::doCommand, "void (CommandTypes eCommand, int iData1, int iData2) - force the unit to perform eCommand")

		.def("getPathEndTurnPlot", &CyUnit::getPathEndTurnPlot, python::return_value_policy<python::manage_new_object>(), "CyPlot* ()")
		.def("generatePath", &CyUnit::generatePath, "bool (CyPlot* pToPlot, int iFlags, bool bReuse, int* piPathTurns)")

		.def("canEnterTerritory", &CyUnit::canEnterTerritory, "bool (int (TeamTypes) eTeam, bool bIgnoreRightOfPassage)")
		.def("canEnterArea", &CyUnit::canEnterArea, "bool (int (TeamTypes) eTeam, CyArea* pArea, bool bIgnoreRightOfPassage)")
		.def("getDeclareWarMove", &CyUnit::getDeclareWarMove, "int (TeamTypes) (CyPlot* pPlot)")
		.def("canMoveInto", &CyUnit::canMoveInto, "bool (CyPlot* pPlot, bool bAttack, bool bDeclareWar, bool bIgnoreLoad)")
		.def("canMoveOrAttackInto", &CyUnit::canMoveOrAttackInto, "bool (CyPlot* pPlot, bool bDeclareWar)")
		.def("canMoveThrough", &CyUnit::canMoveThrough, "bool (CyPlot* pPlot)")
		.def("jumpToNearestValidPlot", &CyUnit::jumpToNearestValidPlot, "bool ()")

		.def("canAutomate", &CyUnit::canAutomate, "bool (AutomateTypes eAutomate)")
		.def("canScrap", &CyUnit::canScrap, "bool ()")
		.def("canGift", &CyUnit::canGift, "bool (bool bTestVisible)")
		.def("canLoadUnit", &CyUnit::canLoadUnit, "bool (CyUnit* pUnit, CyPlot* pPlot)")
		.def("canLoad", &CyUnit::canLoad, "bool (CyUnit* pUnit, CyPlot* pPlot)")
		.def("canUnload", &CyUnit::canUnload, "bool ()")
		.def("canUnloadAll", &CyUnit::canUnloadAll, "bool ()")
		.def("canHold", &CyUnit::canHold, "bool (CyPlot* pPlot)")
		.def("canSleep", &CyUnit::canSleep, "bool (CyPlot* pPlot)")
		.def("canFortify", &CyUnit::canFortify, "bool (CyPlot* pPlot)")
		.def("canPlunder", &CyUnit::canPlunder, "bool (CyPlot* pPlot)")
		.def("canAirPatrol", &CyUnit::canAirPatrol, "bool (CyPlot* pPlot)")
		.def("canSeaPatrol", &CyUnit::canSeaPatrol, "bool (CyPlot* pPlot)")
		.def("canHeal", &CyUnit::canHeal, "bool (CyPlot* pPlot)")
		.def("canSentry", &CyUnit::canSentry, "bool (CyPlot* pPlot)")

		.def("canAirlift", &CyUnit::canAirlift, "bool (CyPlot* pPlot)")
		.def("canAirliftAt", &CyUnit::canAirliftAt, "bool (CyPlot* pPlot, int iX, int iY)")

		.def("isNukeVictim", &CyUnit::isNukeVictim, "bool (CyPlot* pPlot, int (TeamTypes) eTeam)")
		.def("canNuke", &CyUnit::canNuke, "bool (CyPlot* pPlot)")
		.def("canNukeAt", &CyUnit::canNukeAt, "bool (CyPlot* pPlot, int iX, int iY)")

		.def("canRecon", &CyUnit::canRecon, "bool (CyPlot* pPlot)")
		.def("canReconAt", &CyUnit::canReconAt, "bool (CyPlot* pPlot, int iX, int iY)")

		.def("canRecon", &CyUnit::canParadrop, "bool (CyPlot* pPlot)")
		.def("canReconAt", &CyUnit::canParadropAt, "bool (CyPlot* pPlot, int iX, int iY)")

		.def("canAirBomb", &CyUnit::canAirBomb, "bool (CyPlot* pPlot)")
		.def("canAirBombAt", &CyUnit::canAirBombAt, "bool (CyPlot* pPlot, int iX, int iY)")

		.def("bombardTarget", &CyUnit::bombardTarget, python::return_value_policy<python::manage_new_object>(), "CyCity* (CyPlot* pPlot)")
		.def("canBombard", &CyUnit::canBombard, "bool (CyPlot* pPlot)")

		.def("canPillage", &CyUnit::canPillage, "bool (CyPlot* pPlot)")
		.def("sabotageCost", &CyUnit::sabotageCost, "int (CyPlot* pPlot)")
		.def("sabotageProb", &CyUnit::sabotageProb, "int (CyPlot* pPlot, int (ProbabilityTypes) eProbStyle)")
		.def("canSabotage", &CyUnit::canSabotage, "bool (CyPlot* pPlot, bool bTestVisible)")
		.def("destroyCost", &CyUnit::destroyCost, "int (CyPlot* pPlot)")
		.def("destroyProb", &CyUnit::destroyProb, "int (CyPlot* pPlot, int (ProbabilityTypes) eProbStyle)")
		.def("canDestroy", &CyUnit::canDestroy, "bool (CyPlot* pPlot, bool bTestVisible)")
		.def("stealPlansCost", &CyUnit::stealPlansCost, "int (CyPlot* pPlot)")
		.def("stealPlansProb", &CyUnit::stealPlansProb, "int (CyPlot* pPlot, int (ProbabilityTypes) eProbStyle)")
		.def("canStealPlans", &CyUnit::canStealPlans, "bool (CyPlot* pPlot, bool bTestVisible)")

		.def("canFound", &CyUnit::canFound, "bool (CyPlot* pPlot, bool bTestVisible)")
		.def("canSpread", &CyUnit::canSpread, "bool (CyPlot* pPlot, int (ReligionTypes) eReligion, bool bTestVisible)")
		.def("canJoin", &CyUnit::canJoin, "bool (CyPlot* pPlot, int (SpecialistTypes) eSpecialist)")
		.def("canConstruct", &CyUnit::canConstruct, "bool (CyPlot* pPlot, int (BuildingTypes) eBuilding)")

		.def("getDiscoveryTech", &CyUnit::getDiscoveryTech, "int (TechTypes) ()")
		.def("getDiscoverResearch", &CyUnit::getDiscoverResearch, "int (int (TechTypes) eTech)")
		.def("canDiscover", &CyUnit::canDiscover, "bool (CyPlot* pPlot)")
		.def("getMaxHurryProduction", &CyUnit::getMaxHurryProduction, "int (CyCity* pCity)")
		.def("getHurryProduction", &CyUnit::getHurryProduction, "int (CyPlot* pPlot)")
		.def("canHurry", &CyUnit::canHurry, "bool (CyPlot* pPlot, bool bTestVisible)")
		.def("getTradeGold", &CyUnit::getTradeGold, "int (CyPlot* pPlot)")
		.def("canTrade", &CyUnit::canTrade, "bool (CyPlot* pPlot, bool bTestVisible)")
		.def("getGreatWorkCulture", &CyUnit::getGreatWorkCulture, "int (CyPlot* pPlot)")
		.def("canGreatWork", &CyUnit::canGreatWork, "bool (CyPlot* pPlot)")
		.def("getEspionagePoints", &CyUnit::getEspionagePoints, "int (CyPlot* pPlot)")
		.def("canInfiltrate", &CyUnit::canInfiltrate, "bool (CyPlot* pPlot, bool bTestVisible)")
		.def("canEspionage", &CyUnit::canEspionage, "bool (CyPlot* pPlot)")

		.def("canGoldenAge", &CyUnit::canGoldenAge, "bool (CyPlot* pPlot, bool bTestVisible)")
		.def("canBuild", &CyUnit::canBuild, "bool (CyPlot* pPlot, int (BuildTypes) eBuild, bool bTestVisible)")
		.def("canLead", &CyUnit::canLead, "int (CyPlot* pPlot, int iUnitId)")
		.def("lead", &CyUnit::lead, "bool (int iUnitId)")
		.def("canGiveExperience", &CyUnit::canGiveExperience, "int (CyPlot* pPlot)")
		.def("giveExperience", &CyUnit::giveExperience, "bool ()")

		.def("canPromote", &CyUnit::canPromote, "bool (int (PromotionTypes) ePromotion, int iLeaderUnitId)")
		.def("promote", &CyUnit::promote, "void (int (PromotionTypes) ePromotion, int iLeaderUnitId)")

		.def("upgradePrice", &CyUnit::upgradePrice, "int (int (UnitTypes) eUnit)")
		.def("upgradeAvailable", &CyUnit::upgradeAvailable, "bool (int (UnitTypes) eFromUnit, int (UnitClassTypes) eToUnitClass, int iCount)")
		.def("canUpgrade", &CyUnit::canUpgrade, "bool (int (UnitTypes) eUnit, bool bTestVisible)")
		.def("hasUpgrade", &CyUnit::hasUpgrade, "bool (bool bSearch)")

		.def("getHandicapType", &CyUnit::getHandicapType, "int (HandicapTypes) ()")
		.def("getCivilizationType", &CyUnit::getCivilizationType, "int (CivilizationTypes) ()")
		.def("getSpecialUnitType", &CyUnit::getSpecialUnitType, "int (SpecialUnitTypes) ()")
		.def("getCaptureUnitType", &CyUnit::getCaptureUnitType, "int (UnitTypes) (int (CivilizationTypes) eCivilization)")
		.def("getUnitCombatType", &CyUnit::getUnitCombatType, "int (UnitCombatTypes) ()")
		.def("getDomainType", &CyUnit::getDomainType, "int (DomainTypes) ()")
		.def("getInvisibleType", &CyUnit::getInvisibleType, "int (InvisibleTypes) ()")
		.def("getNumSeeInvisibleTypes", &CyUnit::getNumSeeInvisibleTypes, "int ()")
		.def("getSeeInvisibleType", &CyUnit::getSeeInvisibleType, "int (InvisibleTypes) (int i)")

		.def("flavorValue", &CyUnit::flavorValue, "int (int (FlavorTypes) eFlavor)")
		.def("isBarbarian", &CyUnit::isBarbarian, "bool ()")
		.def("isHuman", &CyUnit::isHuman, "bool ()")
		.def("visibilityRange", &CyUnit::visibilityRange, "int ()")
		.def("baseMoves", &CyUnit::baseMoves, "int ()")
		.def("movesLeft", &CyUnit::movesLeft, "int ()")

		.def("maxMoves", &CyUnit::maxMoves, "int ()")
		.def("canMove", &CyUnit::canMove, "bool (CyPlot* pPlot, bool bAttack, bool bDeclareWar, bool bIgnoreLoad)")
		.def("hasMoved", &CyUnit::hasMoved, "bool ()")
		.def("airRange", &CyUnit::airRange, "int ()")
		.def("nukeRange", &CyUnit::nukeRange, "int ()")

		.def("canBuildRoute", &CyUnit::canBuildRoute, "bool ()")
		.def("getBuildType", &CyUnit::getBuildType, "int (BuildTypes) ()")
		.def("workRate", &CyUnit::workRate, "int (bool bMax)")

		.def("isAnimal", &CyUnit::isAnimal, "bool ()")
		.def("isNoBadGoodies", &CyUnit::isNoBadGoodies, "bool ()")
		.def("isOnlyDefensive", &CyUnit::isOnlyDefensive, "bool ()")
		.def("isNoCapture", &CyUnit::isNoCapture, "bool ()")
		.def("isRivalTerritory", &CyUnit::isRivalTerritory, "bool ()")
		.def("isMilitaryHappiness", &CyUnit::isMilitaryHappiness, "bool ()")
		.def("isInvestigate", &CyUnit::isInvestigate, "bool ()")
		.def("isCounterSpy", &CyUnit::isCounterSpy, "bool ()")
		.def("isFound", &CyUnit::isFound, "bool ()")
		.def("isGoldenAge", &CyUnit::isGoldenAge, "bool ()")
		.def("canCoexistWithEnemyUnit", &CyUnit::canCoexistWithEnemyUnit, "bool (int (TeamTypes) eTeam)")

		.def("isFighting", &CyUnit::isFighting, "bool ()")
		.def("isAttacking", &CyUnit::isAttacking, "bool ()")
		.def("isDefending", &CyUnit::isDefending, "bool ()")
		.def("isCombat", &CyUnit::isCombat, "bool ()")
		.def("maxHitPoints", &CyUnit::maxHitPoints, "int ()")
		.def("currHitPoints", &CyUnit::currHitPoints, "int ()")
		.def("isHurt", &CyUnit::isHurt, "bool ()")
		.def("isDead", &CyUnit::isDead, "bool ()")
		.def("setBaseCombatStr", &CyUnit::setBaseCombatStr, "void (int iCombat)")
		.def("baseCombatStr", &CyUnit::baseCombatStr, "int ()")
		.def("maxCombatStr", &CyUnit::maxCombatStr, "int (CyPlot* pPlot, CyUnit* pAttacker)")
		.def("currCombatStr", &CyUnit::currCombatStr, "int (CyPlot* pPlot, CyUnit* pAttacker)")
		.def("currFirepower", &CyUnit::currFirepower, "int (CyPlot* pPlot, CyUnit* pAttacker)")
		.def("maxCombatStrFloat", &CyUnit::maxCombatStrFloat, "float (CyPlot* pPlot, CyUnit* pAttacker)")
		.def("currCombatStrFloat", &CyUnit::currCombatStrFloat, "float (CyPlot* pPlot, CyUnit* pAttacker)")

		.def("canFight", &CyUnit::canFight, "bool ()")
		.def("canAttack", &CyUnit::canAttack, "bool ()")
		.def("canDefend", &CyUnit::canDefend, "bool (CyPlot* pPlot)")
		.def("canSiege", &CyUnit::canSiege, "bool (int (TeamTypes) eTeam)")

		.def("airBaseCombatStr", &CyUnit::airBaseCombatStr, "int ()")
		.def("airMaxCombatStr", &CyUnit::airMaxCombatStr, "int (CyUnit* pOther)")
		.def("airCurrCombatStr", &CyUnit::airCurrCombatStr, "int (CyUnit* pOther)")
		.def("airMaxCombatStrFloat", &CyUnit::airMaxCombatStrFloat, "float (CyUnit* pOther)")
		.def("airCurrCombatStrFloat", &CyUnit::airCurrCombatStrFloat, "float (CyUnit* pOther)")
		.def("combatLimit", &CyUnit::combatLimit, "int ()")
		.def("airCombatLimit", &CyUnit::airCombatLimit, "int ()")
		.def("canAirAttack", &CyUnit::canAirAttack, "bool ()")
		.def("canAirDefend", &CyUnit::canAirDefend, "bool (CyPlot* pPlot)")
		.def("airCombatDamage", &CyUnit::airCombatDamage, "int (CyUnit* pDefender)")
		.def("bestInterceptor", &CyUnit::bestInterceptor, python::return_value_policy<python::manage_new_object>(), "CyUnit* (CyPlot* pPlot)")

		.def("isAutomated", &CyUnit::isAutomated, "bool ()")
		.def("isWaiting", &CyUnit::isWaiting, "bool ()")
		.def("isFortifyable", &CyUnit::isFortifyable, "bool ()")
		.def("fortifyModifier", &CyUnit::fortifyModifier, "int ()")
		.def("experienceNeeded", &CyUnit::experienceNeeded, "int ()") 
		.def("attackXPValue", &CyUnit::attackXPValue, "int ()") 
		.def("defenseXPValue", &CyUnit::defenseXPValue, "int ()")
		.def("maxXPValue", &CyUnit::maxXPValue, "int ()")
		.def("firstStrikes", &CyUnit::firstStrikes, "int ()")
		.def("chanceFirstStrikes", &CyUnit::chanceFirstStrikes, "int ()")
		.def("maxFirstStrikes", &CyUnit::maxFirstStrikes, "int ()")
		.def("isRanged", &CyUnit::isRanged, "bool ()")
		.def("alwaysInvisible", &CyUnit::alwaysInvisible, "bool ()")

		.def("immuneToFirstStrikes", &CyUnit::immuneToFirstStrikes, "bool ()")
		.def("noDefensiveBonus", &CyUnit::noDefensiveBonus, "bool ()")
		.def("ignoreBuildingDefense", &CyUnit::ignoreBuildingDefense, "bool ()")
		.def("canMoveImpassable", &CyUnit::canMoveImpassable, "bool ()")
		.def("canMoveAllTerrain", &CyUnit::canMoveAllTerrain, "bool ()")
		.def("flatMovementCost", &CyUnit::flatMovementCost, "bool ()")
		.def("ignoreTerrainCost", &CyUnit::ignoreTerrainCost, "bool ()")
		.def("isNeverInvisible", &CyUnit::isNeverInvisible, "bool ()")
		.def("isInvisible", &CyUnit::isInvisible, "bool (int (TeamTypes) eTeam, bool bDebug)")
		.def("isNukeImmune", &CyUnit::isNukeImmune, "bool ()")

		.def("maxInterceptionProbability", &CyUnit::maxInterceptionProbability, "int ()")
		.def("currInterceptionProbability", &CyUnit::currInterceptionProbability, "int ()")
		.def("evasionProbability", &CyUnit::evasionProbability, "int ()")
		.def("withdrawalProbability", &CyUnit::withdrawalProbability, "int ()")
		.def("collateralDamage", &CyUnit::collateralDamage, "int ()")
		.def("collateralDamageLimit", &CyUnit::collateralDamageLimit, "int ()")
		.def("collateralDamageMaxUnits", &CyUnit::collateralDamageMaxUnits, "int ()")

		.def("cityAttackModifier", &CyUnit::cityAttackModifier, "int ()")
		.def("cityDefenseModifier", &CyUnit::cityDefenseModifier, "int ()")
		.def("animalCombatModifier", &CyUnit::animalCombatModifier, "int ()")
		.def("hillsAttackModifier", &CyUnit::hillsAttackModifier, "int ()")
		.def("hillsDefenseModifier", &CyUnit::hillsDefenseModifier, "int ()")
		.def("terrainAttackModifier", &CyUnit::terrainAttackModifier, "int (int (TerrainTypes) eTerrain)")
		.def("terrainDefenseModifier", &CyUnit::terrainDefenseModifier, "int (int (TerrainTypes) eTerrain)")
		.def("featureAttackModifier", &CyUnit::featureAttackModifier, "int (int (FeatureTypes) eFeature)")
		.def("featureDefenseModifier", &CyUnit::featureDefenseModifier, "int (int (FeatureTypes) eFeature)")
		.def("unitClassAttackModifier", &CyUnit::unitClassAttackModifier, "int (int (UnitClassTypes) eUnitClass)")
		.def("unitClassDefenseModifier", &CyUnit::unitClassDefenseModifier, "int (int (UnitClassTypes) eUnitClass)")
		.def("unitCombatModifier", &CyUnit::unitCombatModifier, "int (int (UnitCombatTypes) eUnitCombat)")
		.def("domainModifier", &CyUnit::domainModifier, "int (int (DomainTypes) eDomain)")

		.def("bombardRate", &CyUnit::bombardRate, "int ()") 
		.def("airBombBaseRate", &CyUnit::airBombBaseRate, "int ()")
		.def("airBombCurrRate", &CyUnit::airBombCurrRate, "int ()")

		.def("specialCargo", &CyUnit::specialCargo, "int (SpecialUnitTypes) ()")
		.def("domainCargo", &CyUnit::domainCargo, "int (DomainTypes) ()")
		.def("cargoSpace", &CyUnit::cargoSpace, "int ()")
		.def("changeCargoSpace", &CyUnit::changeCargoSpace, "void (int iChange)")
		.def("isFull", &CyUnit::isFull, "bool ()")
		.def("cargoSpaceAvailable", &CyUnit::cargoSpaceAvailable, "int (int (SpecialUnitTypes) eSpecialCargo, int (DomainTypes) eDomainCargo)")
		.def("hasCargo", &CyUnit::hasCargo, "bool ()")
		.def("canCargoAllMove", &CyUnit::canCargoAllMove, "bool ()")
		.def("getUnitAICargo", &CyUnit::getUnitAICargo, "int (UnitAITypes eUnitAI)")
		.def("getID", &CyUnit::getID, "int ()")

		.def("getGroupID", &CyUnit::getGroupID, "int ()")
		.def("isInGroup", &CyUnit::isInGroup, "bool ()")
		.def("isGroupHead", &CyUnit::isGroupHead, "bool ()")
		.def("getGroup", &CyUnit::getGroup, python::return_value_policy<python::manage_new_object>(), "CySelectionGroup* ()")

		.def("getHotKeyNumber", &CyUnit::getHotKeyNumber, "int () - returns the HotKey number for this unit")
		.def("setHotKeyNumber", &CyUnit::setHotKeyNumber, "void (int iNewValue)")

		.def("getX", &CyUnit::getX, "int ()")
		.def("getY", &CyUnit::getY, "int ()")
		.def("setXY", &CyUnit::setXY, "void (int iX, int iY, bool bGroup, bool bUpdate, bool bShow)")
		.def("at", &CyUnit::at, "int ()")
		.def("atPlot", &CyUnit::atPlot, "bool (CyPlot* pPlot)")
		.def("plot", &CyUnit::plot, python::return_value_policy<python::manage_new_object>(), "CyPlot* ()")
		.def("area", &CyUnit::area, python::return_value_policy<python::manage_new_object>(), "CyArea* ()")
		.def("getReconPlot", &CyUnit::getReconPlot, python::return_value_policy<python::manage_new_object>(), "CyPlot* ()")
		.def("setReconPlot", &CyUnit::setReconPlot, "void (CyPlot* pNewValue)")

		.def("getGameTurnCreated", &CyUnit::getGameTurnCreated, "int ()")

		.def("getDamage", &CyUnit::getDamage, "int ()")
		.def("setDamage", &CyUnit::setDamage, "void (int iNewValue, int (PlayerTypes) ePlayer)")
		.def("changeDamage", &CyUnit::changeDamage, "void (int iChange, int (PlayerTypes) ePlayer)")
		.def("getMoves", &CyUnit::getMoves, "int ()")
		.def("setMoves", &CyUnit::setMoves, "void (int iNewValue)")
		.def("changeMoves", &CyUnit::changeMoves, "void (int iChange)")
		.def("finishMoves", &CyUnit::finishMoves, "void ()")
		.def("getExperience", &CyUnit::getExperience, "int ()")
		.def("setExperience", &CyUnit::setExperience, "void (int iNewValue, int iMax)")
		.def("changeExperience", &CyUnit::changeExperience, "void (int iChange, int iMax, bool bFromCombat, bool bInBorders, bool bUpdateGlobal)")
		.def("getLevel", &CyUnit::getLevel, "int ()")
		.def("setLevel", &CyUnit::setLevel, "void (int iNewLevel)")
		.def("changeLevel", &CyUnit::changeLevel, "void (int iChange)")
		.def("getFacingDirection", &CyUnit::getFacingDirection, "int ()")
		.def("rotateFacingDirectionClockwise", &CyUnit::rotateFacingDirectionClockwise, "void ()")
		.def("rotateFacingDirectionCounterClockwise", &CyUnit::rotateFacingDirectionCounterClockwise, "void ()")
		.def("getCargo", &CyUnit::getCargo, "int ()")
		.def("getFortifyTurns", &CyUnit::getFortifyTurns, "int ()")
		.def("getBlitzCount", &CyUnit::getBlitzCount, "int ()")
		.def("isBlitz", &CyUnit::isBlitz, "bool ()")
		.def("getAmphibCount", &CyUnit::getAmphibCount, "int ()")
		.def("isAmphib", &CyUnit::isAmphib, "bool ()")
		.def("getRiverCount", &CyUnit::getRiverCount, "int ()")
		.def("isRiver", &CyUnit::isRiver, "bool ()")
		.def("isEnemyRoute", &CyUnit::isEnemyRoute, "bool ()")
		.def("isAlwaysHeal", &CyUnit::isAlwaysHeal, "bool ()")
		.def("isHillsDoubleMove", &CyUnit::isHillsDoubleMove, "bool ()")

		.def("getExtraVisibilityRange", &CyUnit::getExtraVisibilityRange, "int ()")
		.def("getExtraMoves", &CyUnit::getExtraMoves, "int ()")
		.def("getExtraMoveDiscount", &CyUnit::getExtraMoveDiscount, "int ()")
		.def("getExtraAirRange", &CyUnit::getExtraAirRange, "int ()")
		.def("getExtraIntercept", &CyUnit::getExtraIntercept, "int ()")
		.def("getExtraEvasion", &CyUnit::getExtraEvasion, "int ()")
		.def("getExtraFirstStrikes", &CyUnit::getExtraFirstStrikes, "int ()")
		.def("getExtraChanceFirstStrikes", &CyUnit::getExtraChanceFirstStrikes, "int ()")
		.def("getExtraWithdrawal", &CyUnit::getExtraWithdrawal, "int ()")
		.def("getExtraCollateralDamage", &CyUnit::getExtraCollateralDamage, "int ()")
		.def("getExtraEnemyHeal", &CyUnit::getExtraEnemyHeal, "int ()")
		.def("getExtraNeutralHeal", &CyUnit::getExtraNeutralHeal, "int ()")
		.def("getExtraFriendlyHeal", &CyUnit::getExtraFriendlyHeal, "int ()")

		.def("getSameTileHeal", &CyUnit::getSameTileHeal, "int ()")
		.def("getAdjacentTileHeal", &CyUnit::getAdjacentTileHeal, "int ()")

		.def("getExtraCombatPercent", &CyUnit::getExtraCombatPercent, "int ()")
		.def("getExtraCityAttackPercent", &CyUnit::getExtraCityAttackPercent, "int ()")
		.def("getExtraCityDefensePercent", &CyUnit::getExtraCityDefensePercent, "int ()")
		.def("getExtraHillsAttackPercent", &CyUnit::getExtraHillsAttackPercent, "int ()")
		.def("getExtraHillsDefensePercent", &CyUnit::getExtraHillsDefensePercent, "int ()")
		.def("getRevoltProtection", &CyUnit::getRevoltProtection, "int ()")
		.def("getCollateralDamageProtection", &CyUnit::getCollateralDamageProtection, "int ()")
		.def("getPillageChange", &CyUnit::getPillageChange, "int ()")
		.def("getUpgradeDiscount", &CyUnit::getUpgradeDiscount, "int ()")
		.def("getExperiencePercent", &CyUnit::getExperiencePercent, "int ()")
		.def("getKamikazePercent", &CyUnit::getKamikazePercent, "int ()")
		.def("getImmobileTimer", &CyUnit::getImmobileTimer, "int ()")
		.def("setImmobileTimer", &CyUnit::setImmobileTimer, "void (int iNewValue)")

		.def("isMadeAttack", &CyUnit::isMadeAttack, "bool ()")
		.def("setMadeAttack", &CyUnit::setMadeAttack, "void (bool bNewValue)")
		.def("isMadeInterception", &CyUnit::isMadeInterception, "bool ()")
		.def("setMadeInterception", &CyUnit::setMadeInterception, "void (bool bNewValue)")

		.def("isPromotionReady", &CyUnit::isPromotionReady, "bool ()")
		.def("setPromotionReady", &CyUnit::setPromotionReady, "void (bool bNewValue)")
		.def("getOwner", &CyUnit::getOwner, "int ()")
		.def("getVisualOwner", &CyUnit::getVisualOwner, "int ()")
		.def("getCombatOwner", &CyUnit::getCombatOwner, "int (int iForTeam)")
		.def("getTeam", &CyUnit::getTeam, "int ()")

		.def("getUnitType", &CyUnit::getUnitType, "int (UnitTypes) ()")
		.def("getUnitClassType", &CyUnit::getUnitClassType, "int (UnitClassTypes) ()")
		.def("getLeaderUnitType", &CyUnit::getLeaderUnitType, "int (UnitTypes) ()")
		.def("setLeaderUnitType", &CyUnit::setLeaderUnitType, "void (int leaderUnitType)")

		.def("getTransportUnit", &CyUnit::getTransportUnit, python::return_value_policy<python::manage_new_object>(), "CyUnit* ()")
		.def("isCargo", &CyUnit::isCargo, "bool ()")
		.def("setTransportUnit", &CyUnit::setTransportUnit, "void (CyUnit* pTransportUnit)")

		.def("getExtraDomainModifier", &CyUnit::getExtraDomainModifier, "int (int (DomainTypes) eIndex)")

		.def("getName", &CyUnit::getName, "wstring () - Returns the name of a unit along with its type description in parens if using a custom name")
		.def("getNameForm", &CyUnit::getNameForm, "wstring (int iForm)")
		.def("getNameKey", &CyUnit::getNameKey, "wstring ()")
		.def("getNameNoDesc", &CyUnit::getNameNoDesc, "wstring () - Returns the name of a unit without any description afterwards")
		.def("setName", &CyUnit::setName, "void (wstring szNewValue)")
		.def("getScriptData", &CyUnit::getScriptData, "string ()")
		.def("setScriptData", &CyUnit::setScriptData, "void (string szNewValue)")

		.def("isTerrainDoubleMove", &CyUnit::isTerrainDoubleMove, "bool (TerrainType)")
		.def("isFeatureDoubleMove", &CyUnit::isFeatureDoubleMove, "bool (FeatureType)")

		.def("getExtraTerrainAttackPercent", &CyUnit::getExtraTerrainAttackPercent, "int (int (TerrainTypes) eIndex)")
		.def("getExtraTerrainDefensePercent", &CyUnit::getExtraTerrainDefensePercent, "int (int (TerrainTypes) eIndex)")
		.def("getExtraFeatureAttackPercent", &CyUnit::getExtraFeatureAttackPercent, "int (int (FeatureTypes) eIndex)")
		.def("getExtraFeatureDefensePercent", &CyUnit::getExtraFeatureDefensePercent, "int (int (FeatureTypes) eIndex)")
		.def("getExtraUnitCombatModifier", &CyUnit::getExtraUnitCombatModifier, "int (int (UnitCombatTypes) eIndex)")

		.def("canAcquirePromotion", &CyUnit::canAcquirePromotion, "bool (int (PromotionTypes) ePromotion)")
		.def("canAcquirePromotionAny", &CyUnit::canAcquirePromotionAny, "bool ()")
		.def("isPromotionValid", &CyUnit::isPromotionValid, "bool (int (PromotionTypes) ePromotion)")
		.def("isHasPromotion", &CyUnit::isHasPromotion, "bool (int (PromotionTypes) eIndex)")
		.def("setHasPromotion", &CyUnit::setHasPromotion, "void (int (PromotionTypes) eIndex, bool bNewValue)")
		.def("IsSelected", &CyUnit::IsSelected, "bool ()")

		.def("getUnitAIType", &CyUnit::getUnitAIType, "int (UnitAITypes) () - returns the int value of the UnitAIType")
		.def("setUnitAIType", &CyUnit::setUnitAIType, "void (int (UnitAITypes) iNewValue) - sets the unit's UnitAIType")

		// Python Helper Functions
		.def("centerCamera", &CyUnit::centerCamera, "void () - Centers the Camera on the unit")
		.def("attackForDamage", &CyUnit::attackForDamage, "void (CyUnit *defender, int attakerDamageChange, int defenderDamageChange)")
		.def("rangeStrike", &CyUnit::rangeStrike, "void (int iX, int iY)")

		.def("getArtInfo", &CyUnit::getArtInfo,  python::return_value_policy<python::reference_existing_object>(), "const CvArtInfoUnit* (int i, EraTypes eEra)")
		.def("getButton", &CyUnit::getButton, "string ()")
		;
}
