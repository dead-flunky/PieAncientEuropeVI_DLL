//
// Python wrapper class for CvGame 
// 

#include "CvGameCoreDLL.h"
#include "CyGame.h"
#include "CvGameAI.h"
#include "CvInitCore.h"

#include "CyGlobalContext.h"
#include "CyPlayer.h"
//#include "CvEnums.h"
#include "CyCity.h"
#include "CyDeal.h"
#include "CyReplayInfo.h"
#include "CvReplayInfo.h"
#include "CyPlot.h"

CyGame::CyGame() : m_pGame(NULL)
{
	m_pGame = &GC.getGameINLINE();
}

CyGame::CyGame(CvGame* pGame) : m_pGame(pGame)
{

}

CyGame::CyGame(CvGameAI* pGame) : m_pGame(pGame)
{

}

void CyGame::updateScore(bool bForce)
{
	if (m_pGame)
	{
		m_pGame->updateScore(bForce);
	}
}

void CyGame::cycleCities(bool bForward, bool bAdd)
{
	if (m_pGame)
		m_pGame->cycleCities(bForward, bAdd);
}

void CyGame::cycleSelectionGroups(bool bClear, bool bForward, bool bWorkers)
{
	if (m_pGame)
		m_pGame->cycleSelectionGroups(bClear, bForward, bWorkers);
}

bool CyGame::cyclePlotUnits(CyPlot* pPlot, bool bForward, bool bAuto, int iCount)
{
	return m_pGame ? m_pGame->cyclePlotUnits(pPlot->getPlot(), bForward, bAuto, iCount) : false;
}

void CyGame::selectionListMove(CyPlot* pPlot, bool bAlt, bool bShift, bool bCtrl)
{
	GC.getGameINLINE().selectionListMove(pPlot->getPlot(), bAlt, bShift, bCtrl);
}

void CyGame::selectionListGameNetMessage(int eMessage, int iData2, int iData3, int iData4, int iFlags, bool bAlt, bool bShift)
{
	GC.getGameINLINE().selectionListGameNetMessage(eMessage, iData2, iData3, iData4, iFlags, bAlt, bShift);
}

void CyGame::selectedCitiesGameNetMessage(int eMessage, int iData2, int iData3, int iData4, bool bOption, bool bAlt, bool bShift, bool bCtrl)
{
	GC.getGameINLINE().selectedCitiesGameNetMessage(eMessage, iData2, iData3, iData4, bOption, bAlt, bShift, bCtrl);
}

void CyGame::cityPushOrder(CyCity* pCity, OrderTypes eOrder, int iData, bool bAlt, bool bShift, bool bCtrl)
{
	GC.getGameINLINE().cityPushOrder(pCity->getCity(), eOrder, iData, bAlt, bShift, bCtrl);
}

int CyGame::getSymbolID(int iSymbol)
{
	if (m_pGame)
	{
		return m_pGame->getSymbolID(iSymbol);
	}

	return -1;
}

int CyGame::getProductionPerPopulation(int /*HurryTypes*/ eHurry)
{
	return m_pGame ? m_pGame->getProductionPerPopulation((HurryTypes) eHurry) : -1;
}

int CyGame::getAdjustedPopulationPercent(int /*VictoryTypes*/ eVictory)
{
	return m_pGame ? m_pGame->getAdjustedPopulationPercent((VictoryTypes) eVictory) : -1;
}

int CyGame::getAdjustedLandPercent(int /* VictoryTypes*/ eVictory)
{
	return m_pGame ? m_pGame->getAdjustedLandPercent((VictoryTypes) eVictory) : -1;
}

bool CyGame::isTeamVote(int /*VoteTypes*/ eVote) const
{
	return m_pGame ? m_pGame->isTeamVote((VoteTypes) eVote) : false;
}

bool CyGame::isChooseElection(int /*VoteTypes*/ eVote) const
{
	return m_pGame ? m_pGame->isChooseElection((VoteTypes) eVote) : false;
}

bool CyGame::isTeamVoteEligible(int /*TeamTypes*/ eTeam, int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame ? m_pGame->isTeamVoteEligible((TeamTypes) eTeam, (VoteSourceTypes)eVoteSource) : false;
}

int CyGame::countPossibleVote(int /*VoteTypes*/ eVote, int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame ? m_pGame->countPossibleVote((VoteTypes) eVote, (VoteSourceTypes)eVoteSource) : -1;
}

int CyGame::getVoteRequired(int /*VoteTypes*/ eVote, int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame ? (int)m_pGame->getVoteRequired((VoteTypes)eVote, (VoteSourceTypes) eVoteSource) : -1;
}

int CyGame::getSecretaryGeneral(int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame ? (int)m_pGame->getSecretaryGeneral((VoteSourceTypes) eVoteSource) : -1;
}

bool CyGame::canHaveSecretaryGeneral(int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame ? (int)m_pGame->canHaveSecretaryGeneral((VoteSourceTypes) eVoteSource) : -1;
}

int CyGame::getVoteSourceReligion(int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame ? (int)m_pGame->getVoteSourceReligion((VoteSourceTypes) eVoteSource) : -1;
}

void CyGame::setVoteSourceReligion(int /*VoteSourceTypes*/ eVoteSource, int /*ReligionTypes*/ eReligion, bool bAnnounce)
{
	if (m_pGame)
	{
		m_pGame->setVoteSourceReligion((VoteSourceTypes)eVoteSource, (ReligionTypes)eReligion, bAnnounce);
	}
}

