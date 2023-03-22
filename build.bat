@echo off

echo 🖥️ Started Building 🖥️

set operating_system=%1

echo Building Core
cmake --build c:/Dev/ProjectTime/build --config Realse --target ALL_BUILD -j 18

echo Building ProjectTime
cd ProjectTime
flutter build %operating_system%

cd ..
echo ✅ Finished Building ✅