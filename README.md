# SITL Remote ID

This repository contains new and modified files to implement the ASTM Remote ID Standard Specification.

https://www.astm.org/Standards/F3411.htm

This project was developed on Ubuntu 18.04. Ardupilot must be installed per its documentation's instructions.

https://ardupilot.org/dev/docs/building-setup-linux.html#building-setup-linux

This code was developed on commit https://github.com/ArduPilot/ardupilot/tree/56790625b8f7db5f2c9871e9e6878e57a544a7a7

## Adding Files

Once Ardupilot is installed, the files in the `Changes` Folder must be placed in `ardupilot/libraries/SITL`. The modified `board.py` must be placed in `ardupilot/Tools/ardupilotwaf/`. Then the files of this repo must be placed in a subfolder `ardupilot/libraries/SITL/RemoteID`.

## Building

To build the code, run `./Tools/autotest/sim_vehicle.py -v ArduCopter --console --map --osd`

## Logs

Logs are located in `/var/log/remoteid/`






