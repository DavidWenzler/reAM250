TYPE
   McStpAxHomingParType : STRUCT
        HomingMode : McHomingModeEnum; (*The following homing modes are supported:*)
        Position : LREAL; (*Absolute position or homing offset when homing signal [Measurement units] occurs*)
        StartVelocity : REAL; (*Velocity for reference switch search [Measurement units/s]*)
        HomingVelocity : REAL; (*Velocity (after reaching reference switch) [Measurement units/s]*)
        Acceleration : REAL; (*Maximum acceleration [Measurement units/s]*)
        SwitchEdge : McDirectionEnum; (*Edge of reference switch*)
        StartDirection : McDirectionEnum; (*Start direction for searching the reference edge*)
        HomingDirection : McDirectionEnum; (*Direction for homing (after reaching reference switch) *)
        ReferencePulse : McSwitchEnum; (*The encoder's reference pulse is used for homing*)
        KeepDirection : McSwitchEnum; (*The direction of movement is or is not permitted to be changed during the homing procedure*)
		ReferencePulseBlockingDistance : REAL; (*Distance for blocking activation of "triggering reference pulse" [Measurement units]*)
		RestorePositionVariableAddress : UDINT; (*Address of a remanent variable of type McStpAxRestorePosType that is needed for "HomingMode" mcHOMING_RESTORE_POSITION*)
		BlockDetectionPositionError : REAL; (*Lag error for block detection [Measurement units]*)
		PositionErrorStopLimit : REAL; (*Lag error for canceling homing procedure [Measurement units]*)
    END_STRUCT;

    McStpAxRestorePosType: STRUCT
		Data : ARRAY[0..17] OF DINT; (*Data for restoring the position*)
	END_STRUCT;

END_TYPE