TYPE

    (*Enum types*)

	McDirectionEnum :
	(
		mcDIR_POSITIVE,					 (*Movement only in the positive direction *)
		mcDIR_NEGATIVE,					 (*Movement only in the negative direction*)
		mcDIR_CURRENT,					 (*Movement in the direction of the active movement*)
		mcDIR_SHORTEST_WAY,				 (*Movement with the shortest distance to the target, either in positive or negative direction. The movement will be in the positive direction if the distance is the same in both directions*)
		mcDIR_EXCEED_PERIOD := 8,		 (*The end position can be located outside of the axis period. The axis period can be exited in the negative direction if the end position is also negative*)
		mcDIR_UNDEFINED,				 (*Movement in undefined direction*)
		mcDIR_BOTH						 (*Movement in both directions*)
	);

	 McCamAutCouplingSourceEnum :
	(
		mcCAMAUT_COUPLING_SRC_NOT_USED, 	(*No source*)
		mcCAMAUT_COUPLING_SRC_AXIS,		(*Axis as source*)
		mcCAMAUT_COUPLING_SRC_VARIABLE,		(*Process variable as source*)
		mcCAMAUT_COUPLING_SRC_SYSTIME		(*System time as source*)
	);

	McPlcopenParEnum :
	(
		mcPAR_COMMANDED_AX_POSITION := 1, 	 (*Target position for the movement [Measurement units]*)
		mcPAR_SW_LIMIT_POSITIVE,		 (*Currently not available*)
		mcPAR_SW_LIMIT_NEGATIVE,		 (*Currently not available*)
		mcPAR_ENABLE_LIMIT_POSITIVE,	 (*Currently not available*)
		mcPAR_ENABLE_LIMIT_NEGATIVE,	 (*Currently not available*)
		mcPAR_ENABLE_POS_LAG_MONITORING, (*Currently not available*)
		mcPAR_MAX_AX_POSITION_LAG,		 (*Currently not available*)
		mcPAR_MAX_AX_VELOCITY_SYSTEM,	 (*Currently not available*)
		mcPAR_MAX_AX_VELOCITY_APPL,		 (*Currently not available*)
		mcPAR_ACTUAL_AX_VELOCITY,  		 (*Current speed [Measurement units/s]*)
		mcPAR_COMMANDED_AX_VELOCITY,	 (*Currently not available*)
		mcPAR_MAX_AX_ACCELERATION_SYSTEM,	 (*Currently not available*)
		mcPAR_MAX_AX_ACCELERATION_APPL,	 (*Currently not available*)
		mcPAR_MAX_AX_DECELERATION_SYSTEM,	 (*Currently not available*)
		mcPAR_MAX_AX_DECELERATION_APPL,	 (*Currently not available*)
		mcPAR_MAX_AX_JERK,			(*Maximum jerk of the axis*)
		mcPAR_AX_PERIOD := 1008,     (*The range of values of the axis position is [0, period] in [Measurement units]*)
		mcPAR_SW_END_IGNORE := 1014,     (*Status of the SW end position monitoring*)
		mcPAR_HOMING_OFFSET := 1019, 	 (*Homing offset [Measurement units]. Cannot be read before the first homing procedure*)
		mcPAR_AX_MEASUREMENT_RESOLUTION := 1020,   (*Defines the possible resolution of [Measurement units] that can be met*)
		mcPAR_REFERENCE_PULSE_DISTANCE := 1021,   (*Reference pulse distance [Measurement units]. Cannot be read before the first homing procedure*)
		mcPAR_DISTANCE_PER_ENCODER_REV := 1022   (*Distance of one encoder revolution [Measurement units]*)
	);

	McCamIplModeEnum :
	(
		mcCAMIPL_CUBIC_SPLINE, 				(*Cubic spline interpolation (3rd order polynomial)*)
		mcCAMIPL_OPTIMIZED_VELOCITY,			(*5th order polynomials with optimized velocity characteristics*)
		mcCAMIPL_OPTIMIZED_ACCELERATION,		(*5th order polynomials with optimized velocity and acceleration characteristics*)
		mcCAMIPL_BESTFIT_5TH_ORDER,			(*Best fit interpolation with 5th order polynomials*)
		mcCAMIPL_BESTFIT_6TH_ORDER				(*Best fit interpolation with 6th order polynomials*)
	);

	McCamTypeEnum :
	(
		mcCAMTYPE_NON_PERIODIC,	(*Parameters "StartSlope", "EndSlope" and "StartCurvature", "EndCurvature" are used for the slope at the beginning and end as well as the curvature at the beginning and end of the polynomial cam*)
		mcCAMTYPE_PERIODIC	(*The slope and curvature for the beginning and endpoints are set the same as each other*)
	);

	McCamSectRefPointEnum :
	(
		mcCAMSECTREF_ABSOLUTE := 0, (*Master and slave position are used as absolute values*)
		mcCAMSECTREF_RELATIVE := 1  (*Master and slave position are used as relative values from the last point*)
	);

	McCamSectLawOfMotionEnum :
	(
		mcCAMSECTLAW_LAST_POINT := 0,
		mcCAMSECTLAW_STRAIGHT_LINE := 1,
		mcCAMSECTLAW_QUADRATIC_PARABOLA := 2,
		mcCAMSECTLAW_SIMPLE_SINE_CURVE := 3,
		mcCAMSECTLAW_5TH_ORDER_POLYNOM := 4,
		mcCAMSECTLAW_INCLINED_SINE_CURVE := 5,
		mcCAMSECTLAW_MOD_ACCEL_TRAPEZOID := 6,
		mcCAMSECTLAW_MOD_SINE_CURVE := 7,
		mcCAMSECTLAW_HARMONIC_COMBI := 8
	);

	McEventSrcEnum :
	(
		mcEVENT_SRC_TRIGGER1 := 0,		(*Use Trigger 1 as an event source*)
		mcEVENT_SRC_TRIGGER2 := 1,		(*Use Trigger 2 as an event source*)
		mcEVENT_SRC_ALT_VALUE1 := 2,	(*"Value source 1" of the feature "Alternative value source" is used*)
		mcEVENT_SRC_ALT_VALUE2 := 3,	(*"Value source 2" of the feature "Alternative value source" is used*)
		mcEVENT_SRC_ALT_VALUE3 := 4,	(*"Value source 3" of the feature "Alternative value source" is used*)
		mcEVENT_SRC_ALT_VALUE4 := 5,	(*"Value source 4" of the feature "Alternative value source" is used*)
		mcEVENT_SRC_ALT_VALUE5 := 6,	(*"Value source 5" of the feature "Alternative value source" is used*)
		mcEVENT_SRC_ALT_VALUE6 := 7,	(*"Value source 6" of the feature "Alternative value source" is used*)
		mcEVENT_SRC_ALT_VALUE7 := 8,	(*"Value source 7" of the feature "Alternative value source" is used*)
		mcEVENT_SRC_ALT_VALUE8 := 9		(*"Value source 8" of the feature "Alternative value source" is used*)
	);

	McBrTouchProbeModeEnum :
	(
		mcTP_MODE_WITHOUT_PERIOD := 4, (*Do not use axis or window period*)
		mcTP_MODE_SHIFT_FROM_RESULT := 49, (*Shift window from detected trigger position*)
		mcTP_MODE_SHIFT_FROM_EXPECTED := 50 (*Shift window from expected trigger position*)
	);

	McBrTriggerInfoStatusEnum :
	(
		mcTRG_STAT_WAITING := 0, (*Waiting for trigger event*)
		mcTRG_STAT_VALID := 1, (*A valid trigger event was detected*)
		mcTRG_STAT_MISSED := 2 (*No valid trigger event was detected in period*)
	);

	McDisableModeEnum :
	(
		mcDISABLE_DEFAULT := 0, (*Switch to default setting at disable*)
		mcDISABLE_KEEP_VALUE := 1 (*Keep value at disable*)
	);

	McEventMoveModeEnum :
	(
		mcEVENT_ONCE := 0, (*Single start of a movement after an event*)
		mcEVENT_CYCLIC := 1, (*Cyclic start of a movement during standstill. Note: Not applicable for FB MC_BR_EventMoveVelocity*)
		mcEVENT_CYCLIC_ALL_EVENTS := 2 (*Cyclic start of a movement for all events*)
	);

	McMechDevCompStateEnum:
	(
		mcMDC_STATE_NOT_ACTIVE, (*Compensation is not active*)
		mcMDC_STATE_INIT, (*Initialization of parameters*)
		mcMDC_STATE_ACTIVE_DIR_INDEP, (*Direction independent compensation active*)
		mcMDC_STATE_ACTIVE_DIR_DEP, (*Direction dependent compensation active*)
		mcMDC_STATE_ERROR (*Error state*)
	);

	(*Structure types*)

	McLibraryInfoType : STRUCT
		Name : STRING[32]; (*Name of the implementation-specific axis library*)
	END_STRUCT;

	McDigitalInputStatusType : STRUCT
	    HomingSwitch : BOOL; (*The digital reference switch input is active*)
        PositiveLimitSwitch : BOOL; (*The positive hardware limit switch is active*)
	    NegativeLimitSwitch : BOOL; (*The negative hardware limit switch is active*)
		Trigger1 : BOOL; (*Trigger input 1 is enabled*)
		Trigger2 : BOOL; (*Trigger input 2 is enabled*)
		DriveEnable : BOOL; (*Drive input "Enable" is active*)
	END_STRUCT;

	McAddInfoType : STRUCT
		DigitalInputStatus : McDigitalInputStatusType; (*Status of the digital inputs*)
		LagWarning : BOOL; (*Lag error warning limit reached*)
		StartupCount : UDINT; (*Number of times the drive was started up since the last PLC start*)
		CommunicationState : McCommunicationStateEnum; (*State of network communication*)
		PLCopenState :  McAxisPLCopenStateEnum; (*Extended PLCopen state*)
		InMotion : BOOL; (*Controlled movement on the axis*)
		MechDeviationCompState : McMechDevCompStateEnum; (*State of mechanical deviation compensation*)
	END_STRUCT;

	McAdvVelCtrlParType : STRUCT
		Acceleration : REAL; (*Maximum acceleration [Measurement units/s�]*)
		Deceleration : REAL; (*Maximum deceleration [Measurement units/s�]*)
		Jerk : REAL; (*Maximum jerk [Measurement units/s�]*)
	END_STRUCT;

	McShiftModeEnum:
	(
		mcSHIFT_ABSOLUTE,  (*The value on input "XxxShift" is interpreted as an absolute value*)
		mcSHIFT_RELATIVE,  (*The value on input "XxxShift" is interpreted as a relative value*)
		mcSHIFT_ABSOLUTE_NO_RESET,  (*The functionality here is effectively the same as for mcSHIFT_ABSOLUTE. With this setting, however, the shift value on the drive is not set to 0 if the slave axis leaves state Synchronized Motion and input "Enable" is still set*)
		mcSHIFT_RELATIVE_NO_RESET  (*The functionality here is effectively the same as for mcSHIFT_RELATIVE. With this setting, however, the shift value on the drive is not set to 0 if the slave axis leaves state Synchronized Motion and input "Enable" is still set*)
	);

	McProfileBaseEnum:
	(
		mcPROFBASE_TIME,  (*A speed profile is calculated depending on the "Velocity" and "Acceleration" inputs. The duration of the phase shift is independent of a master speed. If a negative value is entered, this can cause the slave axis to move in the negative direction if the original master speed is low or 0*)
		mcPROFBASE_MASTER_POSITION,  (*The speed profile is calculated from the speed of the coupling master measured at the beginning of the phase shift and function block inputs "Velocity" and "Acceleration". The current master position serves as a basis for calculating the actual shift from the speed profile. The duration of the phase shift depends on the master speed measured at the beginning (profile calculation) and the current master speed*)
		mcPROFBASE_MASTER_DISTANCE,  (*A smooth motion profile is calculated based on the configured value for "ProfileDistance". "ProfileDistance" refers to the sections completed by the master axis. This prevents the slave from moving in the negative direction. The movement is limited by the "Velocity" and "Acceleration" values*)
		mcPROFBASE_SLAVE_POSITION,  (*As per mcPROFBASE_MASTER_POSITION, but in reference to the slave*)
		mcPROFBASE_SLAVE_DISTANCE,  (*As per mcPROFBASE_MASTER_DISTANCE, but in reference to the slave*)
		mcPROFBASE_MASTER_ZONE,  (*A smooth motion profile is calculated based on the configured values for "ZoneParameters". These parameters refer to sections of the master axis*)
		mcPROFBASE_SLAVE_ZONE  (*As per mcPROFBASE_MASTER_ZONE, but in reference to the slave*)
	);

	McAdvShiftDistanceParType : STRUCT
		ProfileDistance : LREAL; (*Distance to the offset [Measurement units]*)
	END_STRUCT;

	McAdvShiftZoneParType : STRUCT
		StartPosition : LREAL; (*Starting position in the profile base for starting the offset [Measurement units]*)
		EndPosition : LREAL; (*End position in the profile base for ending the offset [Measurement units]*)
		Period : LREAL; (*Defines the period if a non-periodic profile base axis or an offset period other than the axis period is to be used [Measurement units]*)
	END_STRUCT;

	McAdvPhasingParType : STRUCT
		ShiftMode : McShiftModeEnum; (*Defines how the value on input "XxxShift" should be used*)
		ProfileBase : McProfileBaseEnum; (*Defines the profile base for the offset as a time or position value*)
		ProfileBaseMaxVelocity : REAL; (*Maximum speed of profile base during offset [Measurement units]*)
		DistanceParameters : McAdvShiftDistanceParType ; (*Distance to the offset [Measurement units]*)
		ZoneParameters : McAdvShiftZoneParType ; (*Position range in which the offset occurs [Measurement units]*)
		Jerk : REAL; (*Maximum jerk of the profile [Measurement units/s�]*)
		ShiftAlternativeValueSource : McAltValueSrcEnum; (*If used, defines the alternative source of shift value [Axis units]*)
	END_STRUCT;

	McAdvOffsetParType : STRUCT
		ShiftMode : McShiftModeEnum; (*Defines how the value on input "XxxShift" should be used*)
		ProfileBase : McProfileBaseEnum; (*Defines the profile base for the offset as a time or position value*)
		ProfileBaseMaxVelocity : REAL; (*Maximum speed of profile base during offset [Measurement units/s]*)
		DistanceParameters : McAdvShiftDistanceParType ; (*Distance to the offset [Measurement units]*)
		ZoneParameters : McAdvShiftZoneParType ; (*Position range in which the offset occurs [Measurement units]*)
		Jerk : REAL; (*Maximum jerk of the profile [Measurement units/s�]*)
		ShiftAlternativeValueSource : McAltValueSrcEnum; (*If used, defines the alternative source of shift value [Axis units]*)
	END_STRUCT;

	McAdvGearInParType : STRUCT
		MasterMaxVelocity : REAL; (*Maximum velocity of the master axis [Measurement units of master/s]*)
	END_STRUCT;

	McAdvGearInPosParType : STRUCT
		MasterMaxVelocity : REAL; (*Maximum velocity of the master axis [Measurement units of master/s]*)
	END_STRUCT;

	McAdvCamInParType : STRUCT
		Periodic : BOOL; (*TRUE -> Cam is executed periodically; FALSE -> Cam is executed just once*)
		Velocity : REAL; (*Velocity which is used for the movement to the start position [Measurement units of slave/s]*)
		Acceleration : REAL; (*Acceleration which is used for the movement to the start position [Measurement units of slave/s�]*)
		Deceleration : REAL; (*Deceleration which is used for the movement to the start position [Measurement units of slave/s�]*)
		Jerk : REAL; (*Maximum jerk during the "move to start" movement [Measurement units of slave/s�]*)
	END_STRUCT;

	McCamAutCrossLeftBoundEnum:
	(
		mcCAMAUT_LIMIT_HORIZONTAL,  (*Position has a horizontal limit*)
		mcCAMAUT_EXTEND_POLY  (*Left limit polynomial is extended*)
	);

	McCamAutCamChangeImmedEnum:
	(
		mcCAMAUT_MASTER_DIR,  (*In the current master direction of movement*)
		mcCAMAUT_POSITIVE_DIR  (*In the positive direction only*)
	);

	McCamAutErrorsInStandbyEnum:
	(
		mcCAMAUT_ERRORS_OFF,  (*No error message in standby mode*)
		mcCAMAUT_ERRORS_ON  (*Error message in standby mode*)
	);

	McCamAutExceedingLimitsEnum:
	(
		mcCAMAUT_WARNING,  (*Warning when limit values have been exceeded*)
		mcCAMAUT_ERROR  (*Error when limit values have been exceeded*)
	);

	McCamAutGetParCmdEnum:
	(
		mcGET_PAR_FROM_OBJECT,  (*Copies parameters from a cam configuration object*)
		mcGET_PAR_ACTUAL,  (*Copies parameters from the configured cam automat for the axis*)
		mcGET_PAR_DEFAULT  (*Copies parameters from the preconfigured cam automat configuration object for the axis*)
	);

	McCamAutSetParCmdEnum:
	(
		mcSET_ALL_PAR_FROM_OBJ, 		 (*Transfers all parameters from a cam automat configuration object*)
		mcSET_ALL_PAR_FROM_ADR, 		 (*Transfers all parameters from the specified user structure*)
		mcSET_ALL_PAR_DEFAULT, 		 (*Transfers all parameters from the preconfigured cam automat configuration object for the axis*)
		mcSET_UPDATE_FROM_OBJ, 		 (*Transfers all update parameters from a cam automat configuration object*)
		mcSET_UPDATE_FROM_ADR, 		 (*Transfers all update parameters from the specified user structure*)
		mcSET_UPDATE_DEFAULT, 		 (*Transfers all update parameters from the preconfigured cam automat configuration object for the axis*)
		mcSET_SYNC_UPDATE_FROM_OBJ,	 (*Transfers all SyncUpdate parameters from a cam automat configuration object*)
		mcSET_SYNC_UPDATE_FROM_ADR, 	 (*Transfers all SyncUpdate parameters from the specified user structure*)
		mcSET_SYNC_UPDATE_DEFAULT 	 (*Transfers all SyncUpdate parameters from the preconfigured cam automat configuration object for the axis*)
	);

	McCamAutResetCmdEnum:
	(
		mcRESET_ALL_AUTOMAT_PARAMS,  (*Resets general automat parameters and all automat states*)
		mcRESET_COMMON_PARAMS,  (*Resets general automat parameters*)
		mcRESET_ALL_STATE_PARAMS,  (*Resets all automat states*)
		mcRESET_ONE_STATE_PARAMS  (*Resets a specific automat state*)
	);

	McCamAutParLockCmdEnum:
	(
		mcCAMAUT_NO_LOCK, 				 (*Automat is not locked*)
		mcCAMAUT_LOCK, 					 (*Locks the automat in order to transfer parameters*)
		mcCAMAUT_UNLOCK_NEXT_STATE, 	 (*Unlocks the automat when switching to the next automat state*)
		mcCAMAUT_UNLOCK_SYNCHRON 		 (*Unlocks the automat when a defined event occurs*)
	);

	McCamAutCompModeEnum:
	(
		mcCOMP_OFF := 0, 					 (*No compensation*)
		mcCOMP_BETWEEN_CAMS := 30, 		 (*Spacing between cams*)
		mcCOMP_BETWEEN_CAMS_DIRECT := 35,  (*Spacing between the end of one cam and the start of another*)
		mcCOMP_CAM_CENTER_POINTS := 31, 	 (*Spacing from the center of one cam to another*)
		mcCOMP_MA_LATCHPOS := 32, 		 (*Master spacing between latch position and cam center*)
		mcCOMP_SL_LATCHPOS := 34, 		 (*Slave spacing between latch position and cam center*)
		mcCOMP_SL_ABSOLUTE := 33, 		 (*Slave compensation for absolute slave position*)
		mcCOMP_VELOCITY_S_MA := 37, 		 (*Minimum jerk velocity mode with master target distance*)
		mcCOMP_VELOCITY_S_SL := 38, 		 (*Minimum jerk velocity mode with slave target distance*)
		mcCOMP_VELOCITY_A_SL := 36, 		(*time optimal jolt limited velocity mode*)
		mcCOMP_VELOCITY_A_CYC := 39, 		 (*Time-optimized jerk-limited velocity mode, cyclical master velocity determination*)
		mcCOMP_MA_SL_ABSOLUTE := 40 		 	     (*Absolute master and slave position when compensation is finished*)
	);

	McCamAutEventTypeEnum:
	(
		mcEVENT_OFF := 0,  (*Disables the event*)
		mcEVENT_START_POSITION := 10,  (*Event is triggered at master starting position*)
		mcEVENT_STATE_END := 12,  (*Event is triggered at end of state*)
		mcEVENT_STATE_END_NEGATIVE := 13,  (*Event is triggered at left end of state*)
		mcEVENT_COUNT := 11,  (*Event is triggered when RepeatCounter is reached*)
		mcEVENT_SIGNAL1 := 91,  (*Event is triggered by Signal1*)
		mcEVENT_SIGNAL2 := 92,  (*Event is triggered by Signal2*)
		mcEVENT_SIGNAL3 := 93,  (*Event is triggered by Signal3*)
		mcEVENT_SIGNAL4 := 94,  (*Event is triggered by Signal4*)
		mcEVENT_TRIGGER1_P_EDGE := 20,  (*Event is triggered by rising edge of Trigger1*)
		mcEVENT_TRIGGER1_N_EDGE := 21,  (*Event is triggered by falling edge of Trigger1*)
		mcEVENT_TRIGGER2_P_EDGE := 22,  (*Event is triggered by rising edge of Trigger2*)
		mcEVENT_TRIGGER2_N_EDGE := 23,  (*Event is triggered by falling edge of Trigger2*)
		mcEVENT_AND_NEXT_TWO := 15,  (*Event is triggered by the next two defined events triggered*)
		mcEVENT_PARID1 := 16,  (*Event is triggered when EventParID1 changes from 0 to not 0*)
		mcEVENT_PARID2 := 17,  (*Event is triggered when EventParID2 changes from 0 to not 0*)
		mcEVENT_PARID3 := 18,  (*Event is triggered when EventParID3 changes from 0 to not 0*)
		mcEVENT_PARID4 := 19,  (*Event is triggered when EventParID4 changes from 0 to not 0*)
		mcEVENT_START_IV_POS1 := 41,  (*Event is triggered when starting interval Position1 is reached*)
		mcEVENT_START_IV_POS2 := 42,  (*Event is triggered when starting interval Position2 is reached*)
		mcEVENT_START_IV_POS3 := 43,  (*Event is triggered when starting interval Position3 is reached*)
		mcEVENT_START_IV_POS4 := 44  (*Event is triggered when starting interval Position4 is reached*)
	);

	McCamAutMaStartPosModeEnum:
	(
		mcCAMAUT_EVALUATE_NEW,  (*Starting position is recalculated*)
		mcCAMAUT_NO_NEW_EVALUATION  (*Starting position is not recalculated*)
	);

	McCamAutEventTransitionEnum:
	(
		mcEVENT_IMMEDIATELY := 0,  (*State changes immediately*)
		mcEVENT_END_OF_STATE := 12  (*State changes at end of state*)
	);

	McCamStartModeEnum:
	(
	 	mcCAM_START_DIRECT,	(*The cam coupling is startet directly at the current axes positions*)
		mcCAM_START_ABSOLUTE,	(*"MasterOffset" and "SlaveOffset" are interpreted as absolute values*)
		mcCAM_START_RELATIVE	(*"MasterOffset" and "SlaveOffset" are interpreted as relative  values*)
	);

	McCamInStatusEnum:
	(
		mcCAM_STATUS_PREPARING_MOVE, (*Preparing for move to SlaveOffset position*)
		mcCAM_STATUS_MOVE_TO_START_POS,	(*Axis is moving to the SlaveOffset position*)
		mcCAM_STATUS_PREPARING_CAM, (*Preparing cam coupling*)
		mcCAM_STATUS_WAIT_FOR_MASTER,	(*Axis is waiting for the master axis to reach the master start position*)
	 	mcCAM_STATUS_IN_CAM,	(*Axis is in cam movement (is set similar to InSync)*)
	 	mcCAM_STATUS_END	(*Non-periodic cam has ended*)
	);

	McSyncModeEnum:
	(
		mcSYNC_MODE_POSITIVE, (*Synchronous position is approached from the starting point in positive direction*)
		mcSYNC_MODE_NEGATIVE,	(*Synchronous position is approached from the starting point in negative directionn*)
		mcSYNC_MODE_SHORTEST_WAY,	(*The nearest synchronous position to the starting point is approached*)
	 	mcSYNC_MODE_WITHIN_PERIOD	(*The synchronous position is approached in the current slave period*)
	);

	McAdvCamInModeEnum:
	(
		mcCAM_MASTER_INTERVAL, (*The cam is started at the current slave position and next possible master start position*)
		mcCAM_DIRECT,	(*The start takes place directly in the cam depending on the master and slave position*)
		mcCAM_MASTER_INTERVAL_LEAD_IN,	(*The cam is started at the current slave position and next possible master start position*)
	 	mcCAM_MASTER_INTERVAL_LEAD_OUT,	(*The cam is started at the current slave position and next possible master start position*)
	 	mcCAM_MASTER_INTERVAL_LEAD_INOUT,	(*The cam is started at the current slave position and next possible master start position*)
	 	mcCAM_DIRECT_LEAD_OUT	(*The start takes place directly in the cam depending on the master and slave position*)
	);

	McAxisTypeEnum:
	(
		mcAX_TYPE_ACP_REAL, (*ACOPOS real axis*)
		mcAX_TYPE_ACP_VIRT,	(*ACOPOS virtual axis*)
		mcAX_TYPE_ACP_APSM,	(*ACOPOS auxiliary power supply module axis*)
	 	mcAX_TYPE_ACP_PS_ACTIVE, (*ACOPOS active power supply axis*)
	 	mcAX_TYPE_ACP_PS_PASSIVE, (*ACOPOS passive power supply axis*)
	 	mcAX_TYPE_ACP_EXT_ENC,	(*ACOPOS external encoder axis*)
	 	mcAX_TYPE_ACP_INV,	(*ACOPOSinverter axis*)
	 	mcAX_TYPE_STP,	(*Stepper module axis*)
		mcAX_TYPE_PURE_VIRT,	(*Purely virtual axis*)
	 	mcAX_TYPE_PURE_VIRT_GPAI,	(*Purely virtual axis with activated general purpose axis interface*)
	 	mcAX_TYPE_DS402_SERVO,	(*DS402 conform servo drive axis*)
	 	mcAX_TYPE_DS402_INV	(*DS402 conform inverter axis*)
	);

	McCamDefineType : STRUCT
		DataObjectName : STRING[12]; (*Name of the cam data object*)
		DataAdress : UDINT; (*Address of the cam data on the PLC provided in a PV of data type "McCamDataType"*)
	END_STRUCT;

	McAdvCamAutSetParType : STRUCT
		ParLock : McCamAutParLockCmdEnum; (*Command for the transfer of the parameter*)
	END_STRUCT;

	McCamAutEventParType : STRUCT
	    Type : McCamAutEventTypeEnum; (*Event type*)
	    Transition :	McCamAutEventTransitionEnum; (*Event transition*)
	    SynchronousUpdate: McSwitchEnum; (*Synchronous parameter update if event occurs*)
	    NextState : USINT; (*Index of the next state if the event occurs*)
	END_STRUCT;

	McCamAutCompParType : STRUCT
	    MasterCompDistance : LREAL; (*Compensation distance for the master axis [Measurement units of master]*)
	    SlaveCompDistance : LREAL; (*Compensation distance for the slave axis [Measurement units of slave]*)
	    MasterCamLeadIn : LREAL; (*Relative position at which the master axis enters the state [Measurement units of master]*)
	    MinMasterCompDistance : LREAL; (*Minimum compensation distance for the master axis [Measurement units of master]*)
	    MinSlaveCompDistance : LREAL; (*Minimum compensation distance for the slave axis [Measurement units of slave]*)
	    MaxSlaveCompDistance : LREAL; (*Maximum compensation distance for the slave axis [Measurement units of slave]*)
	    MinSlaveCompVelocity : REAL; (*Minimum velocity of the slave axis during compensation [Measurement units of slave/s]*)
	    MaxSlaveCompVelocity : REAL; (*Maximum velocity of the slave axis during compensation [Measurement units of slave/s]*)
	    MaxSlaveCompAccel1 : REAL; (*Maximum acceleration of the slave axis during compensation phase 1 [Measurement units of slave/s�]*)
	    MaxSlaveCompAccel2 : REAL; (*Maximum acceleration of the slave axis during compensation phase 2 [Measurement units of slave/s�]*)
	    SlaveCompJoltTime : REAL; (*Jerk time of the slave axis during compensation [s]*)
	    SlaveCompJerk : REAL; (*Jerk of the slave axis during compensation [Measurement units of slave/s�]*)
	END_STRUCT;

	McCamAutMasterAxisType : STRUCT
		Axis : REFERENCE TO McAxisType; (*Axis reference of master axis*)
		ValueSource : McValueSrcEnum ; (*Defines the source of the position to be read*)
		MaxVelocity : REAL; (*Maximum velocity of the master axis [Measurement units of master/s]*)
	END_STRUCT;

	McCamAutMasterVarType : STRUCT
		VariableAddress  :  REFERENCE TO LREAL; (*Address of the process variable*)
		MaxVelocity : REAL; (*Maximum velocity of the master axis [Measurement units of master/s]*)
	END_STRUCT;

	McCamAutAxisType : STRUCT
		Axis : REFERENCE TO McAxisType; (*Axis reference*)
		ValueSource : McValueSrcEnum ; (*Defines the source of the position to be read*)
	END_STRUCT;

	McCamAutVariableType : STRUCT
		VariableAddress  :  REFERENCE TO LREAL; (*Address of the process variable*)
	END_STRUCT;

	McCamAutAdvStateParType : STRUCT
	    RepeatCounterInit : UINT; (*Starting value of state repetitions for event mcACPAX_EVENT_COUNT*)
	    RepeatCounterSetTransfer : McSwitchEnum; (*"RepeatCounterInit" is transferred*)
	    RepeatCounterSet : UINT; (*State repetitions counter for event mcACPAX_EVENT_COUNT*)
	    MasterSource : McCamAutCouplingSourceEnum; (*Source to be used as master of this state*)
	    MasterAxis : McCamAutAxisType; (*Master axis for this state*)
	    MasterVariable : McCamAutVariableType; (*Process variable that is used as master position for this state*)
	END_STRUCT;

	McCamAutStateParType : STRUCT
	    CamID : UINT; (*Index of the cam data for a state*)
	    MasterFactor : DINT; (*Master gauge factor for the cam profile for this state*)
	    SlaveFactor: DINT; (*Slave gauge factor for the cam profile for this state*)
	    CompensationMode : McCamAutCompModeEnum; (*Compensation gear mode*)
	    CompensationParameters : McCamAutCompParType; (*Parameters for the compensation gear*)
	    AdvancedParameters : McCamAutAdvStateParType; (*Advanced state parameter*)
	    Event : ARRAY[0..4] OF McCamAutEventParType; (*Definition of the event for a state*)
	END_STRUCT;

	McCamAutCtrlSettingsType : STRUCT
	    CrossLeftBoundary : McCamAutCrossLeftBoundEnum; (*Function on the left cam edge during backward movement of the master without event mcEVENT_STATE_END_NEGATIVE*)
	    CamChangeImmediately : McCamAutCamChangeImmedEnum; (*Direction of the cam change on event transition mcEVENT_IMMEDIATELY*)
	END_STRUCT;

	McCamAutStartStateParType : STRUCT
	    StartState : USINT; (*State in which the cam automat is started*)
	    MasterStartRelPos : LREAL; (*Master position within the starting state at which the cam automat is started [measurements units of the master]*)
	END_STRUCT;

	McCamAutAddAxesType : STRUCT
	    AdditiveMasterSource : McCamAutCouplingSourceEnum; (*Source to be used as additive master*)
	    AdditiveMasterAxis : McCamAutAxisType; (*Additive master axis*)
	    AdditiveMasterVariable : McCamAutVariableType; (*Process variable specifying the additive master position*)
	    AdditiveSlaveSource : McCamAutCouplingSourceEnum; (*Source to be used as additive slave*)
	    AdditiveSlaveAxis : McCamAutAxisType; (*Additive slave axis*)
	    AdditiveSlaveVariable : McCamAutVariableType; (*Process variable specifying the additive slave position*)
	END_STRUCT;

	McCamAutAdvParType : STRUCT
		StartStateParam : McCamAutStartStateParType; (*Parameter used for starting directly from a state*)
		AdditiveAxes : McCamAutAddAxesType; (*Parameter for additive axes*)
	    MasterStartPosMode : McCamAutMaStartPosModeEnum; (*Mode for event type mcEVENT_START_POSITION*)
	    ControlSettings : McCamAutCtrlSettingsType; (*Control settings for cam automat*)
	    StartIntervalPos1 : LREAL; (*Relative starting positions of the master axis in the interval for generating event mcEVENT_START_IV_POS1 [Measurement units of master]*)
	    StartIntervalPos2 : LREAL; (*Relative starting positions of the master axis in the interval for generating event mcEVENT_START_IV_POS2 [Measurement units of master]*)
	    StartIntervalPos3 : LREAL; (*Relative starting positions of the master axis in the interval for generating event mcEVENT_START_IV_POS3 [Measurement units of master]*)
	    StartIntervalPos4 : LREAL; (*Relative starting positions of the master axis in the interval for generating event mcEVENT_START_IV_POS4 [Measurement units of master]*)
	END_STRUCT;

	McCamAutMasterParType : STRUCT
	    MasterSource : McCamAutCouplingSourceEnum; (*Source to be used as master*)
	    MasterAxis : McCamAutMasterAxisType; (*Master axis*)
	    MasterVariable : McCamAutMasterVarType; (*Process variable specifying the master position*)
	    MasterStartPosition : LREAL; (*Starting position of the master axis [Measurement units of master]*)
	    MasterStartInterval : LREAL; (*Starting interval of the master axis [Measurement units of master]*)
	END_STRUCT;

	McCamAutCommonParType : STRUCT
	    Master : McCamAutMasterParType; (*Parameter for the cam automat master*)
	    AdvancedParameters : McCamAutAdvParType; (*Optional parameter for the cam automat*)
	END_STRUCT;

	McCamAutParType : STRUCT
	    Common : McCamAutCommonParType; (*General parameter for all states of the cam automat*)
	    State : ARRAY[0..14] OF McCamAutStateParType; (*Parameter for the states of the cam automat*)
	END_STRUCT;

	McCamAutDefineType : STRUCT
	    DataObjectName : STRING[32]; (*Name of the cam automat configuration object*)
	    DataAddress : UDINT; (*Address of a variable of data type McCamAutParType or McAcpAxCamAutParType*)
		DataSize: UDINT; (*Address of the cam data, 0 considered as use of McCamAutParType"*)
	END_STRUCT;

	McPolynomialDataType : STRUCT  (*Structure with polynomial coefficient*)
		A : REAL; (*Polynomial coefficient*)
		B : REAL; (*Polynomial coefficient*)
		C : REAL; (*Polynomial coefficient*)
		D : REAL; (*Polynomial coefficient*)
		E : REAL; (*Polynomial coefficient*)
		F : REAL; (*Polynomial coefficient*)
		G : REAL; (*Polynomial coefficient*)
		X : REAL; (*Maximum master position*)
		Reserve : UDINT; (*= 0 (Reserve)*)
	END_STRUCT;

	McCamDataType : STRUCT  (*Structure with cam data*)
		MasterPeriod : DINT; (*Length of the master period*)
		SlavePeriod : DINT; (*Length of the slave period*)
		PolynomialNumber : UDINT; (*Number of polynomials: 1..128*)
		PolynomialData : ARRAY[0..127] OF McPolynomialDataType; (*Polynomial coefficient*)
	END_STRUCT;

	McAdvCalcCamFromPointsParType : STRUCT
 		InterpolationMode 	: McCamIplModeEnum; (*Interpolation mode*)
 		Type 				: McCamTypeEnum; (*Periodic or non-periodic operation*)
 		NumberOfPolynomials : UDINT; (*Maximum number of calculated polynomials: 1 .. 128*)
 		MasterPeriod 		: DINT; (*Length of the master period*)
 		StartSlope 			: LREAL; (*Slope (velocity) at the beginning of the curve*)
 		StartCurvature 		: LREAL; (*Curvature (acceleration) at the beginning of the curve*)
 		EndSlope 			: LREAL; (*Slope (velocity) at the end of the curve*)
 		EndCurvature 		: LREAL; (*Curvature (acceleration) at the end of the curve*)
 	END_STRUCT;

 	McCamSectionType : STRUCT
 		MasterPoint		: REAL; (*Master position of the section*)
 		SlavePoint		: REAL; (*Slave position of the section*)
 		FirstDerivative		: REAL;  (*Velocity of the section*)
 		SecondDerivative	: REAL;  (*Acceleration of the section*)
 		Mode				: McCamSectRefPointEnum; (*Specification if master and slave position is used absolute or relative*)
 		Type				: McCamSectLawOfMotionEnum; (*Law of motion, defines the number of used polynomials*)
 		InflectionPoint		: REAL; (*Master position of the point of inflection*)
 	END_STRUCT;

 	McCamSectionsType : STRUCT
		Section : ARRAY[0..129] OF McCamSectionType; (*Data of one point and the following part*)
 	END_STRUCT;

 	McAdvCamInLeadInOutParType : STRUCT
		MasterOffset : LREAL; (*Master position in the cam at which the lead-in movement ends or the lead-out movement starts [Measurement units of master]*)
		MasterDistance : LREAL; (*Master compensation distance outside the cam for lead-in or lead-out movement [Measurement units of master]*)
		SlaveDistance : LREAL; (*Slave compensation distance for the lead-in or lead-out movement [Measurement units of slave]*)
		CamID : UINT; (*ID of the cam for the lead-in or lead-out movement*)
		MasterScaling : DINT; (*Master gauge factor for the lead-in or lead-out cam*)
		SlaveScaling : DINT; (*Slave gauge factor for the lead-in or lead-out cam*)
		Jerk : REAL; (*Maximum jerk of the slave axis [Measurement units of slave/s�]*)
	END_STRUCT;

	McAdvBrCamInParType : STRUCT
		Mode : McAdvCamInModeEnum; (*Mode for EnterCam and ExitCam*)
		LeadIn : McAdvCamInLeadInOutParType; (*Parameters for lead-in movement*)
		LeadOut : McAdvCamInLeadInOutParType; (*Parameters for lead-out-movement*)
		MasterValueSource : McValueSrcEnum; (*Defines the source of the position to be read*)
		MasterMaxVelocity : REAL; (*Maximum velocity of the master axis [Measurement units of master/s]*)
		Jerk : REAL; (*Maximum jerk of the slave axis [Measurement units of slave/s�]*)
		Deceleration : REAL; (*Maximum deceleration [Measurement units of slave/s�]*)
	END_STRUCT;

	McTriggerType : STRUCT
		ValueSource : McValueSrcEnum; (*Value source selection*)
		EventSource : McEventSrcEnum; (*Trigger event source selection*)
		Edge : McEdgeEnum; (*Trigger event edge selection*)
		TouchProbeID : USINT; (*Instance number of TouchProbe function on the selected axis*)
	END_STRUCT;

	McBrTriggerType : STRUCT
		ValueSource : McValueSrcEnum; (*Data value source selection*)
		EventSource : McEventSrcEnum; (*Trigger event source selection*)
		Edge : McEdgeEnum; (*Trigger event edge selection*)
		MinWidth : LREAL; (*Minimum trigger event width for the event to be considered valid [Measurement units]*)
		MaxWidth : LREAL; (*Maximum trigger event width for the event to be considered valid [Measurement units]*)
		SensorDelay : REAL; (*Trigger event signal sensor delay [s]*)
		DisableWidthEvaluationAtStart : BOOL; (*Ignore width monitoring if the function block is enabled on the high level of the trigger signal*)
	END_STRUCT;

	McAdvBrTouchProbeParType : STRUCT
		UseFirstTriggerPosition : BOOL; (*Capture position upon first trigger event*)
		UseAxisPeriod : BOOL; (*Use axis period for window period*)
		UpdatePeriod : BOOL; (*Detect and adapt to change of input "Period"*)
		ReadTriggerWidth : BOOL; (*Enable reading and updating the "TriggerInfo.Width" value*)
	END_STRUCT;

	McBrTriggerInfoType : STRUCT
		Width : LREAL; (*Measured width (size) of the trigger event [Measurement units]*)
		Status : McBrTriggerInfoStatusEnum; (*Status of the trigger event*)
	END_STRUCT;

	McDigCamSwitchOptionsParType : STRUCT
		DataSet : ARRAY[0..4] OF McDigCamSwDataSetParType; (*Reference to the switch data*)
		Period : LREAL; (*Period if an non periodic axis is used or an other period should be used*)
		StartPosition : LREAL; (*Start position of the cam switch*)
	END_STRUCT;

	McDigCamSwDataSetParType : STRUCT
		NumberOfSwitches : USINT; (*Number of switches with are used*)
		SwitchPositions : ARRAY[0..63] OF McDigCamSwOnPositionsParType; (*Array with the switching positions*)
	END_STRUCT;

	 McDigCamSwOnPositionsParType : STRUCT
		FirstOnPosition : LREAL; (*Lower limit at which the switch is on [Measurement units]*)
		LastOnPosition : LREAL; (*Upper limit at which the switch is on [Measurement units]*)
	 END_STRUCT;

	McDigCamSwTrackOptionsParType : STRUCT
		OnCompensation : REAL; (*Compensation time for the switch-on delay [s]*)
		OffCompensation : REAL; (*Compensation time for the switch-off delay [s]*)
		Filter : REAL; (*Filter time constant (for speed generation to compensate for switching delays) [s]*)
		Hysteresis : REAL; (*Interval from the switching point (in the positive and negative direction) during which the output is not switched until the axis leaves this area. This prevents switching from taking place several times around the switching point [Measurement units]*)
		DisableNegativeDirection : BOOL; (*If this input is set, switching edges are only generated if the master axis is moving in the positive direction*)
	END_STRUCT;

	McDigCamSwOptionsParType : STRUCT
		FeatureName : STRING[250]; (*Name of the "Digital cam switch" feature The feature must be assigned to the axis as well inside the hardware configuration*)
	END_STRUCT;

	McAdvCamAutPrepRestartParType : STRUCT
	 	ToleranceWindow : LREAL; (*Tolerance window, used by several prepare restart modes [Measurement units]*)
		RestartPositionOffset : LREAL; (*Offset applied in addition to the current position got from cam automat [Measurement units]*)
	END_STRUCT;

	McCamAutPrepRestartModeEnum:
	(
		mcPREP_RESTART_POSITIVE, (*Slave axis moves to "RestartPosition" only in positive direction*)
		mcPREP_RESTART_NEGATIVE, (*Slave axis moves to "RestartPosition" only in negative direction*)
		mcPREP_RESTART_SHORTEST_WAY, (*Slave axis moves to "RestartPosition" by the shortest distance*)
		mcPREP_RESTART_POSITIVE_WINDOW, (*Slave moves to "RestartPosition" by the shortest distance when distance is smaller than "ToleranceWindow", otherwise only in positive direction*)
		mcPREP_RESTART_NEGATIVE_WINDOW, (*Slave moves to "RestartPosition" by the shortest distance when distance is smaller than "ToleranceWindow", otherwise only in negative direction*)
		mcPREP_RESTART_GET_POSITION (*"RestartPosition" is output, no movement is performed*)
	);

	McAdvCyclicTorqueFFParType : STRUCT
		DisableMode : McDisableModeEnum; (*Defines the behavior at disable*)
	END_STRUCT;

	McAdvBrCamTransLeadInOutParType : STRUCT
		MasterDistance : LREAL; (*Master compensation distance outside the cam for lead-in or lead-out movement [Measurement units of master]*)
		SlaveDistance : LREAL; (*Slave compensation distance for the lead-in or lead-out movement [Measurement units of slave]*)
		MasterOffset : LREAL; (*Master position in the cam at which the lead-in movement ends or the lead-out movement starts [Measurement units of master]*)
		Jerk : REAL; (*Maximum jerk of the slave axis [Measurement units of slave/s�]*)
	END_STRUCT;

	McAdvBrCamDwellParType : STRUCT
		LeadIn : McAdvBrCamTransLeadInOutParType; (*Parameters for lead-in movement*)
		LeadOut : McAdvBrCamTransLeadInOutParType; (*Parameters for lead-out movement*)
		MasterValueSource : McValueSrcEnum; (*Defines the source of the master axis position to be used*)
		MasterMaxVelocity : REAL; (*Maximum velocity of the master axis [Measurement units of master/s]*)
		Jerk : REAL; (*Maximum jerk of the slave axis [Measurement units of slave/s�]*)
		Deceleration : REAL; (*Maximum deceleration [Measurement units of slave/s�]*)
	END_STRUCT;

	McAdvBrAutoCamDwellParType : STRUCT
		LeadIn : McAdvBrCamTransLeadInOutParType; (*Parameters for lead-in movement*)
		LeadOut : McAdvBrCamTransLeadInOutParType; (*Parameters for lead-out movement*)
		MasterValueSource : McValueSrcEnum; (*Defines the source of the master axis position to be used*)
		MasterMaxVelocity : REAL; (*Maximum velocity of the master axis [Measurement units of master/s]*)
		Jerk : REAL; (*Maximum jerk of the slave axis [Measurement units of slave/s�]*)
		Deceleration : REAL; (*Maximum deceleration [Measurement units of slave/s�]*)
	END_STRUCT;

	McAdvBrCamTransCamModeEnum:
	(
		mcCAM_MODE_DISTANCE_BASED, (*Constant master distance*)
		mcCAM_MODE_TIME_BASED (*Constant time*)
	);

	McAdvBrCamTransTransModeEnum:
	(
		mcCAM_TRANS_MODE_OFF, (*Only the synchronous cam is repeated cyclically*)
		mcCAM_TRANS_MODE_ON, (*The synchronous cam - compensating movement (transition) sequence is repeated cyclically*)
		mcCAM_TRANS_MODE_OFF_LEAD_IN , (*The synchronous cam is repeated cyclically and lead-in movement is performed before entering cam. No lead-out movement is executed*)
		mcCAM_TRANS_MODE_OFF_LEAD_OUT, (*The synchronous cam is repeated cyclically and lead-out movement is performed when exiting the cam. No lead-in movement is executed*)
		mcCAM_TRANS_MODE_OFF_LEAD_IN_OUT, (*The synchronous cam is repeated cyclically. Lead-in movement is performed before entering the cam. Lead-out movement is performed when exiting the cam*)
		mcCAM_TRANS_MODE_ON_LEAD_IN, (*In this mode, the synchronous cam - compensating movement (transition) sequence is repeated cyclically. Lead-in movement is performed before entering the cam. No lead-out movement is performed*)
		mcCAM_TRANS_MODE_ON_LEAD_OUT, (*The synchronous cam - compensating movement (transition) sequence is repeated cyclically. Lead-out movement is performed when exiting the cam. No lead-in movement is performed*)
		mcCAM_TRANS_MODE_ON_LEAD_IN_OUT (*The synchronous cam - compensating movement (transition) sequence is repeated cyclically. Lead-in movement is performed before entering the cam. Lead-out movement is performed when exiting the cam*)
	);

	McAdvBrCamTransitionParType : STRUCT
		LeadIn : McAdvBrCamTransLeadInOutParType; (*Parameters for lead-in movement*)
		LeadOut : McAdvBrCamTransLeadInOutParType; (*Parameters for lead-out movement*)
		MasterValueSource : McValueSrcEnum; (*Defines the source of the master axis position to be used*)
		MasterMaxVelocity : REAL; (*Maximum velocity of the master axis [Measurement units of master/s]*)
		CamTime : REAL; (*Time for the synchronous curve [s]*)
		CamMode : McAdvBrCamTransCamModeEnum; (*Mode for synchronous curve*)
		TransitionMode :  McAdvBrCamTransTransModeEnum; (*Mode for compensation phases*)
		Jerk : REAL; (*Maximum jerk of the slave axis [Measurement units of slave/s�]*)
		Deceleration : REAL; (*Maximum deceleration [Measurement units of slave/s�]*)
	END_STRUCT;

	McBrAdvCamSaveDatObjType : STRUCT
		DataObjectVersion : UINT; (*Version of the saved data object (four digits)*)
	END_STRUCT;

	McEventType : STRUCT
		Event : McEventSrcEnum; (*Event source selection*)
		Edge : McEdgeEnum; (*Defines if the rising or falling edge should be used for the event*)
	END_STRUCT;

	McAdvEventMoveParType : STRUCT
		Mode : McEventMoveModeEnum; (*Operation mode*)
		AlternativeValueSource : McAltValueSrcEnum; (* If used, defines the alternative source of: position for MC_BR_EventMoveAbsolute, distance for MC_BR_EventMoveAdditive, velocity for MC_BR_EventMoveVelocity from which target value is read (Axis Units)*)
	END_STRUCT;

	McDigitalInputsPvIfType : STRUCT
        HomingSwitch : BOOL; (*Variable for homing switch input functionality*)
        PositiveLimitSwitch : BOOL; (*Variable for positive limit switch input functionality*)
        NegativeLimitSwitch : BOOL; (*Variable for negative limit switch input functionality*)
        Trigger1 : BOOL; (*Variable for trigger 1 input functionality*)
        Trigger2 : BOOL; (*Variable for trigger 2 input functionality*)
        Quickstop : BOOL; (*Variable for quickstop input functionality*)
    END_STRUCT;

	McAdvBrTorqueControlParType : STRUCT
		NoHomingCheck : BOOL; (*No check for completed prior homing.*)
		UseVelocityLimits : BOOL; (*Use axis velocity limits.*)
		CorrectVelocityLimits : BOOL; (*Automatically correct velocity limits.*)
		UseTimeLimit : BOOL; (*Automatic cutoff after time if no load or load too low.*)
		TimeLimit : REAL; (*Time limit for how long the axis can move at the speed or acceleration limit before it is stopped automatically [s].*)
	END_STRUCT;

	McLimitLoadModeEnum :
		(
		mcLL_WITH_FEED_FORWARD,    (*control deviation torque AND feed forward torque are limited (overall torque) *)
		mcLL_WITHOUT_FEED_FORWARD  (*control deviation torque only is limited; feed forward torque component is not limited *)
		);

	McAdvBrLimitLoadCamParType : STRUCT
		PositionFactorPos : DINT; (*Multiplication factor of the axis position for the positive direction *)
		LoadFactorPos : DINT; (*Multiplication factor of the torque for the positive direction *)
		PositionFactorNeg : DINT; (*Multiplication factor of the axis position for the negative direction *)
		LoadFactorNeg : DINT; (*Multiplication factor of the torque for the negative direction *)
	END_STRUCT;

	McAcpAxAutoTuneOrientationEnum:
	(
		mcACPAX_ORIENTATION_HORIZONTAL,  (*Horizontal orientation*)
		mcACPAX_ORIENTATION_VERTICAL     (*Vertical orientation*)
	);

	McAcpAxFilterTimeModeEnum:
	(
		mcACPAX_FILTER_TIME_USE,  (*The determination of filter time constants is disabled; however, filter time constants are taken into account for autotuning*)
		mcACPAX_FILTER_TIME_TUNE_MODE1,  (*The controlled variable is the unfiltered actual speed n*)
		mcACPAX_FILTER_TIME_TUNE_MODE2   (*The controlled variable is the filtered actual speed n*)
	);

	McAcpAxLoopFilterModeEnum:
	(
		mcACPAX_LOOP_FILTER_IGNORE,  (*Loop filters are neither taken into account nor calculated.*)
		mcACPAX_LOOP_FILTER_USE,  (*The parameters for all loop filters are taken into account for autotuning*)
		mcACPAX_LOOP_FILTER_TUNE_NOTCH  (*The parameters for the loop filter are calculated*)
	);

	McMechDevCompCmdEnum:
	(
		mcMDC_CMD_SWITCH_ON, (*Functionality activation*)
		mcMDC_CMD_SWITCH_OFF, (*Functionality deactivation*)
		mcMDC_CMD_CALC_COMP_DATA (*Compensation data computation*)
	);

	McMechDevCompDataType : STRUCT
		Position : LREAL; (*Position [Measurement units]*)
		Deviation : LREAL; (*Deviation [Measurement units]*)
	END_STRUCT;

    McMechDevCompAdvParType : STRUCT
        DataObjectNamePos : STRING[12];
        DataObjectNameNeg : STRING[12];
    END_STRUCT;

    McMechDevCompAddInfoType : STRUCT
        CamStartPositionPos : LREAL;
        CamStartPositionNeg : LREAL;
    END_STRUCT;

    McHwInfoAxisType : STRUCT
        AxisName : STRING[32]; (*Name of the logical axis object*)
        ConfigElementLocation : STRING[250]; (*Location for MC_BR_ProcessConfig*)
        AxisType : McAxisTypeEnum; (*Detailed axis type*)
    END_STRUCT;

    McHwInfoDriveType : STRUCT
        ModelNumber : STRING[19]; (*Model number of the drive*)
        ModuleID : STRING[11]; (*For B&R modules: B&R ID code; For DS402 modules: Product code; [hex]*)
        SerialNumber : STRING[19]; (*Serial number of the drive*)
        Revision : STRING[3]; (*Revision number of the drive*)
        FirmwareVersion : STRING[7]; (*Used firmware version*)
    END_STRUCT;

    McHwInfoCardType : STRUCT
    	InfoAvailable : BOOL; (*Displays if the information is available*)
        ModelNumber : STRING[19]; (*Model number of the card*)
        SerialNumber : STRING[19]; (*Serial number of the card*)
        Revision : STRING[3]; (*Revision number of the card*)
    END_STRUCT;

    McHwInfoMotorType : STRUCT
    	InfoAvailable : BOOL; (*Displays if the information is available*)
        ModelNumber : STRING[35]; (*Model number of the motor*)
        SerialNumber : STRING[19]; (*Serial number of the motor*)
        Revision : STRING[3]; (*Revision number of the motor*)
    END_STRUCT;

    McHardwareInfoType : STRUCT
        Axis : McHwInfoAxisType; (*Detailed axis information*)
        Drive : McHwInfoDriveType; (*Detailed drive information*)
		Card : ARRAY[0..3] OF McHwInfoCardType; (*Detailed card information*)
        Motor : ARRAY[0..2] OF McHwInfoMotorType; (*Detailed motor information*)
    END_STRUCT;

END_TYPE