int CyGame::countCivPlayersAlive()
{
	return m_pGame ? m_pGame->countCivPlayersAlive() : -1;
}

int CyGame::countCivPlayersEverAlive()
{
	return m_pGame ? m_pGame->countCivPlayersEverAlive() : -1;
}

int CyGame::countCivTeamsAlive()
{
	return m_pGame ? m_pGame->countCivTeamsAlive() : -1;
}

int CyGame::countCivTeamsEverAlive()
{
	return m_pGame ? m_pGame->countCivTeamsEverAlive() : -1;
}

int CyGame::countHumanPlayersAlive()
{
	return m_pGame ? m_pGame->countHumanPlayersAlive() : -1;
}

int CyGame::countTotalCivPower()
{
	return m_pGame ? m_pGame->countTotalCivPower() : -1;
}

int CyGame::countTotalNukeUnits()
{
	return m_pGame ? m_pGame->countTotalNukeUnits() : -1;
}

int CyGame::countKnownTechNumTeams(int /*TechTypes*/ eTech)
{
	return m_pGame ? m_pGame->countKnownTechNumTeams((TechTypes) eTech) : -1;
}

int CyGame::getNumFreeBonuses(int /*BuildingTypes*/ eBuilding)
{
	return m_pGame ? m_pGame->getNumFreeBonuses((BuildingTypes) eBuilding) : -1;
}

int CyGame::countReligionLevels(int /*ReligionTypes*/ eReligion)
{
	return m_pGame ? m_pGame->countReligionLevels((ReligionTypes) eReligion) : -1;
}

int CyGame::countCorporationLevels(int /*CorporationTypes*/ eCorporation)
{
	return m_pGame ? m_pGame->countCorporationLevels((CorporationTypes) eCorporation) : -1;
}

int CyGame::calculateReligionPercent(int /*ReligionTypes*/ eReligion)
{
	return m_pGame ? m_pGame->calculateReligionPercent((ReligionTypes) eReligion) : -1;
}

int CyGame::goldenAgeLength()
{
	return m_pGame ? m_pGame->goldenAgeLength() : -1;
}

int CyGame::victoryDelay(int iVictory)
{
	return m_pGame ? m_pGame->victoryDelay((VictoryTypes)iVictory) : -1;
}

int CyGame::getImprovementUpgradeTime(int /*ImprovementTypes*/ eImprovement)
{
	return m_pGame ? m_pGame->getImprovementUpgradeTime((ImprovementTypes) eImprovement) : -1;
}

bool CyGame::canTrainNukes()
{
	return m_pGame ? m_pGame->canTrainNukes() : false;
}

int CyGame::getCurrentEra()
{
	return m_pGame ? (int) m_pGame->getCurrentEra() : (int) NO_ERA;
}

int CyGame::getActiveTeam()
{
	return m_pGame ? (int) m_pGame->getActiveTeam() : (int) NO_TEAM;
}

int /* CivilizationTypes */ CyGame::getActiveCivilizationType()
{
	return m_pGame ? (int) m_pGame->getActiveCivilizationType() : (int) NO_CIVILIZATION;
}

bool CyGame::isNetworkMultiPlayer()
{
	return m_pGame ? m_pGame->isNetworkMultiPlayer() : false;
}

bool CyGame::isGameMultiPlayer()
{
	return m_pGame ? m_pGame->isGameMultiPlayer() : false;
}

bool CyGame::isTeamGame()
{
	return m_pGame ? m_pGame->isTeamGame() : false;
}

bool CyGame::isModem()
{
	return m_pGame ? m_pGame->isModem() : true;	// err on the side of caution
}

void CyGame::setModem(bool bModem)
{
	if (m_pGame)
		m_pGame->setModem(bModem);
}

void CyGame::reviveActivePlayer()
{
	if (m_pGame)
		m_pGame->reviveActivePlayer();
}

int CyGame::getNumHumanPlayers()
{
	return m_pGame ? m_pGame->getNumHumanPlayers() : -1;
}

int CyGame::getGameTurn()
{
	return m_pGame ? m_pGame->getGameTurn() : -1;
}

void CyGame::setGameTurn(int iNewValue)
{
	if (m_pGame)
		m_pGame->setGameTurn(iNewValue);
}

int CyGame::getTurnYear(int iGameTurn)
{
	return  m_pGame ? m_pGame->getTurnYear(iGameTurn) : -1;
}

int CyGame::getGameTurnYear()
{
	return  m_pGame ? m_pGame->getGameTurnYear() : -1;
}

int CyGame::getElapsedGameTurns()
{
	return m_pGame ? m_pGame->getElapsedGameTurns() : -1;
}

int CyGame::getMaxTurns() const
{
	return (NULL != m_pGame ? m_pGame->getMaxTurns() : -1);
}

void CyGame::setMaxTurns(int iNewValue)
{
	if (NULL != m_pGame)
	{
		m_pGame->setMaxTurns(iNewValue);
	}
}

void CyGame::changeMaxTurns(int iChange)
{
	if (NULL != m_pGame)
	{
		m_pGame->changeMaxTurns(iChange);
	}
}

int CyGame::getMaxCityElimination() const
{
	return (NULL != m_pGame ? m_pGame->getMaxCityElimination() : -1);
}

void CyGame::setMaxCityElimination(int iNewValue)
{
	if (NULL != m_pGame)
	{
		m_pGame->setMaxCityElimination(iNewValue);
	}
}

