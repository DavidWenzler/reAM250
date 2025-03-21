(*Single-Axis Function Blocks*)

FUNCTION_BLOCK MC_BR_GetAxisLibraryInfo (*commands a controlled motion to a specified absolute position.*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
		Info : McLibraryInfoType; (*implementation lib of the axis*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Power (*switches on the controller of the axis*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
    END_VAR
    VAR_OUTPUT
        Status : BOOL; (*effective status of the power stage*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Home (*start the homing movement of an axis according to the homing parameters*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
        Position : LREAL; (*absolute position when the reference signal is detected*)
        HomingMode : McHomingModeEnum; (*select the homing mode*)
        BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*execution successful. FB finished*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Active : BOOL; (*FB has control over the axis*)
        CommandAborted : BOOL; (*Command was aborted by another command*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_BrakeOperation (*to operate the brake and get the brake status*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
        Command : McBrakeCmdEnum; (*select the brake command*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*execution successful. FB finished*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        BrakeStatus : McBrakeStatusEnum; (*shows the brake status*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Stop (*commands a controlled motion stop and transfers the axis to the state Stopping*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
        Deceleration : REAL; (*value of deceleration*)
	Jerk : REAL; (*maximum jerk*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*execution successful. FB finished*)
        Busy : BOOL; (*FB is active and needs to be called*)
        CommandAborted : BOOL; (*Command was aborted by another command*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Halt (*commands a controlled motion stop.*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
        Deceleration : REAL; (*value of deceleration*)
		Jerk : REAL; (*maximum jerk*)
        BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*execution successful. FB finished*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Active : BOOL; (*FB has control over the axis*)
        CommandAborted : BOOL; (*Command was aborted by another command*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamAutomatCommand (*send command for the cam automat to the drive*)
	VAR_INPUT
		Slave : REFERENCE TO McAxisType; (*axis reference*)
		Enable : BOOL; (*when set commands can be given*)
		Deceleration : REAL; (*maximum deceleration*)
		Start : BOOL; (*starts the cam automat*)
		Stop : BOOL; (*stops the movement on the slave axis*)
		Restart : BOOL; (*restarts a cam automat which is in stand by*)
		EndAutomat : BOOL; (*finishes the execution of the cam automat*)
		SetSignal1 : BOOL; (*sets signal 1 of the cam automat*)
		SetSignal2 : BOOL; (*sets signal 2 of the cam automat*)
		SetSignal3 : BOOL; (*sets signal 3 of the cam automat*)
		SetSignal4 : BOOL; (*sets signal 4 of the cam automat*)
		ResetSignal1 : BOOL; (*resets signal 1 of the cam automat*)
		ResetSignal2 : BOOL; (*resets signal 2 of the cam automat*)
		ResetSignal3 : BOOL; (*resets signal 3 of the cam automat*)
		ResetSignal4 : BOOL; (*resets signal 4 of the cam automat*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*output values are valid*)
		Busy : BOOL; (*FB is active and needs to be called*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
		Running : BOOL; (*automat is currently running*)
		StandBy : BOOL; (*automat is in standby and can be restarted*)
		ActualStateIndex : USINT; (*index of the actual cam automat state*)
		ActualStateCamIndex : UINT; (*index of the cam of the actual cam automat state*)
		InCam : BOOL; (*cam in the current cam automat state is active*)
		InCompensation : BOOL; (*compensation in the current cam automat state is active*)
		Ready : BOOL; (*command can be given*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamAutomatReset (*send reset command for the cam automat to the drive*)
	VAR_INPUT
		Slave : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Command : McCamAutResetCmdEnum; (*command for reset*)
		StateIndex : USINT; (*index of state which should be reset*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamAutomatParLock (*send parlock command for the cam automat to the drive*)
	VAR_INPUT
		Slave : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Command : McCamAutParLockCmdEnum; (*command for reset*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_MoveAbsolute (*commands a controlled motion to a specified absolute position.*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Position : LREAL; (*target position for the motion*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		Direction : McDirectionEnum; (*movement direction*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_MoveAdditive (*commands a motion of a specified relative distance*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Distance : LREAL; (*relative distance for the motion*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_MoveVelocity (*commands a motion with specific velocity*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		Direction : McDirectionEnum; (*movement direction*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
	END_VAR
	VAR_OUTPUT
		InVelocity : BOOL; (*Commanded velocity reached*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveCyclicPosition (*commands the axis to follow a cyclically transferred position*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
        InterpolationMode : McIplModeEnum; (*interpolation mode of cyclic position on receiving drive*)
        AdvancedParameters : McAdvMoveCycParType; (*structure for using additional functions*)
	CyclicPosition : LREAL; (*cyclic position that is transferred to the axis*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*initialization complete, position is beeing transferred cyclically*)
        Busy : BOOL; (*FB is active and needs to be called*)
        CommandAborted : BOOL; (*Command was aborted by another command*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType;(*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MoveCyclicVelocity (*commands the axis to follow a cyclically transferred velocity*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
        InterpolationMode : McIplModeEnum; (*interpolation mode of cyclic set value on receiving drive*)
        AdvancedParameters : McAdvMoveCycParType; (*structure for using additional functions*)
	CyclicVelocity : REAL; (*cyclic velocity that is transferred to the axis*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*initialization complete, velocity is beeing transferred cyclically*)
        Busy : BOOL; (*FB is active and needs to be called*)
        CommandAborted : BOOL; (*Command was aborted by another command*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType;(*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_SetOverride (*sets the values of override parameters for velocity and acceleration/deceleration*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
        VelFactor : REAL; (*New override factor for the velocity*)
        AccFactor : REAL; (*New override factor for the acceleration/deceleration*)
    END_VAR
    VAR_OUTPUT
        Enabled : BOOL; (*Signals that the override factors are set successfully.*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType;
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadStatus (*returns the detailed status of the motion currently in progress according to the State Diagram*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*the output values of the FB can be used*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        ErrorStop : BOOL; (*axis is in state Errorstop*)
        Disabled : BOOL; (*axis is in state Disabled*)
        Stopping : BOOL; (*axis is in state Stopping*)
        Homing : BOOL; (*axis is in state Homing*)
        StandStill : BOOL; (*axis is in state Standstill*)
        DiscreteMotion : BOOL; (*axis is in state DiscreteMotion*)
        ContinuousMotion : BOOL; (*axis is in state ContinuousMotion*)
        SynchronizedMotion : BOOL; (*axis is in state SynchronizedMotion*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadAxisInfo (*reads status information of the axis*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*the output values of the FB can be used*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        Simulation : BOOL; (*the motor is simulated*)
        CommunicationReady : BOOL; (*drive has a network connection*)
        ReadyForPowerOn : BOOL; (*controller can be switched on*)
        PowerOn : BOOL; (*controller is switched on*)
        IsHomed : BOOL; (*axis is homed*)
        AxisWarning : BOOL; (*a warning is active on the drive*)
        AdditionalInfo : McAddInfoType; (*additional information*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadActualPosition (*returns the actual axis position.*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*the output values of the FB can be used*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        Position : LREAL; (*actual position of the axis*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadActualVelocity (*returns the actual axis velocity.*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*the output values of the FB can be used*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        Velocity : REAL; (*actual velocity of the axis*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadActualTorque (*returns the actual axis torque.*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*the output values of the FB can be used*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        Torque : REAL; (*actual torque of the axis*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadAxisError (*reads an error number and deletes it from the error number FIFO*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
        ReadNext: BOOL; (* Error is deleted from the FIFO at rising edge*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*the output values of the FB can be used*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        AxisErrorID : DINT; (*error number of the drive error*)
        RecordID : DINT; (*ID of the event log entry*)
    END_VAR
    VAR
        Internal : McInternalType;
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_Reset (*makes the transition from the state ‘ErrorStop’ to ‘Standstill’ or ‘Disabled’*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Execute : BOOL; (*FB is active as long as input is set*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*execution successful. FB finished*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_VelocityControl (*sends cyclic speed set value for velocity control*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
        AdvancedParameters : McAdvVelCtrlParType; (*structure for using additional functions*)
        CyclicVelocity : REAL; (*parameter input for set speed*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*the output values of the FB can be used*)
        Busy : BOOL; (*FB is active and needs to be called*)
        CommandAborted : BOOL; (*Command was aborted by another command*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ReadCyclicPosition (*reads the high resoluted position of the axis cyclically*)
    VAR_INPUT
	Axis : REFERENCE TO McAxisType; (*axis reference*)
	Enable : BOOL; (*FB is active as long as input is set*)
	ValueSource : McValueSrcEnum; (*selection which position should be read*)
    END_VAR
    VAR_OUTPUT
	Valid : BOOL; (*the output values of the FB can be used*)
	Busy : BOOL; (*FB is active and needs to be called*)
	Error : BOOL; (*error occurred during operation*)
	ErrorID : DINT; (*error number*)
	CyclicPosition : LREAL; (*cyclic position that is read from the axis*)
    END_VAR
    VAR
	Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_ReadParameter (*reads the specified PLCopen Parameter*)
    VAR_INPUT
	Axis : REFERENCE TO McAxisType; (*axis reference*)
	Enable : BOOL; (*FB is active as long as input is set*)
	ParameterNumber : McPlcopenParEnum; (*number of the parameter*)
    END_VAR
    VAR_OUTPUT
	Valid : BOOL; (*the output value of the FB can be used*)
	Busy : BOOL; (*FB is active and needs to be called*)
	Error : BOOL; (*error occurred during operation*)
	ErrorID : DINT; (*error number*)
	Value : LREAL; (*value of parameter*)
    END_VAR
    VAR
	Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_JogVelocity (*enables and executes jog movements*)
    VAR_INPUT
	Axis : REFERENCE TO McAxisType; (*axis reference*)
	Enable : BOOL; (*FB is active as long as input is set*)
	Velocity : REAL; (*maximum velocity*)
	Acceleration : REAL; (*maximum acceleration*)
	Deceleration : REAL; (*maximum deceleration*)
	Jerk : REAL; (*maximum jerk*)
	JogPositive : BOOL; (*executes positive movement at high level*)
	JogNegative : BOOL; (*executes negative movement at high level*)
    END_VAR
    VAR_OUTPUT
	Ready : BOOL; (*function block is active*)
	Busy : BOOL; (*FB is active and needs to be called*)
	CommandAborted : BOOL; (*Command was aborted by another command*)
	Error : BOOL; (*error occurred during operation*)
	ErrorID : DINT; (*error number*)
	Jogging : BOOL; (*jog movement is active*)
    END_VAR
    VAR
	Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_JogLimitPosition (*enables and executes jog movements between two limit positions*)
    VAR_INPUT
	Axis : REFERENCE TO McAxisType; (*axis reference*)
	Enable : BOOL; (*FB is active as long as input is set*)
	FirstPosition : LREAL; (*lower limit position*)
	LastPosition : LREAL; (*upper limit position*)
	Velocity : REAL; (*maximum velocity*)
	Acceleration : REAL; (*maximum acceleration*)
	Deceleration : REAL; (*maximum deceleration*)
	Jerk : REAL; (*maximum jerk*)
	JogPositive : BOOL; (*executes positive movement at high level*)
	JogNegative : BOOL; (*executes negative movement at high level*)
    END_VAR
    VAR_OUTPUT
	Ready : BOOL; (*function block is active*)
	Busy : BOOL; (*FB is active and needs to be called*)
	CommandAborted : BOOL; (*Command was aborted by another command*)
	Error : BOOL; (*error occurred during operation*)
	ErrorID : DINT; (*error number*)
	Jogging : BOOL; (*jog movement is active*)
	LimitReached : BOOL; (*limit position is reached*)
    END_VAR
    VAR
	Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_JogTargetPosition (*enables and executes jog movements with a defined target position*)
    VAR_INPUT
	Axis : REFERENCE TO McAxisType; (*axis reference*)
	Enable : BOOL; (*FB is active as long as input is set*)
	Velocity : REAL; (*maximum velocity*)
	Acceleration : REAL; (*maximum acceleration*)
	Deceleration : REAL; (*maximum deceleration*)
	Jerk : REAL; (*maximum jerk*)
	TargetPosition : LREAL; (*target position*)
	JogToTarget : BOOL; (*moves to target position at high level*)
	JogPositive : BOOL; (*executes positive movement at high level*)
	JogNegative : BOOL; (*executes negative movement at high level*)
    END_VAR
    VAR_OUTPUT
	Ready : BOOL; (*function block is active*)
	Busy : BOOL; (*FB is active and needs to be called*)
	CommandAborted : BOOL; (*Command was aborted by another command*)
	Error : BOOL; (*error occurred during operation*)
	ErrorID : DINT; (*error number*)
	Jogging : BOOL; (*jog movement is active*)
	MovingToTarget : BOOL; (*axis is moving to target*)
	TargetReached : BOOL; (*target position reached*)
    END_VAR
    VAR
	Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_TorqueControl (*startes a torque control movement on the drive*)
    VAR_INPUT
	Axis : REFERENCE TO McAxisType; (*axis reference*)
	Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
	Torque : REAL; (*signed set torque*)
	TorqueRamp : REAL; (*torque increase while reaching Torque*)
	Velocity : REAL; (*maximum velocity*)
	Acceleration : REAL; (*maximum acceleration*)
	Jerk : REAL; (*maximum jerk*)
	BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
    END_VAR
    VAR_OUTPUT
	InTorque : BOOL; (*set torque reached*)
	Busy : BOOL; (*FB is active and needs to be called*)
	Active : BOOL; (*FB has control over the axis*)
	CommandAborted : BOOL; (*Command was aborted by another command*)
	Error : BOOL; (*error occurred during operation*)
	ErrorID : DINT; (*error number*)
	AxisLimitActive : BOOL; (*is set if velocity limit is reached*)
    END_VAR
    VAR
	Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_LimitLoad (*limits the motor torque to a set value*)
VAR_INPUT
	Axis : REFERENCE TO McAxisType; (*axis reference*)
	Enable : BOOL; (*when set limitation is activated*)
	Load : REAL; (*limit for the motor torque [Nm]*)
	Direction : McDirectionEnum; (*movement direction*)
    END_VAR
    VAR_OUTPUT
	Busy : BOOL; (*FB is active and needs to be called*)
        Ready : BOOL; (*parameter initialized*)
	Active : BOOL; (*torque is limited*)
	Error : BOOL; (*error occurred during operation*)
	ErrorID : DINT; (*error number*)
    END_VAR
    VAR
	Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_LoadSimulationCommand (*switch the load simulation of the axis on or off*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
        Command : McSwitchEnum; (*simulation command*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*execution successful. FB finished*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GearIn (*commands a ratio between the velocity of the master and slave axes*)
    VAR_INPUT
        Master : REFERENCE TO McAxisType; (*master axis reference*)
        Slave : REFERENCE TO McAxisType; (*slave axis reference*)
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		RatioNumerator : DINT; (*gear ratio numerator*)
		RatioDenominator : DINT; (*gear ratio denominator*)
		MasterValueSource : McValueSrcEnum; (*defines the source for synchronization*)
		Acceleration : REAL; (*maximum acceleration for gearing in*)
		Deceleration : REAL; (*maximum deceleration for gearing in*)
		Jerk : REAL; (*maximum jerk for gearing in*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
		AdvancedParameters : McAdvGearInParType; (*structure for using additional functions*)
	END_VAR
	VAR_OUTPUT
		InGear : BOOL; (*commanded gearing complete*)
		Busy : BOOL; (*function block is not finished*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
	END_VAR
    VAR
        Internal : McInternalTwoRefType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GearInPos (*commands a ratio between the velocity of the master and slave axes at defined master and slave positions*)
    VAR_INPUT
		Master : REFERENCE TO McAxisType; (*master axis reference*)
		Slave : REFERENCE TO McAxisType; (*slave axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		RatioNumerator : DINT; (*gear ratio numerator*)
		RatioDenominator : DINT; (*gear ratio denominator*)
		MasterValueSource : McValueSrcEnum; (*defines the source for synchronization*)
		MasterSyncPosition : LREAL; (*master position at which the axes begin moving in sync [measurement units of master]*)
		SlaveSyncPosition : LREAL; (*slave position at which the axes begin moving in sync [measurement units of slave]*)
		SyncMode : McSyncModeEnum; (*defines the type of synchronization*)
		MasterStartDistance : LREAL; (*the master distance for the slave to start to synchronize to the master [measurement units of master]*)
		Velocity : REAL; (*maximum velocity during the movement between StartSync and InSync [measurement units of slave/s]*)
		Acceleration : REAL; (*maximum acceleration during the movement between StartSync and InSync [measurement units of slave/s²]*)
		Deceleration : REAL; (*maximum deceleration during the movement between StartSync and InSync [measurement units of slave/s²]*)
		Jerk : REAL; (*maximum jerk during the movement between StartSync and InSync [measurement units of slave/s3]*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
		AdvancedParameters : McAdvGearInPosParType; (*structure for using additional functions*)
    END_VAR
    VAR_OUTPUT
		StartSync : BOOL; (*synchronization is starting*)
		InSync : BOOL; (*synchronization is finished*)
		Busy : BOOL; (*function block is not finished*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalTwoRefType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_GearOut (*ends the coupling of the slave axis to the master, the slave keeps moving with the current velocity*)
    VAR_INPUT
        Slave : REFERENCE TO McAxisType; (*slave axis reference*)
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Jerk : REAL; (*maximum jerk*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. Function block is finished*)
		Busy : BOOL; (*function block is not finished and must continue to be called*)
		Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_CamIn (*starts a cam coupling between the master and slave axis*)
    VAR_INPUT
        Master : REFERENCE TO McAxisType; (*master axis reference*)
        Slave : REFERENCE TO McAxisType; (*slave axis reference*)
        Execute : BOOL; (*execution of the function block begins on a rising edge of this input*)
		MasterOffset : LREAL; (*offset on the master [measurement units of master]*)
		SlaveOffset : LREAL; (*offset on the slave [measurement units of slave]*)
		MasterScaling : DINT; (*master gauge factor for the cam*)
		SlaveScaling : DINT; (*slave gauge factor for the cam*)
		StartMode : McCamStartModeEnum; (*start mode*)
		MasterValueSource : McValueSrcEnum; (*defines the source for synchronization*)
		CamID : UINT; (*ID of the cam*)
		BufferMode : McBufferModeEnum; (*defines the chronological order of the FB and the preceding FB*)
		AdvancedParameters : McAdvCamInParType; (*structure for using additional functions*)
    END_VAR
    VAR_OUTPUT
		InSync : BOOL; (*commanded gearing complete*)
		Busy : BOOL; (*function block is not finished*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        EndOfProfile : BOOL; (*signals the end of the cam*)
        Status : McCamInStatusEnum; (*status of the movement*)
    END_VAR
    VAR
        Internal : McInternalTwoRefType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamIn (*starts a cam coupling between the master and slave axis*)
    VAR_INPUT
        Master : REFERENCE TO McAxisType; (*master axis reference*)
        Slave : REFERENCE TO McAxisType; (*slave axis reference*)
        Enable : BOOL; (*the function block is active as long as this input is set.*)
        InitData : BOOL; (*initializes input data on a rising edge (online change of function block input data)*)
        CamID : UINT; (*ID of the cam*)
		MasterStartPosition : LREAL; (*position within the period of the master axis or absolute position on a non-periodic master axis for beginning the cam [measurement units of master]*)
		MasterScaling : DINT; (*master gauge factor for the cam*)
		SlaveScaling : DINT; (*slave gauge factor for the cam*)
		EnterCam : BOOL; (*signal for coupling to the cam*)
		ExitCam : BOOL; (*signal for decoupling from the cam*)
		Restart : BOOL; (*signal for restarting the cam*)
		AdvancedParameters : McAdvBrCamInParType; (*additional input parameters for optional use with the function block*)
    END_VAR
    VAR_OUTPUT
		Valid : BOOL; (*the function block's output values can be used*)
		Busy : BOOL; (*the function block is active and must continue to be called*)
		CommandAborted : BOOL; (*function block is aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        DataInitialized : BOOL; (*changes to function block inputs initialized*)
        Running : BOOL; (*the coupling is engaged. The slave will follow the master*)
        StandBy : BOOL; (*cam coupling can be restarted with 'Restart'*)
        InLeadIn : BOOL; (*the slave axis couples with the cam with a lead-in movement*)
        InCam : BOOL; (*cam in the current cam automat state is active*)
        InLeadOut : BOOL; (*he slave axis decouples from the cam with a lead-out movement*)
        EndOfProfile : BOOL; (*status of the movement*)
        Ready : BOOL; (*status of the movement*)
    END_VAR
    VAR
        Internal : McInternalTwoRefType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_CamOut (*ends the coupling of the slave axis to the master, the slave keeps moving with the current velocity*)
    VAR_INPUT
        Slave : REFERENCE TO McAxisType; (*slave axis reference*)
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Jerk : REAL; (*maximum jerk*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. Function block is finished*)
		Busy : BOOL; (*function block is not finished and must continue to be called*)
		Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamPrepare (*prepare cam to use for synchronous movement or functionality*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
        Cam : McCamDefineType; (*specify cam to use*)
        CamID : UINT; (*index for cam data object*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*execution successful. FB finished*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamSaveDataObject (*save the data of a cam profile into a data object*)
    VAR_INPUT
        Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
        Data : McCamDefineType; (*specify data to save*)
        AdvancedParameters : McBrAdvCamSaveDatObjType; (*structure for using advanced functions*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*execution successful. FB finished*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
        DataObjectIdent  : UDINT; (*ident of the saved data object*)
    END_VAR
    VAR
        Internal : McExec1InternalType; (*Data for internal use*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CommandError (*generates a warning or an error on the axis*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Command : McErrorCmdEnum; (*selection which error should be generated*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_PhasingAbsolute (*Creates an absolute phase shift in the master position of a slave axis*)
	VAR_INPUT
		Master : REFERENCE TO McAxisType; (*Master axis reference*)
		Slave : REFERENCE TO McAxisType; (*Slave axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		PhaseShift : LREAL; (*Absolute phase difference in master position of the slave axis*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
		AbsolutePhaseShift : LREAL; (*Current absolute phase shift*)
	END_VAR
	VAR
		Internal : McInternalTwoRefType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_PhasingRelative (*Creates a relative phase shift in the master position of a slave axis*)
	VAR_INPUT
		Master : REFERENCE TO McAxisType; (*Master axis reference*)
		Slave : REFERENCE TO McAxisType; (*Slave axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		PhaseShift : LREAL; (*Absolute phase difference in master position of the slave axis*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		BufferMode : McBufferModeEnum; (*defines the chronological sequence of FB*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
		CoveredPhaseShift : LREAL; (*Current absolute phase shift*)
	END_VAR
	VAR
		Internal : McInternalTwoRefType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_Phasing (*controls phase shift of an axis coupling*)
	VAR_INPUT
		Slave : REFERENCE TO McAxisType; (*axis reference*)
		Enable: BOOL; (*FB is active as long as input is set*)
		PhaseShift : LREAL; (*value added as phase to the master position*)
		Velocity : REAL; (*velocity the phase shift is applied with*)
		Acceleration : REAL; (*acceleration the phase shift is applied with*)
		AdvancedParameters : McAdvPhasingParType; (*structure for using additional functions*)
		StartShift : BOOL; (*start shift at rising edge*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*initialization complete, shift can be started*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
		ShiftAttained : BOOL; (*commanded shift reached*)
		ShiftStarted : BOOL; (*shift has been started*)
		ActualPhaseShift : LREAL; (*actual phase shift value*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_Offset (*controls offset shift of an axis coupling*)
	VAR_INPUT
		Slave : REFERENCE TO McAxisType; (*axis reference*)
		Enable: BOOL; (*FB is active as long as input is set*)
		OffsetShift : LREAL; (*value added as offset to the slave position*)
		Velocity : REAL; (*velocity the offset shift is applied with*)
		Acceleration : REAL; (*acceleration the offset shift is applied with*)
		AdvancedParameters : McAdvOffsetParType; (*structure for using additional functions*)
		StartShift : BOOL; (*start shift at rising edge*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*initialization complete, shift can be started*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
		ShiftAttained : BOOL; (*commanded shift reached*)
		ShiftStarted : BOOL; (*shift has been started*)
		ActualOffsetShift : LREAL; (*actual offset shift value*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
FUNCTION_BLOCK MC_BR_CamAutomatSetPar (*set parameter for configuration of cam automat*)
	VAR_INPUT
		Slave : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Command : McCamAutSetParCmdEnum; (*command for sending values*)
		CamAutomat : McCamAutDefineType; (*parameter source for cam automat*)
		AdvancedParameters : McAdvCamAutSetParType; (*advanced parameters for configuration options*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK  MC_BR_CamAutomatGetPar (*get parameter of configured cam automat*)
	VAR_INPUT
		Slave : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Command :  McCamAutGetParCmdEnum; (*command for sending values*)
		CamAutomat : McCamAutDefineType; (*parameter source for cam automat*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK


{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK MC_BR_CalcCamFromPoints (*calculate cam data from points*)
	VAR_INPUT
		Execute 			: BOOL; 		(*Execution of the function block begins on a rising edge of this input.*) (* *) (*#PAR*)
		MasterPointsAddress	: REFERENCE TO LREAL;
		SlavePointsAddress 	: REFERENCE TO LREAL;
		NumberOfPoints 		: UINT;
		CamDataAddress 		: REFERENCE TO McCamDataType;
		AdvancedParameters 	: McAdvCalcCamFromPointsParType;
	END_VAR
	VAR_OUTPUT
		Done		: BOOL; 			(*Execution successful. Function block is finished.*) (* *) (*#PAR*)
		Busy		: BOOL; 			(*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error		: BOOL; 			(*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		ErrorID 	: DINT; 			(*Status information*)(* *) (*#PAR*)
	END_VAR
	VAR
		Internal : McExec1InternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CalcPointsFromCam (*Calculate points from cam data*)
	VAR_INPUT
		Execute 			: BOOL; 		(*Execution of the function block begins on a rising edge of this input.*) (* *) (*#PAR*)
		Cam					: McCamDefineType; (* Information about the cam.*)
		MasterPointsAddress	: REFERENCE TO LREAL; (*Address of the node vector with the master positions to which the corresponding slave positions should be calculated. See more info in AH.*)
		SlavePointsAddress 	: REFERENCE TO LREAL; (*Address of the node vector for the calculated slave positions, array of LREAL*)
		NumberOfPoints 		: UINT; (*Number of nodes*)
	END_VAR
	VAR_OUTPUT
		Done		: BOOL; 			(*Execution successful. Function block is finished.*) (* *) (*#PAR*)
		Busy		: BOOL; 			(*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error		: BOOL; 			(*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		ErrorID 	: DINT; 			(*Status information*)(* *) (*#PAR*)
		AdditionalInfo 	: McAdvCalcCamFromPointsParType; (*Additional information needed to further process the data with the MC_BR_CalcCamFromPoints function block.*)
	END_VAR
	VAR
		Internal : McExec1InternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CalcCamFromSections (*calculate cam data from laws of movement*)
	VAR_INPUT
		Execute				: BOOL;				(*Execution of the function block begins on a rising edge of this input.*) (* *) (*#PAR*)
		CamSectionsAddress	: REFERENCE TO McCamSectionsType;
		CamDataAddress		: REFERENCE TO McCamDataType;
	END_VAR
	VAR_OUTPUT
		Done			: BOOL;			(*Execution successful. Function block is finished.*) (* *) (*#PAR*)
		Busy			: BOOL;			(*The function block is busy and must continue to be called.*) (* *) (*#PAR*)
		Error			: BOOL;			(*An error occurred during operation. The function block must be disabled to get out of the error state.*) (* *) (*#PAR*)
		ErrorID			: DINT;			(*Status information*)(* *) (*#PAR*)
		ErrorInSection	: UINT;
	END_VAR
	VAR
		Internal : McExec1InternalType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CalcSectionsFromCam
    VAR_INPUT
        Execute : BOOL; (*Execution of this FB begins on a rising edge of the input*)
		Cam : McCamDefineType; (*Information about the cam*)
		CamSectionsAddress : REFERENCE TO  McCamSectionsType;
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. FB finished*)
		Busy : BOOL; (*Function block is not finished*)
		Error : BOOL; (*Error occurred during operation*)
        ErrorID : DINT; (*Error number*)
	END_VAR
    VAR
        Internal : McExec1InternalType; (*Data for internal use*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GetCamMasterPosition (*Calculate the master position for a given cam and a given slave position*)
	VAR_INPUT
		Master				: REFERENCE TO McAxisType; (*Master axis reference.*)
		Slave				: REFERENCE TO McAxisType; (*Slave axis reference.*)
		Execute				: BOOL;	(*Execution of the function block begins on a rising edge of this input.*)
		Cam					: McCamDefineType; (* Information about the cam.*)
		MasterStartPosition : LREAL; (*Master starting position within the cam to start the determination of the master position [measurement units of master].*)
		SlavePosition		: LREAL; (*Slave position within the cam [measurement units of slave].*)
		MasterFactor		: DINT; (*Master gauge factor for the cam*)
		SlaveFactor			: DINT; (*Slave gauge factor for the cam*)
	END_VAR
	VAR_OUTPUT
		Done			: BOOL;	(*Execution successful. Function block is finished.*)
		Busy			: BOOL;	(*The function block is busy and must continue to be called.*)
		Error			: BOOL;	(*An error occurred during operation. The function block must be disabled to get out of the error state.*)
		ErrorID			: DINT;	(*Status information*)
		MasterPosition	: LREAL; (*Master position [measurement units of master].*)
	END_VAR
	VAR
		Internal : McInternalTwoRefType; (*Data for internal use*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GetCamSlavePosition (*Determine the slave position according to a given cam, master/slave factors and a given master position*)
    VAR_INPUT
        Master : REFERENCE TO McAxisType; (*Master axis reference*)
        Slave : REFERENCE TO McAxisType; (*Slave axis reference*)
        Execute : BOOL; (*Execution of this FB begins on a rising edge of the input*)
		Cam : McCamDefineType; (*Information about the cam*)
		MasterPosition : LREAL; (*Master position within the cam [measurement units of the master]*)
		MasterFactor : DINT; (*Master gauge factor for the cam*)
		SlaveFactor : DINT; (*Slave gauge factor for the cam*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Execution successful. FB finished*)
		Busy : BOOL; (*Function block is not finished*)
		Error : BOOL; (*Error occurred during operation*)
        ErrorID : DINT; (*Error number*)
        SlavePosition : LREAL; (*Slave position [measurement units of slave]*)
	END_VAR
    VAR
        Internal : McInternalTwoRefType; (*Data for internal use*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_DigitalCamSwitch (*This fb is analogous to switches on a shaft. It makes it possible to switch an output like a mechanical cam switch that is mounted on an axis*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*Axis reference that should control the output*)
        Enable : BOOL; (*Function block is active as long as this input is set*)
        Switches : McDigCamSwitchOptionsParType; (*Input parameter to configure switches and related parameters*)
		TrackOptions : McDigCamSwTrackOptionsParType; (*Input parameters to configure track specific options*)
		GeneralOptions : McDigCamSwOptionsParType; (*Input parameters to configure general options*)
		ValueSource : McValueSrcEnum; (*Source of the position value*)
		DataSetSelector : USINT; (*Selects the data set to be initialized [0..4]*)
		InitDataSet : BOOL; (*Initializes the switches set which are configured under DataSetSelector*)
		ChangeDataSet : BOOL; (*Changes the currently output switches to those which are configured under DataSetSelector*)
		InitTrackOptions : BOOL; (*Initializes the changed TrackOptions*)
		EnableDigOut : BOOL; (*Enables the cam switches on the defined output*)
		ForceOutput : BOOL; (*The ouput is forced to be set*)
	END_VAR
	VAR_OUTPUT
        InOperation : BOOL; (*Controlled track active*)
		Busy : BOOL; (*Function block is active and must continue to be called*)
		Error : BOOL; (*Error occurred during operation*)
        ErrorID : DINT; (*Error number*)
        DataSetInitialized : BOOL; (*New data set initialized*)
        TrackOptionsInitialized : BOOL; (*New track options initialized*)
        Value : BOOL; (*Output value*)
        ActualDataSet : USINT; (*Index of the currently active data set [0..4]*)
	END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_AbortTrigger (*Stops an active latch command (triggered by MC_TouchProbe FB)*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*Axis reference*)
        TriggerInput : McTriggerType; (*Trigger input definition*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input*)
	END_VAR
	VAR_OUTPUT
        Done : BOOL; (*Command executed. Trigger function successfully aborted*)
		Busy : BOOL; (*The function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during operation*)
        ErrorID : DINT; (*Error number*)
	END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_TouchProbe (*This function block saves the value from given source when a specific trigger event occurs*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*Axis reference*)
        TriggerInput : McTriggerType; (*Trigger input definition*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input*)
		WindowOnly : BOOL; (*Accepts trigger events in the window only*)
		FirstPosition : LREAL; (*Window starting position [measurement unit]*)
		LastPosition : LREAL; (*Window end position [measurement unit]*)
	END_VAR
	VAR_OUTPUT
        Done : BOOL; (*Command executed. Valid trigger event detected*)
		Busy : BOOL; (*The function block is active and must continue to be called. Trigger function active, no valid trigger event detected, yet.*)
		CommandAborted : BOOL; (*Function block aborted by another function block*)
		Error : BOOL; (*Error occurred during operation*)
        ErrorID : DINT; (*Error number*)
		RecordedPosition : LREAL; (*Position at which a valid trigger event is detected [measurement units]*)
	END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_TouchProbe (*This function block captures the value from a given value source when a specific trigger event occurs*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*Axis reference*)
        TriggerInput : McBrTriggerType; (*Trigger input definition*)
        Enable : BOOL; (*The function block is active as long as input is set*)
		Period : LREAL; (*Interval between two expected trigger positions. This interval can be different than the period of a periodic axis [measurement units].*)
		PeriodChange : LREAL; (*If no valid event occurs within an interval, the window is not shifted by the value of the "Period" input, but by the value of "Period" + "PeriodChange". [measurement units].*)
		ExpectedValue : LREAL; (*Expected position of the trigger event within the "Period" [measurement units].*)
		WindowNegative : LREAL; (*Range before the expected position in which the trigger signal may occur [measurement units].*)
		WindowPositive : LREAL; (*Range after the expected position in which the trigger signal may occur [measurement units].*)
		Mode : McBrTouchProbeModeEnum; (* Operating mode of the function block.*)
		AdvancedParameters : McAdvBrTouchProbeParType; (*Additional input parameters for optional use with the function block.*)
	END_VAR
	VAR_OUTPUT
        InOperation : BOOL; (* Function block in operation, waiting for trigger event.*)
		Busy : BOOL; (*The function block is active and must continue to be called.*)
		Error : BOOL; (*Error occurred during operation*)
        ErrorID : DINT; (*Error number*)
        RecordedPeriodicValue : LREAL; (*Result value within the configured period [measurement units].*)
        RecordedValue : LREAL; (*Result value [measurement units].*)
        DeltaExpectedValue : LREAL; (*Deviation: Expected position – result value [measurement units].*)
        ValidTriggerCount : UDINT; (*Number of valid trigger events since "Enable" was set to TRUE.*)
		MissedTriggerCount : UDINT; (*Number of missed trigger events since "Enable" was set to TRUE.*)
		TriggerInfo : McBrTriggerInfoType; (*Additional information about the trigger event.*)
	END_VAR
    VAR
        Internal : McInternalType; (*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CyclicTorqueFeedForward (*feeds forward a cyclically transferred torque*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
        InterpolationMode : McIplModeEnum; (*interpolation mode of cyclic value on receiving drive*)
        AdvancedParameters : McAdvCyclicTorqueFFParType; (*additional input parameters for optional use with the function block.*)
        CyclicTorque : REAL; (*cyclic feed forward torque that is transferred to the axis*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*initialization complete, feed forward torque is beeing transferred cyclically*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*error occurred during operation*)
        ErrorID : DINT; (*error number*)
    END_VAR
    VAR
        Internal : McInternalType;(*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamAutomatPrepareRestart (*commands a motion to a aborted cam automat position*)
	VAR_INPUT
		Slave : REFERENCE TO McAxisType; (*axis reference*)
		Execute : BOOL; (*execution of this FB is started on rising edge of the input*)
		Velocity : REAL; (*maximum velocity*)
		Acceleration : REAL; (*maximum acceleration*)
		Deceleration : REAL; (*maximum deceleration*)
		Jerk : REAL; (*maximum jerk*)
		Mode : McCamAutPrepRestartModeEnum; (*mode of preparing restart*)
		AdvancedParameters : McAdvCamAutPrepRestartParType; (*Additional input parameters for optional use with the function block.*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution successful. FB finished*)
		Busy : BOOL; (*FB is active and needs to be called*)
		Active : BOOL; (*FB has control over the axis*)
		CommandAborted : BOOL; (*Command was aborted by another command*)
		Error : BOOL; (*error occurred during operation*)
		ErrorID : DINT; (*error number*)
		RestartPosition : LREAL; (*Restart position*)
	END_VAR
	VAR
		Internal : McInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CheckRestorePositionData (*checks the data for a permanent variable that can be used to save and restore the axis position*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*Axis reference*)
        Execute : BOOL; (*Execution of this FB is started on rising edge of the input*)
        DataAddress : UDINT; (*Address of a permanent variable of type McAcpAxRestorePosType or McStpAxRestorePosType*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*Execution successful. FB finished*)
        Busy : BOOL; (*FB is active and needs to be called*)
        Error : BOOL; (*Error occurred during operation*)
        ErrorID : DINT; (*Error number*)
        DataInUse : BOOL; (*Indicates that the DataAddress for restoring the axis position is in use*)
        DataValid : BOOL; (*Indicates that the data in the permanent variable for restoring the axis position is valid*)
    END_VAR
    VAR
        Internal : McInternalType; (*Internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamDwell (*Starts a coupling between the master and slave axis with a repeated sequence of a user defined cam followed by an optional standstill.*)
	VAR_INPUT
		Master : REFERENCE TO McAxisType; (*Master axis reference*)
		Slave : REFERENCE TO McAxisType; (*Slave axis reference*)
        Enable : BOOL; (*The function block is active as long as this input is set.*)
        InitData : BOOL; (*Initializes input data on a rising edge (online change of function block input data)*)
        CamID : UINT; (*ID of the cam*)
		MasterScaling : DINT; (*Master gauge factor for the cam.*)
		SlaveScaling : DINT; (*Slave gauge factor for the cam.*)
		MasterStartPosition : LREAL; (*Position within the period of the master axis or absolute position on a non-periodic master axis for beginning the cam. [measurement units of master]*)
		MasterDwellDistance : LREAL; (*Length of the dwell (slave at standstill) range on the master axis. [measurement units of master]*)
		AdvancedParameters : McAdvBrCamDwellParType; (* Additional input parameters for optional use with the function block.*)
		LeadIn : BOOL; (*Lead-in command signal.*)
		LeadOut : BOOL; (*Lead-out command signal.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*The function block is active and must continuously be called.*)
		CommandAborted : BOOL; (*Function block is aborted by another command.*)
		Error : BOOL; (*Error occurred during operation.*)
        ErrorID : DINT; (*Error number.*)
        DataInitialized : BOOL; (*Changes to function block inputs initialized.*)
        Running : BOOL; (*The coupling is engaged.*)
        InLeadIn : BOOL; (*Coupling is in the lead-in movement range.*)
        InCam : BOOL; (* Coupling is in the cam range.*)
		InDwell : BOOL; (* Coupling is in the dwell range.*)
        InLeadOut : BOOL; (*Coupling is in the lead-in movement range.*)
	END_VAR
	VAR
        Internal : McInternalTwoRefType; (*internal variable*)
 	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_AutoCamDwell (*Starts a coupling between the master and slave axis with a repeated sequence of an automatically generated cam followed by an optional standstill.*)
	VAR_INPUT
		Master : REFERENCE TO McAxisType; (*Master axis reference*)
		Slave : REFERENCE TO McAxisType; (*Slave axis reference*)
        Enable : BOOL; (*The function block is active as long as this input is set.*)
        InitData : BOOL; (*Initializes input data on a rising edge (online change of function block input data)*)
		MasterLength : LREAL; (*Length of the automatically calculated cam on the master axis. [measurement units of master]*)
		SlaveLength : LREAL; (*Length of the automatically calculated cam on the slave axis. [measurement units of slave]*)
		MasterStartPosition : LREAL; (*Position within the period of the master axis or absolute position on a non-periodic master axis for beginning the cam. [measurement units of master]*)
		MasterDwellDistance : LREAL; (*Length of the dwell (slave at standstill) range on the master axis. [measurement units of master]*)
		AdvancedParameters : McAdvBrAutoCamDwellParType; (* Additional input parameters for optional use with the function block.*)
		LeadIn : BOOL; (*Lead-in command signal.*)
		LeadOut : BOOL; (*Lead-out command signal.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*The function block is active and must continuously be called.*)
		CommandAborted : BOOL; (*Function block is aborted by another command.*)
		Error : BOOL; (*Error occurred during operation.*)
        ErrorID : DINT; (*Error number.*)
        DataInitialized : BOOL; (*Changes to function block inputs initialized.*)
        Running : BOOL; (*The coupling is engaged.*)
        InLeadIn : BOOL; (*Coupling is in the lead-in movement range.*)
        InCam : BOOL; (* Coupling is in the cam range.*)
		InDwell : BOOL; (* Coupling is in the dwell range.*)
        InLeadOut : BOOL; (*Coupling is in the lead-in movement range.*)
	END_VAR
	VAR
        Internal : McInternalTwoRefType; (*internal variable*)
 	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_CamTransition (*Starts a cyclically repeating cam compensation sequence between the master and slave axis with an optional lead in and lead out.*)
	VAR_INPUT
		Master : REFERENCE TO McAxisType; (*Master axis reference*)
		Slave : REFERENCE TO McAxisType; (*Slave axis reference*)
        Enable : BOOL; (*The function block is active as long as this input is set.*)
        InitData : BOOL; (*Initializes input data on a rising edge (online change of function block input data)*)
        CamID : UINT; (*ID of the cam*)
		MasterScaling : DINT; (*Master gauge factor for the cam.*)
		SlaveScaling : DINT; (*Slave gauge factor for the cam.*)
		MasterInterval : LREAL; (*Interval of the master axis (defines the master length of cam + compensation and the starting interval). [measurement units of master]*)
		SlaveInterval : LREAL; (*Interval of the slave axis (defines the slave length of cam + compensation). [measurement units of slave]*)
		MasterStartPosition : LREAL; (*Position within the period of the master axis or absolute position on a non-periodic master axis for beginning the cam. [measurement units of master]*)
		AdvancedParameters : McAdvBrCamTransitionParType; (*Additional input parameters for optional use with the function block.*)
		LeadIn : BOOL; (*Couples with the cam on a rising edge.*)
		LeadOut : BOOL; (*Decouples from the cam on a rising edge.*)
	END_VAR
	VAR_OUTPUT
		Valid : BOOL; (*The function block's output values can be used.*)
		Busy : BOOL; (*The function block is active and must continuously be called.*)
		CommandAborted : BOOL; (*Function block is aborted by another command.*)
		Error : BOOL; (*Error occurred during operation.*)
        ErrorID : DINT; (*Error number.*)
        DataInitialized : BOOL; (*Changes to function block inputs initialized.*)
        Running : BOOL; (*The coupling is engaged.*)
		InLeadIn : BOOL; (*Lead-in movement for the cam is active.*)
        InCam : BOOL; (*Coupling is initiated. The slave axis follows the master axis in cam range.*)
		InTransition : BOOL; (*Coupling is in the transition range.*)
        InLeadOut : BOOL; (*Lead-out movement from the cam is active.*)
	END_VAR
	VAR
        Internal : McInternalTwoRefType; (*internal variable*)
 	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_EventMoveAbsolute (*starts a controlled absolute movement to a specified position with given velocity, acceleration and jerk after a specified event*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*Axis reference*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input*)
		Position : LREAL; (*Target position for the movement [Measurement units]*)
		Velocity : REAL; (*Maximum velocity [Measurement units/s]*)
		Acceleration : REAL; (*Maximum acceleration [Measurement units / s2]*)
		Deceleration : REAL; (*Maximum deceleration [Measurement units / s2]*)
		Jerk : REAL; (*Maximum jerk [Measurement Units / s3]*)
		Direction : McDirectionEnum; (*Direction of movement*)
		Event : McEventType; (*Input used as the event source*)
		AdvancedParameters : McAdvEventMoveParType; (*Structure for using advanced functions*)
	END_VAR
	VAR_OUTPUT
		InPosition : BOOL; (*Specified target position reached*)
		Busy : BOOL; (*Function block is active and must continue to be called*)
		Active : BOOL; (*Indicates that the function block is currently controlling the axis*)
		CommandAborted : BOOL; (*Function block aborted by another command*)
		Error : BOOL; (*Error occurred during execution.*)
		ErrorID : DINT; (*Error number*)
		WaitingForEvent : BOOL; (*FB is active and drive function is waiting for the start event*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_EventMoveAdditive (*starts a controlled additive movement of specified distance with given velocity, acceleration and jerk after a specified event*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*Axis reference*)
		Execute : BOOL; (*Execution of the function block begins on a rising edge of this input.*)
		Distance : LREAL; (*Relative distance covered by the movement*)
		Velocity : REAL; (*Maximum velocity [Measurement units/s]*)
		Acceleration : REAL; (*Maximum acceleration [Measurement units / s2]*)
		Deceleration : REAL; (*Maximum deceleration [Measurement units / s2]*)
		Jerk : REAL; (*Maximum jerk [Measurement Units / s3]*)
		Event : McEventType; (*Input used as the event source*)
		AdvancedParameters : McAdvEventMoveParType; (*Structure for using advanced functions*)
	END_VAR
	VAR_OUTPUT
		InPosition : BOOL; (*Specified distance reached*)
		Busy : BOOL; (*Function block is active and must continue to be called*)
		Active : BOOL; (*Indicates that the function block is currently controlling the axis*)
		CommandAborted : BOOL; (*Function block aborted by another command*)
		Error : BOOL; (*Error occurred during execution*)
		ErrorID : DINT; (*Error number*)
		WaitingForEvent : BOOL; (*FB is active and drive function is waiting for the start event*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_EventMoveVelocity (*starts a controlled movement with given velocity, acceleration and jerk after a specified event*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*Axis reference*)
		Execute : BOOL; (*Starts the execution of the FB on the rising edge*)
		Velocity : REAL; (*Target velocity [Measurement units/s]*)
		Acceleration : REAL; (*Maximum acceleration [Measurement units / s2]*)
		Deceleration : REAL; (*Maximum deceleration [Measurement units / s2]*)
		Jerk : REAL; (*Maximum jerk [Measurement Units / s3]*)
		Direction : McDirectionEnum; (*Direction of movement*)
		Event : McEventType; (*Input used as the event source*)
		AdvancedParameters : McAdvEventMoveParType; (*Structure for using advanced functions*)
	END_VAR
	VAR_OUTPUT
		InVelocity : BOOL; (*Specified velocity reached*)
		Busy : BOOL; (*Function block is active and must continue to be called*)
		Active : BOOL; (*Indicates that the function block is currently controlling the axis*)
		CommandAborted : BOOL; (*Function block aborted by another command*)
		Error : BOOL; (*Error occurred during execution*)
		ErrorID : DINT; (*Error number*)
		WaitingForEvent : BOOL; (*FB is active and drive function is waiting for the start event*)
	END_VAR
	VAR
		Internal : McInternalType; (*Internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_ForceHardwareInputs (*Forces HW inputs of a real axis*)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*Axis reference*)
        Enable : BOOL; (*FB is active as long as input is set*)
        HomingSwitch : BOOL; (*Logical state of the homing switch*)
        PositiveLimitSwitch : BOOL; (*Logical state of the positive limit switch*)
        NegativeLimitSwitch : BOOL; (*Logical state of the negative limit switch*)
        Trigger1 : BOOL; (*Logical state of trigger 1*)
        Trigger2 : BOOL; (*Logical state of trigger 2*)
    END_VAR
    VAR_OUTPUT
        Valid : BOOL; (*The function block's output values can be used*)
        Busy : BOOL; (*The function block is active and must continuously be called*)
        Error : BOOL; (*Error occurred during operation*)
        ErrorID : DINT; (*Error number*)
        Ready : BOOL; (* Function block is ready for input changes*)
    END_VAR
    VAR
        Internal : McInternalType;(*internal variable*)
    END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_TorqueControl (*Starts a movement with a specified torque at a limited velocity*)
	VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*Axis reference.*)
        Enable : BOOL; (*The function block is active as long as this input is set.*)
        InitData : BOOL; (*Initializes input data on a rising edge (online change of function block input data).*)
        Torque: REAL; (*Signed torque setpoint for the axis [Nm].*)
        TorqueRamp : REAL; (*Increase in torque until "Torque" value is reached [Nm/s].*)
        MaximumVelocity: REAL; (*Signed upper speed limit of rotation [measurement units / s]*)
        MinimumVelocity: REAL; (*Signed lower speed limit of rotation [measurement units / s].*)
		Acceleration: REAL; (* Maximum acceleration [measurement units / s^2] or maximum deceleration when the "NegMaxVelocity" or "PosMaxVelocity" value changes [measurement units / s^2].*)
		Jerk : REAL; (*Maximum jerk [measurement units / s^3].*)
		AdvancedParameters : McAdvBrTorqueControlParType; (*Additional input parameters for optional use with the function block.*)
        Start : BOOL; (*Signal to start the torque controlled movement.*)
        Stop : BOOL; (*Signal to stop the torque controlled movement.*)
	END_VAR
	VAR_OUTPUT
		InTorque : BOOL; (*Torque setpoint reached.*)
		Busy : BOOL; (*FB is active and needs to be called.*)
		Active : BOOL; (*FB has control over the axis.*)
		CommandAborted : BOOL; (*Command was aborted by another command.*)
		Error : BOOL; (*Error occurred during operation.*)
		ErrorID : DINT; (*Error number.*)
		DataInitialized : BOOL; (*Changes to function block inputs initialized.*)
		Ready : BOOL; (*FB is ready for Start or Stop signal.*)
		AxisLimitActive : BOOL; (*Axis velocity limit is reached or exceeded.*)
	END_VAR
	VAR
        Internal : McInternalType;(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_WriteParameter (*Writes the value to a specific PLCopen parameter*)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*Axis reference*)
		Execute : BOOL; (*Write the value of the parameter at the rising edge*)
		ParameterNumber : McPlcopenParEnum; (*Number of the parameter*)
		Value : LREAL; (*New value of the specified parameter*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*Parameter successfully written*)
		Busy : BOOL; (*Function block is not finished*)
		Error : BOOL; (*Error occurred in FB*)
		ErrorID : DINT; (*Error number*)
	END_VAR
	VAR
		Internal : McInternalType;(*Internal variable*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_LimitLoadCam (* Enables a cam profile based torque limitation *)
	VAR_INPUT
		Axis : REFERENCE TO McAxisType; (*Axis reference *)
		Enable : BOOL; (*The function block is active as long as this input is set*)
		InitData : BOOL; (*Initializes input data on a rising edge (online change of function block input data)*)
		CamIDPos : UINT; (*Index of cam profile for positive direction torque limitation*)
		CamIDNeg : UINT; (*Index of cam profile for negative direction torque limitation*)
		Mode : McLimitLoadModeEnum;    (*Torque limitation mode selection *)
		AdvancedParameters : McAdvBrLimitLoadCamParType; (*Additional parameters*)
	END_VAR
	VAR_OUTPUT
		Busy : BOOL;  (*The function block is enabled ("Enable" = 1)*)
		Ready : BOOL; (*The parameters on the function block inputs were successfully initialized; the limiter is ready.*)
 		Active : BOOL; (*Limiting is active*)
		Error : BOOL; (*Error during execution*)
		ErrorID : DINT; (*Error number*)
		DataInitialized : BOOL; (*The parameter transfer started with "InitData" = TRUE is ended*)
	END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_MechDeviationComp (* handles mechanical position deviation compensation *)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Execute : BOOL; (*Execute the given command at rising edge*)
        Command : McMechDevCompCmdEnum; (*commands for mechanical deviation compensation*)
        AdvancedParameters : McMechDevCompAdvParType; (*advanced parameters for mechanics deviation position compensation*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*last given command completed successfully*)
        Busy : BOOL; (*function block is not finished (must be continuously called)*)
        Error : BOOL; (*error occurred in FB*)
        ErrorID : DINT; (*error number*)
        AdditionalInfo : McMechDevCompAddInfoType; (*structure with extended output information*)
    END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK MC_BR_GetHardwareInfo (* Get information regarding the axis, the drive, the plug in cards and the motors *)
    VAR_INPUT
        Axis : REFERENCE TO McAxisType; (*axis reference*)
        Execute : BOOL; (*Execute the given command at rising edge*)
    END_VAR
    VAR_OUTPUT
        Done : BOOL; (*last given command completed successfully*)
        Busy : BOOL; (*function block is not finished (must be continuously called)*)
        Error : BOOL; (*error occurred in FB*)
        ErrorID : DINT; (*error number*)
        HardwareInfo : McHardwareInfoType; (*structure with the hardware information*)
    END_VAR
	VAR
		Internal : McInternalType;
	END_VAR
END_FUNCTION_BLOCK
