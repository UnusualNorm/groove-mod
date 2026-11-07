set -e
swig -includeall -c++ -lua -Isrc/swig -xmlout src/swig/game.xml -o src/swig/game.hpp src/swig/game.i
python swig_lua.py src/swig/game.xml types/game.d.lua
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
cp -r ./build/sd/. ~/.config/Ryujinx/sdcard/
rm -rf ~/.config/Ryujinx/sdcard/groove/
mkdir -p ~/.config/Ryujinx/sdcard/groove/
cp -r ./example/* ~/.config/Ryujinx/sdcard/groove/
cp -r ./groove/* ~/.config/Ryujinx/sdcard/groove/