int CyGame::getNumAdvancedStartPoints() const
{
	return (NULL != m_pGame ? m_pGame->getNumAdvancedStartPoints() : -1);
}

void CyGame::setNumAdvancedStartPoints(int iNewValue)
{
	if (NULL != m_pGame)
	{
		m_pGame->setNumAdvancedStartPoints(iNewValue);
	}
}

int CyGame::getStartTurn() const
{
	return (NULL != m_pGame ? m_pGame->getStartTurn() : -1);
}

int CyGame::getStartYear() const
{
	return (NULL != m_pGame ? m_pGame->getStartYear() : -1);
}

void CyGame::setStartYear(int iNewValue)
{
	if (NULL != m_pGame)
	{
		m_pGame->setStartYear(iNewValue);
	}
}

int CyGame::getEstimateEndTurn() const
{
	return (NULL != m_pGame ? m_pGame->getEstimateEndTurn() : -1);
}

void CyGame::setEstimateEndTurn(int iNewValue)
{
	if (NULL != m_pGame)
	{
		m_pGame->setEstimateEndTurn(iNewValue);
	}
}

int CyGame::getTurnSlice() const
{
	return (NULL != m_pGame ? m_pGame->getTurnSlice() : -1);
}

//PBMod, for increment and decrement
void CyGame::incrementTurnTimer(int iNumTurnSlices){
	if( m_pGame != NULL){
		if (isMPOption(MPOPTION_TURN_TIMER)){
			m_pGame->incrementTurnTimer(iNumTurnSlices);
		}
	}
}
//END PBMod

int CyGame::getMinutesPlayed() const
{
	return (NULL != m_pGame ? m_pGame->getMinutesPlayed() : 0);
}

int CyGame::getTargetScore() const
{
	return (NULL != m_pGame ? m_pGame->getTargetScore() : -1);
}

void CyGame::setTargetScore(int iNewValue)
{
	if (NULL != m_pGame)
	{
		m_pGame->setTargetScore(iNewValue);
	}
}

int CyGame::getNumGameTurnActive()
{
	return m_pGame ? m_pGame->getNumGameTurnActive() : -1;
}

int CyGame::countNumHumanGameTurnActive()
{
	return m_pGame ? m_pGame->countNumHumanGameTurnActive() : -1;
}

int CyGame::getNumCities()
{
	return m_pGame ? m_pGame->getNumCities() : -1;
}

int CyGame::getNumCivCities()
{
	return m_pGame ? m_pGame->getNumCivCities() : -1;
}

int CyGame::getTotalPopulation()
{
	return m_pGame ? m_pGame->getTotalPopulation() : -1;
}

int CyGame::getTradeRoutes() const
{
	return m_pGame ? m_pGame->getTradeRoutes() : -1;
}

void CyGame::changeTradeRoutes(int iChange)
{
	if (m_pGame)
		m_pGame->changeTradeRoutes(iChange);
}

int CyGame::getFreeTradeCount() const
{
	return m_pGame ? m_pGame->getFreeTradeCount() : -1;
}

bool CyGame::isFreeTrade() const
{
	return m_pGame ? m_pGame->isFreeTrade() : false;
}

void CyGame::changeFreeTradeCount(int iChange)
{
	if (m_pGame)
		m_pGame->changeFreeTradeCount(iChange);
}

int CyGame::getNoNukesCount() const
{
	return m_pGame ? m_pGame->getNoNukesCount() : -1;
}

bool CyGame::isNoNukes() const
{
	return m_pGame ? m_pGame->isNoNukes() : false;
}

void CyGame::changeNoNukesCount(int iChange)
{
	if (m_pGame)
		m_pGame->changeNoNukesCount(iChange);
}

int CyGame::getSecretaryGeneralTimer(int iVoteSource) const
{
	return m_pGame ? m_pGame->getSecretaryGeneralTimer((VoteSourceTypes)iVoteSource) : -1;
}

int CyGame::getVoteTimer(int iVoteSource) const
{
	return m_pGame ? m_pGame->getVoteTimer((VoteSourceTypes)iVoteSource) : -1;
}

int CyGame::getNukesExploded() const
{
	return m_pGame ? m_pGame->getNukesExploded() : -1;
}

void CyGame::changeNukesExploded(int iChange)
{
	if (m_pGame)
		m_pGame->changeNukesExploded(iChange);
}

int CyGame::getMaxPopulation() const
{
	return (NULL != m_pGame ? m_pGame->getMaxPopulation() : 0);
}

int CyGame::getMaxLand() const
{
	return (NULL != m_pGame ? m_pGame->getMaxLand() : 0);
}

int CyGame::getMaxTech() const
{
	return (NULL != m_pGame ? m_pGame->getMaxTech() : 0);
}

int CyGame::getMaxWonders() const
{
	return (NULL != m_pGame ? m_pGame->getMaxWonders() : 0);
}

int CyGame::getInitPopulation() const
{
	return (NULL != m_pGame ? m_pGame->getInitPopulation() : 0);
}

int CyGame::getInitLand() const
{
	return (NULL != m_pGame ? m_pGame->getInitLand() : 0);
}

int CyGame::getInitTech() const
{
	return (NULL != m_pGame ? m_pGame->getInitTech() : 0);
}

int CyGame::getInitWonders() const
{
	return (NULL != m_pGame ? m_pGame->getInitWonders() : 0);
}

