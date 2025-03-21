TYPE
	McSAMEType : STRUCT (*Parameter of hardware elements situated between motor encoder and load which influence the scaling*)
		Gearbox : McCfgGearBoxType; (*Specifies a gearbox by defining the ratio between a gearbox input and output*)
		RotaryToLinearTransformation : McCfgRotToLinTrfType; (*Specifies a transformation factor between the output of the gear and the actual load movement*)
	END_STRUCT;
	McSAMType : STRUCT (*Parameter to handle the motor*)
		SteppingAngle : REAL; (*Stepping angle of the motor [°]*)
	END_STRUCT;
	McSAELEnum :
		( (*Encoder link selector setting*)
		mcSAEL_NO_ENC := 0, (*No encoder -*)
		mcSAEL_ONE_ENC := 1 (*One encoder -*)
		);
	McSAELOEPosEncEnum :
		( (*Position encoder selector setting*)
		mcSAELOEPE_STEP_CNT := 0, (*Step counter - Internal step counter*)
		mcSAELOEPE_ENC := 1, (*Encoder - OnBoard encoder*)
		mcSAELOEPE_ENC_X6 := 2, (*Encoder X6 - OnBoard encoder*)
		mcSAELOEPE_ENC_X6A := 3, (*Encoder X6A - OnBoard encoder 1*)
		mcSAELOEPE_ENC_X6B := 4, (*Encoder X6B - OnBoard encoder 2*)
		mcSAELOEPE_ENC_X3 := 5, (*Encoder X3 - Plug-in module in Encoder X3*)
		mcSAELOEPE_ENC_X4 := 6, (*Encoder X4 - Plug-in module in Encoder X4*)
		mcSAELOEPE_EXT := 10 (*External - External encoder is used*)
		);
	McSAELOEPosEncStepCntRefPSrcEnum :
		( (*Input source for the reference pulse*)
		mcSAELOEPESCRPS_DIG_IN_1 := 0, (*Digital input 1 -*)
		mcSAELOEPESCRPS_DIG_IN_2 := 1, (*Digital input 2 -*)
		mcSAELOEPESCRPS_DIG_IN_3 := 2, (*Digital input 3 -*)
		mcSAELOEPESCRPS_DIG_IN_5 := 3, (*Digital input 5 -*)
		mcSAELOEPESCRPS_DIG_IN_6 := 4, (*Digital input 6 -*)
		mcSAELOEPESCRPS_R_IN_OF_X6A := 5, (*R input of X6A -*)
		mcSAELOEPESCRPS_R_IN_OF_X6B := 6 (*R input of X6B -*)
		);
	McSAELOEPosEncStepCntRefPEdgEnum :
		( (*Detection of the reference pulse*)
		mcSAELOEPESCRPE_POS_EDG := 0, (*Positive edge - Detection with positive edge*)
		mcSAELOEPESCRPE_NEG_EDG := 1 (*Negative edge - Detection with negative edge*)
		);
	McSAELOEPosEncStepCntType : STRUCT (*Type mcSAELOEPE_STEP_CNT settings*)
		ReferencePulseSource : McSAELOEPosEncStepCntRefPSrcEnum; (*Input source for the reference pulse*)
		ReferencePulseEdge : McSAELOEPosEncStepCntRefPEdgEnum; (*Detection of the reference pulse*)
	END_STRUCT;
	McSAELOEExtPosTypEnum :
		( (*Position type selector setting*)
		mcSAELOEEPT_ABS := 0, (*Absolute - Get position from an absolute encoder*)
		mcSAELOEEPT_INCR := 1 (*Incremental - Get position from an incremental encoder*)
		);
	McSAELOEExtPosTypAbsPosRngType : STRUCT (*Defines the range of the position value*)
		LowerLimit : DINT; (*Lower limit of encoder range*)
		UpperLimit : UDINT; (*Upper limit of encoder range*)
	END_STRUCT;
	McSAELOEExtPosTypAbsType : STRUCT (*Type mcSAELOEEPT_ABS settings*)
		PositionRange : McSAELOEExtPosTypAbsPosRngType; (*Defines the range of the position value*)
	END_STRUCT;
	McSAELOEExtPosTypType : STRUCT (*Type of the encoder*)
		Type : McSAELOEExtPosTypEnum; (*Position type selector setting*)
		Absolute : McSAELOEExtPosTypAbsType; (*Type mcSAELOEEPT_ABS settings*)
	END_STRUCT;
	McSAELOEExtPosSrcEnum :
		( (*Position source selector setting*)
		mcSAELOEEPS_IO_CH_DINT := 0, (*I/O channel DINT - Get position from a signed 32 bit I/O channel*)
		mcSAELOEEPS_IO_CH_UDINT := 1, (*I/O channel UDINT - Get position from an unsigned 32 bit I/O channel*)
		mcSAELOEEPS_IO_CH_INT := 2, (*I/O channel INT - Get position from a signed 16 bit I/O channel*)
		mcSAELOEEPS_IO_CH_UINT := 3, (*I/O channel UINT - Get position from an unsigned 16 bit I/O channel*)
		mcSAELOEEPS_VAR_DINT := 4, (*Variable DINT - Get position from a signed 32 bit variable*)
		mcSAELOEEPS_VAR_UDINT := 5, (*Variable UDINT - Get position from an unsigned 32 bit variable*)
		mcSAELOEEPS_VAR_INT := 6, (*Variable INT - Get position from a signed 16 bit variable*)
		mcSAELOEEPS_VAR_UINT := 7 (*Variable UINT - Get position from an unsigned 16 bit variable*)
		);
	McSAELOEExtPosSrcIOChDINTType : STRUCT (*Type mcSAELOEEPS_IO_CH_DINT settings*)
		ChannelMapping : STRING[250]; (*Input source for the position*)
	END_STRUCT;
	McSAELOEExtPosSrcIOChUDINTType : STRUCT (*Type mcSAELOEEPS_IO_CH_UDINT settings*)
		ChannelMapping : STRING[250]; (*Input source for the position*)
	END_STRUCT;
	McSAELOEExtPosSrcIOChINTType : STRUCT (*Type mcSAELOEEPS_IO_CH_INT settings*)
		ChannelMapping : STRING[250]; (*Input source for the position*)
	END_STRUCT;
	McSAELOEExtPosSrcIOChUINTType : STRUCT (*Type mcSAELOEEPS_IO_CH_UINT settings*)
		ChannelMapping : STRING[250]; (*Input source for the position*)
	END_STRUCT;
	McSAELOEExtPosSrcVarDINTType : STRUCT (*Type mcSAELOEEPS_VAR_DINT settings*)
		PVMapping : STRING[250]; (*Input source for the position*)
	END_STRUCT;
	McSAELOEExtPosSrcVarUDINTType : STRUCT (*Type mcSAELOEEPS_VAR_UDINT settings*)
		PVMapping : STRING[250]; (*Input source for the position*)
	END_STRUCT;
	McSAELOEExtPosSrcVarINTType : STRUCT (*Type mcSAELOEEPS_VAR_INT settings*)
		PVMapping : STRING[250]; (*Input source for the position*)
	END_STRUCT;
	McSAELOEExtPosSrcVarUINTType : STRUCT (*Type mcSAELOEEPS_VAR_UINT settings*)
		PVMapping : STRING[250]; (*Input source for the position*)
	END_STRUCT;
	McSAELOEExtPosSrcType : STRUCT (*Position source*)
		Type : McSAELOEExtPosSrcEnum; (*Position source selector setting*)
		IOChannelDINT : McSAELOEExtPosSrcIOChDINTType; (*Type mcSAELOEEPS_IO_CH_DINT settings*)
		IOChannelUDINT : McSAELOEExtPosSrcIOChUDINTType; (*Type mcSAELOEEPS_IO_CH_UDINT settings*)
		IOChannelINT : McSAELOEExtPosSrcIOChINTType; (*Type mcSAELOEEPS_IO_CH_INT settings*)
		IOChannelUINT : McSAELOEExtPosSrcIOChUINTType; (*Type mcSAELOEEPS_IO_CH_UINT settings*)
		VariableDINT : McSAELOEExtPosSrcVarDINTType; (*Type mcSAELOEEPS_VAR_DINT settings*)
		VariableUDINT : McSAELOEExtPosSrcVarUDINTType; (*Type mcSAELOEEPS_VAR_UDINT settings*)
		VariableINT : McSAELOEExtPosSrcVarINTType; (*Type mcSAELOEEPS_VAR_INT settings*)
		VariableUINT : McSAELOEExtPosSrcVarUINTType; (*Type mcSAELOEEPS_VAR_UINT settings*)
	END_STRUCT;
	McSAELOEExtValCkModOkEnum :
		( (*Module ok selector setting*)
		mcSAELOEEVCMO_POS_SRC_DEV := 0, (*Position source device - Get module ok from the same device as the position source*)
		mcSAELOEEVCMO_IO_CH := 1, (*I/O channel - Get module ok from an I/O channel*)
		mcSAELOEEVCMO_VAR := 2, (*Variable - Get module ok from a variable*)
		mcSAELOEEVCMO_NOT_USE := 3 (*Not used - Module ok is not used*)
		);
	McSAELOEExtValCkModOkIOChType : STRUCT (*Type mcSAELOEEVCMO_IO_CH settings*)
		ChannelMapping : STRING[250]; (*Input source for module ok*)
	END_STRUCT;
	McSAELOEExtValCkModOkVarType : STRUCT (*Type mcSAELOEEVCMO_VAR settings*)
		PVMapping : STRING[250]; (*Input source for module ok*)
	END_STRUCT;
	McSAELOEExtValCkModOkType : STRUCT (*Use module ok for validity check*)
		Type : McSAELOEExtValCkModOkEnum; (*Module ok selector setting*)
		IOChannel : McSAELOEExtValCkModOkIOChType; (*Type mcSAELOEEVCMO_IO_CH settings*)
		Variable : McSAELOEExtValCkModOkVarType; (*Type mcSAELOEEVCMO_VAR settings*)
	END_STRUCT;
	McSAELOEExtValCkStDatEnum :
		( (*Stale data selector setting*)
		mcSAELOEEVCSD_POS_SRC_DEV := 0, (*Position source device - Get stale data from the same device as the position source*)
		mcSAELOEEVCSD_IO_CH := 1, (*I/O channel - Get stale data from an I/O channel*)
		mcSAELOEEVCSD_VAR := 2, (*Variable - Get stale data from a variable*)
		mcSAELOEEVCSD_NOT_USE := 3 (*Not used - Stale data is not used*)
		);
	McSAELOEExtValCkStDatIOChType : STRUCT (*Type mcSAELOEEVCSD_IO_CH settings*)
		ChannelMapping : STRING[250]; (*Input source for stale data*)
	END_STRUCT;
	McSAELOEExtValCkStDatVarType : STRUCT (*Type mcSAELOEEVCSD_VAR settings*)
		PVMapping : STRING[250]; (*Input source for stale data*)
	END_STRUCT;
	McSAELOEExtValCkStDatType : STRUCT (*Use stale data for validity check*)
		Type : McSAELOEExtValCkStDatEnum; (*Stale data selector setting*)
		IOChannel : McSAELOEExtValCkStDatIOChType; (*Type mcSAELOEEVCSD_IO_CH settings*)
		Variable : McSAELOEExtValCkStDatVarType; (*Type mcSAELOEEVCSD_VAR settings*)
	END_STRUCT;
	McSAELOEExtValCkNetTimeEnum :
		( (*Net time selector setting*)
		mcSAELOEEVCNT_NOT_USE := 0, (*Not used - Net time is not used*)
		mcSAELOEEVCNT_IO_CH := 1, (*I/O channel - Get net time from an I/O channel*)
		mcSAELOEEVCNT_VAR := 2 (*Variable - Get net time from a variable*)
		);
	McSAELOEExtValCkNetTimeIOChType : STRUCT (*Type mcSAELOEEVCNT_IO_CH settings*)
		ChannelMapping : STRING[250]; (*Input source for net time*)
	END_STRUCT;
	McSAELOEExtValCkNetTimeVarType : STRUCT (*Type mcSAELOEEVCNT_VAR settings*)
		PVMapping : STRING[250]; (*Input source for net time*)
	END_STRUCT;
	McSAELOEExtValCkNetTimeType : STRUCT (*Use net time for validity check*)
		Type : McSAELOEExtValCkNetTimeEnum; (*Net time selector setting*)
		IOChannel : McSAELOEExtValCkNetTimeIOChType; (*Type mcSAELOEEVCNT_IO_CH settings*)
		Variable : McSAELOEExtValCkNetTimeVarType; (*Type mcSAELOEEVCNT_VAR settings*)
	END_STRUCT;
	McSAELOEExtValCkEncOkEnum :
		( (*Encoder ok selector setting*)
		mcSAELOEEVCEO_NOT_USE := 0, (*Not used - Encoder ok is not used*)
		mcSAELOEEVCEO_IO_CH := 1, (*I/O channel - Get encoder ok from an I/O channel*)
		mcSAELOEEVCEO_VAR := 2 (*Variable - Get encoder ok from a variable*)
		);
	McSAELOEExtValCkEncOkIOChType : STRUCT (*Type mcSAELOEEVCEO_IO_CH settings*)
		ChannelMapping : STRING[250]; (*Input source for encoder ok*)
	END_STRUCT;
	McSAELOEExtValCkEncOkVarType : STRUCT (*Type mcSAELOEEVCEO_VAR settings*)
		PVMapping : STRING[250]; (*Input source for encoder ok*)
	END_STRUCT;
	McSAELOEExtValCkEncOkType : STRUCT (*Use encoder ok flag for validity check (True = position valid)*)
		Type : McSAELOEExtValCkEncOkEnum; (*Encoder ok selector setting*)
		IOChannel : McSAELOEExtValCkEncOkIOChType; (*Type mcSAELOEEVCEO_IO_CH settings*)
		Variable : McSAELOEExtValCkEncOkVarType; (*Type mcSAELOEEVCEO_VAR settings*)
	END_STRUCT;
	McSAELOEExtValCkType : STRUCT (*Check if given position is valid*)
		ModuleOk : McSAELOEExtValCkModOkType; (*Use module ok for validity check*)
		StaleData : McSAELOEExtValCkStDatType; (*Use stale data for validity check*)
		NetTime : McSAELOEExtValCkNetTimeType; (*Use net time for validity check*)
		EncoderOk : McSAELOEExtValCkEncOkType; (*Use encoder ok flag for validity check (True = position valid)*)
	END_STRUCT;
	McSAELOEExtRefPEnum :
		( (*Reference pulse selector setting*)
		mcSAELOEERP_NOT_USE := 0, (*Not used - Reference pulse is not used*)
		mcSAELOEERP_IO_CH := 1, (*I/O channel - Reference pulse is used with I/O channel*)
		mcSAELOEERP_VAR := 2 (*Variable - Reference pulse is used with variable*)
		);
	McSAELOEExtRefPIOChPosType : STRUCT (*Position of the reference pulse*)
		ChannelMapping : STRING[250]; (*Input source for the reference pulse position*)
	END_STRUCT;
	McSAELOEExtRefPIOChCntType : STRUCT (*Count of the reference pulse*)
		ChannelMapping : STRING[250]; (*Input source for the reference pulse count*)
	END_STRUCT;
	McSAELOEExtRefPIOChType : STRUCT (*Type mcSAELOEERP_IO_CH settings*)
		Position : McSAELOEExtRefPIOChPosType; (*Position of the reference pulse*)
		Count : McSAELOEExtRefPIOChCntType; (*Count of the reference pulse*)
	END_STRUCT;
	McSAELOEExtRefPVarPosType : STRUCT (*Position of the reference pulse*)
		PVMapping : STRING[250]; (*Input source for the reference pulse position*)
	END_STRUCT;
	McSAELOEExtRefPVarCntType : STRUCT (*Count of the reference pulse*)
		PVMapping : STRING[250]; (*Input source for the reference pulse count*)
	END_STRUCT;
	McSAELOEExtRefPVarType : STRUCT (*Type mcSAELOEERP_VAR settings*)
		Position : McSAELOEExtRefPVarPosType; (*Position of the reference pulse*)
		Count : McSAELOEExtRefPVarCntType; (*Count of the reference pulse*)
	END_STRUCT;
	McSAELOEExtRefPType : STRUCT (*Check if given position is valid*)
		Type : McSAELOEExtRefPEnum; (*Reference pulse selector setting*)
		IOChannel : McSAELOEExtRefPIOChType; (*Type mcSAELOEERP_IO_CH settings*)
		Variable : McSAELOEExtRefPVarType; (*Type mcSAELOEERP_VAR settings*)
	END_STRUCT;
	McSAELOEEPosFltrEnum :
		( (*Position filter selector setting*)
		mcSAELOEEPF_EXTPOL_AND_DIST := 0 (*Extrapolation and disturbance - An extrapolation and disturbance filter is used*)
		);
	McSAELOEEPosFltrExtpolDistType : STRUCT (*Type mcSAELOEEPF_EXTPOL_AND_DIST settings*)
		PositionFilterTimeConstant : REAL; (*Time constant for actual position filter*)
		ExtrapolationTime : REAL; (*Extrapolation time for actual position filter*)
	END_STRUCT;
	McSAELOEEPosFltrType : STRUCT (*Filter for the encoder position*)
		Type : McSAELOEEPosFltrEnum; (*Position filter selector setting*)
		ExtrapolationAndDisturbance : McSAELOEEPosFltrExtpolDistType; (*Type mcSAELOEEPF_EXTPOL_AND_DIST settings*)
	END_STRUCT;
	McSAELOEPosEncExtType : STRUCT (*Type mcSAELOEPE_EXT settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		PositionType : McSAELOEExtPosTypType; (*Type of the encoder*)
		PositionSource : McSAELOEExtPosSrcType; (*Position source*)
		ValidityCheck : McSAELOEExtValCkType; (*Check if given position is valid*)
		ReferencePulse : McSAELOEExtRefPType; (*Check if given position is valid*)
		PositionFilter : McSAELOEEPosFltrType; (*Filter for the encoder position*)
	END_STRUCT;
	McSAELOEPosEncType : STRUCT
		Type : McSAELOEPosEncEnum; (*Position encoder selector setting*)
		StepCounter : McSAELOEPosEncStepCntType; (*Type mcSAELOEPE_STEP_CNT settings*)
		External : McSAELOEPosEncExtType; (*Type mcSAELOEPE_EXT settings*)
	END_STRUCT;
	McSAELOEType : STRUCT (*Type mcSAEL_ONE_ENC settings*)
		PositionEncoder : McSAELOEPosEncType;
	END_STRUCT;
	McSAELType : STRUCT
		Type : McSAELEnum; (*Encoder link selector setting*)
		OneEncoder : McSAELOEType; (*Type mcSAEL_ONE_ENC settings*)
	END_STRUCT;
	McSACModEnum :
		( (*Mode selector setting*)
		mcSACM_CUR_CTRL := 0, (*Current controller - Current controller is used*)
		mcSACM_POS_AND_CUR_CTRL := 1 (*Position and current controller - Position and current controller are used*)
		);
	McSACCurEnum :
		( (*Current selector setting*)
		mcSACC_STD := 0, (*Standard - Standard controller parameters are available*)
		mcSACC_SMART_CUR_CTRL := 1 (*Smart current control - Standard and smart current controller parameters are available*)
		);
	McSACCStdType : STRUCT (*Type mcSACC_STD settings*)
		StandstillCurrent : REAL; (*Current that is used when no movement is active [A]*)
		ConstantSpeedCurrent : REAL; (*Current that is used when a movement with a constant speed is active [A]*)
		SpeedChangeCurrent : REAL; (*Current that is used when the axis is accelerating or decelerating [A]*)
		FullStepThreshold : REAL; (*Speed of the motor where the driver switch from microstep to full step mode [rpm]*)
		MotorSettlingTime : REAL; (*Minimum time between when the motor is powered on to when the DrvOk bit is set. Setting is made in steps of 10 ms. [s]*)
		DelayedCurrentSwitchOff : REAL; (*Time for a delayed motor switch off after it is decelerated to zero because of a set time fault. Setting is made in steps of 100 ms. [s]*)
	END_STRUCT;
	McSACCSCCSCCActEnum :
		( (*Phases when smart current control is active.*)
		mcSACCSCCSCCA_CONST_SPD := 0, (*Constant speed - Active while axis is moving with a constant speed*)
		mcSACCSCCSCCA_PERM := 1 (*Permanently - Permanently active*)
		);
	McSACCSCCSCCCurRedEnum :
		( (*Maximum reduction of the set current [%]*)
		mcSACCSCCSCCCR_RED_50 := 0, (*Reduction 50 - Maximum reduction of 50%*)
		mcSACCSCCSCCCR_RED_25 := 1 (*Reduction 25 - Maximum reduction of 25%*)
		);
	McSACCSCCSCCRedActLvlEnum :
		( (*Current is decreased when the Motor load value is greater than or equal to this value as many times at it is configured at Reduction activation delay.*)
		mcSACCSCCSCCRAL_GT_992 := 0, (*Gt 992 - Activate if MotorLoad > 992*)
		mcSACCSCCSCCRAL_GT_960 := 1, (*Gt 960 - Activate if MotorLoad > 960*)
		mcSACCSCCSCCRAL_GT_928 := 2, (*Gt 928 - Activate if MotorLoad > 928*)
		mcSACCSCCSCCRAL_GT_896 := 3, (*Gt 896 - Activate if MotorLoad > 896*)
		mcSACCSCCSCCRAL_GT_864 := 4, (*Gt 864 - Activate if MotorLoad > 864*)
		mcSACCSCCSCCRAL_GT_832 := 5, (*Gt 832 - Activate if MotorLoad > 832*)
		mcSACCSCCSCCRAL_GT_800 := 6, (*Gt 800 - Activate if MotorLoad > 800*)
		mcSACCSCCSCCRAL_GT_768 := 7, (*Gt 768 - Activate if MotorLoad > 768*)
		mcSACCSCCSCCRAL_GT_736 := 8, (*Gt 736 - Activate if MotorLoad > 736*)
		mcSACCSCCSCCRAL_GT_704 := 9, (*Gt 704 - Activate if MotorLoad > 704*)
		mcSACCSCCSCCRAL_GT_672 := 10, (*Gt 672 - Activate if MotorLoad > 672*)
		mcSACCSCCSCCRAL_GT_640 := 11, (*Gt 640 - Activate if MotorLoad > 640*)
		mcSACCSCCSCCRAL_GT_608 := 12, (*Gt 608 - Activate if MotorLoad > 608*)
		mcSACCSCCSCCRAL_GT_576 := 13, (*Gt 576 - Activate if MotorLoad > 576*)
		mcSACCSCCSCCRAL_GT_544 := 14, (*Gt 544 - Activate if MotorLoad > 544*)
		mcSACCSCCSCCRAL_GT_512 := 15, (*Gt 512 - Activate if MotorLoad > 512*)
		mcSACCSCCSCCRAL_GT_480 := 16, (*Gt 480 - Activate if MotorLoad > 480*)
		mcSACCSCCSCCRAL_GT_448 := 17, (*Gt 448 - Activate if MotorLoad > 448*)
		mcSACCSCCSCCRAL_GT_416 := 18, (*Gt 416 - Activate if MotorLoad > 416*)
		mcSACCSCCSCCRAL_GT_384 := 19, (*Gt 384 - Activate if MotorLoad > 384*)
		mcSACCSCCSCCRAL_GT_352 := 20, (*Gt 352 - Activate if MotorLoad > 352*)
		mcSACCSCCSCCRAL_GT_320 := 21, (*Gt 320 - Activate if MotorLoad > 320*)
		mcSACCSCCSCCRAL_GT_288 := 22, (*Gt 288 - Activate if MotorLoad > 288*)
		mcSACCSCCSCCRAL_GT_256 := 23, (*Gt 256 - Activate if MotorLoad > 256*)
		mcSACCSCCSCCRAL_GT_224 := 24, (*Gt 224 - Activate if MotorLoad > 224*)
		mcSACCSCCSCCRAL_GT_192 := 25, (*Gt 192 - Activate if MotorLoad > 192*)
		mcSACCSCCSCCRAL_GT_160 := 26, (*Gt 160 - Activate if MotorLoad > 160*)
		mcSACCSCCSCCRAL_GT_128 := 27, (*Gt 128 - Activate if MotorLoad > 128*)
		mcSACCSCCSCCRAL_GT_96 := 28, (*Gt 96 - Activate if MotorLoad > 96*)
		mcSACCSCCSCCRAL_GT_64 := 29 (*Gt 64 - Activate if MotorLoad > 64*)
		);
	McSACCSCCSCCRedActDlyEnum :
		( (*Number of MotorLoad measured values that are greater than or equal to the Reduction activation level value, in order to decrease current. [Measured values]*)
		mcSACCSCCSCCRAD_VAL_8 := 0, (*Values 8 - 8 measured values*)
		mcSACCSCCSCCRAD_VAL_1 := 1, (*Values 1 - 1 measured values*)
		mcSACCSCCSCCRAD_VAL_2 := 2, (*Values 2 - 2 measured values*)
		mcSACCSCCSCCRAD_VAL_32 := 3 (*Values 32 - 32 measured values*)
		);
	McSACCSCCSCCRedRstLvlEnum :
		( (*Current is increased when the Motor load value is less than or equal to this value as many times at it is configured at Reduction reset delay.*)
		mcSACCSCCSCCRRL_LT_32 := 0, (*Lt 32 - Reset if MotorLoad < 32*)
		mcSACCSCCSCCRRL_LT_64 := 1, (*Lt 64 - Reset if MotorLoad < 64*)
		mcSACCSCCSCCRRL_LT_96 := 2, (*Lt 96 - Reset if MotorLoad < 96*)
		mcSACCSCCSCCRRL_LT_128 := 3, (*Lt 128 - Reset if MotorLoad < 128*)
		mcSACCSCCSCCRRL_LT_160 := 4, (*Lt 160 - Reset if MotorLoad < 160*)
		mcSACCSCCSCCRRL_LT_192 := 5, (*Lt 192 - Reset if MotorLoad < 192*)
		mcSACCSCCSCCRRL_LT_224 := 6, (*Lt 224 - Reset if MotorLoad < 224*)
		mcSACCSCCSCCRRL_LT_256 := 7, (*Lt 256 - Reset if MotorLoad < 256*)
		mcSACCSCCSCCRRL_LT_288 := 8, (*Lt 288 - Reset if MotorLoad < 288*)
		mcSACCSCCSCCRRL_LT_320 := 9, (*Lt 320 - Reset if MotorLoad < 320*)
		mcSACCSCCSCCRRL_LT_352 := 10, (*Lt 352 - Reset if MotorLoad < 352*)
		mcSACCSCCSCCRRL_LT_384 := 11, (*Lt 384 - Reset if MotorLoad < 384*)
		mcSACCSCCSCCRRL_LT_416 := 12, (*Lt 416 - Reset if MotorLoad < 416*)
		mcSACCSCCSCCRRL_LT_448 := 13, (*Lt 448 - Reset if MotorLoad < 448*)
		mcSACCSCCSCCRRL_LT_480 := 14 (*Lt 480 - Reset if MotorLoad < 480*)
		);
	McSACCSCCSCCRedRstDlyEnum :
		( (*Number of MotorLoad measured values that are less than or equal to the Reduction reset level value, in order to increase current. [Measured values]*)
		mcSACCSCCSCCRRD_VAL_2 := 0, (*Values 2 - 2 measured values*)
		mcSACCSCCSCCRRD_VAL_1 := 1, (*Values 1 - 1 measured values*)
		mcSACCSCCSCCRRD_VAL_4 := 2, (*Values 4 - 4 measured values*)
		mcSACCSCCSCCRRD_VAL_8 := 3 (*Values 8 - 8 measured values*)
		);
	McSACCSCCSCCType : STRUCT (*Configuration for load dependent current control*)
		Active : McSACCSCCSCCActEnum; (*Phases when smart current control is active.*)
		CurrentReduction : McSACCSCCSCCCurRedEnum; (*Maximum reduction of the set current [%]*)
		ReductionActivationLevel : McSACCSCCSCCRedActLvlEnum; (*Current is decreased when the Motor load value is greater than or equal to this value as many times at it is configured at Reduction activation delay.*)
		ReductionActivationDelay : McSACCSCCSCCRedActDlyEnum; (*Number of MotorLoad measured values that are greater than or equal to the Reduction activation level value, in order to decrease current. [Measured values]*)
		ReductionResetLevel : McSACCSCCSCCRedRstLvlEnum; (*Current is increased when the Motor load value is less than or equal to this value as many times at it is configured at Reduction reset delay.*)
		ReductionResetDelay : McSACCSCCSCCRedRstDlyEnum; (*Number of MotorLoad measured values that are less than or equal to the Reduction reset level value, in order to increase current. [Measured values]*)
	END_STRUCT;
	McSACCSCCType : STRUCT (*Type mcSACC_SMART_CUR_CTRL settings*)
		StandstillCurrent : REAL; (*Current that is used when no movement is active [A]*)
		ConstantSpeedCurrent : REAL; (*Current that is used when a movement with a constant speed is active [A]*)
		SpeedChangeCurrent : REAL; (*Current that is used when the axis is accelerating or decelerating [A]*)
		FullStepThreshold : REAL; (*Speed of the motor where the driver switch from microstep to full step mode [rpm]*)
		MotorSettlingTime : REAL; (*Minimum time between when the motor is powered on to when the DrvOk bit is set. Setting is made in steps of 10 ms. [s]*)
		DelayedCurrentSwitchOff : REAL; (*Time for a delayed motor switch off after it is decelerated to zero because of a set time fault. Setting is made in steps of 100 ms. [s]*)
		SmartCurrentControl : McSACCSCCSCCType; (*Configuration for load dependent current control*)
	END_STRUCT;
	McSACCurType : STRUCT (*Current controller parameters*)
		Type : McSACCurEnum; (*Current selector setting*)
		Standard : McSACCStdType; (*Type mcSACC_STD settings*)
		SmartCurrentControl : McSACCSCCType; (*Type mcSACC_SMART_CUR_CTRL settings*)
	END_STRUCT;
	McSACModCurCtrlType : STRUCT (*Type mcSACM_CUR_CTRL settings*)
		Current : McSACCurType; (*Current controller parameters*)
	END_STRUCT;
	McSACModPosAndCurCtrlPosType : STRUCT (*Position controller parameters*)
		ProportionalGain : REAL; (*Proportional amplification [1/s]*)
		MaximumProportionalAction : REAL; (*Maximum proportional action [Measurement units/s]*)
		PredictionTime : REAL; (*Prediction time [s]*)
		TotalDelayTime : REAL; (*Total delay time [s]*)
	END_STRUCT;
	McSACModPosAndCurCtrlType : STRUCT (*Type mcSACM_POS_AND_CUR_CTRL settings*)
		Current : McSACCurType; (*Current controller parameters*)
		Position : McSACModPosAndCurCtrlPosType; (*Position controller parameters*)
	END_STRUCT;
	McSACModType : STRUCT (*Mode of the axis controller*)
		Type : McSACModEnum; (*Mode selector setting*)
		CurrentController : McSACModCurCtrlType; (*Type mcSACM_CUR_CTRL settings*)
		PositionAndCurrentController : McSACModPosAndCurCtrlType; (*Type mcSACM_POS_AND_CUR_CTRL settings*)
	END_STRUCT;
	McSACType : STRUCT (*Axis controller parameters*)
		Mode : McSACModType; (*Mode of the axis controller*)
	END_STRUCT;
	McSAHModEnum :
		( (*Mode selector setting*)
		mcSAHM_DIR := 0, (*Direct - Direct homing*)
		mcSAHM_ABS_SW := 1, (*Absolute switch - Homing with absolute reference switch*)
		mcSAHM_SW_GATE := 2, (*Switch gate - Homing with reference switch gate*)
		mcSAHM_LIM_SW := 3, (*Limit switch - Homing with hardware end switch*)
		mcSAHM_ABS := 4, (*Absolute - Homing by setting the home offset*)
		mcSAHM_ABS_CORR := 5, (*Absolute correction - Homing by setting the home offset with counting range correction*)
		mcSAHM_BLK_LAG_ERR := 9, (*Block lag error - Homing on block, criterion for homing event: lag error*)
		mcSAHM_RES_POS := 10, (*Restore position - Homing by restoring the position from remanent variable data*)
		mcSAHM_NOT_USE := 100 (*Not used - No preconfigured homing settings used*)
		);
	McSAHModDirRefPEnum :
		( (*Reference pulse selector setting*)
		mcSAHMDRP_NOT_USE := 0, (*Not used - Reference pulse is not used*)
		mcSAHMDRP_USE := 1 (*Used - Reference pulse is used*)
		);
	McSAHModHomeDirEnum :
		( (*Movement direction in which the homing event is evaluated*)
		mcSAHMHD_POS := 0, (*Positive - Positive movement direction*)
		mcSAHMHD_NEG := 1 (*Negative - Negative movement direction*)
		);
	McSAHModKeepDirEnum :
		( (*Keep direction (move only in one direction)*)
		mcSAHMKD_NO := 0, (*No - mcSWITCH_OFF*)
		mcSAHMKD_YES := 1 (*Yes - mcSWITCH_ON*)
		);
	McSAHModDirRefPUseType : STRUCT (*Type mcSAHMDRP_USE settings*)
		HomingVelocity : REAL; (*Speed which is used while searching for the homing event (e.g. after reference switch has been reached) [Measurement units/s]*)
		Acceleration : REAL; (*Acceleration for homing movement [Measurement units/s²]*)
		HomingDirection : McSAHModHomeDirEnum; (*Movement direction in which the homing event is evaluated*)
		KeepDirection : McSAHModKeepDirEnum; (*Keep direction (move only in one direction)*)
		ReferencePulseBlockingDistance : LREAL; (*Distance for blocking the activation of triggering reference pulse [Measurement units]*)
	END_STRUCT;
	McSAHModDirRefPType : STRUCT (*Use reference pulse of encoder*)
		Type : McSAHModDirRefPEnum; (*Reference pulse selector setting*)
		Used : McSAHModDirRefPUseType; (*Type mcSAHMDRP_USE settings*)
	END_STRUCT;
	McSAHModDirType : STRUCT (*Type mcSAHM_DIR settings*)
		Position : LREAL; (*Home position [Measurement units]*)
		ReferencePulse : McSAHModDirRefPType; (*Use reference pulse of encoder*)
	END_STRUCT;
	McSAHModSwEdgEnum :
		( (*Edge of reference switch*)
		mcSAHMSE_POS := 0, (*Positive - Positive switch edge*)
		mcSAHMSE_NEG := 1 (*Negative - Negative switch edge*)
		);
	McSAHModRefPEnum :
		( (*Reference pulse selector setting*)
		mcSAHMRP_NOT_USE := 0, (*Not used - Reference pulse is not used*)
		mcSAHMRP_USE := 1 (*Used - Reference pulse is used*)
		);
	McSAHModRefPUseType : STRUCT (*Type mcSAHMRP_USE settings*)
		ReferencePulseBlockingDistance : LREAL; (*Distance for blocking the activation of triggering reference pulse [Measurement units]*)
	END_STRUCT;
	McSAHModRefPType : STRUCT (*Use reference pulse of encoder*)
		Type : McSAHModRefPEnum; (*Reference pulse selector setting*)
		Used : McSAHModRefPUseType; (*Type mcSAHMRP_USE settings*)
	END_STRUCT;
	McSAHModAbsSwType : STRUCT (*Type mcSAHM_ABS_SW settings*)
		Position : LREAL; (*Home position [Measurement units]*)
		StartVelocity : REAL; (*Speed for searching the reference switch [Measurement units/s]*)
		HomingVelocity : REAL; (*Speed which is used while searching for the homing event (e.g. after reference switch has been reached) [Measurement units/s]*)
		Acceleration : REAL; (*Acceleration for homing movement [Measurement units/s²]*)
		SwitchEdge : McSAHModSwEdgEnum; (*Edge of reference switch*)
		HomingDirection : McSAHModHomeDirEnum; (*Movement direction in which the homing event is evaluated*)
		KeepDirection : McSAHModKeepDirEnum; (*Keep direction (move only in one direction)*)
		ReferencePulse : McSAHModRefPType; (*Use reference pulse of encoder*)
	END_STRUCT;
	McSAHModStartDirEnum :
		( (*Start direction of movement for searching the reference switch*)
		mcSAHMSD_POS := 0, (*Positive - Positive movement direction*)
		mcSAHMSD_NEG := 1 (*Negative - Negative movement direction*)
		);
	McSAHModSwGateType : STRUCT (*Type mcSAHM_SW_GATE settings*)
		Position : LREAL; (*Home position [Measurement units]*)
		StartVelocity : REAL; (*Speed for searching the reference switch [Measurement units/s]*)
		HomingVelocity : REAL; (*Speed which is used while searching for the homing event (e.g. after reference switch has been reached) [Measurement units/s]*)
		Acceleration : REAL; (*Acceleration for homing movement [Measurement units/s²]*)
		SwitchEdge : McSAHModSwEdgEnum; (*Edge of reference switch*)
		StartDirection : McSAHModStartDirEnum; (*Start direction of movement for searching the reference switch*)
		HomingDirection : McSAHModHomeDirEnum; (*Movement direction in which the homing event is evaluated*)
		KeepDirection : McSAHModKeepDirEnum; (*Keep direction (move only in one direction)*)
		ReferencePulse : McSAHModRefPType; (*Use reference pulse of encoder*)
	END_STRUCT;
	McSAHModLimSwType : STRUCT (*Type mcSAHM_LIM_SW settings*)
		Position : LREAL; (*Home position [Measurement units]*)
		StartVelocity : REAL; (*Speed for searching the reference switch [Measurement units/s]*)
		HomingVelocity : REAL; (*Speed which is used while searching for the homing event (e.g. after reference switch has been reached) [Measurement units/s]*)
		Acceleration : REAL; (*Acceleration for homing movement [Measurement units/s²]*)
		SwitchEdge : McSAHModSwEdgEnum; (*Edge of reference switch*)
		HomingDirection : McSAHModHomeDirEnum; (*Movement direction in which the homing event is evaluated*)
		KeepDirection : McSAHModKeepDirEnum; (*Keep direction (move only in one direction)*)
		ReferencePulse : McSAHModRefPType; (*Use reference pulse of encoder*)
	END_STRUCT;
	McSAHModAbsType : STRUCT (*Type mcSAHM_ABS settings*)
		Position : LREAL; (*Home offset [Measurement units]*)
	END_STRUCT;
	McSAHModAbsCorrType : STRUCT (*Type mcSAHM_ABS_CORR settings*)
		Position : LREAL; (*Home offset [Measurement units]*)
	END_STRUCT;
	McSAHModBlkRefPNotUseType : STRUCT (*Type mcSAHMRP_NOT_USE settings*)
		MinimumReturnDistance : LREAL; (*Minimum return distance after the blockade is reached [Measurement units]*)
	END_STRUCT;
	McSAHModBlkRefPUseType : STRUCT (*Type mcSAHMRP_USE settings*)
		ReferencePulseBlockingDistance : LREAL; (*Distance for blocking the activation of triggering reference pulse [Measurement units]*)
	END_STRUCT;
	McSAHModBlkRefPType : STRUCT (*Use reference pulse of encoder*)
		Type : McSAHModRefPEnum; (*Reference pulse selector setting*)
		NotUsed : McSAHModBlkRefPNotUseType; (*Type mcSAHMRP_NOT_USE settings*)
		Used : McSAHModBlkRefPUseType; (*Type mcSAHMRP_USE settings*)
	END_STRUCT;
	McSAHModBlkLagErrType : STRUCT (*Type mcSAHM_BLK_LAG_ERR settings*)
		Position : LREAL; (*Home position [Measurement units]*)
		StartVelocity : REAL; (*Speed for searching the reference switch [Measurement units/s]*)
		HomingVelocity : REAL; (*Speed which is used while searching for the homing event (e.g. after reference switch has been reached) [Measurement units/s]*)
		Acceleration : REAL; (*Acceleration for homing movement [Measurement units/s²]*)
		StartDirection : McSAHModStartDirEnum; (*Start direction of movement for searching the reference switch*)
		HomingDirection : McSAHModHomeDirEnum; (*Movement direction in which the homing event is evaluated*)
		ReferencePulse : McSAHModBlkRefPType; (*Use reference pulse of encoder*)
		PositionErrorStopLimit : LREAL; (*Lag error for stop of the homing movement [Measurement units]*)
		BlockDetectionPositionError : LREAL; (*Lag error for block detection [Measurement units]*)
	END_STRUCT;
	McSAHModType : STRUCT (*Homing mode*)
		Type : McSAHModEnum; (*Mode selector setting*)
		Direct : McSAHModDirType; (*Type mcSAHM_DIR settings*)
		AbsoluteSwitch : McSAHModAbsSwType; (*Type mcSAHM_ABS_SW settings*)
		SwitchGate : McSAHModSwGateType; (*Type mcSAHM_SW_GATE settings*)
		LimitSwitch : McSAHModLimSwType; (*Type mcSAHM_LIM_SW settings*)
		Absolute : McSAHModAbsType; (*Type mcSAHM_ABS settings*)
		AbsoluteCorrection : McSAHModAbsCorrType; (*Type mcSAHM_ABS_CORR settings*)
		BlockLagError : McSAHModBlkLagErrType; (*Type mcSAHM_BLK_LAG_ERR settings*)
	END_STRUCT;
	McSAHType : STRUCT (*Homing mode and parameters which can be used within the application program as preconfigured setting*)
		Mode : McSAHModType; (*Homing mode*)
		RestorePositionVariable : STRING[250]; (*Remanent variable used for homing mode: Restore position*)
	END_STRUCT;
	McSASRDEEnum :
		( (*Drive error selector setting*)
		mcSASRDE_DEC_LIM := 0, (*Deceleration limit - Stop with deceleration limits*)
		mcSASRDE_COAST_TO_STANDSTILL := 1 (*Coast to standstill - Controller is deactivated*)
		);
	McSASRDEType : STRUCT (*Deceleration ramp / reaction in case of an error stop which is caused by a drive error*)
		Type : McSASRDEEnum; (*Drive error selector setting*)
	END_STRUCT;
	McSASRType : STRUCT (*Reactions of the axis in case of certain stop conditions*)
		DriveError : McSASRDEType; (*Deceleration ramp / reaction in case of an error stop which is caused by a drive error*)
	END_STRUCT;
	McSAMELStallDetectCfgEnum :
		( (*Stall detection configuration selector setting*)
		mcSAMELSDC_NOT_USE := 0, (*Not used -*)
		mcSAMELSDC_USE := 1 (*Used -*)
		);
	McSAMELStallDetectCfgUseReacEnum :
		( (*Reaction if a stall error is detected*)
		mcSAMELSDCUR_ERRORSTOP := 0, (*Errorstop - Axis will perform an error stop based on the configured behavior at Stop reaction - Drive error*)
		mcSAMELSDCUR_WARNING := 1 (*Warning - A warning will be entered into the logger*)
		);
	McSAMELStallDetectCfgUseType : STRUCT (*Type mcSAMELSDC_USE settings*)
		Reaction : McSAMELStallDetectCfgUseReacEnum; (*Reaction if a stall error is detected*)
		StallDetectionThreshold : USINT; (*Configuration stall detection threshold motor*)
		StallDetectionMinimumSpeed : REAL; (*Speed threshold for activating the stall detection of motor. Should be at least one revolution per second. [rpm]*)
		MixedDecayThreshold : USINT; (*Configuration mixed decay threshold motor*)
	END_STRUCT;
	McSAMELStallDetectCfgType : STRUCT (*Stall detection configuration*)
		Type : McSAMELStallDetectCfgEnum; (*Stall detection configuration selector setting*)
		Used : McSAMELStallDetectCfgUseType; (*Type mcSAMELSDC_USE settings*)
	END_STRUCT;
	McSAMELStallguardCfgEnum :
		( (*Stallguard configuration selector setting*)
		mcSAMELSC_NOT_USE := 0, (*Not used -*)
		mcSAMELSC_USE := 1 (*Used -*)
		);
	McSAMELStallguardCfgUseReacEnum :
		( (*Reaction if a stall error is detected*)
		mcSAMELSCUR_ERRORSTOP := 0, (*Errorstop - Axis will perform an error stop based on the configured behavior at Stop reaction - Drive error*)
		mcSAMELSCUR_WARNING := 1 (*Warning - A warning will be entered into the logger*)
		);
	McSAMELStallguardCfgUseType : STRUCT (*Type mcSAMELSC_USE settings*)
		Reaction : McSAMELStallguardCfgUseReacEnum; (*Reaction if a stall error is detected*)
		StallDetectionMinimumSpeed : REAL; (*Velocity threshold for activating the stall detection of motor. Should be at least one revolution per second. [rpm]*)
		StallDetectionSpeedA : REAL; (*Velocity A for motor load curve [rpm]*)
		StallDetectionValueA : SINT; (*Sensitivity A for motor load curve*)
		StallDetectionSpeedB : REAL; (*Velocity B for motor load curve [rpm]*)
		StallDetectionValueB : SINT; (*Sensitivity B for motor load curve*)
	END_STRUCT;
	McSAMELStallguardCfgType : STRUCT (*Stall detection configuration*)
		Type : McSAMELStallguardCfgEnum; (*Stallguard configuration selector setting*)
		Used : McSAMELStallguardCfgUseType; (*Type mcSAMELSC_USE settings*)
	END_STRUCT;
	McSAMELType : STRUCT (*Limit values that result in a stop reaction when exceeded*)
		PositionError : LREAL; (*Lag error limit for stopping a movement [Measurement units]*)
		StallDetectionConfiguration : McSAMELStallDetectCfgType; (*Stall detection configuration*)
		StallguardConfiguration : McSAMELStallguardCfgType; (*Stall detection configuration*)
	END_STRUCT;
	McSAJFEnum :
		( (*Jerk filter selector setting*)
		mcSAJF_NOT_USE := 0, (*Not used - No jerk filter is applied*)
		mcSAJF_USE := 1, (*Used - Jerk filter is applied*)
		mcSAJF_JERK_LIM := 2 (*Jerk limited - Jerk is considered in the profile generator*)
		);
	McSAJFUseType : STRUCT (*Type mcSAJF_USE settings*)
		MaximumJerkTime : REAL; (*Maximum configurable jerk filter time [s]*)
		JerkTime : REAL; (*Jerk filter time [s]*)
	END_STRUCT;
	McSAJFJerkLimType : STRUCT (*Type mcSAJF_JERK_LIM settings*)
		JerkLimit : REAL; (*Jerk limit in any movement direction [Measurement units/s³]*)
	END_STRUCT;
	McSAJFType : STRUCT (*Jerk filter*)
		Type : McSAJFEnum; (*Jerk filter selector setting*)
		Used : McSAJFUseType; (*Type mcSAJF_USE settings*)
		JerkLimited : McSAJFJerkLimType; (*Type mcSAJF_JERK_LIM settings*)
	END_STRUCT;
	McSADIAllSrcEnum :
		( (*Source selector setting*)
		mcSADIAS_NOT_USE := 0, (*Not used -*)
		mcSADIAS_VAR := 1, (*Variable -*)
		mcSADIAS_DIG_IN_TRG_1 := 2, (*Digital in Trigger 1 -*)
		mcSADIAS_DIG_IN_TRG_2 := 3, (*Digital in Trigger 2 -*)
		mcSADIAS_DIG_IN_1 := 4, (*Digital input 1 -*)
		mcSADIAS_DIG_IN_2 := 5, (*Digital input 2 -*)
		mcSADIAS_DIG_IN_3 := 6, (*Digital input 3 -*)
		mcSADIAS_DIG_IN_4 := 7, (*Digital input 4 -*)
		mcSADIAS_DIG_IN_5 := 8, (*Digital input 5 -*)
		mcSADIAS_DIG_IN_6 := 9, (*Digital input 6 -*)
		mcSADIAS_IO_CH := 10 (*I/O channel - Get value from an I/O channel*)
		);
	McSADIAllSrcVarTSEnum :
		( (*Time stamp selector setting*)
		mcSADIAllSVTS_NOT_USE := 0, (*Not used - Not used*)
		mcSADIAllSVTS_USE := 1, (*Used - Used*)
		mcSADIAllSVTS_RIS_AND_FALL_EDG := 2 (*Rising and falling edge - Detect the trigger by using a rising and a falling time stamp*)
		);
	McSADIAllSrcVarTSUseType : STRUCT (*Type mcSADIAllSVTS_USE settings*)
		PVMapping : STRING[250]; (*Name of the process variable (DINT) representing trigger time stamp*)
	END_STRUCT;
	McSADIASVTSRAFERECntType : STRUCT (*Count*)
		PVMapping : STRING[250]; (*Name of the process variable (SINT) representing the rising trigger edge count*)
	END_STRUCT;
	McSADIASVTSRAFERETimStmpType : STRUCT (*Time stamp*)
		PVMapping : STRING[250]; (*Name of the process variable (INT) representing the rising trigger edge time*)
	END_STRUCT;
	McSADIASVTSRAFERisEdgType : STRUCT (*Parameters for the rising trigger edge*)
		Count : McSADIASVTSRAFERECntType; (*Count*)
		TimeStamp : McSADIASVTSRAFERETimStmpType; (*Time stamp*)
	END_STRUCT;
	McSADIASVTSRAFEFECntType : STRUCT (*Count*)
		PVMapping : STRING[250]; (*Name of the process variable (SINT) representing the falling trigger edge count*)
	END_STRUCT;
	McSADIASVTSRAFEFETimStmpType : STRUCT (*Time stamp*)
		PVMapping : STRING[250]; (*Name of the process variable (INT) representing the falling trigger edge time*)
	END_STRUCT;
	McSADIASVTSRAFEFallEdgType : STRUCT (*Parameters for the falling trigger edge*)
		Count : McSADIASVTSRAFEFECntType; (*Count*)
		TimeStamp : McSADIASVTSRAFEFETimStmpType; (*Time stamp*)
	END_STRUCT;
	McSADIASVTSRisAndFallEdgType : STRUCT (*Type mcSADIAllSVTS_RIS_AND_FALL_EDG settings*)
		RisingEdge : McSADIASVTSRAFERisEdgType; (*Parameters for the rising trigger edge*)
		FallingEdge : McSADIASVTSRAFEFallEdgType; (*Parameters for the falling trigger edge*)
	END_STRUCT;
	McSADIAllSrcVarTSType : STRUCT (*Trigger time stamp*)
		Type : McSADIAllSrcVarTSEnum; (*Time stamp selector setting*)
		Used : McSADIAllSrcVarTSUseType; (*Type mcSADIAllSVTS_USE settings*)
		RisingAndFallingEdge : McSADIASVTSRisAndFallEdgType; (*Type mcSADIAllSVTS_RIS_AND_FALL_EDG settings*)
	END_STRUCT;
	McSADIAllSrcVarType : STRUCT (*Type mcSADIAS_VAR settings*)
		PVMapping : STRING[250]; (*Name of the process variable (BOOL) representing trigger*)
		TimeStamp : McSADIAllSrcVarTSType; (*Trigger time stamp*)
	END_STRUCT;
	McSADIAllSrcIOChTSEnum :
		( (*Time stamp selector setting*)
		mcSADIAllSIOCTS_NOT_USE := 0, (*Not used - Not used*)
		mcSADIAllSIOCTS_USE := 1, (*Used - Used*)
		mcSADIAllSIOCTS_RIS_AND_FALL_EDG := 2 (*Rising and falling edge - Detect the trigger by using a rising and a falling time stamp*)
		);
	McSADIAllSrcIOChTSUseType : STRUCT (*Type mcSADIAllSIOCTS_USE settings*)
		ChannelMapping : STRING[250]; (*Input source for representing the trigger time stamp*)
	END_STRUCT;
	McSADIASIOCTSRAFERECntType : STRUCT (*Count*)
		ChannelMapping : STRING[250]; (*Input source for representing the rising trigger edge count*)
	END_STRUCT;
	McSADIASIOCTSRAFERETimStmpType : STRUCT (*Time stamp*)
		ChannelMapping : STRING[250]; (*Input source for representing the rising trigger edge time*)
	END_STRUCT;
	McSADIASIOCTSRAFERisEdgType : STRUCT (*Parameters for the rising trigger edge*)
		Count : McSADIASIOCTSRAFERECntType; (*Count*)
		TimeStamp : McSADIASIOCTSRAFERETimStmpType; (*Time stamp*)
	END_STRUCT;
	McSADIASIOCTSRAFEFECntType : STRUCT (*Count*)
		ChannelMapping : STRING[250]; (*Input source for representing the falling trigger edge count*)
	END_STRUCT;
	McSADIASIOCTSRAFEFETimStmpType : STRUCT (*Time stamp*)
		ChannelMapping : STRING[250]; (*Input source for representing the falling trigger edge time*)
	END_STRUCT;
	McSADIASIOCTSRAFEFallEdgType : STRUCT (*Parameters for the falling trigger edge*)
		Count : McSADIASIOCTSRAFEFECntType; (*Count*)
		TimeStamp : McSADIASIOCTSRAFEFETimStmpType; (*Time stamp*)
	END_STRUCT;
	McSADIASIOCTSRisAndFallEdgType : STRUCT (*Type mcSADIAllSIOCTS_RIS_AND_FALL_EDG settings*)
		RisingEdge : McSADIASIOCTSRAFERisEdgType; (*Parameters for the rising trigger edge*)
		FallingEdge : McSADIASIOCTSRAFEFallEdgType; (*Parameters for the falling trigger edge*)
	END_STRUCT;
	McSADIAllSrcIOChTSType : STRUCT (*Trigger time stamp*)
		Type : McSADIAllSrcIOChTSEnum; (*Time stamp selector setting*)
		Used : McSADIAllSrcIOChTSUseType; (*Type mcSADIAllSIOCTS_USE settings*)
		RisingAndFallingEdge : McSADIASIOCTSRisAndFallEdgType; (*Type mcSADIAllSIOCTS_RIS_AND_FALL_EDG settings*)
	END_STRUCT;
	McSADIAllSrcIOChType : STRUCT (*Type mcSADIAS_IO_CH settings*)
		ChannelMapping : STRING[250]; (*Channel input source*)
		TimeStamp : McSADIAllSrcIOChTSType; (*Trigger time stamp*)
	END_STRUCT;
	McSADIAllSrcType : STRUCT (*Source of the digital input hardware which is used for this functionality*)
		Type : McSADIAllSrcEnum; (*Source selector setting*)
		Variable : McSADIAllSrcVarType; (*Type mcSADIAS_VAR settings*)
		IOChannel : McSADIAllSrcIOChType; (*Type mcSADIAS_IO_CH settings*)
	END_STRUCT;
	McSADIHomeSwLvlEnum :
		( (*Level of the digital input hardware which leads to an active level of the functionality*)
		mcSADIHSL_LOW := 0, (*Low*)
		mcSADIHSL_HIGH := 1 (*High*)
		);
	McSADIHomeSwType : STRUCT (*Homing switch input functionality*)
		Source : McSADIAllSrcType; (*Source of the digital input hardware which is used for this functionality*)
		Level : McSADIHomeSwLvlEnum; (*Level of the digital input hardware which leads to an active level of the functionality*)
	END_STRUCT;
	McSADIPosLimSwLvlEnum :
		( (*Level of the digital input hardware which leads to an active level of the functionality*)
		mcSADIPLSL_LOW := 0, (*Low*)
		mcSADIPLSL_HIGH := 1 (*High*)
		);
	McSADIPosLimSwType : STRUCT (*Positive limit switch input functionality*)
		Source : McSADIAllSrcType; (*Source of the digital input hardware which is used for this functionality*)
		Level : McSADIPosLimSwLvlEnum; (*Level of the digital input hardware which leads to an active level of the functionality*)
	END_STRUCT;
	McSADINegLimSwLvlEnum :
		( (*Level of the digital input hardware which leads to an active level of the functionality*)
		mcSADINLSL_LOW := 0, (*Low*)
		mcSADINLSL_HIGH := 1 (*High*)
		);
	McSADINegLimSwType : STRUCT (*Negative limit switch input functionality*)
		Source : McSADIAllSrcType; (*Source of the digital input hardware which is used for this functionality*)
		Level : McSADINegLimSwLvlEnum; (*Level of the digital input hardware which leads to an active level of the functionality*)
	END_STRUCT;
	McSADITrg1LvlEnum :
		( (*Level of the digital input hardware which leads to an active level of the functionality*)
		mcSADIT1L_LOW := 0, (*Low*)
		mcSADIT1L_HIGH := 1 (*High*)
		);
	McSADITrg1Type : STRUCT (*Trigger 1 input functionality*)
		Source : McSADIAllSrcType; (*Source of the digital input hardware which is used for this functionality*)
		Level : McSADITrg1LvlEnum; (*Level of the digital input hardware which leads to an active level of the functionality*)
	END_STRUCT;
	McSADITrg2LvlEnum :
		( (*Level of the digital input hardware which leads to an active level of the functionality*)
		mcSADIT2L_LOW := 0, (*Low*)
		mcSADIT2L_HIGH := 1 (*High*)
		);
	McSADITrg2Type : STRUCT (*Trigger 2 input functionality*)
		Source : McSADIAllSrcType; (*Source of the digital input hardware which is used for this functionality*)
		Level : McSADITrg2LvlEnum; (*Level of the digital input hardware which leads to an active level of the functionality*)
	END_STRUCT;
	McSADIQstopInEnum :
		( (*Input selector setting*)
		mcSADIQI_NOT_USE := 0, (*Not used -*)
		mcSADIQI_TRG_1 := 1, (*Trigger 1 -*)
		mcSADIQI_TRG_2 := 2, (*Trigger 2 -*)
		mcSADIQI_POS_LIM_SW := 3, (*Positive limit switch -*)
		mcSADIQI_NEG_LIM_SW := 4, (*Negative limit switch -*)
		mcSADIQI_HOME_SW := 5, (*Homing switch -*)
		mcSADIQI_VAR := 6, (*Variable -*)
		mcSADIQI_IO_CH := 7 (*I/O channel - Get value from an I/O channel*)
		);
	McSADIQstopInVarType : STRUCT (*Type mcSADIQI_VAR settings*)
		PVMapping : STRING[250]; (*Name of the process variable (BOOL) representing trigger*)
	END_STRUCT;
	McSADIQstopInIOChType : STRUCT (*Type mcSADIQI_IO_CH settings*)
		ChannelMapping : STRING[250]; (*Channel input source*)
	END_STRUCT;
	McSADIQstopInType : STRUCT (*Digital input functionality triggering an axis quickstop*)
		Type : McSADIQstopInEnum; (*Input selector setting*)
		Variable : McSADIQstopInVarType; (*Type mcSADIQI_VAR settings*)
		IOChannel : McSADIQstopInIOChType; (*Type mcSADIQI_IO_CH settings*)
	END_STRUCT;
	McSADIQstopType : STRUCT (*Quickstop functionality*)
		Input : McSADIQstopInType; (*Digital input functionality triggering an axis quickstop*)
	END_STRUCT;
	McSADIType : STRUCT (*Various digital input functionalities e.g. like homing switch or triggers*)
		HomingSwitch : McSADIHomeSwType; (*Homing switch input functionality*)
		PositiveLimitSwitch : McSADIPosLimSwType; (*Positive limit switch input functionality*)
		NegativeLimitSwitch : McSADINegLimSwType; (*Negative limit switch input functionality*)
		Trigger1 : McSADITrg1Type; (*Trigger 1 input functionality*)
		Trigger2 : McSADITrg2Type; (*Trigger 2 input functionality*)
		Quickstop : McSADIQstopType; (*Quickstop functionality*)
	END_STRUCT;
	McSADOBCEnum :
		( (*Brake control selector setting*)
		mcSADOBC_NOT_USE := 0, (*Not used -*)
		mcSADOBC_USE := 1 (*Used -*)
		);
	McSADOBCUseDestEnum :
		( (*Destination selector setting*)
		mcSADOBCUD_VAR := 0, (*Variable -*)
		mcSADOBCUD_X224_VDC_BRK_OUT := 1 (*X2.24 VDC Brake output -*)
		);
	McSADOBCUseDestVarType : STRUCT (*Type mcSADOBCUD_VAR settings*)
		PVMapping : STRING[250]; (*Process variable to activate the holding brake.*)
	END_STRUCT;
	McSADOBCUseDestType : STRUCT (*Destination for the holding break*)
		Type : McSADOBCUseDestEnum; (*Destination selector setting*)
		Variable : McSADOBCUseDestVarType; (*Type mcSADOBCUD_VAR settings*)
	END_STRUCT;
	McSADOBCUseType : STRUCT (*Type mcSADOBC_USE settings*)
		Destination : McSADOBCUseDestType; (*Destination for the holding break*)
		ActivationDelay : REAL; (*Holding torque build-up time after switching off the operating voltage. [s]*)
		ReleaseDelay : REAL; (*Holding torque decaying time after switching on the operating voltage. [s]*)
	END_STRUCT;
	McSADOBCType : STRUCT (*Parameter of the holding break*)
		Type : McSADOBCEnum; (*Brake control selector setting*)
		Used : McSADOBCUseType; (*Type mcSADOBC_USE settings*)
	END_STRUCT;
	McSADOType : STRUCT (*Various digital output functionalities e.g. like brake*)
		BrakeControl : McSADOBCType; (*Parameter of the holding break*)
	END_STRUCT;
	McSAAFType : STRUCT (*Features for an axis*)
		FeatureReference : McCfgUnboundedArrayType; (*Name of the axis feature reference*)
	END_STRUCT;
	McCfgStpAxType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX*)
		AxisReference : McCfgReferenceType; (*Name of the referenced axis component*)
		MechanicalElements : McSAMEType; (*Parameter of hardware elements situated between motor encoder and load which influence the scaling*)
		Motor : McSAMType; (*Parameter to handle the motor*)
		EncoderLink : McSAELType;
		Controller : McSACType; (*Axis controller parameters*)
		Homing : McSAHType; (*Homing mode and parameters which can be used within the application program as preconfigured setting*)
		StopReaction : McSASRType; (*Reactions of the axis in case of certain stop conditions*)
		MovementErrorLimits : McSAMELType; (*Limit values that result in a stop reaction when exceeded*)
		JerkFilter : McSAJFType; (*Jerk filter*)
		DigitalInputs : McSADIType; (*Various digital input functionalities e.g. like homing switch or triggers*)
		DigitalOutputs : McSADOType; (*Various digital output functionalities e.g. like brake*)
		AxisFeatures : McSAAFType; (*Features for an axis*)
	END_STRUCT;
	McCfgStpAxRefType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_REF*)
		AxisReference : McCfgReferenceType; (*Name of the referenced axis component*)
	END_STRUCT;
	McCfgStpAxMechElmType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_MECH_ELM*)
		MechanicalElements : McSAMEType; (*Parameter of hardware elements situated between motor encoder and load which influence the scaling*)
	END_STRUCT;
	McCfgStpAxMotType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_MOT*)
		Motor : McSAMType; (*Parameter to handle the motor*)
	END_STRUCT;
	McCfgStpAxEncLinkType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_ENC_LINK*)
		EncoderLink : McSAELType;
	END_STRUCT;
	McCfgStpAxCtrlType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_CTRL*)
		Controller : McSACType; (*Axis controller parameters*)
	END_STRUCT;
	McCfgStpAxHomeType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_HOME*)
		Homing : McSAHType; (*Homing mode and parameters which can be used within the application program as preconfigured setting*)
	END_STRUCT;
	McCfgStpAxStopReacType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_STOP_REAC*)
		StopReaction : McSASRType; (*Reactions of the axis in case of certain stop conditions*)
	END_STRUCT;
	McCfgStpAxMoveErrLimType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_MOVE_ERR_LIM*)
		MovementErrorLimits : McSAMELType; (*Limit values that result in a stop reaction when exceeded*)
	END_STRUCT;
	McCfgStpAxJerkFltrType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_JERK_FLTR*)
		JerkFilter : McSAJFType; (*Jerk filter*)
	END_STRUCT;
	McCfgStpAxDigInType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_DIG_IN*)
		DigitalInputs : McSADIType; (*Various digital input functionalities e.g. like homing switch or triggers*)
	END_STRUCT;
	McCfgStpAxDigOutType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_DIG_OUT*)
		DigitalOutputs : McSADOType; (*Various digital output functionalities e.g. like brake*)
	END_STRUCT;
	McCfgStpAxFeatType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_AX_FEAT*)
		AxisFeatures : McSAAFType; (*Features for an axis*)
	END_STRUCT;
	McSEEncIfTypEnum :
		( (*Interface type selector setting*)
		mcSEIT_NOT_USE := 0, (*Not used -*)
		mcSEIT_INCR := 1 (*Incremental -*)
		);
	McSEIRefPSrcEnum :
		( (*Input source for the reference pulse*)
		mcSEIRPS_R_IN_ABR_ENC := 0, (*R input ABR encoder - R input of the ABR encoder*)
		mcSEIRPS_DIG_IN_3 := 1 (*Digital input 3 - 24V digital input 3*)
		);
	McSEIRefPEdgEnum :
		( (*Detection of the reference pulse*)
		mcSEIRPE_POS_EDG := 0, (*Positive edge - Detection with positive edge*)
		mcSEIRPE_NEG_EDG := 1 (*Negative edge - Detection with negative edge*)
		);
	McSEIType : STRUCT (*Type mcSEIT_INCR settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		ReferencePulseSource : McSEIRefPSrcEnum; (*Input source for the reference pulse*)
		ReferencePulseEdge : McSEIRefPEdgEnum; (*Detection of the reference pulse*)
	END_STRUCT;
	McSEEncIfTypType : STRUCT
		Type : McSEEncIfTypEnum; (*Interface type selector setting*)
		Incremental : McSEIType; (*Type mcSEIT_INCR settings*)
	END_STRUCT;
	McSEEncType : STRUCT
		InterfaceType : McSEEncIfTypType;
	END_STRUCT;
	McSEX6IfTypEnum :
		( (*Interface type selector setting*)
		mcSEX6IT_NOT_USE := 0, (*Not used -*)
		mcSEX6IT_INCR := 1 (*Incremental -*)
		);
	McSEX6IRefPSrcEnum :
		( (*Input source for the reference pulse*)
		mcSEX6IRPS_R_IN_ABR_ENC := 0, (*R input ABR encoder*)
		mcSEX6IRPS_DIG_IN_1 := 1, (*Digital input 1*)
		mcSEX6IRPS_DIG_IN_2 := 2 (*Digital input 2*)
		);
	McSEX6IRefPEdgEnum :
		( (*Detection of reference switch*)
		mcSEX6IRPE_POS_EDG := 0, (*Positive edge - Referencing with positive edge*)
		mcSEX6IRPE_NEG_EDG := 1, (*Negative edge - Referencing with negative edge*)
		mcSEX6IRPE_POS_AND_NEG_EDG := 2 (*Positive and negative edge - Referencing with positive and negative edge*)
		);
	McSEX6IBkWDetectEnum :
		( (*Broken wire detection*)
		mcSEX6IBWD_A_B := 0, (*A B - Encoder input A and B are checked*)
		mcSEX6IBWD_A_B_R := 1, (*A B R - Encoder input A, B and R are checked*)
		mcSEX6IBWD_NOT_USE := 2 (*Not used - Broken wire detection is switched off*)
		);
	McSEX6IType : STRUCT (*Type mcSEX6IT_INCR settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		ReferencePulseSource : McSEX6IRefPSrcEnum; (*Input source for the reference pulse*)
		ReferencePulseEdge : McSEX6IRefPEdgEnum; (*Detection of reference switch*)
		BrokenWireDetection : McSEX6IBkWDetectEnum; (*Broken wire detection*)
	END_STRUCT;
	McSEX6IfTypType : STRUCT
		Type : McSEX6IfTypEnum; (*Interface type selector setting*)
		Incremental : McSEX6IType; (*Type mcSEX6IT_INCR settings*)
	END_STRUCT;
	McSEX6Type : STRUCT
		InterfaceType : McSEX6IfTypType;
	END_STRUCT;
	McSEX6AIfTypEnum :
		( (*Interface type selector setting*)
		mcSEX6AIT_NOT_USE := 0, (*Not used -*)
		mcSEX6AIT_INCR := 1, (*Incremental -*)
		mcSEX6AIT_HF := 2, (*Hiperface -*)
		mcSEX6AIT_SSI := 3 (*SSI -*)
		);
	McSEX6AIRefPSrcEnum :
		( (*Input source for the reference pulse*)
		mcSEX6AIRPS_R_IN_ABR_ENC := 0, (*R input ABR encoder*)
		mcSEX6AIRPS_DIG_IN_1 := 1, (*Digital input 1*)
		mcSEX6AIRPS_DIG_IN_2 := 2 (*Digital input 2*)
		);
	McSEX6AIRefPEdgEnum :
		( (*Detection of reference switch*)
		mcSEX6AIRPE_POS_EDG := 0, (*Positive edge - Referencing with positive edge*)
		mcSEX6AIRPE_NEG_EDG := 1, (*Negative edge - Referencing with negative edge*)
		mcSEX6AIRPE_POS_AND_NEG_EDG := 2 (*Positive and negative edge - Referencing with positive and negative edge*)
		);
	McSEX6AIBkWDetectEnum :
		( (*Broken wire detection*)
		mcSEX6AIBWD_A_B := 0, (*A B - Encoder input A and B are checked*)
		mcSEX6AIBWD_A_B_R := 1, (*A B R - Encoder input A, B and R are checked*)
		mcSEX6AIBWD_NOT_USE := 2 (*Not used - Broken wire detection is switched off*)
		);
	McSEX6AIType : STRUCT (*Type mcSEX6AIT_INCR settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		ReferencePulseSource : McSEX6AIRefPSrcEnum; (*Input source for the reference pulse*)
		ReferencePulseEdge : McSEX6AIRefPEdgEnum; (*Detection of reference switch*)
		BrokenWireDetection : McSEX6AIBkWDetectEnum; (*Broken wire detection*)
	END_STRUCT;
	McSEX6AHPosRngType : STRUCT (*Defines the range of the position value*)
		LowerLimit : DINT; (*Lower limit of encoder range*)
		UpperLimit : UDINT; (*Upper limit of encoder range*)
	END_STRUCT;
	McSEX6AHSinCosTrkType : STRUCT
		VssMaximum : UINT; (*Maximum peak-to-peak amplitude [mV]*)
		VssMinimum : UINT; (*Minimum peak-to-peak amplitude [mV]*)
		VssQuittTime : UDINT; (*Validation period after Vss check error [µs]*)
	END_STRUCT;
	McSEX6AHHfBdRateEnum :
		( (*Select baud rate*)
		mcSEX6AHHBR_BD_RATE_1_200 := 0, (*Baud rate 1 200*)
		mcSEX6AHHBR_BD_RATE_2_400 := 1, (*Baud rate 2 400*)
		mcSEX6AHHBR_BD_RATE_4_800 := 2, (*Baud rate 4 800*)
		mcSEX6AHHBR_BD_RATE_9_600 := 3, (*Baud rate 9 600*)
		mcSEX6AHHBR_BD_RATE_19_200 := 4, (*Baud rate 19 200*)
		mcSEX6AHHBR_BD_RATE_38_400 := 5 (*Baud rate 38 400*)
		);
	McSEX6AHHfParEnum :
		( (*Select parity*)
		mcSEX6AHHP_NONE := 0, (*None*)
		mcSEX6AHHP_EVEN := 1, (*Even*)
		mcSEX6AHHP_ODD := 2 (*Odd*)
		);
	McSEX6AHHfType : STRUCT (*Hiperface RS485 interface configuration*)
		BaudRate : McSEX6AHHfBdRateEnum; (*Select baud rate*)
		Parity : McSEX6AHHfParEnum; (*Select parity*)
		ReceiveIdleTime : USINT; (*If no more receive data is detected within this time, data transfer is considered complete [bits]*)
		ReferenceStationAdress : USINT; (*Adress of the Sine/Cosine Reference station (255=broadcast)*)
		ReferencePositionWidth : USINT; (*Encoders acquisition width of position (absolute) [bits]*)
	END_STRUCT;
	McSEX6AHType : STRUCT (*Type mcSEX6AIT_HF settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		PositionRange : McSEX6AHPosRngType; (*Defines the range of the position value*)
		SineCosineTrack : McSEX6AHSinCosTrkType;
		Hiperface : McSEX6AHHfType; (*Hiperface RS485 interface configuration*)
	END_STRUCT;
	McSEX6ASPosRngType : STRUCT (*Defines the range of the position value*)
		LowerLimit : DINT; (*Lower limit of encoder range*)
		UpperLimit : UDINT; (*Upper limit of encoder range*)
	END_STRUCT;
	McSEX6ASClkRateEnum :
		( (*Clock rate*)
		mcSEX6ASCR_CLK_RATE_1_MHZ := 0, (*Clock rate 1 MHz*)
		mcSEX6ASCR_CLK_RATE_800_KHZ := 1, (*Clock rate 800 kHz*)
		mcSEX6ASCR_CLK_RATE_400_KHZ := 2, (*Clock rate 400 kHz*)
		mcSEX6ASCR_CLK_RATE_200_KHZ := 3, (*Clock rate 200 kHz*)
		mcSEX6ASCR_CLK_RATE_100_KHZ := 4 (*Clock rate 100 kHz*)
		);
	McSEX6ASEnc01TypEnum :
		( (*Encoder 01 type selector setting*)
		mcSEX6ASE0T_BUR_SSI := 0, (*BuR SSI -*)
		mcSEX6ASE0T_SSI_3P := 1 (*SSI 3rd Party -*)
		);
	McSEX6ASEnc01TypSSI3PDatFmtEnum :
		( (*Data format of SSI encoder*)
		mcSEX6ASE0TS3PDF_BIN := 0, (*Binary*)
		mcSEX6ASE0TS3PDF_GRAY := 1 (*Gray*)
		);
	McSEX6ASEnc01TypSSI3PParBitEnum :
		( (*Select parity mode*)
		mcSEX6ASE0TS3PPB_OFF := 0, (*Off*)
		mcSEX6ASE0TS3PPB_EVEN := 1, (*Even*)
		mcSEX6ASE0TS3PPB_ODD := 2, (*Odd*)
		mcSEX6ASE0TS3PPB_IGN := 3 (*Ignore*)
		);
	McSEX6ASEnc01TypSSI3PMCkEnum :
		( (*Select monoflop check mode*)
		mcSEX6ASE0TS3PMC_OFF := 0, (*Off*)
		mcSEX6ASE0TS3PMC_LOW := 1, (*Low*)
		mcSEX6ASE0TS3PMC_HIGH := 2 (*High*)
		);
	McSEX6ASEnc01TypSSI3PType : STRUCT (*Type mcSEX6ASE0T_SSI_3P settings*)
		DataFormat : McSEX6ASEnc01TypSSI3PDatFmtEnum; (*Data format of SSI encoder*)
		ValidSSIBitLength : USINT; (*Valid SSI bit length*)
		TotalSSIBitLength : USINT; (*Total SSI bit length*)
		ParityBit : McSEX6ASEnc01TypSSI3PParBitEnum; (*Select parity mode*)
		MonoflopCheck : McSEX6ASEnc01TypSSI3PMCkEnum; (*Select monoflop check mode*)
	END_STRUCT;
	McSEX6ASEnc01TypType : STRUCT (*BuR SSI encoder / 3rd Party SSI encoder*)
		Type : McSEX6ASEnc01TypEnum; (*Encoder 01 type selector setting*)
		SSI3rdParty : McSEX6ASEnc01TypSSI3PType; (*Type mcSEX6ASE0T_SSI_3P settings*)
	END_STRUCT;
	McSEX6ASType : STRUCT (*Type mcSEX6AIT_SSI settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		PositionRange : McSEX6ASPosRngType; (*Defines the range of the position value*)
		ClockRate : McSEX6ASClkRateEnum; (*Clock rate*)
		CyclePrescaler : UINT; (*Multiples of X2X cycle*)
		Encoder01Type : McSEX6ASEnc01TypType; (*BuR SSI encoder / 3rd Party SSI encoder*)
	END_STRUCT;
	McSEX6AIfTypType : STRUCT
		Type : McSEX6AIfTypEnum; (*Interface type selector setting*)
		Incremental : McSEX6AIType; (*Type mcSEX6AIT_INCR settings*)
		Hiperface : McSEX6AHType; (*Type mcSEX6AIT_HF settings*)
		SSI : McSEX6ASType; (*Type mcSEX6AIT_SSI settings*)
	END_STRUCT;
	McSEX6AType : STRUCT
		InterfaceType : McSEX6AIfTypType;
	END_STRUCT;
	McSEX6BIfTypEnum :
		( (*Interface type selector setting*)
		mcSEX6BIT_NOT_USE := 0, (*Not used -*)
		mcSEX6BIT_INCR := 1, (*Incremental -*)
		mcSEX6BIT_HF := 2, (*Hiperface -*)
		mcSEX6BIT_SSI := 3 (*SSI -*)
		);
	McSEX6BIRefPSrcEnum :
		( (*Input source for the reference pulse*)
		mcSEX6BIRPS_R_IN_ABR_ENC := 0, (*R input ABR encoder*)
		mcSEX6BIRPS_DIG_IN_1 := 1, (*Digital input 1*)
		mcSEX6BIRPS_DIG_IN_2 := 2 (*Digital input 2*)
		);
	McSEX6BIRefPEdgEnum :
		( (*Detection of reference switch*)
		mcSEX6BIRPE_POS_EDG := 0, (*Positive edge - Referencing with positive edge*)
		mcSEX6BIRPE_NEG_EDG := 1, (*Negative edge - Referencing with negative edge*)
		mcSEX6BIRPE_POS_AND_NEG_EDG := 2 (*Positive and negative edge - Referencing with positive and negative edge*)
		);
	McSEX6BIBkWDetectEnum :
		( (*Broken wire detection*)
		mcSEX6BIBWD_A_B := 0, (*A B - Encoder input A and B are checked*)
		mcSEX6BIBWD_A_B_R := 1, (*A B R - Encoder input A, B and R are checked*)
		mcSEX6BIBWD_NOT_USE := 2 (*Not used - Broken wire detection is switched off*)
		);
	McSEX6BIType : STRUCT (*Type mcSEX6BIT_INCR settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		ReferencePulseSource : McSEX6BIRefPSrcEnum; (*Input source for the reference pulse*)
		ReferencePulseEdge : McSEX6BIRefPEdgEnum; (*Detection of reference switch*)
		BrokenWireDetection : McSEX6BIBkWDetectEnum; (*Broken wire detection*)
	END_STRUCT;
	McSEX6BHPosRngType : STRUCT (*Defines the range of the position value*)
		LowerLimit : DINT; (*Lower limit of encoder range*)
		UpperLimit : UDINT; (*Upper limit of encoder range*)
	END_STRUCT;
	McSEX6BHSinCosTrkType : STRUCT
		VssMaximum : UINT; (*Maximum peak-to-peak amplitude [mV]*)
		VssMinimum : UINT; (*Minimum peak-to-peak amplitude [mV]*)
		VssQuittTime : UDINT; (*Validation period after Vss check error [µs]*)
	END_STRUCT;
	McSEX6BHHfBdRateEnum :
		( (*Select baud rate*)
		mcSEX6BHHBR_BD_RATE_1_200 := 0, (*Baud rate 1 200*)
		mcSEX6BHHBR_BD_RATE_2_400 := 1, (*Baud rate 2 400*)
		mcSEX6BHHBR_BD_RATE_4_800 := 2, (*Baud rate 4 800*)
		mcSEX6BHHBR_BD_RATE_9_600 := 3, (*Baud rate 9 600*)
		mcSEX6BHHBR_BD_RATE_19_200 := 4, (*Baud rate 19 200*)
		mcSEX6BHHBR_BD_RATE_38_400 := 5 (*Baud rate 38 400*)
		);
	McSEX6BHHfParEnum :
		( (*Select parity*)
		mcSEX6BHHP_NONE := 0, (*None*)
		mcSEX6BHHP_EVEN := 1, (*Even*)
		mcSEX6BHHP_ODD := 2 (*Odd*)
		);
	McSEX6BHHfType : STRUCT (*Hiperface RS485 interface configuration*)
		BaudRate : McSEX6BHHfBdRateEnum; (*Select baud rate*)
		Parity : McSEX6BHHfParEnum; (*Select parity*)
		ReceiveIdleTime : USINT; (*If no more receive data is detected within this time, data transfer is considered complete [bits]*)
		ReferenceStationAdress : USINT; (*Adress of the Sine/Cosine Reference station (255=broadcast)*)
		ReferencePositionWidth : USINT; (*Encoders acquisition width of position (absolute) [bits]*)
	END_STRUCT;
	McSEX6BHType : STRUCT (*Type mcSEX6BIT_HF settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		PositionRange : McSEX6BHPosRngType; (*Defines the range of the position value*)
		SineCosineTrack : McSEX6BHSinCosTrkType;
		Hiperface : McSEX6BHHfType; (*Hiperface RS485 interface configuration*)
	END_STRUCT;
	McSEX6BSPosRngType : STRUCT (*Defines the range of the position value*)
		LowerLimit : DINT; (*Lower limit of encoder range*)
		UpperLimit : UDINT; (*Upper limit of encoder range*)
	END_STRUCT;
	McSEX6BSClkRateEnum :
		( (*Clock rate*)
		mcSEX6BSCR_CLK_RATE_1_MHZ := 0, (*Clock rate 1 MHz*)
		mcSEX6BSCR_CLK_RATE_800_KHZ := 1, (*Clock rate 800 kHz*)
		mcSEX6BSCR_CLK_RATE_400_KHZ := 2, (*Clock rate 400 kHz*)
		mcSEX6BSCR_CLK_RATE_200_KHZ := 3, (*Clock rate 200 kHz*)
		mcSEX6BSCR_CLK_RATE_100_KHZ := 4 (*Clock rate 100 kHz*)
		);
	McSEX6BSEnc01TypEnum :
		( (*Encoder 01 type selector setting*)
		mcSEX6BSE0T_BUR_SSI := 0, (*BuR SSI -*)
		mcSEX6BSE0T_SSI_3P := 1 (*SSI 3rd Party -*)
		);
	McSEX6BSEnc01TypSSI3PDatFmtEnum :
		( (*Data format of SSI encoder*)
		mcSEX6BSE0TS3PDF_BIN := 0, (*Binary*)
		mcSEX6BSE0TS3PDF_GRAY := 1 (*Gray*)
		);
	McSEX6BSEnc01TypSSI3PParBitEnum :
		( (*Select parity mode*)
		mcSEX6BSE0TS3PPB_OFF := 0, (*Off*)
		mcSEX6BSE0TS3PPB_EVEN := 1, (*Even*)
		mcSEX6BSE0TS3PPB_ODD := 2, (*Odd*)
		mcSEX6BSE0TS3PPB_IGN := 3 (*Ignore*)
		);
	McSEX6BSEnc01TypSSI3PMCkEnum :
		( (*Select monoflop check mode*)
		mcSEX6BSE0TS3PMC_OFF := 0, (*Off*)
		mcSEX6BSE0TS3PMC_LOW := 1, (*Low*)
		mcSEX6BSE0TS3PMC_HIGH := 2 (*High*)
		);
	McSEX6BSEnc01TypSSI3PType : STRUCT (*Type mcSEX6BSE0T_SSI_3P settings*)
		DataFormat : McSEX6BSEnc01TypSSI3PDatFmtEnum; (*Data format of SSI encoder*)
		ValidSSIBitLength : USINT; (*Valid SSI bit length*)
		TotalSSIBitLength : USINT; (*Total SSI bit length*)
		ParityBit : McSEX6BSEnc01TypSSI3PParBitEnum; (*Select parity mode*)
		MonoflopCheck : McSEX6BSEnc01TypSSI3PMCkEnum; (*Select monoflop check mode*)
	END_STRUCT;
	McSEX6BSEnc01TypType : STRUCT (*BuR SSI encoder / 3rd Party SSI encoder*)
		Type : McSEX6BSEnc01TypEnum; (*Encoder 01 type selector setting*)
		SSI3rdParty : McSEX6BSEnc01TypSSI3PType; (*Type mcSEX6BSE0T_SSI_3P settings*)
	END_STRUCT;
	McSEX6BSType : STRUCT (*Type mcSEX6BIT_SSI settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		PositionRange : McSEX6BSPosRngType; (*Defines the range of the position value*)
		ClockRate : McSEX6BSClkRateEnum; (*Clock rate*)
		CyclePrescaler : UINT; (*Multiples of X2X cycle*)
		Encoder01Type : McSEX6BSEnc01TypType; (*BuR SSI encoder / 3rd Party SSI encoder*)
	END_STRUCT;
	McSEX6BIfTypType : STRUCT
		Type : McSEX6BIfTypEnum; (*Interface type selector setting*)
		Incremental : McSEX6BIType; (*Type mcSEX6BIT_INCR settings*)
		Hiperface : McSEX6BHType; (*Type mcSEX6BIT_HF settings*)
		SSI : McSEX6BSType; (*Type mcSEX6BIT_SSI settings*)
	END_STRUCT;
	McSEX6BType : STRUCT
		InterfaceType : McSEX6BIfTypType;
	END_STRUCT;
	McSEX3IfTypEnum :
		( (*Interface type selector setting*)
		mcSEX3IT_NOT_USE := 0, (*Not used -*)
		mcSEX3IT_INCR := 1 (*Incremental -*)
		);
	McSEX3IRefPSrcEnum :
		( (*Input source for the reference pulse*)
		mcSEX3IRPS_R_IN_ABR_ENC := 0 (*R input ABR encoder - R input of the ABR encoder*)
		);
	McSEX3IRefPEdgEnum :
		( (*Detection of the reference pulse*)
		mcSEX3IRPE_POS_EDG := 0, (*Positive edge - Detection with positive edge*)
		mcSEX3IRPE_NEG_EDG := 1 (*Negative edge - Detection with negative edge*)
		);
	McSEX3IType : STRUCT (*Type mcSEX3IT_INCR settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		ReferencePulseSource : McSEX3IRefPSrcEnum; (*Input source for the reference pulse*)
		ReferencePulseEdge : McSEX3IRefPEdgEnum; (*Detection of the reference pulse*)
	END_STRUCT;
	McSEX3IfTypType : STRUCT
		Type : McSEX3IfTypEnum; (*Interface type selector setting*)
		Incremental : McSEX3IType; (*Type mcSEX3IT_INCR settings*)
	END_STRUCT;
	McSEX3Type : STRUCT
		InterfaceType : McSEX3IfTypType;
	END_STRUCT;
	McSEX4IfTypEnum :
		( (*Interface type selector setting*)
		mcSEX4IT_NOT_USE := 0, (*Not used -*)
		mcSEX4IT_INCR := 1 (*Incremental -*)
		);
	McSEX4IRefPSrcEnum :
		( (*Input source for the reference pulse*)
		mcSEX4IRPS_R_IN_ABR_ENC := 0 (*R input ABR encoder - R input of the ABR encoder*)
		);
	McSEX4IRefPEdgEnum :
		( (*Detection of the reference pulse*)
		mcSEX4IRPE_POS_EDG := 0, (*Positive edge - Detection with positive edge*)
		mcSEX4IRPE_NEG_EDG := 1 (*Negative edge - Detection with negative edge*)
		);
	McSEX4IType : STRUCT (*Type mcSEX4IT_INCR settings*)
		LinesPerEncoderRevolution : UDINT; (*Absolute number of lines of an encoder revolution [Lines/Rev]*)
		ReferencePulseSource : McSEX4IRefPSrcEnum; (*Input source for the reference pulse*)
		ReferencePulseEdge : McSEX4IRefPEdgEnum; (*Detection of the reference pulse*)
	END_STRUCT;
	McSEX4IfTypType : STRUCT
		Type : McSEX4IfTypEnum; (*Interface type selector setting*)
		Incremental : McSEX4IType; (*Type mcSEX4IT_INCR settings*)
	END_STRUCT;
	McSEX4Type : STRUCT
		InterfaceType : McSEX4IfTypType;
	END_STRUCT;
	McCfgStpEncType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_STP_ENC*)
		Encoder : McSEEncType;
		X6 : McSEX6Type;
		X6A : McSEX6AType;
		X6B : McSEX6BType;
		X3 : McSEX3Type;
		X4 : McSEX4Type;
	END_STRUCT;
END_TYPE