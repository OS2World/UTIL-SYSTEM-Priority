@Echo off

priority 1 0 test arg1 arg2
priority 3 31 test argx argy

rem this last is executed only if we get something on the command line...

if "%1" == "" goto End
if "%2" == "" goto End

priority %1 %2 test %3 %4 %5 %6 %7 %8 %9

:End
