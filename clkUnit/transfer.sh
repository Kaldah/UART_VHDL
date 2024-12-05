#!/bin/bash

# Launch the n7xilinxhelper.sh script with "syn" argument
./n7xilinxhelper.sh syn

# Check if the script execution was successful
if [ $? -eq 0 ]; then
    echo "n7xilinxhelper.sh executed successfully."

    # Specify the path to the USB key
    usb_path="/media/gaut/3CDC-E67C/"

    # Check if the USB key is mounted
    if [ -d "$usb_path" ]; then
        # Copy Nexys4Joystick.bit to the USB key
        cp Nexys4Joystick.bit "$usb_path/"
        echo "Nexys4Joystick.bit copied to USB key."
    else
        echo "Error: USB key not found at $usb_path."
    fi
else
    echo "Error: n7xilinxhelper.sh execution failed."
fi