int CyGame::getAIAutoPlay() const
{
	return (NULL != m_pGame ? m_pGame->getAIAutoPlay() : 0);
}

void CyGame::setAIAutoPlay(int iNewValue)
{
	if (m_pGame)
		m_pGame->setAIAutoPlay(iNewValue);
}

bool CyGame::isScoreDirty() const
{
	return m_pGame ? m_pGame->isScoreDirty() : false;
}

void CyGame::setScoreDirty(bool bNewValue)
{
	if (m_pGame)
		m_pGame->setScoreDirty(bNewValue);
}

bool CyGame::isCircumnavigated() const
{
	return m_pGame ? m_pGame->isCircumnavigated() : false;
}

void CyGame::makeCircumnavigated()								 
{
	if (m_pGame)
		m_pGame->makeCircumnavigated();
}

bool CyGame::isDiploVote(int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame ? m_pGame->isDiploVote((VoteSourceTypes)eVoteSource) : false;
}

void CyGame::changeDiploVote(int /*VoteSourceTypes*/ eVoteSource, int iChange)
{
	if (m_pGame)
		m_pGame->changeDiploVote((VoteSourceTypes)eVoteSource, iChange);
}

bool CyGame::isDebugMode() const
{
	return m_pGame ? m_pGame->isDebugMode() : false;
}

void CyGame::toggleDebugMode()
{
	if (m_pGame)
		m_pGame->toggleDebugMode();
}

int CyGame::getPitbossTurnTime()
{
	return m_pGame ? m_pGame->getPitbossTurnTime() : -1;
}

void CyGame::setPitbossTurnTime(int iHours)
{
	if (m_pGame)
		m_pGame->setPitbossTurnTime(iHours);
}

bool CyGame::isHotSeat()
{
	return m_pGame ? m_pGame->isHotSeat() : false;
}

bool CyGame::isPbem()
{
	return m_pGame ? m_pGame->isPbem() : false;
}

bool CyGame::isPitboss()
{
	return m_pGame ? m_pGame->isPitboss() : false;
}
//PBMod
bool CyGame::isPitbossShortNames() const
{
	return m_pGame ? CvInitCore::isPitbossShortNames() : false;
}

void CyGame::setPitbossShortNames(bool bShort, int maxLenName, int maxLenDesc){
	if( m_pGame != NULL ){
		CvInitCore::setPitbossShortNames( bShort, maxLenName, maxLenDesc );
	}
}
//PBMod

bool CyGame::isSimultaneousTeamTurns()
{
	return m_pGame ? m_pGame->isSimultaneousTeamTurns() : false;
}

bool CyGame::isFinalInitialized()
{
	return m_pGame ? m_pGame->isFinalInitialized() : false;
}

int /*PlayerTypes*/ CyGame::getActivePlayer() 
{
	return m_pGame ? (int)m_pGame->getActivePlayerInternal() : -1;
}

void CyGame::setActivePlayer(int /*PlayerTypes*/ eNewValue, bool bForceHotSeat)
{
	if (m_pGame)
		m_pGame->setActivePlayer((PlayerTypes)eNewValue, bForceHotSeat);
}

int CyGame::getPausePlayer()
{
	return m_pGame ? m_pGame->getPausePlayer() : -1;
}
//PBMod
void CyGame::setPausePlayer(int /*PlayerTypes*/ eNewValue)
{
	if (m_pGame)
		m_pGame->setPausePlayer((PlayerTypes)eNewValue);
}
//PBMod

bool CyGame::isPaused()
{
	return m_pGame ? m_pGame->isPaused() : false;
}

int /*PlayerTypes*/ CyGame::getBestLandUnit() 
{
	return m_pGame ? (int)m_pGame->getBestLandUnit() : -1;
}

int CyGame::getBestLandUnitCombat() 
{
	return m_pGame ? m_pGame->getBestLandUnitCombat() : -1;
}

int /*TeamTypes*/ CyGame::getWinner() 
{
	return m_pGame ? (int)m_pGame->getWinner() : -1;
}

int /*VictoryTypes*/ CyGame::getVictory() 
{
	return m_pGame ? (int)m_pGame->getVictory() : -1;
}

void CyGame::setWinner(int /*TeamTypes*/ eNewWinner, int /*VictoryTypes*/ eNewVictory)
{
	if (m_pGame)
		m_pGame->setWinner((TeamTypes) eNewWinner, (VictoryTypes) eNewVictory);
}

int /*GameStateTypes*/ CyGame::getGameState() 
{
	return m_pGame ? (int)m_pGame->getGameState() : -1;
}

int /* HandicapTypes */ CyGame::getHandicapType()
{
	return m_pGame ? (int) m_pGame->getHandicapType() : (int) NO_HANDICAP;
}

CalendarTypes CyGame::getCalendar() const
{
	return m_pGame ? m_pGame->getCalendar() : CALENDAR_DEFAULT;
}

int /*EraTypes*/ CyGame::getStartEra()
{
	return m_pGame ? m_pGame->getStartEra() : -1;
}

int /*GameSpeedTypes*/ CyGame::getGameSpeedType()
{
	return m_pGame ? m_pGame->getGameSpeedType() : -1;
}

int /*PlayerTypes*/ CyGame::getRankPlayer(int iRank)
{
	return m_pGame ? m_pGame->getRankPlayer(iRank) : -1;
}

