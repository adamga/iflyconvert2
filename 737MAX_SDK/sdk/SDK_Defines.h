#ifndef _737MAXSDK_DEFINE_H_
#define _737MAXSDK_DEFINE_H_

#define iFly737MAX_NOT_RUNNING		0
#define iFly737MAX_RUNNING	     	1

#define VER_P3D_V5				0
#define VER_P3D_V6				1
#define VER_MSFS2020	     	10
#define VER_MSFS2024	     	11


typedef	enum PLANE_LIST
{
	iFly737MAX_7,
	iFly737MAX_8,
	iFly737MAX_8200,
	iFly737MAX_9,
	iFly737MAX_10,

	iFly737MAX_END,
} PLANE_LIST;


typedef	enum ENGINE_LIST
{
	LEAP_1B25,
	LEAP_1B27,
	LEAP_1B28,

	LEAP_END,
} ENGINE_LIST;


static const wchar_t szName737MAXSDK[] = L"iFly737MAX_SDK_FileMappingObject";
static HANDLE hMapFile737MAXSDK=0;
static LPCTSTR pBuf737MAXSDK=NULL;
typedef struct ShareMemory737MAXSDK
{
	//
	// This structure gives access to relevant iFly737MAX status variables.
	// DO NOT WRITE! THERE ARE READ ONLY!
	//

	//**********************************************************************************************************************************
	// v1.0.0
	// 2022-12-24
	//**********************************************************************************************************************************

	int			iFly737MAX_STATE;//iFly737MAX_NOT_RUNNING or iFly737MAX_RUNNING

	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ---------------------------- Airplane General variables --------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	int			Aircraft_Model;//See iFly737MAX_*
	long		Tick18;//same as FS TICK18.
	BYTE		UNITstyle;//0:Metric     1:U.S.System
	BYTE		Lights_Test_Status;//0:switch TEST     1:switch BRT     2:switch DIM
	BYTE		Landing_Light_1_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Landing_Light_2_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Runway_Turnoff_Light_1_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Runway_Turnoff_Light_2_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Taxi_Light_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Logo_Light_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Position_Light_Switch_Status;//0:switch STEADY     1:switch OFF     2:switch STROBE & STEADY
	BYTE		Anti_Collision_Light_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Wing_Light_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Wheel_Well_Light_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		AutoOffTaxiLlight;//0: Without Auto Off Taxi Llight		1: With Auto Off Taxi Llight
	BYTE		LandingLlightAlternateFlash;//0:����Landing Lights - Alternate Flash��1����Landing Lights - Alternate Flash
	BYTE		Dome_Light_Switch_Status;//0:switch DIM     1:switch OFF     2:switch BRIGHT
	BYTE		Emergency_Light_Switch_Status;//0:cover CLOSE		1:cover OPEN, switch OFF		2:cover OPEN, switch ARMED		3:cover OPEN, switch ON
	BYTE		NOT_ARMED_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE		No_Smoking_Switch_Status;//0:switch OFF     1:switch AUTO     2:switch ON
	BYTE		Fasten_Belts_Switch_Status;//0:switch OFF     1:switch AUTO     2:switch ON
	BYTE		Attendant_Call_Switch_Status;//0:switch released     1:switch pressed
	BYTE 		Ground_Call_Switch_Status;//0:switch released     1:switch pressed

	BYTE		EQUIP_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		FWD_ENTRY_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		AFT_ENTRY_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		FWD_SERVICE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		AFT_SERVICE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		FWD_CARGO_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		AFT_CARGO_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LEFT_FWD_OVERWING_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LEFT_AFT_OVERWING_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		RIGHT_FWD_OVERWING_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		RIGHT_AFT_OVERWING_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LEFT_MID_EXIT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		RIGHT_MID_EXIT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		AIRSTAIR_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		CAPT_Main_Panel_Light_Switch_Status;//0~20
	BYTE		FO_Main_Panel_Light_Switch_Status;//0~20
	BYTE		Main_Background_Panel_Light_Switch_Status;//0~20
	BYTE		AFDS_Flood_Panel_Light_Switch_Status;//0~20
	BYTE		Aft_Electronics_Flood_Light_Switch_Status;//0~20
	BYTE		Aft_Electronics_Panel_Light_Switch_Status;//0~20
	BYTE		Compass_Light_Switch_Status;//0��DIM��1��OFF��2��BRT
	double		Oxygen_Pointer_Status;//0~2000PSI
	BYTE		Oxygen_Switch_Status;//0:cover CLOSE, switch NORMAL		1:cover OPEN, switch NORMAL		2:cover OPEN, switch ON
	BYTE		PASS_OXY_ON_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ELT_Switch_Status;//0:cover CLOSE, switch ARM		1:cover OPEN, switch ARM		2:cover OPEN, switch ON
	BYTE		ELT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		CB_Light_Control_Status;//0~20
	BYTE		OVHT_Panel_Light_Control_Status;//0~20
	BYTE		Door_Lock_Selector_Status;//0:switch UNLKD     1:switch AUTO     2:switch DENY
	BYTE		AUTO_UNLK_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		LOCK_FAIL_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------- Air Systems variables ----------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		Air_Temperature_Source_Selector_Status;//0:DUCT(CONT CAB)     1:DUCT(FWD)     2:DUCT(AFT)     3:PASS CAB(FWD)     4:PASS CAB(AFT)     5:PACK(R)     6:PACK(L)
	double		Air_Temperature_Pointer_Status;//0~100 degree
	BYTE		Trim_Air_Switch_Status;//0:OFF     1:ON
	BYTE		ZONE_TEMP_Light_Status[3];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Temperature_Selector_Status[3];//0~7     0:OFF    1:C     4:AUTO     7:W
	BYTE 		DUAL_BLEED_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		RecircFan_Switch_Status[2];//0:OFF     1:AUTO
	double		Duct_Pressure_Pointer_Status[2];//0~80
	BYTE		WingBody_Overheat_Test_Switch_Status;//0:switch released     1:switch pressed
	BYTE		Pack_Switch_Status[2];//0:OFF     1:AUTO     2:HIGH
	BYTE		PACK_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		WING_BODY_OVERHEAT_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		BLEED_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Trip_Reset_Switch_Status;//0:switch released     1:switch pressed
	BYTE		Engine_Bleed_Air_Switch_Status[2];//0:OFF     1:ON
	BYTE		APU_Bleed_Air_Switch_Status;//0:OFF     1:ON
	BYTE		Isolation_Valve_Switch_Status;//0:CLOSE     1:AUTO     2:OPEN

	BYTE		AUTO_FAIL_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		OFF_SCHED_DESCENT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ALTN_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		MANUAL_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Flight_Altitude_Indicator_10000_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Flight_Altitude_Indicator_1000_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Flight_Altitude_Indicator_100_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Flight_Altitude_Indicator_10_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Flight_Altitude_Indicator_1_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Flight_Altitude_Switch_Status;//0~2
	BYTE		Landing_Altitude_Indicator_10000_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Landing_Altitude_Indicator_1000_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Landing_Altitude_Indicator_100_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Landing_Altitude_Indicator_10_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Landing_Altitude_Indicator_1_Status;//0~9: '0'~'9', 10:'-', 11:blank
	BYTE		Landing_Altitude_Switch_Status;//0~2
	double		Outflow_VALVE_Position_Indicator_Pointer_Status;//0~100		0:Close		100:Open
	BYTE		Outflow_Valve_Switch_Status;//0:switch CLOSE     1:switch NEUTRAL     2:switch OPEN
	BYTE		Pressurization_Mode_Selector_Status;//0:switch AUTO     1:switch ALTN     2:switch MAN

	BYTE		Equipment_COOLING_SUPPLY_Switch_Status;//0:switch NORM     1:switch ALTN
	BYTE		Equipment_COOLING_EXHAUST_Switch_Status;//0:switch NORM     1:switch ALTN
	BYTE		Equip_Cooling_OFF_Light_1_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Equip_Cooling_OFF_Light_2_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		EQUIP_SMOKE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	double		CabinAltitude;//ft
	double		CabinDeltaPres;//psi
	double		CabinAltitudeRate;//fpm
	BYTE		Altitude_HORN_Cutout_Switch_Status;//0:switch released     1:switch pressed
	BYTE		High_Altitude_Landing_Switch_Status;//0:switch OFF, INOP light OFF     1:switch OFF, INOP light ON(DIM)     2:switch OFF, INOP light ON(BRT)     3:switch ON, INOP light OFF     4:switch ON, INOP light ON(DIM)     5:switch ON, INOP light ON(BRT)


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ---------------------------- Anti-Ice, Rain variables ----------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		IceDetectorSystem;//0: panel with no ice detector system		1: panel with ice detector system
	BYTE		Window_OVERHEAT_1_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Window_OVERHEAT_2_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Window_OVERHEAT_3_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Window_OVERHEAT_4_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Window_Heat_ON_1_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Window_Heat_ON_2_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Window_Heat_ON_3_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Window_Heat_ON_4_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Window_Heat_Test_Switch_Status;//0:switch OVHT     1:switch NEUTRAL     2:switch PWR TEST
	BYTE		Window_Heat_Switch_1_Status;//0:switch OFF     1:switch ON
	BYTE		Window_Heat_Switch_2_Status;//0:switch OFF     1:switch ON
	BYTE		Window_Heat_Switch_3_Status;//0:switch OFF     1:switch ON
	BYTE		Window_Heat_Switch_4_Status;//0:switch OFF     1:switch ON
	BYTE		CAPT_PITOT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		L_ELEV_PITOT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		L_ALPHA_VANE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		TEMP_PROBE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		FO_PITOT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		R_ELEV_PITOT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		R_ALPHA_VANE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		AUX_PITOT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Probe_Heat_Switch_1_Status;//0:switch AUTO     1:switch ON
	BYTE		Probe_Heat_Switch_2_Status;//0:switch AUTO     1:switch ON
	BYTE		L_VALVE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		R_VALVE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		COWL_ANTI_ICE_1_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		COWL_ANTI_ICE_2_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		COWL_VALVE_1_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		COWL_VALVE_2_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ENG_ANTI_ICE_1_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ENG_ANTI_ICE_2_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Wing_AntiIce_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Eng_1_AntiIce_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Eng_2_AntiIce_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Wiper_L_Switch_Status;//0:switch PARK     1:switch INT     2:switch LOW     3:switch HIGH
	BYTE		Wiper_R_Switch_Status;//0:switch PARK     1:switch INT     2:switch LOW     3:switch HIGH
	BYTE		ICE_DETECTOR_Light_Status;//0:switch released     1:switch pressed
	BYTE		TAT_Test_Switch_Status;//0:switch released     1:switch pressed


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ---------------------------- Automatic Flight variables --------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		ALT_HLD_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		APP_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		CMD_A_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		CMD_B_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		CWS_A_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		CWS_B_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		HDG_SEL_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		LNAV_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		LVL_CHG_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		SPEED_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		VNAV_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		VOR_LOC_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		VS_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		N1_Switch_Status;//0:switch released, light OFF     1:switch released, light ON(DIM)     2:switch released, light ON(BRT)     3:switch pressed, light OFF     4:switch pressed, light ON(DIM)     5:switch pressed, light ON(BRT)
	BYTE		ALT_INTV_Switch_Status;//0:switch released     1:switch pressed
	BYTE		SPD_INTV_Switch_Status;//0:switch released     1:switch pressed
	BYTE		DISENGAGE_Bar_Switch_Status;//0:switch Pull down     1:switch Lift up
	BYTE		FD_1_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		FD_2_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		AT_Switch_Status;//0:switch OFF     1:switch ARM
	BYTE		AT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Bank_Limit_Selector_Status;//0:switch 10     1:switch 15     2:switch 20     3:switch 25     4:switch 30
	BYTE		Heading_Selector_Status;//0~11
	BYTE		Course_1_Selector_Status;//0~11
	BYTE		Course_2_Selector_Status;//0~11
	BYTE		Altitude_Switch_Status;//0~11
	BYTE		IASMACH_Switch_Status;//0~7
	BYTE		VERTSPEED_Switch_Status;//0~11
	BYTE		Changeover_Switch_Status;//0:switch released     1:switch pressed
	BYTE		MA_1_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		MA_2_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Course_1_100_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		Course_1_10_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		Course_1_1_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		SPD_Symbol_Status;//0~9: '0'~'9', 10:'A', 11:'-', 12:'+', 13:Full display(light test pattern), 14:blank
	BYTE		SPD_100_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		SPD_10_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		SPD_1_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		SPD_Point_Status;//0: Decimal point not display     1: Decimal point display
	BYTE		HDG_100_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		HDG_10_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		HDG_1_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		ALT_10000_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		ALT_1000_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		ALT_100_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		ALT_10_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		ALT_1_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		VS_Symbol_Status;//0~9: '0'~'9', 10:not used, 11:'-', 12:'+', 13:not used, 14:blank
	BYTE		VS_1000_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		VS_100_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		VS_10_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		VS_1_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		Course_2_100_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		Course_2_10_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		Course_2_1_Status;//0~9: '0'~'9', 10~13:not used, 14:blank
	BYTE		TOGA_1_Switch_Status;//0:switch released     1:switch pressed
	BYTE		TOGA_2_Switch_Status;//0:switch released     1:switch pressed

	BYTE		AP_AT_Test_Switch_Status[2];//0:switch TEST1     1:switch NEUTRAL     2:switch TEST2
	BYTE		AP_Indicators_Light_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		AT_Indicators_Light_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		AP_Indicators_Light_Status[2];//0: light OFF		1: light ON(Amber, DIM)		2: light ON(Amber, BRT)		3: light ON(Red, DIM)		4: light ON(Red, BRT)
	BYTE		AT_Indicators_Light_Status[2];//0: light OFF		1: light ON(Amber, DIM)		2: light ON(Amber, BRT)		3: light ON(Red, DIM)		4: light ON(Red, BRT)


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// -------------------------------Communications variables --------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE        RTP_Radio_OFF_Status[3];//0:switch released     1:switch pressed
	BYTE        RTP_Offside_Tuning_Light_Status[3];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE        RTP_Frequency_Transfer_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        RTP_Frequency_Selector_1_Switch_Status[3];//0~2
	BYTE        RTP_Frequency_Selector_2_Switch_Status[3];//0~2
	BYTE        RTP_VHF1_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        RTP_VHF2_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        RTP_VHF3_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        RTP_HF1_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        RTP_AM_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        RTP_HF2_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        RTP_VHF1_Radio_Light_Status[3];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE        RTP_VHF2_Radio_Light_Status[3];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE        RTP_VHF3_Radio_Light_Status[3];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE        RTP_HF1_Radio_Light_Status[3];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE        RTP_HF2_Radio_Light_Status[3];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE        RTP_AM_Radio_Light_Status[3];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE        RTP_HF_Sensitivity_Control_Switch_Status[3];//0~2
	BYTE        RTP_Test_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        RTP_Left_Num_100_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��full display		21��not used		22��not used		23��not used		24��blank
	BYTE        RTP_Left_Num_10_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��not used		22��not used		23��full display		24��blank
	BYTE        RTP_Left_Num_1_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��full display		22��not used		23��not used		24��blank
	BYTE        RTP_Left_Num_point1_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��not used		22��not used		23��full display		24��blank
	BYTE        RTP_Left_Num_point2_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��not used		22��full display		23��not used		24��blank
	BYTE        RTP_Left_Num_point3_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��not used		22��not used		23��not used		24��blank
	BYTE        RTP_Left_Num_point_Status[3];//0��blank		1��display
	BYTE        RTP_Right_Num_100_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��full display		21��not used		22��not used		23��not used		24��blank
	BYTE        RTP_Right_Num_10_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��not used		22��not used		23��full display		24��blank
	BYTE        RTP_Right_Num_1_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��full display		22��not used		23��not used		24��blank
	BYTE        RTP_Right_Num_point1_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��not used		22��not used		23��full display		24��blank
	BYTE        RTP_Right_Num_point2_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��not used		22��full display		23��not used		24��blank
	BYTE        RTP_Right_Num_point3_Status[3];//0~9��'0'~'9'	10��'A'		11��'D'		12��'E'		13��'F'		14��'I'		15��'L'		16��'N'		17��'O'		18��'P'		19��'T'		20��not used		21��not used		22��not used		23��not used		24��blank
	BYTE        RTP_Right_Num_point_Status[3];//0��blank		1��display

	BYTE        ACP_AltNorm_Switch_Status[3];//0:switch ALT     1:switch NORM
	BYTE        ACP_Filter_Switch_Status[3];//0:switch V     1:switch B     2:switch R
	BYTE        ACP_SAT1_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        ACP_SAT2_Switch_Status[3];//0:switch released     1:switch pressed
	BYTE        ACP_Push_to_Talk_Switch_Status[3];//0:switch RADIO     1:switch NEUTRAL     2:switch INT

	BYTE        ACP_RVC_VHF1_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_VHF2_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_VHF3_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_HF1_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_HF2_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_INT_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_CABIN_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_PA_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_NAV1_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_NAV2_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_ADF1_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_ADF2_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_MKR_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_SAT1_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_SAT2_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_SPKR_Light_Status[3];//0:light OFF		1:light ON(DIM)		2:light ON(BRT)
	BYTE        ACP_RVC_VHF1_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_VHF2_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_VHF3_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_HF1_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_HF2_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_INT_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_CABIN_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_PA_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_NAV1_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_NAV2_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_ADF1_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_ADF2_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_MKR_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_SAT1_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_SAT2_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_SPKR_Switch_Status[3];//0:switch deselect, light OFF		1:switch deselect, light ON(DIM)		2:switch deselect, light ON(BRT)		3:switch select, light OFF		4:switch select, light ON(DIM)		5:switch select, light ON(BRT)
	BYTE        ACP_RVC_VHF1_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_VHF2_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_VHF3_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_HF1_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_HF2_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_INT_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_CABIN_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_PA_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_NAV1_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_NAV2_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_ADF1_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_ADF2_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_MKR_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_SAT1_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_SAT2_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_RVC_SPKR_Volume_Status[3];//0(Min)~6(Max)
	BYTE        ACP_Transmitter_VHF1_Switch_Status[3];//0:All lights OFF     1:Upper light ON(DIM)     2:Upper light ON(BRT)     3:Lower light ON(DIM)     4:Lower light ON(BRT)     5:All lights ON(DIM)     6:All lights ON(BRT)
	BYTE        ACP_Transmitter_VHF2_Switch_Status[3];//0:All lights OFF     1:Upper light ON(DIM)     2:Upper light ON(BRT)     3:Lower light ON(DIM)     4:Lower light ON(BRT)     5:All lights ON(DIM)     6:All lights ON(BRT)
	BYTE        ACP_Transmitter_VHF3_Switch_Status[3];//0:All lights OFF     1:Upper light ON(DIM)     2:Upper light ON(BRT)     3:Lower light ON(DIM)     4:Lower light ON(BRT)     5:All lights ON(DIM)     6:All lights ON(BRT)
	BYTE        ACP_Transmitter_HF1_Switch_Status[3];//0:All lights OFF     1:Upper light ON(DIM)     2:Upper light ON(BRT)     3:Lower light ON(DIM)     4:Lower light ON(BRT)     5:All lights ON(DIM)     6:All lights ON(BRT)
	BYTE        ACP_Transmitter_HF2_Switch_Status[3];//0:All lights OFF     1:Upper light ON(DIM)     2:Upper light ON(BRT)     3:Lower light ON(DIM)     4:Lower light ON(BRT)     5:All lights ON(DIM)     6:All lights ON(BRT)
	BYTE        ACP_Transmitter_INT_Switch_Status[3];//0:All lights OFF     1:Upper light ON(DIM)     2:Upper light ON(BRT)     3:Lower light ON(DIM)     4:Lower light ON(BRT)     5:All lights ON(DIM)     6:All lights ON(BRT)
	BYTE        ACP_Transmitter_CABIN_Switch_Status[3];//0:All lights OFF     1:Upper light ON(DIM)     2:Upper light ON(BRT)     3:Lower light ON(DIM)     4:Lower light ON(BRT)     5:All lights ON(DIM)     6:All lights ON(BRT)
	BYTE        ACP_Transmitter_PA_Switch_Status[3];//0:Light OFF     1:Light ON(DIM)     2:Light ON(BRT)
	BYTE        ACP_Transmitter_SAT1_Switch_Status[3];//0:All lights OFF     1:Upper light ON(DIM)     2:Upper light ON(BRT)     3:Lower light ON(DIM)     4:Lower light ON(BRT)     5:All lights ON(DIM)     6:All lights ON(BRT)
	BYTE        ACP_Transmitter_SAT2_Switch_Status[3];//0:All lights OFF     1:Upper light ON(DIM)     2:Upper light ON(BRT)     3:Lower light ON(DIM)     4:Lower light ON(BRT)     5:All lights ON(DIM)     6:All lights ON(BRT)

	BYTE        CVR_TEST_Switch_Status;//0:switch released     1:switch pressed
	BYTE        CVR_ERASE_Switch_Status;//0:switch released     1:switch pressed
	BYTE        CVR_STATUS_Light_Status;//0:Light OFF     1:Light ON(DIM)     2:Light ON(BRT)

	BYTE        Service_Interphone_Switch_Status;//0:switch OFF     1:switch ON


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// -------------------------------- Electrical variables ----------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		BAT_DISCHARGE_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE		TR_UNIT_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE		ELEC_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE		ENG_DRIVE_Light_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		STANDBY_PWR_OFF_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE		GRD_POWER_AVAILABLE_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE		ENG_TRANSFER_BUS_OFF_Light_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		ENG_SOURCE_OFF_Light_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		ENG_GEN_OFF_BUS_Light_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		APU_GEN_OFF_BUS_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE		AC_Meters_Selector_Status;//0:STBY PWR		1:GRD PWR		2:GEN1		3:APU GEN		4:GEN2		5:INV		6:TEST
	BYTE		DC_Meters_Selector_Status;//0:STBY PWR		1:BAT BUS		2:BAT		3:AUX BAT		4:TR1		5:TR2		6:TR3		7:TEST
	BYTE		Battery_Switch_Status;//0:cover CLOSE		1:cover OPEN, switch OFF		2:cover OPEN, switch ON
	BYTE		Battery_Switch_Mode;//1:switch OFF		2:switch ON
	BYTE		CAB_UTIL_Switch_Status;//0:switch OFF		1:switch ON
	BYTE		IFE_PASS_SEAT_Switch_Status;//0:switch OFF		1:switch ON
	BYTE		STANDBY_POWER_Switch_Status;//0:cover CLOSE		1:cover OPEN, switch BAT		2:cover OPEN, switch OFF		3:cover OPEN, switch AUTO
	BYTE		STANDBY_POWER_Switch_Mode;//1:switch BAT		2:switch OFF		3:switch AUTO
	BYTE		Generator_Drive_Disconnect_Switch_Status[2];//0:cover CLOSE		1:cover OPEN, switch CONNECT		2:cover OPEN, switch DISCONNECT
	BYTE		Generator_Drive_Disconnect_Switch_Mode[2];//1:switch CONNECT		2:switch DISCONNECT
	BYTE		Ground_Power_Switch_Status;//0:switch OFF		1:switch NEUTRAL		2:switch ON
	BYTE		Bus_Transfer_Switches_Status;//0:cover CLOSE		1:cover OPEN, switch OFF		2:cover OPEN, switch AUTO
	BYTE		Bus_Transfer_Switches_Mode;//1:switch OFF		2:switch AUTO
	BYTE		ENG_Generator_Switch_Status[2];//0:switch OFF		1:switch NEUTRAL		2:switch ON
	BYTE		APU_Generator_Switch_Status[2];//0:switch OFF		1:switch NEUTRAL		2:switch ON
	BYTE		ELEC_MAINT_Switch_Status;//0:switch RELEASE		1:switch PRESS
	char		ELEC_LED_TEXT[2][12];//2 Lines, 12 letters for each.  '0~'9'','A'~'Z','-'.		'*'=full display, ' '=blank

	BYTE		Ground_Service_Switch_Status;//0:switch OFF		1:switch ON


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// -------------------------------- Engines, APU variables --------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		Ignition_Select_Switch_Status;//0:switch IGN L     1:switch BOTH     2:switch IGN R
	BYTE		Engine_Start_Switch_Status[2];//0:switch GRD     1:switch OFF     2:switch CONT     3:switch FLT
	BYTE		Engine_Start_Lever_Status[2];//0:switch CUTOFF, fire light OFF     1:switch CUTOFF, fire light ON(DIM)      2:switch CUTOFF, fire light ON(BRT)     3:switch IDLE, fire light OFF     4:switch IDLE, fire light ON(DIM)     5:switch IDLE, fire light ON(BRT)
	BYTE		EEC_Switch_Status[2];//0:switch OFF, light OFF    1:switch OFF, light OFF, guard OPEN    2:switch OFF, light ON(DIM)    3:switch OFF, light ON(BRT)    4:switch OFF, light ON(DIM), guard OPEN    5:switch OFF, light ON(BRT), guard OPEN    6:switch ON, light OFF    7:switch ON, light OFF, guard OPEN    8:switch ON, light ON(DIM)    9:switch ON, light ON(BRT)    10:switch ON, light ON(DIM), guard OPEN    11:switch ON, light ON(BRT), guard OPEN
	BYTE		REVERSER_LIMITED_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		REVERSER_COMMAND_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		REVERSER_AIRGND_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ENGINE_CONTROL_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	double		Throttle_Lever_1_Position;//0:Idle  1:Max
	double		Throttle_Lever_2_Position;//0:Idle  1:Max
	double		Reverse_Lever_1_Position;//0:Stow  0.2:Reverse Idle Position  1:Full deploy
	double		Reverse_Lever_2_Position;//0:Stow  0.2:Reverse Idle Position  1:Full deploy
	bool		Reverse_Lever_1_locked;//true:Reverse lever locked
	bool		Reverse_Lever_2_locked;//true:Reverse lever locked
	BYTE		Fuel_Flow_Switch_Status;//0:switch RESET     1:switch RATE     2:switch USED
	BYTE		APU_Switch_Status;//0:switch OFF     1:switch ON     2:switch START
	BYTE		DOOR_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LOW_OIL_PRESSURE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		FAULT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		OVER_SPEED_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------- Fire Protection variables ------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		LavatorySmoke;//0: panel with no lavatory smoke detector system		1: panel with lavatory smoke detector system
	BYTE        APU_Fire_Switch_Status;//0:switch NORM, light OFF    1:switch NORM, light ON(DIM)    2:switch NORM, light ON(BRT)    3:switch UP, light OFF    4:switch UP, light ON(DIM)    5:switch UP, light ON(BRT)     6:switch rotate LEFT, light OFF    7:switch rotate LEFT, light ON(DIM)    8:switch rotate LEFT, light ON(BRT)        9:switch rotate RIGHT, light OFF    10:switch  rotate RIGHT, light ON(DIM)    11:switch  rotate RIGHT, light ON(BRT)
	BYTE        Engine_Fire_Switch_Status[2];//0:switch NORM, light OFF    1:switch NORM, light ON(DIM)    2:switch NORM, light ON(BRT)    3:switch UP, light OFF    4:switch UP, light ON(DIM)    5:switch UP, light ON(BRT)     6:switch rotate LEFT, light OFF    7:switch rotate LEFT, light ON(DIM)    8:switch rotate LEFT, light ON(BRT)        9:switch rotate RIGHT, light OFF    10:switch  rotate RIGHT, light ON(DIM)    11:switch  rotate RIGHT, light ON(BRT)
	BYTE		EXT_Test_Switch_Status;//0:switch 1     1:switch NEUTRAL     2:switch 2
	BYTE		Fire_Test_Switch_Status;//0:switch FAULT/INOP     1:switch NEUTRAL     2:switch OVHT/FIRE
	BYTE		OVHT_DET_1_Switch_Status;//0:switch A     1:switch NORMAL     2:switch B
	BYTE		OVHT_DET_2_Switch_Status;//0:switch A     1:switch NORMAL     2:switch B
	BYTE		Fire_Warning_Bell_Cutout_Switch_Status;//0:switch RELEASE		1:switch PRESS
	BYTE		APU_BOTTLE_DISCHARGE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		APU_DET_INOP_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ENG1_OVERHEAT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ENG2_OVERHEAT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Extinguisher_Test_Light_L_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Extinguisher_Test_Light_R_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Extinguisher_Test_Light_APU_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		L_BOTTLE_DISCHARGE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		R_BOTTLE_DISCHARGE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		OverheatDetector_FAULT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		WHEEL_WELL_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Lavatory_SMOKE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)

	BYTE		FWD_Cargo_FIRE_Switch_Status;//0:switch OFF     1:switch OFF, light ON(DIM)     2:switch OFF, light ON(BRT)     3:switch ON     4:switch ON, light ARM(DIM)     5:switch ON, light ON(BRT)
	BYTE		AFT_Cargo_FIRE_Switch_Status;//0:switch OFF     1:switch OFF, light ON(DIM)     2:switch OFF, light ON(BRT)     3:switch ON     4:switch ON, light ARM(DIM)     5:switch ON, light ON(BRT)
	BYTE		CARGO_FIRE_Discharge_Switch_Status;//0:switch OFF, cover CLOSE     1:switch OFF, cover OPEN     2:switch OFF, cover CLOSE, light ON(DIM)     3:switch OFF, cover OPEN, light ON(DIM)     4:switch OFF, cover CLOSE, light ON(BRT)     5:switch OFF, cover OPEN, light ON(BRT)
												   //6:switch ON, cover CLOSE      7:switch ON, cover OPEN      8:switch ON, cover CLOSE, light ON(DIM)      9:switch ON, cover OPEN, light ON(DIM)     10:switch ON, cover CLOSE, light ON(BRT)     11:switch ON, cover OPEN, light ON(BRT)
	BYTE		Cargo_Fire_Test_Light_FWD_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Cargo_Fire_Test_Light_AFT_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Cargo_Fire_Test_Switch_Status;//0:switch RELEASE		1:switch PRESS
	BYTE		DET_Select_1_Switch_Status;//0:switch A		1:switch NORM		2:switch B
	BYTE		DET_Select_2_Switch_Status;//0:switch A		1:switch NORM		2:switch B
	BYTE		DETECTOR_FAULT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------ Flight Controls variables -------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		Flight_Control_A_Switch_Status;//0:guard CLOSE     1:guard OPEN, switch STBY RUD     2:guard OPEN, switch OFF     3:guard OPEN, switch ON
	BYTE		Flight_Control_A_Mode;//1:switch STBY RUD     2:switch OFF     3:switch ON
	BYTE		Flight_Control_B_Switch_Status;//0:guard CLOSE     1:guard OPEN, switch STBY RUD     2:guard OPEN, switch OFF     3:guard OPEN, switch ON
	BYTE		Flight_Control_B_Mode;//1:switch STBY RUD     2:switch OFF     3:switch ON
	BYTE		Spoiler_A_Switch_Status;//0:guard CLOSE     1:guard OPEN, switch OFF     2:guard OPEN, switch ON
	BYTE		Spoiler_A_Mode;//1:switch OFF     2:switch ON
	BYTE		Spoiler_B_Switch_Status;//0:guard CLOSE     1:guard OPEN, switch OFF     2:guard OPEN, switch ON
	BYTE		Spoiler_B_Mode;//1:switch OFF     2:switch ON
	BYTE		Altn_Flap_Master_Switch_Status;//0:guard CLOSE     1:guard OPEN, switch OFF     2:guard OPEN, switch ARM
	BYTE		Altn_Flap_Master_Mode;//1:switch OFF     2:switch ARM
	BYTE		Altn_Flap_Position_Switch_Status;//0:switchUP     1:switch OFF     2:switch DN
	BYTE		Yaw_Damper_Switch_Status;//0:OFF     1:ON
	BYTE		FLT_CTL_A_LOW_PRESSURE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		FLT_CTL_B_LOW_PRESSURE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		YAW_DAMPER_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		STBY_HYD_LOW_QUANTITY_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		STBY_HYD_LOW_PRESSURE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		STBY_RUD_ON_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		FEEL_DIFF_PRESS_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		SPEED_TRIM_FAIL_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		MACH_TRIM_FAIL_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		AUTO_SLAT_FAIL_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		SPOILERS_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		Stab_Trim_Primary_Switch_Status;//0:guard CLOSE     1:guard OPEN, switch NORMAL     2:guard OPEN, switch CUTOFF
	BYTE		Stab_Trim_Primary_Mode;//1:switch NORMAL     2:switch CUTOFF
	BYTE		Stab_Trim_Backup_Switch_Status;//0:guard CLOSE     1:guard OPEN, switch NORMAL     2:guard OPEN, switch CUTOFF
	BYTE		Stab_Trim_Backup_Mode;//1:switch NORMAL     2:switch CUTOFF
	BYTE		Stabilizer_Trim_Override_Switch_Status;//0:guard CLOSE     1:guard OPEN, switch OVERRIDE     2:guard OPEN, switch NORMAL
	BYTE		Stabilizer_Trim_Override_Mode;//1:switch OVERRIDE     2:switch NORMAL
	BYTE		FLAP_Status;//0: Lever UP		1: Lever 1		2: Lever 2		3: Lever 5		4: Lever 10		5: Lever 15		6: Lever 25		7: Lever 30		8: Lever 40
	BYTE		Flap_Left_Light_Status;//0: All lights OFF		1: TRANSIT light ON(DIM)		2: TRANSIT light ON(BRIGHT)		3: FULL EXT light ON(DIM)		4: FULL EXT light ON(BRIGHT)		5: All lights ON(DIM)		6: All lights ON(BRIGHT)
	BYTE		Flap_Right_Light_Status;//0: All lights OFF		1: TRANSIT light ON(DIM)		2: TRANSIT light ON(BRIGHT)		3: FULL EXT light ON(DIM)		4: FULL EXT light ON(BRIGHT)		5: All lights ON(DIM)		6: All lights ON(BRIGHT)
	BYTE		Slat_Left_Light_Status;//0: All lights OFF		1: TRANSIT light ON(DIM)		2: TRANSIT light ON(BRIGHT)		3: EXT light ON(DIM)		4: EXT light ON(BRIGHT)		5: FULL EXT light ON(DIM)		6: FULL EXT light ON(BRIGHT)		7: All lights ON(DIM)		8: All lights ON(BRIGHT)
	BYTE		Slat_Right_Light_Status;//0: All lights OFF		1: TRANSIT light ON(DIM)		2: TRANSIT light ON(BRIGHT)		3: EXT light ON(DIM)		4: EXT light ON(BRIGHT)		5: FULL EXT light ON(DIM)		6: FULL EXT light ON(BRIGHT)		7: All lights ON(DIM)		8: All lights ON(BRIGHT)
	BYTE		LE_Devices_Test_Switch_Status;//0:switch released     1:switch pressed
	int			Spoiler_Lever_Status;//0~225		0: DOWN		35: ARMED		149: FLIGHT DETEND		224: UP
	double		Stabilizer_Trim_Pointer_Status;//0~17 Unit
	BYTE		Stab_Trim_Wheel_Move;//0:trim wheel not move		1:trim wheel move backward		2:trim wheel move forward
	BYTE		Stabilizer_Trim_Switch_Status[2];//0:switch NOSE DOWN     1:switch NEUTRAL     2:switch NOSE UP
	BYTE		SPEED_BRAKE_ARMED_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		SPEED_BRAKE_DO_NOT_ARM_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		STAB_OUT_TRIM_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		SPEEDBRAKES_EXTENDED_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		Elevator_Jam_Landing_Assist_Switch_Status;//0:guard CLOSE     1:guard OPEN, switch OFF     2:guard OPEN, switch ON
	BYTE		ASSIST_ON_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	double		Rudder_Trim_Pointer_Status;//-1.0~+1.0. -1.0: Full to LEFT		0.0: CENTER		1.0: Full to RIGHT
	BYTE		Rudder_Trim_Switch_Status;//0:switch LEFT     1:switch NEUTRAL     2:switch RIGHT
	BYTE		Aileron_Trim_Switch_Status;//0:switch LEFT     1:switch NEUTRAL     2:switch RIGHT
	BYTE		Rudder_Trim_OFF_Light_Status;//0:Trim OFF flag OFF     1:Trim OFF flag ON


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------ Flight Instruments, Displays ----------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		Baro_Select_Status[2];//0:switch IN     1:switch HPA
	BYTE		Barometric_Selector_Status[2];//0~2
	BYTE		BARO_STD_Status[2];//0:switch released     1:switch pressed
	BYTE		BARO_RADIO_Status[2];//0:switch RADIO     1:switch BARO
	BYTE		Minimiums_Selector_Status[2];//0~2
	BYTE		MINS_RST_Status[2];//0:switch released     1:switch pressed
	BYTE		ND_Mode_Status[2];//0:switch APP     1:switch VOR     2:switch MAP     3:switch PLN
	BYTE		CTR_Status[2];//0:switch released     1:switch pressed
	BYTE		ND_Range_Status[2];//0~2
	BYTE		TFC_Status[2];//0:switch released     1:switch pressed
	BYTE		VORADF_L_Status[2];//0:switch VOR     1:switch OFF     2:switch ADF
	BYTE		VORADF_R_Status[2];//0:switch VOR     1:switch OFF     2:switch ADF
	BYTE		FPV_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		MTRS_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		VSD_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		WXR_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		STA_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		WPT_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		ARPT_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		DATA_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		POS_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		TERR_Switch_Status[2];//0:switch released     1:switch pressed

	BYTE		Source_Switch_Status;//0:switch ALL ON 1     1:switch AUTO     2:switch ALL ON 2
	BYTE		Control_Panel_Switch_Status;//0:switch BOTH ON 1     1:switch NORMAL     2:switch BOTH ON 2

	BYTE		CAPT_Display_Selector_Switch_Status;//0:switch OUTBD     1:switch NORMAL     2:switch INBD
	BYTE		FO_Display_Selector_Switch_Status;//0:switch INBD     1:switch NORMAL     2:switch OUTBD
	BYTE		ISFD_Brightness_Switch_Status;//0~20
	BYTE		CAPT_OUTBD_Brightness_Switch_Status;//0~20
	BYTE		CAPT_OUTBD_RADAR_Brightness_Switch_Status;//0~20
	BYTE		CAPT_INBD_Brightness_Switch_Status;//0~20
	BYTE		CAPT_INBD_RADAR_Brightness_Switch_Status;//0~20
	BYTE		FO_OUTBD_Brightness_Switch_Status;//0~20
	BYTE		FO_OUTBD_RADAR_Brightness_Switch_Status;//0~20
	BYTE		FO_INBD_Brightness_Switch_Status;//0~20
	BYTE		FO_INBD_RADAR_Brightness_Switch_Status;//0~20
	BYTE		CDU_Brightness_Status[2];//0~20

	BYTE		CAPT_SELECTOR_Outer_Status;//0:switch L     1:switch C
	BYTE		CAPT_SELECTOR_Inner_Status;//0~2
	BYTE		CAPT_SELECTOR_Switch_Status;//0:switch released     1:switch pressed
	BYTE		FO_SELECTOR_Outer_Status;//0:switch C     1:switch R
	BYTE		FO_SELECTOR_Inner_Status;//0~2
	BYTE		FO_SELECTOR_Switch_Status;//0:switch released     1:switch pressed
	BYTE		ENG_TFR_Switch_Status;//0:switch released     1:switch pressed
	BYTE		MFD_ENG_Switch_Status;//0:switch released     1:switch pressed
	BYTE		MFD_SYS_Switch_Status;//0:switch released     1:switch pressed
	BYTE		MFD_INFO_Switch_Status;//0:switch released     1:switch pressed
	BYTE		MFD_CR_Switch_Status;//0:switch released     1:switch pressed

	BYTE		Flight_Recorder_Switch_Status;//0:cover CLOSE, switch NORMAL     1:cover OPEN, switch NORMAL     2:cover OPEN, switch TEST
	BYTE		Flight_Recorder_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)

	BYTE		Clock_Switch_Status[2];//0:switch released     1:switch pressed

	BYTE		ISFD_APP_Switch_Status;//0:switch released     1:switch pressed
	BYTE		ISFD_HPIN_Switch_Status;//0:switch released     1:switch pressed
	BYTE		ISFD_Increase_Switch_Status;//0:switch released     1:switch pressed
	BYTE		ISFD_Decrease_Switch_Status;//0:switch released     1:switch pressed
	BYTE		ISFD_RST_Switch_Status;//0:switch released     1:switch pressed
	BYTE		ISFD_BARO_Switch_Status;//0:switch released     1:switch pressed
	BYTE		ISFD_BARO_Rotate_Status;//0~5��clockwise rotation


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ---------------------- Flight Management, Navigation variables -------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		VHF_NAV_Switch_Status;//0:switch BOTH ON 1     1:switch NORMAL     2:switch BOTH ON 2
	BYTE		IRS_Switch_Status;//0:switch BOTH ON L     1:switch NORMAL     2:switch BOTH ON R
	BYTE		FMC_Switch_Status;//0:switch BOTH ON L     1:switch NORMAL     2:switch BOTH ON R

	BYTE		FMC_Indicators_Light_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE        FMC_Indicators_Light_Status[2];//0: light OFF		1: light ON(Amber, DIM)		2: light ON(Amber, BRT)

	BYTE		IRS_Brightness_Switch_Status;//0~20
	BYTE		DSPL_SEL_Switch_Status;//0:switch TEST     1:switch TK/GS     2:switch PPOS     3:switch WIND     4:switch HDG/STS
	BYTE		SYS_DSPL_Switch_Status;//0:switch L     1:switch R
	BYTE		IRS_Mode_Switch_Status[2];//0:switch OFF     1:switch ALIGN     2:switch NAV     3:switch ATT
	BYTE		IRS_ALIGN_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		IRS_ON_DC_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		IRS_FAULT_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		IRS_DC_FAIL_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		GPS_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		ILS_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		GLS_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRIGHT)
	BYTE		IRS_Window_L_1_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Full display style;	19:Not used
	BYTE		IRS_Window_L_2_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_L_3_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_L_4_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_L_5_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_L_6_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_R_1_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Full display style
	BYTE		IRS_Window_R_2_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_R_3_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_R_4_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_R_5_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_R_6_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_R_7_Status;//0~9: '0'~'9';	10:Blank;	11:'E';	12:'N';	13:'S';	14:'T';	15:'W';	16:'M';	17:'H';	18:Not used;	19:Not used
	BYTE		IRS_Window_L_point_1_Status;//0: Not display		1: Display
	BYTE		IRS_Window_L_point_2_Status;//0: Not display		1: Display
	BYTE		IRS_Window_L_point_3_Status;//0: Not display		1: Display
	BYTE		IRS_Window_R_point_1_Status;//0: Not display		1: Display
	BYTE		IRS_Window_R_point_2_Status;//0: Not display		1: Display
	BYTE		IRS_Window_R_point_3_Status;//0: Not display		1: Display
	BYTE		IRS_KB_CLR_Switch_Status;//0: switch released, light OFF		1: switch released, light ON(DIM)		2: switch released, light ON(BRIGHT)		3: switch pressed, light OFF		4: switch pressed, light ON(DIM)		5: switch pressed, light ON(BRIGHT)
	BYTE		IRS_KB_ENT_Switch_Status;//0: switch released, light OFF		1: switch released, light ON(DIM)		2: switch released, light ON(BRIGHT)		3: switch pressed, light OFF		4: switch pressed, light ON(DIM)		5: switch pressed, light ON(BRIGHT)
	BYTE		IRS_KB_0_Switch_Status;//0:switch released     1:switch pressed
	BYTE		IRS_KB_1_Switch_Status;//0:switch released     1:switch pressed
	BYTE		IRS_KB_2_Switch_Status;//0:switch released     1:switch pressed
	BYTE		IRS_KB_3_Switch_Status;//0:switch released     1:switch pressed
	BYTE		IRS_KB_4_Switch_Status;//0:switch released     1:switch pressed
	BYTE		IRS_KB_5_Switch_Status;//0:switch released     1:switch pressed
	BYTE		IRS_KB_6_Switch_Status;//0:switch released     1:switch pressed
	BYTE		IRS_KB_7_Switch_Status;//0:switch released     1:switch pressed
	BYTE		IRS_KB_8_Switch_Status;//0:switch released     1:switch pressed
	BYTE		IRS_KB_9_Switch_Status;//0:switch released     1:switch pressed

	BYTE        ADF_Tone_Switch_Status;//0:switch 1     1:switch OFF     2:switch 2
	BYTE        ADF_Test_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE        ADF_Mode_Switch_Status[2];//0:switch ADF     1:switch ANT     2:switch OFF
	BYTE        ADF_num_point1_Status[2];//Decimal after 1st digital.		0: not display     1:display
	BYTE        ADF_num_point2_Status[2];//Decimal after 2nd digital.		0: not display     1:display
	BYTE        ADF_num_point3_Status[2];//Decimal after 3th digital.		0: not display     1:display
	BYTE        ADF_num_point4_Status[2];//Decimal after 4th digital.		0: not display     1:display
	BYTE        ADF_num_01_Status[2];//0~9:'0~'9'     10:blank
	BYTE        ADF_num_1_Status[2];//0~9:'0~'9'     10:blank     11:full display
	BYTE        ADF_num_10_Status[2];//0~9:'0~'9'     10:blank     12:full display
	BYTE        ADF_num_100_Status[2];//0~9:'0~'9'     10:blank     11:full display
	BYTE        ADF_num_1000_Status[2];//0~9:'0~'9'     10:blank
	BYTE        ADF_FLAG[2];//0: not display     1:display
	BYTE        ANT_FLAG[2];//0: not display     1:display

	BYTE		NAV_Transfer_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Test_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Mode_Down_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Mode_Up_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_0_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_1_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_2_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_3_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_4_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_5_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_6_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_7_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_8_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_9_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_Key_CLR_Switch_Status[2];//0:switch released     1:switch pressed
	BYTE		NAV_num_Flag_Status[2][2];//0:"GLS"     1:"ILS"     2:"VOR"     3:"ERR"     4:test mode     5:blank
	BYTE		NAV_num_100_Status[2][2];//0~9:'0~'9'     10:blank     11:Line
	BYTE		NAV_num_10_Status[2][2];//0~9:'0~'9'     10:blank     11:Line     12:full display
	BYTE		NAV_num_1_Status[2][2];//0~9:'0~'9'     10:blank      11:Line     12:not used    13:full display
	BYTE		NAV_num_01_Status[2][2];//0~9:'0~'9'     10:blank      11:Line    12:full display
	BYTE		NAV_num_001_Status[2][2];//0~9:'0~'9'     10:blank     11:Line    12:not used     13:not used      14:full display
	BYTE		NAV_num_0001_Status[2][2];//0~9:'0~'9'     10:blank     11:Line
	BYTE		NAV_num_Point1_Status[2][2];//Decimal after 2nd digital.		0: not display     1:display
	BYTE		NAV_num_Point2_Status[2][2];//Decimal after 3th digital.		0: not display     1:display

	BYTE		Transponder_Mode_Switch_Status;//0:switch ALT OFF     1:switch XPNDR     2:switch TA ONLY     3:switch TA/RA
	BYTE		Transponder_Test_Switch_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Selector_Status;//0:switch 1     1:switch 2
	BYTE		Transponder_TCAS_Airspace_Selector_Status;//0:switch ABV     1:switch N     2:switch BLW
	BYTE		Transponder_Keypad_0_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Keypad_1_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Keypad_2_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Keypad_3_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Keypad_4_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Keypad_5_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Keypad_6_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Keypad_7_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Keypad_CLR_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_Alt_Source_Selector_Status;//0:switch 1     1:switch 2
	BYTE		Transponder_Reply_Selector_Status;//0:switch STBY     1:switch ON     2:switch AUTO
	BYTE		Transponder_Fail_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Transponder_IDENT_Switch_Status;//0:switch released     1:switch pressed
	BYTE		Transponder_num_ATC_Index_Status;//0:Display "ATC 1"     1:Display "ATC 2"     2:Display "ATC 1" and "ATC 2"     3:Display blank
	BYTE		Transponder_Windows_Digital_1000_Status;//0~9:'0~'9'     10:blank
	BYTE		Transponder_Windows_Digital_100_Status;//0~9:'0~'9'     10:blank
	BYTE		Transponder_Windows_Digital_10_Status;//0~9:'0~'9'     10:blank
	BYTE		Transponder_Windows_Digital_1_Status;//0~9:'0~'9'     10:blank

	BYTE		Weather_Radar_Gain_Control_Switch_Status[2];//0~6:MIN~MAX, 3=AUTO
	BYTE		Weather_Radar_Manual_Alt_Control_Switch_Status[2];//0~2
	BYTE		Weather_Radar_Mode_Switch_Status[2];//0:MAP    1:WX-A (Auto mode)    2:WX-M (Manual mode)
	BYTE		Weather_Radar_System_Control_Switch_Status;//0:TEST    1:NORM

	char		LSKChar[2][14][24];//two CDU screen, 14*24
	bool		LSK_SmallFont[2][14][24];//true: display in small font
	BYTE		LSK_Color[2][14][24];//0��White��1��Green��2��Cyan��3��Magenta��4��Grey Background��5��empty BOX��6��Degree Symbol(Write) ��7��Degree Symbol(Write, Grey Background) ��8��Degree Symbol(Magenta) ��9��Left Arrow(White) ��10��Right Arrow(White) 
	BYTE		CDU_FAIL_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		CDU_MSG_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		CDU_EXEC_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		CDU_CALL_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		CDU_OFST_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		CDU_BRT_Switch_Status[2];//0:switch -		1:switch NEUTRAL		2:switch +


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------------ Fuel variables ------------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		ENG_VALVE_CLOSED_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		SPAR_VALVE_CLOSED_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		FILTER_BYPASS_Light_Status[2];//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		VALVE_OPEN_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Fuel_Crossfeed_Selector_Status;//0:valve CLOSED     1:valve OPEN
	BYTE		Fuel_CENTER_L_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Fuel_CENTER_R_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Fuel_L_AFT_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Fuel_L_FWD_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Fuel_R_FWD_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		Fuel_R_AFT_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		LOW_PRESSURE_CENTER_L_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LOW_PRESSURE_CENTER_R_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LOW_PRESSURE_L_AFT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LOW_PRESSURE_L_FWD_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LOW_PRESSURE_R_FWD_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LOW_PRESSURE_R_AFT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	double		FUEL_TEMP_Indicator;//degree. <=-100:invalid

	BYTE		Refuel_Power_Control_Switch_Status;//�����������(S156)��0:Refuel Access Panel CLOSED     1:Refuel Access Panel OPEN
	BYTE		Fueling_Indication_Test_Switch_Status;//0:switch TEST GAGES     1:switch NEUTRAL     2:switch FUEL DOOR SWITCH BYPASS
	BYTE		Refuel_Valve_Control_Switch_Status[3];//0:switch CLOSED     1:switch OPEN		(Index 0��Left Tank��1��Right Tank��2��Center Tank)
	bool		REFUEL_VALVE_Light_Status[3];//false: light OFF		true: light ON		(Index 0��Left Tank��1��Right Tank��2��Center Tank)
	BYTE		Fuel_Quantity_Indicator_Status[3][5];//0~9:'0~'9'     10:blank
	bool		Fuel_Quantity_Indicator_Index_Status[3];//false:not display the fuel tank name at screen     true:display the fuel tank name at screen


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// --------------------------------- Hydraulics variables ---------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		ENG_1_HYD_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		ELEC_2_HYD_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		ELEC_1_HYD_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		ENG_2_HYD_Switch_Status;//0:switch OFF     1:switch ON
	BYTE		ELEC_1_HYD_OVERHEAT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ELEC_2_HYD_OVERHEAT_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ENG_1_HYD_LOW_PRESSURE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ELEC_2_HYD_LOW_PRESSURE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ELEC_1_HYD_LOW_PRESSURE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ENG_2_HYD_LOW_PRESSURE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// -------------------------------- Landing Gear variables --------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE		NOSE_GEAR_RedLight_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		NOSE_GEAR_GreenLight_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LEFT_GEAR_RedLight_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		LEFT_GEAR_GreenLight_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		RIGHT_GEAR_RedLight_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		RIGHT_GEAR_GreenLight_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		Nose_Wheel_Steering_Switch_Status;//0:cover CLOSE     1:cover OPEN, switch ALT     2:cover OPEN, switch NORM
	BYTE		Nose_Wheel_Steering_Mode;//1:switch ALT     2:switch NORM
	BYTE		Gear_Lever_Status;//0:lever UP     1:lever DN
	BYTE		Landing_Gear_Lever_Lock_Override_Switch;//0:switch released     1:switch pressed
	bool		Landing_Gear_Lever_Locked;//true:landing gear lever locked

	BYTE		SYS2_LEFT_GEAR_GreenLight_Status;//landing gear light at aft overhead panel			0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		SYS2_NOSE_GEAR_GreenLight_Status;//landing gear light at aft overhead panel			0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		SYS2_RIGHT_GEAR_GreenLight_Status;//landing gear light at aft overhead panel		0: light OFF		1: light ON(DIM)		2: light ON(BRT)

	BYTE		Parking_Brake_Lever_Status;//0: lever RELEASED     1:lever SET
	BYTE		Parking_Brake_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	double		Hydraulic_Brake_Pressure_Status;//psi
	BYTE		Autobrake_Selector_Status;//0:selector RTO    1:selector OFF    2:selector 1    3:selector 2    4:selector 3    5:selector MAX AUTO
	BYTE		AUTO_BRAKE_DISARM_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		ANTISKID_INOP_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		BRAKE_TEMP_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)
	BYTE		TIRE_PRESSURE_Light_Status;//0: light OFF		1: light ON(DIM)		2: light ON(BRT)


	///////////////////////////////////////////////////////////////////////////////////////////
	//
	// ------------------------------- Warning Systems variables ------------------------------
	//
	///////////////////////////////////////////////////////////////////////////////////////////
	BYTE        Fire_Warning_Light_Status[2];//0:switch released, light OFF		1:switch released, light DIM		2:switch released, light BRI		3:switch pressed, light OFF		4:switch pressed, light DIM		5:switch pressed, light BRI		
	BYTE        Master_Caution_Light_Status[2];//0:switch released, light OFF		1:switch released, light DIM		2:switch released, light BRI		3:switch pressed, light OFF		4:switch pressed, light DIM		5:switch pressed, light BRI		
	BYTE		System_Annunciator_Light_Status[2];//0:switch released		1:switch pressed
	BYTE        Warning_FLTCONT_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_IRS_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_FUEL_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_ELEC_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_APU_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_OVHT_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_ANTIICE_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_HYD_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_DOORS_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_ENG_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_OVERHEAD_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        Warning_AIR_COND_Light_Status;//0:light OFF		1:light DIM		2:light BRI

	BYTE		GS_Inhibit_Switch_Status[2];//0:switch OFF, light OFF		1: switch OFF, light ON(DIM)		2: switch OFF, light ON(BRT)		3:switch ON, light OFF		4: switch ON, light ON(DIM)		5: switch ON, light ON(BRT)
	BYTE        CABIN_ALTITUDE_Light_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE		TAKEOFF_CONFIG_Light_Status[2];//0:light OFF		1:light DIM		2:light BRI
	BYTE        Flap_Inhibit_Switch_Status;//0:cover CLOSE		1:cover OPEN, switch INHIBIT		2:cover OPEN, switch NORM
	BYTE        Gear_Inhibit_Switch_Status;//0:cover CLOSE		1:cover OPEN, switch INHIBIT		2:cover OPEN, switch NORM
	BYTE        Terr_Inhibit_Switch_Status;//0:cover CLOSE		1:cover OPEN, switch INHIBIT		2:cover OPEN, switch NORM
	BYTE        Runway_Inhibit_Switch_Status;//0:cover CLOSE		1:cover OPEN, switch INHIBIT		2:cover OPEN, switch NORM
	BYTE        GPWS_Test_Switch_Status;//0:switch released     1:switch pressed
	BYTE        GPWS_INOP_Light_Status;//0:light OFF		1:light DIM		2:light BRI
	BYTE        RUNWAY_INOP_Light_Status;//0:light OFF		1:light DIM		2:light BRI

	BYTE		Mach_Airspeed_TEST_1_Switch_Status;//0:switch released     1:switch pressed
	BYTE		Mach_Airspeed_TEST_2_Switch_Status;//0:switch released     1:switch pressed
	BYTE		Stall_Warning_TEST_1_Switch_Status;//0:switch released     1:switch pressed
	BYTE		Stall_Warning_TEST_2_Switch_Status;//0:switch released     1:switch pressed
	BYTE		Landing_Gear_Warning_Cutout_Switch_Status;//0:switch released     1:switch pressed

	BYTE		MAINT_light_Status;//0:light OFF		1:light DIM		2:light BRI



	//**********************************************************************************************************************************
	// v1.1.0
	// 2024-09-17
	//**********************************************************************************************************************************
	BYTE		Emergency_Exit_Light_Switch_Status;//0:cover CLOSE, switch OFF		1:cover OPEN, switch OFF		2:cover CLOSE, switch ON		3:cover OPEN, switch ON

}
ShareMemory737MAXSDK, *pShareMemory737MAXSDK;
#define BUF_SIZE_737MAXSDK (sizeof(struct ShareMemory737MAXSDK)+1)
static ShareMemory737MAXSDK ShareMem737MAXSDK;
static pShareMemory737MAXSDK pShareMem737MAXSDK=&ShareMem737MAXSDK;


static HWND FS_main_window=NULL;
static int Version=VER_P3D_V5;


typedef struct iFly737MAX_Message
{
	int      Command;//ID from KEY_COMMAND_IFLY737MAX
	double   Value1;
	double   Value2;
	double   Value3;
} iFly737MAX_Message;


#endif
