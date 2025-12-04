import shutil
import os

Import("env")

SRC = os.path.join('include', 'tft_espi', 'User_Setup.h')
DST = os.path.join('.pio', 'libdeps', env["PIOENV"], 'TFT_eSPI', 'User_Setup.h')

def copy_user_setup():
    if os.path.exists(SRC):
        os.makedirs(os.path.dirname(DST), exist_ok=True)
        shutil.copyfile(SRC, DST)
        print(f"Copied {SRC} to {DST}")
    else:
        print(f"Source file {SRC} does not exist!")

copy_user_setup()
