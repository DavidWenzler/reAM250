
TYPE
	SFCActionType : STRUCT			(*internal use*)
		x	: BOOL;
		_x	: BOOL;
		t	: TIME;
		_t	: TIME;
		AC	: SFCActionControl;
	END_STRUCT;
	SFCActionType2 : STRUCT		(*internal use*)
		x	: BOOL;
		_x	: BOOL;
		AC	: SFCAC2;
	END_STRUCT;
	SFCActionCType : STRUCT		(*internal use*)
		x		: BOOL;
		_x		: BOOL;
		force	: BOOL;
		_force	: BOOL;
		active	: BOOL;
		_active	: BOOL;
		error	: BOOL;
		AC		: SFCActionControl;
	END_STRUCT;
	SFCActionCType2 : STRUCT	(*internal use*)
		x		: BOOL;
		_x		: BOOL;
		force	: BOOL;
		_force	: BOOL;
		active	: BOOL;
		_active	: BOOL;
		error	: BOOL;
		AC		: SFCAC2;
	END_STRUCT;
	SFCActionCType3 : STRUCT	(*internal use*)
		t		: LREAL;
		_t		: LREAL;
		tp		: LREAL;
		x		: BOOL;
		_x		: BOOL;
		force	: BOOL;
		_force	: BOOL;
		active	: BOOL;
		_active	: BOOL;
		error	: BOOL;
		AC		: SFCAC3;
	END_STRUCT;
	SFCStepType : STRUCT			(*internal use*)
		x	: BOOL;
		t	: TIME;
		_x	: BOOL;
		_t	: TIME;
	END_STRUCT;
	SFCStepCType : STRUCT		(*internal use*)
		t					: TIME;
		_t					: TIME;
		inactive_actions	: UDINT;
		_inactive_actions	: UDINT;
		error_actions		: UDINT;
		x					: BOOL;
		_x					: BOOL;
		x_activate			: BOOL;
		force				: BOOL;
		_force				: BOOL;
		active				: BOOL;
		_active				: BOOL;
		error				: BOOL;
		tip					: BOOL;
		tip_disable_duration: BOOL;
		tip_disable_action	: BOOL;
	END_STRUCT;
	SFCStepCType3 : STRUCT		(*internal use*)
		t						: LREAL;
		_t						: LREAL;
		tp						: LREAL;
		inactive_actions		: UDINT;
		_inactive_actions		: UDINT;
		error_actions			: UDINT;
		x						: BOOL;
		_x						: BOOL;
		x_activate				: {REDUND_UNREPLICABLE} BOOL;
		force					: BOOL;
		_force					: BOOL;
		active					: BOOL;
		_active					: BOOL;
		error					: BOOL;
		tip						: BOOL;
		tip_disable_duration	: BOOL;
		tip_disable_action		: BOOL;
	END_STRUCT;
	SFCSimpleStepCType : STRUCT	(*internal use*)
		t						: TIME;
		_t						: TIME;
		x						: BOOL;
		_x						: BOOL;
		x_activate				: BOOL;
		force					: BOOL;
		_force					: BOOL;
		active					: BOOL;
		_active					: BOOL;
		error					: BOOL;
		tip						: BOOL;
		tip_disable_duration	: BOOL;
		tip_disable_action		: BOOL;
	END_STRUCT;
	SFCSimpleStepCType3 : STRUCT	(*internal use*)
		t						: LREAL;
		_t						: LREAL;
		tp						: LREAL;
		x						: BOOL;
		_x						: BOOL;
		x_activate				: {REDUND_UNREPLICABLE} BOOL;
		force					: BOOL;
		_force					: BOOL;
		active					:  BOOL;
		_active					: BOOL;
		error					: BOOL;
		tip						: BOOL;
		tip_disable_duration	: BOOL;
		tip_disable_action		: BOOL;
	END_STRUCT;
	SFCTransitionCType : STRUCT	(*internal use*)
		force	: BOOL;
		_force	: BOOL;
		active	: BOOL;
		_active	: BOOL;
	END_STRUCT;
	TimerType : STRUCT	(*internal use*)
		ptime	: LREAL;
		etime	: LREAL;
		start	: LREAL;
		in		: USINT;
		q		: USINT;
	END_STRUCT;

	ArFBStateInternalType : STRUCT			(*fb state machine internal context*)
		ExecuteRef		: UDINT;
		BusyRef			: UDINT;
		DoneRef			: UDINT;
		ErrorRef		: UDINT;
		ActiveRef		: UDINT;
		StatusRef		: UDINT;
		FBCyclic		: UDINT;
		AsyfumaState		: UDINT;
		FBResetOut		: UDINT;
		Argument		: UDINT;
		State			: UDINT;
		ExecutePrev		: BOOL;
	END_STRUCT;
	
	ArFBAsyFuMaInternalType : STRUCT		(*asynchronous function manager internal context*)
		State			: UINT;
		Result			: DINT;
	END_STRUCT;

END_TYPE
