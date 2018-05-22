
[configData,stateData,onlineData] = getCodeGenerationData(mpc1)

func = 'mpcmoveCodeGeneration';
funcOutput = 'mpcmoveMEX';
Cfg = coder.config('dll');
Cfg.TargetLang = 'c++'
Cfg.DynamicMemoryAllocation = 'off';
codegen('-config',Cfg,func,'-o',funcOutput,'-args',...
    {coder.Constant(configData),stateData,onlineData});

