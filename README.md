on-board-computer
=================

Overview
--------

This is an on-board computer. It is responsible for controlling the AUV, interfacing with the sensors, and communicating with the ground computer.

Development
-----------

Using pico as debugprobe.

```bash
openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program onboard-computer.elf verify reset exit"
```

There is a helper script to flash the board. It is located in the `scripts` directory.

```bash
./scripts/flash.sh
```