int CyGame::getPlayerRank(int /*PlayerTypes*/ ePlayer)
{
	return m_pGame ? m_pGame->getPlayerRank((PlayerTypes)ePlayer) : -1;
}

int CyGame::getPlayerScore(int /*PlayerTypes*/ ePlayer)
{
	return m_pGame ? m_pGame->getPlayerScore((PlayerTypes)ePlayer) : -1;
}

int /*TeamTypes*/ CyGame::getRankTeam(int iRank)
{
	return m_pGame ? m_pGame->getRankTeam(iRank) : -1;
}

int CyGame::getTeamRank(int /*TeamTypes*/ eTeam)
{
	return m_pGame ? m_pGame->getTeamRank((TeamTypes)eTeam) : -1;
}

int CyGame::getTeamScore(int /*TeamTypes*/ eTeam)
{
	return m_pGame ? m_pGame->getTeamScore((TeamTypes)eTeam) : -1;
}

bool CyGame::isOption(int /*GameOptionTypes*/ eIndex)
{
	return m_pGame ? m_pGame->isOption((GameOptionTypes)eIndex) : -1;
}

void CyGame::setOption(int /*GameOptionTypes*/ eIndex, bool bEnabled)
{
	if (m_pGame)
		m_pGame->setOption((GameOptionTypes)eIndex, bEnabled);
}

bool CyGame::isMPOption(int /*MultiplayerOptionTypes*/ eIndex)
{
	return m_pGame ? m_pGame->isMPOption((MultiplayerOptionTypes)eIndex) : -1;
}

//PBMod
void CyGame::setMPOption(int /*MultiplayerOptionTypes*/ eIndex, bool bEnabled)
{
  if( !isPitbossHost() ){
		return;
	}
	if (m_pGame)
		m_pGame->setMPOption((MultiplayerOptionTypes)eIndex, bEnabled);
}
//PBMod

bool CyGame::isForcedControl(int /*ForceControlTypes*/ eIndex)
{
	return m_pGame ? m_pGame->isForcedControl((ForceControlTypes)eIndex) : -1;
}

int CyGame::getUnitCreatedCount(int /*UnitTypes*/ eIndex)
{
	return m_pGame ? m_pGame->getUnitCreatedCount((UnitTypes)eIndex) : -1;
}

int CyGame::getUnitClassCreatedCount(int /*UnitClassTypes*/ eIndex)
{
	return m_pGame ? m_pGame->getUnitClassCreatedCount((UnitClassTypes)eIndex) : -1;
}

bool CyGame::isUnitClassMaxedOut(int /*UnitClassTypes*/ eIndex, int iExtra)
{
	return m_pGame ? m_pGame->isUnitClassMaxedOut((UnitClassTypes)eIndex, iExtra) : -1;
}

int CyGame::getBuildingClassCreatedCount(int /*BuildingClassTypes*/ eIndex) 
{
	return m_pGame ? m_pGame->getBuildingClassCreatedCount((BuildingClassTypes) eIndex) : -1;
}

bool CyGame::isBuildingClassMaxedOut(int /*BuildingClassTypes*/ eIndex, int iExtra)
{
	return m_pGame ? m_pGame->isBuildingClassMaxedOut((BuildingClassTypes)eIndex, iExtra) : false;
}

int CyGame::getProjectCreatedCount(int /*ProjectTypes*/ eIndex) 
{
	return m_pGame ? m_pGame->getProjectCreatedCount((ProjectTypes) eIndex) : -1;
}

bool CyGame::isProjectMaxedOut(int /*ProjectTypes*/ eIndex, int iExtra)
{
	return m_pGame ? m_pGame->isProjectMaxedOut((ProjectTypes)eIndex, iExtra) : false;
}

int CyGame::getForceCivicCount(int /*CivicTypes*/ eIndex) 
{
	return m_pGame ? m_pGame->getForceCivicCount((CivicTypes) eIndex) : -1;
}

bool CyGame::isForceCivic(int /*CivicTypes*/ eIndex)
{
	return m_pGame ? m_pGame->isForceCivic((CivicTypes)eIndex) : false;
}

bool CyGame::isForceCivicOption(int /*CivicOptionTypes*/ eCivicOption)
{
	return m_pGame ? m_pGame->isForceCivicOption((CivicOptionTypes)eCivicOption) : false;
}

int CyGame::getVoteOutcome(int /*VoteTypes*/ eIndex) 
{
	return m_pGame ? m_pGame->getVoteOutcome((VoteTypes) eIndex) : NO_PLAYER_VOTE;
}

int CyGame::getReligionGameTurnFounded(int /*ReligionTypes*/ eIndex)
{
	return m_pGame ? m_pGame->getReligionGameTurnFounded((ReligionTypes) eIndex) : -1;
}

bool CyGame::isReligionFounded(int /*ReligionTypes*/ eIndex)
{
	return m_pGame ? m_pGame->isReligionFounded((ReligionTypes) eIndex) : false;
}

bool CyGame::isReligionSlotTaken(int /*ReligionTypes*/ eIndex)
{
	return m_pGame ? m_pGame->isReligionSlotTaken((ReligionTypes) eIndex) : false;
}

int CyGame::getCorporationGameTurnFounded(int /*CorporationTypes*/ eIndex)
{
	return m_pGame ? m_pGame->getCorporationGameTurnFounded((CorporationTypes) eIndex) : -1;
}

bool CyGame::isCorporationFounded(int /*CorporationTypes*/ eIndex)
{
	return m_pGame ? m_pGame->isCorporationFounded((CorporationTypes) eIndex) : false;
}

