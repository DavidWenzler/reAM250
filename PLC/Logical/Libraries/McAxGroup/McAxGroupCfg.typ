TYPE
	McAGAPhsAxAxType : STRUCT
		AxisReference : McCfgReferenceType; (*Name of the axis reference*)
	END_STRUCT;
	McAGAPhsAxType : STRUCT (*Defines the axes which a part of the axis group*)
		Axis : McCfgUnboundedArrayType;
	END_STRUCT;
	McAGAGFType : STRUCT
		FeatureReference : McCfgUnboundedArrayType; (*Name of the axes group feature reference*)
	END_STRUCT;
	McCfgAxGrpAdminType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_AXGRP_ADMIN*)
		ProcessingTaskClass : McPTCEnum; (*Cyclic task class for command processing*)
		PhysicalAxes : McAGAPhsAxType; (*Defines the axes which a part of the axis group*)
		AxesGroupFeatures : McAGAGFType;
	END_STRUCT;
	McAGFHOTogGrpType : STRUCT
		AxisReference : McCfgUnboundedArrayType; (*Name of the axis reference*)
	END_STRUCT;
	McCfgAxGrpFeatHomeOrdType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_AXGRP_FEAT_HOME_ORD*)
		TogetherGroup : McCfgUnboundedArrayType;
	END_STRUCT;
	McAGFPOOTogGrpType : STRUCT
		AxisReference : McCfgUnboundedArrayType; (*Name of the axis reference*)
	END_STRUCT;
	McCfgAxGrpFeatPwrOnOrdType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_AXGRP_FEAT_PWR_ON_ORD*)
		TogetherGroup : McCfgUnboundedArrayType;
	END_STRUCT;
	McAGFESAGrpStopExType : STRUCT
		AxisReference : McCfgUnboundedArrayType; (*Name of the axis reference*)
	END_STRUCT;
	McAGFESAGrpOvrExType : STRUCT
		AxisReference : McCfgUnboundedArrayType; (*Name of the axis reference*)
	END_STRUCT;
	McCfgAxGrpFeatExSngAxType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_AXGRP_FEAT_EX_SNG_AX*)
		GroupStopExclusion : McAGFESAGrpStopExType;
		GroupOverrideExclusion : McAGFESAGrpOvrExType;
	END_STRUCT;
	McAGFSBSBCAxType : STRUCT
		AxisReference : McCfgUnboundedArrayType; (*Name of the axis reference*)
	END_STRUCT;
	McAGFSBSBCErrBxEnum :
		( (*Error behavior selector setting*)
		mcAGFSBSBCEB_CLOSE_IMMED := 0, (*Close immediately - Close Brake immediately, risk of abraision of the brakes*)
		mcAGFSBSBCEB_CLOSE_A_STOP := 1 (*Close after stop - Close Brake after stop to prevent damage. Robot may fall down!*)
		);
	McAGFSBSBCErrBxType : STRUCT (*Defines the reaction to the composite if one axis gets error with CTRL off*)
		Type : McAGFSBSBCErrBxEnum; (*Error behavior selector setting*)
	END_STRUCT;
	McAGFSBSBCOutEnum :
		( (*Output selector setting*)
		mcAGFSBSBCO_AX := 0, (*Axis - Standard brake output of ACOPOS is used*)
		mcAGFSBSBCO_VAR := 1 (*Variable - A variable that is connected to the output which controls the brakes*)
		);
	McAGFSBSBCOutAxType : STRUCT (*Type mcAGFSBSBCO_AX settings*)
		AxisReference : McCfgReferenceType; (*Name of the axis reference*)
	END_STRUCT;
	McAGFSBSBCOutVarType : STRUCT (*Type mcAGFSBSBCO_VAR settings*)
		PVMapping : STRING[250]; (*Process variable to activate the holding brake*)
	END_STRUCT;
	McAGFSBSBCOutType : STRUCT (*Defines the brake signal destination*)
		Type : McAGFSBSBCOutEnum; (*Output selector setting*)
		Axis : McAGFSBSBCOutAxType; (*Type mcAGFSBSBCO_AX settings*)
		Variable : McAGFSBSBCOutVarType; (*Type mcAGFSBSBCO_VAR settings*)
	END_STRUCT;
	McAGFSBSBCFdbkEnum :
		( (*Feedback selector setting*)
		mcAGFSBSBCF_TIME_BASED := 0 (*Time based - Brake is activated/released after a certain waiting time*)
		);
	McAGFSBSBCFdbkTimeBasedType : STRUCT (*Type mcAGFSBSBCF_TIME_BASED settings*)
		ActivationDelay : REAL; (*Holding torque build-up time after switching off the operating voltage [s]*)
		ReleaseDelay : REAL; (*Holding torque decaying time after switching on the operating voltage [s]*)
	END_STRUCT;
	McAGFSBSBCFdbkType : STRUCT (*Status intformation of the brake*)
		Type : McAGFSBSBCFdbkEnum; (*Feedback selector setting*)
		TimeBased : McAGFSBSBCFdbkTimeBasedType; (*Type mcAGFSBSBCF_TIME_BASED settings*)
	END_STRUCT;
	McAGFSBSBCType : STRUCT
		Axes : McAGFSBSBCAxType;
		ErrorBehavior : McAGFSBSBCErrBxType; (*Defines the reaction to the composite if one axis gets error with CTRL off*)
		Output : McAGFSBSBCOutType; (*Defines the brake signal destination*)
		Feedback : McAGFSBSBCFdbkType; (*Status intformation of the brake*)
	END_STRUCT;
	McCfgAxGrpFeatShrBrkSigType : STRUCT (*Main data type corresponding to McCfgTypeEnum mcCFG_AXGRP_FEAT_SHR_BRK_SIG*)
		BrakeComposite : McCfgUnboundedArrayType;
	END_STRUCT;
	McAGFModalDatBxEnum :
		( (*Modal data behaviour selector setting*)
		mcAGFMDB_USE_AX_GRP_SET := 0, (*Use axes group settings - The settings from the axes group are used.*)
		mcAGFMDB_RST_TO_DEF := 1, (*Reset to default - The values are reseted to the configured/default values at program end.*)
		mcAGFMDB_KEEP_CUR_VAL := 2 (*Keep current values - The values at program end are used for the next program.*)
		);
	McAGFModalDatBxType : STRUCT (*Defines the modal data behaviour of the feature.*)
		Type : McAGFModalDatBxEnum; (*Modal data behaviour selector setting*)
	END_STRUCT;
END_TYPE