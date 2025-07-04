#ifndef _737MAXSDK_COMMAND_H_
#define _737MAXSDK_COMMAND_H_

typedef enum    KEY_COMMAND_IFLY737MAX
{
	//**********************************************************************************************************************************
	// v1.0.0
	// 2020-12-24
	//**********************************************************************************************************************************

	//-------------------------------------------------------------
	//Airplane General
	//-------------------------------------------------------------
	KEY_COMMAND_GENERAL_LIGHTS_TEST_DEC,//Master LIGHTS TEST and DIM Switch - Move Up							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHTS_TEST_INC,//Master LIGHTS TEST and DIM Switch - Move Down							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHTS_TEST_TEST,//Master LIGHTS TEST and DIM Switch - Move to TEST						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHTS_TEST_BRT,//Master LIGHTS TEST and DIM Switch - Move to BRT						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHTS_TEST_DIM,//Master LIGHTS TEST and DIM Switch - Move to DIM						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_DOOR_LOCK_DEC,//Flight Deck (FLT DK) Door Lock Selector - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_DOOR_LOCK_INC,//Flight Deck (FLT DK) Door Lock Selector - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_DOOR_LOCK_SET,//Flight Deck (FLT DK) Door Lock Selector - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch UNLKD; 1:switch AUTO; 2:switch DENY
	KEY_COMMAND_GENERAL_LIGHT_LOCK_FAIL,//LOCK FAIL Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_AUTO_UNLK,//AUTO Unlock (UNLK) Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LANDING_LIGHT_1_DEC,//Left LANDING Light Switch - Move Up								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LANDING_LIGHT_1_INC,//Left LANDING Light Switch - Move Down								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LANDING_LIGHT_1_SET,//Left LANDING Light Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch FLASH; 2:switch ON
	KEY_COMMAND_GENERAL_LANDING_LIGHT_2_DEC,//Right LANDING Light Switch - Move Up								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LANDING_LIGHT_2_INC,//Right LANDING Light Switch - Move Down							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LANDING_LIGHT_2_SET,//Left LANDING Light Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch FLASH; 2:switch ON
	KEY_COMMAND_GENERAL_RUNWAY_TURNOFF_LIGHT_1,//Left RUNWAY TURNOFF Light Switch - Click						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_RUNWAY_TURNOFF_LIGHT_1_SET,//Left RUNWAY TURNOFF Light Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_GENERAL_RUNWAY_TURNOFF_LIGHT_2,//Right RUNWAY TURNOFF Light Switch - Click						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_RUNWAY_TURNOFF_LIGHT_2_SET,//Right RUNWAY TURNOFF Light Switch - Set					Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_GENERAL_TAXI_LIGHT,//TAXI Light Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_TAXI_LIGHT_SET,//TAXI Light Switch - Set												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_GENERAL_LOGO_LIGHT,//LOGO Light Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LOGO_LIGHT_SET,//LOGO Light Switch - Set												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_GENERAL_ANTI_COLLISION_LIGHT,//ANTI-COLLISION Light Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_ANTI_COLLISION_LIGHT_SET,//ANTI-COLLISION Light Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_GENERAL_WING_LIGHT,//WING Illumination Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_WING_LIGHT_SET,//WING Illumination Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_GENERAL_WHEEL_WELL_LIGHT,//WHEEL WELL Light Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_WHEEL_WELL_LIGHT_SET,//WHEEL WELL Light Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_GENERAL_POSITION_LIGHT_DEC,//POSITION Light Switch - Move Up									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_POSITION_LIGHT_INC,//POSITION Light Switch - Move Down									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_POSITION_LIGHT_SET,//POSITION Light Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch STROBE&STEADY; 1:switch OFF; 2:switch STEADY
	KEY_COMMAND_GENERAL_DOME_LIGHT_DEC,//DOME Light Switch - Move Up											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_DOME_LIGHT_INC,//DOME Light Switch - Move Down											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_DOME_LIGHT_SET,//DOME Light Switch - Set												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch DIM; 1:switch OFF; 2:switch BRIGHT				Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_GENERAL_EMER_LIGHT_DEC,//Emergency (EMER) EXIT LIGHTS Switch - Move Up							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_EMER_LIGHT_INC,//Emergency (EMER) EXIT LIGHTS Switch - Move Down						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_EMER_LIGHT_SET,//Emergency (EMER) EXIT LIGHTS Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ARMED; 2:switch ON
	KEY_COMMAND_GENERAL_LIGHT_NOT_ARMED,//Emergency (EMER) EXIT LIGHTS NOT ARMED Light - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_NO_SMOKING_DEC,//NO SMOKING Switch - Move Up											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_NO_SMOKING_INC,//NO SMOKING Switch - Move Down											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_NO_SMOKING_SET,//NO SMOKING Switch - Set												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch AUTO; 2:switch ON
	KEY_COMMAND_GENERAL_FASTEN_BELTS_DEC,//FASTEN BELTS Switch - Move Up										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_FASTEN_BELTS_INC,//FASTEN BELTS Switch - Move Up										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_FASTEN_BELTS_SET,//FASTEN BELTS Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch AUTO; 2:switch ON
	KEY_COMMAND_GENERAL_LIGHT_FWD_ENTRY,//Exterior Door (FWD ENTRY) Annunciations - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_LEFT_FWD_OVERWING,//Exterior Door (LEFT FWD OVERWING) Annunciations - Press		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_LEFT_AFT_OVERWING,//Exterior Door (LEFT AFT OVERWING) Annunciations - Press		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_AFT_ENTRY,//Exterior Door (AFT ENTRY) Annunciations - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_FWD_SERVICE,//Exterior Door (FWD SERVICE) Annunciations - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_RIGHT_FWD_OVERWING,//Exterior Door (RIGHT FWD OVERWING) Annunciations - Press		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_RIGHT_AFT_OVERWING,//Exterior Door (RIGHT AFT OVERWING) Annunciations - Press		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_AFT_SERVICE,//Exterior Door (AFT SERVICE) Annunciations - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_EQUIP,//Exterior Door (EQUIP) Annunciations - Press								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_LEFT_MID_EXIT,//Exterior Door (LEFT MID EXIT) Annunciations - Press				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_RIGHT_MID_EXIT,//Exterior Door (RIGHT MID EXIT) Annunciations - Press				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_FWD_CARGO,//Exterior Door (FWD CARGO) Annunciations - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_AFT_CARGO,//Exterior Door (AFT CARGO) Annunciations - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_LIGHT_AIRSTAIR,//Exterior Door (AIRSTAIR) Annunciations - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_CAPT_MAIN_PANEL_DEC,//Captain's MAIN PANEL Light Control - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_CAPT_MAIN_PANEL_INC,//Captain's MAIN PANEL Light Control - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_CAPT_MAIN_PANEL_SET,//Captain's MAIN PANEL Light Control - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_GENERAL_FO_MAIN_PANEL_DEC,//FO's MAIN PANEL Light Control - Rotate Left							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_FO_MAIN_PANEL_INC,//FO's MAIN PANEL Light Control - Rotate Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_FO_MAIN_PANEL_SET,//FO's MAIN PANEL Light Control - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_GENERAL_PASS_OXYGEN,//Passenger Oxygen (PASS OXYGEN) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_PASS_OXYGEN_SET,//Passenger Oxygen (PASS OXYGEN) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch NORMAL; 1:switch ON 							Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_GENERAL_LIGHT_PASS_OXY_ON,//Passenger Oxygen On Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_ELT,//Emergency Locator Transmitter Switch - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_ELT_SET,//Emergency Locator Transmitter Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2:0:switch ARM; 1:switch ON 								Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_GENERAL_LIGHT_ELT,//Emergency Locator Transmitter Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_GENERAL_CB_BRIGHT_DEC,//CIRCUIT BREAKER Light Control - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_CB_BRIGHT_INC,//CIRCUIT BREAKER Light Control - Rotate Right							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_CB_BRIGHT_SET,//CIRCUIT BREAKER Light Control - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2:0~20, from DIM to BRIGHT
	KEY_COMMAND_GENERAL_OVHT_PANEL_BRIGHT_DEC,//Overhead PANEL Light Control - Rotate Left						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_OVHT_PANEL_BRIGHT_INC,//Overhead PANEL Light Control - Rotate Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_OVHT_PANEL_BRIGHT_SET,//Overhead PANEL Light Control - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2:0~20, from DIM to BRIGHT

	KEY_COMMAND_GENERAL_AFT_ELEC_FLOOD_BRIGHT_DEC,//Aft Electronics FLOOD Light Control - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_AFT_ELEC_FLOOD_BRIGHT_INC,//Aft Electronics FLOOD Light Control - Rotate Right			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_AFT_ELEC_FLOOD_BRIGHT_SET,//Aft Electronics FLOOD Light Control - Set					Value1: 0: OFF the click sound; 1: ON the click sound			Value2:0~20, from DIM to BRIGHT
	KEY_COMMAND_GENERAL_AFT_ELEC_PANEL_BRIGHT_DEC,//Aft Electronics PANEL Light Control - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_AFT_ELEC_PANEL_BRIGHT_INC,//Aft Electronics PANEL Light Control - Rotate Right			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GENERAL_AFT_ELEC_PANEL_BRIGHT_SET,//Aft Electronics PANEL Light Control - Set					Value1: 0: OFF the click sound; 1: ON the click sound			Value2:0~20, from DIM to BRIGHT


	//-------------------------------------------------------------
	//Air Systems
	//-------------------------------------------------------------
	KEY_COMMAND_AIRSYSTEM_ENG_1_BLEED,//Engine 1 BLEED Air Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_ENG_1_BLEED_SET,//Engine 1 BLEED Air Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_AIRSYSTEM_ENG_2_BLEED,//Engine 2 BLEED Air Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_ENG_2_BLEED_SET,//Engine 2 BLEED Air Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_AIRSYSTEM_APU_BLEED,//APU BLEED Air Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_APU_BLEED_SET,//APU BLEED Air Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_AIRSYSTEM_PACK_1_UP,//Left Air Conditioning PACK Switch - Move Up								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_PACK_1_DOWN,//Left Air Conditioning PACK Switch - Move Up								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_PACK_1_SET,//Left Air Conditioning PACK Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch AUTO; 2:switch HIGH
	KEY_COMMAND_AIRSYSTEM_PACK_2_UP,//Right Air Conditioning PACK Switch - Move Up								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_PACK_2_DOWN,//Right Air Conditioning PACK Switch - Move Up							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_PACK_2_SET,//Right Air Conditioning PACK Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch AUTO; 2:switch HIGH
	KEY_COMMAND_AIRSYSTEM_RECIRC_L_FAN,//Left Recirculation (RECIRC) FAN Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_RECIRC_L_FAN_SET,//Left Recirculation (RECIRC) FAN Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch AUTO
	KEY_COMMAND_AIRSYSTEM_RECIRC_R_FAN,//Right Recirculation (RECIRC) FAN Switch - Click						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_RECIRC_R_FAN_SET,//Right Recirculation (RECIRC) FAN Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch AUTO
	KEY_COMMAND_AIRSYSTEM_WINGBODY_OVHT_TEST,//Wing-Body Overheat (OVHT) TEST Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SEL_1_DEC,//Temperature Selector (CONT CAB) - Rotate Left						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SEL_1_INC,//Temperature Selector (CONT CAB) - Rotate Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SEL_1_SET,//Temperature Selector (CONT CAB) - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2:0~7, from OFF to W
	KEY_COMMAND_AIRSYSTEM_TEMP_SEL_2_DEC,//Temperature Selector (FWD CAB) - Rotate Left							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SEL_2_INC,//Temperature Selector (FWD CAB) - Rotate Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SEL_2_SET,//Temperature Selector (FWD CAB) - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2:0~7, from OFF to W
	KEY_COMMAND_AIRSYSTEM_TEMP_SEL_3_DEC,//Temperature Selector (AFT CAB) - Rotate Left							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SEL_3_INC,//Temperature Selector (AFT CAB) - Rotate Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SEL_3_SET,//Temperature Selector (AFT CAB) - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2:0~7, from OFF to W
	KEY_COMMAND_AIRSYSTEM_ISOLATION_VALVE_UP,//ISOLATION VALVE Switch - Move Up									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_ISOLATION_VALVE_DOWN,//ISOLATION VALVE Switch - Move Down								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_ISOLATION_VALVE_SET,//ISOLATION VALVE Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch CLOSE; 1:switch AUTO; 2:switch OPEN
	KEY_COMMAND_AIRSYSTEM_TRIP_RESET,//TRIP RESET Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SOURCE_DEC,//AIR Temperature (TEMP) Source Selector - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SOURCE_INC,//AIR Temperature (TEMP) Source Selector - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TEMP_SOURCE_SET,//AIR Temperature (TEMP) Source Selector - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch DUCT CONT; 1:switch DUCT FWD; 2:switch DUCT AFT; 3:switch PASS CAB FWD; 4:switch PASS CAB AFT; 5:switch PACK R; 6:switch PACK L
	KEY_COMMAND_AIRSYSTEM_TRIM_AIR,//TRIM AIR Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_TRIM_AIR_SET,//TRIM AIR Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_AIRSYSTEM_OUTFLOW_VALVE_CLOSE,//Outflow Valve Switch - Move Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_OUTFLOW_VALVE_OPEN,//Outflow Valve Switch - Move Right								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_FLT_ALT_INC,//Flight Altitude Selector - Rotate Left									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_FLT_ALT_DEC,//Flight Altitude Selector - Rotate Right									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_FLT_ALT_SET,//Flight Altitude Selector - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: Altitude(ft), -1000~42000
	KEY_COMMAND_AIRSYSTEM_LDG_ALT_INC,//Landing Altitude Selector - Rotate Left									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LDG_ALT_DEC,//Landing Altitude Selector - Rotate Right								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LDG_ALT_SET,//Landing Altitude Selector - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: Altitude(ft), -1000~14000
	KEY_COMMAND_AIRSYSTEM_PRESSURIZATION_MODE_DEC,//Pressurization Mode Selector - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_PRESSURIZATION_MODE_INC,//Pressurization Mode Selector - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_PRESSURIZATION_MODE_SET,//Pressurization Mode Selector - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch AUTO; 1:switch ALTN; 2:switch MAN
	KEY_COMMAND_AIRSYSTEM_ALT_HORN_CUTOUT,//Altitude (ALT) HORN CUTOUT Switch - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_HIGH_ALTITUDE_LANDING,//High Altitude Landing Switch - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_HIGH_ALTITUDE_LANDING_SET,//High Altitude Landing Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_AIRSYSTEM_COOLING_SUPPLY,//Equipment (EQUIP) COOLING SUPPLY Switch - Click						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_COOLING_SUPPLY_SET,//Equipment (EQUIP) COOLING SUPPLY Switch - Set					Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch NORM; 1:switch ALTN
	KEY_COMMAND_AIRSYSTEM_COOLING_EXHAUST,//Equipment (EQUIP) COOLING EXHAUST Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_COOLING_EXHAUST_SET,//Equipment (EQUIP) COOLING EXHAUST Switch - Set					Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch NORM; 1:switch ALTN
	KEY_COMMAND_AIRSYSTEM_LIGHT_ZONE_TEMP_1,//ZONE TEMP (CONT CAB) Light - Press								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_ZONE_TEMP_2,//ZONE TEMP (FWD CAB) Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_ZONE_TEMP_3,//ZONE TEMP (AFT CAB) Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_DUAL_BLEED,//DUAL BLEED Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_PACK_1,//Left PACK Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_PACK_2,//Right PACK Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_WINGBODY_OVWEHEAT_1,//Left WING-BODY OVERHEAT Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_WINGBODY_OVWEHEAT_2,//Right WING-BODY OVERHEAT Light - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_BLEED_1,//Left BLEED Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_BLEED_2,//Right BLEED Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_AUTO_FAIL,//AUTO FAIL Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_OFF_SCHED_DESCENT,//OFF Schedule (SCHED) DESCENT Light - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_ALTN,//Alternate (ALTN) Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_MANUAL,//MANUAL Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_SUPPLY_OFF,//Equipment Cooling Supply OFF Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_EXHAUST_OFF,//Equipment Cooling Exhaust OFF Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AIRSYSTEM_LIGHT_EQUIP_SMOKE,//Equipment Cooling EQUIP SMOKE Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound



	//-------------------------------------------------------------
	//Anti-Ice
	//-------------------------------------------------------------
	KEY_COMMAND_ANTIICE_LEFT_SIDE_WINDOW_HEAT,//Left SIDE WINDOW HEAT Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LEFT_SIDE_WINDOW_HEAT_SET,//Left SIDE WINDOW HEAT Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_ANTIICE_LEFT_FWD_WINDOW_HEAT,//Left FWD WINDOW HEAT Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LEFT_FWD_WINDOW_HEAT_SET,//Left FWD WINDOW HEAT Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_ANTIICE_RIGHT_FWD_WINDOW_HEAT,//Right FWD WINDOW HEAT Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_RIGHT_FWD_WINDOW_HEAT_SET,//Right FWD WINDOW HEAT Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_ANTIICE_RIGHT_SIDE_WINDOW_HEAT,//Right SIDE WINDOW HEAT Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_RIGHT_SIDE_WINDOW_HEAT_SET,//Right SIDE WINDOW HEAT Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_ANTIICE_WINDOW_HEAT_TEST_DEC,//WINDOW HEAT Test Switch - Move Up								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_WINDOW_HEAT_TEST_INC,//WINDOW HEAT Test Switch - Move Down								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_WINDOW_HEAT_TEST_SET,//WINDOW HEAT Test Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OVHT; 1:switch Neutral; 2:switch PWR TEST
	KEY_COMMAND_ANTIICE_PROBE_A_HEAT,//PROBE HEAT A Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_PROBE_A_HEAT_SET,//PROBE HEAT A Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch AUTO; 1:switch ON
	KEY_COMMAND_ANTIICE_PROBE_B_HEAT,//PROBE HEAT B Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_PROBE_B_HEAT_SET,//PROBE HEAT B Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch AUTO; 1:switch ON
	KEY_COMMAND_ANTIICE_WING,//WING ANTI-ICE Switch - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_WING_SET,//WING ANTI-ICE Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_ANTIICE_ENG_1,//ENGINE 1 ANTI-ICE Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_ENG_1_SET,//ENGINE 1 ANTI-ICE Switch - Set												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_ANTIICE_ENG_2,//ENGINE 2 ANTI-ICE Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_ENG_2_SET,//ENGINE 2 ANTI-ICE Switch - Set												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_ANTIICE_TAT_TEST,//TAT TEST Switch - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_WINDOW_OVERHEAT_1,//Left SIDE Window OVERHEAT Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_WINDOW_OVERHEAT_2,//Left FWD Window OVERHEAT Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_WINDOW_OVERHEAT_3,//Right FWD Window OVERHEAT Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_WINDOW_OVERHEAT_4,//Right SIDE Window OVERHEAT Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_WINDOW_HEAT_ON_1,//Left SIDE Window Heat ON Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_WINDOW_HEAT_ON_2,//Left FWD Window Heat ON Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_WINDOW_HEAT_ON_3,//Right FWD Window Heat ON Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_WINDOW_HEAT_ON_4,//Right SIDE Window Heat ON Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_CAPT_PITOT,//Probe Heat (CAPT PITOT) Light - Press								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_L_ELEV_PITOT,//Probe Heat (L ELEV PITOT) Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_L_ALPHA_VANE,//Probe Heat (L ALPHA VANE) Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_TEMP_PROBE,//Probe Heat (TEMP PROBE) Light - Press								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_FO_PITOT,//Probe Heat (FO PITOT) Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_R_ELEV_PITOT,//Probe Heat (R ELEV PITOT) Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_R_ALPHA_VANE,//Probe Heat (R ALPHA VANE) Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_AUX_PITOT,//Probe Heat (AUX PITOT) Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_L_VALVE,//Left Wing VALVE Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_R_VALVE,//Right Wing VALVE Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_COWL_ANTI_ICE_1,//Engine 1 COWL ANTI-ICE Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_COWL_ANTI_ICE_2,//Engine 2 COWL ANTI-ICE Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_COWL_VALVE_1,//Engine 1 COWL VALVE Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_COWL_VALVE_2,//Engine 2 COWL VALVE Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_ENG_ANTI_ICE_1,//Engine 1 ANTI-ICE Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_ENG_ANTI_ICE_2,//Engine 2 ANTI-ICE Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LIGHT_ICE_DETECTOR,//ICE DETECTOR Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LEFT_WINDSHIELD_WIPER_DEC,//Left Windshield WIPER Selector - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LEFT_WINDSHIELD_WIPER_INC,//Left Windshield WIPER Selector - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_LEFT_WINDSHIELD_WIPER_SET,//Left Windshield WIPER Selector - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch PARK; 1:switch INT; 2:switch LOW; 3:switch HIGH
	KEY_COMMAND_ANTIICE_RIGHT_WINDSHIELD_WIPER_DEC,//Right Windshield WIPER Selector - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_RIGHT_WINDSHIELD_WIPER_INC,//Right Windshield WIPER Selector - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ANTIICE_RIGHT_WINDSHIELD_WIPER_SET,//Right Windshield WIPER Selector - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch PARK; 1:switch INT; 2:switch LOW; 3:switch HIGH


	//-------------------------------------------------------------
	//Automatic Flight
	//-------------------------------------------------------------
	KEY_COMMAND_AUTOMATICFLIGHT_COURSE_1_DEC,//Left Course Selector - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_COURSE_1_INC,//Left Course Selector - Rotate Right								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_COURSE_1_SET,//Left Course Selector - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~359
	KEY_COMMAND_AUTOMATICFLIGHT_COURSE_2_DEC,//Right Course Selector - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_COURSE_2_INC,//Right Course Selector - Rotate Right								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_COURSE_2_SET,//Right Course Selector - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~359
	KEY_COMMAND_AUTOMATICFLIGHT_IAS_MACH_DEC,//IAS/MACH Selector - Rotate Left									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_IAS_MACH_INC,//IAS/MACH Selector - Rotate Right									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_IAS_MACH_SET,//IAS/MACH Selector - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=MACH; 1=IAS; 								Value3: If Value2==0, then 0.60~0.82, If Value2==1, then 100~340
	KEY_COMMAND_AUTOMATICFLIGHT_CHANGEOVER,//Changeover (C/O) Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_CHANGEOVER_SET,//Changeover (C/O) Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=MACH; 	1=IAS
	KEY_COMMAND_AUTOMATICFLIGHT_BANK_ANGLE_DEC,//Bank Angle Selector - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_BANK_ANGLE_INC,//Bank Angle Selector - Rotate Right								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_BANK_ANGLE_SET,//Bank Angle Selector - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=10degree, 1=15degree, 2=20degree, 3=25degree, 4=30degree
	KEY_COMMAND_AUTOMATICFLIGHT_HDG_SEL_DEC,//Heading Selector - Rotate Left									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_HDG_SEL_INC,//Heading Selector - Rotate Right									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_HDG_SEL_SET,//Heading Selector - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~359
	KEY_COMMAND_AUTOMATICFLIGHT_ALT_SEL_DEC,//Altitude Selector (SEL) - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_ALT_SEL_INC,//Altitude Selector (SEL) - Rotate Right							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_ALT_SEL_SET,//Altitude Selector (SEL) - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~50000, 100ft increments
	KEY_COMMAND_AUTOMATICFLIGHT_VS_DOWN,//Vertical Speed Thumbwheel - Rotate Down								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_VS_UP,//Vertical Speed Thumbwheel - Rotate Up									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_VS_SET,//Vertical Speed Thumbwheel - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: -7900~6000. 50fpm increments if V/S is less than 1000 fpm, 100 fpm if V/S is 1000 fpm or greater
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOTHROTTLE_ARM,//Autothrottle (A/T) ARM Switch - Click						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOTHROTTLE_ARM_SET,//Autothrottle (A/T) ARM Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=OFF; 	1=ARM
	KEY_COMMAND_AUTOMATICFLIGHT_N1,//N1 Switch - Click															Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_SPEED,//SPEED Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_SPD_INTV,//Speed Intervention (SPD INTV) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_VNAV,//VNAV Switch - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_LVL_CHG,//Level Change (LVL CHG) Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_APP,//Approach (APP) Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_ALT_HLD,//Altitude Hold (ALT HLD) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_VS,//Vertical Speed (V/S) Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_ALT_INTV,//Altitude Intervention (ALT INTV) Switch - Click						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_LNAV,//LNAV Switch - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_VORLOC,//VOR Localizer (LOC) Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_HDG_SEL,//Heading Select (HDG SEL) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_CMD_A,//Command Engage (CMD A ENGAGE) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_CMD_B,//Command Engage (CMD B ENGAGE) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_CWS_A,//Control Wheel Steering Engage (CWS A ENGAGE) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_CWS_B,//Control Wheel Steering Engage (CWS B ENGAGE) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_LEFT_FD,//Captain Side Flight Director (F/D) Switch - Click						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_LEFT_FD_SET,//Captain Side Flight Director (F/D) Switch - Set					Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=OFF, 1=ON
	KEY_COMMAND_AUTOMATICFLIGHT_RIGHT_FD,//FO Side Flight Director (F/D) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_RIGHT_FD_SET,//FO Side Flight Director (F/D) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=OFF, 1=ON
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOPILOT_DISENGAGE_BAR,//Autopilot Disengage (DISENGAGE) Bar - Click			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOPILOT_DISENGAGE_BAR_SET,//Autopilot Disengage (DISENGAGE) Bar - Set			Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=switch Up; 1:switch Down
	KEY_COMMAND_AUTOMATICFLIGHT_TOGA_1,//Left Takeoff/Go-Around (TO/GA) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_TOGA_2,//Right Takeoff/Go-Around (TO/GA) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOPILOT_DISCONNECT_1,//Captain Side Autopilot Disengage Switch - Click		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOPILOT_DISCONNECT_2,//FO Side Autopilot Disengage Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOTHROTTLE_DISCONNECT_1,//Left Autothrottle Disengage Switch - Click			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOTHROTTLE_DISCONNECT_2,//Right Autothrottle Disengage Switch - Click			Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_AUTOMATICFLIGHT_LIGHT_STAB_OUT_TRIM,//Stabilizer Out Of Trim (STAB OUT OF TRIM) Light - Press	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_L_DISENGAGE_LIGHT_TEST_UP,//Captain Side Disengage Light Test (TEST) Switch - Move Up		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_L_DISENGAGE_LIGHT_TEST_DOWN,//Captain Side Disengage Light Test (TEST) Switch - Move Down	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_L_DISENGAGE_LIGHT_TEST_SET,//Captain Side Disengage Light Test (TEST) Switch - Set			Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch TEST1; 1:switch NEUTRAL; 2:switch TEST2
	KEY_COMMAND_AUTOMATICFLIGHT_R_DISENGAGE_LIGHT_TEST_UP,//FO Side Disengage Light Test (TEST) Switch - Move Up			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_R_DISENGAGE_LIGHT_TEST_DOWN,//FO Side Disengage Light Test (TEST) Switch - Move Down		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_R_DISENGAGE_LIGHT_TEST_SET,//FO Side Disengage Light Test (TEST) Switch - Set				Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch TEST1; 1:switch NEUTRAL; 2:switch TEST2
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOPILOT_DIS_L_LIGHT,//Captain Side Autopilot (A/P) Disengage Light - Press				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOPILOT_DIS_R_LIGHT,//FO Side Autopilot (A/P) Disengage Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOTHROTTLE_DIS_L_LIGHT,//Captain Side Autothrottle (A/T) Disengage Light - Press			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_AUTOMATICFLIGHT_AUTOTHROTTLE_DIS_R_LIGHT,//FO Side Autothrottle (A/T) Disengage Light - Press				Value1: 0: OFF the click sound; 1: ON the click sound


	//-------------------------------------------------------------
	//Communications
	//-------------------------------------------------------------
	KEY_COMMAND_COMMUNICATION_ATTENDANT_CALL,//Attendant Call (ATTEND) Switch - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_GROUND_CALL,//Ground Call (GRD CALL) Switch - Press								Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_COMMUNICATION_RTP_1_OFF,//RTP 1, Radio Tuning Panel OFF Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_VHF1,//RTP 1, Radio (VHF1) Tuning Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_VHF2,//RTP 1, Radio (VHF2) Tuning Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_VHF3,//RTP 1, Radio (VHF3) Tuning Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_HF1,//RTP 1, Radio (HF1) Tuning Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_AM,//RTP 1, AM Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_HF2,//RTP 1, Radio (HF2) Tuning Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_HF_SENS_DEC,//RTP 1, HF Sensitivity Control - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_HF_SENS_INC,//RTP 1, HF Sensitivity Control - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_TRANSFER,//RTP 1, Frequency Transfer Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_FRACT_DEC,//RTP 1, Frequency Selector (Inner) - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_FRACT_INC,//RTP 1, Frequency Selector (Inner) - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_WHOLE_DEC,//RTP 1, Frequency Selector (Outer) - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_WHOLE_INC,//RTP 1, Frequency Selector (Outer) - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_1_TEST,//RTP 1, VHF TEST Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_COMMUNICATION_RTP_2_OFF,//RTP 2, Radio Tuning Panel OFF Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_VHF1,//RTP 2, Radio (VHF1) Tuning Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_VHF2,//RTP 2, Radio (VHF2) Tuning Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_VHF3,//RTP 2, Radio (VHF3) Tuning Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_HF1,//RTP 2, Radio (HF1) Tuning Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_AM,//RTP 2, AM Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_HF2,//RTP 2, Radio (HF2) Tuning Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_HF_SENS_DEC,//RTP 2, HF Sensitivity Control - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_HF_SENS_INC,//RTP 2, HF Sensitivity Control - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_TRANSFER,//RTP 2, Frequency Transfer Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_FRACT_DEC,//RTP 2, Frequency Selector (Inner) - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_FRACT_INC,//RTP 2, Frequency Selector (Inner) - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_WHOLE_DEC,//RTP 2, Frequency Selector (Outer) - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_WHOLE_INC,//RTP 2, Frequency Selector (Outer) - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_2_TEST,//RTP 2, VHF TEST Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_COMMUNICATION_RTP_3_OFF,//RTP 3, Radio Tuning Panel OFF Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_VHF1,//RTP 3, Radio (VHF1) Tuning Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_VHF2,//RTP 3, Radio (VHF2) Tuning Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_VHF3,//RTP 3, Radio (VHF3) Tuning Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_HF1,//RTP 3, Radio (HF1) Tuning Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_AM,//RTP 3, AM Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_HF2,//RTP 3, Radio (HF2) Tuning Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_HF_SENS_DEC,//RTP 3, HF Sensitivity Control - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_HF_SENS_INC,//RTP 3, HF Sensitivity Control - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_TRANSFER,//RTP 3, Frequency Transfer Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_FRACT_DEC,//RTP 3, Frequency Selector (Inner) - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_FRACT_INC,//RTP 3, Frequency Selector (Inner) - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_WHOLE_DEC,//RTP 3, Frequency Selector (Outer) - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_WHOLE_INC,//RTP 3, Frequency Selector (Outer) - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_RTP_3_TEST,//RTP 3, VHF TEST Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_COMMUNICATION_ACP_1_ALT_NORM,//ACP 1, Alternate-Normal (ALT-NORM) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_ALT_NORM_SET,//ACP 1, Alternate-Normal (ALT-NORM) Switch - Set				Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=ALT; 1=NORM
	KEY_COMMAND_COMMUNICATION_ACP_1_PUSH_TO_TALK_DEC,//ACP 1, Push-to-Talk Switch - Move Up						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_PUSH_TO_TALK_INC,//ACP 1, Push-to-Talk Switch - Move Down					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_PUSH_TO_TALK_SET,//ACP 1, Push-to-Talk Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch RADIO; 1:switch Neutral; 2:switch INT
	KEY_COMMAND_COMMUNICATION_ACP_1_FILTER_DEC,//ACP 1, Filter Switch - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_FILTER_INC,//ACP 1, Filter Switch - Rotate Right							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_FILTER_SET,//ACP 1, Filter Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch V; 1:switch B; 2:switch R
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_VHF1,//ACP 1, Transmitter Selector (VHF1) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_VHF2,//ACP 1, Transmitter Selector (VHF2) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_VHF3,//ACP 1, Transmitter Selector (VHF3) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_HF1,//ACP 1, Transmitter Selector (HF1) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_HF2,//ACP 1, Transmitter Selector (HF2) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_INT,//ACP 1, Transmitter Selector (INT) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_CABIN,//ACP 1, Transmitter Selector (CABIN) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_PA,//ACP 1, Transmitter Selector (PA) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_SAT1,//ACP 1, Transmitter Selector (SAT1) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_MIC_SAT2,//ACP 1, Transmitter Selector (SAT2) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF1,//ACP 1, Receiver (VHF1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF1_SET,//ACP 1, Receiver (VHF1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF1_VOL_DEC,//ACP 1, Receiver (VHF1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF1_VOL_INC,//ACP 1, Receiver (VHF1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF1_VOL_SET,//ACP 1, Receiver (VHF1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF2,//ACP 1, Receiver (VHF2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF2_SET,//ACP 1, Receiver (VHF2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF2_VOL_DEC,//ACP 1, Receiver (VHF2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF2_VOL_INC,//ACP 1, Receiver (VHF2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF2_VOL_SET,//ACP 1, Receiver (VHF2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF3,//ACP 1, Receiver (VHF3) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF3_SET,//ACP 1, Receiver (VHF3) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF3_VOL_DEC,//ACP 1, Receiver (VHF3) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF3_VOL_INC,//ACP 1, Receiver (VHF3) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_VHF3_VOL_SET,//ACP 1, Receiver (VHF3) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF1,//ACP 1, Receiver (HF1) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF1_SET,//ACP 1, Receiver (HF1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF1_VOL_DEC,//ACP 1, Receiver (HF1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF1_VOL_INC,//ACP 1, Receiver (HF1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF1_VOL_SET,//ACP 1, Receiver (HF1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF2,//ACP 1, Receiver (HF2) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF2_SET,//ACP 1, Receiver (HF2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF2_VOL_DEC,//ACP 1, Receiver (HF2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF2_VOL_INC,//ACP 1, Receiver (HF2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_HF2_VOL_SET,//ACP 1, Receiver (HF2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_INT,//ACP 1, Receiver (INT) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_INT_SET,//ACP 1, Receiver (INT) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_INT_VOL_DEC,//ACP 1, Receiver (INT) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_INT_VOL_INC,//ACP 1, Receiver (INT) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_INT_VOL_SET,//ACP 1, Receiver (INT) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_CABIN,//ACP 1, Receiver (CABIN) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_CABIN_SET,//ACP 1, Receiver (CABIN) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_CABIN_VOL_DEC,//ACP 1, Receiver (CABIN) Switch - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_CABIN_VOL_INC,//ACP 1, Receiver (CABIN) Switch - Rotate Right			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_CABIN_VOL_SET,//ACP 1, Receiver (CABIN) Switch - Set					Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_PA,//ACP 1, Receiver (PA) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_PA_SET,//ACP 1, Receiver (PA) Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_PA_VOL_DEC,//ACP 1, Receiver (PA) Switch - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_PA_VOL_INC,//ACP 1, Receiver (PA) Switch - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_PA_VOL_SET,//ACP 1, Receiver (PA) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV1,//ACP 1, Receiver (NAV1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV1_SET,//ACP 1, Receiver (NAV1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV1_VOL_DEC,//ACP 1, Receiver (NAV1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV1_VOL_INC,//ACP 1, Receiver (NAV1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV1_VOL_SET,//ACP 1, Receiver (NAV1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV2,//ACP 1, Receiver (NAV2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV2_SET,//ACP 1, Receiver (NAV2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV2_VOL_DEC,//ACP 1, Receiver (NAV2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV2_VOL_INC,//ACP 1, Receiver (NAV2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_NAV2_VOL_SET,//ACP 1, Receiver (NAV2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF1,//ACP 1, Receiver (ADF1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF1_SET,//ACP 1, Receiver (ADF1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF1_VOL_DEC,//ACP 1, Receiver (ADF1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF1_VOL_INC,//ACP 1, Receiver (ADF1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF1_VOL_SET,//ACP 1, Receiver (ADF1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF2,//ACP 1, Receiver (ADF2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF2_SET,//ACP 1, Receiver (ADF2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF2_VOL_DEC,//ACP 1, Receiver (ADF2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF2_VOL_INC,//ACP 1, Receiver (ADF2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_ADF2_VOL_SET,//ACP 1, Receiver (ADF2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_MKR,//ACP 1, Receiver (MKR) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_MKR_SET,//ACP 1, Receiver (MKR) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_MKR_VOL_DEC,//ACP 1, Receiver (MKR) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_MKR_VOL_INC,//ACP 1, Receiver (MKR) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_MKR_VOL_SET,//ACP 1, Receiver (MKR) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT1,//ACP 1, Receiver (SAT1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT1_SET,//ACP 1, Receiver (SAT1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT1_VOL_DEC,//ACP 1, Receiver (SAT1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT1_VOL_INC,//ACP 1, Receiver (SAT1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT1_VOL_SET,//ACP 1, Receiver (SAT1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT2,//ACP 1, Receiver (SAT2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT2_SET,//ACP 1, Receiver (SAT2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT2_VOL_DEC,//ACP 1, Receiver (SAT2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT2_VOL_INC,//ACP 1, Receiver (SAT2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SAT2_VOL_SET,//ACP 1, Receiver (SAT2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SPKR,//ACP 1, Receiver (SPKR) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SPKR_SET,//ACP 1, Receiver (SPKR) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SPKR_VOL_DEC,//ACP 1, Receiver (SPKR) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SPKR_VOL_INC,//ACP 1, Receiver (SPKR) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_RVC_SPKR_VOL_SET,//ACP 1, Receiver (SPKR) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_1_SAT1,//ACP 1, SAT 1 Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_SAT2,//ACP 1, SAT 2 Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_1_SELCAL_VHF1,//Value1: unused												Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_1_SELCAL_VHF2,//Value1: unused												Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_1_SELCAL_VHF3,//Value1: unused												Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_1_SELCAL_HF1,//Value1: unused													Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_1_SELCAL_HF2,//Value1: unused													Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_1_SELCAL_INT,//Value1: unused													Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_1_SELCAL_CABIN,//Value1: unused												Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_1_SELCAL_SAT1,//Value1: unused												Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_1_SELCAL_SAT2,//Value1: unused												Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL

	KEY_COMMAND_COMMUNICATION_ACP_2_ALT_NORM,//ACP 2, Alternate-Normal (ALT-NORM) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_ALT_NORM_SET,//ACP 2, Alternate-Normal (ALT-NORM) Switch - Set				Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=ALT; 1=NORM
	KEY_COMMAND_COMMUNICATION_ACP_2_PUSH_TO_TALK_DEC,//ACP 2, Push-to-Talk Switch - Move Up						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_PUSH_TO_TALK_INC,//ACP 2, Push-to-Talk Switch - Move Down					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_PUSH_TO_TALK_SET,//ACP 2, Push-to-Talk Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch RADIO; 1:switch Neutral; 2:switch INT
	KEY_COMMAND_COMMUNICATION_ACP_2_FILTER_DEC,//ACP 2, Filter Switch - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_FILTER_INC,//ACP 2, Filter Switch - Rotate Right							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_FILTER_SET,//ACP 2, Filter Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch V; 1:switch B; 2:switch R
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_VHF1,//ACP 2, Transmitter Selector (VHF1) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_VHF2,//ACP 2, Transmitter Selector (VHF2) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_VHF3,//ACP 2, Transmitter Selector (VHF3) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_HF1,//ACP 2, Transmitter Selector (HF1) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_HF2,//ACP 2, Transmitter Selector (HF2) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_INT,//ACP 2, Transmitter Selector (INT) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_CABIN,//ACP 2, Transmitter Selector (CABIN) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_PA,//ACP 2, Transmitter Selector (PA) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_SAT1,//ACP 2, Transmitter Selector (SAT1) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_MIC_SAT2,//ACP 2, Transmitter Selector (SAT2) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF1,//ACP 2, Receiver (VHF1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF1_SET,//ACP 2, Receiver (VHF1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF1_VOL_DEC,//ACP 2, Receiver (VHF1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF1_VOL_INC,//ACP 2, Receiver (VHF1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF1_VOL_SET,//ACP 2, Receiver (VHF1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF2,//ACP 2, Receiver (VHF2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF2_SET,//ACP 2, Receiver (VHF2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF2_VOL_DEC,//ACP 2, Receiver (VHF2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF2_VOL_INC,//ACP 2, Receiver (VHF2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF2_VOL_SET,//ACP 2, Receiver (VHF2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF3,//ACP 2, Receiver (VHF3) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF3_SET,//ACP 2, Receiver (VHF3) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF3_VOL_DEC,//ACP 2, Receiver (VHF3) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF3_VOL_INC,//ACP 2, Receiver (VHF3) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_VHF3_VOL_SET,//ACP 2, Receiver (VHF3) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF1,//ACP 2, Receiver (HF1) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF1_SET,//ACP 2, Receiver (HF1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF1_VOL_DEC,//ACP 2, Receiver (HF1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF1_VOL_INC,//ACP 2, Receiver (HF1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF1_VOL_SET,//ACP 2, Receiver (HF1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF2,//ACP 2, Receiver (HF2) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF2_SET,//ACP 2, Receiver (HF2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF2_VOL_DEC,//ACP 2, Receiver (HF2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF2_VOL_INC,//ACP 2, Receiver (HF2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_HF2_VOL_SET,//ACP 2, Receiver (HF2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_INT,//ACP 2, Receiver (INT) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_INT_SET,//ACP 2, Receiver (INT) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_INT_VOL_DEC,//ACP 2, Receiver (INT) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_INT_VOL_INC,//ACP 2, Receiver (INT) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_INT_VOL_SET,//ACP 2, Receiver (INT) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_CABIN,//ACP 2, Receiver (CABIN) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_CABIN_SET,//ACP 2, Receiver (CABIN) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_CABIN_VOL_DEC,//ACP 2, Receiver (CABIN) Switch - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_CABIN_VOL_INC,//ACP 2, Receiver (CABIN) Switch - Rotate Right			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_CABIN_VOL_SET,//ACP 2, Receiver (CABIN) Switch - Set					Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_PA,//ACP 2, Receiver (PA) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_PA_SET,//ACP 2, Receiver (PA) Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_PA_VOL_DEC,//ACP 2, Receiver (PA) Switch - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_PA_VOL_INC,//ACP 2, Receiver (PA) Switch - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_PA_VOL_SET,//ACP 2, Receiver (PA) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV1,//ACP 2, Receiver (NAV1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV1_SET,//ACP 2, Receiver (NAV1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV1_VOL_DEC,//ACP 2, Receiver (NAV1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV1_VOL_INC,//ACP 2, Receiver (NAV1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV1_VOL_SET,//ACP 2, Receiver (NAV1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV2,//ACP 2, Receiver (NAV2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV2_SET,//ACP 2, Receiver (NAV2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV2_VOL_DEC,//ACP 2, Receiver (NAV2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV2_VOL_INC,//ACP 2, Receiver (NAV2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_NAV2_VOL_SET,//ACP 2, Receiver (NAV2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF1,//ACP 2, Receiver (ADF1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF1_SET,//ACP 2, Receiver (ADF1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF1_VOL_DEC,//ACP 2, Receiver (ADF1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF1_VOL_INC,//ACP 2, Receiver (ADF1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF1_VOL_SET,//ACP 2, Receiver (ADF1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF2,//ACP 2, Receiver (ADF2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF2_SET,//ACP 2, Receiver (ADF2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF2_VOL_DEC,//ACP 2, Receiver (ADF2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF2_VOL_INC,//ACP 2, Receiver (ADF2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_ADF2_VOL_SET,//ACP 2, Receiver (ADF2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_MKR,//ACP 2, Receiver (MKR) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_MKR_SET,//ACP 2, Receiver (MKR) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_MKR_VOL_DEC,//ACP 2, Receiver (MKR) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_MKR_VOL_INC,//ACP 2, Receiver (MKR) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_MKR_VOL_SET,//ACP 2, Receiver (MKR) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT1,//ACP 2, Receiver (SAT1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT1_SET,//ACP 2, Receiver (SAT1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT1_VOL_DEC,//ACP 2, Receiver (SAT1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT1_VOL_INC,//ACP 2, Receiver (SAT1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT1_VOL_SET,//ACP 2, Receiver (SAT1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT2,//ACP 2, Receiver (SAT2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT2_SET,//ACP 2, Receiver (SAT2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT2_VOL_DEC,//ACP 2, Receiver (SAT2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT2_VOL_INC,//ACP 2, Receiver (SAT2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SAT2_VOL_SET,//ACP 2, Receiver (SAT2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SPKR,//ACP 2, Receiver (SPKR) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SPKR_SET,//ACP 2, Receiver (SPKR) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SPKR_VOL_DEC,//ACP 2, Receiver (SPKR) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SPKR_VOL_INC,//ACP 2, Receiver (SPKR) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_RVC_SPKR_VOL_SET,//ACP 2, Receiver (SPKR) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_2_SAT1,//ACP 2, SAT 1 Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_SAT2,//ACP 2, SAT 2 Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_2_SELCAL_VHF1,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_2_SELCAL_VHF2,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_2_SELCAL_VHF3,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_2_SELCAL_HF1,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_2_SELCAL_HF2,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_2_SELCAL_INT,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_2_SELCAL_CABIN,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_2_SELCAL_SAT1,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_2_SELCAL_SAT2,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL

	KEY_COMMAND_COMMUNICATION_ACP_3_ALT_NORM,//ACP 3, Alternate-Normal (ALT-NORM) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_ALT_NORM_SET,//ACP 3, Alternate-Normal (ALT-NORM) Switch - Set				Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0=ALT; 1=NORM
	KEY_COMMAND_COMMUNICATION_ACP_3_PUSH_TO_TALK_DEC,//ACP 3, Push-to-Talk Switch - Move Up						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_PUSH_TO_TALK_INC,//ACP 3, Push-to-Talk Switch - Move Down					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_PUSH_TO_TALK_SET,//ACP 3, Push-to-Talk Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch RADIO; 1:switch Neutral; 2:switch INT
	KEY_COMMAND_COMMUNICATION_ACP_3_FILTER_DEC,//ACP 3, Filter Switch - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_FILTER_INC,//ACP 3, Filter Switch - Rotate Right							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_FILTER_SET,//ACP 3, Filter Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch V; 1:switch B; 2:switch R
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_VHF1,//ACP 3, Transmitter Selector (VHF1) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_VHF2,//ACP 3, Transmitter Selector (VHF2) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_VHF3,//ACP 3, Transmitter Selector (VHF3) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_HF1,//ACP 3, Transmitter Selector (HF1) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_HF2,//ACP 3, Transmitter Selector (HF2) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_INT,//ACP 3, Transmitter Selector (INT) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_CABIN,//ACP 3, Transmitter Selector (CABIN) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_PA,//ACP 3, Transmitter Selector (PA) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_SAT1,//ACP 3, Transmitter Selector (SAT1) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_MIC_SAT2,//ACP 3, Transmitter Selector (SAT2) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF1,//ACP 3, Receiver (VHF1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF1_SET,//ACP 3, Receiver (VHF1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF1_VOL_DEC,//ACP 3, Receiver (VHF1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF1_VOL_INC,//ACP 3, Receiver (VHF1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF1_VOL_SET,//ACP 3, Receiver (VHF1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF2,//ACP 3, Receiver (VHF2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF2_SET,//ACP 3, Receiver (VHF2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF2_VOL_DEC,//ACP 3, Receiver (VHF2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF2_VOL_INC,//ACP 3, Receiver (VHF2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF2_VOL_SET,//ACP 3, Receiver (VHF2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF3,//ACP 3, Receiver (VHF3) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF3_SET,//ACP 3, Receiver (VHF3) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF3_VOL_DEC,//ACP 3, Receiver (VHF3) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF3_VOL_INC,//ACP 3, Receiver (VHF3) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_VHF3_VOL_SET,//ACP 3, Receiver (VHF3) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF1,//ACP 3, Receiver (HF1) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF1_SET,//ACP 3, Receiver (HF1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF1_VOL_DEC,//ACP 3, Receiver (HF1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF1_VOL_INC,//ACP 3, Receiver (HF1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF1_VOL_SET,//ACP 3, Receiver (HF1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF2,//ACP 3, Receiver (HF2) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF2_SET,//ACP 3, Receiver (HF2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF2_VOL_DEC,//ACP 3, Receiver (HF2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF2_VOL_INC,//ACP 3, Receiver (HF2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_HF2_VOL_SET,//ACP 3, Receiver (HF2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_INT,//ACP 3, Receiver (INT) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_INT_SET,//ACP 3, Receiver (INT) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_INT_VOL_DEC,//ACP 3, Receiver (INT) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_INT_VOL_INC,//ACP 3, Receiver (INT) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_INT_VOL_SET,//ACP 3, Receiver (INT) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_CABIN,//ACP 3, Receiver (CABIN) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_CABIN_SET,//ACP 3, Receiver (CABIN) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_CABIN_VOL_DEC,//ACP 3, Receiver (CABIN) Switch - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_CABIN_VOL_INC,//ACP 3, Receiver (CABIN) Switch - Rotate Right			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_CABIN_VOL_SET,//ACP 3, Receiver (CABIN) Switch - Set					Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_PA,//ACP 3, Receiver (PA) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_PA_SET,//ACP 3, Receiver (PA) Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_PA_VOL_DEC,//ACP 3, Receiver (PA) Switch - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_PA_VOL_INC,//ACP 3, Receiver (PA) Switch - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_PA_VOL_SET,//ACP 3, Receiver (PA) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV1,//ACP 3, Receiver (NAV1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV1_SET,//ACP 3, Receiver (NAV1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV1_VOL_DEC,//ACP 3, Receiver (NAV1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV1_VOL_INC,//ACP 3, Receiver (NAV1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV1_VOL_SET,//ACP 3, Receiver (NAV1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV2,//ACP 3, Receiver (NAV2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV2_SET,//ACP 3, Receiver (NAV2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV2_VOL_DEC,//ACP 3, Receiver (NAV2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV2_VOL_INC,//ACP 3, Receiver (NAV2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_NAV2_VOL_SET,//ACP 3, Receiver (NAV2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF1,//ACP 3, Receiver (ADF1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF1_SET,//ACP 3, Receiver (ADF1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF1_VOL_DEC,//ACP 3, Receiver (ADF1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF1_VOL_INC,//ACP 3, Receiver (ADF1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF1_VOL_SET,//ACP 3, Receiver (ADF1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF2,//ACP 3, Receiver (ADF2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF2_SET,//ACP 3, Receiver (ADF2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF2_VOL_DEC,//ACP 3, Receiver (ADF2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF2_VOL_INC,//ACP 3, Receiver (ADF2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_ADF2_VOL_SET,//ACP 3, Receiver (ADF2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_MKR,//ACP 3, Receiver (MKR) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_MKR_SET,//ACP 3, Receiver (MKR) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_MKR_VOL_DEC,//ACP 3, Receiver (MKR) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_MKR_VOL_INC,//ACP 3, Receiver (MKR) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_MKR_VOL_SET,//ACP 3, Receiver (MKR) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT1,//ACP 3, Receiver (SAT1) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT1_SET,//ACP 3, Receiver (SAT1) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT1_VOL_DEC,//ACP 3, Receiver (SAT1) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT1_VOL_INC,//ACP 3, Receiver (SAT1) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT1_VOL_SET,//ACP 3, Receiver (SAT1) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT2,//ACP 3, Receiver (SAT2) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT2_SET,//ACP 3, Receiver (SAT2) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT2_VOL_DEC,//ACP 3, Receiver (SAT2) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT2_VOL_INC,//ACP 3, Receiver (SAT2) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SAT2_VOL_SET,//ACP 3, Receiver (SAT2) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SPKR,//ACP 3, Receiver (SPKR) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SPKR_SET,//ACP 3, Receiver (SPKR) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SPKR_VOL_DEC,//ACP 3, Receiver (SPKR) Switch - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SPKR_VOL_INC,//ACP 3, Receiver (SPKR) Switch - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_RVC_SPKR_VOL_SET,//ACP 3, Receiver (SPKR) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~6, from min to max
	KEY_COMMAND_COMMUNICATION_ACP_3_SAT1,//ACP 3, SAT 1 Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_SAT2,//ACP 3, SAT 2 Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_ACP_3_SELCAL_VHF1,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_3_SELCAL_VHF2,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_3_SELCAL_VHF3,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_3_SELCAL_HF1,//Value1: unused				Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_3_SELCAL_HF2,//Value1: unused				Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_3_SELCAL_INT,//Value1: unused				Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_3_SELCAL_CABIN,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_3_SELCAL_SAT1,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL
	KEY_COMMAND_COMMUNICATION_ACP_3_SELCAL_SAT2,//Value1: unused			Value2: 1£ºTrigger a SELCAL; 0£ºBypass all system logic and remove a SELCAL

	KEY_COMMAND_COMMUNICATION_CVR_TEST,//CVR TEST Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_CVR_ERASE,//CVR ERASE Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_COMMUNICATION_SERVICE_INTERPHONE,//SERVICE INTERPHONE Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_COMMUNICATION_SERVICE_INTERPHONE_SET,//SERVICE INTERPHONE Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0: switch OFF; 1: switch ON 


	//-------------------------------------------------------------
	//Electrical
	//-------------------------------------------------------------
	KEY_COMMAND_ELECTRICAL_IDG_1_DISCONNECT,//Left Generator Drive Disconnect (DISCONNECT) Switch - Click		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_IDG_1_DISCONNECT_SET,//Left Generator Drive Disconnect (DISCONNECT) Switch - Set		Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0: switch Connect; 1: switch Disconnect 			Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_ELECTRICAL_IDG_2_DISCONNECT,//Right Generator Drive Disconnect (DISCONNECT) Switch - Click		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_IDG_2_DISCONNECT_SET,//Right Generator Drive Disconnect (DISCONNECT) Switch - Set	Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0: switch Connect; 1: switch Disconnect 			Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_ELECTRICAL_GENERATOR_1_UP,//Generator (GEN) 1 Switch - Move Up									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_GENERATOR_1_DOWN,//Generator (GEN) 1 Switch - Move Down								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_GENERATOR_1_SET,//Generator (GEN) 1 Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch Neutral; 2:switch ON
	KEY_COMMAND_ELECTRICAL_GENERATOR_2_UP,//Generator (GEN) 2 Switch - Move Up									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_GENERATOR_2_DOWN,//Generator (GEN) 2 Switch - Move Down								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_GENERATOR_2_SET,//Generator (GEN) 2 Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch Neutral; 2:switch ON
	KEY_COMMAND_ELECTRICAL_APU_GENERATOR_1_UP,//APU Generator (GEN) 1 Switch - Move Up							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_APU_GENERATOR_1_DOWN,//APU Generator (GEN) 1 Switch - Move Down						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_APU_GENERATOR_1_SET,//APU Generator (GEN) 1 Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch Neutral; 2:switch ON
	KEY_COMMAND_ELECTRICAL_APU_GENERATOR_2_UP,//APU Generator (GEN) 2 Switch - Move Up							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_APU_GENERATOR_2_DOWN,//APU Generator (GEN) 2 Switch - Move Down						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_APU_GENERATOR_2_SET,//APU Generator (GEN) 2 Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch Neutral; 2:switch ON
	KEY_COMMAND_ELECTRICAL_GRD_PWR_UP,//Ground Power (GRD PWR) Switch - Move Up									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_GRD_PWR_DOWN,//Ground Power (GRD PWR) Switch - Move Down								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_GRD_PWR_SET,//Ground Power (GRD PWR) Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch Neutral; 2:switch ON
	KEY_COMMAND_ELECTRICAL_BAT,//Battery (BAT) Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_BAT_SET,//Battery (BAT) Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON							Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_ELECTRICAL_BUS_TRANSFER,//BUS TRANSFER Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_BUS_TRANSFER_SET,//BUS TRANSFER Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch AUTO							Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_ELECTRICAL_STANDBY_POWER_DEC,//STANDBY POWER Switch - Move Left									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_STANDBY_POWER_INC,//STANDBY POWER Switch - Move Right								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_STANDBY_POWER_SET,//STANDBY POWER Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch BAT; 1:switch OFF; 2:switch AUTO			Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_ELECTRICAL_CAB_UTIL,//CAB/UTIL Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_CAB_UTIL_SET,//CAB/UTIL Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_ELECTRICAL_IFE_PASS_SEAT,//IFE/PASS SEAT Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_IFE_PASS_SEAT_SET,//IFE/PASS SEAT Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_ELECTRICAL_DC_METER_DEC,//DC Meters Selector - Rotate Left										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_DC_METER_INC,//DC Meters Selector - Rotate Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_DC_METER_SET,//DC Meters Selector - Set												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch STBY PWR; 1:switch BAT BUS; 2:switch BAT; 3:switch AUX BAT; 4:switch TR1; 5:switch TR2; 6:switch TR3; 7:switch TEST
	KEY_COMMAND_ELECTRICAL_AC_METER_DEC,//AC Meters Selector - Rotate Left										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_AC_METER_INC,//AC Meters Selector - Rotate Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_AC_METER_SET,//AC Meters Selector - Set												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch STBY PWR; 1:switch GRD PWR; 2:switch GEN1; 3:switch APU GEN; 4:switch GEN2; 5:switch INV; 6:switch TEST
	KEY_COMMAND_ELECTRICAL_MAINT,//Maintenance Test (MAINT) Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_GRD_POWER_AVAILABLE,//Ground Power Available (GRD POWER AVAILABLE) Light - Press	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_DRIVE_1,//Left Generator Drive (DRIVE) Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_DRIVE_2,//Right Generator Drive (DRIVE) Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_STANDBY_PWR_OFF,//STANDBY Power Off (PWR OFF) Light - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_GEN_OFF_BUS_1,//Left Generator Off Bus (GEN OFF BUS) Light - Press				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_GEN_OFF_BUS_2,//Right Generator Off Bus (GEN OFF BUS) Light - Press			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_TRANSFER_BUS_OFF_1,//Left TRANSFER BUS OFF Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_TRANSFER_BUS_OFF_2,//Right TRANSFER BUS OFF Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_SOURCE_OFF_1,//Left SOURCE OFF Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_SOURCE_OFF_2,//Right SOURCE OFF Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_APU_GEN_OFF_BUS,//APU Generator Off Bus (GEN OFF BUS) Light - Press			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_BAT_DISCHARGE,//Battery Discharge (BAT DISCHARGE) Light - Press				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_TR_UNIT,//TR UNIT Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ELECTRICAL_LIGHT_ELEC,//Electrical (ELEC) Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound



	//-------------------------------------------------------------
	//Engines, APU
	//-------------------------------------------------------------
	KEY_COMMAND_ENGAPU_IGNITION_SELECT_DEC,//Ignition Select Switch - Move Left									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_IGNITION_SELECT_INC,//Ignition Select Switch - Move Right								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_IGNITION_SELECT_SET,//Ignition Select Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch 1; 1:switch BOTH; 2:switch 2
	KEY_COMMAND_ENGAPU_ENG_1_START_DEC,//Engine 1 START Switch - Rotate Left									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_ENG_1_START_INC,//Engine 1 START Switch - Rotate Right									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_ENG_1_START_SET,//Engine 1 START Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch GRD; 1:switch OFF; 2:switch CONT; 3:switch FLT
	KEY_COMMAND_ENGAPU_ENG_2_START_DEC,//Engine 2 START Switch - Rotate Left									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_ENG_2_START_INC,//Engine 2 START Switch - Rotate Right									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_ENG_2_START_SET,//Engine 2 START Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch GRD; 1:switch OFF; 2:switch CONT; 3:switch FLT
	KEY_COMMAND_ENGAPU_ENG_1_START_LEVER,//Engine 1 Start Lever - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_ENG_1_START_LEVER_SET,//Engine 1 Start Lever - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch IDLE; 1:switch CUTOFF
	KEY_COMMAND_ENGAPU_ENG_2_START_LEVER,//Engine 2 Start Lever - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_ENG_2_START_LEVER_SET,//Engine 2 Start Lever - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch IDLE; 1:switch CUTOFF
	KEY_COMMAND_ENGAPU_EEC_1,//Engine 1 Electronic Engine Control (EEC) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_EEC_1_SET,//Engine 1 Electronic Engine Control (EEC) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch ALTN; 1:switch ON
	KEY_COMMAND_ENGAPU_EEC_2,//Engine 2 Electronic Engine Control (EEC) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_EEC_2_SET,//Engine 2 Electronic Engine Control (EEC) Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch ALTN; 1:switch ON
	KEY_COMMAND_ENGAPU_LIGHT_ENGINE_CONTROL_1,//Engine 1 CONTROL Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_LIGHT_ENGINE_CONTROL_2,//Engine 2 CONTROL Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_LIGHT_REVERSER_LIMITED_1,//Engine 1 REVERSER LIMITED Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_LIGHT_REVERSER_LIMITED_2,//Engine 2 REVERSER LIMITED Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_LIGHT_REVERSER_COMMAND,//REVERSER COMMAND Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_LIGHT_REVERSER_AIRGND,//REVERSER AIR/GRD Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_APU_UP,//APU Switch - Move Up															Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_APU_DOWN,//APU Switch - Move Down														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_APU_SET,//APU Switch - Set																Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON; 2:switch START
	KEY_COMMAND_ENGAPU_FUEL_FLOW_DEC,//FUEL FLOW Switch - Move Up												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_FUEL_FLOW_INC,//FUEL FLOW Switch - Move Down												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_FUEL_FLOW_SET,//FUEL FLOW Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch RESET; 1:switch RATE; 2:switch USED
	KEY_COMMAND_ENGAPU_LIGHT_APU_DOOR,//APU Door (DOOR) Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_LIGHT_APU_LOW_OIL_PRESSURE,//APU LOW OIL PRESSURE Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_LIGHT_APU_FAULT,//APU FAULT Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_LIGHT_APU_OVER_SPEED,//APU OVERSPEED Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_ENGAPU_THROTTLE1_POS,//Value2:-16383~16383,from Full_Rev to Full_Power		Value3:ticks(0~64), 1 tick=1/18sec. set the time to inhibit AT throttle control
	KEY_COMMAND_ENGAPU_THROTTLE2_POS,//Value2:-16383~16383,from Full_Rev to Full_Power		Value3:ticks(0~64), 1 tick=1/18sec. set the time to inhibit AT throttle control


	//-------------------------------------------------------------
	//Fire Protection
	//-------------------------------------------------------------
	KEY_COMMAND_FIRE_LEFT_OVHT_DET_DEC,//Engine 1 Overheat Detector (OVHT DET) Switch - Move Left						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LEFT_OVHT_DET_INC,//Engine 1 Overheat Detector (OVHT DET) Switch - Move Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LEFT_OVHT_DET_SET,//Engine 1 Overheat Detector (OVHT DET) Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch A; 1:switch NORMAL; 2:switch B
	KEY_COMMAND_FIRE_RIGHT_OVHT_DET_DEC,//Engine 2 Overheat Detector (OVHT DET) Switch - Move Left						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_RIGHT_OVHT_DET_INC,//Engine 2 Overheat Detector (OVHT DET) Switch - Move Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_RIGHT_OVHT_DET_SET,//Engine 2 Overheat Detector (OVHT DET) Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch A; 1:switch NORMAL; 2:switch B
	KEY_COMMAND_FIRE_EXT_TEST_DEC,//Extinguisher (EXT) TEST Switchh - Move Left											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_EXT_TEST_INC,//Extinguisher (EXT) TEST Switchh - Move Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_EXT_TEST_SET,//Extinguisher (EXT) TEST Switchh - Set												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch 1; 1:switch Neutral; 2:switch 2
	KEY_COMMAND_FIRE_TEST_DEC,//Fault/Inoperative (FAULT/INOP) and Overheat/Fire (OVHT/FIRE) TEST Switch - Move Left	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_TEST_INC,//Fault/Inoperative (FAULT/INOP) and Overheat/Fire (OVHT/FIRE) TEST Switch - Move Right	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_TEST_SET,//Fault/Inoperative (FAULT/INOP) and Overheat/Fire (OVHT/FIRE) TEST Switch - Set			Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch FAULT/INOP; 1:switch Neutral; 2:switch OVHT/FIRE
	KEY_COMMAND_FIRE_APU_FIRE_SWITCH_PULL,//APU Fire Switch - Click														Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0: Fire switch not override; 1: Fire switch override
	KEY_COMMAND_FIRE_APU_FIRE_SWITCH_DEC,//APU Fire Switch - Rotate Left												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_APU_FIRE_SWITCH_INC,//APU Fire Switch - Rotate Right												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_APU_FIRE_SWITCH_SET,//APU Fire Switch - Set														Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0: Fire switch NORMAL; 1: Fire switch UP; 2: Fire switch rotate LEFT; 3: Fire switch rotate LEFT			Value3: 0: Fire switch not override; 1: Fire switch override
	KEY_COMMAND_FIRE_ENG_1_FIRE_SWITCH_PULL,//Engine 1 Fire Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0: Fire switch not override; 1: Fire switch override
	KEY_COMMAND_FIRE_ENG_1_FIRE_SWITCH_DEC,//Engine 1 Fire Switch - Rotate Left											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_ENG_1_FIRE_SWITCH_INC,//Engine 1 Fire Switch - Rotate Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_ENG_1_FIRE_SWITCH_SET,//Engine 1 Fire Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0: Fire switch NORMAL; 1: Fire switch UP; 2: Fire switch rotate LEFT; 3: Fire switch rotate LEFT			Value3: 0: Fire switch not override; 1: Fire switch override
	KEY_COMMAND_FIRE_ENG_2_FIRE_SWITCH_PULL,//Engine 2 Fire Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0: Fire switch not override; 1: Fire switch override
	KEY_COMMAND_FIRE_ENG_2_FIRE_SWITCH_DEC,//Engine 2 Fire Switch - Rotate Left											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_ENG_2_FIRE_SWITCH_INC,//Engine 2 Fire Switch - Rotate Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_ENG_2_FIRE_SWITCH_SET,//Engine 2 Fire Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0: Fire switch NORMAL; 1: Fire switch UP; 2: Fire switch rotate LEFT; 3: Fire switch rotate LEFT			Value3: 0: Fire switch not override; 1: Fire switch override
	KEY_COMMAND_FIRE_BELL_CUTOUT,//Fire Warning BELL CUTOUT Switch - Push												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_EXTINGUISHER_1_RESET,//Refill Engine 1 Extinguisher
	KEY_COMMAND_FIRE_EXTINGUISHER_2_RESET,//Refill Engine 2 Extinguisher
	KEY_COMMAND_FIRE_EXTINGUISHER_APU_RESET,//Refill APU Extinguisher
	KEY_COMMAND_FIRE_LIGHT_WHEEL_WELL,//WHEEL WELL Fire Warning Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_L_BOTTLE_DISCHARGE,//Engine L BOTTLE DISCHARGE Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_R_BOTTLE_DISCHARGE,//Engine R BOTTLE DISCHARGE Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_EXT_L,//Left Extinguisher Test (EXT TEST) Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_EXT_R,//Right Extinguisher Test (EXT TEST) Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_EXT_APU,//APU Extinguisher Test (EXT TEST) Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_APU_BOTTLE_DISCHARGE,//APU BOTTLE DISCHARGE Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_APU_DET_INOP,//APU Detector Inoperative (DET INOP) Light - Press								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_ENG1_OVERHEAT,//Engine 1 OVERHEAT Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_ENG2_OVERHEAT,//Engine 2 OVERHEAT Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_FAULT,//FAULT Light - Press																	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_LAVATORY_SMOKE,//LAVATORY SMOKE Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FIRE_FWD_DET_SELECT_DEC,//FWD Detector Select (DET SELECT) Switch - Rotate Left							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_FWD_DET_SELECT_INC,//FWD Detector Select (DET SELECT) Switch - Rotate Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_FWD_DET_SELECT_SET,//FWD Detector Select (DET SELECT) Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch A; 1:switch NORM; 2:switch B
	KEY_COMMAND_FIRE_AFT_DET_SELECT_DEC,//AFT Detector Select (DET SELECT) Switch - Rotate Left							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_AFT_DET_SELECT_INC,//AFT Detector Select (DET SELECT) Switch - Rotate Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_AFT_DET_SELECT_SET,//AFT Detector Select (DET SELECT) Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch A; 1:switch NORM; 2:switch B
	KEY_COMMAND_FIRE_CARGO_FIRE_TEST,//Cargo Fire TEST Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_FWD_CARGO_FIRE_ARM,//FWD Cargo Fire ARM Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_FWD_CARGO_FIRE_ARM_SET,//FWD Cargo Fire ARM Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_FIRE_AFT_CARGO_FIRE_ARM,//AFT Cargo Fire ARM Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_AFT_CARGO_FIRE_ARM_SET,//AFT Cargo Fire ARM Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_FIRE_CARGO_FIRE_DISCH,//Cargo Fire Discharge (DISCH) Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_CARGO_FIRE_DISCH_SET,//Cargo Fire Discharge (DISCH) Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON								Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_FIRE_CARGO_EXTINGUISHER_RESET,//Refill Cargo Extinguisher
	KEY_COMMAND_FIRE_LIGHT_CARGO_EXT_FWD,//FWD Extinguisher (EXT) Test Light - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_CARGO_EXT_AFT,//AFT Extinguisher (EXT) Test Light - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FIRE_LIGHT_DETECTOR_FAULT,//DETECTOR FAULT Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound


	//-------------------------------------------------------------
	//Flight Control
	//-------------------------------------------------------------
	KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_A_DEC,//FLIGHT CONTROL A Switch - Move Up										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_A_INC,//FLIGHT CONTROL A Switch - Move Down										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_A_SET,//FLIGHT CONTROL A Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch STBY RUD; 1:switch OFF; 2:switch ON			Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_B_DEC,//FLIGHT CONTROL B Switch - Move Up										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_B_INC,//FLIGHT CONTROL B Switch - Move Down										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_B_SET,//FLIGHT CONTROL B Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch STBY RUD; 1:switch OFF; 2:switch ON			Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_FLTCTRL_SPOILER_A_DEC,//Flight SPOILER A Switch - Move Up												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_SPOILER_A_INC,//Flight SPOILER A Switch - Move Down												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_SPOILER_A_SET,//Flight SPOILER A Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_FLTCTRL_SPOILER_B_DEC,//Flight SPOILER B Switch - Move Up												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_SPOILER_B_INC,//Flight SPOILER B Switch - Move Down												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_SPOILER_B_SET,//Flight SPOILER B Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_MASTER_DEC,//ALTERNATE FLAPS Master Switch - Move Up							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_MASTER_INC,//ALTERNATE FLAPS Master Switch - Move Down							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_MASTER_SET,//ALTERNATE FLAPS Master Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ARM								Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_DEC,//ALTERNATE FLAPS Position Switch - Move Up									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_INC,//ALTERNATE FLAPS Position Switch - Move Down								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_SET,//ALTERNATE FLAPS Position Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch UP; 1:switch OFF; 2:switch DOWN
	KEY_COMMAND_FLTCTRL_YAW_DAMPER,//YAW DAMPER Switch - Click															Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_YAW_DAMPER_SET,//YAW DAMPER Switch - Set														Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_FLTCTRL_LIGHT_YAW_DAMPER,//YAW DAMPER Light - Press														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_FLT_CTL_A_LOW_PRESSURE,//Flight Control A LOW PRESSURE Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_FLT_CTL_B_LOW_PRESSURE,//Flight Control B LOW PRESSURE Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_SPOILERS,//SPOILERS Light - Press															Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_STBY_HYD_LOW_QUANTITY,//STANDBY HYDRAULIC LOW QUANTITY Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_STBY_HYD_LOW_PRESSURE,//STANDBY HYDRAULIC LOW PRESSURE Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_STBY_RUD_ON,//STBY RUD ON Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_AUTO_SLAT_FAIL,//Automatic Slat Failure (AUTO SLAT FAIL) Light - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_MACH_TRIM_FAIL,//Mach Trim Failure (MACH TRIM FAIL) Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_SPEED_TRIM_FAIL,//Speed Trim Failure (SPEED TRIM FAIL) Light - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_FEEL_DIFF_PRESS,//Feel Differential Pressure (FEEL DIFF PRESS) Light - Press				Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FLTCTRL_STAB_TRIM_PRI,//Stabilizer Trim PRI (primary) Cutout Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_STAB_TRIM_PRI_SET,//Stabilizer Trim PRI (primary) Cutout Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch NORMAL; 1:switch CUTOF
	KEY_COMMAND_FLTCTRL_STAB_TRIM_BU,//Stabilizer Trim B/U (backup) Cutout Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_STAB_TRIM_BU_SET,//Stabilizer Trim B/U (backup) Cutout Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch NORMAL; 1:switch CUTOF

	KEY_COMMAND_FLTCTRL_STAB_TRIM_OVERRIDE,//Stabilizer Trim Override Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_STAB_TRIM_OVERRIDE_SET,//Stabilizer Trim Override Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OVRD; 1:switch NORM							Value3: 1: ignore the guard, press the button directly
	KEY_COMMAND_FLTCTRL_STAB_TRIM_WHEEL_DN,//Stabilizer Trim Wheel - Airplane Nose Down
	KEY_COMMAND_FLTCTRL_STAB_TRIM_WHEEL_UP,//Stabilizer Trim Wheel - Airplane Nose Up
	KEY_COMMAND_FLTCTRL_CAPT_STAB_TRIM_SWITCH_DN,//Captain Side Stabilizer Trim Switch - Airplane Nose Down				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_CAPT_STAB_TRIM_SWITCH_UP,//Captain Side Stabilizer Trim Switch - Airplane Nose Up				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_FO_STAB_TRIM_SWITCH_DN,//FO Side Stabilizer Trim Switch - Airplane Nose Down					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_FO_STAB_TRIM_SWITCH_UP,//FO Side Stabilizer Trim Switch - Airplane Nose Up						Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FLTCTRL_LE_TEST,//Leading Edge Annunciator Panel TEST Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FLTCTRL_FLAP_DEC,//FLAP Lever - Move Up																	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_FLAP_INC,//FLAP Lever - Move Down																Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_FLAP_SET,//FLAP Lever - Set																		Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~8: FlapUp~Fla40
	KEY_COMMAND_FLTCTRL_SPOILER,//SPD BRK Lever - Set																	Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0~254: Spoiler lever position,		0: DOWN; 34: ARMED; 180: FLIGHT DETEND; 254: UP
	KEY_COMMAND_FLTCTRL_LIGHT_SPEED_BRAKE_DO_NOT_ARM,//SPEED BRAKE DO NOT ARM Light - Press								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_SPEED_BRAKE_ARMED,//SPEED BRAKE ARMED Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_LIGHT_SPEEDBRAKES_EXTENDED,//SPEEDBRAKES EXTENDED Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FLTCTRL_ELEV_JAM_LANDING_ASSIST,//Elevator Jam Landing Assist Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_ELEV_JAM_LANDING_ASSIST_SET,//Elevator Jam Landing Assist Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound			Value2: 0:switch OFF; 1:switch ON
	KEY_COMMAND_FLTCTRL_LIGHT_ASSIST_ON,//ASSIST ON Light - Press														Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FLTCTRL_RUDDER_TRIM_DEC,//Rudder Trim Control - Rotate Left												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_RUDDER_TRIM_INC,//Rudder Trim Control - Rotate Right											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_AILERON_TRIM_DEC,//AILERON Trim Switches - Rotate Left											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FLTCTRL_AILERON_TRIM_INC,//AILERON Trim Switches - Rotate Right											Value1: 0: OFF the click sound; 1: ON the click sound


	//-------------------------------------------------------------
	//Flight Instruments, Displays
	//-------------------------------------------------------------
	KEY_COMMAND_INSTRUMENT_EFIS_L_LEFT_VORADF_DEC,//Captain Side EFIS, Left VOR/ADF Switch - Move Up					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_LEFT_VORADF_INC,//Captain Side EFIS, Left VOR/ADF Switch - Move Down					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_LEFT_VORADF_SET,//Captain Side EFIS, Left VOR/ADF Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0=VOR; 1=OFF; 2=ADF; 
	KEY_COMMAND_INSTRUMENT_EFIS_L_RIGHT_VORADF_DEC,//Captain Side EFIS, Right VOR/ADF Switch - Move Up					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_RIGHT_VORADF_INC,//Captain Side EFIS, Right VOR/ADF Switch - Move Down				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_RIGHT_VORADF_SET,//Captain Side EFIS, Right VOR/ADF Switch - Set						Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0=VOR; 1=OFF; 2=ADF; 
	KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_REF_RADIO,//Captain Side EFIS, Minimums (MINS) Reference Selector (Outer) - Select RADIO		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_REF_BARO,//Captain Side EFIS, Minimums (MINS) Reference Selector (Outer) - Select BARO		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_DEC,//Captain Side EFIS, Minimums (MINS) Selector (Middle) - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0=Auto; 1=Selector rotate in slow mode; 2=Selector rotate in fast mode
	KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_INC,//Captain Side EFIS, Minimums (MINS) Selector (Middle) - Rotate Right		Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0=Auto; 1=Selector rotate in slow mode; 2=Selector rotate in fast mode
	KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_SET,//Captain Side EFIS, Minimums (MINS) Selector (Middle) - Set					Value1: 0: OFF the click sound; 1: ON the click sound						Value2:altitude
	KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_RST,//Captain Side EFIS, Radio Minimums (MINS) Reset (RST) Switch (Inner) - Click	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_MTRS,//Captain Side EFIS, Meters (MTRS) Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_FPV,//Captain Side EFIS, Flight Path Vector (FPV) Switch - Click						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_REF_HPA,//Captain Side EFIS, Barometric (BARO) Reference Selector (Iuter) - Select HPA		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_REF_IN,//Captain Side EFIS, Barometric (BARO) Reference Selector (Iuter) - Select IN			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_DEC,//Captain Side EFIS, Barometric (BARO) Selector (Mmiddle) - Rotate Left		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_INC,//Captain Side EFIS, Barometric (BARO) Selector (Mmiddle) - Rotate Right		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_STD,//Captain Side EFIS, Barometric (BARO) Standard (STD) Switch (Inner) - Click	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_CTR,//Captain Side EFIS, Center (CTR) Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_MODE_DEC,//Captain Side EFIS, Mode Selector (Outer) - Rotate Left						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_MODE_INC,//Captain Side EFIS, Mode Selector (Outer) - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_MODE_SET,//Captain Side EFIS, Mode Selector (Outer) - Set								Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch APP; 1:switch VOR; 2:switch MAP; 3:switch PLN
	KEY_COMMAND_INSTRUMENT_EFIS_L_TFC,//Captain Side EFIS, Traffic (TFC) Switch (Inner) - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_RANGE_DEC,//Captain Side EFIS, Range Selector (Outer) - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_RANGE_INC,//Captain Side EFIS, Range Selector (Outer) - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_RANGE_SET,//Captain Side EFIS, Range Selector (Outer) - Set							Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:.5nm; 1:1nm; 2:2nm; 3:5nm; 4:10nm; 5:20nm; 6:40nm; 7:80nm; 8:160nm; 9:320nm; 10:640nm
	KEY_COMMAND_INSTRUMENT_EFIS_L_WXR,//Captain Side EFIS, MAP Switch (WXR) - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_STA,//Captain Side EFIS, MAP Switch (STA) - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_WPT,//Captain Side EFIS, MAP Switch (WPT) - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_ARPT,//Captain Side EFIS, MAP Switch (ARPT) - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_DATA,//Captain Side EFIS, MAP Switch (DATA) - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_POS,//Captain Side EFIS, MAP Switch (POS) - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_TERR,//Captain Side EFIS, MAP Switch (TERR) - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_L_VSD,//Captain Side EFIS, MAP Switch (VSD) - Click										Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_INSTRUMENT_EFIS_R_LEFT_VORADF_DEC,//FO Side EFIS, Left VOR/ADF Switch - Move Up							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_LEFT_VORADF_INC,//FO Side EFIS, Left VOR/ADF Switch - Move Down						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_LEFT_VORADF_SET,//FO Side EFIS, Left VOR/ADF Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0=VOR; 1=OFF; 2=ADF; 
	KEY_COMMAND_INSTRUMENT_EFIS_R_RIGHT_VORADF_DEC,//FO Side EFIS, Right VOR/ADF Switch - Move Up						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_RIGHT_VORADF_INC,//FO Side EFIS, Right VOR/ADF Switch - Move Down						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_RIGHT_VORADF_SET,//FO Side EFIS, Right VOR/ADF Switch - Set							Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0=VOR; 1=OFF; 2=ADF; 
	KEY_COMMAND_INSTRUMENT_EFIS_R_MINS_REF_RADIO,//FO Side EFIS, Minimums (MINS) Reference Selector (Outer) - Select RADIO		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_MINS_REF_BARO,//FO Side EFIS, Minimums (MINS) Reference Selector (Outer) - Select BARO		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_MINS_DEC,//FO Side EFIS, Minimums (MINS) Selector (Middle) - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0=Auto; 1=Selector rotate in slow mode; 2=Selector rotate in fast mode
	KEY_COMMAND_INSTRUMENT_EFIS_R_MINS_INC,//FO Side EFIS, Minimums (MINS) Selector (Middle) - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0=Auto; 1=Selector rotate in slow mode; 2=Selector rotate in fast mode
	KEY_COMMAND_INSTRUMENT_EFIS_R_MINS_SET,//FO Side EFIS, Minimums (MINS) Selector (Middle) - Set						Value1: 0: OFF the click sound; 1: ON the click sound						Value2:altitude
	KEY_COMMAND_INSTRUMENT_EFIS_R_MINS_RST,//FO Side EFIS, Radio Minimums (MINS) Reset (RST) Switch (Inner) - Click	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_MTRS,//FO Side EFIS, Meters (MTRS) Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_FPV,//FO Side EFIS, Flight Path Vector (FPV) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_BARO_REF_HPA,//FO Side EFIS, Barometric (BARO) Reference Selector (Iuter) - Select HPA		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_BARO_REF_IN,//FO Side EFIS, Barometric (BARO) Reference Selector (Iuter) - Select IN			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_BARO_DEC,//FO Side EFIS, Barometric (BARO) Selector (Mmiddle) - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_BARO_INC,//FO Side EFIS, Barometric (BARO) Selector (Mmiddle) - Rotate Right			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_BARO_STD,//FO Side EFIS, Barometric (BARO) Standard (STD) Switch (Inner) - Click		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_CTR,//FO Side EFIS, Center (CTR) Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_MODE_DEC,//FO Side EFIS, Mode Selector (Outer) - Rotate Left							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_MODE_INC,//FO Side EFIS, Mode Selector (Outer) - Rotate Right							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_MODE_SET,//FO Side EFIS, Mode Selector (Outer) - Set									Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch APP; 1:switch VOR; 2:switch MAP; 3:switch PLN
	KEY_COMMAND_INSTRUMENT_EFIS_R_TFC,//FO Side EFIS, Traffic (TFC) Switch (Inner) - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_RANGE_DEC,//FO Side EFIS, Range Selector (Outer) - Rotate Left						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_RANGE_INC,//FO Side EFIS, Range Selector (Outer) - Rotate Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_RANGE_SET,//FO Side EFIS, Range Selector (Outer) - Set								Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:.5nm; 1:1nm; 2:2nm; 3:5nm; 4:10nm; 5:20nm; 6:40nm; 7:80nm; 8:160nm; 9:320nm; 10:640nm
	KEY_COMMAND_INSTRUMENT_EFIS_R_WXR,//FO Side EFIS, MAP Switch (WXR) - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_STA,//FO Side EFIS, MAP Switch (STA) - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_WPT,//FO Side EFIS, MAP Switch (WPT) - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_ARPT,//FO Side EFIS, MAP Switch (ARPT) - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_DATA,//FO Side EFIS, MAP Switch (DATA) - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_POS,//FO Side EFIS, MAP Switch (POS) - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_TERR,//FO Side EFIS, MAP Switch (TERR) - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_EFIS_R_VSD,//FO Side EFIS, MAP Switch (VSD) - Click											Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_INSTRUMENT_DISPLAYS_SOURCE_DEC,//Displays Source Switch - Rotate Left									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_DISPLAYS_SOURCE_INC,//Displays Source Switch - Rotate Right									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_DISPLAYS_SOURCE_SET,//Displays Source Switch - Set											Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch ALL ON 1; 1:switch AUTO; 2:switch ALL ON 2
	KEY_COMMAND_INSTRUMENT_CONTROL_PANEL_DEC,//Displays Control Panel Switch - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CONTROL_PANEL_INC,//Displays Control Panel Switch - Rotate Right								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CONTROL_PANEL_SET,//Displays Control Panel Switch - Set										Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch BOTH ON 1; 1:switch NORMAL; 2:switch BOTH ON 2

	KEY_COMMAND_INSTRUMENT_CAPT_DISP_SEL_DEC,//Captain Side Display Selector Switch - Rotate Left						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_DISP_SEL_INC,//Captain Side Display Selector Switch - Rotate Right						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_DISP_SEL_SET,//Captain Side Display Selector Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound						Value2: 0: switch OUTBD; 1: switch NORMAL; 2: switch INBD
	KEY_COMMAND_INSTRUMENT_CAPT_OUTBD_DU_BRIGHTNESS_DEC,//Captain Side Outboard Display Brightness Control (Outer) - Rotate Left		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_OUTBD_DU_BRIGHTNESS_INC,//Captain Side Outboard Display Brightness Control (Outer) - Rotate Right		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_OUTBD_DU_BRIGHTNESS_SET,//Captain Side Outboard Display Brightness Control (Outer) - Set				Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_INSTRUMENT_CAPT_OUTBD_DU_RADAR_BRIGHTNESS_DEC,//Captain Side Outboard Display Brightness Control (Inner) - Rotate Left	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_OUTBD_DU_RADAR_BRIGHTNESS_INC,//Captain Side Outboard Display Brightness Control (Inner) - Rotate Right	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_OUTBD_DU_RADAR_BRIGHTNESS_SET,//Captain Side Outboard Display Brightness Control (Inner) - Set			Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_INSTRUMENT_CAPT_INBD_DU_BRIGHTNESS_DEC,//Captain Side Inboard Display Brightness Control (Outer) - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_INBD_DU_BRIGHTNESS_INC,//Captain Side Inboard Display Brightness Control (Outer) - Rotate Right			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_INBD_DU_BRIGHTNESS_SET,//Captain Side Inboard Display Brightness Control (Outer) - Set					Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_INSTRUMENT_CAPT_INBD_DU_RADAR_BRIGHTNESS_DEC,//Captain Side Inboard Display Brightness Control (Inner) - Rotate Left	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_INBD_DU_RADAR_BRIGHTNESS_INC,//Captain Side Inboard Display Brightness Control (Inner) - Rotate Right	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_INBD_DU_RADAR_BRIGHTNESS_SET,//Captain Side Inboard Display Brightness Control (Inner) - Set			Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_INSTRUMENT_MIP_BACKGROUND_LIGHT_BRIGHTNESS_DEC,//Captain Side BACKGROUND Light Control - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_MIP_BACKGROUND_LIGHT_BRIGHTNESS_INC,//Captain Side BACKGROUND Light Control - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_MIP_BACKGROUND_LIGHT_BRIGHTNESS_SET,//Captain Side BACKGROUND Light Control - Set							Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_INSTRUMENT_AFDS_FLOOD_LIGHT_BRIGHTNESS_DEC,//AFDS FLOOD Light Control - Rotate Left										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_AFDS_FLOOD_LIGHT_BRIGHTNESS_INC,//AFDS FLOOD Light Control - Rotate Right									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_AFDS_FLOOD_LIGHT_BRIGHTNESS_SET,//AFDS FLOOD Light Control - Set												Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_INSTRUMENT_FO_DISP_SEL_DEC,//FO Side Display Selector Switch - Rotate Left												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_DISP_SEL_INC,//FO Side Display Selector Switch - Rotate Right												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_DISP_SEL_SET,//FO Side Display Selector Switch - Set														Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0: switch OUTBD; 1: switch NORMAL; 2: switch INBD
	KEY_COMMAND_INSTRUMENT_FO_OUTBD_DU_BRIGHTNESS_DEC,//FO Side Outboard Display Brightness Control (Outer) - Rotate Left				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_OUTBD_DU_BRIGHTNESS_INC,//FO Side Outboard Display Brightness Control (Outer) - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_OUTBD_DU_BRIGHTNESS_SET,//FO Side Outboard Display Brightness Control (Outer) - Set						Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_INSTRUMENT_FO_OUTBD_DU_RADAR_BRIGHTNESS_DEC,//FO Side Outboard Display Brightness Control (Inner) - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_OUTBD_DU_RADAR_BRIGHTNESS_INC,//FO Side Outboard Display Brightness Control (Inner) - Rotate Right		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_OUTBD_DU_RADAR_BRIGHTNESS_SET,//FO Side Outboard Display Brightness Control (Inner) - Set					Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_INSTRUMENT_FO_INBD_DU_BRIGHTNESS_DEC,//FO Side Inboard Display Brightness Control (Outer) - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_INBD_DU_BRIGHTNESS_INC,//FO Side Inboard Display Brightness Control (Outer) - Rotate Right				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_INBD_DU_BRIGHTNESS_SET,//FO Side Inboard Display Brightness Control (Outer) - Set							Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT
	KEY_COMMAND_INSTRUMENT_FO_INBD_DU_RADAR_BRIGHTNESS_DEC,//FO Side Inboard Display Brightness Control (Inner) - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_INBD_DU_RADAR_BRIGHTNESS_INC,//FO Side Inboard Display Brightness Control (Inner) - Rotate Right			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_INBD_DU_RADAR_BRIGHTNESS_SET,//FO Side Inboard Display Brightness Control (Inner) - Set					Value1: 0: OFF the click sound; 1: ON the click sound		Value2: 0~20, from DIM to BRIGHT

	KEY_COMMAND_INSTRUMENT_CAPT_SELECTOR_OUTER_L,//Captain Side Interactive Display Selector (Outer) - Select L			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_SELECTOR_OUTER_C,//Captain Side Interactive Display Selector (Outer) - Select C			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_SELECTOR_INNER_DEC,//Captain Side Interactive Display Selector (Inner) - Rotate Left	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_SELECTOR_INNER_INC,//Captain Side Interactive Display Selector (Inner) - Rotate Right	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_CAPT_SELECTOR_SEL,//Captain Side Interactive Display Select (SEL) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_SELECTOR_OUTER_C,//FO Side Interactive Display Selector (Outer) - Select C				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_SELECTOR_OUTER_R,//FO Side Interactive Display Selector (Outer) - Select R				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_SELECTOR_INNER_DEC,//FO Side Interactive Display Selector (Inner) - Rotate Left			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_SELECTOR_INNER_INC,//FO Side Interactive Display Selector (Inner) - Rotate Right			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_SELECTOR_SEL,//FO Side Interactive Display Select (SEL) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_ENG_TFR,//Engine Transfer (ENG TFR) Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_MFD_ENG,//MFD Engine (ENG) Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_MFD_SYS,//MFD System (SYS) Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_MFD_INFO,//MFD Information (INFO) Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_MFD_CR,//MFD Cancel/Recall (C/R) Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_INSTRUMENT_FLIGHT_RECORD_MODE,//Flight Recorder Test Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FLIGHT_RECORD_MODE_SET,//Flight Recorder Test Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch NORMAL; 1:switch TEST			Value3: 1: ignore the guard, press the button directly

	KEY_COMMAND_INSTRUMENT_ISFD_APP,//ISFD, Approach (APP) Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_ISFD_HPIN,//ISFD, Hectopascal/Inch (HP/IN) Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_ISFD_RST,//ISFD, Attitude Reset (RST) Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_ISFD_BRT_DEC,//ISFD, Display Brightness (-) Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_ISFD_BRT_INC,//ISFD, Display Brightness (+) Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_ISFD_BARO_DEC,//ISFD, Barometric (BARO) Selector - Rotate Left								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_ISFD_BARO_INC,//ISFD, Barometric (BARO) Selector - Rotate Right								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_ISFD_BARO_STD,//ISFD, Barometric (BARO) Selector - Click										Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_INSTRUMENT_CAPT_CLOCK_SWITCH,//Captain Side Clock Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_INSTRUMENT_FO_CLOCK_SWITCH,//FO Side Clock Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound


	//-------------------------------------------------------------
	//Flight Management, Navigation
	//-------------------------------------------------------------
	KEY_COMMAND_FMS_VHF_NAV_DEC,//VHF NAV Transfer Switch - Move Left													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_VHF_NAV_INC,///VHF NAV Transfer Switch - Move Right													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_VHF_NAV_SET,///VHF NAV Transfer Switch - Click														Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch BOTH ON 1; 1:switch NORMAL; 2:switch BOTH ON 2
	KEY_COMMAND_FMS_IRS_TFR_DEC,//IRS Transfer Switch - Move Left														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_TFR_INC,//IRS Transfer Switch - Move Right														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_TFR_SET,//IRS Transfer Switch - Click															Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch BOTH ON L; 1:switch NORMAL; 2:switch BOTH ON R
	KEY_COMMAND_FMS_FMC_SOURCE_SELECT_DEC,//FMC Source Select Switch - Move Left										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_FMC_SOURCE_SELECT_INC,//FMC Source Select Switch - Move Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_FMC_SOURCE_SELECT_SET,//FMC Source Select Switch - Click											Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch BOTH ON L; 1:switch NORMAL; 2:switch BOTH ON R

	KEY_COMMAND_FMS_IRS_DSPL_BRT_DEC,//Brightness (BRT) Control - Rotate Left											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_DSPL_BRT_INC,//Brightness (BRT) Control - Rotate Right											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_DSPL_SEL_DEC,//Display Selector (DSPL SEL) - Move Left											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_DSPL_SEL_INC,//Display Selector (DSPL SEL) - Move Right											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_DSPL_SEL_SET,//Display Selector (DSPL SEL) - Click												Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch TEST; 1:switch TK/GS; 2:switch PPOS; 3:switch WIND; 4:switch HDG/STS
	KEY_COMMAND_FMS_IRS_SYS_DSPL,//System Display (SYS DSPL) Selector - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_SYS_DSPL_SET,//System Display (SYS DSPL) Selector - Set											Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch L; 1:switch R
	KEY_COMMAND_FMS_IRS_L_MODE_DEC,//Left Inertial Reference System (IRS) Mode Selector - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_L_MODE_INC,//Left Inertial Reference System (IRS) Mode Selector - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_L_MODE_SET,//Left Inertial Reference System (IRS) Mode Selector - Set							Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ALIGN; 2:switch NAV; 3:switch ATT
	KEY_COMMAND_FMS_IRS_R_MODE_DEC,//Right Inertial Reference System (IRS) Mode Selector - Rotate Left					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_R_MODE_INC,//Right Inertial Reference System (IRS) Mode Selector - Rotate Right					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_R_MODE_SET,//Right Inertial Reference System (IRS) Mode Selector - Set							Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ALIGN; 2:switch NAV; 3:switch ATT
	KEY_COMMAND_FMS_IRS_KEY_1,//ISDU Keyboard - 1																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_2,//ISDU Keyboard - 2																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_3,//ISDU Keyboard - 3																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_4,//ISDU Keyboard - 4																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_5,//ISDU Keyboard - 5																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_6,//ISDU Keyboard - 6																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_7,//ISDU Keyboard - 7																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_8,//ISDU Keyboard - 8																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_9,//ISDU Keyboard - 9																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_ENT,//ISDU Keyboard - ENT																	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_0,//ISDU Keyboard - 0																		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_KEY_CLR,//ISDU Keyboard - CLR																	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_L_LIGHT_ALIGN,//Left IRS ALIGN Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_L_LIGHT_ON_DC,//Left IRS ON DC Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_L_LIGHT_FAULT,//Left IRS FAULT Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_L_LIGHT_DC_FAIL,//Left IRS DC FAIL Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_R_LIGHT_ALIGN,//Right IRS ALIGN Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_R_LIGHT_ON_DC,//Right IRS ON DC Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_R_LIGHT_FAULT,//Right IRS FAULT Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_IRS_R_LIGHT_DC_FAIL,//Right IRS DC FAIL Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_LIGHT_GPS,//Global Positioning System (GPS) Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_LIGHT_ILS,//Instrument Landing System (ILS) Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_LIGHT_GLS,//GNSS Landing System (GLS) Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FMS_FMC_ALERT_L_LIGHT,//Captain Side FMC Alert Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_FMC_ALERT_R_LIGHT,//FO Side FMC Alert Light - Press													Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FMS_ADF_TONE_DEC,//ADF, TONE Switch - Rotate Left														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_TONE_INC,//ADF, TONE Switch - Rotate Right														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_TONE_SET,//ADF, TONE Switch - Set																Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch 1; 1:switch OFF; 2:switch 2
	KEY_COMMAND_FMS_ADF_L_MODE_DEC,//ADF, Left Mode Selector Switch - Rotate Left										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_MODE_INC,//ADF, Left Mode Selector Switch - Rotate Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_MODE_SET,//ADF, Left Mode Selector Switch - Set												Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch ADF; 1:switch ANT; 2:switch OFF
	KEY_COMMAND_FMS_ADF_L_TEST,//ADF, Left Mode Selector Switch (TEST) - Click											Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:ADF1; 1:ADF2
	KEY_COMMAND_FMS_ADF_R_MODE_DEC,//ADF, Right Mode Selector Switch - Rotate Left										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_MODE_INC,//ADF, Right Mode Selector Switch - Rotate Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_MODE_SET,//ADF, Right Mode Selector Switch - Set												Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch ADF; 1:switch ANT; 2:switch OFF
	KEY_COMMAND_FMS_ADF_R_TEST,//ADF, Right Mode Selector Switch (TEST) - Click											Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:ADF1; 1:ADF2
	KEY_COMMAND_FMS_ADF_L_100_DEC,//ADF, Left ADF Frequency Selector - The hundreds number -1							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_100_INC,//ADF, Left ADF Frequency Selector - The hundreds number +1							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_10_DEC,//ADF, Left ADF Frequency Selector - The tens number -1								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_10_INC,//ADF, Left ADF Frequency Selector - The tens number +1								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_1_DEC,//ADF, Left ADF Frequency Selector - The ones number -1									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_1_INC,//ADF, Left ADF Frequency Selector - The ones number +1									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_FRAC_DEC,//ADF, Left ADF Frequency Selector - The tenths number -1							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_FRAC_INC,//ADF, Left ADF Frequency Selector - The tenths number +1							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_OUTER_DEC,//ADF, Left ADF Frequency Selector (Outer) - Set the hundreds number -1				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_OUTER_INC,//ADF, Left ADF Frequency Selector (Outer) - Set the hundreds number +1				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_MIDDLE_DEC,//ADF, Left ADF Frequency Selector (Middle) - Set the tens number -1				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_MIDDLE_INC,//ADF, Left ADF Frequency Selector (Middle) - Set the tens number +1				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_INNER_DEC,//ADF, Left ADF Frequency Selector (Inner) - Set the tenths and ones number -1		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_L_INNER_INC,//ADF, Left ADF Frequency Selector (Inner) - Set the tenths and ones number +1		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_100_DEC,//ADF, Right ADF Frequency Selector - The hundreds number -1							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_100_INC,//ADF, Right ADF Frequency Selector - The hundreds number +1							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_10_DEC,//ADF, Right ADF Frequency Selector - The tens number -1								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_10_INC,//ADF, Right ADF Frequency Selector - The tens number +1								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_1_DEC,//ADF, Right ADF Frequency Selector - The ones number -1								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_1_INC,//ADF, Right ADF Frequency Selector - The ones number +1								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_FRAC_DEC,//ADF, Right ADF Frequency Selector - The tenths number -1							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_FRAC_INC,//ADF, Right ADF Frequency Selector - The tenths number +1							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_OUTER_DEC,//ADF, Right ADF Frequency Selector (Outer) - Set the hundreds number -1			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_OUTER_INC,//ADF, Right ADF Frequency Selector (Outer) - Set the hundreds number +1			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_MIDDLE_DEC,//ADF, Right ADF Frequency Selector (Middle) - Set the tens number -1				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_MIDDLE_INC,//ADF, Right ADF Frequency Selector (Middle) - Set the tens number +1				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_INNER_DEC,//ADF, Right ADF Frequency Selector (Inner) - Set the tenths and ones number -1		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_ADF_R_INNER_INC,//ADF, Right ADF Frequency Selector (Inner) - Set the tenths and ones number +1		Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FMS_NAV_1_TFR,//Left NAV Panel, Transfer Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_TEST,//Left NAV Panel, TEST Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_MODE_UP,//Left NAV Panel, Mode Switch (Up) - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_MODE_DN,//Left NAV Panel, Mode Switch (Down) - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_0,//Left NAV Panel, Frequency Selection Keypad - 0										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_1,//Left NAV Panel, Frequency Selection Keypad - 1										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_2,//Left NAV Panel, Frequency Selection Keypad - 2										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_3,//Left NAV Panel, Frequency Selection Keypad - 3										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_4,//Left NAV Panel, Frequency Selection Keypad - 4										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_5,//Left NAV Panel, Frequency Selection Keypad - 5										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_6,//Left NAV Panel, Frequency Selection Keypad - 6										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_7,//Left NAV Panel, Frequency Selection Keypad - 7										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_8,//Left NAV Panel, Frequency Selection Keypad - 8										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_9,//Left NAV Panel, Frequency Selection Keypad - 9										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_1_KEY_CLR,//Left NAV Panel, Frequency Selection Keypad - CLR									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_TFR,//Right NAV Panel, Transfer Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_TEST,//Right NAV Panel, TEST Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_MODE_UP,//Right NAV Panel, Mode Switch (Up) - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_MODE_DN,//Right NAV Panel, Mode Switch (Down) - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_0,//Right NAV Panel, Frequency Selection Keypad - 0										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_1,//Right NAV Panel, Frequency Selection Keypad - 1										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_2,//Right NAV Panel, Frequency Selection Keypad - 2										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_3,//Right NAV Panel, Frequency Selection Keypad - 3										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_4,//Right NAV Panel, Frequency Selection Keypad - 4										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_5,//Right NAV Panel, Frequency Selection Keypad - 5										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_6,//Right NAV Panel, Frequency Selection Keypad - 6										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_7,//Right NAV Panel, Frequency Selection Keypad - 7										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_8,//Right NAV Panel, Frequency Selection Keypad - 8										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_9,//Right NAV Panel, Frequency Selection Keypad - 9										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_NAV_2_KEY_CLR,//Right NAV Panel, Frequency Selection Keypad - CLR									Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FMS_XPNDR_MODE_DEC,//Transponder Mode Selector - Rotate Left											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_MODE_INC,//Transponder Mode Selector - Rotate Right											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_MODE_SET,//Transponder Mode Selector - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch ALT OFF; 1:switch XPNDR; 2:switch TA ONLY; 3:switch TA/RA
	KEY_COMMAND_FMS_XPNDR_MODE_TEST,//Transponder Mode Selector (TEST) - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_IDENT,//Identification (IDENT) Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_ATC,//Transponder (XPNDR) Selector - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_ATC_SET,//Transponder (XPNDR) Selector - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch 1; 1:switch 2
	KEY_COMMAND_FMS_XPNDR_ALT_SOURCE,//Altitude (ALT) SOURCE Selector - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_ALT_SOURCE_SET,//Altitude (ALT) SOURCE Selector - Set											Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch 1; 1:switch 2
	KEY_COMMAND_FMS_XPNDR_AIRSPECE_SELECTOR_DEC,//Traffic Collision Avoidance System (TCAS) Functions - Move Up			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_AIRSPECE_SELECTOR_INC,//Traffic Collision Avoidance System (TCAS) Functions - Move Down		Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_AIRSPECE_SELECTOR_SET,//Traffic Collision Avoidance System (TCAS) Functions -Set				Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch ABV; 1:switch N; 2:switch BLW
	KEY_COMMAND_FMS_XPNDR_REPLY_SELECTOR_DEC,//Transponder Reply selector - Move Up										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_REPLY_SELECTOR_INC,//Transponder Reply selector - Move Down									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_REPLY_SELECTOR_SET,//Transponder Reply selector - Set											Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch STBY; 1:switch ON; 2:switch AUTO
	KEY_COMMAND_FMS_XPNDR_KEYPAD_0,//Air Traffic Control (ATC) Code Switch - 0											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_KEYPAD_1,//Air Traffic Control (ATC) Code Switch - 1											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_KEYPAD_2,//Air Traffic Control (ATC) Code Switch - 2											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_KEYPAD_3,//Air Traffic Control (ATC) Code Switch - 3											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_KEYPAD_4,//Air Traffic Control (ATC) Code Switch - 4											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_KEYPAD_5,//Air Traffic Control (ATC) Code Switch - 5											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_KEYPAD_6,//Air Traffic Control (ATC) Code Switch - 6											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_KEYPAD_7,//Air Traffic Control (ATC) Code Switch - 7											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_XPNDR_KEYPAD_CLR,//Air Traffic Control (ATC) Code Switch - CLR										Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FMS_WXR_SYS_CTRL,//WXR, System Control Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_SYS_CTRL_SET,//WXR, System Control Switch - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch TEST; 1:switch NORM
	KEY_COMMAND_FMS_WXR_MODE_L_DEC,//WXR, Left Mode Selector - Rotate Left												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_MODE_L_INC,//WXR, Left Mode Selector - Rotate Right												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_MODE_L_SET,//WXR, Left Mode Selector - Set														Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch MAP; 1:switch AUTO; 2:switch MAN
	KEY_COMMAND_FMS_WXR_MODE_R_DEC,//WXR, Right Mode Selector - Rotate Left												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_MODE_R_INC,//WXR, Right Mode Selector - Rotate Right											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_MODE_R_SET,//WXR, Right Mode Selector - Set														Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch MAP; 1:switch AUTO; 2:switch MAN
	KEY_COMMAND_FMS_WXR_GAIN_L_DEC,//WXR, Left Gain Control Selector - Rotate Left										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_GAIN_L_INC,//WXR, Left Gain Control Selector - Rotate Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_GAIN_L_SET,//WXR, Left Gain Control Selector - Set												Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0~6:MIN~MAX, 3=AUTO
	KEY_COMMAND_FMS_WXR_GAIN_R_DEC,//WXR, Right Gain Control Selector - Rotate Left										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_GAIN_R_INC,//WXR, Right Gain Control Selector - Rotate Right									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_GAIN_R_SET,//WXR, Right Gain Control Selector - Set												Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0~6:MIN~MAX, 3=AUTO
	KEY_COMMAND_FMS_WXR_ALT_L_DEC,//WXR, Left Manual Altitude Control Selector - Rotate Left							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_ALT_L_INC,//WXR, Left Manual Altitude Control Selector - Rotate Right							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_ALT_L_SET,//WXR, Left Manual Altitude Control Selector - Set									Value1: unused																Value2: 0~60000ft
	KEY_COMMAND_FMS_WXR_ALT_R_DEC,//WXR, Right Manual Altitude Control Selector - Rotate Left							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_ALT_R_INC,//WXR, Right Manual Altitude Control Selector - Rotate Right							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_WXR_ALT_R_SET,//WXR, Right Manual Altitude Control Selector - Set									Value1: unused																Value2: 0~60000ft

	KEY_COMMAND_FMS_CDU_1_BRT_DEC,//Left CDU, Brightness Control - Rotate Left											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_BRT_INC,//Left CDU, Brightness Control - Rotate Right											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_BRT_SET,//Left CDU, Brightness Control - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0~20, from DIM to BRT
	KEY_COMMAND_FMS_CDU_1_INIT_REF,//Left CDU, Function and Execute Key - INIT REF										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_RTE,//Left CDU, Function and Execute Key - RTE												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_DEP_ARR,//Left CDU, Function and Execute Key - DEP ARR										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_ATC,//Left CDU, Function and Execute Key - ATC												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_VNAV,//Left CDU, Function and Execute Key - VNAV												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_FIX,//Left CDU, Function and Execute Key - FIX												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LEGS,//Left CDU, Function and Execute Key - LEGS												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_HOLD,//Left CDU, Function and Execute Key - HOLD												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_FMC_COMM,//Left CDU, Function and Execute Key - FMC COMM										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_PROG,//Left CDU, Function and Execute Key - PROG												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_MENU,//Left CDU, Function and Execute Key - MENU												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_N1_LIMIT,//Left CDU, Function and Execute Key - N1 LIMIT										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_PREV_PAGE,//Left CDU, Function and Execute Key - PREV PAGE									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_NEXT_PAGE,//Left CDU, Function and Execute Key - NEXT PAGE									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_EXEC,//Left CDU, Function and Execute Key - EXEC												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_A,//Left CDU, Alpha/Numeric Keys - A															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_B,//Left CDU, Alpha/Numeric Keys - B															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_C,//Left CDU, Alpha/Numeric Keys - C															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_D,//Left CDU, Alpha/Numeric Keys - D															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_E,//Left CDU, Alpha/Numeric Keys - E															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_F,//Left CDU, Alpha/Numeric Keys - F															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_G,//Left CDU, Alpha/Numeric Keys - G															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_H,//Left CDU, Alpha/Numeric Keys - H															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_I,//Left CDU, Alpha/Numeric Keys - I															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_J,//Left CDU, Alpha/Numeric Keys - J															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_K,//Left CDU, Alpha/Numeric Keys - K															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_L,//Left CDU, Alpha/Numeric Keys - L															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_M,//Left CDU, Alpha/Numeric Keys - M															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_N,//Left CDU, Alpha/Numeric Keys - N															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_O,//Left CDU, Alpha/Numeric Keys - O															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_P,//Left CDU, Alpha/Numeric Keys - P															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_Q,//Left CDU, Alpha/Numeric Keys - Q															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_R,//Left CDU, Alpha/Numeric Keys - R															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_S,//Left CDU, Alpha/Numeric Keys - S															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_T,//Left CDU, Alpha/Numeric Keys - T															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_U,//Left CDU, Alpha/Numeric Keys - U															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_V,//Left CDU, Alpha/Numeric Keys - V															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_W,//Left CDU, Alpha/Numeric Keys - W															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_X,//Left CDU, Alpha/Numeric Keys - X															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_Y,//Left CDU, Alpha/Numeric Keys - Y															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_Z,//Left CDU, Alpha/Numeric Keys - Z															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_SP,//Left CDU, Space (SP) Key																	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_DEL,//Left CDU, Delete (DEL) Key																Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_SLASH,//Left CDU, Alpha/Numeric Keys - /														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_CLR,//Left CDU, Clear (CLR) Key																Send this message every 1/18sec can simulate "Push and Hold" feature		Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:key press; 1:key release
	KEY_COMMAND_FMS_CDU_1_0,//Left CDU, Alpha/Numeric Keys - 0															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_1,//Left CDU, Alpha/Numeric Keys - 1															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_2,//Left CDU, Alpha/Numeric Keys - 2															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_3,//Left CDU, Alpha/Numeric Keys - 3															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_4,//Left CDU, Alpha/Numeric Keys - 4															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_5,//Left CDU, Alpha/Numeric Keys - 5															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_6,//Left CDU, Alpha/Numeric Keys - 6															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_7,//Left CDU, Alpha/Numeric Keys - 7															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_8,//Left CDU, Alpha/Numeric Keys - 8															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_9,//Left CDU, Alpha/Numeric Keys - 9															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_1_PERIOD,//Left CDU, Alpha/Numeric Keys - .														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_ADDMINUS,//Left CDU, Alpha/Numeric Keys - +/-													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_L1,//Left CDU,Line Select Keys - L1														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_L2,//Left CDU,Line Select Keys - L2														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_L3,//Left CDU,Line Select Keys - L3														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_L4,//Left CDU,Line Select Keys - L4														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_L5,//Left CDU,Line Select Keys - L5														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_L6,//Left CDU,Line Select Keys - L6														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_R1,//Left CDU,Line Select Keys - R1														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_R2,//Left CDU,Line Select Keys - R2														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_R3,//Left CDU,Line Select Keys - R3														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_R4,//Left CDU,Line Select Keys - R4														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_R5,//Left CDU,Line Select Keys - R5														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_1_LSK_R6,//Left CDU,Line Select Keys - R6														Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FMS_CDU_2_BRT_DEC,//Right CDU, Brightness Control - Rotate Left											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_BRT_INC,//Right CDU, Brightness Control - Rotate Right										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_BRT_SET,//Right CDU, Brightness Control - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0~20, from DIM to BRT
	KEY_COMMAND_FMS_CDU_2_INIT_REF,//Right CDU, Function and Execute Key - INIT REF										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_RTE,//Right CDU, Function and Execute Key - RTE												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_DEP_ARR,//Right CDU, Function and Execute Key - DEP ARR										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_ATC,//Right CDU, Function and Execute Key - ATC												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_VNAV,//Right CDU, Function and Execute Key - VNAV												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_FIX,//Right CDU, Function and Execute Key - FIX												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LEGS,//Right CDU, Function and Execute Key - LEGS												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_HOLD,//Right CDU, Function and Execute Key - HOLD												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_FMC_COMM,//Right CDU, Function and Execute Key - FMC COMM										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_PROG,//Right CDU, Function and Execute Key - PROG												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_MENU,//Right CDU, Function and Execute Key - MENU												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_N1_LIMIT,//Right CDU, Function and Execute Key - N1 LIMIT										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_PREV_PAGE,//Right CDU, Function and Execute Key - PREV PAGE									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_NEXT_PAGE,//Right CDU, Function and Execute Key - NEXT PAGE									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_EXEC,//Right CDU, Function and Execute Key - EXEC												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_A,//Right CDU, Alpha/Numeric Keys - A															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_B,//Right CDU, Alpha/Numeric Keys - B															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_C,//Right CDU, Alpha/Numeric Keys - C															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_D,//Right CDU, Alpha/Numeric Keys - D															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_E,//Right CDU, Alpha/Numeric Keys - E															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_F,//Right CDU, Alpha/Numeric Keys - F															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_G,//Right CDU, Alpha/Numeric Keys - G															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_H,//Right CDU, Alpha/Numeric Keys - H															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_I,//Right CDU, Alpha/Numeric Keys - I															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_J,//Right CDU, Alpha/Numeric Keys - J															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_K,//Right CDU, Alpha/Numeric Keys - K															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_L,//Right CDU, Alpha/Numeric Keys - L															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_M,//Right CDU, Alpha/Numeric Keys - M															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_N,//Right CDU, Alpha/Numeric Keys - N															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_O,//Right CDU, Alpha/Numeric Keys - O															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_P,//Right CDU, Alpha/Numeric Keys - P															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_Q,//Right CDU, Alpha/Numeric Keys - Q															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_R,//Right CDU, Alpha/Numeric Keys - R															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_S,//Right CDU, Alpha/Numeric Keys - S															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_T,//Right CDU, Alpha/Numeric Keys - T															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_U,//Right CDU, Alpha/Numeric Keys - U															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_V,//Right CDU, Alpha/Numeric Keys - V															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_W,//Right CDU, Alpha/Numeric Keys - W															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_X,//Right CDU, Alpha/Numeric Keys - X															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_Y,//Right CDU, Alpha/Numeric Keys - Y															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_Z,//Right CDU, Alpha/Numeric Keys - Z															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_SP,//Right CDU, Space (SP) Key																Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_DEL,//Right CDU, Delete (DEL) Key																Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_SLASH,//Right CDU, Alpha/Numeric Keys - /														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_CLR,//Right CDU, Clear (CLR) Key																Send this message every 1/18sec can simulate "Push and Hold" feature		Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:key press; 1:key release
	KEY_COMMAND_FMS_CDU_2_0,//Right CDU, Alpha/Numeric Keys - 0															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_1,//Right CDU, Alpha/Numeric Keys - 1															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_2,//Right CDU, Alpha/Numeric Keys - 2															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_3,//Right CDU, Alpha/Numeric Keys - 3															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_4,//Right CDU, Alpha/Numeric Keys - 4															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_5,//Right CDU, Alpha/Numeric Keys - 5															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_6,//Right CDU, Alpha/Numeric Keys - 6															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_7,//Right CDU, Alpha/Numeric Keys - 7															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_8,//Right CDU, Alpha/Numeric Keys - 8															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_9,//Right CDU, Alpha/Numeric Keys - 9															Value1: 0: OFF the click sound; 1: ON the click sound	
	KEY_COMMAND_FMS_CDU_2_PERIOD,//Right CDU, Alpha/Numeric Keys - .													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_ADDMINUS,//Right CDU, Alpha/Numeric Keys - +/-												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_L1,//Right CDU,Line Select Keys - L1														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_L2,//Right CDU,Line Select Keys - L2														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_L3,//Right CDU,Line Select Keys - L3														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_L4,//Right CDU,Line Select Keys - L4														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_L5,//Right CDU,Line Select Keys - L5														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_L6,//Right CDU,Line Select Keys - L6														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_R1,//Right CDU,Line Select Keys - R1														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_R2,//Right CDU,Line Select Keys - R2														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_R3,//Right CDU,Line Select Keys - R3														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_R4,//Right CDU,Line Select Keys - R4														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_R5,//Right CDU,Line Select Keys - R5														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FMS_CDU_2_LSK_R6,//Right CDU,Line Select Keys - R6														Value1: 0: OFF the click sound; 1: ON the click sound


	//-------------------------------------------------------------
	//Fuel
	//-------------------------------------------------------------
	KEY_COMMAND_FUEL_CROSSFEED,//CROSSFEED Selector - Click																Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_CROSSFEED_SET,//CROSSFEED Selector - Set															Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_FUEL_CTR_L_PUMP,//FUEL PUMP Switch (CTR L) - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_CTR_L_PUMP_SET,//FUEL PUMP Switch (CTR L) - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_FUEL_CTR_R_PUMP,//FUEL PUMP Switch (CTR R) - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_CTR_R_PUMP_SET,//FUEL PUMP Switch (CTR R) - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_FUEL_AFT_1_PUMP,//FUEL PUMP Switch (L AFT) - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_AFT_1_PUMP_SET,//FUEL PUMP Switch (L AFT) - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_FUEL_FWD_1_PUMP,//FUEL PUMP Switch (L FWD) - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FWD_1_PUMP_SET,//FUEL PUMP Switch (L FWD) - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_FUEL_AFT_2_PUMP,//FUEL PUMP Switch (R AFT) - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_AFT_2_PUMP_SET,//FUEL PUMP Switch (R AFT) - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_FUEL_FWD_2_PUMP,//FUEL PUMP Switch (R FWD) - Click														Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FWD_2_PUMP_SET,//FUEL PUMP Switch (R FWD) - Set													Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_FUEL_LIGHT_CTR_L_LOW_PRESSURE,//Fuel Pump LOW PRESSURE Light (CTR L) - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_CTR_R_LOW_PRESSURE,//Fuel Pump LOW PRESSURE Light (CTR R) - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_AFT_1_LOW_PRESSURE,//Fuel Pump LOW PRESSURE Light (L AFT) - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_FWD_1_LOW_PRESSURE,//Fuel Pump LOW PRESSURE Light (L FWD) - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_AFT_2_LOW_PRESSURE,//Fuel Pump LOW PRESSURE Light (R AFT) - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_FWD_2_LOW_PRESSURE,//Fuel Pump LOW PRESSURE Light (R FWD) - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_VALVE_OPEN,//Crossfeed VALVE OPEN Light - Press												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_FILTER_BYPASS_1,//Engine 1 FILTER BYPASS Lights - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_FILTER_BYPASS_2,//Engine 2 FILTER BYPASS Lights - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_ENG_VALVE_CLOSED_1,//Engine 1 Valve Closed (ENG VALVE CLOSED) Light - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_ENG_VALVE_CLOSED_2,//Engine 2 Valve Closed (ENG VALVE CLOSED) Light - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_SPAR_VALVE_CLOSED_1,//Engine 1 Valve Closed (SPAR VALVE CLOSED) Light - Press				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_LIGHT_SPAR_VALVE_CLOSED_2,//Engine 2 Valve Closed (SPAR VALVE CLOSED) Light - Press				Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_FUEL_FUELING_VALVE_1,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_1_OPEN,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_1_CLOSE,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_C,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_C_OPEN,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_C_CLOSE,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_2,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_2_OPEN,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_2_CLOSE,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_UP,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_DOWN,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_TEST,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_OFF,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_BYPASS,//Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_1_LIGHT,//Fueling Valve Position Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_C_LIGHT,//Fueling Valve Position Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_FUEL_FUELING_VALVE_2_LIGHT,//Fueling Valve Position Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound


	//-------------------------------------------------------------
	//Hydraulics
	//-------------------------------------------------------------
	KEY_COMMAND_HYDRAULIC_ELECTRIC_PUMP_1,//HYD B, ELECTRIC HYDRAULIC PUMP Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_HYDRAULIC_ELECTRIC_PUMP_1_SET,//HYD B, ELECTRIC HYDRAULIC PUMP Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_HYDRAULIC_ELECTRIC_PUMP_2,//HYD A, ELECTRIC HYDRAULIC PUMP Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_HYDRAULIC_ELECTRIC_PUMP_2_SET,//HYD A, ELECTRIC HYDRAULIC PUMP Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_HYDRAULIC_ENG_PUMP_1,//HYD A, ENGINE HYDRAULIC PUMP Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_HYDRAULIC_ENG_PUMP_1_SET,//HYD A, ENGINE HYDRAULIC PUMP Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_HYDRAULIC_ENG_PUMP_2,//HYD B, ENGINE HYDRAULIC PUMP Switch - Click										Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_HYDRAULIC_ENG_PUMP_2_SET,//HYD B, ENGINE HYDRAULIC PUMP Switch - Set									Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch OFF; 1:switch ON
	KEY_COMMAND_HYDRAULIC_LIGHT_ENG_1_LOW_PRESSURE,//HYD A, Engine Hydraulic Pump LOW PRESSURE Light - Press			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_HYDRAULIC_LIGHT_ENG_2_LOW_PRESSURE,//HYD B, Engine Hydraulic Pump LOW PRESSURE Light - Press			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_HYDRAULIC_LIGHT_ELEC_1_LOW_PRESSURE,//HYD B, Electric Hydraulic Pump LOW PRESSURE Light - Press			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_HYDRAULIC_LIGHT_ELEC_2_LOW_PRESSURE,//HYD A, Electric Hydraulic Pump LOW PRESSURE Light - Press			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_HYDRAULIC_LIGHT_ELEC_1_OVERHEAT,//HYD B, Electric Hydraulic Pump OVERHEAT Light - Press					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_HYDRAULIC_LIGHT_ELEC_2_OVERHEAT,//HYD A, Electric Hydraulic Pump OVERHEAT Light - Press					Value1: 0: OFF the click sound; 1: ON the click sound


	//-------------------------------------------------------------
	//Gear
	//-------------------------------------------------------------
	KEY_COMMAND_GEAR_LEVER,//LANDING GEAR Lever - Click																	Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LEVER_SET,//LANDING GEAR Lever - Set																Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch UP; 1:switch DN
	KEY_COMMAND_GEAR_STEERING_SWITCH,//NOSE WHEEL STEER Switch - Click													Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_STEERING_SWITCH_SET,//NOSE WHEEL STEER Switch - Set												Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch ALT; 1:switch NORM
	KEY_COMMAND_GEAR_LEVER_LOCK_SWITCH,//Landing Gear Lever Lock Override (LOCK OVRD) Switch - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_PARKING_BRAKE,//PARKING BRAKE Lever - Click														Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0: use real logic(need brake pedals to set the brake); 1: ignore the brake pedals position, set the parking brake directly
	KEY_COMMAND_GEAR_PARKING_BRAKE_SET,//PARKING BRAKE Lever - Set														Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0: switch RELEASE; 1:switch SET									Value3:0: use real logic(need brake pedals to set the brake); 1: ignore the brake pedals position, set the parking brake directly
	KEY_COMMAND_GEAR_STEER,//Rotate the Nose Wheel Steering Wheel at the captain side panel								Value1: -78~+78 degree
	KEY_COMMAND_GEAR_AUTOBRAKE_DEC,//AUTO BRAKE Select Switch - Rotate Left												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_AUTOBRAKE_INC,//AUTO BRAKE Select Switch - Rotate Right											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_AUTOBRAKE_SET,//AUTO BRAKE Select Switch - Set														Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch RTO; 1:switch OFF; 2:switch 1; 3:switch 2; 4:switch 3; 5:switch MAX
	KEY_COMMAND_GEAR_LIGHT_NOSE_GEAR_RED,//Nose Landing Gear Indicator Light (Top) - Press								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_NOSE_GEAR_GREEN,//Nose Landing Gear Indicator Light (Bottom) - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_LEFT_GEAR_RED,//Left Landing Gear Indicator Light (Top) - Press								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_LEFT_GEAR_GREEN,//Left Landing Gear Indicator Light (Bottom) - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_RIGHT_GEAR_RED,//Right Landing Gear Indicator Light (Top) - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_RIGHT_GEAR_GREEN,//Right Landing Gear Indicator Light (Bottom) - Press						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_SYS2_LEFT_GEAR,//Left Landing Gear Indicator Light (Aft Overhead Panel) - Press				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_SYS2_NOSE_GEAR,//Nose Landing Gear Indicator Light (Aft Overhead Panel) - Press				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_SYS2_RIGHT_GEAR,//Right Landing Gear Indicator Light (Aft Overhead Panel) - Press			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_AUTO_BRAKE_DISARM,//AUTO BRAKE DISARM Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_ANTISKID_INOP,//Antiskid Inoperative (ANTISKID INOP) Light - Press							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_BRAKE_TEMP,//Brake Temperature (BRAKE TEMP) Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_TIRE_PRESSURE,//Tire Pressure (TIRE PRESSURE) Light - Press									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_GEAR_LIGHT_PARKING_BRAKE,//Parking Brake Warning Light - Press											Value1: 0: OFF the click sound; 1: ON the click sound


	//-------------------------------------------------------------
	//Warning Systems
	//-------------------------------------------------------------
	KEY_COMMAND_WARNING_MASTER_FIRE_WARN_LIGHT_L,//Captain Side Master Fire Warning (FIRE WARN) Light - Click			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_MASTER_CAUTION_L,//Captain Side MASTER CAUTION Light - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_SYSTEM_ANNUNCIATOR_L,//Captain Side System Annunciator Panel - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_MASTER_FIRE_WARN_LIGHT_R,//FO Side Master Fire Warning (FIRE WARN) Light - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_MASTER_CAUTION_R,//FO Side MASTER CAUTION Light - Click											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_SYSTEM_ANNUNCIATOR_R,//FO Side System Annunciator Panel - Click									Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_WARNING_AIRSPEED_TEST1,//MACH AIRSPEED WARNING TEST 1 Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_AIRSPEED_TEST2,//MACH AIRSPEED WARNING TEST 2 Switch - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_LIGHT_FDR_OFF,//Flight Recorder OFF Light - Click												Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_WARNING_GPWS_BELOW_GS_L,//Captain Side BELOW Glideslope (G/S) light - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_GPWS_BELOW_GS_R,//FO Side BELOW Glideslope (G/S) light - Click									Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_LIGHT_TAKEOFF_CONFIG_L,//Captain Side Takeoff Configuration Warning Light - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_LIGHT_TAKEOFF_CONFIG_R,//FO Side Takeoff Configuration Warning Light - Click					Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_LIGHT_CABIN_ALTITUDE_L,//Captain Side Cabin Altitude Warning Light - Click						Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_LIGHT_CABIN_ALTITUDE_R,//FO Side Cabin Altitude Warning Light - Click							Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_WARNING_GPWS_FLAP_INHIBIT,//Ground Proximity FLAP INHIBIT Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_GPWS_FLAP_INHIBIT_SET,//Ground Proximity FLAP INHIBIT Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch INHIBIT; 1:switch NORMAL
	KEY_COMMAND_WARNING_GPWS_GEAR_INHIBIT,//Ground Proximity GEAR INHIBIT Switch - Click								Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_GPWS_GEAR_INHIBIT_SET,//Ground Proximity GEAR INHIBIT Switch - Set								Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch INHIBIT; 1:switch NORMAL
	KEY_COMMAND_WARNING_GPWS_TERR_INHIBIT,//Ground Proximity Terrain Inhibit (TERR INHIBIT) Switch - Click				Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_GPWS_TERR_INHIBIT_SET,//Ground Proximity Terrain Inhibit (TERR INHIBIT) Switch - Set			Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch INHIBIT; 1:switch NORMAL
	KEY_COMMAND_WARNING_GPWS_RUNWAY_INHIBIT,//Ground Proximity Runway Inhibit (RUNWAY INHIBIT) Switch - Click			Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_GPWS_RUNWAY_INHIBIT_SET,//Ground Proximity Runway Inhibit (RUNWAY INHIBIT) Switch - Set			Value1: 0: OFF the click sound; 1: ON the click sound						Value2:0:switch INHIBIT; 1:switch NORMAL
	KEY_COMMAND_WARNING_GPWS_SYS_TEST,//Ground Proximity System Test (SYS TEST) Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_GPWS_GPWS_INOP,//GPWS Inoperative (INOP) light - Press											Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_GPWS_RUNWAY_INOP,//Runway Inoperative (INOP) Light - Press										Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_WARNING_STALL_1_TEST,//STALL WARNING TEST 1 Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_STALL_2_TEST,//STALL WARNING TEST 2 Switch - Click												Value1: 0: OFF the click sound; 1: ON the click sound
	KEY_COMMAND_WARNING_LDG_GEAR_WARNING_CUTOUT,//Landing Gear Warning Cutout Switch - Click							Value1: 0: OFF the click sound; 1: ON the click sound

	KEY_COMMAND_WARNING_MAINT_LIGHT,//Maintenance (MAINT) light - Press													Value1: 0: OFF the click sound; 1: ON the click sound




	KEY_COMMAND_IFLY737MAX_END,

}KEY_COMMAND_IFLY737MAX;


#endif