bool CyGame::isVotePassed(int /*VoteTypes*/ eIndex) const
{
	return m_pGame ? m_pGame->isVotePassed((VoteTypes)eIndex) : false;
}

bool CyGame::isVictoryValid(int /*VictoryTypes*/ eIndex)
{
	return m_pGame ? m_pGame->isVictoryValid((VictoryTypes)eIndex) : false;
}

//PBMod
void CyGame::setVictoryValid(int /*VictoryTypes*/ eIndex, bool bValid)
{
	if (m_pGame) {
		m_pGame->setVictoryValid((VictoryTypes)eIndex, bValid);
	}
}
//PBMod

bool CyGame::isSpecialUnitValid(int /*SpecialUnitTypes*/ eSpecialUnitType)
{
	return m_pGame ? m_pGame->isSpecialUnitValid((SpecialUnitTypes)eSpecialUnitType) : false;
}

void CyGame::makeSpecialUnitValid(int /*SpecialUnitTypes*/ eSpecialUnitType)
{
	if (m_pGame)
		m_pGame->makeSpecialUnitValid((SpecialUnitTypes) eSpecialUnitType);
}

bool CyGame::isSpecialBuildingValid(int /*SpecialBuildingTypes*/ eIndex)
{
	return m_pGame ? m_pGame->isSpecialBuildingValid((SpecialBuildingTypes)eIndex) : false;
}

void CyGame::makeSpecialBuildingValid(int /*SpecialBuildingTypes*/ eIndex)
{
	if (m_pGame)
		m_pGame->makeSpecialBuildingValid((SpecialBuildingTypes) eIndex);
}

bool CyGame::isNukesValid()
{
	return m_pGame ? m_pGame->isNukesValid() : false;
}

void CyGame::makeNukesValid(bool bValid)
{
	if (m_pGame)
		m_pGame->makeNukesValid(bValid);
}

bool CyGame::isInAdvancedStart()
{
	return m_pGame ? m_pGame->isInAdvancedStart() : false;
}

CyCity* CyGame::getHolyCity(int /*ReligionTypes*/ eIndex)
{
	return m_pGame ? new CyCity(m_pGame->getHolyCity((ReligionTypes) eIndex)) : NULL;
}

void CyGame::setHolyCity(int /*ReligionTypes*/ eIndex, CyCity* pNewValue, bool bAnnounce)
{
	if (m_pGame)
		m_pGame->setHolyCity((ReligionTypes) eIndex, pNewValue->getCity(), bAnnounce);
}

void CyGame::clearHolyCity(int /*ReligionTypes*/ eIndex)
{
	if (m_pGame)
		m_pGame->setHolyCity((ReligionTypes) eIndex, NULL, false);
}

CyCity* CyGame::getHeadquarters(int /*CorporationTypes*/ eIndex)
{
	return m_pGame ? new CyCity(m_pGame->getHeadquarters((CorporationTypes) eIndex)) : NULL;
}

void CyGame::setHeadquarters(int /*CorporationTypes*/ eIndex, CyCity* pNewValue, bool bAnnounce)
{
	if (m_pGame)
		m_pGame->setHeadquarters((CorporationTypes) eIndex, pNewValue->getCity(), bAnnounce);
}

void CyGame::clearHeadquarters(int /*CorporationTypes*/ eIndex)
{
	if (m_pGame)
		m_pGame->setHeadquarters((CorporationTypes) eIndex, NULL, false);
}

int CyGame::getPlayerVote(int /*PlayerTypes*/ eOwnerIndex, int iVoteId)
{
	return m_pGame ? m_pGame->getPlayerVote((PlayerTypes) eOwnerIndex, iVoteId) : NO_PLAYER_VOTE;
}

std::string CyGame::getScriptData() const
{
	return m_pGame ? m_pGame->getScriptData() : "";
}

void CyGame::setScriptData(std::string szNewValue)
{
	if (m_pGame)
		m_pGame->setScriptData(szNewValue);
}

void CyGame::setName(TCHAR* szNewValue)
{
	if (m_pGame)
		m_pGame->setName(szNewValue);
}

std::wstring CyGame::getName()
{
	return m_pGame ? m_pGame->getName() : "";
}

int CyGame::getIndexAfterLastDeal() 
{
	return m_pGame ? m_pGame->getIndexAfterLastDeal() : -1;
}

int CyGame::getNumDeals() 
{
	return m_pGame ? m_pGame->getNumDeals() : -1;
}

CyDeal* CyGame::getDeal(int iID)
{
	if (m_pGame)
	{
		return new CyDeal(m_pGame->getDeal(iID));
	}
	else
	{
		return NULL;
	}
}

CyDeal* CyGame::addDeal()
{
	if (m_pGame)
	{
		return new CyDeal(m_pGame->addDeal());
	}
	else
	{
		return NULL;
	}
}

void CyGame::deleteDeal(int iID)
{
	if (m_pGame)
	{
		m_pGame->deleteDeal(iID);
	}
}

CvRandom& CyGame::getMapRand()
{
	FAssert(m_pGame);
	return (m_pGame->getMapRand());
}

int CyGame::getMapRandNum(int iNum, TCHAR* pszLog) 
{
	return m_pGame ? m_pGame->getMapRandNum(iNum, pszLog) : -1;
}

CvRandom& CyGame::getSorenRand()
{
	FAssert(m_pGame);
	return (m_pGame->getSorenRand());
}

