TYPE
	McAddGroupReadInfoType : 	STRUCT
		InMotion : BOOL; (*Axis of group is moving*)
		GroupInterrupted : BOOL; (*Group movement interrupted*)
		WaitForContinue : BOOL; (*Command "Continue" is expected (currently not implemented)*)
		PLCopenState :  McGroupPLCopenStateEnum; (*Extended PLCopen state*)
	END_STRUCT;

	McAdvGroupHome_15_Type : 	STRUCT
		HomingOrderSource : McHomingOrderSourceEnum; (*Source of the homing order*)
		HomingOrder : ARRAY[0..14]OF UINT; (*Specifies the homing order (see *)
	END_STRUCT;

 	McLimitMonPointsParType : 	STRUCT
		Velocity : REAL; (*Limiting velocity*)
	END_STRUCT;

	McLimitMonPointsInfoType : 	STRUCT
		Velocity : REAL; (*Limiting velocity*)
		LimitActive :   BOOL; (*Signaling that the limit is adhered to*)
	END_STRUCT;

	McHomingOrderSourceEnum :
		(
		mcHO_CONFIGURATION, (*Uses the homing order configured in the configuration*)
		mcHO_FUNCTIONBLOCK (*Uses the homing order configured in the function block*)
		);
	McBrakeSelectModeEnum :
	(
		mcBRAKESELECT_COMPOSITE					 (*Select a brake composite for the operation *)
	);
	McJogStatusEnum :
		(
		mcJOGSTATUS_DISABLED, (*Function block disabled*)
		mcJOGSTATUS_STANDSTILL, (*Function block enabled; no movement active*)
		mcJOGSTATUS_JOGGING, (*Jogging movement active*)
		mcJOGSTATUS_TARGET_REACHED, (*End position reached*)
		mcJOGSTATUS_AXES_VIOLATION, (*Axis limit reached*)
		mcJOGSTATUS_JOINTAXES_VIOLATION, (*Joint axis limit reached*)
		mcJOGSTATUS_SLAVEAXES_VIOLATION, (*Slave axis limit reached*)
		mcJOGSTATUS_WORKSPACE_VIOLATION, (*Workspace boundary reached*)
		mcJOGSTATUS_SAFESPACE_VIOLATION, (*Safe space workspace boundary reached*)
		mcJOGSTATUS_SELF_COLLISION, (*Self collision imminent*)
		mcJOGSTATUS_TARGET_NOT_REACHABLE, (*Mechanical limit reached*)
		mcJOGSTATUS_WORKRANGE_VIOLATION (*Working range boundary reached*)
		);
	McOverrideEnum :
		(
		mcOVERRIDE_VELOCITY, (*Velocity override*)
		mcOVERRIDE_VELOCITY_AXIS, (*Axis velocity override*)
		mcOVERRIDE_ACCELERATION, (*Acceleration override*)
		mcOVERRIDE_ACCELERATION_AXIS, (*Axis acceleration override*)
		mcOVERRIDE_JERK, (*Jerk override*)
		mcOVERRIDE_FEEDRATE := 10, (*Feed override*)
		mcOVERRIDE_RAPID, (*Rapid motion override*)
		mcOVERRIDE_SPINDLE, (*Spindle override*)
		mcOVERRIDE_TIMESTRETCH := 20 (*Time override*)
		);
	McMotionChainModuleEnum :
		(
		mcMCM_DEFAULT, (*Default motion chain module*)
		mcMCM_INTERPRETER (*Interpreter motion chain module*)
		);
	McSingleStepAdvParType : 	STRUCT
		Module : McMotionChainModuleEnum; (*Motion chain module Enumerator*)
	END_STRUCT;
	McPathInfoType : 	STRUCT
		CurrentPathVelocity : REAL; (*Current speed of path*)
		CurrentPathPosition : LREAL; (*Current path position*)
		CurrentLength : LREAL; (*Length of the path of the current movement (not currently available)*)
		RemainingDistance : LREAL; (*Distance remaining until the end of the current movement (not currently available)*)
		ProgrammedPathVelocity : REAL; (*Programmed speed of path*)
	END_STRUCT;
	McPrgAdvParType : 	STRUCT
		InitProgram : STRING[260]; (*Init programs*)
		StartMode : McPrgStartModeEnum; (*Defines the start mode of the program*)
		StartPointType : McPrgStartPointEnum; (*Defines the starting point type*)
		StartPointParameter : LREAL; (*Additional parameter for the starting point of the program*)
		RepositioningParameter : McPrgAxesReposParType; (*Parameter for repositioning the axes*)
		SaveRestartData : McSwitchEnum; (*Saves data for program restart*)
	END_STRUCT;
	McPrgAxesReposParType : 	STRUCT
		Type : McPrgAxesReposTypeEnum; (*Type of axis repositioning*)
		String : STRING[260]; (*String parameter (e.g. name of the program)*)
		AxisVelocityFactor : REAL; (*Single axis velocity for mcPRGRP_SINGLE_AXIS_AUTOMATIC*)
	END_STRUCT;
	McPrgAxesReposTypeEnum :
		(
		mcPRGRP_SINGLE_AXIS, (*The axes are positioned by single-axis movements*)
		mcPRGRP_PROGRAM, (*The axes are positioned by a program*)
		mcPRGRP_SINGLE_AXIS_AUTOMATIC (*The axes are positioned automatically*)
		);
	McPrgInfoBlockMonitorType : 	STRUCT
		SecondLast : STRING[260]; (*Line before previous line in the program*)
		Last : STRING[260]; (*Previous line in the program*)
		Current : STRING[260]; (*Current line in the program*)
		Next : STRING[260]; (*Next line in the program*)
		SecondNext : STRING[260]; (*Line after the next line in the program*)
	END_STRUCT;
	McPrgInfoPrgMonitorType : 	STRUCT
		LineNumber : UDINT; (*Current line number*)
		BlockNumber : UDINT; (*Current block number*)
		OverallRuntime : LREAL; (*Current program execution time*)
		MovementRuntime : LREAL; (*Current duration of the movements in the program*)
		CurrentDwellTime : LREAL; (*Current active dwell time*)
		RemainingDwellTime : LREAL; (*Remaining dwell time*)
		BlockMonitor : McPrgInfoBlockMonitorType; (*Block monitor information*)
	END_STRUCT;
	McPrgInfoType : 	STRUCT
		MainProgram : STRING[260]; (*Name of the current main routine*)
		InitProgram : STRING[260]; (*Name of the current initialization subroutine*)
		CurrentProgram : STRING[260]; (*Name of the currently running subroutine*)
		ProgramMonitor : McPrgInfoPrgMonitorType; (*Program monitor information*)
		ProgramPhase : McPrgPhaseEnum; (*Program phase (not currently implemented)*)
		InterruptStatus : McPrgInfoInterruptEnum; (*Interrupt status*)
	END_STRUCT;
	McToolParType : 	STRUCT
		Geometry : McToolGeometryType; (*geometry for tool fubs*)
	END_STRUCT;
	McToolGeometryType : 	STRUCT
		Radius : LREAL; (*tool - radius*)
		Length : LREAL; (*tool - length*)
		Translation : McToolTranslationType; (*tool - trans*)
		Orientation : McToolOrientationType; (*tool - orient*)
		VirtualToolTip : McToolVirtualToolTipPositionEnum; (*tool - virttooltip*)
	END_STRUCT;
	McToolTranslationType : 	STRUCT
		X : LREAL; (*tool - x*)
		Y : LREAL; (*tool - y*)
		Z : LREAL; (*tool - z*)
	END_STRUCT;
	McToolOrientationType : 	STRUCT
		Angle1 : LREAL; (*tool - angle1*)
		Angle2 : LREAL; (*tool - angle2*)
		Angle3 : LREAL; (*tool - angle3*)
	END_STRUCT;
	McToolVirtualToolTipPositionEnum :
		(
		mcTOOL_VIRTUAL_TOOL_TIP_POS0,
		mcTOOL_VIRTUAL_TOOL_TIP_POS1,
		mcTOOL_VIRTUAL_TOOL_TIP_POS2,
		mcTOOL_VIRTUAL_TOOL_TIP_POS3,
		mcTOOL_VIRTUAL_TOOL_TIP_POS4,
		mcTOOL_VIRTUAL_TOOL_TIP_POS5,
		mcTOOL_VIRTUAL_TOOL_TIP_POS6,
		mcTOOL_VIRTUAL_TOOL_TIP_POS7,
		mcTOOL_VIRTUAL_TOOL_TIP_POS8,
		mcTOOL_VIRTUAL_TOOL_TIP_POS9
		);

	McPrgPhaseEnum :
		(
		mcPRGPH_INACTIVE, (*Program not active*)
		mcPRGPH_SIMULATION_RUN, (*Program is running in simulation mode*)
		mcPRGPH_WAIT_FOR_AXES_REPOS, (*The program is waiting for the axes to be positioned at their starting points*)
		mcPRGPH_AXES_REPOS, (*The axes are being positioned at their starting points*)
		mcPRGPH_WAIT_FOR_REAL_RUN, (*The program is waiting for the command to resume execution*)
		mcPRGPH_REAL_RUN (*The program is active*)
		);
	McPrgStartModeEnum :
		(
		mcPRGSM_NON_MODAL, (*Non-modal start mode*)
		mcPRGSM_MODAL, (*Modal start mode*)
		mcPRGSM_RESTART, (*Starts the program using the saved restart data*)
		mcPRGSM_SIMULATION (*High-precision simulation*)
		);
	McPrgStartPointEnum :
		(
		mcPRGSP_STANDARD, (*Start at beginning*)
		mcPRGSP_BLOCK_NUMBER, (*Start at specified block number*)
		mcPRGSP_ABORT_LINE, (*Start at the line number at which the program aborted*)
		mcPRGSP_ABORT_POINT, (*Start at the point where the program aborted*)
		mcPRGSP_LINE_NUMBER := 5, (*Start at the specified line number*)
		mcPRGSP_PATH_DISTANCE_LINE (*Start at line in which the specified path is reached*)
		);
	McPrgInfoInterruptEnum :
		(
			mcINTERRUPT_NOT_INTERRUPTED,	(*The program has not been interrupted*)
			mcINTERRUPT_SINGLESTEP,			(*The program has been interrupted by activation of single-step mode*)
			mcINTERRUPT_FB,					(*The program has been interrupted by the "MC_GroupInterrupt" function block*)
			mcINTERRUPT_INTERPRETER,		(*The program has been interrupted by an interpreter halt (G170)*)
			mcINTERRUPT_MFUNCTION,			(*The program has been interrupted by a blocking M-code*)
			mcINTERRUPT_PROGRAM				(*The program has been interrupted by a programmed command*)
		);
	McJogPathLimitsType : 	STRUCT
		Velocity : REAL; (*Tool path feed rate*)
		Acceleration : REAL; (*Path acceleration*)
		Deceleration : REAL; (*Path deceleration*)
		Jerk : REAL; (*Path jerk*)
	END_STRUCT;
	McManualMoveTypeEnum :
		(
			mcMOVE_ABSOLUTE := 0, (*Absolute movement*)
			mcMOVE_RELATIVE := 1  (*Relative movement*)
		);
	McLoadProgramModeEnum :
		(
			mcLOADPRG_PROGRAM, (*Regular program with visible code, kept in the memory*)
			mcLOADPRG_SYSTEM   (*Load as a system file*)
		);
	McUnloadProgramModeEnum :
		(
			mcUNLOADPRG_PROGRAM, (*Unload program of given name*)
			mcUNLOADPRG_ALL      (*Unload all programs*)
		);
		McToolDynamicsType : 	STRUCT  (*Tool dynamic parameters*)
		Mass : LREAL; (*Tool mass [kg]*)
		CenterOfGravity : McToolTranslationType; (*Tool center of gravity [m]*)
		MomentOfInertiaAbout : McToolTranslationType; (*Tool moment of interia about XYZ [kgm2]*)
	END_STRUCT;
	McToolWireFrameType : 	STRUCT  (*Tool wire frame description*)
		Point : ARRAY[0..15]OF McToolWireFramePointType; (*Tool wire frame points*)
	END_STRUCT;
	McToolWireFramePointTypeEnum :
		(
		mcTOOL_WF_TYPE_DISABLED, (*Not active wire frame point*)
		mcTOOL_WF_TYPE_CONNECTION_LINE, (*Connection line between previous point n-1 (or flange, if it is the starting point) and point n.*)
		mcTOOL_WF_TYPE_POINT, (*Point n is defined by translation x, y, z applied outward from the flange*)
		mcTOOL_WF_TYPE_NOT_USED (*Point P1 is defined by translation x, y, z applied outward from the flange. "Not used" means that the point is not used for the wireframe model unless subsequent point n+1 is of type connecting line.*)
		);
	McToolWireFramePointType : 	STRUCT
		Type : McToolWireFramePointTypeEnum := mcTOOL_WF_TYPE_DISABLED; (*Type of point*)
		Translation : McToolTranslationType; (*Translation parameters*)
		Distance : LREAL; (*Edge distance to prevent collisions*)
	END_STRUCT;
END_TYPE
