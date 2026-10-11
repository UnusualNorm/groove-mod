set -e
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
cp -r ./build/sd/. ~/.config/Ryujinx/sdcard/
rm -rf ~/.config/Ryujinx/sdcard/groove/
mkdir -p ~/.config/Ryujinx/sdcard/groove/
cp -r ./example/* ~/.config/Ryujinx/sdcard/groove/
cp -r ./groove/* ~/.config/Ryujinx/sdcard/groove/