int CyGame::getSorenRandNum(int iNum, TCHAR* pszLog) 
{
	return m_pGame ? m_pGame->getSorenRandNum(iNum, pszLog) : -1;
}

int CyGame::calculateSyncChecksum()
{
	return m_pGame ? m_pGame->calculateSyncChecksum() : -1;
}

int CyGame::calculateOptionsChecksum()
{
	return m_pGame ? m_pGame->calculateOptionsChecksum() : -1;
}

// JS - can't access protected member declared in class CvGame

bool CyGame::GetWorldBuilderMode() const				// remove once CvApp is exposed
{
	return gDLL->GetWorldBuilderMode();
}

bool CyGame::isPitbossHost() const				// remove once CvApp is exposed
{
	return gDLL->IsPitbossHost();
}

int CyGame::getCurrentLanguage() const				// remove once CvApp is exposed
{
	return gDLL->getCurrentLanguage();
}

void CyGame::setCurrentLanguage(int iNewLanguage)			// remove once CvApp is exposed
{
	gDLL->setCurrentLanguage(iNewLanguage);
}

int CyGame::getReplayMessageTurn(int i) const
{
	return (NULL != m_pGame ? m_pGame->getReplayMessageTurn(i) : -1);
}

ReplayMessageTypes CyGame::getReplayMessageType(int i) const
{
	return (NULL != m_pGame ? m_pGame->getReplayMessageType(i) : NO_REPLAY_MESSAGE);
}

int CyGame::getReplayMessagePlotX(int i) const
{
	return (NULL != m_pGame ? m_pGame->getReplayMessagePlotX(i) : -1);
}

int CyGame::getReplayMessagePlotY(int i) const
{
	return (NULL != m_pGame ? m_pGame->getReplayMessagePlotY(i) : -1);
}

int CyGame::getReplayMessagePlayer(int i) const
{
	return (NULL != m_pGame ? m_pGame->getReplayMessagePlayer(i) : -1);
}

ColorTypes CyGame::getReplayMessageColor(int i) const
{
	return (NULL != m_pGame ? m_pGame->getReplayMessageColor(i) : NO_COLOR);
}

std::wstring CyGame::getReplayMessageText(int i) const
{
	return (NULL != m_pGame ? m_pGame->getReplayMessageText(i) : L"");
}

uint CyGame::getNumReplayMessages() const
{
	return (NULL != m_pGame ? m_pGame->getNumReplayMessages() : 0);
}

CyReplayInfo* CyGame::getReplayInfo() const
{
	return (NULL != m_pGame ? (new CyReplayInfo(m_pGame->getReplayInfo())) : NULL);
}

bool CyGame::hasSkippedSaveChecksum() const
{
	return (NULL != m_pGame ? m_pGame->hasSkippedSaveChecksum() : false);
}

void CyGame::saveReplay(int iPlayer)
{
	if (m_pGame)
	{
		m_pGame->saveReplay((PlayerTypes)iPlayer);
	}
}

void CyGame::addPlayer(int eNewPlayer, int eLeader, int eCiv)
{
	if (m_pGame)
	{
		m_pGame->addPlayer((PlayerTypes)eNewPlayer, (LeaderHeadTypes)eLeader, (CivilizationTypes)eCiv);
	}
}

int CyGame::getCultureThreshold(int eLevel)
{
	return (m_pGame ? m_pGame->getCultureThreshold((CultureLevelTypes) eLevel) : -1);
}

void CyGame::setPlotExtraYield(int iX, int iY, int /*YieldTypes*/ eYield, int iExtraYield)
{
	if (m_pGame)
	{
		m_pGame->setPlotExtraYield(iX, iY, (YieldTypes)eYield, iExtraYield);
	}
}

void CyGame::changePlotExtraCost(int iX, int iY, int iCost)
{
	if (m_pGame)
	{
		m_pGame->changePlotExtraCost(iX, iY, iCost);
	}
}

bool CyGame::isCivEverActive(int /*CivilizationTypes*/ eCivilization)
{
	return (NULL != m_pGame ? m_pGame->isCivEverActive((CivilizationTypes)eCivilization) : false);
}

bool CyGame::isLeaderEverActive(int /*LeaderHeadTypes*/ eLeader)
{
	return (NULL != m_pGame ? m_pGame->isLeaderEverActive((LeaderHeadTypes)eLeader) : false);
}

bool CyGame::isUnitEverActive(int /*UnitTypes*/ eUnit)
{
	return (NULL != m_pGame ? m_pGame->isUnitEverActive((UnitTypes)eUnit) : false);
}

bool CyGame::isBuildingEverActive(int /*BuildingTypes*/ eBuilding)
{
	return (NULL != m_pGame ? m_pGame->isBuildingEverActive((BuildingTypes)eBuilding) : false);
}

bool CyGame::isEventActive(int /*EventTriggerTypes*/ eTrigger)
{
	return (NULL != m_pGame ? m_pGame->isEventActive((EventTriggerTypes)eTrigger) : false);
}

void CyGame::doControl(int iControl)
{
	if (m_pGame)
	{
		m_pGame->doControl((ControlTypes) iControl);
	}
}

//PBMod
/* Set player password to new value. Requires correct admin password as second argument.
 * */
