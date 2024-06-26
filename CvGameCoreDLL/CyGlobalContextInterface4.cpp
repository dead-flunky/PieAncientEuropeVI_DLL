//
// published python interface for CyGlobalContext
// Author - Mustafa Thamer
//

#include "CvGameCoreDLL.h"
#include "CyMap.h"
#include "CyPlayer.h"
#include "CyGame.h"
#include "CyGlobalContext.h"
#include "CvRandom.h"
//#include "CvStructs.h"
#include "CvInfos.h"
#include "CyTeam.h"


void CyGlobalContextPythonInterface4(python::class_<CyGlobalContext>& x)
{
	OutputDebugString("Python Extension Module - CyGlobalContextPythonInterface1\n");

	x
		.def("getNumMissionInfos", &CyGlobalContext::getNumMissionInfos, "() - Total Mission Infos XML\\Units\\CIV4MissionInfos.xml")
		.def("getMissionInfo", &CyGlobalContext::getMissionInfo, python::return_value_policy<python::reference_existing_object>(), "CvMissionInfo* (int i) - CvInfo for MissionID")

		.def("getNumAutomateInfos", &CyGlobalContext::getNumAutomateInfos, "() - Total Automate Infos XML\\Units\\CIV4AutomateInfos.xml")
		.def("getAutomateInfo", &CyGlobalContext::getAutomateInfo, python::return_value_policy<python::reference_existing_object>(), "CvAutomateInfo* (int i) - CvInfo for AutomateID")

		.def("getNumCommandInfos", &CyGlobalContext::getNumCommandInfos, "() - Total Command Infos XML\\Units\\CIV4CommandInfos.xml")
		.def("getCommandInfo", &CyGlobalContext::getCommandInfo, python::return_value_policy<python::reference_existing_object>(), "CvCommandInfo* (int i) - CvInfo for CommandID")

		.def("getNumControlInfos", &CyGlobalContext::getNumControlInfos, "() - Total Control Infos XML\\Units\\CIV4ControlInfos.xml")
		.def("getControlInfo", &CyGlobalContext::getControlInfo, python::return_value_policy<python::reference_existing_object>(), "CvControlInfo* (int i) - CvInfo for ControlID")

		.def("getNumPromotionInfos", &CyGlobalContext::getNumPromotionInfos, "() - Total Promotion Infos XML\\Units\\CIV4PromotionInfos.xml")
		.def("getPromotionInfo", &CyGlobalContext::getPromotionInfo, python::return_value_policy<python::reference_existing_object>(), "CvPromotionInfo* (int i) - CvInfo for PromotionID")

		.def("getNumTechInfos", &CyGlobalContext::getNumTechInfos, "() - Total Technology Infos XML\\Technologies\\CIV4TechInfos.xml")
		.def("getTechInfo", &CyGlobalContext::getTechInfo, python::return_value_policy<python::reference_existing_object>(), "CvTechInfo* (int i) - CvInfo for TechID")

		.def("getNumSpecialBuildingInfos", &CyGlobalContext::getNumSpecialBuildingInfos, "() - Total Special Building Infos")
		.def("getSpecialBuildingInfo", &CyGlobalContext::getSpecialBuildingInfo, python::return_value_policy<python::reference_existing_object>(), "CvSpecialBuildingInfo* (int i) - CvInfo for SpecialBuildingID")

		.def("getNumReligionInfos", &CyGlobalContext::getNumReligionInfos, "() - Total Religion Infos XML\\GameInfo\\CIV4ReligionInfos.xml")
		.def("getReligionInfo", &CyGlobalContext::getReligionInfo, python::return_value_policy<python::reference_existing_object>(), "CvReligionInfo* (int i) - CvInfo for ReligionID")

		.def("getNumCorporationInfos", &CyGlobalContext::getNumCorporationInfos, "() - Total Religion Infos XML\\GameInfo\\CIV4CorporationInfos.xml")
		.def("getCorporationInfo", &CyGlobalContext::getCorporationInfo, python::return_value_policy<python::reference_existing_object>(), "CvCorporationInfo* (int i) - CvInfo for CorporationID")

		.def("getNumVictoryInfos", &CyGlobalContext::getNumVictoryInfos, "() - Total Victory Infos XML\\GameInfo\\CIV4VictoryInfos.xml")
		.def("getVictoryInfo", &CyGlobalContext::getVictoryInfo, python::return_value_policy<python::reference_existing_object>(), "CvVictoryInfo* (int i) - CvInfo for VictoryID")

		.def("getNumSpecialistInfos", &CyGlobalContext::getNumSpecialistInfos, "() - Total Specialist Infos XML\\Units\\CIV4SpecialistInfos.xml")
		.def("getSpecialistInfo", &CyGlobalContext::getSpecialistInfo, python::return_value_policy<python::reference_existing_object>(), "CvSpecialistInfo* (int i) - CvInfo for SpecialistID")

		.def("getNumCivicOptionInfos", &CyGlobalContext::getNumCivicOptionInfos, "() - Total Civic Infos XML\\Misc\\CIV4CivicOptionInfos.xml")
		.def("getCivicOptionInfo", &CyGlobalContext::getCivicOptionInfo, python::return_value_policy<python::reference_existing_object>(), "CvCivicOptionInfo* (int i) - CvInfo for CivicID")

		.def("getNumCivicInfos", &CyGlobalContext::getNumCivicInfos, "() - Total Civic Infos XML\\Misc\\CIV4CivicInfos.xml")
		.def("getCivicInfo", &CyGlobalContext::getCivicInfo, python::return_value_policy<python::reference_existing_object>(), "CvCivicInfo* (int i) - CvInfo for CivicID")

		.def("getNumDiplomacyInfos", &CyGlobalContext::getNumDiplomacyInfos, "() - Total diplomacy Infos XML\\GameInfo\\CIV4DiplomacyInfos.xml")
		.def("getDiplomacyInfo", &CyGlobalContext::getDiplomacyInfo, python::return_value_policy<python::reference_existing_object>(), "CvDiplomacyInfo* (int i) - CvInfo for DiplomacyID")

		.def("getNumProjectInfos", &CyGlobalContext::getNumProjectInfos, "() - Total Project Infos XML\\GameInfo\\CIV4ProjectInfos.xml")
		.def("getProjectInfo", &CyGlobalContext::getProjectInfo, python::return_value_policy<python::reference_existing_object>(), "CvProjectInfo* (int i) - CvInfo for ProjectID")

		.def("getNumVoteInfos", &CyGlobalContext::getNumVoteInfos, "() - Total VoteInfos")
		.def("getVoteInfo", &CyGlobalContext::getVoteInfo, python::return_value_policy<python::reference_existing_object>(), "CvVoteInfo* (int i) - CvInfo for VoteID")

		.def("getNumProcessInfos", &CyGlobalContext::getNumProcessInfos, "() - Total ProcessInfos")
		.def("getProcessInfo", &CyGlobalContext::getProcessInfo, python::return_value_policy<python::reference_existing_object>(), "CvProcessInfo* (int i) - CvInfo for ProcessID")

		.def("getNumEmphasizeInfos", &CyGlobalContext::getNumEmphasizeInfos, "() - Total EmphasizeInfos")
		.def("getEmphasizeInfo", &CyGlobalContext::getEmphasizeInfo, python::return_value_policy<python::reference_existing_object>(), "CvEmphasizeInfo* (int i) - CvInfo for EmphasizeID")

		.def("getHurryInfo", &CyGlobalContext::getHurryInfo, python::return_value_policy<python::reference_existing_object>(), "CvHurryInfo* (int i) - CvInfo for HurryID")

		.def("getUnitAIInfo", &CyGlobalContext::getUnitAIInfo, python::return_value_policy<python::reference_existing_object>(), "CvInfoBase* (int i)")

		.def("getColorInfo", &CyGlobalContext::getColorInfo, python::return_value_policy<python::reference_existing_object>(), "CvColorInfo* (int i)")

		.def("getInfoTypeForString", &CyGlobalContext::getInfoTypeForString, "int (const char* szInfoType) - returns the info index with the matching type string")
		.def("getTypesEnum", &CyGlobalContext::getTypesEnum, "int (const char* szType) - returns the type enum from a type string")

		.def("getNumPlayerColorInfos", &CyGlobalContext::getNumPlayerColorInfos, "int () - Returns number of PlayerColorInfos")
		.def("getPlayerColorInfo", &CyGlobalContext::getPlayerColorInfo, python::return_value_policy<python::reference_existing_object>(), "CvPlayerColorInfo* (int i)")

		.def("getNumQuestInfos", &CyGlobalContext::getNumQuestInfos, "int () - Returns number of QuestInfos")
		.def("getQuestInfo", &CyGlobalContext::getQuestInfo, python::return_value_policy<python::reference_existing_object>(), "CvQuestInfo* (int i) - Returns info object")

		.def("getNumTutorialInfos", &CyGlobalContext::getNumTutorialInfos, "int () - Returns number of TutorialInfos")
		.def("getTutorialInfo", &CyGlobalContext::getTutorialInfo, python::return_value_policy<python::reference_existing_object>(), "CvTutorialInfo* (int i) - Returns info object")

		.def("getNumEventTriggerInfos", &CyGlobalContext::getNumEventTriggerInfos, "int () - Returns number of EventTriggerInfos")
		.def("getEventTriggerInfo", &CyGlobalContext::getEventTriggerInfo, python::return_value_policy<python::reference_existing_object>(), "CvEventTriggerInfo* (int i) - Returns info object")

		.def("getNumEventInfos", &CyGlobalContext::getNumEventInfos, "int () - Returns number of EventInfos")
		.def("getEventInfo", &CyGlobalContext::getEventInfo, python::return_value_policy<python::reference_existing_object>(), "CvEventInfo* (int i) - Returns info object")

		.def("getNumEspionageMissionInfos", &CyGlobalContext::getNumEspionageMissionInfos, "int () - Returns number of EspionageMissionInfos")
		.def("getEspionageMissionInfo", &CyGlobalContext::getEspionageMissionInfo, python::return_value_policy<python::reference_existing_object>(), "CvEspionageMissionInfo* (int i) - Returns info object")

		.def("getNumHints", &CyGlobalContext::getNumHints, "int () - Returns number of Hints")
		.def("getHints", &CyGlobalContext::getHints, python::return_value_policy<python::reference_existing_object>(), "CvInfoBase* (int i) - Returns info object")

		.def("getNumMainMenus", &CyGlobalContext::getNumMainMenus, "int () - Returns number")
		.def("getMainMenus", &CyGlobalContext::getMainMenus, python::return_value_policy<python::reference_existing_object>(), "CvMainMenuInfo* (int i) - Returns info object")

		.def("getNumVoteSourceInfos", &CyGlobalContext::getNumVoteSourceInfos, "int ()")
		.def("getVoteSourceInfo", &CyGlobalContext::getVoteSourceInfo, python::return_value_policy<python::reference_existing_object>(), "CvVoteSourceInfo* (int i)")

		.def("getNumVoteSourceInfos", &CyGlobalContext::getNumVoteSourceInfos, "int ()")
		.def("getVoteSourceInfo", &CyGlobalContext::getVoteSourceInfo, python::return_value_policy<python::reference_existing_object>(), "CvVoteSourceInfo* (int i)")

		// ArtInfos
		.def("getNumInterfaceArtInfos", &CyGlobalContext::getNumInterfaceArtInfos, "() - Total InterfaceArtnology Infos XML\\InterfaceArtnologies\\CIV4InterfaceArtInfos.xml")
		.def("getInterfaceArtInfo", &CyGlobalContext::getInterfaceArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoInterface* (int i) - CvArtInfo for InterfaceArtID")

		.def("getNumMovieArtInfos", &CyGlobalContext::getNumMovieArtInfos, "() - Total MovieArt Infos XML\\MovieArtInfos\\CIV4ArtDefines.xml")
		.def("getMovieArtInfo", &CyGlobalContext::getMovieArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoMovie* (int i) - CvArtInfo for MovieArtID")

		.def("getNumMiscArtInfos", &CyGlobalContext::getNumMiscArtInfos, "() - Total MiscArtnology Infos XML\\MiscArt\\CIV4MiscArtInfos.xml")
		.def("getMiscArtInfo", &CyGlobalContext::getMiscArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoMisc* (int i) - CvArtInfo for MiscArtID")

		.def("getNumUnitArtInfos", &CyGlobalContext::getNumUnitArtInfos, "() - Total UnitArtnology Infos XML\\UnitArt\\CIV4UnitArtInfos.xml")
		.def("getUnitArtInfo", &CyGlobalContext::getUnitArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoUnit* (int i) - CvArtInfo for UnitID")

		.def("getNumBuildingArtInfos", &CyGlobalContext::getNumBuildingArtInfos, "int () - Returns number of BuildingArtInfos")
		.def("getBuildingArtInfo", &CyGlobalContext::getBuildingArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoBuilding* (int i) - CvArtInfo for BuildingID")

		.def("getNumCivilizationArtInfos", &CyGlobalContext::getNumCivilizationArtInfos, "int () - Returns number of CivilizationArtInfos")
		.def("getCivilizationArtInfo", &CyGlobalContext::getCivilizationArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoCivilization* (int i) - CvArtInfo for CivilizationID")

		.def("getNumLeaderheadArtInfos", &CyGlobalContext::getNumLeaderheadArtInfos, "int () - Returns number of LeaderHeadArtInfos")
		.def("getLeaderheadArtInfo", &CyGlobalContext::getLeaderheadArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoLeaderhead* (int i) - CvArtInfo for LeaderheadID")

		.def("getNumBonusArtInfos", &CyGlobalContext::getNumBonusArtInfos, "int () - Returns number of BonusArtInfos")
		.def("getBonusArtInfo", &CyGlobalContext::getBonusArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoBonus* (int i) - Returns info object")

		.def("getNumImprovementArtInfos", &CyGlobalContext::getNumImprovementArtInfos, "int () - Returns number of ImprovementArtInfos")
		.def("getImprovementArtInfo", &CyGlobalContext::getImprovementArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoImprovement* (int i) - Returns info object")

		.def("getNumTerrainArtInfos", &CyGlobalContext::getNumTerrainArtInfos, "int () - Returns number of TerrainArtInfos")
		.def("getTerrainArtInfo", &CyGlobalContext::getTerrainArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoTerrain* (int i) - Returns info object")

		.def("getNumFeatureArtInfos", &CyGlobalContext::getNumFeatureArtInfos, "int () - Returns number of FeatureArtInfos")
		.def("getFeatureArtInfo", &CyGlobalContext::getFeatureArtInfo, python::return_value_policy<python::reference_existing_object>(), "CvArtInfoFeature* (int i) - Returns info object")

		// Types
		.def("getNumEntityEventTypes", &CyGlobalContext::getNumEntityEventTypes, "int () - Returns number of EntityEventTypes")
		.def("getEntityEventType", &CyGlobalContext::getEntityEventTypes, "string () - Returns enum string")

		.def("getNumAnimationOperatorTypes", &CyGlobalContext::getNumAnimationOperatorTypes, "int () - Returns number of AnimationOperatorTypes")
		.def("getAnimationOperatorTypes", &CyGlobalContext::getAnimationOperatorTypes, "string () - Returns enum string")

		.def("getFunctionTypes", &CyGlobalContext::getFunctionTypes, "string () - Returns enum string")

		.def("getNumArtStyleTypes", &CyGlobalContext::getNumArtStyleTypes, "int () - Returns number of ArtStyleTypes")
		.def("getArtStyleTypes", &CyGlobalContext::getArtStyleTypes, "string () - Returns enum string")

		.def("getNumFlavorTypes", &CyGlobalContext::getNumFlavorTypes, "int () - Returns number of FlavorTypes")
		.def("getFlavorTypes", &CyGlobalContext::getFlavorTypes, "string () - Returns enum string")

		.def("getNumUnitArtStyleTypeInfos", &CyGlobalContext::getNumUnitArtStyleTypeInfos, "int () - Returns number of UnitArtStyleTypes")
		.def("getUnitArtStyleTypeInfo", &CyGlobalContext::getUnitArtStyleTypeInfo, python::return_value_policy<python::reference_existing_object>(), "CvUnitArtStyleTypeInfo* (int i) - CvInfo for UnitArtStyleTypeID")

		.def("getNumCitySizeTypes", &CyGlobalContext::getNumCitySizeTypes, "int () - Returns number of CitySizeTypes")
		.def("getCitySizeTypes", &CyGlobalContext::getCitySizeTypes, "string () - Returns enum string")

		.def("getContactTypes", &CyGlobalContext::getContactTypes, "string () - Returns enum string")

		.def("getDiplomacyPowerTypes", &CyGlobalContext::getDiplomacyPowerTypes, "string () - Returns enum string")
		// PBMod
		.def("getAltrootDir", &CyGlobalContext::getAltrootDir, "string ( )" )
		.def("sendChat", &CyGlobalContext::sendChat, "void (wstring szString, int targetType)")
		.def("sendPause", &CyGlobalContext::sendPause, "void (int iPauseID = -1)")
		;
}
