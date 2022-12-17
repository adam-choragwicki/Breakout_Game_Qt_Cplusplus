if [ ! -d "executable_linux" ]; then
    wget https://github.com/adam-choragwicki/Breakout_Game_Qt_Cplusplus/releases/latest/download/executable_linux.zip
    unzip executable_linux.zip && rm executable_linux.zip
    chmod +x executable_linux/Breakout.sh executable_linux/Breakout
fi

./executable_linux/Breakout