int CyGame::setCivPassword(int ePlayer, const char *pNewPw, const char *pAdminPw)
{
  // Evaluate MD5-Hash of AdminPw
  CvWString szAdminPw(pAdminPw);
  if (!szAdminPw.empty()){
    szAdminPw = CvWString(gDLL->md5String((char*)CvString(szAdminPw).GetCString()));
  }

  if( 0 == szAdminPw.compare( GC.getInitCore().getAdminPassword())){
    CvWString szNewCivPW( pNewPw );
    GC.getInitCore().setCivPassword((PlayerTypes)ePlayer, szNewCivPW );
  }else{
    return -1;
  }
  return 0;
}

bool CyGame::isDiploScreenUp() const
{
	return (NULL != m_pGame ? m_pGame->isDiploScreenUp() : false);
}

void CyGame::doControlWithoutWidget(int /*ControlTypes*/ eControl) const
{
    if( m_pGame ){
        m_pGame->doControlWithoutWidget((ControlTypes) eControl);
    }
}

std::wstring __mod_path__ = L""; // static variable to avoid local one.
std::wstring CyGame::getModPath()
{
  if( __mod_path__.empty() ){
	  char *path = get_dll_folder();

	  // Remove lowest folder (\Assets)
	  char *last_slash = strrchr(path, '\\');
	  *last_slash = '\0';

	  //__mod_path__.clear();
	  int status = CharToWString(__mod_path__, path);
	  free(path);
  }
  return __mod_path__;
}

int CyGame::unzipModUpdate(std::wstring zipFilename)
{
	std::wstring out_folder(getModPath());   
	BSTR out_folder_bstr = SysAllocString(out_folder.c_str());
	
#if 0
	// Manuell konstruieren
	char *dll_folder = get_dll_folder();
	std::string absolute_path = std::string(dll_folder);
	absolute_path.append("\\");
	absolute_path.append("Update 1.zip");
	std::wstring wabsolute_path;
	StringToWString(wabsolute_path, absolute_path);
	BSTR z_bstr = SysAllocString(wabsolute_path.c_str()); //=>File not found error
	free((void *)dll_folder);
#else
	//BSTR z_bstr = SysAllocString(L"I:\\Olaf\\Civ4\\Beyond the Sword\\Mods\\PBMod_v10\\Update 1.zip");//ok
	BSTR z_bstr = SysAllocString(zipFilename.c_str());
	//BSTR z_bstr = SysAllocString(L"Z:\\home\\olaf\\Civ4\\Civ4\\Beyond the Sword\\Mods\\PBMod_v10\\Update 1.zip");
#endif

	int ret = Unzip2Folder(z_bstr, out_folder_bstr);

	SysFreeString(z_bstr);
	SysFreeString(out_folder_bstr);
	return ret;
}

int CyGame::setAdminPassword(const char *pNewAdminPw, const char *pAdminPw)
{
  if( !isPitbossHost() ){
    return -2;
  }

  // Evaluate MD5-Hash of AdminPw
  CvWString szAdminPw(pAdminPw);
  if (!szAdminPw.empty()){
    szAdminPw = CvWString(gDLL->md5String((char*)CvString(szAdminPw).GetCString()));
  }

  if( 0 == szAdminPw.compare( GC.getInitCore().getAdminPassword())){
    CvWString szNewAdminPW( pNewAdminPw );
    GC.getInitCore().setAdminPassword(szNewAdminPW );
  }else{
    return -1;
  }
  return 0;
}

void CyGame::fixTradeRoutes()
{
  if(m_pGame){
    m_pGame->fixTradeRoutes();
  }
}

int CyGame::getCorporationFactor100_(int numCorpLocationsOfPlayer, int numPlayersWithCorp,
        int /*CorporationTypes*/ eCorporation) const
{
  if(m_pGame){
    return m_pGame->getCorporationFactor100_(numCorpLocationsOfPlayer, numPlayersWithCorp, (CorporationTypes) eCorporation);
  }
  return 0;
}

int CyGame::swapPlayersInTurnOrder(int iPlayerA, int iPlayerB){
	return (m_pGame ? m_pGame->swapPlayersInTurnOrder(iPlayerA, iPlayerB) : -1);
}

boost::python::list CyGame::getPlayersInTurnOrder(){
	boost::python::list ret;
	if (m_pGame){
		for (int iPlayer = m_pGame->getNextPlayerInTurnOrder(MAX_PLAYERS);
				iPlayer < MAX_PLAYERS;
				iPlayer = m_pGame->getNextPlayerInTurnOrder(iPlayer)
				){
			CvPlayer& kPlayer = GET_PLAYER((PlayerTypes)iPlayer);
			if (kPlayer.isAlive() && !kPlayer.isBarbarian()){
				ret.append(iPlayer);
			}
		}
	}
	return ret;
}

int CyGame::swapTeamsInTurnOrder(int iTeamA, int iTeamB){
	return (m_pGame ? m_pGame->swapTeamsInTurnOrder(iTeamA, iTeamB): -1);
}

boost::python::list CyGame::getTeamsInTurnOrder(){
	boost::python::list ret;
	if (m_pGame){
		for (int iTeam = m_pGame->getNextTeamInTurnOrder(MAX_TEAMS);
				iTeam < MAX_TEAMS;
				iTeam = m_pGame->getNextTeamInTurnOrder(iTeam)
				){
			CvTeam& kTeam = GET_TEAM((TeamTypes)iTeam);
			if (kTeam.isAlive() && !kTeam.isBarbarian()){
				ret.append(iTeam);
			}
		}
	}
	return ret;
}
//PBMod