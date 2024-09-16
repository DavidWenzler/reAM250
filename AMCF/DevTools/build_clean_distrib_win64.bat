@ECHO OFF

if not exist "DevPackages" (mkdir "DevPackages")

SET /p DEVPACKAGE=<devpackage_version.txt
SET /p DEVPACKAGESHA=<devpackage_sha256_win64.txt

echo "Verifying package %DEVPACKAGE%"
DevTools\packageManager.exe download "DevPackages\amcf_win64_%DEVPACKAGE%.zip" "https://ssl.aleos.io" "win64_%DEVPACKAGE%" "%DEVPACKAGESHA%"

if %ERRORLEVEL% == 0 goto :verification_done

echo "Errors encountered during execution.  Exited with status: %errorlevel%"
goto :endofscript

:verification_done
echo "Using developer package win64_%DEVPACKAGE%"

if not exist "build" (mkdir "build")
if not exist "build\Framework" (mkdir "build\Framework")
if not exist "build\Output" (mkdir "build\Output")
if not exist "build\Output\data" (mkdir "build\Output\data")

echo "Extracting DevPackages\amcf_win64_%DEVPACKAGE%.zip"

DevTools\7z.exe x DevPackages\amcf_win64_%DEVPACKAGE%.zip -y -o.\build\Framework\
copy .\build\Framework\Dist\disthash.txt .\build\githash.txt 
SET /p GITHASH=<.\build\githash.txt

echo "Found GIT hash %GITHASH%"

cd build
REM call cmake -G "MinGW Makefiles" ..
call cmake  ..
call cmake --build . --config Release

".\Framework\create_package_xml.exe" --config ".\Output\%GITHASH%_config.xml" --devpackage %GITHASH% --output ".\Output\%GITHASH%_package.xml" --serveroutput ".\Output\amc_server.xml"


cd Output

:endofscript
pause