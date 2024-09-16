TYPE
	McCfgString250Type : STRING[250]; (**)
	McCfgTypeEnum :
		( (*Configuration system enum*)
		mcCFG_NONE := 0, (*None -*)
		mcCFG_MMCFG := 10, (*Associated with data type McCfgMMCfgType*)
		mcCFG_WS := 800, (*Associated with data type McCfgWorkspaceType*)
		mcCFG_TOOLTBL := 900, (*Tooltable -*)
		mcCFG_FRMTBL := 1000, (*Associated with data type McCfgFrmTblType*)
		mcCFG_DYNPARTBL := 1100, (**)
		mcCFG_TOOL := 1300, (*Tool -*)
		mcCFG_LIMSET_LIN := 1411, (*Associated with data type McCfgLimSetLinType*)
		mcCFG_LIMSET_ROT := 1412, (*Associated with data type McCfgLimSetRotType*)
		mcCFG_PROC_PT_LST := 1600, (*Associated with data type McCfgProcPtLstType*)
		mcCFG_AX := 10000, (*Associated with data type McCfgAxType*)
		mcCFG_AX_BASE_TYP := 10011, (*Associated with data type McCfgAxBaseTypType*)
		mcCFG_AX_MOVE_LIM := 10012, (*Associated with data type McCfgAxMoveLimType*)
		mcCFG_AX_FEAT_CAM_AUT_CMN := 10101, (*AxisFeatureCamAutCommon -*)
		mcCFG_AX_FEAT_PROF_GEN := 10102, (*AxisFeatureProfGen -*)
		mcCFG_AX_FEAT_DIG_CAM_SW := 10103, (*Associated with data type McCfgAxFeatDigCamSwType*)
		mcCFG_AX_FEAT_CAM_LST := 11102, (*AxisFeatureCamList -*)
		mcCFG_AX_FEAT_ALT_VAL_SRC := 10104, (*Associated with data type McCfgAxFeatAltValSrcType*)
		mcCFG_AX_FEAT_BRK := 10105, (*Associated with data type McCfgAxFeatBrkType*)
		mcCFG_AX_FEAT_MECH_DEV_COMP := 10106, (*Associated with data type McCfgAxFeatMechDevCompType*)
		mcCFG_MOT_SYN := 10500, (*Associated with data type McCfgMotSynType*)
		mcCFG_MOT_INDUCT := 10501, (*Associated with data type McCfgMotInductType*)
		mcCFG_IO_PL_IN_CARD := 10510, (*IOPlugInCard -*)
		mcCFG_ACP_AX := 11000, (*Associated with data type McCfgAcpAxType*)
		mcCFG_ACP_AX_REF := 11011, (*Associated with data type McCfgAcpAxRefType*)
		mcCFG_ACP_MECH_ELM := 11012, (*Associated with data type McCfgAcpMechElmType*)
		mcCFG_ACP_ENC_LINK := 11013, (*Associated with data type McCfgAcpEncLinkType*)
		mcCFG_ACP_CTRL := 11014, (*Associated with data type McCfgAcpCtrlType*)
		mcCFG_ACP_HOME := 11015, (*Associated with data type McCfgAcpHomeType*)
		mcCFG_ACP_STOP_REAC := 11016, (*Associated with data type McCfgAcpStopReacType*)
		mcCFG_ACP_MOVE_ERR_LIM := 11017, (*Associated with data type McCfgAcpMoveErrLimType*)
		mcCFG_ACP_JERK_FLTR := 11018, (*Associated with data type McCfgAcpJerkFltrType*)
		mcCFG_ACP_DIG_IN := 11019, (*Associated with data type McCfgAcpDigInType*)
		mcCFG_ACP_SIM := 11020, (*Associated with data type McCfgAcpSimType*)
		mcCFG_ACP_AX_FEAT := 11021, (*Associated with data type McCfgAcpAxFeatType*)
		mcCFG_ACP_AUX_PWR_SUP_MOD := 11030, (*Associated with data type McCfgAcpAuxPwrSupModType*)
		mcCFG_ACP_PSM_PWR_SEC := 11031, (*Associated with data type McCfgAcpPSMPwrSecType*)
		mcCFG_ACP_PWR_SUP := 11040, (*Associated with data type McCfgAcpPwrSupType*)
		mcCFG_ACP_ENC := 11045, (*Associated with data type McCfgAcpEncType*)
		mcCFG_ACP_VIRT_AX := 11050, (*Associated with data type McCfgAcpVirtAxType*)
		mcCFG_ACP_VIRT_AX_REF := 11051, (*Associated with data type McCfgAcpVirtAxRefType*)
		mcCFG_ACP_VIRT_HOME := 11052, (*Associated with data type McCfgAcpVirtHomeType*)
		mcCFG_ACP_VIRT_JERK_FLTR := 11053, (*Associated with data type McCfgAcpVirtJerkFltrType*)
		mcCFG_ACP_VIRT_AX_FEAT := 11054, (*Associated with data type McCfgAcpVirtAxFeatType*)
		mcCFG_ACP_CH_FEAT := 11060, (*Associated with data type McCfgAcpChFeatType*)
		mcCFG_ACP_EXT_ENC_AX := 11070, (*Associated with data type McCfgAcpExtEncAxType*)
		mcCFG_ACP_EXT_ENC_AX_REF := 11071, (*Associated with data type McCfgAcpExtEncAxRefType*)
		mcCFG_ACP_EXT_ENC_AX_ENC_LINK := 11072, (*Associated with data type McCfgAcpExtEncAxEncLinkType*)
		mcCFG_ACP_EXT_ENC_AX_MECH_ELM := 11073, (*Associated with data type McCfgAcpExtEncAxMechElmType*)
		mcCFG_ACP_EXT_ENC_AX_HOME := 11074, (*Associated with data type McCfgAcpExtEncAxHomeType*)
		mcCFG_AX_FEAT_CAM_AUT_ACP := 11101, (*AxisFeatureCamAutAcopos -*)
		mcCFG_AX_FEAT_A_IN := 11103, (*AxisFeatureAInput -*)
		mcCFG_AX_FEAT_ACP_PAR_TBL := 11104, (*Associated with data type McCfgAxFeatAcpParTblType*)
		mcCFG_PURE_V_AX := 12000, (*Associated with data type McCfgPureVAxType*)
		mcCFG_PURE_V_AX_REF := 12011, (*Associated with data type McCfgPureVAxRefType*)
		mcCFG_PURE_V_AX_HOME := 12012, (*Associated with data type McCfgPureVAxHomeType*)
		mcCFG_PURE_V_AX_JERK_FLTR := 12013, (*Associated with data type McCfgPureVAxJerkFltrType*)
		mcCFG_PURE_V_AX_FEAT := 12014, (*Associated with data type McCfgPureVAxFeatType*)
		mcCFG_PURE_V_AX_MECH_ELM := 12015, (*Associated with data type McCfgPureVAxMechElmType*)
		mcCFG_PURE_V_AX_ENC_LINK := 12016, (*Associated with data type McCfgPureVAxEncLinkType*)
		mcCFG_PURE_V_AX_CTRL := 12017, (*Associated with data type McCfgPureVAxCtrlType*)
		mcCFG_PURE_V_AX_STOP_REAC := 12018, (*Associated with data type McCfgPureVAxStopReacType*)
		mcCFG_PURE_V_AX_MOVE_ERR_LIM := 12019, (*Associated with data type McCfgPureVAxMoveErrLimType*)
		mcCFG_PURE_V_AX_DIG_IN := 12020, (*Associated with data type McCfgPureVAxDigInType*)
		mcCFG_PURE_V_AX_STAT_IN := 12021, (*Associated with data type McCfgPureVAxStatInType*)
		mcCFG_PURE_V_AX_CTRL_OUT := 12022, (*Associated with data type McCfgPureVAxCtrlOutType*)
		mcCFG_STP_AX := 13000, (*Associated with data type McCfgStpAxType*)
		mcCFG_STP_AX_REF := 13011, (*Associated with data type McCfgStpAxRefType*)
		mcCFG_STP_AX_MECH_ELM := 13012, (*Associated with data type McCfgStpAxMechElmType*)
		mcCFG_STP_AX_MOT := 13013, (*Associated with data type McCfgStpAxMotType*)
		mcCFG_STP_AX_ENC_LINK := 13014, (*Associated with data type McCfgStpAxEncLinkType*)
		mcCFG_STP_AX_CTRL := 13015, (*Associated with data type McCfgStpAxCtrlType*)
		mcCFG_STP_AX_HOME := 13016, (*Associated with data type McCfgStpAxHomeType*)
		mcCFG_STP_AX_STOP_REAC := 13017, (*Associated with data type McCfgStpAxStopReacType*)
		mcCFG_STP_AX_MOVE_ERR_LIM := 13018, (*Associated with data type McCfgStpAxMoveErrLimType*)
		mcCFG_STP_AX_JERK_FLTR := 13019, (*Associated with data type McCfgStpAxJerkFltrType*)
		mcCFG_STP_AX_DIG_IN := 13020, (*Associated with data type McCfgStpAxDigInType*)
		mcCFG_STP_AX_DIG_OUT := 13021, (*Associated with data type McCfgStpAxDigOutType*)
		mcCFG_STP_AX_FEAT := 13022, (*Associated with data type McCfgStpAxFeatType*)
		mcCFG_STP_ENC := 13100, (*Associated with data type McCfgStpEncType*)
		mcCFG_DS402_AX := 13500, (*Associated with data type McCfgDS402AxType*)
		mcCFG_DS402_INV_AX := 13501, (*Associated with data type McCfgDS402InvAxType*)
		mcCFG_DS402_AX_REF := 13511, (*Associated with data type McCfgDS402AxRefType*)
		mcCFG_DS402_AX_MECH_ELM := 13512, (*Associated with data type McCfgDS402AxMechElmType*)
		mcCFG_DS402_AX_ENC_SET := 13513, (*Associated with data type McCfgDS402AxEncSetType*)
		mcCFG_DS402_AX_POS_ACT_VAL_RNG := 13514, (*Associated with data type McCfgDS402AxPosActValRngType*)
		mcCFG_DS402_AX_CYC_SET_VAL_MOD := 13515, (*Associated with data type McCfgDS402AxCycSetValModType*)
		mcCFG_DS402_AX_FEAT := 13516, (*Associated with data type McCfgDS402AxFeatType*)
		mcCFG_ACP_INV_AX := 13600, (*Associated with data type McCfgAcpInvAxType*)
		mcCFG_ACP_INV_AX_REF := 13611, (*Associated with data type McCfgAcpInvAxRefType*)
		mcCFG_ACP_INV_AX_MECH_ELM := 13612, (*Associated with data type McCfgAcpInvAxMechElmType*)
		mcCFG_AXGRP_ADMIN := 20000, (*Associated with data type McCfgAxGrpAdminType*)
		mcCFG_AXGRP_FEAT_HOME_ORD := 20101, (*Associated with data type McCfgAxGrpFeatHomeOrdType*)
		mcCFG_AXGRP_FEAT_PWR_ON_ORD := 20102, (*Associated with data type McCfgAxGrpFeatPwrOnOrdType*)
		mcCFG_AXGRP_FEAT_EX_SNG_AX := 20103, (*Associated with data type McCfgAxGrpFeatExSngAxType*)
		mcCFG_AXGRP_FEAT_SHR_BRK_SIG := 20104, (*Associated with data type McCfgAxGrpFeatShrBrkSigType*)
		mcCFG_AXGRP_PATHGEN := 21000, (*Associated with data type McCfgAxGrpPathGenType*)
		mcCFG_AXGRP_PATHGEN_BASE_SET := 21013, (*Associated with data type McCfgAxGrpPathGenBaseSetType*)
		mcCFG_AXGRP_FEAT_PRG := 21101, (*Associated with data type McCfgAxGrpFeatPrgType*)
		mcCFG_AXGRP_FEAT_COMP := 21102, (*Associated with data type McCfgAxGrpFeatCompType*)
		mcCFG_AXGRP_FEAT_CDC := 21103, (*Associated with data type McCfgAxGrpFeatCdcType*)
		mcCFG_AXGRP_FEAT_FF := 21104, (*Associated with data type McCfgAxGrpFeatFfType*)
		mcCFG_AXGRP_FEAT_FRM_HIER_STD := 21105, (*Associated with data type McCfgAxGrpFeatFrmHierStdType*)
		mcCFG_AXGRP_FEAT_FRM_HIER_CUS := 21106, (*Associated with data type McCfgAxGrpFeatFrmHierCusType*)
		mcCFG_AXGRP_FEAT_JOG := 21107, (*AxesgroupFeatureJogging -*)
		mcCFG_AXGRP_FEAT_LAH := 21108, (*Associated with data type McCfgAxGrpFeatLahType*)
		mcCFG_AXGRP_FEAT_MFUN := 21109, (*Associated with data type McCfgAxGrpFeatMFunType*)
		mcCFG_AXGRP_FEAT_MON_ELEM := 21110, (*Associated with data type McCfgAxGrpFeatMonElemType*)
		mcCFG_AXGRP_FEAT_MP_LOG := 21111, (*Associated with data type McCfgAxGrpFeatMpLogType*)
		mcCFG_AXGRP_FEAT_PATH_DEF := 21112, (*Associated with data type McCfgAxGrpFeatPathDefType*)
		mcCFG_AXGRP_FEAT_PRG_SIM := 21113, (*Associated with data type McCfgAxGrpFeatPrgSimType*)
		mcCFG_AXGRP_FEAT_SPINDLES := 21114, (*Associated with data type McCfgAxGrpFeatSpindlesType*)
		mcCFG_AXGRP_FEAT_TOOL := 21115, (*Associated with data type McCfgAxGrpFeatToolType*)
		mcCFG_AXGRP_FEAT_WSM := 21116, (*Associated with data type McCfgAxGrpFeatWsmType*)
		mcCFG_AXGRP_FEAT_EX_PATH_AX := 21117, (*Associated with data type McCfgAxGrpFeatExPathAxType*)
		mcCFG_AXGRP_FEAT_PROBE := 21118, (*Associated with data type McCfgAxGrpFeatProbeType*)
		mcCFG_AXGRP_FEAT_SIG := 21119, (*Associated with data type McCfgAxGrpFeatSigType*)
		mcCFG_AXGRP_FEAT_2D_COMP := 21120, (*Associated with data type McCfgAxGrpFeat2DCompType*)
		mcCFG_AXGRP_FEAT_3D_COMP := 21121, (*Associated with data type McCfgAxGrpFeat3DCompType*)
		mcCFG_AXGRP_FEAT_PATH_PREVIEW := 21122, (*Associated with data type McCfgAxGrpFeatPathPreviewType*)
		mcCFG_AXGRP_FEAT_TAN_TOOL := 21124, (*Associated with data type McCfgAxGrpFeatTanToolType*)
		mcCFG_AXGRP_FEAT_REV_MOVE := 21125, (*Associated with data type McCfgAxGrpFeatRevMoveType*)
		mcCFG_ASM := 31000, (*Associated with data type McCfgAsmType*)
		mcCFG_ASM_FEAT_CPLG := 31101, (*Associated with data type McCfgAsmFeatCplgType*)
		mcCFG_ASM_FEAT_SIM_SH_DEF := 31102, (*Associated with data type McCfgAsmFeatSimShDefType*)
		mcCFG_ASM_FEAT_SH_TRACE := 31103, (*Associated with data type McCfgAsmFeatShTraceType*)
		mcCFG_ASM_FEAT_SH_AUT_ATT := 31104, (*Associated with data type McCfgAsmFeatShAutAttType*)
		mcCFG_ASM_FEAT_LOC_LIM := 31105, (*Associated with data type McCfgAsmFeatLocLimType*)
		mcCFG_ASM_FEAT_EX_SEG := 31106, (*Associated with data type McCfgAsmFeatExSegType*)
		mcCFG_ASM_FEAT_SH_SHP_REG := 31107, (*Associated with data type McCfgAsmFeatShShpRegType*)
		mcCFG_SEC_COMP := 31301, (*Associated with data type McCfgSecCompType*)
		mcCFG_SEC_SUB := 31302, (*Associated with data type McCfgSecSubType*)
		mcCFG_SH_STEREO_TYP := 31400, (*Associated with data type McCfgShStereoTypType*)
		mcCFG_SEG := 31500, (*Associated with data type McCfgSegType*)
		mcCFG_MS_CUS_STD := 50001, (*Associated with data type McCfgMSCusStdType*)
		mcCFG_MS_2AX_CNC_XY := 51201, (*Associated with data type McCfgMS2AxCncXYType*)
		mcCFG_MS_2AX_CNC_XZ := 51202, (*Associated with data type McCfgMS2AxCncXZType*)
		mcCFG_MS_2AX_CNC_YZ := 51203, (*Associated with data type McCfgMS2AxCncYZType*)
		mcCFG_MS_3AX_CNC_XYZ := 51301, (*Associated with data type McCfgMS3AxCncXYZType*)
		mcCFG_MS_3AX_CNC_XZC := 51302, (*Associated with data type McCfgMS3AxCncXZCType*)
		mcCFG_MS_3AX_CNC_XZB := 51303, (*Associated with data type McCfgMS3AxCncXZBType*)
		mcCFG_MS_4AX_CNC_XYZB := 51401, (*Associated with data type McCfgMS4AxCncXYZBType*)
		mcCFG_MS_4AX_CNC_XYZC := 51402, (*Associated with data type McCfgMS4AxCncXYZCType*)
		mcCFG_MS_5AX_CNC_XYZCA := 51504, (*Associated with data type McCfgMS5AxCncXYZCAType*)
		mcCFG_MS_6AX_CNC_ZXYBCA := 51603, (*Associated with data type McCfgMS6AxCncZXYBCAType*)
		mcCFG_MS_4AX_SCARA_A := 52041, (*Associated with data type McCfgMS4AxScaraAType*)
		mcCFG_MS_2AX_DELTA_A := 52121, (*Associated with data type McCfgMS2AxDeltaAType*)
		mcCFG_MS_3AX_DELTA_A := 52131, (*Associated with data type McCfgMS3AxDeltaAType*)
		mcCFG_MS_3AX_DELTA_XZB := 52132, (*Associated with data type McCfgMS3AxDeltaXZBType*)
		mcCFG_MS_3AX_DELTA_B := 52133, (*Associated with data type McCfgMS3AxDeltaBType*)
		mcCFG_MS_4AX_DELTA_A := 52141, (*Associated with data type McCfgMS4AxDeltaAType*)
		mcCFG_MS_4AX_DELTA_B := 52142, (*Associated with data type McCfgMS4AxDeltaBType*)
		mcCFG_MS_4AX_DELTA_C := 52143, (*Associated with data type McCfgMS4AxDeltaCType*)
		mcCFG_MS_5AX_DELTA_A := 52151, (*Associated with data type McCfgMS5AxDeltaAType*)
		mcCFG_MS_3AX_ROB_A := 52301, (*Associated with data type McCfgMS3AxRobAType*)
		mcCFG_MS_4AX_ROB_A := 52401, (*Associated with data type McCfgMS4AxRobAType*)
		mcCFG_MS_4AX_ROB_B := 52402, (*Associated with data type McCfgMS4AxRobBType*)
		mcCFG_MS_5AX_ROB_A := 52501, (*Associated with data type McCfgMS5AxRobAType*)
		mcCFG_MS_5AX_ROB_B := 52502, (*Associated with data type McCfgMS5AxRobBType*)
		mcCFG_MS_6AX_ROB_A := 52601, (*Associated with data type McCfgMS6AxRobAType*)
		mcCFG_MS_6AX_ROB_B := 52602, (*Associated with data type McCfgMS6AxRobBType*)
		mcCFG_MS_6AX_ROB_C := 52603 (*Associated with data type McCfgMS6AxRobCType*)
		);
	McCfgUnboundedArrayType : STRUCT (*General purpose datatype*)
		NumberOfElements : UDINT;
		DataAddress : UDINT;
		NumberOfArrayElements : UDINT;
	END_STRUCT;
	McCfgReferenceType : STRUCT (*General purpose datatype*)
		Name : STRING[250];
		ConfigType : McCfgTypeEnum;
	END_STRUCT;
	McMMCProcProcTskCEnum :
		( (*Cyclic task class for command processing*)
		mcMMCPPTC_CYC_1 := 1, (*Cyclic #1 - Task class 1*)
		mcMMCPPTC_CYC_2 := 2 (*Cyclic #2 - Task class 2*)
		);
	McMMCProcType : STRUCT
		ProcessingTaskClass : McMMCProcProcTskCEnum; (*Cyclic task class for command processing*)
	END_STRUCT;
	McMMCLogSelEnum :
		( (*Selective logging selector setting*)
		mcMMCLS_NOT_USE := 0, (*Not used -*)
		mcMMCLS_USE := 1 (*Used -*)
		);
	McCfgVisEnum :
		( (*Component state change logger entries (PLCopen state)*)
		mcCV_VIS := 0, (*Visible*)
		mcCV_SUP := 1 (*Suppressed*)
		);
	McMMCLogSelUseAdmCmdEnum :
		( (*Administrative commands selector setting*)
		mcMMCLSUAC_VIS := 0, (*Visible - This command group of logger entries will be visible*)
		mcMMCLSUAC_SUP := 1, (*Suppressed - This command group of logger entries will be suppressed*)
		mcMMCLSUAC_SEL := 2 (*Selective - Defines which sections of this command group should be visible*)
		);
	McMMCLogSelUseAdmCmdSelType : STRUCT (*Type mcMMCLSUAC_SEL settings*)
		CallerInstance : McCfgVisEnum; (*Logging of the caller instance entries*)
		ComponentResponse : McCfgVisEnum; (*Logging of component response entries*)
		AdditionalInformation : McCfgVisEnum; (*Logging of additional information entries*)
	END_STRUCT;
	McMMCLogSelUseAdmCmdType : STRUCT (*Administrative logger entries*)
		Type : McMMCLogSelUseAdmCmdEnum; (*Administrative commands selector setting*)
		Selective : McMMCLogSelUseAdmCmdSelType; (*Type mcMMCLSUAC_SEL settings*)
	END_STRUCT;
	McMMCLogSelUseMoveCmdEnum :
		( (*Movement commands selector setting*)
		mcMMCLSUMC_VIS := 0, (*Visible - This command group of logger entries will be visible*)
		mcMMCLSUMC_SUP := 1, (*Suppressed - This command group of logger entries will be suppressed*)
		mcMMCLSUMC_SEL := 2 (*Selective - Defines which sections of this command group should be visible*)
		);
	McMMCLogSelUseMoveCmdSelType : STRUCT (*Type mcMMCLSUMC_SEL settings*)
		CallerInstance : McCfgVisEnum; (*Logging of the caller instance entries*)
		ComponentResponse : McCfgVisEnum; (*Logging of component response entries*)
		AdditionalInformation : McCfgVisEnum; (*Logging of additional information entries*)
	END_STRUCT;
	McMMCLogSelUseMoveCmdType : STRUCT (*Movement logger entries*)
		Type : McMMCLogSelUseMoveCmdEnum; (*Movement commands selector setting*)
		Selective : McMMCLogSelUseMoveCmdSelType; (*Type mcMMCLSUMC_SEL settings*)
	END_STRUCT;
	McMMCLogSelUseInfoCmdEnum :
		( (*Informational commands selector setting*)
		mcMMCLSUIC_VIS := 0, (*Visible - This command group of logger entries will be visible*)
		mcMMCLSUIC_SUP := 1, (*Suppressed - This command group of logger entries will be suppressed*)
		mcMMCLSUIC_SEL := 2 (*Selective - Defines which sections of this command group should be visible*)
		);
	McMMCLogSelUseInfoCmdSelType : STRUCT (*Type mcMMCLSUIC_SEL settings*)
		CallerInstance : McCfgVisEnum; (*Logging of the caller instance entries*)
		ComponentResponse : McCfgVisEnum; (*Logging of component response entries*)
		AdditionalInformation : McCfgVisEnum; (*Logging of additional information entries*)
	END_STRUCT;
	McMMCLogSelUseInfoCmdType : STRUCT (*Status information logger entries*)
		Type : McMMCLogSelUseInfoCmdEnum; (*Informational commands selector setting*)
		Selective : McMMCLogSelUseInfoCmdSelType; (*Type mcMMCLSUIC_SEL settings*)
	END_STRUCT;
	McMMCLogSelUseSupSubcEEnum :
		( (*Suppress entries for internally invoked commands for subcomponents*)
		mcMMCLSUSSE_INACT := 0, (*Inactive - Entries for internally invoked commands for subcomponents are shown unless the base entries are suppressed*)
		mcMMCLSUSSE_ACT := 1 (*Active - Entries for internally invoked commands for subcomponents are suppressed*)
		);
	McMMCLogSelUseType : STRUCT (*Type mcMMCLS_USE settings*)
		StateChange : McCfgVisEnum; (*Component state change logger entries (PLCopen state)*)
		AdministrativeCommands : McMMCLogSelUseAdmCmdType; (*Administrative logger entries*)
		MovementCommands : McMMCLogSelUseMoveCmdType; (*Movement logger entries*)
		InformationalCommands : McMMCLogSelUseInfoCmdType; (*Status information logger entries*)
		SuppressSubcomponentEntries : McMMCLogSelUseSupSubcEEnum; (*Suppress entries for internally invoked commands for subcomponents*)
	END_STRUCT;
	McMMCLogSelType : STRUCT (*Define which logging areas should be visible*)
		Type : McMMCLogSelEnum; (*Selective logging selector setting*)
		Used : McMMCLogSelUseType; (*Type mcMMCLS_USE settings*)
	END_STRUCT;
	McMMCLogType : STRUCT
		Selective : McMMCLogSelType; (*Define which logging areas should be visible*)
	END_STRUCT;
	McCfgMMCfgType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_MMCFG*)
		Processing : McMMCProcType;
		Logger : McMMCLogType;
	END_STRUCT;
	McCfgTransXYZType : STRUCT (*Translation parameters*)
		X : LREAL; (*Translation in X direction [measurement units]*)
		Y : LREAL; (*Translation in Y direction [measurement units]*)
		Z : LREAL; (*Translation in Z direction [measurement units]*)
	END_STRUCT;
	McCfgOrientType : STRUCT (*Orientation parameters*)
		Angle1 : LREAL; (*Rotation around the first coordinateaxis of the rotation order [measurement units]*)
		Angle2 : LREAL; (*Rotation around the second coordinateaxis of the rotation order [measurement units]*)
		Angle3 : LREAL; (*Rotation around the third coordinateaxis of the rotation order [measurement units]*)
	END_STRUCT;
	McWSCubeDimType : STRUCT (*Dimension parameters*)
		X : LREAL; (*Dimension of the cuboid in the x-direction (endpoint) [measurement units]*)
		Y : LREAL; (*Dimension of the cuboid in the y-direction (endpoint) [measurement units]*)
		Z : LREAL; (*Dimension of the cuboid in the z-direction (endpoint) [measurement units]*)
	END_STRUCT;
	McWSCubeType : STRUCT
		ID : UDINT; (*Unique cuboid ID*)
		Translation : McCfgTransXYZType; (*Translation parameters*)
		Orientation : McCfgOrientType; (*Orientation parameters*)
		Dimension : McWSCubeDimType; (*Dimension parameters*)
	END_STRUCT;
	McWSCubesType : STRUCT (*Defines cuboids*)
		Cuboid : McCfgUnboundedArrayType;
	END_STRUCT;
	McWSHalfSpcPlEnum :
		( (*Defines plane*)
		mcWSHSP_PL_XY := 0, (*Plane XY*)
		mcWSHSP_PL_YZ := 1, (*Plane YZ*)
		mcWSHSP_PL_ZX := 2 (*Plane ZX*)
		);
	McWSHalfSpcType : STRUCT
		ID : UDINT; (*Unique half-space ID*)
		Translation : McCfgTransXYZType; (*Translation parameters*)
		Orientation : McCfgOrientType; (*Orientation parameters*)
		Plane : McWSHalfSpcPlEnum; (*Defines plane*)
	END_STRUCT;
	McWSHalfSpcsType : STRUCT (*Defines half-spaces*)
		HalfSpace : McCfgUnboundedArrayType;
	END_STRUCT;
	McWSTcConeParType : STRUCT (*Object description parameters*)
		BaseRadius : LREAL; (*Base radius of the cone [measurement units]*)
		Height : LREAL; (*Height of the cone [measurement units]*)
		TopRadius : LREAL; (*Top radius of the cone [measurement units]*)
	END_STRUCT;
	McWSTcConeType : STRUCT (*Selects object type*)
		ID : UDINT; (*Unique object ID*)
		Translation : McCfgTransXYZType; (*Translation parameters*)
		Orientation : McCfgOrientType; (*Orientation parameters*)
		Parameters : McWSTcConeParType; (*Object description parameters*)
	END_STRUCT;
	McWSTcConesType : STRUCT (*Defines truncated cones*)
		TruncatedCone : McCfgUnboundedArrayType; (*Selects object type*)
	END_STRUCT;
	McWSWorkSpaceType : STRUCT (*Defines the WorkSpace*)
		Cuboids : McWSCubesType; (*Defines cuboids*)
		HalfSpaces : McWSHalfSpcsType; (*Defines half-spaces*)
		TruncatedCones : McWSTcConesType; (*Defines truncated cones*)
	END_STRUCT;
	McWSSafeSpaceType : STRUCT (*Defines the SafeSpace*)
		Cuboids : McWSCubesType; (*Defines cuboids*)
		HalfSpaces : McWSHalfSpcsType; (*Defines half-spaces*)
		TruncatedCones : McWSTcConesType; (*Defines truncated cones*)
	END_STRUCT;
	McCfgWorkspaceType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_WS*)
		WorkSpace : McWSWorkSpaceType; (*Defines the WorkSpace*)
		SafeSpace : McWSSafeSpaceType; (*Defines the SafeSpace*)
	END_STRUCT;
	McFTRowType : STRUCT
		Index : UINT;
		X : LREAL;
		Y : LREAL;
		Z : LREAL;
		Angle1 : LREAL;
		Angle2 : LREAL;
		Angle3 : LREAL;
		Description : STRING[250];
	END_STRUCT;
	McCfgFrmTblType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_FRMTBL*)
		Row : McCfgUnboundedArrayType;
	END_STRUCT;
	McLSPosEnum :
		( (*Position selector setting*)
		mcLSP_NOT_USE := 0, (*Not used -*)
		mcLSP_USE := 1 (*Used -*)
		);
	McCfgLimPosType : STRUCT (*Type mcLSP_USE settings*)
		LowerLimit : LREAL; (*Lower software limit position [Measurement units]*)
		UpperLimit : LREAL; (*Upper software limit position [Measurement units]*)
	END_STRUCT;
	McLSPosType : STRUCT (*Movement range of the axis via two position boundaries*)
		Type : McLSPosEnum; (*Position selector setting*)
		Used : McCfgLimPosType; (*Type mcLSP_USE settings*)
	END_STRUCT;
	McLSVelEnum :
		( (*Velocity selector setting*)
		mcLSV_NOT_USE := 0, (*Not used -*)
		mcLSV_BASIC := 1, (*Basic -*)
		mcLSV_ADV := 2 (*Advanced -*)
		);
	McCfgLimVelBaseType : STRUCT (*Type mcLSV_BASIC settings*)
		Velocity : REAL; (*Velocity limit in any movement direction [Measurement units/s]*)
	END_STRUCT;
	McCfgLimVelAdvType : STRUCT (*Type mcLSV_ADV settings*)
		Positive : REAL; (*Velocity limit in positive movement direction [Measurement units/s]*)
		Negative : REAL; (*Velocity limit in negative movement direction [Measurement units/s]*)
	END_STRUCT;
	McLSVelType : STRUCT (*Velocity limits*)
		Type : McLSVelEnum; (*Velocity selector setting*)
		Basic : McCfgLimVelBaseType; (*Type mcLSV_BASIC settings*)
		Advanced : McCfgLimVelAdvType; (*Type mcLSV_ADV settings*)
	END_STRUCT;
	McLSAccEnum :
		( (*Acceleration selector setting*)
		mcLSA_NOT_USE := 0, (*Not used -*)
		mcLSA_BASIC := 1, (*Basic -*)
		mcLSA_ADV := 2 (*Advanced -*)
		);
	McCfgLimAccBaseType : STRUCT (*Type mcLSA_BASIC settings*)
		Acceleration : REAL; (*Acceleration limit in any movement direction [Measurement units/s²]*)
	END_STRUCT;
	McCfgLimAccAdvType : STRUCT (*Type mcLSA_ADV settings*)
		Positive : REAL; (*Acceleration limit in positive movement direction [Measurement units/s²]*)
		Negative : REAL; (*Acceleration limit in negative movement direction [Measurement units/s²]*)
	END_STRUCT;
	McLSAccType : STRUCT (*Acceleration limits*)
		Type : McLSAccEnum; (*Acceleration selector setting*)
		Basic : McCfgLimAccBaseType; (*Type mcLSA_BASIC settings*)
		Advanced : McCfgLimAccAdvType; (*Type mcLSA_ADV settings*)
	END_STRUCT;
	McLSDecEnum :
		( (*Deceleration selector setting*)
		mcLSD_NOT_USE := 0, (*Not used -*)
		mcLSD_BASIC := 1, (*Basic -*)
		mcLSD_ADV := 2 (*Advanced -*)
		);
	McCfgLimDecBaseType : STRUCT (*Type mcLSD_BASIC settings*)
		Deceleration : REAL; (*Deceleration limit in any movement direction [Measurement units/s²]*)
	END_STRUCT;
	McCfgLimDecAdvType : STRUCT (*Type mcLSD_ADV settings*)
		Positive : REAL; (*Deceleration limit in positive movement direction [Measurement units/s²]*)
		Negative : REAL; (*Deceleration limit in negative movement direction [Measurement units/s²]*)
	END_STRUCT;
	McLSDecType : STRUCT (*Deceleration limits*)
		Type : McLSDecEnum; (*Deceleration selector setting*)
		Basic : McCfgLimDecBaseType; (*Type mcLSD_BASIC settings*)
		Advanced : McCfgLimDecAdvType; (*Type mcLSD_ADV settings*)
	END_STRUCT;
	McCfgLimJerkEnum :
		( (*Jerk selector setting*)
		mcCLJ_NOT_USE := 0, (*Not used -*)
		mcCLJ_BASIC := 1, (*Basic -*)
		mcCLJ_ADV := 2 (*Advanced -*)
		);
	McCfgLimJerkBasicType : STRUCT (*Type mcCLJ_BASIC settings*)
		Jerk : REAL; (*Jerk limit in any movement direction [Measurement units/s³]*)
	END_STRUCT;
	McCfgLimJerkAdvType : STRUCT (*Type mcCLJ_ADV settings*)
		AccelerationPositive : REAL; (*Jerk limit in positive movement direction during acceleration [Measurement units/s³]*)
		AccelerationNegative : REAL; (*Jerk limit in negative movement direction during acceleration [Measurement units/s³]*)
		DecelerationPositive : REAL; (*Jerk limit in positive movement direction during deceleration [Measurement units/s³]*)
		DecelerationNegative : REAL; (*Jerk limit in negative movement direction during deceleration [Measurement units/s³]*)
	END_STRUCT;
	McCfgLimJerkType : STRUCT (*Jerk limits*)
		Type : McCfgLimJerkEnum; (*Jerk selector setting*)
		Basic : McCfgLimJerkBasicType; (*Type mcCLJ_BASIC settings*)
		Advanced : McCfgLimJerkAdvType; (*Type mcCLJ_ADV settings*)
	END_STRUCT;
	McCfgLimForEnum :
		( (*Force selector setting*)
		mcCLF_NOT_USE := 0, (*Not used -*)
		mcCLF_BASIC := 1, (*Basic -*)
		mcCLF_ADV := 2 (*Advanced -*)
		);
	McCfgLimForBasicType : STRUCT (*Type mcCLF_BASIC settings*)
		Force : REAL; (*Force limit in any movement direction [N]*)
	END_STRUCT;
	McCfgLimForAdvType : STRUCT (*Type mcCLF_ADV settings*)
		AccelerationPositive : REAL; (*Force limit in positive movement direction during acceleration [N]*)
		AccelerationNegative : REAL; (*Force limit in negative movement direction during acceleration [N]*)
		DecelerationPositive : REAL; (*Force limit in positive movement direction during deceleration [N]*)
		DecelerationNegative : REAL; (*Force limit in negative movement direction during deceleration [N]*)
	END_STRUCT;
	McCfgLimForType : STRUCT (*Limits for the force of the axis*)
		Type : McCfgLimForEnum; (*Force selector setting*)
		Basic : McCfgLimForBasicType; (*Type mcCLF_BASIC settings*)
		Advanced : McCfgLimForAdvType; (*Type mcCLF_ADV settings*)
	END_STRUCT;
	McCfgLimSetLinType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_LIMSET_LIN*)
		Position : McLSPosType; (*Movement range of the axis via two position boundaries*)
		Velocity : McLSVelType; (*Velocity limits*)
		Acceleration : McLSAccType; (*Acceleration limits*)
		Deceleration : McLSDecType; (*Deceleration limits*)
		Jerk : McCfgLimJerkType; (*Jerk limits*)
		Force : McCfgLimForType; (*Limits for the force of the axis*)
	END_STRUCT;
	McCfgLimTorqEnum :
		( (*Torque selector setting*)
		mcCLT_NOT_USE := 0, (*Not used -*)
		mcCLT_BASIC := 1, (*Basic -*)
		mcCLT_ADV := 2 (*Advanced -*)
		);
	McCfgLimTorqBasicType : STRUCT (*Type mcCLT_BASIC settings*)
		Torque : REAL; (*Torque limit in any movement direction [Nm]*)
	END_STRUCT;
	McCfgLimTorqAdvType : STRUCT (*Type mcCLT_ADV settings*)
		AccelerationPositive : REAL; (*Torque limit in positive movement direction during acceleration [Nm]*)
		AccelerationNegative : REAL; (*Torque limit in negative movement direction during acceleration [Nm]*)
		DecelerationPositive : REAL; (*Torque limit in positive movement direction during deceleration [Nm]*)
		DecelerationNegative : REAL; (*Torque limit in negative movement direction during deceleration [Nm]*)
	END_STRUCT;
	McCfgLimTorqType : STRUCT (*Torque limits*)
		Type : McCfgLimTorqEnum; (*Torque selector setting*)
		Basic : McCfgLimTorqBasicType; (*Type mcCLT_BASIC settings*)
		Advanced : McCfgLimTorqAdvType; (*Type mcCLT_ADV settings*)
	END_STRUCT;
	McCfgLimSetRotType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_LIMSET_ROT*)
		Position : McLSPosType; (*Movement range of the axis via two position boundaries*)
		Velocity : McLSVelType; (*Velocity limits*)
		Acceleration : McLSAccType; (*Acceleration limits*)
		Deceleration : McLSDecType; (*Deceleration limits*)
		Jerk : McCfgLimJerkType; (*Jerk limits*)
		Torque : McCfgLimTorqType; (*Torque limits*)
	END_STRUCT;
	McPPLPtEnum :
		( (*Process point: {/} selector setting*)
		mcPPLP_TRAK_PT := 0 (*Trak point - ACOPOSTrak*)
		);
	McPPLPtTrakPtPosRelToEnum :
		( (*Absolute position from which the position is counted*)
		mcPPLPTPPRT_ST_OF_SEC := 0, (*Start of sector - Tail of the sector*)
		mcPPLPTPPRT_END_OF_SEC := 1 (*End of sector - Head of the sector*)
		);
	McPPLPtTrakPtBarrFunEnum :
		( (*Barrier functionality selector setting*)
		mcPPLPTPBF_OFF := 0, (*Off - Disable barrier functionality*)
		mcPPLPTPBF_ON := 1 (*On - Enable barrier functionality*)
		);
	McPPLPtTrakPtBarrFunType : STRUCT (*Enable barrier functionality for process point*)
		Type : McPPLPtTrakPtBarrFunEnum; (*Barrier functionality selector setting*)
	END_STRUCT;
	McPPLPtTrakPtType : STRUCT (*Type mcPPLP_TRAK_PT settings*)
		Name : STRING[250]; (*Identifier of point*)
		SectorReference : McCfgReferenceType; (*Name of the referenced sector component*)
		Position : LREAL; (*Position on the sector [Measurement units]*)
		PositionRelativeTo : McPPLPtTrakPtPosRelToEnum; (*Absolute position from which the position is counted*)
		TriggerEventBufferSize : UINT; (*Amount of maximum saved trigger point events*)
		BarrierFunctionality : McPPLPtTrakPtBarrFunType; (*Enable barrier functionality for process point*)
	END_STRUCT;
	McPPLPtType : STRUCT
		Type : McPPLPtEnum; (*Process point: {/} selector setting*)
		TrakPoint : McPPLPtTrakPtType; (*Type mcPPLP_TRAK_PT settings*)
	END_STRUCT;
	McCfgProcPtLstType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_PROC_PT_LST*)
		ProcessPoints : McCfgUnboundedArrayType;
	END_STRUCT;
	McCfgLocLenUnitEnum :
		( (*Measurement unit for the axis*)
		mcCLLU_G_SET := 0, (*Global settings*)
		mcCLLU_MILL := 5066068, (*Millimeters*)
		mcCLLU_M := 5067858, (*Meters*)
		mcCLLU_INCH := 4804168, (*Inches*)
		mcCLLU_GEN := -1 (*Generic*)
		);
	McCfgCntDirEnum :
		( (*Direction of the axis in which the position value is increasing*)
		mcCCD_STD := 0, (*Standard - Rotary axis: clockwise*)
		mcCCD_INV := 1 (*Inverse - Rotary axis: counter-clockwise*)
		);
	McCfgLocRotUnitEnum :
		( (*Measurement unit for the axis*)
		mcCLRU_G_SET := 0, (*Global settings*)
		mcCLRU_DEG := 17476, (*Degrees*)
		mcCLRU_GRAD := 4274481, (*Gradians*)
		mcCLRU_REV := 5059636, (*Revolutions*)
		mcCLRU_GEN := -1 (*Generic*)
		);
	McCfgExtLimRefType : STRUCT (*Type mcAML_EXT settings*)
		LimitReference : McCfgReferenceType; (*Name of the limit reference*)
	END_STRUCT;
	McCfgGearBoxType : STRUCT (*Ratio between a gearbox input and output*)
		Input : DINT; (*Number of rotations on the encoder side [Revolutions]*)
		Output : DINT; (*Number of rotations on the load side which correspond to the number of rotations on the encoder side [Revolutions]*)
	END_STRUCT;
	McCfgRotToLinTrfType : STRUCT (*Specifies a transformation factor between the output of the gear and the actual load movement*)
		ReferenceDistance : LREAL; (*Reference distance which is considered for an axis positioning [Measurement units/Gearbox output revolution]*)
	END_STRUCT;
	McPTCEnum :
		( (*Cyclic task class for command processing*)
		mcPTC_CYC_1 := 1, (*Cyclic #1 - Task class 1*)
		mcPTC_USE_MP_MOT_SET := 255 (*Use mapp Motion setting - Use the defined setting from the mapp Motion configuration or Task class 1 if no mapp Motion Configuration exists*)
		);
	McCfgVarDatTypEnum :
		( (*Data type selector setting*)
		mcCVDT_TYP_BOOL := 0, (*Type BOOL -*)
		mcCVDT_TYP_SINT := 1, (*Type SINT -*)
		mcCVDT_TYP_USINT := 2, (*Type USINT -*)
		mcCVDT_TYP_INT := 3, (*Type INT -*)
		mcCVDT_TYP_UINT := 4, (*Type UINT -*)
		mcCVDT_TYP_DINT := 5, (*Type DINT -*)
		mcCVDT_TYP_UDINT := 6, (*Type UDINT -*)
		mcCVDT_TYP_REAL := 7, (*Type REAL -*)
		mcCVDT_TYP_LREAL := 8, (*Type LREAL -*)
		mcCVDT_TYP_STRING := 9, (*Type STRING -*)
		mcCVDT_TYP_DER := 10 (*Type Derived - Derived data type*)
		);
	McCfgVarDatTypTypSTRINGType : STRUCT (*Type mcCVDT_TYP_STRING settings*)
		Length : UDINT;
	END_STRUCT;
	McCfgVarDatTypTypDerType : STRUCT (*Type mcCVDT_TYP_DER settings*)
		Name : STRING[250]; (*Name*)
	END_STRUCT;
	McCfgVarDatTypType : STRUCT (*Data type*)
		Type : McCfgVarDatTypEnum; (*Data type selector setting*)
		TypeSTRING : McCfgVarDatTypTypSTRINGType; (*Type mcCVDT_TYP_STRING settings*)
		TypeDerived : McCfgVarDatTypTypDerType; (*Type mcCVDT_TYP_DER settings*)
	END_STRUCT;
	McCfgLimJerkBaseType : STRUCT (*Type mcAGFPDPLIJ_BASIC settings*)
		Jerk : REAL; (*Jerk limit in any movement direction [Measurement units/s³]*)
	END_STRUCT;
	McCfgTransXType : STRUCT (*Translation from base to QX*)
		X : LREAL; (*Translation in X direction [measurement units]*)
	END_STRUCT;
	McCfgTransZType : STRUCT (*Translation from QX to QZ*)
		Z : LREAL; (*Translation in Z direction [measurement units]*)
	END_STRUCT;
	McCfgTransXZType : STRUCT (*Translation from QZ to QB*)
		X : LREAL; (*Translation in X direction [measurement units]*)
		Z : LREAL; (*Translation in Z direction [measurement units]*)
	END_STRUCT;
	McCfgTransYType : STRUCT (*Translation from QX to QY*)
		Y : LREAL; (*Translation in Y direction [measurement units]*)
	END_STRUCT;
END_TYPE