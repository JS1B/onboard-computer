openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program onboard-computer.elf verify; reset; exit;"
